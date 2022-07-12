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

#define NVIC_BASE                                           UINT32_C(0xE000E100)
#define STK_BASE                                            UINT32_C(0xE000E010)

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

#define isrNoNonMaskableInt                                          INT8_C(-14)
#define isrNoHardFault                                               INT8_C(-13)
#define isrNoMemoryManagement                                        INT8_C(-12)
#define isrNoBusFault                                                INT8_C(-11)
#define isrNoUsageFault                                              INT8_C(-10)
#define isrNoSVCall                                                  INT8_C( -5)
#define isrNoDebugMonitor                                            INT8_C( -4)
#define isrNoPendSV                                                  INT8_C( -2)
#define isrNoSysTick                                                 INT8_C( -1)
#define isrNoWWDG                                                    INT8_C(  0)
#define isrNoPVD                                                     INT8_C(  1)
#define isrNoTAMPER                                                  INT8_C(  2)
#define isrNoRTC                                                     INT8_C(  3)
#define isrNoFLASH                                                   INT8_C(  4)
#define isrNoRCC                                                     INT8_C(  5)
#define isrNoEXTI0                                                   INT8_C(  6)
#define isrNoEXTI1                                                   INT8_C(  7)
#define isrNoEXTI2                                                   INT8_C(  8)
#define isrNoEXTI3                                                   INT8_C(  9)
#define isrNoEXTI4                                                   INT8_C( 10)
#define isrNoDMA1_Channel1                                           INT8_C( 11)
#define isrNoDMA1_Channel2                                           INT8_C( 12)
#define isrNoDMA1_Channel3                                           INT8_C( 13)
#define isrNoDMA1_Channel4                                           INT8_C( 14)
#define isrNoDMA1_Channel5                                           INT8_C( 15)
#define isrNoDMA1_Channel6                                           INT8_C( 16)
#define isrNoDMA1_Channel7                                           INT8_C( 17)
#define isrNoADC1_2                                                  INT8_C( 18)
#define isrNoUSB_HP_CAN_TX                                           INT8_C( 19)
#define isrNoUSB_LP_CAN_RX0                                          INT8_C( 20)
#define isrNoCAN_RX1                                                 INT8_C( 21)
#define isrNoCAN_SCE                                                 INT8_C( 22)
#define isrNoEXTI9_5                                                 INT8_C( 23)
#define isrNoTIM1_BRK                                                INT8_C( 24)
#define isrNoTIM1_UP                                                 INT8_C( 25)
#define isrNoTIM1_TRG_COM                                            INT8_C( 26)
#define isrNoTIM1_CC                                                 INT8_C( 27)
#define isrNoTIM2                                                    INT8_C( 28)
#define isrNoTIM3                                                    INT8_C( 29)
#define isrNoTIM4                                                    INT8_C( 30)
#define isrNoI2C1_EV                                                 INT8_C( 31)
#define isrNoI2C1_ER                                                 INT8_C( 32)
#define isrNoI2C2_EV                                                 INT8_C( 33)
#define isrNoI2C2_ER                                                 INT8_C( 34)
#define isrNoSPI1                                                    INT8_C( 35)
#define isrNoSPI2                                                    INT8_C( 36)
#define isrNoUSART1                                                  INT8_C( 37)
#define isrNoUSART2                                                  INT8_C( 38)
#define isrNoUSART3                                                  INT8_C( 39)
#define isrNoEXTI15_10                                               INT8_C( 40)
#define isrNoRTCAlarm                                                INT8_C( 41)
#define isrNoUSBWakeUp                                               INT8_C( 42)
