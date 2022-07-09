#pragma once

#include "mem.h"
#include "stm32.h"

/*----------------------------------------------------------------------------*/
#define RCC_CR                                               R32(RCC_BASE, 0x00)
#define CR_HSION                                                     UINT8_C( 0)
#define CR_HSIRDY                                                    UINT8_C( 1)
#define CR_HSITRIM                                                   UINT8_C( 3)
#define CR_HSICAL                                                    UINT8_C( 8)
#define CR_HSEON                                                     UINT8_C(16)
#define CR_HSERDY                                                    UINT8_C(17)
#define CR_HSEBYP                                                    UINT8_C(18)
#define CR_CSSON                                                     UINT8_C(19)
#define CR_PLLON                                                     UINT8_C(24)
#define CR_PLLRDY                                                    UINT8_C(25)
/*----------------------------------------------------------------------------*/
#define RCC_CFGR                                             R32(RCC_BASE, 0x04)
#define CFGR_SW                                                      UINT8_C( 0)
#define CFGR_SWS                                                     UINT8_C( 2)
#define CFGR_HPRE                                                    UINT8_C( 4)
#define CFGR_PPRE1                                                   UINT8_C( 8)
#define CFGR_PPRE2                                                   UINT8_C(11)
#define CFGR_ADC_PRE                                                 UINT8_C(14)
#define CFGR_PLLSRC                                                  UINT8_C(16)
#define CFGR_PLLXTPRE                                                UINT8_C(17)
#define CFGR_PLLMULL                                                 UINT8_C(18)
#define CFGR_OTGFSPRE                                                UINT8_C(22)
#define CFGR_MCO                                                     UINT8_C(24)
/*----------------------------------------------------------------------------*/
#define RCC_CIR                                              R32(RCC_BASE, 0x08)
#define CIR_LSIRDYF                                                  UINT8_C( 0)
#define CIR_LSERDYF                                                  UINT8_C( 1)
#define CIR_HSIRDYF                                                  UINT8_C( 2)
#define CIR_HSERDYF                                                  UINT8_C( 3)
#define CIR_PLLRDYF                                                  UINT8_C( 4)
#define CIR_CSSF                                                     UINT8_C( 7)
#define CIR_LSIRDYIE                                                 UINT8_C( 8)
#define CIR_LSERDYIE                                                 UINT8_C( 9)
#define CIR_HSIRDYIE                                                 UINT8_C(10)
#define CIR_HSERDYIE                                                 UINT8_C(11)
#define CIR_PLLRDYIE                                                 UINT8_C(12)
#define CIR_LSIRDYC                                                  UINT8_C(16)
#define CIR_LSERDYC                                                  UINT8_C(17)
#define CIR_HSIRDYC                                                  UINT8_C(18)
#define CIR_HSERDYC                                                  UINT8_C(19)
#define CIR_PLLRDYC                                                  UINT8_C(20)
#define CIR_CSSC                                                     UINT8_C(23)
/*----------------------------------------------------------------------------*/
#define RCC_APB2RSTR                                         R32(RCC_BASE, 0x0C)
#define APB2RSTR_AFIORST                                             UINT8_C( 0)
#define APB2RSTR_IOPARST                                             UINT8_C( 2)
#define APB2RSTR_IOPBRST                                             UINT8_C( 3)
#define APB2RSTR_IOPCRST                                             UINT8_C( 4)
#define APB2RSTR_IOPDRST                                             UINT8_C( 5)
#define APB2RSTR_IOPERST                                             UINT8_C( 6)
#define APB2RSTR_IOPFRST                                             UINT8_C( 7)
#define APB2RSTR_IOPGRST                                             UINT8_C( 8)
#define APB2RSTR_ADC1RST                                             UINT8_C( 9)
#define APB2RSTR_ADC2RST                                             UINT8_C(10)
#define APB2RSTR_TIM1RST                                             UINT8_C(11)
#define APB2RSTR_SPI1RST                                             UINT8_C(12)
#define APB2RSTR_USART1RST                                           UINT8_C(14)
#define APB2RSTR_ADC3RST                                             UINT8_C(14)
#define APB2RSTR_TIM9RST                                             UINT8_C(19)
#define APB2RSTR_TIM10RST                                            UINT8_C(20)
#define APB2RSTR_TIM11RST                                            UINT8_C(21)
/*----------------------------------------------------------------------------*/
#define RCC_APB1RSTR                                         R32(RCC_BASE, 0x10)
#define APB1RSTR_TIM2RST                                             UINT8_C( 0)
#define APB1RSTR_TIM3RST                                             UINT8_C( 1)
#define APB1RSTR_TIM4RST                                             UINT8_C( 2)
#define APB1RSTR_TIM5RST                                             UINT8_C( 3)
#define APB1RSTR_TIM6RST                                             UINT8_C( 4)
#define APB1RSTR_TIM7RST                                             UINT8_C( 5)
#define APB1RSTR_TIM12RST                                            UINT8_C( 6)
#define APB1RSTR_TIM13RST                                            UINT8_C( 7)
#define APB1RSTR_TIM14RST                                            UINT8_C( 8)
#define APB1RSTR_WWDGRST                                             UINT8_C(11)
#define APB1RSTR_SPI2RST                                             UINT8_C(14)
#define APB1RSTR_SPI3RST                                             UINT8_C(15)
#define APB1RSTR_USART2RST                                           UINT8_C(17)
#define APB1RSTR_USART3RST                                           UINT8_C(18)
#define APB1RSTR_USART4RST                                           UINT8_C(19)
#define APB1RSTR_USART5RST                                           UINT8_C(20)
#define APB1RSTR_I2C1RST                                             UINT8_C(21)
#define APB1RSTR_I2C2RST                                             UINT8_C(22)
#define APB1RSTR_USBRST                                              UINT8_C(23)
#define APB1RSTR_CAN1RST                                             UINT8_C(25)
#define APB1RSTR_BKPRST                                              UINT8_C(27)
#define APB1RSTR_PWRRST                                              UINT8_C(28)
#define APB1RSTR_DACRST                                              UINT8_C(29)
/*----------------------------------------------------------------------------*/
#define RCC_AHBENR                                           R32(RCC_BASE, 0x14)
#define AHBENR_DMA1EN                                                UINT8_C( 0)
#define AHBENR_DMA2EN                                                UINT8_C( 1)
#define AHBENR_SRAMEN                                                UINT8_C( 2)
#define AHBENR_FLITFEN                                               UINT8_C( 4)
#define AHBENR_CRCEN                                                 UINT8_C( 6)
#define AHBENR_FSMCEN                                                UINT8_C( 8)
#define AHBENR_SDIOEN                                                UINT8_C(10)
/*----------------------------------------------------------------------------*/
#define RCC_APB2ENR                                          R32(RCC_BASE, 0x18)
#define APB2ENR_AFIOEN                                               UINT8_C( 0)
#define APB2ENR_IOPAEN                                               UINT8_C( 2)
#define APB2ENR_IOPBEN                                               UINT8_C( 3)
#define APB2ENR_IOPCEN                                               UINT8_C( 4)
#define APB2ENR_IOPDEN                                               UINT8_C( 5)
#define APB2ENR_IOPEEN                                               UINT8_C( 6)
#define APB2ENR_IOPFEN                                               UINT8_C( 7)
#define APB2ENR_IOPGEN                                               UINT8_C( 8)
#define APB2ENR_ADC1EN                                               UINT8_C( 9)
#define APB2ENR_ADC2EN                                               UINT8_C(10)
#define APB2ENR_TIM1EN                                               UINT8_C(11)
#define APB2ENR_SPI1EN                                               UINT8_C(12)
#define APB2ENR_TIM8EN                                               UINT8_C(13)
#define APB2ENR_USART1EN                                             UINT8_C(14)
#define APB2ENR_ADC3EN                                               UINT8_C(15)
#define APB2ENR_TIM9EN                                               UINT8_C(19)
#define APB2ENR_TIM10EN                                              UINT8_C(20)
#define APB2ENR_TIM11EN                                              UINT8_C(21)
/*----------------------------------------------------------------------------*/
#define RCC_APB1ENR                                          R32(RCC_BASE, 0x1C)
#define APB1ENR_TIM2EN                                               UINT8_C( 0)
#define APB1ENR_TIM3EN                                               UINT8_C( 1)
#define APB1ENR_TIM4EN                                               UINT8_C( 2)
#define APB1ENR_TIM5EN                                               UINT8_C( 3)
#define APB1ENR_TIM6EN                                               UINT8_C( 4)
#define APB1ENR_TIM7EN                                               UINT8_C( 5)
#define APB1ENR_TIM12EN                                              UINT8_C( 6)
#define APB1ENR_TIM13EN                                              UINT8_C( 7)
#define APB1ENR_TIM14EN                                              UINT8_C( 8)
#define APB1ENR_WWDGEN                                               UINT8_C(11)
#define APB1ENR_SPI2EN                                               UINT8_C(14)
#define APB1ENR_SPI3EN                                               UINT8_C(15)
#define APB1ENR_USART2EN                                             UINT8_C(17)
#define APB1ENR_USART3EN                                             UINT8_C(18)
#define APB1ENR_USART4EN                                             UINT8_C(19)
#define APB1ENR_USART5EN                                             UINT8_C(20)
#define APB1ENR_I2C1EN                                               UINT8_C(21)
#define APB1ENR_I2C2EN                                               UINT8_C(22)
#define APB1ENR_USBEN                                                UINT8_C(23)
#define APB1ENR_CAN1EN                                               UINT8_C(25)
#define APB1ENR_BKPEN                                                UINT8_C(27)
#define APB1ENR_PWREN                                                UINT8_C(28)
#define APB1ENR_DACEN                                                UINT8_C(29)
/*----------------------------------------------------------------------------*/
#define RCC_BDCR                                             R32(RCC_BASE, 0x20)
#define BDCR_LSEON                                                   UINT8_C( 0)
#define BDCR_LSERDY                                                  UINT8_C( 1)
#define BDCR_LSEBYP                                                  UINT8_C( 2)
#define BDCR_RTCSEL                                                  UINT8_C( 8)
#define BDCR_RTCEN                                                   UINT8_C(15)
#define BDCR_BDRST                                                   UINT8_C(16)
/*----------------------------------------------------------------------------*/
#define RCC_CSR_AT                                           R32(RCC_BASE, 0x24)
#define CSR_LSION                                                    UINT8_C( 0)
#define CSR_LSIRDY                                                   UINT8_C( 1)
#define CSR_RMVF                                                     UINT8_C(24)
#define CSR_PINRSTF                                                  UINT8_C(26)
#define CSR_PORRSTF                                                  UINT8_C(27)
#define CSR_SFTRSTF                                                  UINT8_C(28)
#define CSR_IWDGRSTF                                                 UINT8_C(29)
#define CSR_WWDGRSTF                                                 UINT8_C(30)
#define CSR_LPWRRSTF                                                 UINT8_C(31)
/*----------------------------------------------------------------------------*/
#define HSE_ENABLE()                 RCC_CR |= M1(CR_HSEON)
#define HSE_READY()                 (RCC_CR & M1(CR_HSERDY))

