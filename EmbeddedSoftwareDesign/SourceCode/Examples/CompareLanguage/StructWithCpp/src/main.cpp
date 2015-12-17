/******************************************************//**
* \file     main.cpp
* \brief    The Main Program.
* \author   Thomas Zöchbauer
* \version  V1.0
* \date     01-August-2015
**********************************************************/

#include <cstdint>
#include <array>
#include <iterator>
#include <cmath>

#include "stm32f30x_conf.h"
#include "stm32f3_discovery_systick.h"

#include "stm32f30x_rcc.h"
#include "spl_gpio_stm32f30x.h"

struct Point
{
    int8_t X;
    int8_t Y;
};

struct Line
{
    Point Start;
    Point End;

    Line() = delete;    // Delete default CTor.
    Line(const Line&) = default; // Default Copy-CTor.
    Line(Point& p1, Point& p2) : Start(p1), End(p2) { }
    Line& operator=(const Line&) = default; // Default assignment Operator.
    ~Line() = default;  // Set default DTor.

    float CalcLength();
};

float Line::CalcLength()
{
    int16_t dist_x = Start.X - End.X;
    int16_t dist_y = Start.Y - End.Y;

    return sqrt((dist_x*dist_x) + (dist_y*dist_y));
}

int main(void)
{
    // Init SysTick.
    SystemCoreClockUpdate();
    if (SysTick_Config(SystemCoreClock / 1000) != 0)
    {
        /* Capture error */
        while (1);
    }

    Point p1 = {0,0};
    Point p2 = {30, 20};

    // Line l1 = {{0,0},{20,30}};   // Not valid since CTors are specified.
    Line l2 = {p1, p2};
    float len = l2.CalcLength();    // returns 36.0555115

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
