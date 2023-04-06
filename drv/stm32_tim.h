#pragma once

#include "mem.h"
#include "stm32.h"

/*----------------------------------------------------------------------------*/
#define TIM_CR1(base)                                            R32(base, 0x00)
#define CR1_CEN                                                      UINT8_C( 0)
#define CR1_UDIS                                                     UINT8_C( 1)
#define CR1_URS                                                      UINT8_C( 2)
#define CR1_OPM                                                      UINT8_C( 3)
#define CR1_DIR                                                      UINT8_C( 4)
#define CR1_CMS                                                      UINT8_C( 5)
#define CR1_ARPE                                                     UINT8_C( 7)
#define CR1_CKD                                                      UINT8_C( 8)
/*----------------------------------------------------------------------------*/
#define TIM_CR2(base)                                            R32(base, 0x04)
#define CR2_CCPC                                                     UINT8_C( 0)
#define CR2_CCUS                                                     UINT8_C( 2)
#define CR2_CCDS                                                     UINT8_C( 3)
#define CR2_MMS                                                      UINT8_C( 4)
#define CR2_TI1S                                                     UINT8_C( 7)
#define CR2_OIS1                                                     UINT8_C( 8)
#define CR2_OIS1N                                                    UINT8_C( 9)
#define CR2_OIS2                                                     UINT8_C(10)
#define CR2_OIS2N                                                    UINT8_C(11)
#define CR2_OIS3                                                     UINT8_C(12)
#define CR2_OIS3N                                                    UINT8_C(13)
#define CR2_OIS4                                                     UINT8_C(14)
/*----------------------------------------------------------------------------*/
#define TIM_SMCR(base)                                           R32(base, 0x08)
#define SMCR_SMS                                                     UINT8_C( 0)
#define SMCR_TS                                                      UINT8_C( 4)
#define SMCR_MSM                                                     UINT8_C( 7)
#define SMCR_ETF                                                     UINT8_C( 8)
#define SMCR_ETPS                                                    UINT8_C(12)
#define SMCR_ECE                                                     UINT8_C(14)
#define SMCR_ETP                                                     UINT8_C(15)
/*----------------------------------------------------------------------------*/
#define TIM_DIER(base)                                           R32(base, 0x0C)
#define DIER_UIE                                                     UINT8_C( 0)
#define DIER_CC1IE                                                   UINT8_C( 1)
#define DIER_CC2IE                                                   UINT8_C( 2)
#define DIER_CC3IE                                                   UINT8_C( 3)
#define DIER_CC4IE                                                   UINT8_C( 4)
#define DIER_COMIE                                                   UINT8_C( 5)
#define DIER_TIE                                                     UINT8_C( 6)
#define DIER_BIE                                                     UINT8_C( 7)
#define DIER_UDE                                                     UINT8_C( 8)
#define DIER_CC1DE                                                   UINT8_C( 9)
#define DIER_CC2DE                                                   UINT8_C(10)
#define DIER_CC3DE                                                   UINT8_C(11)
#define DIER_CC4DE                                                   UINT8_C(12)
#define DIER_COMDE                                                   UINT8_C(13)
#define DIER_TDE                                                     UINT8_C(14)
/*----------------------------------------------------------------------------*/
#define TIM_SR(base)                                             R32(base, 0x10)
#define SR_UIF                                                       UINT8_C( 0)
#define SR_CC1IF                                                     UINT8_C( 1)
#define SR_CC2IF                                                     UINT8_C( 2)
#define SR_CC3IF                                                     UINT8_C( 3)
#define SR_CC4IF                                                     UINT8_C( 4)
#define SR_COMIF                                                     UINT8_C( 5)
#define SR_TIF                                                       UINT8_C( 6)
#define SR_BIF                                                       UINT8_C( 7)
#define SR_CC1OF                                                     UINT8_C( 9)
#define SR_CC2OF                                                     UINT8_C(10)
#define SR_CC3OF                                                     UINT8_C(11)
#define SR_CC4OF                                                     UINT8_C(12)
/*----------------------------------------------------------------------------*/
#define TIM_EGR(base)                                            R32(base, 0x14)
#define EGR_UG                                                       UINT8_C( 0)
#define EGR_CC1G                                                     UINT8_C( 1)
#define EGR_CC2G                                                     UINT8_C( 2)
#define EGR_CC3G                                                     UINT8_C( 3)
#define EGR_CC4G                                                     UINT8_C( 4)
#define EGR_COMG                                                     UINT8_C( 5)
#define EGR_TG                                                       UINT8_C( 6)
#define EGR_BG                                                       UINT8_C( 7)
/*----------------------------------------------------------------------------*/
#define TIM_CCMR1(base)                                          R32(base, 0x18)
#define CCMR1_CC1S                                                   UINT8_C( 0)
#define CCMR1_IC1PSC                                                 UINT8_C( 2)
#define CCMR1_OC1FE                                                  UINT8_C( 2)
#define CCMR1_OC1PE                                                  UINT8_C( 3)
#define CCMR1_IC1F                                                   UINT8_C( 4)
#define CCMR1_OC1M                                                   UINT8_C( 4)
#define CCMR1_OC1CE                                                  UINT8_C( 7)
#define CCMR1_CC2S                                                   UINT8_C( 8)
#define CCMR1_IC2PSC                                                 UINT8_C(10)
#define CCMR1_OC2FE                                                  UINT8_C(10)
#define CCMR1_OC2PE                                                  UINT8_C(11)
#define CCMR1_IC2F                                                   UINT8_C(12)
#define CCMR1_OC2M                                                   UINT8_C(12)
#define CCMR1_OC2CE                                                  UINT8_C(15)
/*----------------------------------------------------------------------------*/
#define TIM_CCMR2(base)                                          R32(base, 0x1C)
#define CCMR2_CC3S                                                   UINT8_C( 0)
#define CCMR2_IC3PSC                                                 UINT8_C( 2)
#define CCMR2_OC3FE                                                  UINT8_C( 2)
#define CCMR2_OC3PE                                                  UINT8_C( 3)
#define CCMR2_IC3F                                                   UINT8_C( 4)
#define CCMR2_OC3M                                                   UINT8_C( 4)
#define CCMR2_OC3CE                                                  UINT8_C( 7)
#define CCMR2_CC4S                                                   UINT8_C( 8)
#define CCMR2_IC4PSC                                                 UINT8_C(10)
#define CCMR2_OC4FE                                                  UINT8_C(10)
#define CCMR2_OC4PE                                                  UINT8_C(11)
#define CCMR2_IC4F                                                   UINT8_C(12)
#define CCMR2_OC4M                                                   UINT8_C(12)
#define CCMR2_OC4CE                                                  UINT8_C(15)
/*----------------------------------------------------------------------------*/
#define TIM_CCER(base)                                           R32(base, 0x20)
#define CCER_CC1E                                                    UINT8_C( 0)
#define CCER_CC1P                                                    UINT8_C( 1)
#define CCER_CC1NE                                                   UINT8_C( 2)
#define CCER_CC1NP                                                   UINT8_C( 3)
#define CCER_CC2E                                                    UINT8_C( 4)
#define CCER_CC2P                                                    UINT8_C( 5)
#define CCER_CC2NE                                                   UINT8_C( 6)
#define CCER_CC2NP                                                   UINT8_C( 7)
#define CCER_CC3E                                                    UINT8_C( 8)
#define CCER_CC3P                                                    UINT8_C( 9)
#define CCER_CC3NE                                                   UINT8_C(10)
#define CCER_CC3NP                                                   UINT8_C(11)
#define CCER_CC4E                                                    UINT8_C(12)
#define CCER_CC4P                                                    UINT8_C(13)
/*----------------------------------------------------------------------------*/
#define TIM_CNT(base)                                            R32(base, 0x24)
/*----------------------------------------------------------------------------*/
#define TIM_PSC(base)                                            R32(base, 0x28)
/*----------------------------------------------------------------------------*/
#define TIM_ARR(base)                                            R32(base, 0x2C)
/*----------------------------------------------------------------------------*/
#define TIM_RCR(base)                                            R32(base, 0x30)
/*----------------------------------------------------------------------------*/
#define TIM_CCR1(base)                                           R32(base, 0x34)
/*----------------------------------------------------------------------------*/
#define TIM_CCR2(base)                                           R32(base, 0x38)
/*----------------------------------------------------------------------------*/
#define TIM_CCR3(base)                                           R32(base, 0x3C)
/*----------------------------------------------------------------------------*/
#define TIM_CCR4(base)                                           R32(base, 0x40)
/*----------------------------------------------------------------------------*/
#define TIM_BDTR(base)                                           R32(base, 0x44)
#define BDTR_DTG                                                     UINT8_C( 0)
#define BDTR_LOCK                                                    UINT8_C( 8)
#define BDTR_OSSI                                                    UINT8_C(10)
#define BDTR_OSSR                                                    UINT8_C(11)
#define BDTR_BKE                                                     UINT8_C(12)
#define BDTR_BKP                                                     UINT8_C(13)
#define BDTR_AOE                                                     UINT8_C(14)
#define BDTR_MOE                                                     UINT8_C(15)
/*----------------------------------------------------------------------------*/
#define TIM_DCR(base)                                            R32(base, 0x48)
#define DCR_DBA                                                      UINT8_C( 0)
#define DCR_DBL                                                      UINT8_C( 8)
/*----------------------------------------------------------------------------*/
#define TIM_DMAR(base)                                           R32(base, 0x4C)
/*----------------------------------------------------------------------------*/
#define TIM_ENABLE(base)                           TIM_CR1(base) |= M1(CR1_CEN)
#define TIM_DISABLE(base)                          TIM_CR1(base) &= ~M1(CR1_CEN)
#define TIM_ENABLED(base)                         (TIM_CR1(base) & M1(CR1_CEN))
#define TIM_AUTO_RELOAD_PRELOAD_ENABLE(base)       TIM_CR1(base) |= M1(CR1_ARPE)
#define TIM_COUNT_UP(base)                         TIM_CR1(base) &= ~M1(CR1_DIR)
#define TIM_COUNT_DOWN(base)                       TIM_CR1(base) |= M1(CR1_DIR)

