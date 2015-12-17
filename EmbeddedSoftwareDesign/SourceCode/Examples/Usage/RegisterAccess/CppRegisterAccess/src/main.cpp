/******************************************************//**
* \file     main.cpp
* \brief    The Main Program.
* \author   Thomas Zöchbauer
* \version  V1.0
* \date     13-November-2015
**********************************************************/

#include <cstdint>
#include "mcal_rcc.h"
#include "mcal_gpio.h"
#include "mcal_reg.h"

//#define USE_LOCAL_VARIABLE_DEFINITION
#define USE_VALUE_OF_UNION
//#define RESET_GPIO_VALUES       // Use this in combination with USE_VALUE_OF_UNION.

constexpr mcal::reg::BitPos_t BITPOS_LED                   = mcal::reg::BitPos_t::BitPos_9;    // GPIOE.9 is connected to LED3.
constexpr mcal::reg::value_t  PIN_LED_MODE_OUT_bm          = static_cast<mcal::reg::value_t>(mcal::gpio::Mode_t::OUT) << static_cast<mcal::reg::value_t>(BITPOS_LED)*2;
constexpr mcal::reg::value_t  PIN_LED_OTYPE_PUSH_PULL_bm   = static_cast<mcal::reg::value_t>(mcal::gpio::OType_t::PUSH_PULL) << static_cast<mcal::reg::value_t>(BITPOS_LED);
constexpr mcal::reg::value_t  PIN_LED_OSPEED_HIGH_SPEED_bm = static_cast<mcal::reg::value_t>(mcal::gpio::OSpeed_t::HIGH_SPEED) << static_cast<mcal::reg::value_t>(BITPOS_LED)*2;
constexpr mcal::reg::value_t  PIN_LED_PUPD_PULL_UP_bm      = static_cast<mcal::reg::value_t>(mcal::gpio::PuPd_t::PULL_UP) << static_cast<mcal::reg::value_t>(BITPOS_LED)*2;
constexpr mcal::reg::value_t  PIN_LED_ODR_bm               = static_cast<mcal::reg::value_t>(0x01) << static_cast<mcal::reg::value_t>(BITPOS_LED);

constexpr mcal::reg::value_t  PIN_LED_32_2_bm             = static_cast<mcal::reg::value_t>(0x03) << static_cast<mcal::reg::value_t>(BITPOS_LED)*2;

