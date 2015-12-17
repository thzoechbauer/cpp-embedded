#ifndef HALO_H_INCLUDED
#define HALO_H_INCLUDED

/******************************************************//**
* \file     led_driver.h
* \brief    Control the 8 LEDs placed at the
*           STM32 F3 Discovery board.
* \author   Thomas Zöchbauer
* \version  V1.0
* \date     26-July-2015
**********************************************************/

#include <stdint.h>
#include <stdbool.h>

#include "stm32f30x_gpio.h"
#include "stm32f30x_rcc.h"

#define LEDn    8	// Number of LEDs.

// Enumeration of LEDs.
typedef enum
{
    LED3 = 0,
    LED5 = 1,
    LED7 = 2,
    LED9 = 3,
    LED10 = 4,
    LED8 = 5,
    LED6 = 6,
    LED4 = 7
} LED_LedNo;

// Initialize LED.
void LED_Init(LED_LedNo const LedNo);
// Enable or disable LED.
void LED_Enable(LED_LedNo const LedNo, bool const Enable);
// Toggle state of LED.
void LED_Toggle(LED_LedNo const LedNo);

#endif // HALO_H_INCLUDED
