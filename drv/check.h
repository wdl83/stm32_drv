#pragma once

#include <stddef.h>

#define STATIC_ASSERT_MSG(cond, msg) \
    typedef struct {uint8_t value : (cond) ? 8 : 0;} static_assert_##msg

#define STATIC_ASSERT_IMPL1(cond, L, C) \
    STATIC_ASSERT_MSG(cond, C##_at_line_##L)

#define STATIC_ASSERT_IMPL2(cond, L, C) \
    STATIC_ASSERT_IMPL1(cond, L, C)

#define STATIC_ASSERT(cond) \
    STATIC_ASSERT_IMPL2(cond, __LINE__, __COUNTER__)

#define STRUCT_OFFSET(type, field) \
    (size_t)((const uint8_t *const)(&((const type *const)NULL)->field))

#define STATIC_ASSERT_STRUCT_OFFSET(type, field, offset) \
    STATIC_ASSERT(STRUCT_OFFSET(type, field) == (size_t)(offset))

#define ASSERT(cond)
