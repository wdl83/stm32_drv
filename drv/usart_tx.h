#pragma once

#include <stdint.h>

const char *usart_send_str_r(uintptr_t base, const char *begin, const char *const end);
const char *usart_send_str(uintptr_t base, const char *str);
void usart_send(uintptr_t base, const uint8_t *begin, const uint8_t *const end);
