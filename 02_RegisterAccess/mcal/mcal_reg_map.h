/********************************************//**
 *  \brief     Access Registers via C++ Template Functions.
 *             The code is based on the book "Real-Time C++"
 *             by Chris Kormanyos.
 *  \author    Tom
 *  \version   V1.0
 *  \date      20-February-2015
 ***********************************************/

#include <cstdint>

namespace mcal
{
    namespace reg
    {
        // Bit mapped structure for 8 bit type.
        typedef struct struct_bit8_type
        {
            std::uint8_t b0 : 1;
            std::uint8_t b1 : 1;
            std::uint8_t b2 : 1;
            std::uint8_t b3 : 1;
            std::uint8_t b4 : 1;
            std::uint8_t b5 : 1;
            std::uint8_t b6 : 1;
            std::uint8_t b7 : 1;
        }bit8_type;

        // Bit mapped structure for 16 bit type.
        typedef struct struct_bit16_type
        {
            std::uint8_t b0 : 1;
            std::uint8_t b1 : 1;
            std::uint8_t b2 : 1;
            std::uint8_t b3 : 1;
            std::uint8_t b4 : 1;
            std::uint8_t b5 : 1;
            std::uint8_t b6 : 1;
            std::uint8_t b7 : 1;
            std::uint8_t b8 : 1;
            std::uint8_t b9 : 1;
            std::uint8_t b10 : 1;
            std::uint8_t b11 : 1;
            std::uint8_t b12 : 1;
            std::uint8_t b13 : 1;
            std::uint8_t b14 : 1;
            std::uint8_t b15 : 1;
        }bit16_type;

        // Bit mapped structure for 32 bit type.
        typedef struct struct_bit32_type
        {
            std::uint8_t b0 : 1;
            std::uint8_t b1 : 1;
            std::uint8_t b2 : 1;
            std::uint8_t b3 : 1;
            std::uint8_t b4 : 1;
            std::uint8_t b5 : 1;
            std::uint8_t b6 : 1;
            std::uint8_t b7 : 1;
            std::uint8_t b8 : 1;
            std::uint8_t b9 : 1;
            std::uint8_t b10 : 1;
            std::uint8_t b11 : 1;
            std::uint8_t b12 : 1;
            std::uint8_t b13 : 1;
            std::uint8_t b14 : 1;
            std::uint8_t b15 : 1;
            std::uint8_t b16 : 1;
            std::uint8_t b17 : 1;
            std::uint8_t b18 : 1;
            std::uint8_t b19 : 1;
            std::uint8_t b20 : 1;
            std::uint8_t b21 : 1;
            std::uint8_t b22 : 1;
            std::uint8_t b23 : 1;
            std::uint8_t b24 : 1;
            std::uint8_t b25 : 1;
            std::uint8_t b26 : 1;
            std::uint8_t b27 : 1;
            std::uint8_t b28 : 1;
            std::uint8_t b29 : 1;
            std::uint8_t b30 : 1;
            std::uint8_t b31 : 1;
        }bit32_type;

        // Template Class to access register via value or bit mapped structure.
        template<typename addr_type,
                 typename reg_type,
                 typename bits_type,
                 const addr_type addr>
        class reg_map
        {
        public:
            static volatile reg_type& value()
            {
                return *reinterpret_cast<volatile reg_type*>(addr);
            }

            static volatile bits_type& bits()
            {
                return *reinterpret_cast<volatile bits_type*>(addr);
            }
        };
    }
}

