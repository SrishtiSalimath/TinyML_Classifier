#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include <inttypes.h>
#include <string.h>

#include "app_x-cube-ai.h"
#include "main.h"
#include "ai_datatypes_defines.h"
#include "network.h"
#include "network_data.h"

/* USER CODE BEGIN includes */
extern float user_temp;
extern float user_humid;
float ai_result = 0.0f;
/* USER CODE END includes */

/* IO buffers ----------------------------------------------------------------*/
#if !defined(AI_NETWORK_INPUTS_IN_ACTIVATIONS)
AI_ALIGNED(4) ai_i8 data_in_1[AI_NETWORK_IN_1_SIZE_BYTES];
ai_i8* data_ins[AI_NETWORK_IN_NUM] = { data_in_1 };
#else
ai_i8* data_ins[AI_NETWORK_IN_NUM] = { NULL };
#endif

#if !defined(AI_NETWORK_OUTPUTS_IN_ACTIVATIONS)
AI_ALIGNED(4) ai_i8 data_out_1[AI_NETWORK_OUT_1_SIZE_BYTES];
ai_i8* data_outs[AI_NETWORK_OUT_NUM] = { data_out_1 };
#else
ai_i8* data_outs[AI_NETWORK_OUT_NUM] = { NULL };
#endif

/* Activations buffers -------------------------------------------------------*/
AI_ALIGNED(32) static uint8_t pool0[AI_NETWORK_DATA_ACTIVATION_1_SIZE];
ai_handle data_activations0[] = { pool0 };

/* AI objects ----------------------------------------------------------------*/
static ai_handle network = AI_HANDLE_NULL;
static ai_buffer* ai_input;
static ai_buffer* ai_output;

static void ai_log_err(const ai_error err, const char *fct)
{
  if (fct)
    printf("TEMPLATE - Error (%s) - type=0x%02x code=0x%02x\r\n", fct, err.type, err.code);
  else
    printf("TEMPLATE - Error - type=0x%02x code=0x%02x\r\n", err.type, err.code);
  while (1);
}

static int ai_boostrap(ai_handle *act_addr)
{
  ai_error err;

  err = ai_network_create_and_init(&network, act_addr, NULL);
  if (err.type != AI_ERROR_NONE) {
    ai_log_err(err, "ai_network_create_and_init");
    return -1;
  }

  ai_input = ai_network_inputs_get(network, NULL);
  ai_output = ai_network_outputs_get(network, NULL);

#if defined(AI_NETWORK_INPUTS_IN_ACTIVATIONS)
  for (int idx = 0; idx < AI_NETWORK_IN_NUM; idx++) {
    data_ins[idx] = ai_input[idx].data;
  }
#else
  for (int idx = 0; idx < AI_NETWORK_IN_NUM; idx++) {
    ai_input[idx].data = data_ins[idx];
  }
#endif

#if defined(AI_NETWORK_OUTPUTS_IN_ACTIVATIONS)
  for (int idx = 0; idx < AI_NETWORK_OUT_NUM; idx++) {
    data_outs[idx] = ai_output[idx].data;
  }
#else
  for (int idx = 0; idx < AI_NETWORK_OUT_NUM; idx++) {
    ai_output[idx].data = data_outs[idx];
  }
#endif

  return 0;
}

static int ai_run(void)
{
  ai_i32 batch;
  batch = ai_network_run(network, ai_input, ai_output);
  if (batch != 1) {
    ai_log_err(ai_network_get_error(network), "ai_network_run");
    return -1;
  }
  return 0;
}

/* USER CODE BEGIN 2 */
int acquire_and_process_data(ai_i8* data[])
{
  ((ai_float *)data[0])[0] = user_temp;  // Already normalized in main.c
  ((ai_float *)data[0])[1] = user_humid;
  return 0;
}

int post_process(ai_i8* data[])
{
  ai_result = ((ai_float *)data[0])[0];
  return 0;
}
/* USER CODE END 2 */

/* Entry points --------------------------------------------------------------*/

void MX_X_CUBE_AI_Init(void)
{
  printf("\r\nTEMPLATE - initialization\r\n");
  ai_boostrap(data_activations0);
}

void MX_X_CUBE_AI_Process(void)
{
  int res = -1;
  printf("TEMPLATE - run - main loop\r\n");

  if (network) {
    res = acquire_and_process_data(data_ins);
    if (res == 0)
      res = ai_run();
    if (res == 0)
      res = post_process(data_outs);
  }

  if (res) {
    ai_error err = { AI_ERROR_INVALID_STATE, AI_ERROR_CODE_NETWORK };
    ai_log_err(err, "Process has FAILED");
  }
}

#ifdef __cplusplus
}
#endif
