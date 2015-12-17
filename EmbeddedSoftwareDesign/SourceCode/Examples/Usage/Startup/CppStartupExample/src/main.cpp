/******************************************************//**
* \file     main.cpp
* \brief    C++ Starup Example.
* \author   Thomas Zöchbauer
* \version  V1.0
* \date     23-September-2015
**********************************************************/

#include <cstdint>

#include "mcal_cpu.h"

// Rom-to-Ram data (*.data).
bool is_spi_init = false;
bool is_uart_init = false;

// Filled with zero data (*.bss).
uint32_t bss1;
uint32_t bss2;
uint32_t bss3 = 0;

// Define Classes to demonstrate .init_array.
class peripheral_t
{
protected:
    bool is_init = false;
public:
    peripheral_t() {}
    virtual ~peripheral_t() {}
};

// Derive uart and spi classes from peripheral.
class uart_t : peripheral_t
{
public:
    uart_t() { is_init = true; }
};

class spi_t : peripheral_t
{
public:
    spi_t() { is_init = true; }
};

// Define global objects of uart_t and spi_t to
// demonstrate call of ctors:
uart_t uart1;
spi_t spi1;

int main()
{
    volatile std::uint32_t counter = 0;

    while(1)
    {
        mcal::cpu::nop();
        counter++;
    }
}
