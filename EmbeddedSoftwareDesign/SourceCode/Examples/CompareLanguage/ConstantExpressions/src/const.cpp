#include "const.h"

namespace use_const
{
    const std::uint32_t periph_base = 0x40000000;
    // ...
    const std::uint32_t ahb2periph_base = periph_base + 0x08000000;
    const std::uint32_t ahb1periph_base = periph_base + 0x00020000;
    const std::uint32_t rcc_base = ahb1periph_base + 0x00001000;
    // ...
    const std::uint32_t gpioa_base = ahb2periph_base + 0x0000;
    // ...
    const std::uint32_t rcc_ahbenr_offset = 0x00000014;
    const std::uint32_t rcc_ahbenr_gpioaen = 0x00020000;
    // ...
    const std::uint32_t gpio_idr_offset = 0x00000010;
    const std::uint32_t gpio_idr_0      = 0x00000001;
}

void use_const::enable_gpioa()
{
    // Enable GPIOA Clock:
     *reinterpret_cast<volatile std::uint32_t*>(rcc_base+rcc_ahbenr_offset) |= rcc_ahbenr_gpioaen;
}

bool use_const::is_pressed()
{
    volatile std::uint32_t* pgpioa_idr = reinterpret_cast<std::uint32_t*>(gpioa_base+gpio_idr_offset);
    return (*pgpioa_idr & gpio_idr_0);
}
