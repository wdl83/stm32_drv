#include <stddef.h>

#include "stm32_usart.h"
#include "usart_tx.h"

const char *usart_send_str_r(
    uintptr_t base, const char *begin, const char *const end)
{
    if(!begin) return begin;

    while(!end && *begin != '\0' || end && begin != end)
    {
        while(!USART_TX_READY(base)) {}
        USART_TX(base, *begin);
        ++begin;
    }

    while(!USART_TX_COMPLETE(base)) {}
    return begin;
}

const char *usart_send_str(uintptr_t base, const char *str)
{
    return usart_send_str_r(base, str, NULL);
}

void usart_send(uintptr_t base, const uint8_t *begin, const uint8_t *const end)
{
    if(!begin || !end || begin == end) return;

    USART_TX_ENABLE(base);

    while(begin != end)
    {
        while(!USART_TX_READY(base)) {}
        USART_TX(base, *begin);
        ++begin;
    }

    while(!USART_TX_COMPLETE(base)) {}
    USART_TX_DISABLE(base);
}
