/******************************************************//**
* \file     mcal_cpu.c
* \brief    MCAL CPU.
* \author   Thomas Zöchbauer
* \version  V1.0
* \date     23-September-2015
**********************************************************/

#include "mcal_cpu.h"

void mcal_cpu_init()
{
    // init cpu.
}

void mcal_cpu_nop()
{
    __asm__ volatile ("nop");
}
