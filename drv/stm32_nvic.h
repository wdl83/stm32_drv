#pragma once

#include "mem.h"
#include "stm32.h"

/*----------------------------------------------------------------------------*/
/* interrupt set-enable
 * '0' write: no effect
 * '1' write: enable interrupt */
#define NVIC_ISER(i)         R32(NVIC_BASE, UINT32_C(0x000) + UINT32_C(4) * (i))
/*----------------------------------------------------------------------------*/
/* interrupt clear-enable
 * '0' write: no effect
 * '1' write: disable interrupt */
#define NVIC_ICER(i)           R32(NVIC_BASE, UINT32_C(0x080) + UINT32_C(4) * i)
/*----------------------------------------------------------------------------*/
#define NVIC_ISPR(i)          R32(NVIC_BASE, UINT32_C(0x100) + UINT32_C(4) * i)
/*----------------------------------------------------------------------------*/
#define NVIC_ICPR(i)           R32(NVIC_BASE, UINT32_C(0x180) + UINT32_C(4) * i)
/*----------------------------------------------------------------------------*/
#define NVIC_IABR(i)           R32(NVIC_BASE, UINT32_C(0x200) + UINT32_C(4) * i)
/*----------------------------------------------------------------------------*/
#define NVIC_IPR(i)            R32(NVIC_BASE, UINT32_C(0x300) + i)
/*----------------------------------------------------------------------------*/
#define NVIC_STIR              R32(NVIC_BASE, UINT32_C(0xE00))
/*----------------------------------------------------------------------------*/
#define NVIC_SET(R, isrNo)     R((isrNo) >> 5) = M1((isrNo) % 32)

#define ISR_ENABLE(isrNo)                             NVIC_SET(NVIC_ISER, isrNo)
#define ISR_DISABLE(isrNo)                            NVIC_SET(NVIC_ICER, isrNo)
#define ISR_SET_PENDING(isrNo)                        NVIC_SET(NVIC_ISPR, isrNo)
#define ISR_CLR_PENDING(isrNo)                        NVIC_SET(NVIC_ICPR, isrNo)
#define ISR_ACTIVE(isrNo)                             NVIC_SET(NVIC_IABR, isrNo)
#define ISR_PRIORITY(isrNo, p)     NVIC_IPR(isrNo) = (((p) & UINT8_C(0xF)) << 4)
#define ISR_TRIGGER(isrNo)                            NVIC_STIR = (isrNo)
