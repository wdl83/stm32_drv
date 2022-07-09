#pragma once

#include <stdint.h>

#define ASSERT(cond)

#ifdef STM32F103C8
#include "stm32f103c8.h"
#else
#error "unsupported device"
#endif
