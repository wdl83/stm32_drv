#pragma once

#include "mem.h"
#include "stm32.h"

#define FLASH_ACR                                       R32(FLASH_IF_BASE, 0x00)
#define ACR_LATENCY                                                  UINT8_C( 0)
#define ACR_HLFCYA                                                   UINT8_C( 3)
#define ACR_PRFTBE                                                   UINT8_C( 4)
#define ACR_PRFTBS                                                   UINT8_C( 5)

#define FLASH_SYSCLK_24_48MHz()                 FLASH_ACR |= M1(ACR_LATENCY)
#define FLASH_SYSCLK_48_72MHz()                 FLASH_ACR |= M1(ACR_LATENCY + 1)
