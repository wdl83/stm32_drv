#include <stddef.h>
#include <string.h>

#include "check.h"
#include "stm32_usart.h"
#include "usart_async_rx.h"

void usart_async_recv(uintptr_t base, usart_rx_ctrl_t *ctrl)
{
    ASSERT(ctrl);
    ASSERT(ctrl->begin);
    ASSERT(ctrl->end);
    ASSERT(ctrl->next == ctrl->begin);
    ASSERT(ctrl->end != ctrl->begin);
    ASSERT(ctrl->complete_cb);

    if(!USART_RX_ENABLED(base)) USART_RX_ENABLE(base);
    USART_RX_INT_ENABLE(base);
}

void usart_rx_isr(uintptr_t base, usart_rx_ctrl_t *ctrl)
{
    ASSERT(ctrl);
    ++ctrl->stats.irq_cntr;
    /* buffer can not be full on entry to ISR - otherwise
     * data will be lost */
    ASSERT(ctrl->next != ctrl->end);

    while(ctrl->next != ctrl->end && USART_RX_READY(base))
    {
        ctrl->flags.errors.fopn = USART_FOPN_ERR(base);
        USART_RX(base, *ctrl->next);
        ++ctrl->stats.byte_cntr;
        ++ctrl->next;

        if(!ctrl->pred_cb) continue;

        if((*ctrl->pred_cb)(ctrl->next - 1, ctrl))
        {
            ctrl->flags.bits.aborted = 1;
            break;
        }
    }

	ctrl->flags.bits.full = ctrl->next == ctrl->end;
	ctrl->flags.bits.empty = !USART_RX_READY(base);

    if(ctrl->flags.bits.full || ctrl->flags.bits.aborted)
    {
        USART_RX_INT_DISABLE(base);
        /* there is data in buffer */
        if(ctrl->begin != ctrl->next)
        {
            ASSERT(ctrl->complete_cb);
            (*ctrl->complete_cb)(base, ctrl);
        }
    }
}
