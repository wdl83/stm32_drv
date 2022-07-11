#include <stddef.h>

#include "stm32_usart.h"
#include "usart_async_tx.h"

void usart_async_send(uintptr_t base,  usart_tx_ctrl_t *ctrl)
{
    ASSERT(ctrl);
    ASSERT(ctrl->begin);
    ASSERT(ctrl->end);

    if(!USART_TX_ENABLED(base)) USART_TX_ENABLE(base);
    USART_TX_READY_INT_ENABLE(base);
}

void usart_tx_isr(uintptr_t base, usart_tx_ctrl_t *ctrl)
{
    ASSERT(ctrl);
    ASSERT(ctrl->begin);
    ASSERT(ctrl->end);

    ++ctrl->stats.irq_cntr;

    if(USART_TX_COMPLETE_INT_ENABLED(base) && USART_TX_COMPLETE(base))
    {
        ASSERT(ctrl->complete_cb);
        ASSERT(ctrl->begin == ctrl->end);

        USART_TX_COMPLETE_INT_DISABLE(base);

        if(ctrl->complete_cb) (*ctrl->complete_cb)(base, ctrl);
    }
    else
    {
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
}
