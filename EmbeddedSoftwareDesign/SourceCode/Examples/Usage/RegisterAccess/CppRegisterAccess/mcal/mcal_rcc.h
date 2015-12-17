#ifndef MCAL_RCC_H_INCLUDED
#define MCAL_RCC_H_INCLUDED

#include <stdint.h>
#include "mcal_reg.h"

namespace mcal
{
    namespace rcc
    {
        // Offset definitions of RCC:
        // ...
        constexpr mcal::reg::offset_t AHBENR_OFFSET = 0x00000014; // Offset to AHRENR
        // ...

        // Bitmask definitions to enable special GPIO Clock at AHBENR:
        constexpr mcal::reg::value_t AHB_GPIOAEN_bm  = 0x1 << 17;   // Bitmask to enable GPIOA Clock.
        constexpr mcal::reg::value_t AHB_GPIOBEN_bm  = 0x1 << 18;   // Bitmask to enable GPIOB Clock.
        constexpr mcal::reg::value_t AHB_GPIOCEN_bm  = 0x1 << 19;   // Bitmask to enable GPIOC Clock.
        constexpr mcal::reg::value_t AHB_GPIODEN_bm  = 0x1 << 20;   // Bitmask to enable GPIOD Clock.
        constexpr mcal::reg::value_t AHB_GPIOEEN_bm  = 0x1 << 21;   // Bitmask to enable GPIOE Clock.
        constexpr mcal::reg::value_t AHB_GPIOFEN_bm  = 0x1 << 22;   // Bitmask to enable GPIOF Clock.
        constexpr mcal::reg::value_t AHB_GPIOGEN_bm  = 0x1 << 23;   // Bitmask to enable GPIOG Clock.
        constexpr mcal::reg::value_t AHB_GPIOHEN_bm  = 0x1 << 16;   // Bitmask to enable GPIOH Clock.

        // Register map of register AHBENR:
        struct AHBENR_RegMap_t
        {
            volatile std::uint8_t DMA1EN  : 1;   // 0
            volatile std::uint8_t DMA2EN  : 1;   // 1
            volatile std::uint8_t SRAMEN  : 1;   // 2
            std::uint8_t reserved3        : 1;   // 3
            volatile std::uint8_t FLIFTEN : 1;   // 4
            volatile std::uint8_t FMCEN   : 1;   // 5
            volatile std::uint8_t CRCEN   : 1;   // 6
            std::uint8_t reserved7        : 1;   // 7
            std::uint8_t reserved8_15; // : 8;   // 8-15
            volatile std::uint8_t IOPHEN  : 1;   // 16
            volatile std::uint8_t IOPAEN  : 1;   // 17
            volatile std::uint8_t IOPBEN  : 1;   // 18
            volatile std::uint8_t IOPCEN  : 1;   // 19
            volatile std::uint8_t IOPDEN  : 1;   // 20
            volatile std::uint8_t IOPEEN  : 1;   // 21
            volatile std::uint8_t IOPFEN  : 1;   // 22
            volatile std::uint8_t IOPGEN  : 1;   // 23
            volatile std::uint8_t TSCEN   : 1;   // 24
            std::uint8_t reserved25_27    : 3;   // 25-27
            volatile std::uint8_t ADC12EN : 1;   // 28
            volatile std::uint8_t ADC34EN : 1;   // 29
            std::uint8_t reserved30_31    : 2;   // 30-31
        };

        // Define RCC register unions with register map and value:
        // Special definition of union for AHBENR that uses AHBENR_RegMap_t:
        using AHBENR_Reg_t = mcal::reg::Reg_t<AHBENR_RegMap_t, mcal::reg::value_t>;

        using CR_Reg_t =       mcal::reg::Reg32_t;      // dummy type.
        using CFGR_Reg_t =     mcal::reg::Reg32_t;      // dummy type.
        using CIR_Reg_t =      mcal::reg::Reg32_t;      // dummy type.
        using APB2RSTR_Reg_t = mcal::reg::Reg32_t;      // dummy type.
        using APB1RSTR_Reg_t = mcal::reg::Reg32_t;      // dummy type.
        using APB2ENR_Reg_t =  mcal::reg::Reg32_t;      // dummy type.
        using APB1ENR_Reg_t =  mcal::reg::Reg32_t;      // dummy type.
        using BDCR_Reg_t =     mcal::reg::Reg32_t;      // dummy type.
        using CSR_Reg_t =      mcal::reg::Reg32_t;      // dummy type.
        using ABHRSTR_Reg_t =  mcal::reg::Reg32_t;      // dummy type.
        using CFGR2_Reg_t =    mcal::reg::Reg32_t;      // dummy type.
        using CFGR3_Reg_t =    mcal::reg::Reg32_t;      // dummy type.

        // Define RCC peripheral structure (with unions):
        struct RCC_t
        {
            CR_Reg_t CR;
            CFGR_Reg_t CFGR;
            CIR_Reg_t CIR;
            APB2RSTR_Reg_t APB2RSTR;
            APB1RSTR_Reg_t APB1RSTR;
            AHBENR_Reg_t AHBENR;  // ! use of AHBENR_Reg_t !
            APB2ENR_Reg_t APB2ENR;
            APB1ENR_Reg_t APB1ENR;
            BDCR_Reg_t BDCR;
            CSR_Reg_t CSR;
            ABHRSTR_Reg_t ABHRSTR;
            CFGR2_Reg_t CFGR2;
            CFGR3_Reg_t CFGR3;
        };

        // Define template for AHBENR.
        using AHBENR_RegExt_t = mcal::reg::RegExt_t<mcal::reg::address_t,
                                                    mcal::reg::value_t,
                                                    AHBENR_RegMap_t,
                                                    mcal::reg::RCC_BASE + mcal::rcc::AHBENR_OFFSET>;
    }
}



#endif // MCAL_RCC_H_INCLUDED
