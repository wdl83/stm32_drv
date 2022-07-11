#pragma once

#include <stdint.h>

struct usart_tx_ctrl;
typedef
struct usart_tx_ctrl usart_tx_ctrl_t;

typedef
void (*usart_tx_complete_cb_t)(uintptr_t base, usart_tx_ctrl_t *);

struct usart_tx_ctrl
{
    const uint8_t *begin;
    const uint8_t *end;
    usart_tx_complete_cb_t complete_cb;
    uintptr_t user_data;
    struct
    {
        uint32_t irq_cntr : 16;
        uint32_t byte_cntr : 16;
    } stats;
};

void usart_async_send(uintptr_t base, usart_tx_ctrl_t *);
void usart_tx_isr(uintptr_t base, usart_tx_ctrl_t *);