#ifndef USE_LOCAL_VARIABLE_DEFINITION
    // If USE_LOCAL_VARIABLE_DEFINITION is not defined, use global variable definition:

    // Global variables for direct_register_access():
    constexpr volatile mcal::reg::value_t* prcc_ahbenr =    reinterpret_cast<mcal::reg::value_t*>(mcal::reg::RCC_BASE + mcal::rcc::AHBENR_OFFSET);
    constexpr volatile mcal::reg::value_t* pgpioe_moder =   reinterpret_cast<mcal::reg::value_t*>(mcal::reg::GPIOE_BASE + mcal::gpio::MODER_OFFSET);
    constexpr volatile mcal::reg::value_t* pgpioe_otyper =  reinterpret_cast<mcal::reg::value_t*>(mcal::reg::GPIOE_BASE + mcal::gpio::OTYPER_OFFSET);
    constexpr volatile mcal::reg::value_t* pgpioe_ospeedr = reinterpret_cast<mcal::reg::value_t*>(mcal::reg::GPIOE_BASE + mcal::gpio::OSPEEDR_OFFSET);
    constexpr volatile mcal::reg::value_t* pgpioe_pupdr =   reinterpret_cast<mcal::reg::value_t*>(mcal::reg::GPIOE_BASE + mcal::gpio::PUPDR_OFFSET);
    constexpr volatile mcal::reg::value_t* pgpioe_odr =     reinterpret_cast<mcal::reg::value_t*>(mcal::reg::GPIOE_BASE + mcal::gpio::ODR_OFFSET);

    // Global variables for regmap_register_access():
    constexpr mcal::rcc::AHBENR_RegMap_t* pahbenr_regmap =          reinterpret_cast<mcal::rcc::AHBENR_RegMap_t*>(mcal::reg::RCC_BASE + mcal::rcc::AHBENR_OFFSET);
    constexpr mcal::gpio::MODER_RegMap_t* pgpioe_moder_regmap =     reinterpret_cast<mcal::gpio::MODER_RegMap_t*>(mcal::reg::GPIOE_BASE + mcal::gpio::MODER_OFFSET);
    constexpr mcal::gpio::OTYPER_RegMap_t* pgpioe_otyper_regmap =   reinterpret_cast<mcal::gpio::OTYPER_RegMap_t*>(mcal::reg::GPIOE_BASE + mcal::gpio::OTYPER_OFFSET);
    constexpr mcal::gpio::OSPEEDR_RegMap_t* pgpioe_ospeedr_regmap = reinterpret_cast<mcal::gpio::OSPEEDR_RegMap_t*>(mcal::reg::GPIOE_BASE + mcal::gpio::OSPEEDR_OFFSET);
    constexpr mcal::gpio::PUPDR_RegMap_t* pgpioe_pupd_regmap =      reinterpret_cast<mcal::gpio::PUPDR_RegMap_t*>(mcal::reg::GPIOE_BASE + mcal::gpio::PUPDR_OFFSET);
    constexpr mcal::gpio::ODR_RegMap_t* pgpioe_odr_regmap =         reinterpret_cast<mcal::gpio::ODR_RegMap_t*>(mcal::reg::GPIOE_BASE + mcal::gpio::ODR_OFFSET);

    // Global variables for union_register_access():
    constexpr mcal::rcc::AHBENR_Reg_t* prcc_reg =             reinterpret_cast<mcal::rcc::AHBENR_Reg_t*>(mcal::reg::RCC_BASE + mcal::rcc::AHBENR_OFFSET);
    constexpr mcal::gpio::MODER_Reg_t* pgpioe_moder_reg =     reinterpret_cast<mcal::gpio::MODER_Reg_t*>(mcal::reg::GPIOE_BASE + mcal::gpio::MODER_OFFSET);
    constexpr mcal::gpio::OTYPER_Reg_t* pgpioe_otyper_reg =   reinterpret_cast<mcal::gpio::OTYPER_Reg_t*>(mcal::reg::GPIOE_BASE + mcal::gpio::OTYPER_OFFSET);
    constexpr mcal::gpio::OSPEEDR_Reg_t* pgpioe_ospeedr_reg = reinterpret_cast<mcal::gpio::OSPEEDR_Reg_t*>(mcal::reg::GPIOE_BASE + mcal::gpio::OSPEEDR_OFFSET);
    constexpr mcal::gpio::PUPDR_Reg_t* pgpioe_pupd_reg =      reinterpret_cast<mcal::gpio::PUPDR_Reg_t*>(mcal::reg::GPIOE_BASE + mcal::gpio::PUPDR_OFFSET);
    constexpr mcal::gpio::ODR_Reg_t* pgpioe_odr_reg =         reinterpret_cast<mcal::gpio::ODR_Reg_t*>(mcal::reg::GPIOE_BASE + mcal::gpio::ODR_OFFSET);

    // Global variables for struct_register_access():
    constexpr mcal::rcc::RCC_t* prcc =     reinterpret_cast<mcal::rcc::RCC_t*>(mcal::reg::RCC_BASE);
    constexpr mcal::gpio::GPIO_t* pgpioe = reinterpret_cast<mcal::gpio::GPIO_t*>(mcal::reg::GPIOE_BASE);
#endif  // !USE_LOCAL_VARIABLE_DEFINITION

// Function prototypes for register access:
void direct_register_access();
void regmap_register_access();
void union_register_access();
void struct_register_access();


