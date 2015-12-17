#ifndef MACRO_H_INCLUDED
#define MACRO_H_INCLUDED

#include <cstdint>

// just a few lines with makros of original file "stm32f30x.h"
// ...
#define PERIPH_BASE        static_cast<std::uint32_t>(0x40000000)
// ...
#define AHB2PERIPH_BASE    static_cast<std::uint32_t>(PERIPH_BASE + 0x08000000)
#define AHB1PERIPH_BASE    static_cast<std::uint32_t>(PERIPH_BASE + 0x00020000)
#define RCC_BASE           static_cast<std::uint32_t>(AHB1PERIPH_BASE + 0x00001000)
// ...
#define GPIOA_BASE         static_cast<std::uint32_t>(AHB2PERIPH_BASE + 0x0000)
// ...
#define RCC_AHBENR_OFFSET  static_cast<std::uint32_t>(0x00000014)
#define RCC_AHBENR_GPIOAEN ((uint32_t)0x00020000)
// ...
#define GPIO_IDR_OFFSET    static_cast<std::uint32_t>(0x00000010)
#define GPIO_IDR_0         static_cast<std::uint32_t>(0x00000001)
// ...

void macro_enable_gpioa();
bool macro_is_pressed();

#endif // MACRO_H_INCLUDED
