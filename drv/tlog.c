#include <stdarg.h>
#include <stddef.h>
#include <stdio.h>

#include "stm32.h"
#include "tlog.h"
#include "util.h"

typedef struct
{
    char *begin;
    const char *end;
    char *cur;
    uint8_t cntr;
} tlog_t;

tlog_t tlog_;

void tlog_init(char *buf)
{
    tlog_.begin = buf;
    tlog_.end = tlog_.begin + TLOG_SIZE - 1;
    tlog_.cur = tlog_.begin;
}

void tlog_append(const char *begin, size_t len)
{
    /* cntr is appended as HEX + 1 space char */
    const uint8_t prefix_len = (sizeof(tlog_.cntr) << 1) + 1;

    if(TLOG_SIZE < len + prefix_len) return;

    primask_t primask = PRIMASK_IRQ_DISABLED;

    PRIMASK_SWAP(primask); // disable IRQ (storing current IRQ state)
    {

        const size_t capacity = tlog_.end - tlog_.cur;

        if(capacity < len + prefix_len)
        {
            /* fill remaining tlog buffer with zeros */
            *(tlog_.cur - 1) = '\n';
            bzero(tlog_.cur, capacity);
            /* wrap around and retry */
            tlog_.cur = tlog_.begin;
        }

        tlog_.cur = xprint8(tlog_.cur, tlog_.cntr);
        *tlog_.cur++ = ' ';
        memcpy(tlog_.cur, begin, len);
        tlog_.cur += len;
        ++tlog_.cntr;
    }
    PRIMASK_SWAP(primask); // restore IRQ state
}

void tlog_clear(void)
{
    primask_t primask = PRIMASK_IRQ_DISABLED;
    PRIMASK_SWAP(primask);
    tlog_.cur = tlog_.begin;
    PRIMASK_SWAP(primask);
}

const char *tlog_begin(void)
{
    return tlog_.begin;
}

const char *tlog_end(void)
{
    return tlog_.end;
}