#define TIM_UPDATE_INT_ENABLE(base)              TIM_DIER(base) |= M1(DIER_UIE)
#define TIM_UPDATE_INT_DISABLE(base)             TIM_DIER(base) &= ~M1(DIER_UIE)

#define TIM_UPDATE_INT_CLEAR(base)                   TIM_SR(base) &= ~M1(SR_UIF)

#define TIM_RD_CNTR(base)                                TIM_CNT(base)
#define TIM_WR_CNTR(base, value)                         TIM_CNT(base) = (value)

// freq_psc = freq_src / (value + 1)
#define TIM_CLK_DIV(base, value)                         TIM_PSC(base) = (value)

#define TIM_RD_TARGET(base)                              TIM_ARR(base)
#define TIM_WR_TARGET(base, value)                       TIM_ARR(base) = (value)

/* control register 1 */
#define TIM_ALIGNED_EDGE                                             UINT32_C(0)
#define TIM_ALIGNED_CENTER_DOWN                                      UINT32_C(1)
#define TIM_ALIGNED_CENTER_UP                                        UINT32_C(2)
#define TIM_ALIGNED_CENTER_BOTH                                      UINT32_C(3)

#define TIM_DIR_UP                                                   UINT32_C(0)
#define TIM_DIR_DOWN                                                 UINT32_C(1)
typedef union
{
    struct {
        uint16_t CEN : 1; // counter enable
        uint16_t UDIS : 1; // update event (UEV) disabled
        uint16_t URS : 1; // update request source
        uint16_t OPM : 1; // open pulse mode
        uint16_t DIR : 1; // 0: up, 1: down
        uint16_t CMS : 2; // center-aligned mode selection
        uint16_t ARPE : 1; // auto-reload preload enable
        uint16_t CKD : 2; // clock division
        uint16_t : 6;
    } bits;
    uint16_t u16;
    uint32_t u32;
} TIM_CR1_t;

