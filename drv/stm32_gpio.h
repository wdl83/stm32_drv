#pragma once

#include "mem.h"
#include "stm32.h"

#define GPIO_CRL(base)                                           R32(base, 0x00)
#define GPIOA_CRL                                          R32(GPIOA_BASE, 0x00)
#define GPIOB_CRL                                          R32(GPIOB_BASE, 0x00)
#define GPIOC_CRL                                          R32(GPIOC_BASE, 0x00)
#define GPIOD_CRL                                          R32(GPIOD_BASE, 0x00)
#define GPIOE_CRL                                          R32(GPIOE_BASE, 0x00)
#define GPIOF_CRL                                          R32(GPIOF_BASE, 0x00)
#define GPIOG_CRL                                          R32(GPIOG_BASE, 0x00)

#define CRL_MODE0                                                    UINT8_C( 0)
#define CRL_CNF0                                                     UINT8_C( 2)
#define CRL_MODE1                                                    UINT8_C( 4)
#define CRL_CNF1                                                     UINT8_C( 6)
#define CRL_MODE2                                                    UINT8_C( 8)
#define CRL_CNF2                                                     UINT8_C(10)
#define CRL_MODE3                                                    UINT8_C(12)
#define CRL_CNF3                                                     UINT8_C(14)
#define CRL_MODE4                                                    UINT8_C(16)
#define CRL_CNF4                                                     UINT8_C(18)
#define CRL_MODE5                                                    UINT8_C(20)
#define CRL_CNF5                                                     UINT8_C(22)
#define CRL_MODE6                                                    UINT8_C(24)
#define CRL_CNF6                                                     UINT8_C(26)
#define CRL_MODE7                                                    UINT8_C(28)
#define CRL_CNF7                                                     UINT8_C(30)

#define GPIO_CRH(base)                                           R32(base, 0x04)
#define GPIOA_CRH                                          R32(GPIOA_BASE, 0x04)
#define GPIOB_CRH                                          R32(GPIOB_BASE, 0x04)
#define GPIOC_CRH                                          R32(GPIOC_BASE, 0x04)
#define GPIOD_CRH                                          R32(GPIOD_BASE, 0x04)
#define GPIOE_CRH                                          R32(GPIOE_BASE, 0x04)
#define GPIOF_CRH                                          R32(GPIOF_BASE, 0x04)
#define GPIOG_CRH                                          R32(GPIOG_BASE, 0x04)

#define CRH_MODE8                                                    UINT8_C( 0)
#define CRH_CNF8                                                     UINT8_C( 2)
#define CRH_MODE9                                                    UINT8_C( 4)
#define CRH_CNF9                                                     UINT8_C( 6)
#define CRH_MODE10                                                   UINT8_C( 8)
#define CRH_CNF10                                                    UINT8_C(10)
#define CRH_MODE11                                                   UINT8_C(12)
#define CRH_CNF11                                                    UINT8_C(14)
#define CRH_MODE12                                                   UINT8_C(16)
#define CRH_CNF12                                                    UINT8_C(18)
#define CRH_MODE13                                                   UINT8_C(20)
#define CRH_CNF13                                                    UINT8_C(22)
#define CRH_MODE14                                                   UINT8_C(24)
#define CRH_CNF14                                                    UINT8_C(26)
#define CRH_MODE15                                                   UINT8_C(28)
#define CRH_CNF15                                                    UINT8_C(30)

/* Read-Only 32bit-only (contain the input value of corresponding I/O port) */
#define GPIO_IDR(base)                                           R32(base, 0x08)
#define GPIOA_IDR                                          R32(GPIOA_BASE, 0x08)
#define GPIOB_IDR                                          R32(GPIOB_BASE, 0x08)
#define GPIOC_IDR                                          R32(GPIOC_BASE, 0x08)
#define GPIOD_IDR                                          R32(GPIOD_BASE, 0x08)
#define GPIOE_IDR                                          R32(GPIOE_BASE, 0x08)
#define GPIOF_IDR                                          R32(GPIOF_BASE, 0x08)
#define GPIOG_IDR                                          R32(GPIOG_BASE, 0x08)

/* Read/Write 32bit-only (use BSRR/BRR for atomic access) */
#define GPIO_ODR(base)                                           R32(base, 0x0C)
#define GPIOA_ODR                                          R32(GPIOA_BASE, 0x0C)
#define GPIOB_ODR                                          R32(GPIOB_BASE, 0x0C)
#define GPIOC_ODR                                          R32(GPIOC_BASE, 0x0C)
#define GPIOD_ODR                                          R32(GPIOD_BASE, 0x0C)
#define GPIOE_ODR                                          R32(GPIOE_BASE, 0x0C)
#define GPIOF_ODR                                          R32(GPIOF_BASE, 0x0C)
#define GPIOG_ODR                                          R32(GPIOG_BASE, 0x0C)

