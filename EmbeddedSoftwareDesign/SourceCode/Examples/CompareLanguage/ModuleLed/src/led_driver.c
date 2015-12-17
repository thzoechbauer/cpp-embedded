/******************************************************//**
* \file     led_driver.c
* \brief    Control the 8 LEDs placed at the
*           STM32 F3 Discovery board.
* \author   Thomas Zöchbauer
* \version  V1.0
* \date     26-July-2015
**********************************************************/

#include "led_driver.h"

// LED Definitions with Pins and Ports mounted on STM32F3Discovery
#define LED_3_PIN                   GPIO_Pin_9
#define LED_3_GPIO_PORT             GPIOE
#define LED_3_GPIO_CLK              RCC_AHBPeriph_GPIOE

#define LED_4_PIN                   GPIO_Pin_8
#define LED_4_GPIO_PORT             GPIOE
#define LED_4_GPIO_CLK              RCC_AHBPeriph_GPIOE

#define LED_5_PIN                   GPIO_Pin_10
#define LED_5_GPIO_PORT             GPIOE
#define LED_5_GPIO_CLK              RCC_AHBPeriph_GPIOE

#define LED_6_PIN                   GPIO_Pin_15
#define LED_6_GPIO_PORT             GPIOE
#define LED_6_GPIO_CLK              RCC_AHBPeriph_GPIOE

#define LED_7_PIN                   GPIO_Pin_11
#define LED_7_GPIO_PORT             GPIOE
#define LED_7_GPIO_CLK              RCC_AHBPeriph_GPIOE

#define LED_8_PIN                   GPIO_Pin_14
#define LED_8_GPIO_PORT             GPIOE
#define LED_8_GPIO_CLK              RCC_AHBPeriph_GPIOE

#define LED_9_PIN                   GPIO_Pin_12
#define LED_9_GPIO_PORT             GPIOE
#define LED_9_GPIO_CLK              RCC_AHBPeriph_GPIOE

#define LED_10_PIN                  GPIO_Pin_13
#define LED_10_GPIO_PORT            GPIOE
#define LED_10_GPIO_CLK             RCC_AHBPeriph_GPIOE

GPIO_TypeDef* LED_GPIO_PORT[LEDn] = {LED_3_GPIO_PORT, LED_5_GPIO_PORT, LED_7_GPIO_PORT,
                                LED_9_GPIO_PORT, LED_10_GPIO_PORT, LED_8_GPIO_PORT,
                                LED_6_GPIO_PORT, LED_4_GPIO_PORT};

const uint16_t LED_GPIO_PIN[LEDn] = {LED_3_PIN, LED_5_PIN, LED_7_PIN,
                                LED_9_PIN, LED_10_PIN, LED_8_PIN,
                                LED_6_PIN, LED_4_PIN};

const uint32_t LED_GPIO_CLK[LEDn] = {LED_3_GPIO_CLK, LED_5_GPIO_CLK, LED_7_GPIO_CLK,
                                LED_9_GPIO_CLK, LED_10_GPIO_CLK, LED_8_GPIO_CLK,
                                LED_6_GPIO_CLK, LED_4_GPIO_CLK};


void LED_Init(LED_LedNo const LedNo)
{
    GPIO_InitTypeDef GPIO_InitStructure;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
    GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
    GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;

    /* Enable the GPIO LED Clock */
    RCC_AHBPeriphClockCmd(LED_GPIO_CLK[LedNo], ENABLE);
    /* Configure the GPIO LED pin */
    GPIO_InitStructure.GPIO_Pin = LED_GPIO_PIN[LedNo];
    GPIO_Init(LED_GPIO_PORT[LedNo], &GPIO_InitStructure);
}

void LED_Enable(LED_LedNo const LedNo, bool const Enable)
{
    if (Enable)
    {
        LED_GPIO_PORT[LedNo]->BSRR = LED_GPIO_PIN[LedNo];   // Set bit in register.
    }
    else
    {
        LED_GPIO_PORT[LedNo]->BRR = LED_GPIO_PIN[LedNo];  // Clear bit in register.
    }
}

void LED_Toggle(LED_LedNo const LedNo)
{
    LED_GPIO_PORT[LedNo]->ODR ^= LED_GPIO_PIN[LedNo];
}
