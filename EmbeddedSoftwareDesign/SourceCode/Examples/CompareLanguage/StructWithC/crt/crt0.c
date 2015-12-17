/******************************************************//**
* \file     crt0.h
* \brief    Startup code expressed with C.
* \author   Thomas Zöchbauer
* \version  V1.0
* \date     30-September-2015
**********************************************************/

void crt_init_ram();
void crt_init_ctors();

void __my_startup() __attribute__((used, noinline));

void __my_startup()
{
    // Load the stack pointer.
    // The stack pointer is automatically loaded from
    // the base position of the interrupt vector table.
    // So we do nothing here.

    // Chip init: Watchdog, port, and oscillator.
    // mcal_cpu_init();

    // Initialize statics from ROM to RAM.
    // Zero-clear default-initialized static RAM.
    crt_init_ram();

    // Call all ctor initializations.
    crt_init_ctors();

    // Call main (and never return).
    __asm__ volatile("bl main");

    // Catch an unexpected return from main.
    for(;;)
    {
        // Replace with a loud error if desired.
        __asm__ volatile("nop");
    }
}
