/******************************************************//**
* \file     int_vect.c
* \brief    Interrupt vector table for STM32F303VC.
* \author   Thomas Zöchbauer
* \version  V1.0
* \date     30-September-2015
**********************************************************/

#include <stddef.h>

void __initial_stack_pointer();

void __my_startup         () __attribute__((used, noinline));
void __vector_unused_irq  () __attribute__((used, noinline));
void __nmi_handler        () __attribute__((used, noinline));
void __hard_fault_handler () __attribute__((used, noinline));
void __mem_manage_handler () __attribute__((used, noinline));
void __bus_fault_handler  () __attribute__((used, noinline));
void __usage_fault_handler() __attribute__((used, noinline));
void __svc_handler        () __attribute__((used, noinline));
void __debug_mon_handler  () __attribute__((used, noinline));
void __pend_sv_handler    () __attribute__((used, noinline));
void __sys_tick_handler   () __attribute__((used, noinline));

void __vector_unused_irq  () { for(;;) { __asm__ volatile("nop"); } }
void __nmi_handler        () { for(;;) { __asm__ volatile("nop"); } }
void __hard_fault_handler () { for(;;) { __asm__ volatile("nop"); } }
void __mem_manage_handler () { for(;;) { __asm__ volatile("nop"); } }
void __bus_fault_handler  () { for(;;) { __asm__ volatile("nop"); } }
void __usage_fault_handler() { for(;;) { __asm__ volatile("nop"); } }
void __svc_handler        () { for(;;) { __asm__ volatile("nop"); } }
void __debug_mon_handler  () { for(;;) { __asm__ volatile("nop"); } }
void __pend_sv_handler    () { for(;;) { __asm__ volatile("nop"); } }

void __sys_tick_handler   () { for(;;) { __asm__ volatile("nop"); } }


typedef void(*isr_type)();
#define NUMBER_OF_INTERRUPTS  (128U)

extern const volatile isr_type __isr_vector[NUMBER_OF_INTERRUPTS] __attribute__((section(".isr_vector")));

