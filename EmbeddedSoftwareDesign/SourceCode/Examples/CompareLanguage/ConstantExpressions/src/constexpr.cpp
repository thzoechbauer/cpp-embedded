#include "constexpr.h"

void use_constexpr::enable_gpioa()
{
    // Enable GPIOA Clock:
    *reinterpret_cast<volatile std::uint32_t*>(rcc_base+rcc_ahbenr_offset) |= rcc_ahbenr_gpioaen;
}

bool use_constexpr::is_pressed()
{
    volatile std::uint32_t* pgpioa_idr = reinterpret_cast<std::uint32_t*>(gpioa_base+gpio_idr_offset);
    return (*pgpioa_idr & gpio_idr_0);
}
