#pragma once

#include <stdint.h>

#define FLASH_BASE                                          UINT32_C(0x08000000)
#define SRAM_BASE                                           UINT32_C(0x20000000)
#define PERIPH_BASE                                         UINT32_C(0x40000000)

#define SRAM_BB_BASE                                        UINT32_C(0x22000000)
#define PERIPH_BB_BASE                                      UINT32_C(0x42000000)
#define PERIPH_BASE                                         UINT32_C(0x40000000)


#define APB1_BASE                           (PERIPH_BASE + UINT32_C(0x00000000))
#define APB2_BASE                           (PERIPH_BASE + UINT32_C(0x00010000))
#define AHB_BASE                            (PERIPH_BASE + UINT32_C(0x00020000))

#define FLASH_IF_BASE                          (AHB_BASE + UINT32_C(0x00002000))

#define USART1_BASE                           (APB2_BASE + UINT32_C(0x00003800))
#define USART2_BASE                           (APB1_BASE + UINT32_C(0x00004400))
#define USART3_BASE                           (APB1_BASE + UINT32_C(0x00004800))


#define RCC_BASE                               (AHB_BASE + UINT32_C(0x00001000))

#define GPIOA_BASE                            (APB2_BASE + UINT32_C(0x00000800))
#define GPIOB_BASE                            (APB2_BASE + UINT32_C(0x00000C00))
#define GPIOC_BASE                            (APB2_BASE + UINT32_C(0x00001000))
#define GPIOD_BASE                            (APB2_BASE + UINT32_C(0x00001400))
#define GPIOE_BASE                            (APB2_BASE + UINT32_C(0x00001800))