/* control register 2 */
typedef union
{
    struct {
        uint16_t CCPC : 1; // capture/compare preload control
        uint16_t : 1; // reserved
        uint16_t CCUS : 1; // capture/compare control update selection
        uint16_t CCDS : 1; // capture/compare DMA selection
        uint16_t MMS : 2; // master mode selection
        uint16_t TI1S : 1; // TI1 selection
        uint16_t OIS1 : 1; // output idle state 1 (OC1 output)
        uint16_t OIS1N : 1; // output idle state 1 (OC1N output)
        uint16_t OIS2 : 1; // output idle state 2 (OC2 output)
        uint16_t OIS2N : 1; // output idle state 2 (OC2N output)
        uint16_t OIS3 : 1; // output idle state 3 (OC3 output)
        uint16_t OIS3N : 1; // output idle state 3 (OC3N output)
        uint16_t OIS4 : 1; // output idle state 4 (OC4 output)
        uint16_t OIS4N : 1; // output idle state 4 (OC4N output)
        uint16_t : 1;
    } bits;
    uint16_t u16;
    uint32_t u32;
} TIM_CR2_t;

/* slave mode control register */
typedef union
{
    struct {
        uint16_t SMS : 3; // slave mode selection
        uint16_t : 1; // reserved
        uint16_t TS : 3; // trigger selection
        uint16_t MSM : 1; // master/slave mode
        uint16_t ETF : 4; // external trigger filter
        uint16_t ETPS : 2; // external trigger prescaler
        uint16_t ECE : 1; // external clock enable
        uint16_t ETP : 1; // external trigger polarity
    } bits;
    uint32_t u16;
    uint32_t u32;
} TIM_SMCR_t;