#define PLL_ENABLE()                 RCC_CR |= M1(CR_PLLON)
#define PLL_READY()                 (RCC_CR & M1(CR_PLLRDY))
#define PLL_SRC_HSI()                RCC_CFGR &= ~M1(CFGR_PLLSRC)
#define PLL_SRC_HSE()                RCC_CFGR |= M1(CFGR_PLLSRC)
#define PLL_MUL_9()                  RCC_CFGR |= UINT32_C(9 - 2) << CFGR_PLLMULL

#define APB1_CLK_DIV2()              RCC_CFGR |= UINT32_C(0 + 4) << CFGR_PPRE1
#define APB1_CLK_DIV4()              RCC_CFGR |= UINT32_C(1 + 4) << CFGR_PPRE1
#define APB1_CLK_DIV8()              RCC_CFGR |= UINT32_C(2 + 4) << CFGR_PPRE1
#define APB1_CLK_DIV16()             RCC_CFGR |= UINT32_C(3 + 4) << CFGR_PPRE1

#define SYSCLK_SRC_HSI()             RCC_CFGR &= ~M2R(CFGR_SW)
#define SYSCLK_SRC_HSE()             RCC_CFGR |= M1(CFGR_SW)
#define SYSCLK_SRC_PLL()             RCC_CFGR |= M1(CFGR_SW + 1)