void direct_register_access()
{
    // start direct
#ifdef USE_LOCAL_VARIABLE_DEFINITION
    // RCC AHB Enable Register:
    constexpr volatile mcal::reg::value_t* prcc_ahbenr =    reinterpret_cast<mcal::reg::value_t*>(mcal::reg::RCC_BASE + mcal::rcc::AHBENR_OFFSET);
    // GPIOE Register:
    constexpr volatile mcal::reg::value_t* pgpioe_moder =   reinterpret_cast<mcal::reg::value_t*>(mcal::reg::GPIOE_BASE + mcal::gpio::MODER_OFFSET);
    constexpr volatile mcal::reg::value_t* pgpioe_otyper =  reinterpret_cast<mcal::reg::value_t*>(mcal::reg::GPIOE_BASE + mcal::gpio::OTYPER_OFFSET);
    constexpr volatile mcal::reg::value_t* pgpioe_ospeedr = reinterpret_cast<mcal::reg::value_t*>(mcal::reg::GPIOE_BASE + mcal::gpio::OSPEEDR_OFFSET);
    constexpr volatile mcal::reg::value_t* pgpioe_pupdr =   reinterpret_cast<mcal::reg::value_t*>(mcal::reg::GPIOE_BASE + mcal::gpio::PUPDR_OFFSET);
    constexpr volatile mcal::reg::value_t* pgpioe_odr =     reinterpret_cast<mcal::reg::value_t*>(mcal::reg::GPIOE_BASE + mcal::gpio::ODR_OFFSET);
#endif // USE_LOCAL_VARIABLE_DEFINITION

#ifdef RESET_GPIO_VALUES
    // Clear GPIO bits before setting new values:
    *pgpioe_moder    &= ~PIN_LED_32_2_bm;
    *pgpioe_ospeedr  &= ~PIN_LED_32_2_bm;
    *pgpioe_pupdr    &= ~PIN_LED_32_2_bm;
#endif // RESET_GPIO_VALUES

    // Enable GPIOE Clock at AHB:
    *prcc_ahbenr    |= mcal::rcc::AHB_GPIOEEN_bm;
    // Configure GPIOE.9:
    *pgpioe_moder   |= PIN_LED_MODE_OUT_bm;
    *pgpioe_otyper  |= PIN_LED_OTYPE_PUSH_PULL_bm;
    *pgpioe_ospeedr |= PIN_LED_OSPEED_HIGH_SPEED_bm;
    *pgpioe_pupdr   |= PIN_LED_PUPD_PULL_UP_bm;

    // Toggle Output at GPIOE.9:
    *pgpioe_odr ^= PIN_LED_ODR_bm;
    // end direct
}

void regmap_register_access()
{
#ifdef USE_LOCAL_VARIABLE_DEFINITION
    // RCC AHB Enable Register Map:
    constexpr mcal::rcc::AHBENR_RegMap_t* pahbenr_regmap =          reinterpret_cast<mcal::rcc::AHBENR_RegMap_t*>(mcal::reg::RCC_BASE + mcal::rcc::AHBENR_OFFSET);
    // GPIOE Register Maps:
    constexpr mcal::gpio::MODER_RegMap_t* pgpioe_moder_regmap =     reinterpret_cast<mcal::gpio::MODER_RegMap_t*>(mcal::reg::GPIOE_BASE + mcal::gpio::MODER_OFFSET);
    constexpr mcal::gpio::OTYPER_RegMap_t* pgpioe_otyper_regmap =   reinterpret_cast<mcal::gpio::OTYPER_RegMap_t*>(mcal::reg::GPIOE_BASE + mcal::gpio::OTYPER_OFFSET);
    constexpr mcal::gpio::OSPEEDR_RegMap_t* pgpioe_ospeedr_regmap = reinterpret_cast<mcal::gpio::OSPEEDR_RegMap_t*>(mcal::reg::GPIOE_BASE + mcal::gpio::OSPEEDR_OFFSET);
    constexpr mcal::gpio::PUPDR_RegMap_t* pgpioe_pupd_regmap =      reinterpret_cast<mcal::gpio::PUPDR_RegMap_t*>(mcal::reg::GPIOE_BASE + mcal::gpio::PUPDR_OFFSET);
    constexpr mcal::gpio::ODR_RegMap_t* pgpioe_odr_regmap =         reinterpret_cast<mcal::gpio::ODR_RegMap_t*>(mcal::reg::GPIOE_BASE + mcal::gpio::ODR_OFFSET);
#endif // USE_LOCAL_VARIABLE_DEFINITION

    // Enable GPIOE Clock at AHB:
    pahbenr_regmap->IOPEEN = 1;
    // Configure GPIOE.9:
    pgpioe_moder_regmap->val9 =   static_cast<mcal::reg::value_t>(mcal::gpio::Mode_t::OUT);
    pgpioe_otyper_regmap->val9 =  static_cast<mcal::reg::value_t>(mcal::gpio::OType_t::PUSH_PULL);
    pgpioe_ospeedr_regmap->val9 = static_cast<mcal::reg::value_t>(mcal::gpio::OSpeed_t::HIGH_SPEED);
    pgpioe_pupd_regmap->val9 =    static_cast<mcal::reg::value_t>(mcal::gpio::PuPd_t::PULL_UP);
    // Toggle Output at GPIOE.9:
    pgpioe_odr_regmap->val9 ^= 0x01;
}

