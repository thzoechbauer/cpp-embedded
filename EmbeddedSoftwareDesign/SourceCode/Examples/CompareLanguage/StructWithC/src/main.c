/******************************************************//**
* \file     main.c
* \brief    The Main Program.
* \author   Thomas Zöchbauer
* \version  V1.0
* \date     01-August-2015
**********************************************************/

#include "stm32f30x_conf.h"
#include "stm32f3_discovery_systick.h"
#include "stm32f30x_rcc.h"
#include "stm32f30x_gpio.h"

#include <stdint.h>

// Definition of a Line-Structure with Start- and Endpoint.
//struct Line
//{
//    struct Point
//    {
//        int8_t X;
//        int8_t Y;
//    } Start, End;
//};

struct Point
{
    int8_t X;
    int8_t Y;
};

struct Line
{
    struct Point Start;
    struct Point End;
};

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

    struct Point p1 = {0, 0};
    struct Point p2 = {30, 20};

    struct Line l1 = {{0, 0}, {30, 20}};
    struct Line l2 = {p1, p2};


    // Enable the GPIOE Clock.
    RCC_AHBPeriphClockCmd(RCC_AHBPeriph_GPIOE, ENABLE);

    // Initialize GPIOE.9 as output (pin is connected to LED3):
    GPIO_InitTypeDef InitStructure;
    InitStructure.GPIO_Mode = GPIO_Mode_OUT;
    InitStructure.GPIO_OType = GPIO_OType_PP;
    InitStructure.GPIO_PuPd = GPIO_PuPd_UP;
    InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    InitStructure.GPIO_Pin = GPIO_Pin_9;
    GPIO_Init(GPIOE, &InitStructure);

    while(1)
    {
        GPIO_SetBits(GPIOE, GPIO_Pin_9);
        Delay(500);
        GPIO_ResetBits(GPIOE, GPIO_Pin_9);
        Delay(200);
    }
}
