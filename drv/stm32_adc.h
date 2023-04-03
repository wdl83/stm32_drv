#pragma once

#include "mem.h"
#include "stm32.h"

/*----------------------------------------------------------------------------*/
#define ADC_SR(base)                                             R32(base, 0x00)
#define SR_AWD                                                       UINT8_C( 0)
#define SR_EOC                                                       UINT8_C( 1)
#define SR_JEOS                                                      UINT8_C( 2)
#define SR_JSTRT                                                     UINT8_C( 3)
#define SR_STRT                                                      UINT8_C( 4)
/*----------------------------------------------------------------------------*/
#define ADC_CR1(base)                                            R32(base, 0x04)
#define CR1_AWDCH                                                    UINT8_C( 0)
#define CR1_EOSIE                                                    UINT8_C( 5)
#define CR1_AWDIE                                                    UINT8_C( 6)
#define CR1_JEOSIE                                                   UINT8_C( 7)
#define CR1_SCAN                                                     UINT8_C( 8)
#define CR1_AWDSGL                                                   UINT8_C( 9)
#define CR1_JAUTO                                                    UINT8_C(10)
#define CR1_DISCEN                                                   UINT8_C(11)
#define CR1_JDISCEN                                                  UINT8_C(12)
#define CR1_DISCNUM                                                  UINT8_C(13)
#define CR1_DUALMOD                                                  UINT8_C(16)
#define CR1_JAWDEN                                                   UINT8_C(22)
#define CR1_AWDEN                                                    UINT8_C(23)
/*----------------------------------------------------------------------------*/
#define ADC_CR2(base)                                            R32(base, 0x08)
#define CR2_ADON                                                     UINT8_C( 0)
#define CR2_CONT                                                     UINT8_C( 1)
#define CR2_CAL                                                      UINT8_C( 2)
#define CR2_RSTCAL                                                   UINT8_C( 3)
#define CR2_DMA                                                      UINT8_C( 8)
#define CR2_ALIGN                                                    UINT8_C(11)
#define CR2_JEXTSEL                                                  UINT8_C(12)
#define CR2_JEXTTRIG                                                 UINT8_C(15)
#define CR2_EXTSEL                                                   UINT8_C(17)
#define CR2_EXTTRIG                                                  UINT8_C(20)
#define CR2_JSWSTART                                                 UINT8_C(21)
#define CR2_SWSTART                                                  UINT8_C(22)
#define CR2_TSVREFE                                                  UINT8_C(23)
/*----------------------------------------------------------------------------*/
#define ADC_SMPR1(base)                                          R32(base, 0x0C)
#define SMPR1_SMP10                                                  UINT8_C( 0)
#define SMPR1_SMP11                                                  UINT8_C( 3)
#define SMPR1_SMP12                                                  UINT8_C( 6)
#define SMPR1_SMP13                                                  UINT8_C( 9)
#define SMPR1_SMP14                                                  UINT8_C(12)
#define SMPR1_SMP15                                                  UINT8_C(15)
#define SMPR1_SMP16                                                  UINT8_C(18)
#define SMPR1_SMP17                                                  UINT8_C(21)
/*----------------------------------------------------------------------------*/
#define ADC_SMPR2(base)                                          R32(base, 0x10)
#define SMPR2_SMP0                                                   UINT8_C( 0)
#define SMPR2_SMP1                                                   UINT8_C( 3)
#define SMPR2_SMP2                                                   UINT8_C( 6)
#define SMPR2_SMP3                                                   UINT8_C( 9)
#define SMPR2_SMP4                                                   UINT8_C(12)
#define SMPR2_SMP5                                                   UINT8_C(15)
#define SMPR2_SMP6                                                   UINT8_C(18)
#define SMPR2_SMP7                                                   UINT8_C(21)
#define SMPR2_SMP8                                                   UINT8_C(24)
#define SMPR2_SMP9                                                   UINT8_C(27)
/*----------------------------------------------------------------------------*/
#define ADC_JOFR1(base)                                          R32(base, 0x14)
#define JOFR1_JOFFSET1                                               UINT8_C( 0)
/*----------------------------------------------------------------------------*/
#define ADC_JOFR2(base)                                          R32(base, 0x18)
#define JOFR2_JOFFSET2                                               UINT8_C( 0)
/*----------------------------------------------------------------------------*/
#define ADC_JOFR3(base)                                          R32(base, 0x1C)
#define JOFR3_JOFFSET3                                               UINT8_C( 0)
/*----------------------------------------------------------------------------*/
#define ADC_JOFR4(base)                                          R32(base, 0x20)
#define JOFR4_JOFFSET4                                               UINT8_C( 0)
/*----------------------------------------------------------------------------*/
#define ADC_HTR(base)                                            R32(base, 0x24)
#define HTR_HT                                                       UINT8_C( 0)
/*----------------------------------------------------------------------------*/
#define ADC_LTR(base)                                            R32(base, 0x28)
#define LTR_LT                                                       UINT8_C( 0)
/*----------------------------------------------------------------------------*/
#define ADC_SQR1(base)                                           R32(base, 0x2C)
#define SQR1_SQ13                                                    UINT8_C( 0)
#define SQR1_SQ14                                                    UINT8_C( 5)
#define SQR1_SQ15                                                    UINT8_C(10)
#define SQR1_SQ16                                                    UINT8_C(15)
#define SQR1_L                                                       UINT8_C(20)
/*----------------------------------------------------------------------------*/
#define ADC_SQR2(base)                                           R32(base, 0x30)
#define SQR2_SQ7                                                     UINT8_C( 0)
#define SQR2_SQ8                                                     UINT8_C( 5)
#define SQR2_SQ9                                                     UINT8_C(10)
#define SQR2_SQ10                                                    UINT8_C(15)
#define SQR2_SQ11                                                    UINT8_C(20)
#define SQR2_SQ12                                                    UINT8_C(25)
/*----------------------------------------------------------------------------*/
#define ADC_SQR3(base)                                           R32(base, 0x34)
#define SQR3_SQ1                                                     UINT8_C( 0)
#define SQR3_SQ2                                                     UINT8_C( 5)
#define SQR3_SQ3                                                     UINT8_C(10)
#define SQR3_SQ4                                                     UINT8_C(15)
#define SQR3_SQ5                                                     UINT8_C(20)
#define SQR3_SQ6                                                     UINT8_C(25)
/*----------------------------------------------------------------------------*/
#define ADC_JSQR(base)                                           R32(base, 0x38)
#define JSQR_JSQ1                                                    UINT8_C( 0)
#define JSQR_JSQ2                                                    UINT8_C( 5)
#define JSQR_JSQ3                                                    UINT8_C(10)
#define JSQR_JSQ4                                                    UINT8_C(15)
#define JSQR_JL                                                      UINT8_C(20)
/*----------------------------------------------------------------------------*/
#define ADC_JDR1(base)                                           R32(base, 0x3C)
#define JDR1_JDATA                                                   UINT8_C( 0)
/*----------------------------------------------------------------------------*/
#define ADC_JDR2(base)                                           R32(base, 0x40)
#define JDR2_JDATA                                                   UINT8_C( 0)
/*----------------------------------------------------------------------------*/
#define ADC_JDR3(base)                                           R32(base, 0x44)
#define JDR3_JDATA                                                   UINT8_C( 0)
/*----------------------------------------------------------------------------*/
#define ADC_JDR4(base)                                           R32(base, 0x48)
#define JDR4_JDATA                                                   UINT8_C( 0)
/*----------------------------------------------------------------------------*/
#define ADC_DR(base)                                             R32(base, 0x4C)
#define DR_DATA                                                      UINT8_C( 0)
#define DR_ADC2DATA                                                  UINT8_C(16)
/*----------------------------------------------------------------------------*/
#define ADC_SCAN_ENABLE(base)                    ADC_CR1(base) |= M1(CR1_SCAN)
#define ADC_SCAN_DISABLE(base)                   ADC_CR1(base) &= ~M1(CR1_SCAN)

