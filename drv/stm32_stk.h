#pragma once

#include "mem.h"
#include "stm32.h"

/*----------------------------------------------------------------------------*/
#define STK_CTRL                                             R32(STK_BASE, 0x00)
#define CTRL_ENABLE                                                  UINT8_C( 0)
#define CTRL_TICKINT                                                 UINT8_C( 1)
#define CTRL_CLKSOURCE                                               UINT8_C( 2)
#define CTRL_COUNTFALG                                               UINT8_C(16)
/*----------------------------------------------------------------------------*/
#define STK_LOAD                                             R32(STK_BASE, 0x04)
/*----------------------------------------------------------------------------*/
#define STK_VAL                                              R32(STK_BASE, 0x08)
/*----------------------------------------------------------------------------*/

#define STK_CLK_SRC_AHB_DIV8()                   STK_CTRL &= ~M1(CTRL_CLKSOURCE)
#define STK_CLK_SRC_AHB()                        STK_CTRL |= M1(CTRL_CLKSOURCE)

#define STK_INT_ENABLE()                         STK_CTRL |= M1(CTRL_TICKINT)
#define STK_INT_DISABLE()                        STK_CTRL &= ~M1(CTRL_TICKINT)

#define STK_ENABLE()                             STK_CTRL |= M1(CTRL_ENABLE)
#define STK_DISABLE()                            STK_CTRL &= ~M1(CTRL_ENABLE)

#define STK_SET(value)               STK_LOAD = (UINT32_C(0x00FFFFFF) & (value))
#define STK_GET()                    STK_VAL
/*----------------------------------------------------------------------------*/
