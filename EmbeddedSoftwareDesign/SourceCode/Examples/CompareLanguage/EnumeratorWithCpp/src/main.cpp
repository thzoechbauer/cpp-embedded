/******************************************************//**
* \file     main.cpp
* \brief    The Main Program.
* \author   Thomas Zöchbauer
* \version  V1.0
* \date     01-August-2015
**********************************************************/

#include <cstdint>
#include <type_traits>

#include "stm32f30x_conf.h"
#include "stm32f3_discovery_systick.h"

#include "stm32f30x_rcc.h"
#include "spl_gpio_stm32f30x.h"


// Unscoped, forward declared and type specified enumerator:
enum Speed : std::uint8_t;
// Scoped, forward declared and type specified enumerator:
enum class OType : std::uint8_t;


// Definition of Mode enumeration:
enum Mode : std::uint8_t
{
	IN   = 0x00, // Input Mode
	OUT  = 0x01, // Output Mode
	AF   = 0x02, // Alternate function Mode
	AN   = 0x03  // Analog In/Out Mode
	//, TEST = 0xFFFF
};

// Definition of scoped Pull-Up and Pull-Down enumeration:
enum class PuPd : std::uint8_t
{
    NOPULL = 0x00,
    UP     = 0x01,
    DOWN   = 0x02,
    OUT           // valid because of own scope.
};

void DoIt()
{
    //
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

    /* ----------------------------------------------- */
    /* "Normal" Enumerator Usage */

    // Usage of Mode enumeration:
    Mode mode0 = IN;        // Same as in C.
    //Mode mode1 = 0x01;    // Not valid in C++.
    Mode mode1 = static_cast<Mode>(0x01);   // Valid cast.

    int tmp = 0;
    if (mode0 < 1.3f)
    {
        tmp = 1;
    }

    Mode mode_int = static_cast<Mode>(123);			// Invalid Mode.
    Mode mode_char = static_cast<Mode>('a');		// Invalid Mode.
    Mode mode_bool = static_cast<Mode>(true);		// Cast to OUT.
    Mode mode_float = static_cast<Mode>(2.123f);	// Cast to AF.

    /* ----------------------------------------------- */
    /* "Scoped" Enumerator Usage */

    // Usage of scoped PuPd enumerator:
    //PuPd pp0 = NOPULL;	    // Invalid, 'NOPULL' was not declared in this scope.
    PuPd pp1 = PuPd::NOPULL;    // Valid usage!

//    enum Mode mode3 = 0x03;    // Same as AN.
//
//    int mode_var = OUT;         // Same as 0x01.
//    enum Mode mode4 = mode_var; // Same as OUT.
//
//    enum Mode mode5 = 0x0A;     // Not a valid Mode.
//
      /* ----------------------------------------------- */
      /* "Mixed" Enumerator Usage */
//
//    enum Mode mode6 = NOPULL;   // Mode variable gets a PuPd value.
//    enum PuPd pupd0 = OUT;      // PuPd variable gets a Mode value.
//
      /* ----------------------------------------------- */
      /* Variable Names: */
//
//    int OUT = DOWN;         // OUT == 2
//    enum Mode mode = OUT;   // mode ?= OUT or AF.

    /* ----------------------------------------------- */
    /* Check underlaying type of Enums: */
    using PuPd_type = std::underlying_type<PuPd>::type;
    PuPd_type var = static_cast<PuPd_type>(PuPd::UP); // Declare variable with underlying type of PuPd.

    // Comment in to provoke assertion!
    //static_assert(std::is_same<PuPd_type, std::uint8_t>::value, "Underlying type of PuPd is not std::uint8_t.");
    //static_assert(!std::is_same<PuPd_type, std::uint8_t>::value, "Underlying type of PuPd is std::uint8_t.");

    //static_assert(std::is_same<PuPd_type, std::uint16_t>::value, "Underlying type of PuPd is not std::uint16_t.");
    //static_assert(std::is_same<PuPd_type, std::uint32_t>::value, "Underlying type of PuPd is not std::uint32_t.");
    //static_assert(std::is_same<PuPd_type, int>::value, "Underlying type of PuPd is int.");

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
