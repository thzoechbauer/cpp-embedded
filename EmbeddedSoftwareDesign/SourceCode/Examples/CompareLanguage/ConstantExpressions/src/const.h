#ifndef CONST_H_INCLUDED
#define CONST_H_INCLUDED

#include <cstdint>

namespace use_const
{
    extern const std::uint32_t periph_base;
    // ...
    extern const std::uint32_t ahb2periph_base;
    extern const std::uint32_t ahb1periph_base;
    extern const std::uint32_t rcc_base;
    // ...
    extern const std::uint32_t gpioa_base;
    // ...
    extern const std::uint32_t rcc_ahbenr_offset;
    extern const std::uint32_t rcc_ahbenr_gpioaen;
    // ...
    extern const std::uint32_t gpio_idr_offset;
    extern const std::uint32_t gpio_idr_0;

    void enable_gpioa();
    bool is_pressed();
}

#endif // CONST_H_INCLUDED
