#pragma once

#include <stdint.h>

char *usart_recv_str(
    uintptr_t base, char *begin, const char *const end, char delimiter);