#define ADC_ENABLE(base)                         ADC_CR2(base) |= M1(CR2_ADON)
#define ADC_DISABLE(base)                        ADC_CR2(base) &= ~M1(CR2_ADON)
#define ADC_TRIGGER(base)                        ADC_CR2(base) |= M1(CR2_ADON)
#define ADC_SINGLE(base)                         ADC_CR2(base) &= ~M1(CR2_CONT)
#define ADC_CONTINUOUS(base)                     ADC_CR2(base) |= M1(CR2_CONT)
#define ADC_CALIBRATION(base)                    ADC_CR2(base) |= M1(CR2_CAL)
#define ADC_CALIBRATION_DONE(base)            (!(ADC_CR2(base) & M1(CR2_CAL)))
#define ADC_CALIBRATION_RESET(base)              ADC_CR2(base) |= M1(CR2_RSTCAL)
#define ADC_DMA_ENABLE(base)                     ADC_CR2(base) |= M1(CR2_DMA)
#define ADC_DMA_DISABLE(base)                    ADC_CR2(base) &= ~M1(CR2_DMA)
#define ADC_IN16_IN17_ENABLE(base)               ADC_CR2(base) |= M1(CR2_TSVREFE)

#define ADC_COMPLETE(base)                      (ADC_SR(base) & M1(SR_EOC))


