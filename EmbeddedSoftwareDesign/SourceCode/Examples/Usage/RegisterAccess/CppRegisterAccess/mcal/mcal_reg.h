#ifndef MCAL_REG_H_INCLUDED
#define MCAL_REG_H_INCLUDED

#include <cstdint>

namespace mcal
{
    namespace reg
    {
        using value_t = std::uint32_t;      // Register Value Type.
        using address_t = std::uint32_t;    // Register Address Type.
        using offset_t = address_t;         // Register Offset Type.

        // Base Address of bus:
        constexpr value_t AHB1_BASE = 0x40020000;
        constexpr value_t AHB2_BASE = 0x48000000;

        // Peripheral base addresses:
        constexpr address_t RCC_BASE   = AHB1_BASE + 0x1000;  // RCC Base Address.
        constexpr address_t GPIO_BASE  = AHB2_BASE;           // GPIO Base Address.
        constexpr address_t GPIOA_BASE = GPIO_BASE + 0x0000;
        constexpr address_t GPIOB_BASE = GPIO_BASE + 0x0400;
        constexpr address_t GPIOC_BASE = GPIO_BASE + 0x0800;
        constexpr address_t GPIOD_BASE = GPIO_BASE + 0x0C00;
        constexpr address_t GPIOE_BASE = GPIO_BASE + 0x1000;
        constexpr address_t GPIOF_BASE = GPIO_BASE + 0x1400;

        enum class BitPos_t : std::uint8_t
        {
            BitPos_0 = 0x00,
            BitPos_1,  BitPos_2,  BitPos_3,  BitPos_4,  BitPos_5,
            BitPos_6,  BitPos_7,  BitPos_8,  BitPos_9,  BitPos_10,
            BitPos_11, BitPos_12, BitPos_13, BitPos_14, BitPos_15,
            BitPos_16, BitPos_17, BitPos_18, BitPos_19, BitPos_20,
            BitPos_21, BitPos_22, BitPos_23, BitPos_24, BitPos_25,
            BitPos_26, BitPos_27, BitPos_28, BitPos_29, BitPos_30,
            BitPos_31
        };

        struct RegMap32_2_t
        {
            volatile std::uint8_t val0  : 2;
            volatile std::uint8_t val1  : 2;
            volatile std::uint8_t val2  : 2;
            volatile std::uint8_t val3  : 2;
            volatile std::uint8_t val4  : 2;
            volatile std::uint8_t val5  : 2;
            volatile std::uint8_t val6  : 2;
            volatile std::uint8_t val7  : 2;
            volatile std::uint8_t val8  : 2;
            volatile std::uint8_t val9  : 2;
            volatile std::uint8_t val10 : 2;
            volatile std::uint8_t val11 : 2;
            volatile std::uint8_t val12 : 2;
            volatile std::uint8_t val13 : 2;
            volatile std::uint8_t val14 : 2;
            volatile std::uint8_t val15 : 2;
        };

        struct RegMap32_t
        {
            volatile std::uint8_t val0  : 1;
            volatile std::uint8_t val1  : 1;
            volatile std::uint8_t val2  : 1;
            volatile std::uint8_t val3  : 1;
            volatile std::uint8_t val4  : 1;
            volatile std::uint8_t val5  : 1;
            volatile std::uint8_t val6  : 1;
            volatile std::uint8_t val7  : 1;
            volatile std::uint8_t val8  : 1;
            volatile std::uint8_t val9  : 1;
            volatile std::uint8_t val10 : 1;
            volatile std::uint8_t val11 : 1;
            volatile std::uint8_t val12 : 1;
            volatile std::uint8_t val13 : 1;
            volatile std::uint8_t val14 : 1;
            volatile std::uint8_t val15 : 1;
            volatile std::uint8_t val16 : 1;
            volatile std::uint8_t val17 : 1;
            volatile std::uint8_t val18 : 1;
            volatile std::uint8_t val19 : 1;
            volatile std::uint8_t val20 : 1;
            volatile std::uint8_t val21 : 1;
            volatile std::uint8_t val22 : 1;
            volatile std::uint8_t val23 : 1;
            volatile std::uint8_t val24 : 1;
            volatile std::uint8_t val25 : 1;
            volatile std::uint8_t val26 : 1;
            volatile std::uint8_t val27 : 1;
            volatile std::uint8_t val28 : 1;
            volatile std::uint8_t val29 : 1;
            volatile std::uint8_t val30 : 1;
            volatile std::uint8_t val31 : 1;
        };

        template<typename RegMap_t, typename RegValue_t>
        union Reg_t
        {
            RegMap_t regmap;
            volatile RegValue_t value;
        };

        using Reg32_2_t = Reg_t<RegMap32_2_t, std::uint32_t>;
        using Reg32_t = Reg_t<RegMap32_t, std::uint32_t>;

        template<typename address_type,
                 typename val_type,
                 typename RegMap_type,
                 const address_type addr>
        class RegExt_t
        {
        public:
            static volatile RegMap_type& regmap()
            {
                return *reinterpret_cast<RegMap_type*>(addr);
            }

            static volatile val_type& value()
            {
                return *reinterpret_cast<val_type*>(addr);
            }
        };

        template<const address_t addr>
        using RegExt32_2_t = RegExt_t<address_t, value_t, RegMap32_2_t, addr>;

        template<const address_t addr>
        using RegExt32_t = RegExt_t<address_t, value_t, RegMap32_t, addr>;
    }
}




#endif // MCAL_REG_H_INCLUDED
