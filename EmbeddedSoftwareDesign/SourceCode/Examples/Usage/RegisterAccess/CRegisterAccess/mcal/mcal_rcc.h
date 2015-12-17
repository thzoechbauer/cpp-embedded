#ifndef MCAL_RCC_H_INCLUDED
#define MCAL_RCC_H_INCLUDED

#include <stdint.h>
#include "mcal_reg.h"

// Offset definitions of RCC:
// ...
#define RCC_AHBENR_OFFSET       ((uint32_t)0x00000014)  // Offset to AHRENR
// ...

// Bitmask definitions to enable special GPIO Clock at AHBENR:
#define AHB_GPIOAEN_bm  ((uint32_t)0x1 << 17)   // Bitmask to enable GPIOA Clock.
#define AHB_GPIOBEN_bm  ((uint32_t)0x1 << 18)   // Bitmask to enable GPIOB Clock.
#define AHB_GPIOCEN_bm  ((uint32_t)0x1 << 19)   // Bitmask to enable GPIOC Clock.
#define AHB_GPIODEN_bm  ((uint32_t)0x1 << 20)   // Bitmask to enable GPIOD Clock.
#define AHB_GPIOEEN_bm  ((uint32_t)0x1 << 21)   // Bitmask to enable GPIOE Clock.
#define AHB_GPIOFEN_bm  ((uint32_t)0x1 << 22)   // Bitmask to enable GPIOF Clock.
#define AHB_GPIOGEN_bm  ((uint32_t)0x1 << 23)   // Bitmask to enable GPIOG Clock.
#define AHB_GPIOHEN_bm  ((uint32_t)0x1 << 16)   // Bitmask to enable GPIOH Clock.

// Register map of register AHBENR:
struct AHBENR_RegMap_t
{
    volatile uint8_t DMA1EN  : 1;   // 0
    volatile uint8_t DMA2EN  : 1;   // 1
    volatile uint8_t SRAMEN  : 1;   // 2
    uint8_t reserved3 : 1;          // 3
    volatile uint8_t FLIFTEN : 1;   // 4
    volatile uint8_t FMCEN   : 1;   // 5
    volatile uint8_t CRCEN   : 1;   // 6
    uint8_t reserved7 : 1;          // 7
    uint8_t reserved8_15;           // 8-15
    volatile uint8_t IOPHEN  : 1;   // 16
    volatile uint8_t IOPAEN  : 1;   // 17
    volatile uint8_t IOPBEN  : 1;   // 18
    volatile uint8_t IOPCEN  : 1;   // 19
    volatile uint8_t IOPDEN  : 1;   // 20
    volatile uint8_t IOPEEN  : 1;   // 21
    volatile uint8_t IOPFEN  : 1;   // 22
    volatile uint8_t IOPGEN  : 1;   // 23
    volatile uint8_t TSCEN   : 1;   // 24
    uint8_t reserved25_27    : 3;   // 25-27
    volatile uint8_t ADC12EN : 1;   // 28
    volatile uint8_t ADC34EN : 1;   // 29
    uint8_t reserved30_31    : 2;   // 30-31
};

// Define RCC register unions with register map and value:
// Special definition of union for AHBENR that uses AHBENR_RegMap_t:
union AHBENR_Reg_t
{
    volatile uint32_t value;
    volatile struct AHBENR_RegMap_t regmap;
};

typedef union Reg32_t CR_Reg_t;             // dummy type.
typedef union Reg32_t CFGR_Reg_t;           // dummy type.
typedef union Reg32_t CIR_Reg_t;            // dummy type.
typedef union Reg32_t APB2RSTR_Reg_t;       // dummy type.
typedef union Reg32_t APB1RSTR_Reg_t;       // dummy type.
typedef union Reg32_t APB2ENR_Reg_t;        // dummy type.
typedef union Reg32_t APB1ENR_Reg_t;        // dummy type.
typedef union Reg32_t BDCR_Reg_t;           // dummy type.
typedef union Reg32_t CSR_Reg_t;            // dummy type.
typedef union Reg32_t ABHRSTR_Reg_t;        // dummy type.
typedef union Reg32_t CFGR2_Reg_t;          // dummy type.
typedef union Reg32_t CFGR3_Reg_t;          // dummy type.

// Define RCC peripheral structure (with unions):
struct RCC_t
{
    CR_Reg_t CR;
    CFGR_Reg_t CFGR;
    CIR_Reg_t CIR;
    APB2RSTR_Reg_t APB2RSTR;
    APB1RSTR_Reg_t APB1RSTR;
    union AHBENR_Reg_t AHBENR;  // ! use of AHBENR_Reg_t !
    APB2ENR_Reg_t APB2ENR;
    APB1ENR_Reg_t APB1ENR;
    BDCR_Reg_t BDCR;
    CSR_Reg_t CSR;
    ABHRSTR_Reg_t ABHRSTR;
    CFGR2_Reg_t CFGR2;
    CFGR3_Reg_t CFGR3;
};

#endif // MCAL_RCC_H_INCLUDED
