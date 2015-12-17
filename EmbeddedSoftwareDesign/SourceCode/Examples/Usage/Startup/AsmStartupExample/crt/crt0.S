/******************************************************//**
* \file     crt0.S
* \brief    Program startup expressed with ASM.
* \author   Thomas Zöchbauer
* \version  V1.0
* \date     30-September-2015
**********************************************************/

    .syntax unified
    .arch armv7-m

    /********************************************************/
    .section .text
    .thumb
    .thumb_func
    .align 2
    .globl    __my_startup
    .type    __my_startup, %function
__my_startup:

    // Chip init: Watchdog, port, and oscillator.
    bl mcal_cpu_init

    // Initialize statics from ROM to RAM.
    // Zero-clear default-initialized static RAM.
    bl _crt_init_ram

    // Call all ctor initializations.
    bl _crt_init_ctors

    // Jump to main.
    bl main
    b .			// Endless loop in case of unexpected return.

    .pool
    .size __my_startup, . - __my_startup
    /********************************************************/

    .end
