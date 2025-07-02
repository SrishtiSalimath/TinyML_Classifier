#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <errno.h>
#include "usart.h"  // Required for huart2

int _write(int file, char *ptr, int len) {
    HAL_UART_Transmit(&huart2, (uint8_t*)ptr, len, HAL_MAX_DELAY);
    return len;
}

int _read(int file, char *ptr, int len) {
    errno = ENOSYS;
    return -1;
}

int _close(int file) {
    errno = ENOSYS;
    return -1;
}

int _fstat(int file, struct stat *st) {
    st->st_mode = S_IFCHR;
    return 0;
}

int _isatty(int file) {
    return 1;
}

int _lseek(int file, int ptr, int dir) {
    return 0;
}

int _getpid(void) {
    return 1;
}

int _kill(int pid, int sig) {
    errno = ENOSYS;
    return -1;
}
