#ifndef MCAL_GPIO_H_INCLUDED
#define MCAL_GPIO_H_INCLUDED

#include <stdint.h>
#include "mcal_reg.h"

// GPIO Register Offsets:
#define GPIO_MODER_OFFSET       ((uint32_t)0x00)    // Mode
#define GPIO_OTYPER_OFFSET      ((uint32_t)0x04)    // Output type
#define GPIO_OSPEEDR_OFFSET     ((uint32_t)0x08)    // Output speed
#define GPIO_PUPDR_OFFSET       ((uint32_t)0x0C)    // Pull Up/Down
#define GPIO_IDR_OFFSET         ((uint32_t)0x10)    // Input Data
#define GPIO_ODR_OFFSET         ((uint32_t)0x14)    // Output Data
#define GPIO_BSRR_OFFSET        ((uint32_t)0x18)    // Bit Set/Reset
#define GPIO_LCKR_OFFSET        ((uint32_t)0x1C)    // Lock
#define GPIO_AFRL_OFFSET        ((uint32_t)0x20)    // AF Low
#define GPIO_AFRH_OFFSET        ((uint32_t)0x24)    // AF High
#define GPIO_BRR_OFFSET         ((uint32_t)0x28)    // Bit Reset

enum GPIO_Mode_t
{
    IN = 0x00,
    OUT = 0x01,
    AF = 0x02,  // alternate function
    AN = 0x03   // analog
};

enum GPIO_OType_t
{
  PUSH_PULL = 0x00,
  OPEN_DRAIN = 0x01
};

enum GPIO_OSpeed_t
{
  LOW_SPEED = 0x01,
  MEDIUM_SPEED = 0x02,
  HIGH_SPEED = 0x03
};

enum GPIO_PuPd_t
{
  NO_PULL = 0x00,
  PULL_UP = 0X01,
  PULL_DOWN = 0x02
};

// Define GPIO register map types:
typedef struct RegMap32_2_t GPIO_MODER_RegMap_t;
typedef struct RegMap32_t   GPIO_OTYPER_RegMap_t;
typedef struct RegMap32_2_t GPIO_OSPEEDR_RegMap_t;
typedef struct RegMap32_2_t GPIO_PUPDR_RegMap_t;
typedef struct RegMap32_t   GPIO_IDR_RegMap_t;
typedef struct RegMap32_t   GPIO_ODR_RegMap_t;
typedef struct RegMap32_2_t GPIO_BSSR_RegMap_t;
typedef struct RegMap32_2_t GPIO_LCKR_RegMap_t;
typedef struct RegMap32_2_t GPIO_AFR_RegMap_t;
typedef struct RegMap32_t   GPIO_BRR_RegMap_t;

// Define GPIO register unions with register map and value:
typedef union Reg32_2_t GPIO_MODER_Reg_t;
typedef union Reg32_t   GPIO_OTYPER_Reg_t;
typedef union Reg32_2_t GPIO_OSPEEDR_Reg_t;
typedef union Reg32_2_t GPIO_PUPDR_Reg_t;
typedef union Reg32_t   GPIO_IDR_Reg_t;
typedef union Reg32_t   GPIO_ODR_Reg_t;
typedef union Reg32_2_t GPIO_BSSR_Reg_t;
typedef union Reg32_2_t GPIO_LCKR_Reg_t;
typedef union Reg32_2_t GPIO_AFR_Reg_t;
typedef union Reg32_t   GPIO_BRR_Reg_t;

// Define GPIO peripheral structure (with unions):
struct GPIO_t
{
    GPIO_MODER_Reg_t    MODER;
    GPIO_OTYPER_Reg_t   OTYPER;
    GPIO_OSPEEDR_Reg_t  OSPEEDR;
    GPIO_PUPDR_Reg_t    PUPDR;
    GPIO_IDR_Reg_t      IDR;
    GPIO_ODR_Reg_t      ODR;
    GPIO_BSSR_Reg_t     BSSR;
    GPIO_LCKR_Reg_t     LCKR;
    GPIO_AFR_Reg_t      AFR[2];
    GPIO_BRR_Reg_t      BRR;
};

#endif // MCAL_GPIO_H_INCLUDED
