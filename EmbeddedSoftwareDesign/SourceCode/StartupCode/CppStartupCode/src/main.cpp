/******************************************************//**
* \file     main.cpp
* \brief    The Main Program (CppStartupCode).
* \author   Thomas Zöchbauer
* \version  V1.0
* \date     23-September-2015
**********************************************************/

//#include <cstdint>

int main()
{
    //volatile std::uint32_t counter = 0;
    while(1)
    {
        __asm__ volatile("nop");
        //counter++;
    }
}
