.syntax unified

/* User overridable symbols --------------------------------------------------*/
.weak irqReset
.weak irqNMI
.weak irqHardFault
.weak irqMemManage
.weak irqBusFault
.weak irqUsageFault
.weak irqSVCall
.weak irqDebugMonitor
.weak irqPendSV
.weak irqSysTick
.weak irqWWDG
.weak irqPVD
.weak irqTAMPER
.weak irqRTC
.weak irqFLASH
.weak irqRCC
.weak irqEXTI0
.weak irqEXTI1
.weak irqEXTI2
.weak irqEXTI3
.weak irqEXTI4
.weak irqDMA1_Channel1
.weak irqDMA1_Channel2
.weak irqDMA1_Channel3
.weak irqDMA1_Channel4
.weak irqDMA1_Channel5
.weak irqDMA1_Channel6
.weak irqDMA1_Channel7
.weak irqADC1_2
.weak irqUSB_HP_CAN_TX
.weak irqUSB_LP_CAN_RX0
.weak irqCAN_RX1
.weak irqCAN_SCE
.weak irqEXTI9_5
.weak irqTIM1_BRK
.weak irqTIM1_UP
.weak irqTIM1_TRG_COM
.weak irqTIM1_CC
.weak irqTIM2
.weak irqTIM3
.weak irqTIM4
.weak irqI2C1_EV
.weak irqI2C1_ER
.weak irqI2C2_EV
.weak irqI2C2_ER
.weak irqSPI1
.weak irqSPI2
.weak irqUSART1
.weak irqUSART2
.weak irqUSART3
.weak irqEXTI15_10
.weak irqRTCAlarm
.weak irqUSBWakeUp
.weak irqDefault
/*----------------------------------------------------------------------------*/
.thumb_set irqReset,                                                  irqDefault
.thumb_set irqNMI,                                                    irqDefault
.thumb_set irqHardFault,                                              irqDefault
.thumb_set irqMemManage,                                              irqDefault
.thumb_set irqBusFault,                                               irqDefault
.thumb_set irqUsageFault,                                             irqDefault
.thumb_set irqSVCall,                                                 irqDefault
.thumb_set irqDebugMonitor,                                           irqDefault
.thumb_set irqPendSV,                                                 irqDefault
.thumb_set irqSysTick,                                                irqDefault
.thumb_set irqWWDG,                                                   irqDefault
.thumb_set irqPVD,                                                    irqDefault
.thumb_set irqTAMPER,                                                 irqDefault
.thumb_set irqRTC,                                                    irqDefault
.thumb_set irqFLASH,                                                  irqDefault
.thumb_set irqRCC,                                                    irqDefault
.thumb_set irqEXTI0,                                                  irqDefault
.thumb_set irqEXTI1,                                                  irqDefault
.thumb_set irqEXTI2,                                                  irqDefault
.thumb_set irqEXTI3,                                                  irqDefault
.thumb_set irqEXTI4,                                                  irqDefault
.thumb_set irqDMA1_Channel1,                                          irqDefault
.thumb_set irqDMA1_Channel2,                                          irqDefault
.thumb_set irqDMA1_Channel3,                                          irqDefault
.thumb_set irqDMA1_Channel4,                                          irqDefault
.thumb_set irqDMA1_Channel5,                                          irqDefault
.thumb_set irqDMA1_Channel6,                                          irqDefault
.thumb_set irqDMA1_Channel7,                                          irqDefault
.thumb_set irqADC1_2,                                                 irqDefault
.thumb_set irqUSB_HP_CAN_TX,                                          irqDefault
.thumb_set irqUSB_LP_CAN_RX0,                                         irqDefault
.thumb_set irqCAN_RX1,                                                irqDefault
.thumb_set irqCAN_SCE,                                                irqDefault
.thumb_set irqEXTI9_5,                                                irqDefault
.thumb_set irqTIM1_BRK,                                               irqDefault
.thumb_set irqTIM1_UP,                                                irqDefault
.thumb_set irqTIM1_TRG_COM,                                           irqDefault
.thumb_set irqTIM1_CC,                                                irqDefault
.thumb_set irqTIM2,                                                   irqDefault
.thumb_set irqTIM3,                                                   irqDefault
.thumb_set irqTIM4,                                                   irqDefault
.thumb_set irqI2C1_EV,                                                irqDefault
.thumb_set irqI2C1_ER,                                                irqDefault
.thumb_set irqI2C2_EV,                                                irqDefault
.thumb_set irqI2C2_ER,                                                irqDefault
.thumb_set irqSPI1,                                                   irqDefault
.thumb_set irqSPI2,                                                   irqDefault
.thumb_set irqUSART1,                                                 irqDefault
.thumb_set irqUSART2,                                                 irqDefault
.thumb_set irqUSART3,                                                 irqDefault
.thumb_set irqEXTI15_10,                                              irqDefault
.thumb_set irqRTCAlarm,                                               irqDefault
.thumb_set irqUSBWakeUp,                                              irqDefault
/* default PANIC procedure ---------------------------------------------------*/
.section .text
.thumb_func
.global panic
.weak panic
panic:
  bkpt
  b panic 
/* default irq vector --------------------------------------------------------*/
.thumb_func
irqDefault:
  b panic
/* define IRQ vector table ---------------------------------------------------*/
.section .irq_vector_table
irq_vector_table_begin:
  .word _stack_end
  .word irqReset
  .word irqNMI
  .word irqHardFault
  .word irqMemManage
  .word irqBusFault
  .word irqUsageFault
  .word irqDefault 
  .word irqDefault 
  .word irqDefault 
  .word irqDefault 
  .word irqSVCall
  .word irqDebugMonitor
  .word irqDefault 
  .word irqPendSV
  .word irqSysTick
  .word irqWWDG
  .word irqPVD
  .word irqTAMPER
  .word irqRTC
  .word irqFLASH
  .word irqRCC
  .word irqEXTI0
  .word irqEXTI1
  .word irqEXTI2
  .word irqEXTI3
  .word irqEXTI4
  .word irqDMA1_Channel1
  .word irqDMA1_Channel2
  .word irqDMA1_Channel3
  .word irqDMA1_Channel4
  .word irqDMA1_Channel5
  .word irqDMA1_Channel6
  .word irqDMA1_Channel7
  .word irqADC1_2
  .word irqUSB_HP_CAN_TX
  .word irqUSB_LP_CAN_RX0
  .word irqCAN_RX1
  .word irqCAN_SCE
  .word irqEXTI9_5
  .word irqTIM1_BRK
  .word irqTIM1_UP
  .word irqTIM1_TRG_COM
  .word irqTIM1_CC
  .word irqTIM2
  .word irqTIM3
  .word irqTIM4
  .word irqI2C1_EV
  .word irqI2C1_ER
  .word irqI2C2_EV
  .word irqI2C2_ER
  .word irqSPI1
  .word irqSPI2
  .word irqUSART1
  .word irqUSART2
  .word irqUSART3
  .word irqEXTI15_10
  .word irqRTCAlarm
  .word irqUSBWakeUp
  .word irqDefault 
  .word irqDefault 
  .word irqDefault 
  .word irqDefault 
  .word irqDefault 
  .word irqDefault 
  .word irqDefault 
  .word irqDefault 
irq_vector_table_end:
