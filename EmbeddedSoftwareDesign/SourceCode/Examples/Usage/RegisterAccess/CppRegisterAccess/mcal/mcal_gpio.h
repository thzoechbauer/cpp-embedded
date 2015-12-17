#ifndef MCAL_GPIO_H_INCLUDED
#define MCAL_GPIO_H_INCLUDED

#include <stdint.h>
#include "mcal_reg.h"

namespace mcal
{
    namespace gpio
    {
        // GPIO Register Offsets:
        constexpr mcal::reg::offset_t MODER_OFFSET   = 0x00;    // Mode
        constexpr mcal::reg::offset_t OTYPER_OFFSET  = 0x04;    // Output type
        constexpr mcal::reg::offset_t OSPEEDR_OFFSET = 0x08;    // Output speed
        constexpr mcal::reg::offset_t PUPDR_OFFSET   = 0x0C;    // Pull Up/Down
        constexpr mcal::reg::offset_t IDR_OFFSET     = 0x10;    // Input Data
        constexpr mcal::reg::offset_t ODR_OFFSET     = 0x14;    // Output Data
        constexpr mcal::reg::offset_t BSRR_OFFSET    = 0x18;    // Bit Set/Reset
        constexpr mcal::reg::offset_t LCKR_OFFSET    = 0x1C;    // Lock
        constexpr mcal::reg::offset_t AFRL_OFFSET    = 0x20;    // AF Low
        constexpr mcal::reg::offset_t AFRH_OFFSET    = 0x24;    // AF High
        constexpr mcal::reg::offset_t BRR_OFFSET     = 0x28;    // Bit Reset

        enum class Mode_t : mcal::reg::value_t
        {
            IN = 0x00,
            OUT = 0x01,
            AF = 0x02,  // alternate function
            AN = 0x03   // analog
        };

        enum class OType_t : mcal::reg::value_t
        {
          PUSH_PULL = 0x00,
          OPEN_DRAIN = 0x01
        };

        enum class OSpeed_t : mcal::reg::value_t
        {
          LOW_SPEED = 0x01,
          MEDIUM_SPEED = 0x02,
          HIGH_SPEED = 0x03
        };

        enum class PuPd_t : mcal::reg::value_t
        {
          NO_PULL = 0x00,
          PULL_UP = 0X01,
          PULL_DOWN = 0x02
        };

        // Define GPIO register map types:
        using MODER_RegMap_t = mcal::reg::RegMap32_2_t;
        using OTYPER_RegMap_t =  mcal::reg::RegMap32_t;
        using OSPEEDR_RegMap_t = mcal::reg::RegMap32_2_t;
        using PUPDR_RegMap_t =   mcal::reg::RegMap32_2_t;
        using IDR_RegMap_t =     mcal::reg::RegMap32_t;
        using ODR_RegMap_t =     mcal::reg::RegMap32_t;
        using BSSR_RegMap_t =    mcal::reg::RegMap32_2_t;
        using LCKR_RegMap_t =    mcal::reg::RegMap32_2_t;
        using AFR_RegMap_t =     mcal::reg::RegMap32_2_t;
        using BRR_RegMap_t =     mcal::reg::RegMap32_t;

        // Define GPIO register unions with register map and value:
        using MODER_Reg_t =   mcal::reg::Reg32_2_t;
        using OTYPER_Reg_t =  mcal::reg::Reg32_t;
        using OSPEEDR_Reg_t = mcal::reg::Reg32_2_t;
        using PUPDR_Reg_t =   mcal::reg::Reg32_2_t;
        using IDR_Reg_t =     mcal::reg::Reg32_t;
        using ODR_Reg_t =     mcal::reg::Reg32_t;
        using BSSR_Reg_t =    mcal::reg::Reg32_2_t;
        using LCKR_Reg_t =    mcal::reg::Reg32_2_t;
        using AFR_Reg_t =     mcal::reg::Reg32_2_t;
        using BRR_Reg_t =     mcal::reg::Reg32_t;

        // Define GPIO peripheral structure (with unions):
        struct GPIO_t
        {
            MODER_Reg_t    MODER;
            OTYPER_Reg_t   OTYPER;
            OSPEEDR_Reg_t  OSPEEDR;
            PUPDR_Reg_t    PUPDR;
            IDR_Reg_t      IDR;
            ODR_Reg_t      ODR;
            BSSR_Reg_t     BSSR;
            LCKR_Reg_t     LCKR;
            AFR_Reg_t      AFR[2];
            BRR_Reg_t      BRR;
        };

        template<const mcal::reg::address_t GPIOx_BASE>
        using MODER_RegExt_t = mcal::reg::RegExt_t<mcal::reg::address_t,
                                    mcal::reg::value_t, mcal::reg::RegMap32_2_t,
                                    GPIOx_BASE + mcal::gpio::MODER_OFFSET>;

        template<const mcal::reg::address_t GPIOx_BASE>
        using OTYPER_RegExt_t = mcal::reg::RegExt_t<mcal::reg::address_t,
                                    mcal::reg::value_t, mcal::reg::RegMap32_t,
                                    GPIOx_BASE + mcal::gpio::OTYPER_OFFSET>;

        template<const mcal::reg::address_t GPIOx_BASE>
        using OSPEEDR_RegExt_t = mcal::reg::RegExt_t<mcal::reg::address_t,
                                    mcal::reg::value_t, mcal::reg::RegMap32_2_t,
                                    GPIOx_BASE + mcal::gpio::OSPEEDR_OFFSET>;

        template<const mcal::reg::address_t GPIOx_BASE>
        using PUPDR_RegExt_t = mcal::reg::RegExt_t<mcal::reg::address_t,
                                    mcal::reg::value_t, mcal::reg::RegMap32_2_t,
                                    GPIOx_BASE + mcal::gpio::PUPDR_OFFSET>;

        template<const mcal::reg::address_t GPIOx_BASE>
        using ODR_RegExt_t = mcal::reg::RegExt_t<mcal::reg::address_t,
                                    mcal::reg::value_t, mcal::reg::RegMap32_t,
                                    GPIOx_BASE + mcal::gpio::ODR_OFFSET>;
    }
}



#endif // MCAL_GPIO_H_INCLUDED
