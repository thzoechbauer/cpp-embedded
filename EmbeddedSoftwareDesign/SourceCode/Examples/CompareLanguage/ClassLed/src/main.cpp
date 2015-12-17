/******************************************************//**
* \file     main.cpp
* \brief    The Main Program to test LED-Class.
* \author   Thomas Zöchbauer
* \version  V1.0
* \date     30-April-2015
**********************************************************/

#include <cstdint>
#include <cstdint>
#include <array>
#include <iterator>

#include "stm32f30x_conf.h"
#include "stm32f3_discovery_systick.h"

#include "led.h"

template<uint32_t N>
using led_array_t = std::array<Led* const, N>;


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

    // Create led-objects.
    Led led3(led_enum_t::led3);
    Led led4(led_enum_t::led4);
    Led led5(led_enum_t::led5);
    Led led6(led_enum_t::led6);
    Led led7(led_enum_t::led7);
    Led led8(led_enum_t::led8);
    Led led9(led_enum_t::led9);
    Led led10(led_enum_t::led10);

    // Create array that holds pointer to led-objects.
    led_array_t<num_leds> led_arr = {&led3, &led5,
                    &led7, &led9, &led10, &led8, &led6, &led4};

    // Init all LEDs.
    // Set all LEDs to off state.
    for(auto l : led_arr)
    {
        l->init();
        l->enable(false);
    }

    //Led test_led1(3);      // error: invalid conversion from 'int' to 'led_enum_t'.
    //Led test_led2(static_cast<led_enum_t>(3));   // compiles well.
    //Led test_led3(static_cast<led_enum_t>(21));   // compiles well.
    //test_led2.enable(true);     // ok.
    //test_led3.enable(true);     // may lead to an error.

    auto iter = led_arr.begin();

    while(1)
    {
        (*iter)->toggle();
        iter++;
        // Reset iterator if last led of array toggled.
        if (iter == led_arr.end())
        {
            iter = led_arr.begin();
        }

        Delay(500);
    }
}