/* Tconv: total conversion time, Tconv = sampling_time + 12.5 cycles (HW const)
 * Tconv = 1.5 + 12.5 = 14 cycles
 * ADC_CLK == 14MHz: 14 x 71.43ns ~= 1us */
#define ADC_SAMPLE_TIME_1t5                                          UINT32_C(0)
#define ADC_SAMPLE_TIME_7t5                                          UINT32_C(1)
#define ADC_SAMPLE_TIME_13t5                                         UINT32_C(2)
#define ADC_SAMPLE_TIME_28t5                                         UINT32_C(3)
#define ADC_SAMPLE_TIME_41t5                                         UINT32_C(4)
#define ADC_SAMPLE_TIME_55t5                                         UINT32_C(5)
#define ADC_SAMPLE_TIME_71t5                                         UINT32_C(6)
#define ADC_SAMPLE_TIME_239t5                                        UINT32_C(7)

#define ADC_CH0_SAMPLE_TIME(base, t)      SET3R(ADC_SMPR2(base), SMPR2_SMP0, t)
#define ADC_CH1_SAMPLE_TIME(base, t)      SET3R(ADC_SMPR2(base), SMPR2_SMP1, t)
#define ADC_CH2_SAMPLE_TIME(base, t)      SET3R(ADC_SMPR2(base), SMPR2_SMP2, t)
#define ADC_CH3_SAMPLE_TIME(base, t)      SET3R(ADC_SMPR2(base), SMPR2_SMP3, t)
#define ADC_CH4_SAMPLE_TIME(base, t)      SET3R(ADC_SMPR2(base), SMPR2_SMP4, t)
#define ADC_CH5_SAMPLE_TIME(base, t)      SET3R(ADC_SMPR2(base), SMPR2_SMP5, t)
#define ADC_CH6_SAMPLE_TIME(base, t)      SET3R(ADC_SMPR2(base), SMPR2_SMP6, t)
#define ADC_CH7_SAMPLE_TIME(base, t)      SET3R(ADC_SMPR2(base), SMPR2_SMP7, t)
#define ADC_CH8_SAMPLE_TIME(base, t)      SET3R(ADC_SMPR2(base), SMPR2_SMP8, t)
#define ADC_CH9_SAMPLE_TIME(base, t)      SET3R(ADC_SMPR2(base), SMPR2_SMP9, t)
#define ADC_CH10_SAMPLE_TIME(base, t)     SET3R(ADC_SMPR1(base), SMPR1_SMP10, t)
#define ADC_CH11_SAMPLE_TIME(base, t)     SET3R(ADC_SMPR1(base), SMPR1_SMP11, t)
#define ADC_CH12_SAMPLE_TIME(base, t)     SET3R(ADC_SMPR1(base), SMPR1_SMP12, t)
#define ADC_CH13_SAMPLE_TIME(base, t)     SET3R(ADC_SMPR1(base), SMPR1_SMP13, t)
#define ADC_CH14_SAMPLE_TIME(base, t)     SET3R(ADC_SMPR1(base), SMPR1_SMP14, t)
#define ADC_CH15_SAMPLE_TIME(base, t)     SET3R(ADC_SMPR1(base), SMPR1_SMP15, t)
/* ADC1 CH16 is connected to temp. sensor internally
 * ADC2 CH16 is connected to Vss internally */