void union_register_access()
{
#ifdef USE_LOCAL_VARIABLE_DEFINITION
    // RCC AHB Enable Register Map as Union:
    constexpr mcal::rcc::AHBENR_Reg_t* prcc_reg =             reinterpret_cast<mcal::rcc::AHBENR_Reg_t*>(mcal::reg::RCC_BASE + mcal::rcc::AHBENR_OFFSET);
    // GPIOE Register Maps as Union:
    constexpr mcal::gpio::MODER_Reg_t* pgpioe_moder_reg =     reinterpret_cast<mcal::gpio::MODER_Reg_t*>(mcal::reg::GPIOE_BASE + mcal::gpio::MODER_OFFSET);
    constexpr mcal::gpio::OTYPER_Reg_t* pgpioe_otyper_reg =   reinterpret_cast<mcal::gpio::OTYPER_Reg_t*>(mcal::reg::GPIOE_BASE + mcal::gpio::OTYPER_OFFSET);
    constexpr mcal::gpio::OSPEEDR_Reg_t* pgpioe_ospeedr_reg = reinterpret_cast<mcal::gpio::OSPEEDR_Reg_t*>(mcal::reg::GPIOE_BASE + mcal::gpio::OSPEEDR_OFFSET);
    constexpr mcal::gpio::PUPDR_Reg_t* pgpioe_pupd_reg =      reinterpret_cast<mcal::gpio::PUPDR_Reg_t*>(mcal::reg::GPIOE_BASE + mcal::gpio::PUPDR_OFFSET);
    constexpr mcal::gpio::ODR_Reg_t* pgpioe_odr_reg =         reinterpret_cast<mcal::gpio::ODR_Reg_t*>(mcal::reg::GPIOE_BASE + mcal::gpio::ODR_OFFSET);
#endif // USE_LOCAL_VARIABLE_DEFINITION

#ifdef USE_VALUE_OF_UNION
    #ifdef RESET_GPIO_VALUES
    // Clear GPIO bits before setting new values:
    pgpioe_moder_reg->value     &= ~PIN_LED_32_2_bm;
    pgpioe_ospeedr_reg->value   &= ~PIN_LED_32_2_bm;
    pgpioe_pupd_reg->value      &= ~PIN_LED_32_2_bm;
    #endif // RESET_GPIO_VALUES

    // Enable GPIOE Clock at AHB:
    prcc_reg->value |= mcal::rcc::AHB_GPIOEEN_bm;
    // Configure GPIOE.9:
    pgpioe_moder_reg->value     |= PIN_LED_MODE_OUT_bm;
    pgpioe_otyper_reg->value    |= PIN_LED_OTYPE_PUSH_PULL_bm;
    pgpioe_ospeedr_reg->value   |= PIN_LED_OSPEED_HIGH_SPEED_bm;
    pgpioe_pupd_reg->value      |= PIN_LED_PUPD_PULL_UP_bm;
    // Toggle Output at GPIOE.9:
    pgpioe_odr_reg->value       ^= PIN_LED_ODR_bm;
#else
    // Enable GPIOE Clock at AHB:
    prcc_reg->regmap.IOPEEN = 1;
    // Configure GPIOE.9:
    pgpioe_moder_reg->regmap.val9 =   static_cast<mcal::reg::value_t>(mcal::gpio::Mode_t::OUT);
    pgpioe_otyper_reg->regmap.val9 =  static_cast<mcal::reg::value_t>(mcal::gpio::OType_t::PUSH_PULL);
    pgpioe_ospeedr_reg->regmap.val9 = static_cast<mcal::reg::value_t>(mcal::gpio::OSpeed_t::HIGH_SPEED);
    pgpioe_pupd_reg->regmap.val9 =    static_cast<mcal::reg::value_t>(mcal::gpio::PuPd_t::PULL_UP);
    // Toggle Output at GPIOE.9:
    pgpioe_odr_reg->regmap.val9 ^= 0x01;
#endif
}