/* DMA/interrupt enable register */
typedef union
{
    struct {
        uint16_t UIE : 1; // update interrupt enable
        uint16_t CC1IE : 1; // capture/compare 1 interrupt enable
        uint16_t CC2IE : 1; // capture/compare 2 interrupt enable
        uint16_t CC3IE : 1; // capture/compare 3 interrupt enable
        uint16_t CC4IE : 1; // capture/compare 4 interrupt enable
        uint16_t COMIE : 1; // COM interrupt enable
        uint16_t TIE : 1; // trigger interrupt enable
        uint16_t BIE : 1; // break interrupt enable
        uint16_t UDE : 1; // update DMA request enable
        uint16_t CC1DE : 1; // capture/compare 1 DMA request enable
        uint16_t CC2DE : 1; // capture/compare 2 DMA request enable
        uint16_t CC3DE : 1; // capture/compare 3 DMA request enable
        uint16_t CC4DE : 1; // capture/compare 4 DMA request enable
        uint16_t COMDE : 1; // COM DMA request enable
        uint16_t TDE : 1; // trigger DMA request enable
        uint16_t : 1;
    } bits;
    uint16_t u16;
    uint32_t u32;
} TIM_DIER_t;

/* status register */
typedef union
{
    struct {
        uint16_t UIF : 1; // update interrupt flag
        uint16_t CC1F : 1; // capture/compare 1 interrupt flag
        uint16_t CC2F : 1; // capture/compare 2 interrupt flag
        uint16_t CC3F : 1; // capture/compare 3 interrupt flag
        uint16_t CC4F : 1; // capture/compare 4 interrupt flag
        uint16_t COMIF : 1; // COM interrupt flag
        uint16_t TIF : 1; // trigger interrupt flag
        uint16_t BIF : 1; // break interrupt flag
        uint16_t : 1; // reserved
        uint16_t CC1OF : 1; // capture/compare 1 overcapture flag
        uint16_t CC2OF : 1; // capture/compare 2 overcapture flag
        uint16_t CC3OF : 1; // capture/compare 3 overcapture flag
        uint16_t CC4OF : 1; // capture/compare 4 overcapture flag
        uint16_t : 3;
    } bits;
    uint16_t u16;
    uint32_t u32;
} TIM_SR_t;

/* event generation register */
typedef union
{
    struct {
        uint16_t UG : 1; // update generation
        uint16_t CC1G : 1; // capture/compare 1 generation
        uint16_t CC2G : 1; // capture/compare 2 generation
        uint16_t CC3G : 1; // capture/compare 3 generation
        uint16_t CC4G : 1; // capture/compare 4 generation
        uint16_t COMG : 1; // capture/compare control update generation
        uint16_t TG : 1; // trigger generation
        uint16_t BG : 1; // break generation
        uint16_t : 8;
    } bits;
    uint16_t u16;
    uint32_t u32;
} TIM_EGR_t;

