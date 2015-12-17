/******************************************************//**
* \file     main.cpp
* \brief    The Main Program.
* \author   Thomas Zöchbauer
* \version  V1.0
* \date     06-December-2015
**********************************************************/

#include <cstdint>
#include <exception>

#define PRINT(x)

void* __dso_handle = nullptr;

#define USE_MY_LOGIC_ERROR_EXCEPTION

#ifdef USE_MY_LOGIC_ERROR_EXCEPTION
    #include "my_stdexcept.h"
    using my_std::logic_error;
#else
    #include <stdexcept>
    using std::logic_error;
#endif // USE_MY_LOGIC_ERROR_EXCEPTION

std::int32_t area(const std::int32_t a, const std::int32_t b)
{
    if (a <= 0 || b <= 0)
    {
        throw logic_error("Parameter equal or less than zero.");
    }

    return a*b;
}

int main()
{
    volatile std::uint32_t counter = 0;
    volatile std::int32_t sum = 0;
    volatile bool le_catched = false;

    try
    {
        std::int32_t A = area(2, 3);
        std::int32_t B = area(-2, 5);
        sum = A+B;
    }
    catch(logic_error &e)
    {
        // Handle thrown logic_error.
        le_catched = true;
    }

    while(1)
    {
        __asm__ volatile("nop");
        counter++;
    }
}