void struct_register_access()
{
#ifdef USE_LOCAL_VARIABLE_DEFINITION
    // RCC Peripheral as sturcture (of unions):
    constexpr mcal::rcc::RCC_t* prcc =     reinterpret_cast<mcal::rcc::RCC_t*>(mcal::reg::RCC_BASE);
    // GPIOE Peripheral as structure (of unions):
    constexpr mcal::gpio::GPIO_t* pgpioe = reinterpret_cast<mcal::gpio::GPIO_t*>(mcal::reg::GPIOE_BASE);
#endif // USE_LOCAL_VARIABLE_DEFINITION

#ifdef USE_VALUE_OF_UNION
    #ifdef RESET_GPIO_VALUES
    // Clear GPIO bits before setting new values:
    pgpioe->MODER.value     &= ~PIN_LED_32_2_bm;
    pgpioe->OSPEEDR.value   &= ~PIN_LED_32_2_bm;
    pgpioe->PUPDR.value     &= ~PIN_LED_32_2_bm;
    #endif // RESET_GPIO_VALUES

    // Enable GPIOE Clock at AHB:
    prcc->AHBENR.value |= mcal::rcc::AHB_GPIOEEN_bm;
    // Configure GPIOE.9:
    pgpioe->MODER.value     |= PIN_LED_MODE_OUT_bm;
    pgpioe->OTYPER.value    |= PIN_LED_OTYPE_PUSH_PULL_bm;
    pgpioe->OSPEEDR.value   |= PIN_LED_OSPEED_HIGH_SPEED_bm;
    pgpioe->PUPDR.value     |= PIN_LED_PUPD_PULL_UP_bm;
    // Toggle Output at GPIOE.9:
    pgpioe->ODR.value ^= PIN_LED_ODR_bm;
#else
    // Enable GPIOE Clock at AHB:
    prcc->AHBENR.regmap.IOPEEN = 1;
    // Configure GPIOE.9:
    pgpioe->MODER.regmap.val9 =   static_cast<mcal::reg::value_t>(mcal::gpio::Mode_t::OUT);
    pgpioe->OTYPER.regmap.val9 =  static_cast<mcal::reg::value_t>(mcal::gpio::OType_t::PUSH_PULL);
    pgpioe->OSPEEDR.regmap.val9 = static_cast<mcal::reg::value_t>(mcal::gpio::OSpeed_t::HIGH_SPEED);
    pgpioe->PUPDR.regmap.val9 =   static_cast<mcal::reg::value_t>(mcal::gpio::PuPd_t::PULL_UP);
    // Toggle Output at GPIOE.9:
    pgpioe->ODR.regmap.val9 ^= 0x01;
#endif
}