const volatile isr_type __isr_vector[NUMBER_OF_INTERRUPTS] =
{
    __initial_stack_pointer,    // 0x0000, -16: Initial stack pointer handler.
    __my_startup,               // 0x0004, -15: Reset/Startup handler.
    __nmi_handler,              // 0x0008, -14: Non maskable interrupt handler.
    __hard_fault_handler,       // 0x000C, -13: All class of fault handler.
    __mem_manage_handler,       // 0x0010, -12: Memory management handler.
    __bus_fault_handler,        // 0x0014, -11: Pre-fetch fault, memory access fault handler.
    __usage_fault_handler,      // 0x0018, -10: Undefined instruction or illegal state handler.
    __vector_unused_irq,        // 0x001C, -9: Reserved handler.
    __vector_unused_irq,        // 0x0020, -8: Reserved handler.
    __vector_unused_irq,        // 0x0024, -7: Reserved handler.
    __vector_unused_irq,        // 0x0028, -6: Reserved handler.
    __svc_handler,              // 0x002C, -5: System service call via SWI instruction handler.
    __debug_mon_handler,        // 0x0030, -4: Debug monitor handler.
    __vector_unused_irq,        // 0x0034, -3: Reserved handler.
    __pend_sv_handler,          // 0x0038, -2: Pendable request for system service handler.
    __sys_tick_handler,         // 0x003C, -1: System tick timer handler.

	// External Interrupts:
	__vector_unused_irq,   		// __wwdg_handler              // 0x0040, 0: Window Watchdog interrupt handler.
    __vector_unused_irq,       	// __pvd_handler               // 0x0044, 1: PVD through EXTI Line16 detection interrupt handler.
    __vector_unused_irq,       	// __tamper_stamp_handler      // 0x0048, 2: Tamper and TimeStamp interrupts through EXTI Line19 handler.
    __vector_unused_irq,       	// __rtc_wkup_handler          // 0x004C, 3: RTC wakeup timer interrupt through EXTI Line20 handler.
    __vector_unused_irq,       	// __flash_handler             // 0x0050, 4: Flash global interrupt handler.
    __vector_unused_irq,       	// __rcc_handler               // 0x0054, 5: RCC global interrupt handler.
    __vector_unused_irq,       	// __exti0_handler             // 0x0058, 6: EXTI Line0 interrupt handler.
    __vector_unused_irq,       	// __exti1_handler             // 0x005C, 7: EXTI Line1 interrupt handler.
    __vector_unused_irq,       	// __exti2_ts_handler          // 0x0060, 8: EXTI Line2 and Touch sensing interrupts handler.
    __vector_unused_irq,       	// __exti3_handler             // 0x0064, 9: EXTI Line3 interrupt handler.
    __vector_unused_irq,       	// __exti4_handler             // 0x0068, 10: EXTI Line4 interrupt handler.
    __vector_unused_irq,       	// __dma1_channel1_handler     // 0x006C, 11: DMA1 channel 1 interrupt handler.
    __vector_unused_irq,       	// __dma1_channel2_handler     // 0x0070, 12: DMA1 channel 2 interrupt handler.
    __vector_unused_irq,       	// __dma1_channel3_handler     // 0x0074, 13: DMA1 channel 3 interrupt handler.
    __vector_unused_irq,       	// __dma1_channel4_handler     // 0x0078, 14: DMA1 channel 4 interrupt handler.
    __vector_unused_irq,       	// __dma1_channel5_handler     // 0x007C, 15: DMA1 channel 5 interrupt handler.
    __vector_unused_irq,       	// __dma1_channel6_handler     // 0x0080, 16: DMA1 channel 6 interrupt handler.
    __vector_unused_irq,       	// __dma1_channel7_handler     // 0x0084, 17: DMA1 channel 7 interrupt handler.
    __vector_unused_irq,       	// __adc1_2_handler            // 0x0088, 18: ADC1 and ADC2 global interrupt handler.
    __vector_unused_irq,       	// __usb_hp_can1_tx_handler    // 0x008C, 19: USB High Priority/CAN_TX interrupts handler.
    __vector_unused_irq,       	// __usb_lp_can1_rx0_handler   // 0x0090, 20: USB Low Priority/CAN_RX0 interrupts handler.
    __vector_unused_irq,       	// __can1_rx1_handler          // 0x0094, 21: CAN_RX1 interrupt handler.
    __vector_unused_irq,       	// __can1_sce_handler          // 0x0098, 22: CAN_SCE interrupt handler.
    __vector_unused_irq,       	// __exti9_5_handler           // 0x009C, 23: EXTI Line[9:5] interrupts handler.
    __vector_unused_irq,       	// __tim1_brk_tim15_handler    // 0x00A0, 24: TIM1 Break/TIM15 global interrupts handler.
    __vector_unused_irq,       	// __tim1_up_tim16_handler     // 0x00A4, 25: TIM1 Update/TIM16 global interrupts handler.
    __vector_unused_irq,       	// __tim1_trg_com_tim17_handler// 0x00A8, 26: TIM1 trigger and commutation/TIM17 interrupts handler.
    __vector_unused_irq,       	// __tim1_cc_handler           // 0x00AC, 27: TIM1 capture compare interrupt handler.
    __vector_unused_irq,       	// __tim2_handler              // 0x00B0, 28: TIM2 global interrupt handler.
    __vector_unused_irq,       	// __tim3_handler              // 0x00B4, 29: TIM3 global interrupt handler.
    __vector_unused_irq,       	// __tim4_handler              // 0x00B8, 30: TIM4 global interrupt handler.
    __vector_unused_irq,       	// __i2c1_ev_handler           // 0x00BC, 31: I2C1 event interrupt & EXTI Line23 interrupt handler.
    __vector_unused_irq,       	// __i2c1_er_handler           // 0x00C0, 32: I2C1 error interrupt handler.
    __vector_unused_irq,       	// __i2c2_ev_handler           // 0x00C4, 33: I2C2 event interrupt & EXTI Line24 interrupt handler.
    __vector_unused_irq,       	// __i2c2_er_handler           // 0x00C8, 34: I2C2 error interrupt handler.
    __vector_unused_irq,       	// __spi1_handler              // 0x00CC, 35: SPI1 global interrupt handler.
    __vector_unused_irq,       	// __spi2_handler              // 0x00D0, 36: SPI2 global interrupt.
    __vector_unused_irq,       	// __usart1_handler            // 0x00D4, 37: USART1 global interrupt & EXTI Line 25 handler.
    __vector_unused_irq,       	// __usart2_handler            // 0x00D8, 38: USART2 global interrupt & EXTI Line 26 handler.
    __vector_unused_irq,       	// __usart3_handler            // 0x00DC, 39: USART3 global interrupt & EXTI Line 28 handler.
    __vector_unused_irq,       	// __exti15_10_handler         // 0x00E0, 40: EXTI Line[15:10] interrupts handler.
    __vector_unused_irq,       	// __rtc_alarm_handler         // 0x00E4, 41: RTC alarm interrupt.
    __vector_unused_irq,       	// __usbwakeup_handler         // 0x00E8, 42: USB wakeup from Suspend (EXTI line 18) handler.
    __vector_unused_irq,       	// __tim8_brk_handler          // 0x00EC, 43: TIM8 break interrupt handler.
    __vector_unused_irq,       	// __tim8_up_handler           // 0x00F0, 44: TIM8 update interrupt handler.
    __vector_unused_irq,       	// __tim8_trg_com_handler      // 0x00F4, 45: TIM8 Trigger and commutation interrupts handler.
    __vector_unused_irq,       	// __tim8_cc_handler           // 0x00F8, 46: TIM8 capture compare interrupt handler.
    __vector_unused_irq,       	// __adc3_handler              // 0x00FC, 47: ADC3 global interrupt handler.
    __vector_unused_irq,       	// __vector_unused_irq         // 0x0100, 48: Reserved handler.
    __vector_unused_irq,       	// __vector_unused_irq         // 0x0104, 49: Reserved handler.
    __vector_unused_irq,       	// __vector_unused_irq         // 0x0108, 50: Reserved handler.
    __vector_unused_irq,       	// __spi3_handler              // 0x010C, 51: SPI3 global interrupt handler.
    __vector_unused_irq,       	// __uart4_handler             // 0x0110, 52: UART4 global and EXTI Line 34 interrupts handler.
    __vector_unused_irq,       	// __uart5_handler             // 0x0114, 53: UART5 global and EXTI Line 35 interrupts handler.
    __vector_unused_irq,       	// __tim6_dac_handler          // 0x0118, 54: TIM6 global and DAC1 underrun interrupts handler.
    __vector_unused_irq,       	// __tim7_handler              // 0x011C, 55: TIM7 global interrupt handler.
    __vector_unused_irq,       	// __dma2_channel1_handler     // 0x0120, 56: DMA2 channel1 global interrupt handler.
    __vector_unused_irq,       	// __dma2_channel2_handler     // 0x0124, 57: DMA2 channel2 global interrupt handler.
    __vector_unused_irq,       	// __dma2_channel3_handler     // 0x0128, 58: DMA2 channel3 global interrupt handler.
    __vector_unused_irq,       	// __dma2_channel4_handler     // 0x012C, 59: DMA2 channel4 global interrupt handler.
    __vector_unused_irq,       	// __dma2_channel5_handler     // 0x0130, 60: DMA2 channel5 global interrupt handler.
    __vector_unused_irq,       	// __adc4_handler              // 0x0134, 61: ADC4 global interrupt handler.
    __vector_unused_irq,       	// __vector_unused_irq         // 0x0138, 62: Reserved handler.
    __vector_unused_irq,       	// __vector_unused_irq         // 0x013C, 63: Reserved handler.
    __vector_unused_irq,       	// __comp1_2_3_handler         // 0x0140, 64: COMP1 & COMP2 & COMP3 interrupts combined with EXTI Lines 21, 22 and 29 interrupts handle
    __vector_unused_irq,       	// __comp4_5_6_handler         // 0x0144, 65: COMP4 & COMP5 & COMP6 interrupts combined with EXTI Lines 30, 31 and 32 interrupts handle
    __vector_unused_irq,       	// __comp7_handler             // 0x0148, 66: COMP7 interrupt combined with EXTI Line 33interrupt handler.
    __vector_unused_irq,       	// __vector_unused_irq         // 0x014C, 67: Reserved handler.
    __vector_unused_irq,       	// __vector_unused_irq         // 0x0150, 68: Reserved handler.
    __vector_unused_irq,       	// __vector_unused_irq         // 0x0154, 69: Reserved handler.
    __vector_unused_irq,       	// __vector_unused_irq         // 0x0158, 70: Reserved handler.
    __vector_unused_irq,       	// __vector_unused_irq         // 0x015C, 71: Reserved handler.
    __vector_unused_irq,       	// __vector_unused_irq         // 0x0160, 72: Reserved handler.
    __vector_unused_irq,       	// __vector_unused_irq         // 0x0164, 73: Reserved handler.
    __vector_unused_irq,       	// __usb_hp_handler            // 0x0168, 74: USB High priority interrupt handler.
    __vector_unused_irq,       	// __usb_lp_handler            // 0x016C, 75: USB Low priority interrupt handler.
    __vector_unused_irq,       	// __usbwakeup_rmp_handler     // 0x0170, 76: USB wake up from Suspend and EXTI Line 18 handler.
    __vector_unused_irq,       	// __vector_unused_irq         // 0x0174, 77: Reserved handler.
    __vector_unused_irq,       	// __vector_unused_irq         // 0x0178, 78: Reserved handler.
    __vector_unused_irq,       	// __vector_unused_irq         // 0x017C, 79: Reserved handler.
    __vector_unused_irq,       	// __vector_unused_irq         // 0x0180, 80: Reserved handler.
    __vector_unused_irq,       	// __fpu_handler               // 0x0184, 81: Floating point interrupt handler.
    __vector_unused_irq,       	// __vector_unused_irq         // 0x0188, 82: Reserved handler.
    __vector_unused_irq,       	// __vector_unused_irq         // 0x018C, 83: Reserved handler.
    __vector_unused_irq,       	// __vector_unused_irq         // 0x0190, 84: Reserved handler.
    NULL,       				// 0x0194, 85: Dummy handler.
    NULL,       				// 0x0198, 86: Dummy handler.
    NULL,       				// 0x019C, 87: Dummy handler.
    NULL,       				// 0x01A0, 88: Dummy handler.
    NULL,       				// 0x01A4, 89: Dummy handler.
    NULL,       				// 0x01A8, 90: Dummy handler.
    NULL,                   	// 0x01AC, 91: Dummy handler.
    NULL,                   	// 0x01B0, 92: Dummy handler.
    NULL,                   	// 0x01B4, 93: Dummy handler.
    NULL,                   	// 0x01B8, 94: Dummy handler.
    NULL,                   	// 0x01BC, 95: Dummy handler.
    NULL,                   	// 0x01C0, 96: Dummy handler.
    NULL,                   	// 0x01C4, 97: Dummy handler.
    NULL,                   	// 0x01C8, 98: Dummy handler.
    NULL,                   	// 0x01CC, 99: Dummy handler.
    NULL,                   	// 0x01D0, 100: Dummy handler.
    NULL,                   	// 0x01D4, 101: Dummy handler.
    NULL,                   	// 0x01D8, 102: Dummy handler.
    NULL,                   	// 0x01DC, 103: Dummy handler.
    NULL,                   	// 0x01E0, 104: Dummy handler.
    NULL,                   	// 0x01E4, 105: Dummy handler.
    NULL,                   	// 0x01E8, 106: Dummy handler.
    NULL,                   	// 0x01EC, 107: Dummy handler.
    NULL,                   	// 0x01F0, 108: Dummy handler.
    NULL,                   	// 0x01F4, 109: Dummy handler.
    NULL,                   	// 0x01F8, 110: Dummy handler.
	NULL                    	// 0x01FC, 111: Dummy handler.
};
