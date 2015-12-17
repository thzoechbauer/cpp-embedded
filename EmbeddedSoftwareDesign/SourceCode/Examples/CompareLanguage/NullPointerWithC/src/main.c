/******************************************************//**
* \file     main.c
* \brief    The Main Program.
* \author   Thomas Zöchbauer
* \version  V1.0
* \date     05-August-2015
**********************************************************/

#include <stdio.h>  // For use of NULL.
#include <limits.h>

#include "stm32f30x_conf.h"
#include "stm32f3_discovery_systick.h"
#include "stm32f30x_rcc.h"
#include "stm32f30x_gpio.h"

// Squares value.
int Square(int val)
{
    return val*val;
}

// Deref pointer and square value.
int PtrSquare(int* ptr_val)
{
    if (ptr_val != NULL)
        return (*ptr_val) * (*ptr_val);
    else
        return 0;
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

    int32_t value = 12;
    int32_t* ptr_val = &value;
    int32_t* ptr_NULL = NULL;

    int32_t sqare_value = Square(value);        // 144
    int32_t square_ptr_val = Square(ptr_val);   // squares pointer address!
    int32_t square_ptr_NULL = Square(ptr_NULL); // 0
    int32_t square_NULL = Square(NULL);         // 0

    int32_t ptrsquare_value = PtrSquare(value); // Might cause Memory-Access-Violation!
    int32_t ptrsquare_ptr_val = PtrSquare(ptr_val);   // 144
    int32_t ptrsquare_ptr_NULL = PtrSquare(ptr_NULL); // 0
    int32_t ptrsquare_NULL = PtrSquare(NULL);         // 0
    int32_t ptrsquare_anyval = PtrSquare(123);  // Might cause Memory-Access-Violation!


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
