/********************************************//**
 *  \brief     The Blinking LED expample with one way
 *             to access a register via templates.
 *  \author    Tom
 *  \version   V1.0
 *  \date      20-February-2015
 ***********************************************/

#include <cstdint>

#include "led_test.h"

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

    led6::init();
    led7::init();
    led7::on();

    while(1)
    {
//#define TOGGLE
#ifdef TOGGLE
        led6::toggle();
        led7::toggle();
        short_delay.wait();     ///< Short LED On state.
#else
        led6::on();
        led7::off();
        short_delay.wait();     ///< Short LED On state.

        led6::off();
        led7::on();
        long_delay.wait();      ///< Long LED Off state.
#endif // TOGGLE
    }
    return 0;
}
