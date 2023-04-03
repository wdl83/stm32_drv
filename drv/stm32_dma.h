#pragma once

#include "mem.h"
#include "stm32.h"

/* DMA1 channels [1, 2, 3, 4, 5, 6, 7] */

/* Peripherals request to Channel mapping:
 *
 * Channel 1: ADC1, TIM2_CH3, TIM4_CH1
 * Channel 2: SPI1_RX, USART3_TX, TIM1_CH1, TIM2_UP, TIM3_CH3
 * Channel 3: SPI1_TX, USART3_RX, TIM1_CH2, TIM3_CH4/UP
 * Channel 4: SPI2, I2S2_RX, USART1_TX, I2C2_TX, TIM1_CH4/TRIG/COM, TIM4_CH2
 * Channel 5: SPI2, I2S2_TX, USART1_RX, I2C2_RX, TIM1_UP, TIM2_CH1, TIM4_CH3
 * Channel 6: USART2_RX, I2C1_TX, TIM1_CH3, TIM3_CH1/TRIG
 * Channel 7: USART2_TX, I2C1_RX, TIM2_CH2/CH4, TIM4_UP */
/*----------------------------------------------------------------------------*/
/* interrupt status register */
#define DMA_ISR(base)                                            R32(base, 0x00)
#define ISR_GIF(ch)                                  ((ch - 1) * 4 + UINT8_C(0))
#define ISR_TCIF(ch)                                 ((ch - 1) * 4 + UINT8_C(1))
#define ISR_HTIF(ch)                                 ((ch - 1) * 4 + UINT8_C(2))
#define ISR_TEIF(ch)                                 ((ch - 1) * 4 + UINT8_C(3))
/*----------------------------------------------------------------------------*/
/* interrupt flag clear register */
#define DMA_IFCR(base)                                           R32(base, 0x00)
#define IFCR_CGIF(ch)                                ((ch - 1) * 4 + UINT8_C(0))
#define IFCR_CTCIF(ch)                               ((ch - 1) * 4 + UINT8_C(1))
#define IFCR_CHTIF(ch)                               ((ch - 1) * 4 + UINT8_C(2))
#define IFCR_CTEIF(ch)                               ((ch - 1) * 4 + UINT8_C(3))
/*----------------------------------------------------------------------------*/
/* channel configuration register */
#define DMA_CCR(base, ch)                      R32(base, 0x14 * (ch - 1) + 0x08)
#define CCR_EN                                                       UINT8_C( 0)
#define CCR_TCIE                                                     UINT8_C( 1)
#define CCR_HTIE                                                     UINT8_C( 2)
#define CCR_TEIE                                                     UINT8_C( 3)
#define CCR_DIR                                                      UINT8_C( 4)
#define CCR_CIRC                                                     UINT8_C( 5)
#define CCR_PINC                                                     UINT8_C( 6)
#define CCR_MINC                                                     UINT8_C( 7)
#define CCR_PSIZE                                                    UINT8_C( 8)
#define CCR_MSIZE                                                    UINT8_C(10)
#define CCR_PL                                                       UINT8_C(12)
#define CCR_MEM2MEM                                                  UINT8_C(14)

typedef union
{
    struct {
        uint32_t EN : 1;
        uint32_t TCIE : 1;
        uint32_t HTIE : 1;
        uint32_t TEIE : 1;
        uint32_t DIR : 1;
        uint32_t CIRC : 1;
        uint32_t PINC : 1;
        uint32_t MINC : 1;
        uint32_t PSIZE : 2;
        uint32_t MSIZE : 2;
        uint32_t PL : 2;
        uint32_t MEM2MEM : 1;
    };
    uint32_t raw;
} DMA_CCR_t;
/*----------------------------------------------------------------------------*/
/* number of data to transfer [0:65535] lower 16bits */
#define DMA_CNDTR(base, ch)                    R32(base, 0x14 * (ch - 1) + 0x0C)
/*----------------------------------------------------------------------------*/
/* peripheral address register */
#define DMA_CPAR(base, ch)                     R32(base, 0x14 * (ch - 1) + 0x10)
/*----------------------------------------------------------------------------*/
/* memory address register */
#define DMA_CMAR(base, ch)                     R32(base, 0x14 * (ch - 1) + 0x14)
/*----------------------------------------------------------------------------*/
#define DMA_PRIORITY_LOW                                             UINT32_C(0)
#define DMA_PRIORITY_MEDIUM                                          UINT32_C(0)
#define DMA_PRIORITY_HIGH                                            UINT32_C(0)
#define DMA_PRIORITY_VERY_HIGH                                       UINT32_C(0)
#define DMA_WIDTH8                                                   UINT32_C(0)
#define DMA_WIDTH16                                                  UINT32_C(1)
#define DMA_WIDTH32                                                  UINT32_C(2)

