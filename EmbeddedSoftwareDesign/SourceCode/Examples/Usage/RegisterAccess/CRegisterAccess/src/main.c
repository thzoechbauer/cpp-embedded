/******************************************************//**
* \file     main.c
* \brief    The Main Program.
* \author   Thomas Zöchbauer
* \version  V1.0
* \date     12-November-2015
**********************************************************/

#include <stdint.h>
#include "mcal_rcc.h"
#include "mcal_gpio.h"
#include "mcal_reg.h"

//#define USE_LOCAL_VARIABLE_DEFINITION
#define USE_VALUE_OF_UNION
//#define RESET_GPIO_VALUES       // Use this in combination with USE_VALUE_OF_UNION.

#define BITPOS_LED                    ((uint32_t)BitPos_9)    // GPIOE.9 is connected to LED3.
#define PIN_LED_MODE_OUT_bm           ((uint32_t)OUT << BITPOS_LED*2)
#define PIN_LED_OTYPE_PUSH_PULL_bm    ((uint32_t)PUSH_PULL << BITPOS_LED)
#define PIN_LED_OSPEED_HIGH_SPEED_bm  ((uint32_t)HIGH_SPEED << BITPOS_LED*2)
#define PIN_LED_PUPD_PULL_UP_bm       ((uint32_t)PULL_UP << BITPOS_LED*2)
#define PIN_LED_ODR_bm                ((uint32_t)0x01 << BITPOS_LED)

#define PIN_LED_32_2_bm               ((uint32_t)0x03 << BITPOS_LED*2)

#ifndef USE_LOCAL_VARIABLE_DEFINITION
    // If USE_LOCAL_VARIABLE_DEFINITION is not defined, use global variable definition:

    // Global variables for direct_register_access():
    volatile uint32_t* const prcc_ahbenr =    ((uint32_t*)(RCC_BASE + RCC_AHBENR_OFFSET));
    volatile uint32_t* const pgpioe_moder =   ((uint32_t*)(GPIOE_BASE + GPIO_MODER_OFFSET));
    volatile uint32_t* const pgpioe_otyper =  ((uint32_t*)(GPIOE_BASE + GPIO_OTYPER_OFFSET));
    volatile uint32_t* const pgpioe_ospeedr = ((uint32_t*)(GPIOE_BASE + GPIO_OSPEEDR_OFFSET));
    volatile uint32_t* const pgpioe_pupdr =   ((uint32_t*)(GPIOE_BASE + GPIO_PUPDR_OFFSET));
    volatile uint32_t* const pgpioe_odr =     ((uint32_t*)(GPIOE_BASE + GPIO_ODR_OFFSET));

    // Global variables for regmap_register_access():
    struct AHBENR_RegMap_t* const pahbenr_regmap =       ((struct AHBENR_RegMap_t*)(RCC_BASE + RCC_AHBENR_OFFSET));
    GPIO_MODER_RegMap_t* const pgpioe_moder_regmap =     ((GPIO_MODER_RegMap_t*)(GPIOE_BASE + GPIO_MODER_OFFSET));
    GPIO_OTYPER_RegMap_t* const pgpioe_otyper_regmap =   ((GPIO_OTYPER_RegMap_t*)(GPIOE_BASE + GPIO_OTYPER_OFFSET));
    GPIO_OSPEEDR_RegMap_t* const pgpioe_ospeedr_regmap = ((GPIO_OSPEEDR_RegMap_t*)(GPIOE_BASE + GPIO_OSPEEDR_OFFSET));
    GPIO_PUPDR_RegMap_t* const pgpioe_pupd_regmap =      ((GPIO_PUPDR_RegMap_t*)(GPIOE_BASE + GPIO_PUPDR_OFFSET));
    GPIO_ODR_RegMap_t* const pgpioe_odr_regmap =         ((GPIO_ODR_RegMap_t*)(GPIOE_BASE + GPIO_ODR_OFFSET));

    // Global variables for union_register_access():
    union AHBENR_Reg_t* const prcc_reg =           ((union AHBENR_Reg_t*)(RCC_BASE + RCC_AHBENR_OFFSET));
    GPIO_MODER_Reg_t* const pgpioe_moder_reg =     ((GPIO_MODER_Reg_t*)(GPIOE_BASE + GPIO_MODER_OFFSET));
    GPIO_OTYPER_Reg_t* const pgpioe_otyper_reg =   ((GPIO_OTYPER_Reg_t*)(GPIOE_BASE + GPIO_OTYPER_OFFSET));
    GPIO_OSPEEDR_Reg_t* const pgpioe_ospeedr_reg = ((GPIO_OSPEEDR_Reg_t*)(GPIOE_BASE + GPIO_OSPEEDR_OFFSET));
    GPIO_PUPDR_Reg_t* const pgpioe_pupd_reg =      ((GPIO_PUPDR_Reg_t*)(GPIOE_BASE + GPIO_PUPDR_OFFSET));
    GPIO_ODR_Reg_t* const pgpioe_odr_reg =         ((GPIO_ODR_Reg_t*)(GPIOE_BASE + GPIO_ODR_OFFSET));

    // Global variables for struct_register_access():
    struct RCC_t* const prcc =    ((struct RCC_t*)(RCC_BASE));
    struct GPIO_t* const pgpioe = ((struct GPIO_t*)(GPIOE_BASE));
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
    volatile uint32_t* const prcc_ahbenr =    ((uint32_t*)(RCC_BASE + RCC_AHBENR_OFFSET));
    // GPIOE Register:
    volatile uint32_t* const pgpioe_moder =   ((uint32_t*)(GPIOE_BASE + GPIO_MODER_OFFSET));
    volatile uint32_t* const pgpioe_otyper =  ((uint32_t*)(GPIOE_BASE + GPIO_OTYPER_OFFSET));
    volatile uint32_t* const pgpioe_ospeedr = ((uint32_t*)(GPIOE_BASE + GPIO_OSPEEDR_OFFSET));
    volatile uint32_t* const pgpioe_pupdr =   ((uint32_t*)(GPIOE_BASE + GPIO_PUPDR_OFFSET));
    volatile uint32_t* const pgpioe_odr =     ((uint32_t*)(GPIOE_BASE + GPIO_ODR_OFFSET));