#define GPIO_BSRR(base)                                          R32(base, 0x10)
#define GPIOA_BSRR                                         R32(GPIOA_BASE, 0x10)
#define GPIOB_BSRR                                         R32(GPIOB_BASE, 0x10)
#define GPIOC_BSRR                                         R32(GPIOC_BASE, 0x10)
#define GPIOD_BSRR                                         R32(GPIOD_BASE, 0x10)
#define GPIOE_BSRR                                         R32(GPIOE_BASE, 0x10)
#define GPIOF_BSRR                                         R32(GPIOF_BASE, 0x10)
#define GPIOG_BSRR                                         R32(GPIOG_BASE, 0x10)
#define BSRR_BS                                                      UINT8_C( 0)
#define BSRR_BR                                                      UINT8_C(16)

#define GPIO_BRR(base)                                           R32(base, 0x14)
#define GPIOA_BRR                                          R32(GPIOA_BASE, 0x14)
#define GPIOB_BRR                                          R32(GPIOB_BASE, 0x14)
#define GPIOC_BRR                                          R32(GPIOC_BASE, 0x14)
#define GPIOD_BRR                                          R32(GPIOD_BASE, 0x14)
#define GPIOE_BRR                                          R32(GPIOE_BASE, 0x14)
#define GPIOF_BRR                                          R32(GPIOF_BASE, 0x14)
#define GPIOG_BRR                                          R32(GPIOG_BASE, 0x14)
#define BRR_BR                                                       UINT8_C( 0)

#define GPIO_LCKR(base)                                          R32(base, 0x18)
#define GPIOA_LCKR                                         R32(GPIOA_BASE, 0x18)
#define GPIOB_LCKR                                         R32(GPIOB_BASE, 0x18)
#define GPIOC_LCKR                                         R32(GPIOC_BASE, 0x18)
#define GPIOD_LCKR                                         R32(GPIOD_BASE, 0x18)
#define GPIOE_LCKR                                         R32(GPIOE_BASE, 0x18)
#define GPIOF_LCKR                                         R32(GPIOF_BASE, 0x18)
#define GPIOG_LCKR                                         R32(GPIOG_BASE, 0x18)
#define LCKR_LCK                                                     UINT8_C( 0)
#define LCKR_LCKK                                                    UINT8_C(16)
/*------------------------------------------------------------------------------
 * RM0008 Reference manual (Rev 21, 02/2021)
 * 9.1 General-purpose and alternate-function I/Os (GPIOs and AFIOs),
 * Table 20 */
#define CFN_OUT_PUSH_PULL                                            UINT32_C(0)
#define CFN_OUT_OPEN_DRAIN                                           UINT32_C(1)
#define CFN_OUT_ALT_PUSH_PULL                                        UINT32_C(2)
#define CFN_OUT_ALT_OPEN_DRAIN                                       UINT32_C(3)
#define CFN_IN_ANALOG                                                UINT32_C(0)
#define CFN_IN_FLOAT                                                 UINT32_C(1)
#define CFN_IN_PULL_UP_DOWN                                          UINT32_C(2)

#define MODE_INPUT                                                   UINT32_C(0)
#define MODE_10MHz                                                   UINT32_C(1)
#define MODE_2MHz                                                    UINT32_C(2)
#define MODE_50MHz                                                   UINT32_C(3)

#define MODE_MASK(pin)                                  (UINT32_C(0x3) << (pin))
#define CFN_MASK(pin)                                   (UINT32_C(0x3) << (pin))

#define GPIO_CFG_L(base, i, cfn, mode) \
    do { \
        GPIO_CRL(base) &= ~(CFN_MASK((i) * 4 + 2) | MODE_MASK((i) * 4)); \
        GPIO_CRL(base) |= (cfn) << ((i) * 4 + 2) | (mode) << ((i) * 4); \
    } while(0)

#define GPIO_CFG_H(base, i, cfn, mode) \
    do { \
        GPIO_CRH(base) &= ~(CFN_MASK((i) * 4 + 2) | MODE_MASK((i) * 4)); \
        GPIO_CRH(base) |= (cfn) << ((i) * 4 + 2) | (mode) << ((i) * 4); \
    } while(0)

#define GPIO_CFG(base, pin, cfn, mode) \
    do { \
        if(8 > (pin)) {GPIO_CFG_L(base, pin & 0x7, cfn, mode);} \
        else {GPIO_CFG_H(base, ((pin) - 8) & 0xF, cfn, mode);} \
    } while(0)
/*----------------------------------------------------------------------------*/
