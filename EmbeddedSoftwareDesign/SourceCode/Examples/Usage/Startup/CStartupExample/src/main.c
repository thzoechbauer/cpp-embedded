/******************************************************//**
* \file     main.c
* \brief    C Startup Example.
* \author   Thomas Zöchbauer
* \version  V1.0
* \date     21-September-2015
**********************************************************/

#include <stdint.h>
#include <stdbool.h>
#include "mcal_cpu.h"

// Rom-to-Ram data (*.data).
bool is_spi_init = false;
bool is_uart_init = false;

// Filled with zero data (*.COMMON).
uint32_t bss1;
uint32_t bss2;
// Filled with zero data (*.bss).
uint32_t bss3 = 0;

// Initializing constructors.
void init_uart() __attribute ((constructor(110)));
void init_spi() __attribute ((constructor(120)));

void init_uart()
{
    is_uart_init = true;
}

void init_spi()
{
    is_spi_init = true;
}

int main(void)
{
    volatile uint32_t counter = 0;

    while(1)
    {
        mcal_cpu_nop();
        counter++;
    }
}
