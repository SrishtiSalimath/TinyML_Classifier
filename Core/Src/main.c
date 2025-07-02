#include "main.h"
#include "usart.h"
#include "gpio.h"
#include "app_x-cube-ai.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/* USER CODE BEGIN PV */
extern UART_HandleTypeDef huart2;

float user_temp = 0.0f;
float user_humid = 0.0f;
extern float ai_result;  // From app_x-cube-ai.c
/* USER CODE END PV */

void SystemClock_Config(void);
void Error_Handler(void);

void uart_read_line(char *buffer, size_t max_len) {
  uint8_t ch;
  size_t idx = 0;
  while (1) {
    HAL_UART_Receive(&huart2, &ch, 1, HAL_MAX_DELAY);
    if (ch == '\r' || ch == '\n') break;
    if (ch >= 32 && ch <= 126 && idx < max_len - 1) {
      buffer[idx++] = ch;
      HAL_UART_Transmit(&huart2, &ch, 1, HAL_MAX_DELAY);
    }
  }
  buffer[idx] = '\0';
  HAL_UART_Transmit(&huart2, (uint8_t *)"\r\n", 2, HAL_MAX_DELAY);
}

void trim_trailing_whitespace(char *str) {
  int len = strlen(str);
  while (len > 0 && (str[len - 1] == '\r' || str[len - 1] == '\n' || str[len - 1] == ' ' || str[len - 1] == '\t')) {
    str[--len] = '\0';
  }
}

void uart_flush_input(void) {
  uint8_t dump;
  while (HAL_UART_Receive(&huart2, &dump, 1, 0) == HAL_OK);
}

int main(void) {
  HAL_Init();
  SystemClock_Config();
  MX_GPIO_Init();
  MX_USART2_UART_Init();

  HAL_UART_Transmit(&huart2, (uint8_t *)"\033[2J\033[H", 7, HAL_MAX_DELAY);  // Clear terminal
  HAL_UART_Transmit(&huart2, (uint8_t *)"\r\nX-CUBE-AI: Initialization...\r\n", 31, HAL_MAX_DELAY);
  MX_X_CUBE_AI_Init();

  while (1) {
    char rx_buf[32];
    char *endptr;

    // TEMPERATURE
    HAL_UART_Transmit(&huart2, (uint8_t *)"\r\nEnter Temperature (°C): ", 27, HAL_MAX_DELAY);
    memset(rx_buf, 0, sizeof(rx_buf));
    uart_read_line(rx_buf, sizeof(rx_buf));
    uart_flush_input();
    trim_trailing_whitespace(rx_buf);
    user_temp = strtof(rx_buf, &endptr);
    if (endptr == rx_buf || *endptr != '\0') {
      HAL_UART_Transmit(&huart2, (uint8_t *)"Invalid temperature. Try again.\r\n", 33, HAL_MAX_DELAY);
      continue;
    }

    // HUMIDITY
    HAL_UART_Transmit(&huart2, (uint8_t *)"Enter Humidity (%): ", 21, HAL_MAX_DELAY);
    memset(rx_buf, 0, sizeof(rx_buf));
    uart_read_line(rx_buf, sizeof(rx_buf));
    uart_flush_input();
    trim_trailing_whitespace(rx_buf);
    user_humid = strtof(rx_buf, &endptr);
    if (endptr == rx_buf || *endptr != '\0') {
      HAL_UART_Transmit(&huart2, (uint8_t *)"Invalid humidity. Try again.\r\n", 31, HAL_MAX_DELAY);
      continue;
    }

    // Clamp to match training range
    if (user_temp < 0) user_temp = 0;
    if (user_temp > 45) user_temp = 45;
    if (user_humid < 10) user_humid = 10;
    if (user_humid > 100) user_humid = 100;

    // Normalize before feeding to model
    user_temp /= 100.0f;
    user_humid /= 100.0f;

    // Run inference
    MX_X_CUBE_AI_Process();

    // Output
    char msg[64];
    snprintf(msg, sizeof(msg), "Model Output: %.3f\r\n", ai_result);
    HAL_UART_Transmit(&huart2, (uint8_t *)msg, strlen(msg), HAL_MAX_DELAY);

    snprintf(msg, sizeof(msg), "Comfort Score: %.1f%%\r\n", ai_result * 100.0f);
    HAL_UART_Transmit(&huart2, (uint8_t *)msg, strlen(msg), HAL_MAX_DELAY);

    if (ai_result >= 0.66f)
      HAL_UART_Transmit(&huart2, (uint8_t *)"-> Comfortable ✅\r\n", 20, HAL_MAX_DELAY);
    else if (ai_result >= 0.33f)
      HAL_UART_Transmit(&huart2, (uint8_t *)"-> Neutral ⚠️\r\n", 18, HAL_MAX_DELAY);
    else
      HAL_UART_Transmit(&huart2, (uint8_t *)"-> Uncomfortable ❌\r\n", 24, HAL_MAX_DELAY);

    HAL_UART_Transmit(&huart2, (uint8_t *)"Hint: Ideal = 25°C, 55% Humidity\r\n\r\n", 36, HAL_MAX_DELAY);

    HAL_Delay(1000);
  }
}

void SystemClock_Config(void) {
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  HAL_PWREx_ControlVoltageScaling(PWR_REGULATOR_VOLTAGE_SCALE1);

  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_MSI;
  RCC_OscInitStruct.MSIState = RCC_MSI_ON;
  RCC_OscInitStruct.MSICalibrationValue = 0;
  RCC_OscInitStruct.MSIClockRange = RCC_MSIRANGE_6;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_MSI;
  RCC_OscInitStruct.PLL.PLLM = 1;
  RCC_OscInitStruct.PLL.PLLN = 40;
  RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV7;
  RCC_OscInitStruct.PLL.PLLQ = RCC_PLLQ_DIV2;
  RCC_OscInitStruct.PLL.PLLR = RCC_PLLR_DIV2;
  HAL_RCC_OscConfig(&RCC_OscInitStruct);

  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK | RCC_CLOCKTYPE_SYSCLK |
                                RCC_CLOCKTYPE_PCLK1 | RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;
  HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_4);

  HAL_RCCEx_EnableMSIPLLMode();
}

void Error_Handler(void) {
  __disable_irq();
  while (1) {}
}
