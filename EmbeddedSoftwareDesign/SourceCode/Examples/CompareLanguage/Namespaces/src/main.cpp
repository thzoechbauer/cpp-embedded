/******************************************************//**
* \file     main.cpp
* \brief    The Main Program to demonstrate Namespaces.
* \author   Thomas Zöchbauer
* \version  V1.0
* \date     30-April-2015
**********************************************************/

#include <cstdint>
#include <array>
#include <iterator>

#include "stm32f30x_conf.h"
#include "stm32f3_discovery_systick.h"

#include "stm32f30x_rcc.h"
#include "spl_gpio_stm32f30x.h"


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

    // Enable the GPIOE Clock.
    RCC_AHBPeriphClockCmd(RCC_AHBPeriph_GPIOE, ENABLE);

    // Initialize GPIOE.9 as output (pin is connected to LED3):
    spl::gpio::InitType InitStructure;
    InitStructure.Mode = spl::gpio::Mode_Type::out;
    InitStructure.OType = spl::gpio::OType_Type::pp;
    InitStructure.PuPd = spl::gpio::PuPd_Type::up;
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