/* can only be set when channel is disabled */
#define DMA_TRANSFER_NUM(base, ch, n)                  DMA_CNDTR(base, ch) = (n)
#define DMA_PADDR(base, ch, addr)                    DMA_CPAR(base, ch) = (addr)
#define DMA_MADDR(base, ch, addr)                    DMA_CMAR(base, ch) = (addr)

#define DMA_ENABLE(base, ch)                  DMA_CCR(base, ch) |= M1(CCR_EN)
#define DMA_DISABLE(base, ch)                 DMA_CCR(base, ch) &= ~M1(CCR_EN)

#define DMA_COMPLETE_INT_ENABLE(base, ch)     DMA_CCR(base, ch) |= M1(CCR_TCIE)
#define DMA_COMPLETE_INT_DISABLE(base, ch)    DMA_CCR(base, ch) &= ~M1(CCR_TCIE)
#define DMA_COMPLETE_INT_ENABLED(base, ch)   (DMA_CCR(base, ch) & M1(CCR_TCIE))

#define DMA_ERROR_INT_ENABLE(base, ch)        DMA_CCR(base, ch) |= M1(CCR_TEIE)
#define DMA_ERROR_INT_DISABLE(base, ch)       DMA_CCR(base, ch) &= ~M1(CCR_TEIE)
#define DMA_ERROR_INT_ENABLED(base, ch)      (DMA_CCR(base, ch) & M1(CCR_TEIE))

#define DMA_FROM_MEMORY(base, ch)             DMA_CCR(base, ch) |= M1(CCR_DIR)
#define DMA_FROM_PERIPHERAL(base, ch)         DMA_CCR(base, ch) &= ~M1(CCR_DIR)

#define DMA_CIRCULAR_ENABLE(base, ch)         DMA_CCR(base, ch) |= M1(CCR_CIRC)
#define DMA_CIRCULAR_DISABLE(base, ch)        DMA_CCR(base, ch) &= ~M1(CCR_CIRC)

#define DMA_PADDR_INC_ENABLE(base, ch)        DMA_CCR(base, ch) |= M1(CCR_PINC)
#define DMA_PADDR_INC_DISABLE(base, ch)       DMA_CCR(base, ch) &= ~M1(CCR_PINC)

#define DMA_MADDR_INC_ENABLE(base, ch)        DMA_CCR(base, ch) |= M1(CCR_MINC)
#define DMA_MADDR_INC_DISABLE(base, ch)       DMA_CCR(base, ch) &= ~M1(CCR_MINC)

#define DMA_PSIZE(base, ch, size)      SET2R(DMA_CCR(base, ch), CCR_PSIZE, size)
#define DMA_MSIZE(base, ch, size)      SET2R(DMA_CCR(base, ch), CCR_MSIZE, size)

#define DMA_PRIORITY(base, ch, p)            SET2R(DMA_CCR(base, ch), CCR_PL, p)

#define DMA_MEM2MEM_ENABLE(base, ch)       DMA_CCR(base, ch) |= M1(CCR_MEM2MEM)
#define DMA_MEM2MEM_DISABLE(base, ch)      DMA_CCR(base, ch) &= ~M1(CCR_MEM2MEM)
