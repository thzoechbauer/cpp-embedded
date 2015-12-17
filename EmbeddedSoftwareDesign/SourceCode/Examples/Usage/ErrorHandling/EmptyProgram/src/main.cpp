/******************************************************//**
* \file     main.cpp
* \brief    The Main Program.
* \author   Thomas Zöchbauer
* \version  V1.0
* \date     06-December-2015
**********************************************************/

#include <cstdint>

int main()
{
    volatile std::uint32_t counter = 0;
    while(1)
    {
        __asm__ volatile("nop");
        counter++;
    }
}


