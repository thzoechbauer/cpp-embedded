/******************************************************//**
* \file     main.cpp
* \brief    The Main Program.
* \author   Thomas Zöchbauer
* \version  V1.0
* \date     01-August-2015
**********************************************************/

#include <cstdio>
#include <cstdint>
#include <string>
#include <cstring>
#include <typeinfo>
#include <type_traits>

#include "stm32f30x_conf.h"
#include "stm32f3_discovery_systick.h"

#include "stm32f30x_rcc.h"
#include "spl_gpio_stm32f30x.h"

// Squares value.
int32_t Square(int32_t val)
{
    return val*val;
}

// Deref pointer and square value.
// (Overloads 'int32_t Square(int32_t val)')
int32_t Square(int32_t* ptr)
{
    if (ptr != nullptr)
        return ((*ptr) * (*ptr));
    else
        return 0;
}

int32_t Square(nullptr_t ptr_to_null)
{
	return 0;
}

int main(void)
{
    SystemInit();
    // Init SysTick.
    SystemCoreClockUpdate();
    if (SysTick_Config(SystemCoreClock / 1000) != 0)
    {
        /* Capture error */
        while (1);
    }

    // ----------------------------------------
    // Define variables:
    int32_t value = 12;
    int32_t value_NULL = NULL;
    //int32_t value_nullptr = nullptr; // error: cannot convert 'std::nullptr_t' to 'int32_t {aka long int}' in initialization.

    int32_t* ptr_value = &value;
    int32_t* ptr_null = nullptr;
    int32_t* ptr_NULL = NULL;

    // ----------------------------------------
    // Test function calls:
    int32_t sqare_value = Square(value);        // 144, calls Square(int32_t val).
    int32_t square_value_NULL = Square(value_NULL); // 0, calls Square(int32_t val).
    //int32_t square_value_nullptr = Square(value_nullptr);

    int32_t square_ptr_val = Square(ptr_value);   // 144, calls Square(int32_t* val).
    int32_t square_ptr_null = Square(ptr_null); // 0, calls Square(int32_t* val).
    int32_t square_ptr_NULL = Square(ptr_NULL); // 0, calls Square(int32_t* val).

    int32_t square_nullptr = Square(nullptr);   // 0, calls Square(int32_t* val).
    //int32_t square_NULL = Square(NULL);         // error: call of overloaded 'Square(NULL)' is ambiguous.
    int32_t square_anyval = Square(123);        // 15129, calls Square(int32_t val).

    // ----------------------------------------
    // Check data types:
    bool NULL_is_nullptr = typeid(NULL) == typeid(nullptr);
    bool NULL_is_int = typeid(NULL) == typeid(int(0));

    const char * typeinfo_NULL = typeid(NULL).name();           // typeinfo name for int
    const char * typeinfo_nullptr = typeid(nullptr).name();     // typeinfo name for decltype(nullptr)

    const char * typeinfo_ptrtonull = typeid(ptr_null).name();		// int *

//    const char * typeinfo_value = typeid(value).name();         // typeinfo name for long
//    const char * typeinfo_ptr_val = typeid(ptr_value).name();   // typeinfo name for long*
//
//    const char * typeinfo_int = typeid(int).name();             // typeinfo name for int
//    const char * typeinfo_int32 = typeid(int32_t).name();       // typeinfo name for long
//    const char * typeinfo_int16 = typeid(int16_t).name();       // typeinfo name for short
//    const char * typeinfo_int8 = typeid(int8_t).name();         // typeinfo name for signed char
//    const char * typeinfo_char = typeid(char).name();           // typeinfo name for char
//
//    const char * typeinfo_uint = typeid(unsigned int).name();   // typeinfo name for unsigned int
//    const char * typeinfo_uint32 = typeid(uint32_t).name();     // typeinfo name for unsigned long
//    const char * typeinfo_uint16 = typeid(uint16_t).name();     // typeinfo name for unsigned short
//    const char * typeinfo_uint8 = typeid(uint8_t).name();       // typeinfo name for unsigned char
//    const char * typeinfo_uchar = typeid(unsigned char).name(); // typeinfo name for unsigned char
//
//    const char * typeinfo_float = typeid(float).name();			// typeinfo name for float
//	const char * typeinfo_double = typeid(double).name();		// typeinfo name for double

    // Enable the GPIOE Clock.
    RCC_AHBPeriphClockCmd(RCC_AHBPeriph_GPIOE, ENABLE);

    // Initialize GPIOE.9 as output (pin is connected to LED3):
    spl::gpio::InitTypeDef InitStructure;
    InitStructure.Mode = spl::gpio::Mode_TypeDef::out;
    InitStructure.OType = spl::gpio::OType_TypeDef::pp;
    InitStructure.PuPd = spl::gpio::PuPd_TypeDef::up;
    InitStructure.Speed = spl::gpio::Speed_50MHz;
    InitStructure.Pin = spl::gpio::Pin_9;
    spl::gpio::Init(spl::gpio::gpioe, &InitStructure);

    while(1)
    {
        spl::gpio::SetBits(spl::gpio::gpioe, spl::gpio::Pin_9);
        Delay(500);
        spl::gpio::ResetBits(spl::gpio::gpioe, spl::gpio::Pin_9);
        Delay(200);
    }
}
