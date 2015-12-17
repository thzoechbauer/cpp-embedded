/********************************************//**
* \file     led.cpp
* \brief    Implementation of class Led.
* \author   Thomas Zöchbauer
* \version  V1.0
* \date     26-July-2015
************************************************/

#include <type_traits>

#include "led.h"

// LED Definitions with Pins and Ports mounted on STM32F3Discovery
constexpr GPIO_TypeDef* led3_gpio_port = GPIOE;
constexpr uint16_t  led3_gpio_pin = GPIO_Pin_9;
constexpr uint32_t  led3_gpio_clock = RCC_AHBPeriph_GPIOE;

constexpr GPIO_TypeDef* led4_gpio_port = GPIOE;
constexpr uint16_t  led4_gpio_pin = GPIO_Pin_8;
constexpr uint32_t  led4_gpio_clock = RCC_AHBPeriph_GPIOE;

constexpr GPIO_TypeDef* led5_gpio_port = GPIOE;
constexpr uint16_t  led5_gpio_pin = GPIO_Pin_10;
constexpr uint32_t  led5_gpio_clock = RCC_AHBPeriph_GPIOE;

constexpr GPIO_TypeDef* led6_gpio_port = GPIOE;
constexpr uint16_t  led6_gpio_pin = GPIO_Pin_15;
constexpr uint32_t  led6_gpio_clock = RCC_AHBPeriph_GPIOE;

constexpr GPIO_TypeDef* led7_gpio_port = GPIOE;
constexpr uint16_t  led7_gpio_pin = GPIO_Pin_11;
constexpr uint32_t  led7_gpio_clock = RCC_AHBPeriph_GPIOE;

constexpr GPIO_TypeDef* led8_gpio_port = GPIOE;
constexpr uint16_t  led8_gpio_pin = GPIO_Pin_14;
constexpr uint32_t  led8_gpio_clock = RCC_AHBPeriph_GPIOE;

constexpr GPIO_TypeDef* led9_gpio_port = GPIOE;
constexpr uint16_t  led9_gpio_pin = GPIO_Pin_12;
constexpr uint32_t  led9_gpio_clock = RCC_AHBPeriph_GPIOE;

constexpr GPIO_TypeDef* led10_gpio_port = GPIOE;
constexpr uint16_t  led10_gpio_pin = GPIO_Pin_13;
constexpr uint32_t  led10_gpio_clock = RCC_AHBPeriph_GPIOE;

constexpr GPIO_TypeDef* led_gpio_port[num_leds] = {led3_gpio_port, led4_gpio_port,
                                    led5_gpio_port, led6_gpio_port, led7_gpio_port,
                                    led8_gpio_port, led9_gpio_port, led10_gpio_port};

constexpr uint16_t led_gpio_pin[num_leds] = {led3_gpio_pin, led4_gpio_pin,
                                    led5_gpio_pin, led6_gpio_pin, led7_gpio_pin,
                                    led8_gpio_pin, led9_gpio_pin, led10_gpio_pin};

constexpr uint32_t led_gpio_clock[num_leds] = {led3_gpio_clock, led4_gpio_clock,
                                    led5_gpio_clock, led6_gpio_clock, led7_gpio_clock,
                                    led8_gpio_clock, led9_gpio_clock, led10_gpio_clock};

Led::Led(led_enum_t const led_enum)
        : mPort(led_gpio_port[static_cast<uint8_t>(led_enum)]),
          mPin(led_gpio_pin[static_cast<uint8_t>(led_enum)]),
          mClock(led_gpio_clock[static_cast<uint8_t>(led_enum)])
{
    // empty
}

void Led::init() const
{
    GPIO_InitTypeDef GPIO_InitStructure;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
    GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
    GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;

    /* Enable the GPIO LED Clock */
    RCC_AHBPeriphClockCmd(mClock, ENABLE);
    /* Configure the GPIO LED pin */
    GPIO_InitStructure.GPIO_Pin = mPin;
    GPIO_Init(mPort, &GPIO_InitStructure);
}

void Led::enable(bool enable) const
{
    if (enable)
    {
        mPort->BSRR = mPin;   // Set bit in register.
    }
    else
    {
        mPort->BRR = mPin;    // Clear bit in register.
    }
}

void Led::toggle() const
{
    // Toggle bit in register.
    mPort->ODR ^= mPin;
}

void Led_static::init(led_enum_t const led_enum)
{
    GPIO_InitTypeDef GPIO_InitStructure;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
    GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
    GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;

    /* Enable the GPIO LED Clock */
    RCC_AHBPeriphClockCmd(led_gpio_clock[static_cast<uint8_t>(led_enum)], ENABLE);
    /* Configure the GPIO LED pin */
    GPIO_InitStructure.GPIO_Pin = led_gpio_pin[static_cast<uint8_t>(led_enum)];
    GPIO_Init(led_gpio_port[static_cast<uint8_t>(led_enum)], &GPIO_InitStructure);
}

void Led_static::enable(led_enum_t const led_enum, bool enable)
{
    if (enable)
    {
        // Set bit in register.
        led_gpio_port[static_cast<uint8_t>(led_enum)]->BSRR =
            led_gpio_pin[static_cast<uint8_t>(led_enum)];
    }
    else
    {
        // Clear bit in register.
        led_gpio_port[static_cast<uint8_t>(led_enum)]->BRR =
            led_gpio_pin[static_cast<uint8_t>(led_enum)];
    }
}

void Led_static::toggle(led_enum_t const led_enum)
{
    // Toggle bit in register.
    led_gpio_port[static_cast<uint8_t>(led_enum)]->ODR ^=
        led_gpio_pin[static_cast<uint8_t>(led_enum)];
}