#endif // USE_LOCAL_VARIABLE_DEFINITION

#ifdef RESET_GPIO_VALUES
    // Clear GPIO bits before setting new values:
    *pgpioe_moder    &= ~PIN_LED_32_2_bm;
    *pgpioe_ospeedr  &= ~PIN_LED_32_2_bm;
    *pgpioe_pupdr    &= ~PIN_LED_32_2_bm;
#endif // RESET_GPIO_VALUES

    // Enable GPIOE Clock at AHB:
    *prcc_ahbenr    |= AHB_GPIOEEN_bm;
    // Configure GPIOE.9:
    *pgpioe_moder   |= PIN_LED_MODE_OUT_bm;
    *pgpioe_otyper  |= PIN_LED_OTYPE_PUSH_PULL_bm;
    *pgpioe_ospeedr |= PIN_LED_OSPEED_HIGH_SPEED_bm;
    *pgpioe_pupdr   |= PIN_LED_PUPD_PULL_UP_bm;
    // Toggle Output at GPIOE.9:
    *pgpioe_odr     ^= PIN_LED_ODR_bm;
    // end direct
}

void regmap_register_access()
{
#ifdef USE_LOCAL_VARIABLE_DEFINITION
    // RCC AHB Enable Register Map:
    struct AHBENR_RegMap_t* const pahbenr_regmap =       ((struct AHBENR_RegMap_t*)(RCC_BASE + RCC_AHBENR_OFFSET));
    // GPIOE Register Maps:
    GPIO_MODER_RegMap_t* const pgpioe_moder_regmap =     ((GPIO_MODER_RegMap_t*)(GPIOE_BASE + GPIO_MODER_OFFSET));
    GPIO_OTYPER_RegMap_t* const pgpioe_otyper_regmap =   ((GPIO_OTYPER_RegMap_t*)(GPIOE_BASE + GPIO_OTYPER_OFFSET));
    GPIO_OSPEEDR_RegMap_t* const pgpioe_ospeedr_regmap = ((GPIO_OSPEEDR_RegMap_t*)(GPIOE_BASE + GPIO_OSPEEDR_OFFSET));
    GPIO_PUPDR_RegMap_t* const pgpioe_pupd_regmap =      ((GPIO_PUPDR_RegMap_t*)(GPIOE_BASE + GPIO_PUPDR_OFFSET));
    GPIO_ODR_RegMap_t* const pgpioe_odr_regmap =         ((GPIO_ODR_RegMap_t*)(GPIOE_BASE + GPIO_ODR_OFFSET));
#endif // USE_LOCAL_VARIABLE_DEFINITION

    // Enable GPIOE Clock at AHB:
    pahbenr_regmap->IOPEEN = 1;
    // Configure GPIOE.9:
    pgpioe_moder_regmap->val9 =   OUT;
    pgpioe_otyper_regmap->val9 =  PUSH_PULL;
    pgpioe_ospeedr_regmap->val9 = HIGH_SPEED;
    pgpioe_pupd_regmap->val9 =    PULL_UP;
    // Toggle Output at GPIOE.9:
    pgpioe_odr_regmap->val9 ^= 0x01;
}

