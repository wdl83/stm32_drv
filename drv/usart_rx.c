#include <stddef.h>
#include <string.h>

#include "check.h"
#include "stm32_usart.h"
#include "usart_rx.h"

char *usart_recv_str(
    uintptr_t base,
    char *begin, const char *const end, char delimiter)
{
    if(!begin || !end) return NULL;

    while(begin != end)
    {
        while(!USART_RX_READY(base)) {}
        USART_RX(base, *begin);
        ++begin;
        /* special character received */
        if(*(begin - 1) == delimiter) break;
    }

    return begin;
}