void template_register_access()
{
#ifdef USE_VALUE_OF_UNION
    #ifdef RESET_GPIO_VALUES
    // Clear GPIO bits before setting new values:
    mcal::gpio::MODER_RegExt_t<mcal::reg::GPIOE_BASE>::value()   &= ~PIN_LED_32_2_bm;
    mcal::gpio::OSPEEDR_RegExt_t<mcal::reg::GPIOE_BASE>::value() &= ~PIN_LED_32_2_bm;
    mcal::gpio::PUPDR_RegExt_t<mcal::reg::GPIOE_BASE>::value()   &= ~PIN_LED_32_2_bm;
    #endif // RESET_GPIO_VALUES

    // Enable GPIOE Clock at AHB:
    mcal::rcc::AHBENR_RegExt_t::value() |= mcal::rcc::AHB_GPIOEEN_bm;
    // Configure GPIOE.9:
    mcal::gpio::MODER_RegExt_t<mcal::reg::GPIOE_BASE>::value()   |= PIN_LED_MODE_OUT_bm;
    mcal::gpio::OTYPER_RegExt_t<mcal::reg::GPIOE_BASE>::value()  |= PIN_LED_OTYPE_PUSH_PULL_bm;
    mcal::gpio::OSPEEDR_RegExt_t<mcal::reg::GPIOE_BASE>::value() |= PIN_LED_OSPEED_HIGH_SPEED_bm;
    mcal::gpio::PUPDR_RegExt_t<mcal::reg::GPIOE_BASE>::value()   |= PIN_LED_PUPD_PULL_UP_bm;
    // Toggle Output at GPIOE.9:
    mcal::reg::RegExt32_t<mcal::reg::GPIOE_BASE + mcal::gpio::ODR_OFFSET>::value()       ^= PIN_LED_ODR_bm;
#else
    // Enable GPIOE Clock at AHB:
    mcal::rcc::AHBENR_RegExt_t::regmap().IOPEEN = 1;
    // Configure GPIOE.9:
    mcal::gpio::MODER_RegExt_t<mcal::reg::GPIOE_BASE>::regmap().val9   = static_cast<mcal::reg::value_t>(mcal::gpio::Mode_t::OUT);
    mcal::gpio::OTYPER_RegExt_t<mcal::reg::GPIOE_BASE>::regmap().val9  = static_cast<mcal::reg::value_t>(mcal::gpio::OType_t::PUSH_PULL);
    mcal::gpio::OSPEEDR_RegExt_t<mcal::reg::GPIOE_BASE>::regmap().val9 = static_cast<mcal::reg::value_t>(mcal::gpio::OSpeed_t::HIGH_SPEED);
    mcal::gpio::PUPDR_RegExt_t<mcal::reg::GPIOE_BASE>::regmap().val9   = static_cast<mcal::reg::value_t>(mcal::gpio::PuPd_t::PULL_UP);
    // Toggle Output at GPIOE.9:
    mcal::gpio::ODR_RegExt_t<mcal::reg::GPIOE_BASE>::regmap().val9 ^= 0x01;
#endif
}

int main()
{
    volatile std::uint32_t counter = 0;

    direct_register_access();
    //regmap_register_access();
    //union_register_access();
    //struct_register_access();
    //template_register_access();

#ifdef USE_LOCAL_VARIABLE_DEFINITION
    // GPIOE Peripheral as structure (of unions):
    constexpr mcal::gpio::GPIO_t* pgpioe = reinterpret_cast<mcal::gpio::GPIO_t*>(mcal::reg::GPIOE_BASE);
#endif // USE_LOCAL_VARIABLE_DEFINITION

    while(1)
    {
        if (counter % 0x3FFFF == 0)
        {
            pgpioe->ODR.regmap.val9 ^= 0x01;    // Toggle bit.
        }
        __asm__ volatile("nop");
        counter++;
    }
}
