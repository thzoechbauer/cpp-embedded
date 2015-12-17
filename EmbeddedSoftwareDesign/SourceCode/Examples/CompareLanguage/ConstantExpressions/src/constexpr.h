#ifndef CONSTEXPR_H_INCLUDED
#define CONSTEXPR_H_INCLUDED

#include <cstdint>

namespace use_constexpr
{
    constexpr std::uint32_t periph_base = 0x40000000;
    // ...
    constexpr std::uint32_t ahb2periph_base = periph_base + 0x08000000;
    constexpr std::uint32_t ahb1periph_base = periph_base + 0x00020000;
    constexpr std::uint32_t rcc_base = ahb1periph_base + 0x00001000;
    // ...
    constexpr std::uint32_t gpioa_base = ahb2periph_base + 0x0000;
    // ...
    constexpr std::uint32_t rcc_ahbenr_offset = 0x00000014;
    constexpr std::uint32_t rcc_ahbenr_gpioaen = 0x00020000;
    // ...
    constexpr std::uint32_t gpio_idr_offset = 0x00000010;
    constexpr std::uint32_t gpio_idr_0      = 0x00000001;

    void enable_gpioa();
    bool is_pressed();
}

#endif // CONSTEXPR_H_INCLUDED
