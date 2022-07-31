#pragma once

#include <stdint.h>

#include "check.h"

typedef uint32_t primask_t;

#define PRIMASK_IRQ_DISABLED                                         UINT32_C(1)
#define PRIMASK_IRQ_ENABLED                                          UINT32_C(0)


#define PRIMASK_GET(mask) \
        do { \
            asm volatile ("MRS %0, PRIMASK" : "=r" (mask) ::); \
        } while(0)

#define PRIMASK_SET(mask) \
        do { \
            asm volatile ("MSR PRIMASK, %0" :: "r" (mask)); \
        } while(0)

#define PRIMASK_SWAP(next) \
    do { \
        primask_t curr; \
        PRIMASK_GET(curr); \
        PRIMASK_SET(next); \
        (next) = curr; \
    } while(0)

// PMASK = 1, Prevents the activation of all exceptions with configurable priority
#define INTERRUPT_DISABLE()              do {asm volatile ("cpsid i");} while(0)
#define INTERRUPT_ENABLE()               do {asm volatile ("cpsie i");} while(0)
// FMASK = 1, Prevents the activation of all exceptions except for NMI
#define FAULT_DISABLE()                  do {asm volatile ("cpsid f");} while(0)
#define FAULT_ENABLE()                   do {asm volatile ("cpsie f");} while(0)
// wait for interrupt
#define WAIT_FOR_INTERRUPT()             do {asm volatile ("wfi");} while(0)
// wait for event
#define WAIT_FOR_EVENT()                 do {asm volatile ("wfe");} while(0)

#ifdef STM32F103C8
#include "stm32f103c8.h"
#else
#error "unsupported device"
#endif
