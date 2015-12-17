/******************************************************//**
* \file     main.c
* \brief    The Main Program (AsmStartupCode).
* \author   Thomas Zöchbauer
* \version  V1.0
* \date     21-September-2015
**********************************************************/

//#include <stdint.h>

int main(void)
{
    //volatile uint32_t counter = 0;
    while(1)
    {
        __asm__ volatile("nop");
        //counter++;
    }
}
