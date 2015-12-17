/******************************************************//**
* \file     main.c
* \brief    The Main Program to test LED_Driver Module.
* \author   Thomas Zöchbauer
* \version  V1.0
* \date     30-April-2015
**********************************************************/

#include "stm32f30x_conf.h"
#include "stm32f3_discovery_systick.h"

#include "led_driver.h"

int main(void)
{
    SystemInit();
    // Init SysTick.
    SystemCoreClockUpdate();
    if (SysTick_Config(SystemCoreClock / 1000) != 0)
    {
        /* Capture error */
        while (1);
    }

    // Init all LEDs.
    // Set all LEDs to off state.
    for (LED_LedNo led = LED3; led < LEDn; led++)
    {
        LED_Init(led);
        LED_Enable(led, false);
    }

    //LED_Enable(4, true);    // compiles well, no error!
    //LED_Enable(21, true);   // compiles well, but leads to error!

    LED_LedNo led = LED3;
    while(1)
    {
        // Toggle LED 3.
        LED_Toggle(led);
        led++;
        led = led%LEDn;
        Delay(500);
    }
}