#define ADC_CH16_SAMPLE_TIME(base, t)     SET3R(ADC_SMPR1(base), SMPR1_SMP16, t)
/* ADC1 CH17 is connected to Vrefint internally
 * ADC2 CH17 is connected to Vss internally */
#define ADC_CH17_SAMPLE_TIME(base, t)     SET3R(ADC_SMPR1(base), SMPR1_SMP17, t)

#define ADC_SEQ_NUM(base, n)                 SET4R(ADC_SQR1(base), SQR1_L, n)
#define ADC_SEQ1(base, n)                    SET5R(ADC_SQR3(base), SQR3_SQ1, n)
#define ADC_SEQ2(base, n)                    SET5R(ADC_SQR3(base), SQR3_SQ2, n)
#define ADC_SEQ3(base, n)                    SET5R(ADC_SQR3(base), SQR3_SQ3, n)
#define ADC_SEQ4(base, n)                    SET5R(ADC_SQR3(base), SQR3_SQ4, n)
#define ADC_SEQ5(base, n)                    SET5R(ADC_SQR3(base), SQR3_SQ5, n)
#define ADC_SEQ6(base, n)                    SET5R(ADC_SQR3(base), SQR3_SQ6, n)
#define ADC_SEQ7(base, n)                    SET5R(ADC_SQR2(base), SQR2_SQ7, n)
#define ADC_SEQ8(base, n)                    SET5R(ADC_SQR2(base), SQR2_SQ8, n)
#define ADC_SEQ9(base, n)                    SET5R(ADC_SQR2(base), SQR2_SQ9, n)
#define ADC_SEQ10(base, n)                   SET5R(ADC_SQR2(base), SQR2_SQ10, n)
#define ADC_SEQ11(base, n)                   SET5R(ADC_SQR2(base), SQR2_SQ11, n)
#define ADC_SEQ12(base, n)                   SET5R(ADC_SQR2(base), SQR2_SQ12, n)
#define ADC_SEQ13(base, n)                   SET5R(ADC_SQR1(base), SQR1_SQ13, n)
#define ADC_SEQ14(base, n)                   SET5R(ADC_SQR1(base), SQR1_SQ14, n)
#define ADC_SEQ15(base, n)                   SET5R(ADC_SQR1(base), SQR1_SQ15, n)
#define ADC_SEQ16(base, n)                   SET5R(ADC_SQR1(base), SQR1_SQ16, n)

#define ADC_JSEQ_NUM(base, n)                SET2R(ADC_JSQR(base), JSQR_JL, n)
#define ADC_JSEQ1(base, n)                   SET2R(ADC_JSQR(base), JSQR_JSQ1, n)
#define ADC_JSEQ2(base, n)                   SET2R(ADC_JSQR(base), JSQR_JSQ2, n)
#define ADC_JSEQ3(base, n)                   SET2R(ADC_JSQR(base), JSQR_JSQ3, n)
#define ADC_JSEQ4(base, n)                   SET2R(ADC_JSQR(base), JSQR_JSQ4, n)
/*----------------------------------------------------------------------------*/