/* capture/compare mode register 1 */
typedef union
{
    struct {
        struct {
            uint16_t CC1S : 2; // capture/compare 1 selection
            uint16_t OC1FE : 1; // output compare 1 fast enable
            uint16_t OC1PE : 1; // output compare 1 preload enable
            uint16_t OC1M : 3; // output compare 1 mode
            uint16_t OC1CE : 1; // output compare 1 clear enable
            uint16_t CC2S : 2; // capture/compare 2 selection
            uint16_t OC2FE : 1; // output compare 2 fast enable
            uint16_t OC2PE : 1; // output compare 2 preload enable
            uint16_t OC2M : 3; // output compare 2 mode
            uint16_t OC2CE : 1; // output compare 2 clear enable
        } bits;
    } OC; // output compare mode
    struct {
        struct {
            uint16_t CC1S : 2; // capture/compare 1 selection
            uint16_t IC1PCS : 2; // input capture 1 prescaler
            uint16_t IC1F : 4; // input capture 1 filter
            uint16_t CC2S : 2; // capture/compare 2 selection
            uint16_t IC2PSC : 2; // input capture 2 prescaler
            uint16_t IC2F : 4; // input capture 2 filter
        } bits;
    } IC; // input capture mode
    uint16_t u16;
    uint32_t u32;
} TIM_CCMR1_t;

/* capture/compare mode register 2 */
typedef union
{
    struct {
        struct {
            uint16_t CC3S : 2; // capture/compare 3 selection
            uint16_t OC3FE : 1; // output compare 3 fast enable
            uint16_t OC3PE : 1; // output compare 3 preload enable
            uint16_t OC3M : 3; // output compare 3 mode
            uint16_t OC3CE : 1; // output compare 3 clear enable
            uint16_t CC4S : 2; // capture/compare 4 selection
            uint16_t OC4FE : 1; // output compare 4 fast enable
            uint16_t OC4PE : 1; // output compare 4 preload enable
            uint16_t OC4M : 3; // output compare 4 mode
            uint16_t OC4CE : 1; // output compare 4 clear enable
        } bits;
    } OC; // output compare mode
    struct {
        struct {
            uint16_t CC3S : 2; // capture/compare 3 selection
            uint16_t IC3PCS : 2; // input capture 3 prescaler
            uint16_t IC3F : 4; // input capture 3 filter
            uint16_t CC4S : 2; // capture/compare 4 selection
            uint16_t IC4PSC : 2; // input capture 4 prescaler
            uint16_t IC4F : 4; // input capture 4 filter
        } bits;
    } IC; // input capture mode
    uint16_t u16;
    uint32_t u32;
} TIM_CCMR2_t;

/* capture compare enable register */
typedef union
{
    struct {
        uint16_t CC1E : 1; // capture/compare 1 output enable
        uint16_t CC1P : 1; // capture/compare 1 output polarity
        uint16_t CC1NE : 1; // capture/compare 1 complementary output enable
        uint16_t CC1NP : 1; // capture/compare 1 complementary output polarity
        uint16_t CC2E : 1; // capture/compare 2 output enable
        uint16_t CC2P : 1; // capture/compare 2 output polarity
        uint16_t CC2NE : 1; // capture/compare 2 complementary output enable
        uint16_t CC2NP : 1; // capture/compare 2 complementary output polarity
        uint16_t CC3E : 1; // capture/compare 3 output enable
        uint16_t CC3P : 1; // capture/compare 3 output polarity
        uint16_t CC3NE : 1; // capture/compare 3 complementary output enable
        uint16_t CC3NP : 1; // capture/compare 3 complementary output polarity
        uint16_t CC4E : 1; // capture/compare 4 output enable
        uint16_t CC4P : 1; // capture/compare 4 output polarity
        uint16_t CC4NE : 1; // capture/compare 4 complementary output enable
        uint16_t CC4NP : 1; // capture/compare 4 complementary output polarity
    } bits;
    uint16_t u16;
    uint32_t u32;
} TIM_CCER_t;
