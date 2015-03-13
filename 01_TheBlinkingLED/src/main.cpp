/********************************************//**
 *  \brief     The Blinking LED expample with
 *             C++ template experiment.
 *  \author    Tom
 *  \version   V1.0
 *  \date      12-February-2015
 ***********************************************/

#include <cstdint>

#include "stm32f30x_conf.h"

#define LED6_PIN            GPIO_Pin_15
#define LED6_GPIO_PORT      GPIOE
#define LED6_GPIO_CLK       RCC_AHBPeriph_GPIOE

void led_init_gpio()
{
    ///< Init Peripheral Clock.
    RCC_AHBPeriphClockCmd(LED6_GPIO_CLK, ENABLE);

    ///< Init GPIO for LED6
    GPIO_InitTypeDef init_struct;
    init_struct.GPIO_Mode = GPIO_Mode_OUT;
    init_struct.GPIO_OType = GPIO_OType_PP;
    init_struct.GPIO_Pin = LED6_PIN;
    init_struct.GPIO_PuPd = GPIO_PuPd_NOPULL;
    init_struct.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(LED6_GPIO_PORT, &init_struct);
}

void led_set()
{
    GPIO_SetBits(LED6_GPIO_PORT, LED6_PIN);
}

void led_clear()
{
    GPIO_ResetBits(LED6_GPIO_PORT, LED6_PIN);
}

void led_toggle()
{
    uint16_t data = GPIO_ReadOutputData(LED6_GPIO_PORT);
    GPIO_Write(LED6_GPIO_PORT, data^LED6_PIN);
}

template<std::uint32_t N>
struct delay_type
{
    void wait()
    {
        for (std::uint32_t i = 0; i < N; i++)
        {
            __asm__("nop");
        }
    }
};

int main(void)
{
    delay_type<500000U> short_delay;
    delay_type<2000000U> long_delay;

    led_init_gpio();
    led_clear();

    while(1)
    {
        led_set();
        short_delay.wait();     ///< Short LED On state.

        led_clear();
        long_delay.wait();      ///< Long LED Off state.
    }
    return 0;
}
