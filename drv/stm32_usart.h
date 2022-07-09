#pragma once

#include "mem.h"
#include "stm32.h"

/*----------------------------------------------------------------------------*/
#define USART_SR(base)                                           R32(base, 0x00)
#define SR_PE                                                        UINT8_C( 0)
#define SR_FE                                                        UINT8_C( 1)
#define SR_NE                                                        UINT8_C( 2)
#define SR_ORE                                                       UINT8_C( 3)
#define SR_IDLE                                                      UINT8_C( 4)
#define SR_RXNE                                                      UINT8_C( 5)
#define SR_TC                                                        UINT8_C( 6)
#define SR_TXE                                                       UINT8_C( 7)
#define SR_LBD                                                       UINT8_C( 8)
#define SR_CTS                                                       UINT8_C( 9)
/*----------------------------------------------------------------------------*/
#define USART_DR(base)                                           R32(base, 0x04)
/*----------------------------------------------------------------------------*/
#define USART_BRR(base)                                          R32(base, 0x08)
/*----------------------------------------------------------------------------*/
#define USART_CR1(base)                                          R32(base, 0x0C)
#define CR1_SBK                                                      UINT8_C( 0)
#define CR1_RWU                                                      UINT8_C( 1)
#define CR1_RE                                                       UINT8_C( 2)
#define CR1_TE                                                       UINT8_C( 3)
#define CR1_IDLEIE                                                   UINT8_C( 4)
#define CR1_RXNEIE                                                   UINT8_C( 5)
#define CR1_TCIE                                                     UINT8_C( 6)
#define CR1_TXEIE                                                    UINT8_C( 7)
#define CR1_PEIE                                                     UINT8_C( 8)
#define CR1_PS                                                       UINT8_C( 9)
#define CR1_PCE                                                      UINT8_C(10)
#define CR1_WAKE                                                     UINT8_C(11)
#define CR1_M                                                        UINT8_C(12)
#define CR1_UE                                                       UINT8_C(13)
/*----------------------------------------------------------------------------*/
#define USART_CR2(base)                                          R32(base, 0x10)
#define CR2_ADD                                                      UINT8_C( 0)
#define CR2_LBDL                                                     UINT8_C( 5)
#define CR2_LBDIE                                                    UINT8_C( 6)
#define CR2_LBCL                                                     UINT8_C( 8)
#define CR2_CPHA                                                     UINT8_C( 9)
#define CR2_CPOL                                                     UINT8_C(10)
#define CR2_CLKEN                                                    UINT8_C(11)
#define CR2_STOP0                                                    UINT8_C(12)
#define CR2_STOP1                                                    UINT8_C(13)
#define CR2_LINEN                                                    UINT8_C(14)
/*----------------------------------------------------------------------------*/
#define USART_CR3(base)                                          R32(base, 0x14)
#define CR3_EIE                                                      UINT8_C( 0)
#define CR3_IREN                                                     UINT8_C( 1)
#define CR3_IRLP                                                     UINT8_C( 2)
#define CR3_HDSEL                                                    UINT8_C( 3)
#define CR3_NACK                                                     UINT8_C( 4)
#define CR3_SCEN                                                     UINT8_C( 5)
#define CR3_DMAR                                                     UINT8_C( 6)
#define CR3_DMAT                                                     UINT8_C( 7)
#define CR3_RTSE                                                     UINT8_C( 8)
#define CR3_CTSE                                                     UINT8_C( 9)
#define CR3_CTSIE                                                    UINT8_C(10)
/*----------------------------------------------------------------------------*/
#define USART_GTPR(base)                                         R32(base, 0x18)
#define GTPR_PSC                                                     UINT8_C( 0)
#define GTPR_GT                                                      UINT8_C( 8)
/*----------------------------------------------------------------------------*/
#define USART_ENABLE(base)                        USART_CR1(base) |= M1(CR1_UE)
#define USART_DISABLE(base)                       USART_CR1(base) &= ~M1(CR1_UE)
#define USART_ENABLED(base)                      (USART_CR1(base) & M1(CR1_UE))

#define USART_TX_ENABLE(base)                     USART_CR1(base) |= M1(CR1_TE)
#define USART_TX_DISABLE(base)                    USART_CR1(base) &= ~M1(CR1_TE)
#define USART_TX_ENABLED(base)                   (USART_CR1(base) & M1(CR1_TE))

#define USART_RX_ENABLE(base)                     USART_CR1(base) |= M1(CR1_RE)
#define USART_RX_DISABLE(base)                    USART_CR1(base) &= ~M1(CR1_RE)
#define USART_RX_ENABLED(base)                   (USART_CR1(base) & M1(CR1_RE))

/* USARTDIV = clk / (16 * bps) */
#define CALC_BR(clk, bps) ((clk) / (bps))

#define USART_BR(base, br)       USART_BRR(base) = ((br))

#define USART_TX_READY(base)                       (USART_SR(base) & M1(SR_TXE))
#define USART_TX_COMPLETE(base)                    (USART_SR(base) & M1(SR_TC))

#define USART_RX_READY(base)                      (USART_SR(base) & M1(SR_RXNE))

#define USART_IDLE(base)                          (USART_SR(base) & M1(SR_IDLE))

#define USART_TX(base, data)                             USART_DR(base) = (data)
#define USART_RX(base, data)                    (data) = USART_DR(base)
#define USART_RD(base)                                   USART_DR(base)

#define USART_TX_READY_INT_ENABLE(base)        USART_CR1(base) |= M1(CR1_TXEIE)
#define USART_TX_READY_INT_DISABLE(base)       USART_CR1(base) &= ~M1(CR1_TXEIE)

#define USART_TX_COMPLETE_INT_ENABLE(base)      USART_CR2(base) |= M1(CR2_TCIE)
#define USART_TX_COMPLETE_INT_DISABLE(base)     USART_CR2(base) &= ~M1(CR2_TCIE)
#define USART_TX_COMPLETE_INT_ENABLED(base)    (USART_CR2(base) & M1(CR2_TCIE))

#define USART_RX_INT_ENABLE(base)             USART_CR2(base) |= M1(CR1_RXNEIE)
#define USART_RX_INT_DISABLE(base)            USART_CR2(base) &= ~M1(CR1_RXNEIE)

#define USART_PARITY_ENABLE(base)                USART_CR1(base) |= M1(CR1_MSE)
#define USART_PARITY_DISABLE(base)               USART_CR1(base) &= ~M1(CR1_MSE)

#define USART_PARITY_EVEN(base)                   USART_CR1(base) &= ~M1(CR1_PS)
#define USART_PARITY_ODD(base)                    USART_CR1(base) |= M1(CR1_PS)

#define USART_FRAME_ERR(base)                      (USART_SR(base) & M1(SR_FE))
#define USART_OVERRUN_ERR(base)                    (USART_SR(base) & M1(SR_ORE))
#define USART_PARITY_ERR(base)                     (USART_SR(base) & M1(SR_PE))
#define USART_NOISE_FLAG(base)                     (USART_SR(base) & M1(SR_NF))

#define USART_FOPN_ERR(base)  (USART_SR(base) & M4(SR_ORE, SR_NF, SR_FE, SR_PE))
