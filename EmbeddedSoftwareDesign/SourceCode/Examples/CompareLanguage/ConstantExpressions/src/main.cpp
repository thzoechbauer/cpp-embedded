/******************************************************//**
* \file     main.cpp
* \brief    The Main Program.
* \author   Thomas Zöchbauer
* \version  V1.0
* \date     26-November-2015
**********************************************************/

#include <cstdint>

#include "macro.h"
#include "const.h"
#include "constexpr.h"

#define ENABLE_BY_MACRO
#define ENABLE_BY_CONST
#define ENABLE_BY_CONSTEXPR

std::int32_t foo()
{
    return static_cast<std::int32_t>(10);
}

std::int32_t foo2()
{
    return static_cast<std::int32_t>(20);
}

constexpr std::int32_t constexpr_foo()
{
    return static_cast<std::int32_t>(10);
}

int main()
{
    std::uint32_t a = 20;
    a = 30; // valid, a is not constant.

    const std::uint32_t c = 500;
    //c = 3; // error: assignment of read-only variable 'c'.

    constexpr std::uint32_t cexpr = 1000;
    //cexpr = 7; // error: assignment of read-only variable 'cexpr'.

    #define C static_cast<std::uint32_t>(123)
    //C = 100; // error: lvalue required as left operand of assignment.

    // ----------------------------------------------------
    // #define:
    std::uint32_t value = C;    // value = 123;
    #define C static_cast<std::uint32_t>(456)   // warning: "C" redefined.
    value = C;  // value = 456;
    #define C "this is a test"                    // warning: "C" redefined.
    //value = C;  // error: invalid conversion from 'const char*' to
                // 'uint32_t {aka long unsigned int}' [-fpermissive].

    // ----------------------------------------------------
    // const:
    std::int8_t c1 = 14;    // known at compile time.
    const std::int32_t cfoo = foo(); // calculated constant.
    //c1 = 5; // error: assignment of read-only variable 'c1'.
    //cfoo = foo2(); // error: assignment of read-only variable 'cfoo'.

    //std::int8_t c1 = 15; // error: redeclaration of 'int8_t c1'.

    using std::uint8_t;
    int8_t val = 20;
    int8_t b = 100;
    int8_t const * pcval = &val; // pointer to constant int8_t.
    int8_t * const cpval = &val; // constant pointer to int8_t.
    int8_t const * const cpcval = &val; // constant pointer to constant int8_t.
    val = 30;   // valid, val is not constant.

    //*pcval = 40; // error: assignment of read-only location '* pcval'.
    pcval = &b;  // valid, pointer is not constant.

    *cpval = 50; // valid, value of cpval is not constant.
    //cpval = &b; // error: assignment of read-only variable 'cpval'.

    //*cpcval = 60; // error: assignment of read-only location '*(const int8_t*)cpcval'.
    //cpcval = &b; // error: assignment of read-only variable 'cpcval'.

    // ----------------------------------------------------
    // #constexpr:
    //int8_t val = 20;
    int8_t const cval = 30;
    constexpr int8_t cexpr1 = 100;
    constexpr int8_t cexpr2 = cexpr1;
    //constexpr int8_t cexpr1 = 200;  // error: redeclaration of 'constexpr const int8_t cexpr1'.
    //constexpr int8_t cexpr_val = val; // error: the value of 'val' is not usable in a constant expression.
    constexpr int8_t cexpr_cval = cval;
    //constexpr int8_t cexpr_foo1 = foo(); // error: call to non-constexpr function 'int32_t foo()'.
    constexpr int8_t cepxr_foo2 = constexpr_foo();

    //constexpr int8_t * pcexpr_val = &val; // error: '& val' is not a constant expression.
    constexpr int8_t * pcexpr = reinterpret_cast<int8_t*>(0xA0);
    //*pcexpr = val; // valid.
    //pcexpr = reinterpret_cast<int8_t*>(0xB0); // error: assignment of read-only variable 'pcexpr'.


    /*******************************************************
    /* Demo:
    /* User-Button is connected to GPIOA.0.
    /* Enable GPIOA Clock and read input value of GPIOA.0.
    *******************************************************/

    volatile bool macro_pressed = false;
    volatile bool const_pressed = false;
    volatile bool constexpr_pressed = false;

    #ifdef ENABLE_BY_MACRO
    macro_enable_gpioa();
    #endif

    #ifdef ENABLE_BY_CONST
    use_const::enable_gpioa();
    #endif

    #ifdef ENABLE_BY_CONSTEXPR
    use_constexpr::enable_gpioa();
    #endif

    while(1)
    {
        if (macro_is_pressed())
            if (use_const::is_pressed())
                if (use_constexpr::is_pressed())
                    __asm__ volatile("nop");

        __asm__ volatile("nop");
        //counter++;
    }
}
