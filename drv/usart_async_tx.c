#include <stddef.h>

#include "stm32_usart.h"
#include "usart_async_tx.h"

static
void ctrl_clear(usart_tx_ctrl_t *ctrl)
{
    if(!ctrl) return;
    ctrl->begin = NULL;
    ctrl->end = NULL;
    ctrl->complete_cb = NULL;
    ctrl->user_data = (uintptr_t)0;
}

void usart_async_send(uintptr_t base,  usart_tx_ctrl_t *ctrl)
{
    ASSERT(ctrl);
    ASSERT(ctrl->begin);
    ASSERT(ctrl->end);

    if(!USART_TX_ENABLED(base)) USART_TX_ENABLE(base);
    USART_TX_READY_INT_ENABLE(base);
}

static
void on_tx_ready(uintptr_t base, usart_tx_ctrl_t *ctrl)
{
    ASSERT(ctrl->begin);
    ASSERT(ctrl->end);

    while(ctrl->begin != ctrl->end && USART_TX_READY(base))
    {
        USART_TX(base, *ctrl->begin);
        ++ctrl->begin;
        ++ctrl->stats.byte_cntr;
    }

    if(ctrl->begin == ctrl->end)
    {
        USART_TX_READY_INT_DISABLE(base);
        USART_TX_COMPLETE_INT_ENABLE(base);
    }
}

static
void on_tx_complete(uintptr_t base, usart_tx_ctrl_t *ctrl)
{
    ASSERT(ctrl->begin);
    ASSERT(ctrl->end);
    ASSERT(ctrl->complete_cb);
    ASSERT(ctrl->begin == ctrl->end);

    USART_TX_COMPLETE_INT_DISABLE(base);

    usart_tx_complete_cb_t complete_cb = ctrl->complete_cb;
    uintptr_t user_data = ctrl->user_data;

    ctrl_clear(ctrl);
    if(complete_cb) (*complete_cb)(base, user_data);
}

void usart_tx_isr(uintptr_t base, usart_tx_ctrl_t *ctrl)
{
    ASSERT(ctrl);

    ++ctrl->stats.irq_cntr;

    if(USART_TX_COMPLETE_INT_ENABLED(base) && USART_TX_COMPLETE(base))
    {
        on_tx_complete(base, ctrl);
    }
    else on_tx_ready(base, ctrl);
}
