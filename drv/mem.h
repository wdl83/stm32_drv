#pragma once

#include <stdint.h>

#define R32(base, offset)            (*(volatile uint32_t *)((base) + (offset)))

#define M1(I1) (UINT32_C(1) << (I1))
#define M2(I1, I2) (M1(I1) | UINT32_C(1) << (I2))
#define M3(I1, I2, I3) (M2(I1, I2) | UINT32_C(1) << (I3))
#define M4(I1, I2, I3, I4) (M3(I1, I2, I3) | UINT32_C(1) << (I4))
#define M5(I1, I2, I3, I4, I5) (M4(I1, I2, I3, I4) | UINT32_C(1) << (I5))
#define M6(I1, I2, I3, I4, I5, I6) (M5(I1, I2, I3, I4, I5) | UINT32_C(1) << (I6))
#define M7(I1, I2, I3, I4, I5, I6, I7) (M6(I1, I2, I3, I4, I5, I6) | UINT32_C(1) << (I7))

#define M2R(OFFSET) M2((OFFSET)+1, (OFFSET)+0)
#define M3R(OFFSET) M3((OFFSET)+2, (OFFSET)+1, (OFFSET)+0)
#define M4R(OFFSET) M4((OFFSET)+3, (OFFSET)+2, (OFFSET)+1, (OFFSET)+0)
#define M5R(OFFSET) M5((OFFSET)+4, (OFFSET)+3, (OFFSET)+2, (OFFSET)+1, (OFFSET)+0)
#define M6R(OFFSET) M6((OFFSET)+5, (OFFSET)+4, (OFFSET)+3, (OFFSET)+2, (OFFSET)+1, (OFFSET)+0)
#define M7R(OFFSET) M7((OFFSET)+6, (OFFSET)+5, (OFFSET)+4, (OFFSET)+3, (OFFSET)+2, (OFFSET)+1, (OFFSET)+0)