void union_register_access()
{
#ifdef USE_LOCAL_VARIABLE_DEFINITION
    // RCC AHB Enable Register Map as Union:
    union AHBENR_Reg_t* const prcc_reg =           ((union AHBENR_Reg_t*)(RCC_BASE + RCC_AHBENR_OFFSET));
    // GPIOE Register Maps as Union:
    GPIO_MODER_Reg_t* const pgpioe_moder_reg =     ((GPIO_MODER_Reg_t*)(GPIOE_BASE + GPIO_MODER_OFFSET));
    GPIO_OTYPER_Reg_t* const pgpioe_otyper_reg =   ((GPIO_OTYPER_Reg_t*)(GPIOE_BASE + GPIO_OTYPER_OFFSET));
    GPIO_OSPEEDR_Reg_t* const pgpioe_ospeedr_reg = ((GPIO_OSPEEDR_Reg_t*)(GPIOE_BASE + GPIO_OSPEEDR_OFFSET));
    GPIO_PUPDR_Reg_t* const pgpioe_pupd_reg =      ((GPIO_PUPDR_Reg_t*)(GPIOE_BASE + GPIO_PUPDR_OFFSET));
    GPIO_ODR_Reg_t* const pgpioe_odr_reg =         ((GPIO_ODR_Reg_t*)(GPIOE_BASE + GPIO_ODR_OFFSET));
#endif // USE_LOCAL_VARIABLE_DEFINITION

#ifdef USE_VALUE_OF_UNION
    #ifdef RESET_GPIO_VALUES
    // Clear GPIO bits before setting new values:
    pgpioe_moder_reg->value     &= ~PIN_LED_32_2_bm;
    pgpioe_ospeedr_reg->value   &= ~PIN_LED_32_2_bm;
    pgpioe_pupd_reg->value      &= ~PIN_LED_32_2_bm;
    #endif // RESET_GPIO_VALUES

    // Enable GPIOE Clock at AHB:
    prcc_reg->value |= AHB_GPIOEEN_bm;
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
    pgpioe_moder_reg->regmap.val9 =   OUT;
    pgpioe_otyper_reg->regmap.val9 =  PUSH_PULL;
    pgpioe_ospeedr_reg->regmap.val9 = HIGH_SPEED;
    pgpioe_pupd_reg->regmap.val9 =    PULL_UP;
    // Toggle Output at GPIOE.9:
    pgpioe_odr_reg->regmap.val9 ^= 0x01;
#endif
}

void struct_register_access()
{
#ifdef USE_LOCAL_VARIABLE_DEFINITION
    // RCC Peripheral as sturcture (of unions):
    struct RCC_t* const prcc =    ((struct RCC_t*)(RCC_BASE));
    // GPIOE Peripheral as structure (of unions):
    struct GPIO_t* const pgpioe = ((struct GPIO_t*)(GPIOE_BASE));
#endif // USE_LOCAL_VARIABLE_DEFINITION

#ifdef USE_VALUE_OF_UNION
    #ifdef RESET_GPIO_VALUES
    // Clear GPIO bits before setting new values:
    pgpioe->MODER.value     &= ~PIN_LED_32_2_bm;
    pgpioe->OSPEEDR.value   &= ~PIN_LED_32_2_bm;
    pgpioe->PUPDR.value     &= ~PIN_LED_32_2_bm;
    #endif // RESET_GPIO_VALUES

    // Enable GPIOE Clock at AHB:
    prcc->AHBENR.value |= AHB_GPIOEEN_bm;
    // Configure GPIOE.9:
    pgpioe->MODER.value     |= PIN_LED_MODE_OUT_bm;
    pgpioe->OTYPER.value    |= PIN_LED_OTYPE_PUSH_PULL_bm;
    pgpioe->OSPEEDR.value   |= PIN_LED_OSPEED_HIGH_SPEED_bm;
    pgpioe->PUPDR.value     |= PIN_LED_PUPD_PULL_UP_bm;
    // Toggle Output at GPIOE.9:
    pgpioe->ODR.value       ^= PIN_LED_ODR_bm;
#else
    // Enable GPIOE Clock at AHB:
    prcc->AHBENR.regmap.IOPEEN = 1;
    // Configure GPIOE.9:
    pgpioe->MODER.regmap.val9 =   OUT;
    pgpioe->OTYPER.regmap.val9 =  PUSH_PULL;
    pgpioe->OSPEEDR.regmap.val9 = HIGH_SPEED;
    pgpioe->PUPDR.regmap.val9 =   PULL_UP;
    // Toggle Output at GPIOE.9:
    pgpioe->ODR.regmap.val9 ^= 0x01;
#endif
}

int main(void)
{
    volatile uint32_t counter = 0;

    direct_register_access();
    //regmap_register_access();
    //union_register_access();
    //struct_register_access();

#ifdef USE_LOCAL_VARIABLE_DEFINITION
    // GPIOE Peripheral as structure (of unions):
    struct GPIO_t* const pgpioe = ((struct GPIO_t*)(GPIOE_BASE));
#endif // USE_LOCAL_VARIABLE_DEFINITION

    while(1)
    {
        if (counter % 0x3FFFF == 0)
        {
            pgpioe->ODR.regmap.val9 ^= 0x01;     // Toggle bit.
        }
        __asm__ volatile("nop");
        counter++;
    }
}
