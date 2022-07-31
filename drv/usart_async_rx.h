#pragma once

#include <stdint.h>
#include <stdbool.h>

struct usart_rx_ctrl;
typedef
struct usart_rx_ctrl usart_rx_ctrl_t;

typedef
bool (*usart_rx_pred_cb_t)(const uint8_t *curr, usart_rx_ctrl_t *);
typedef
void (*usart_rx_complete_cb_t)(uintptr_t base, usart_rx_ctrl_t *);

void usart_async_recv(uintptr_t base, usart_rx_ctrl_t *);
void usart_rx_isr(uintptr_t base, usart_rx_ctrl_t *);

typedef union
{
    struct
    {
        /* aborted is set if user provided predicate was satisfied */
        uint32_t aborted : 1;
        /* set if provided buffer is full */
        uint32_t full : 1;
        /* set if no more data is waiting in HW register */
        uint32_t empty : 1;
        uint32_t : 13;
        uint32_t parity_error : 1;
        uint32_t frame_error : 1;
        uint32_t noise_flag : 1;
        uint32_t overrun_error : 1;
        uint32_t : 12;
    } bits;

    struct
    {
        uint32_t : 16;
        uint32_t fopn : 4;
        uint32_t : 12;
    } errors;

    uint32_t value;
} usart_rx_flags_t;

struct usart_rx_ctrl
{
    uint8_t *begin;
    const uint8_t *end;
    uint8_t *next;
    usart_rx_pred_cb_t pred_cb;
    usart_rx_complete_cb_t complete_cb;
    uintptr_t user_data;
    usart_rx_flags_t flags;
    struct
    {
        uint32_t irq_cntr : 16;
        uint32_t byte_cntr : 16;
    } stats;
};
