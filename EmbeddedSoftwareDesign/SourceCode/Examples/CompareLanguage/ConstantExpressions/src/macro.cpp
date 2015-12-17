#include "macro.h"

void macro_enable_gpioa()
{
    *reinterpret_cast<volatile std::uint32_t*>(RCC_BASE+RCC_AHBENR_OFFSET) |= RCC_AHBENR_GPIOAEN;
}

bool macro_is_pressed()
{
    volatile std::uint32_t* pGPIOA_IDR = reinterpret_cast<std::uint32_t*>(GPIOA_BASE+GPIO_IDR_OFFSET);
    return (*pGPIOA_IDR & GPIO_IDR_0);
}
