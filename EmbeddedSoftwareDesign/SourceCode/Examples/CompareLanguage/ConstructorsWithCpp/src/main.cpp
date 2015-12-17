/******************************************************//**
* \file     main.cpp
* \brief    The Main Program.
* \author   Thomas Zöchbauer
* \version  V1.0
* \date     07-August-2015
**********************************************************/

#include <cstdint>
#include <type_traits>

#include "stm32f30x_conf.h"
#include "stm32f3_discovery_systick.h"

#include "stm32f30x_rcc.h"
#include "spl_gpio_stm32f30x.h"

#include "simpleled.h"

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

    // Check CTors:
    bool is_default_constructible = std::is_default_constructible<SimpleLed>::value;
	bool is_copy_constructible = std::is_copy_constructible<SimpleLed>::value;
	bool is_move_constructible = std::is_move_constructible<SimpleLed>::value;
	bool is_copy_assignable = std::is_copy_assignable<SimpleLed>::value;
	bool is_move_assignable = std::is_move_assignable<SimpleLed>::value;
    bool is_destructible = std::is_destructible<SimpleLed>::value;


    // Enable the GPIOE Clock.
    RCC_AHBPeriphClockCmd(RCC_AHBPeriph_GPIOE, ENABLE);

    // Initialize GPIOE.9 as output (pin is connected to LED3):
    spl::gpio::InitTypeDef InitStructure;
    InitStructure.Mode = spl::gpio::Mode_TypeDef::out;
    InitStructure.OType = spl::gpio::OType_TypeDef::pp;
    InitStructure.PuPd = spl::gpio::PuPd_TypeDef::up;
    InitStructure.Speed = spl::gpio::Speed_50MHz;
    InitStructure.Pin = spl::gpio::Pin_9;
    spl::gpio::Init(spl::gpio::gpioe, &InitStructure);

    while(1)
    {
        spl::gpio::SetBits(spl::gpio::gpioe, spl::gpio::Pin_9);
        Delay(500);
        spl::gpio::ResetBits(spl::gpio::gpioe, spl::gpio::Pin_9);
        Delay(200);
    }
}
