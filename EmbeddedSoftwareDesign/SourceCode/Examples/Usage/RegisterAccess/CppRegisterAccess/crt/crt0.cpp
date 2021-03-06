/******************************************************//**
* \file     crt0.cpp
* \brief    STM32 EABI ARM(R) Cortex-M4(TM) startup code.
*           Expressed with C++ for STM32F303VC.
* \author   Thomas Z�chbauer
* \version  V1.0
* \date     23-September-2015
*
*           This file is based on Christopher Kormanyos
*           and modified by Thomas Z�chbauer (2015).
**********************************************************/

///////////////////////////////////////////////////////////////////////////////
//  Copyright Christopher Kormanyos 2007 - 2013.
//  Distributed under the Boost Software License,
//  Version 1.0. (See accompanying file LICENSE_1_0.txt
//  or copy at http://www.boost.org/LICENSE_1_0.txt)
//

// STM32 EABI ARM(R) Cortex-M4(TM) startup code.
// Expressed with C++ for STM32F407 by Chris.

namespace crt
{
    void init_ram();
    void init_ctors();
}

void __my_startup() __attribute__((used, noinline));

void __my_startup()
{
    // Load the stack pointer.
    // The stack pointer is automatically loaded from
    // the base position of the interrupt vector table.
    // So we do nothing here.

    // Chip init (e.g. Watchdog, port, and oscillator).
    // mcal::cpu::init();

    // Initialize statics from ROM to RAM.
    // Zero-clear default-initialized static RAM.
    crt::init_ram();

    // Call all ctor initializations.
    crt::init_ctors();

    // Call main (and never return).
    __asm__ volatile("bl main");

    // Catch an unexpected return from main.
    for(;;)
    {
        // Replace with a loud error if desired.
        __asm__ volatile("nop");
    }
}
