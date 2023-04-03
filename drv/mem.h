#pragma once

#include <stdint.h>

#define R32(base, offset)            (*(volatile uint32_t *)((base) + (offset)))

#define M1(a)                                     (UINT32_C(1) << (a))
#define M2(a, b)                                  (M1(a) | M1(b))
#define M3(a, b, c)                               (M2(a, b) | M1(c))
#define M4(a, b, c, d)                            (M3(a, b, c) | M1(d))
#define M5(a, b, c, d, e)                         (M4(a, b, c, d) | M1(e))
#define M6(a, b, c, d, e, f)                      (M5(a, b, c, d, e) | M1(f))
#define M7(a, b, c, d, e, f, g)                   (M6(a, b, c, d, e, f) | M1(g))

#define M2R(i)               M2((i)+1, (i)+0)
#define M3R(i)               M3((i)+2, (i)+1, (i)+0)
#define M4R(i)               M4((i)+3, (i)+2, (i)+1, (i)+0)
#define M5R(i)               M5((i)+4, (i)+3, (i)+2, (i)+1, (i)+0)
#define M6R(i)               M6((i)+5, (i)+4, (i)+3, (i)+2, (i)+1, (i)+0)
#define M7R(i)               M7((i)+6, (i)+5, (i)+4, (i)+3, (i)+2, (i)+1, (i)+0)

#define MSK2R(R, i)                                              ((R) & ~M2R(i))
#define MSK3R(R, i)                                              ((R) & ~M3R(i))
#define MSK4R(R, i)                                              ((R) & ~M4R(i))
#define MSK5R(R, i)                                              ((R) & ~M5R(i))
#define MSK6R(R, i)                                              ((R) & ~M6R(i))
#define MSK7R(R, i)                                              ((R) & ~M7R(i))

#define CLR2R(R, i)                                               (R) &= ~M2R(i)
#define CLR3R(R, i)                                               (R) &= ~M3R(i)
#define CLR4R(R, i)                                               (R) &= ~M4R(i)
#define CLR5R(R, i)                                               (R) &= ~M5R(i)
#define CLR6R(R, i)                                               (R) &= ~M6R(i)
#define CLR7R(R, i)                                               (R) &= ~M7R(i)

#define SET2R(R, i, v)     (R) = (MSK2R(R, i) | (M2R(i) & ((uint32_t)(v) << i)))
#define SET3R(R, i, v)     (R) = (MSK3R(R, i) | (M3R(i) & ((uint32_t)(v) << i)))
#define SET4R(R, i, v)     (R) = (MSK4R(R, i) | (M4R(i) & ((uint32_t)(v) << i)))
#define SET5R(R, i, v)     (R) = (MSK5R(R, i) | (M5R(i) & ((uint32_t)(v) << i)))
#define SET6R(R, i, v)     (R) = (MSK6R(R, i) | (M6R(i) & ((uint32_t)(v) << i)))
#define SET7R(R, i, v)     (R) = (MSK7R(R, i) | (M7R(i) & ((uint32_t)(v) << i)))