#define IS_SYSCLK_SRC_HSI()       (!(RCC_CFGR & M2R(CFGR_SWS)))
#define IS_SYSCLK_SRC_HSE()         (RCC_CFGR & M1(CFGR_SWS))
#define IS_SYSCLK_SRC_PLL()         (RCC_CFGR & M1(CFGR_SWS + 1))

#define USART1_CLK_ENABLE()          RCC_APB2ENR |= M1(APB2ENR_USART1EN)
#define USART1_CLK_DISABLE()         RCC_APB2ENR &= ~M1(APB2ENR_USART1EN)

#define PORTA_CLK_ENABLE()           RCC_APB2ENR |= M1(APB2ENR_IOPAEN)
#define PORTB_CLK_ENABLE()           RCC_APB2ENR |= M1(APB2ENR_IOPBEN)
#define PORTC_CLK_ENABLE()           RCC_APB2ENR |= M1(APB2ENR_IOPCEN)
#define PORTD_CLK_ENABLE()           RCC_APB2ENR |= M1(APB2ENR_IOPDEN)
#define PORTE_CLK_ENABLE()           RCC_APB2ENR |= M1(APB2ENR_IOPEEN)
#define PORTF_CLK_ENABLE()           RCC_APB2ENR |= M1(APB2ENR_IOPFEN)
#define PORTG_CLK_ENABLE()           RCC_APB2ENR |= M1(APB2ENR_IOPGEN)
/*----------------------------------------------------------------------------*/