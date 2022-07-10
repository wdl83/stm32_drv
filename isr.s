.syntax unified

/* User overridable symbols --------------------------------------------------*/
.weak isrReset
.weak isrNMI
.weak isrHardFault
.weak isrMemManage
.weak isrBusFault
.weak isrUsageFault
.weak isrSVCall
.weak isrDebugMonitor
.weak isrPendSV
.weak isrSysTick
.weak isrWWDG
.weak isrPVD
.weak isrTAMPER
.weak isrRTC
.weak isrFLASH
.weak isrRCC
.weak isrEXTI0
.weak isrEXTI1
.weak isrEXTI2
.weak isrEXTI3
.weak isrEXTI4
.weak isrDMA1_Channel1
.weak isrDMA1_Channel2
.weak isrDMA1_Channel3
.weak isrDMA1_Channel4
.weak isrDMA1_Channel5
.weak isrDMA1_Channel6
.weak isrDMA1_Channel7
.weak isrADC1_2
.weak isrUSB_HP_CAN_TX
.weak isrUSB_LP_CAN_RX0
.weak isrCAN_RX1
.weak isrCAN_SCE
.weak isrEXTI9_5
.weak isrTIM1_BRK
.weak isrTIM1_UP
.weak isrTIM1_TRG_COM
.weak isrTIM1_CC
.weak isrTIM2
.weak isrTIM3
.weak isrTIM4
.weak isrI2C1_EV
.weak isrI2C1_ER
.weak isrI2C2_EV
.weak isrI2C2_ER
.weak isrSPI1
.weak isrSPI2
.weak isrUSART1
.weak isrUSART2
.weak isrUSART3
.weak isrEXTI15_10
.weak isrRTCAlarm
.weak isrUSBWakeUp
.weak isrDefault
/*----------------------------------------------------------------------------*/
.thumb_set isrReset,                                                  isrDefault
.thumb_set isrNMI,                                                    isrDefault
.thumb_set isrHardFault,                                              isrDefault
.thumb_set isrMemManage,                                              isrDefault
.thumb_set isrBusFault,                                               isrDefault
.thumb_set isrUsageFault,                                             isrDefault
.thumb_set isrSVCall,                                                 isrDefault
.thumb_set isrDebugMonitor,                                           isrDefault
.thumb_set isrPendSV,                                                 isrDefault
.thumb_set isrSysTick,                                                isrDefault
.thumb_set isrWWDG,                                                   isrDefault
.thumb_set isrPVD,                                                    isrDefault
.thumb_set isrTAMPER,                                                 isrDefault
.thumb_set isrRTC,                                                    isrDefault
.thumb_set isrFLASH,                                                  isrDefault
.thumb_set isrRCC,                                                    isrDefault
.thumb_set isrEXTI0,                                                  isrDefault
.thumb_set isrEXTI1,                                                  isrDefault
.thumb_set isrEXTI2,                                                  isrDefault
.thumb_set isrEXTI3,                                                  isrDefault
.thumb_set isrEXTI4,                                                  isrDefault
.thumb_set isrDMA1_Channel1,                                          isrDefault
.thumb_set isrDMA1_Channel2,                                          isrDefault
.thumb_set isrDMA1_Channel3,                                          isrDefault
.thumb_set isrDMA1_Channel4,                                          isrDefault
.thumb_set isrDMA1_Channel5,                                          isrDefault
.thumb_set isrDMA1_Channel6,                                          isrDefault
.thumb_set isrDMA1_Channel7,                                          isrDefault
.thumb_set isrADC1_2,                                                 isrDefault
.thumb_set isrUSB_HP_CAN_TX,                                          isrDefault
.thumb_set isrUSB_LP_CAN_RX0,                                         isrDefault
.thumb_set isrCAN_RX1,                                                isrDefault
.thumb_set isrCAN_SCE,                                                isrDefault
.thumb_set isrEXTI9_5,                                                isrDefault
.thumb_set isrTIM1_BRK,                                               isrDefault
.thumb_set isrTIM1_UP,                                                isrDefault
.thumb_set isrTIM1_TRG_COM,                                           isrDefault
.thumb_set isrTIM1_CC,                                                isrDefault
.thumb_set isrTIM2,                                                   isrDefault
.thumb_set isrTIM3,                                                   isrDefault
.thumb_set isrTIM4,                                                   isrDefault
.thumb_set isrI2C1_EV,                                                isrDefault
.thumb_set isrI2C1_ER,                                                isrDefault
.thumb_set isrI2C2_EV,                                                isrDefault
.thumb_set isrI2C2_ER,                                                isrDefault
.thumb_set isrSPI1,                                                   isrDefault
.thumb_set isrSPI2,                                                   isrDefault
.thumb_set isrUSART1,                                                 isrDefault
.thumb_set isrUSART2,                                                 isrDefault
.thumb_set isrUSART3,                                                 isrDefault
.thumb_set isrEXTI15_10,                                              isrDefault
.thumb_set isrRTCAlarm,                                               isrDefault
.thumb_set isrUSBWakeUp,                                              isrDefault
/* default PANIC procedure ---------------------------------------------------*/
.section .text
.thumb_func
.global panic
.weak panic
panic:
  bkpt
  b panic 
/* default isr vector --------------------------------------------------------*/
.thumb_func
isrDefault:
  b panic
/* define IRQ vector table ---------------------------------------------------*/
.section .isr_vector_table
isr_vector_table_begin:
  .word _stack_end
  .word isrReset
  .word isrNMI
  .word isrHardFault
  .word isrMemManage
  .word isrBusFault
  .word isrUsageFault
  .word isrDefault 
  .word isrDefault 
  .word isrDefault 
  .word isrDefault 
  .word isrSVCall
  .word isrDebugMonitor
  .word isrDefault 
  .word isrPendSV
  .word isrSysTick
  .word isrWWDG
  .word isrPVD
  .word isrTAMPER
  .word isrRTC
  .word isrFLASH
  .word isrRCC
  .word isrEXTI0
  .word isrEXTI1
  .word isrEXTI2
  .word isrEXTI3
  .word isrEXTI4
  .word isrDMA1_Channel1
  .word isrDMA1_Channel2
  .word isrDMA1_Channel3
  .word isrDMA1_Channel4
  .word isrDMA1_Channel5
  .word isrDMA1_Channel6
  .word isrDMA1_Channel7
  .word isrADC1_2
  .word isrUSB_HP_CAN_TX
  .word isrUSB_LP_CAN_RX0
  .word isrCAN_RX1
  .word isrCAN_SCE
  .word isrEXTI9_5
  .word isrTIM1_BRK
  .word isrTIM1_UP
  .word isrTIM1_TRG_COM
  .word isrTIM1_CC
  .word isrTIM2
  .word isrTIM3
  .word isrTIM4
  .word isrI2C1_EV
  .word isrI2C1_ER
  .word isrI2C2_EV
  .word isrI2C2_ER
  .word isrSPI1
  .word isrSPI2
  .word isrUSART1
  .word isrUSART2
  .word isrUSART3
  .word isrEXTI15_10
  .word isrRTCAlarm
  .word isrUSBWakeUp
  .word isrDefault 
  .word isrDefault 
  .word isrDefault 
  .word isrDefault 
  .word isrDefault 
  .word isrDefault 
  .word isrDefault 
  .word isrDefault 
isr_vector_table_end:
