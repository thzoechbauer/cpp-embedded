/********************************************//**
 *  \brief     List of most important Registers for stm32f30x MCU.
 *             All register addresses are listed in file stm32f30x.h.
 *  \author    Tom
 *  \version   V1.0
 *  \date      20-February-2015
 ***********************************************/

#ifndef INCLUDE_MCAL_REG_H
#define INCLUDE_MCAL_REG_H

#include <cstdint>

namespace mcal
{
    namespace reg
    {
        // --------------------------------------
        // Peripheral memory_map.

        // Global base addresses.
        constexpr std::uint32_t flash_base      = UINT32_C(0x08000000);     /*!< FLASH base address in the alias region */
        constexpr std::uint32_t sram_base       = UINT32_C(0x20000000);     /*!< SRAM base address in the alias region */
        constexpr std::uint32_t periph_base     = UINT32_C(0x40000000);     /*!< Peripheral base address in the alias region */

        constexpr std::uint32_t sram_bb_base    = UINT32_C(0x22000000);     /*!< SRAM base address in the bit-band region */
        constexpr std::uint32_t periph_bb_base  = UINT32_C(0x42000000);     /*!< Peripheral base address in the bit-band region */

        // Peripheral memory map.
        constexpr std::uint32_t apb1periph_base = periph_base + UINT32_C(0x00000000);
        constexpr std::uint32_t apb2periph_base = periph_base + UINT32_C(0x00010000);
        constexpr std::uint32_t ahb1periph_base = periph_base + UINT32_C(0x00020000);
        constexpr std::uint32_t ahb2periph_base = periph_base + UINT32_C(0x08000000);
        constexpr std::uint32_t ahb3periph_base = periph_base + UINT32_C(0x10000000);

        // APB1 peripherals.
        constexpr std::uint32_t  tim2_base      = apb1periph_base + UINT32_C(0x00000000);
        constexpr std::uint32_t  tim3_base      = apb1periph_base + UINT32_C(0x00000400);
        constexpr std::uint32_t  tim4_base      = apb1periph_base + UINT32_C(0x00000800);
        constexpr std::uint32_t  tim6_base      = apb1periph_base + UINT32_C(0x00001000);
        constexpr std::uint32_t  tim7_base      = apb1periph_base + UINT32_C(0x00001400);
        constexpr std::uint32_t  rtc_base       = apb1periph_base + UINT32_C(0x00002800);
        constexpr std::uint32_t  wwdg_base      = apb1periph_base + UINT32_C(0x00002c00);
        constexpr std::uint32_t  iwdg_base      = apb1periph_base + UINT32_C(0x00003000);
        constexpr std::uint32_t  i2s2ext_base   = apb1periph_base + UINT32_C(0x00003400);
        constexpr std::uint32_t  spi2_base      = apb1periph_base + UINT32_C(0x00003800);
        constexpr std::uint32_t  spi3_base      = apb1periph_base + UINT32_C(0x00003c00);
        constexpr std::uint32_t  i2s3ext_base   = apb1periph_base + UINT32_C(0x00004000);
        constexpr std::uint32_t  usart2_base    = apb1periph_base + UINT32_C(0x00004400);
        constexpr std::uint32_t  usart3_base    = apb1periph_base + UINT32_C(0x00004800);
        constexpr std::uint32_t  uart4_base     = apb1periph_base + UINT32_C(0x00004c00);
        constexpr std::uint32_t  uart5_base     = apb1periph_base + UINT32_C(0x00005000);
        constexpr std::uint32_t  i2c1_base      = apb1periph_base + UINT32_C(0x00005400);
        constexpr std::uint32_t  i2c2_base      = apb1periph_base + UINT32_C(0x00005800);
        constexpr std::uint32_t  can1_base      = apb1periph_base + UINT32_C(0x00006400);
        constexpr std::uint32_t  pwr_base       = apb1periph_base + UINT32_C(0x00007000);
        constexpr std::uint32_t  dac_base       = apb1periph_base + UINT32_C(0x00007400);

        // APB2 peripherals.
        constexpr std::uint32_t syscfg_base     = apb2periph_base + UINT32_C(0x00000000);
        constexpr std::uint32_t comp_base       = apb2periph_base + UINT32_C(0x0000001c);
        constexpr std::uint32_t comp1_base      = apb2periph_base + UINT32_C(0x0000001c);
        constexpr std::uint32_t comp2_base      = apb2periph_base + UINT32_C(0x00000020);
        constexpr std::uint32_t comp3_base      = apb2periph_base + UINT32_C(0x00000024);
        constexpr std::uint32_t comp4_base      = apb2periph_base + UINT32_C(0x00000028);
        constexpr std::uint32_t comp5_base      = apb2periph_base + UINT32_C(0x0000002c);
        constexpr std::uint32_t comp6_base      = apb2periph_base + UINT32_C(0x00000030);
        constexpr std::uint32_t comp7_base      = apb2periph_base + UINT32_C(0x00000034);
        constexpr std::uint32_t opamp_base      = apb2periph_base + UINT32_C(0x00000038);
        constexpr std::uint32_t opamp1_base     = apb2periph_base + UINT32_C(0x00000038);
        constexpr std::uint32_t opamp2_base     = apb2periph_base + UINT32_C(0x0000003c);
        constexpr std::uint32_t opamp3_base     = apb2periph_base + UINT32_C(0x00000040);
        constexpr std::uint32_t opamp4_base     = apb2periph_base + UINT32_C(0x00000044);
        constexpr std::uint32_t exti_base       = apb2periph_base + UINT32_C(0x00000400);
        constexpr std::uint32_t tim1_base       = apb2periph_base + UINT32_C(0x00002c00);
        constexpr std::uint32_t spi1_base       = apb2periph_base + UINT32_C(0x00003000);
        constexpr std::uint32_t tim8_base       = apb2periph_base + UINT32_C(0x00003400);
        constexpr std::uint32_t usart1_base     = apb2periph_base + UINT32_C(0x00003800);
        constexpr std::uint32_t tim15_base      = apb2periph_base + UINT32_C(0x00004000);
        constexpr std::uint32_t tim16_base      = apb2periph_base + UINT32_C(0x00004400);
        constexpr std::uint32_t tim17_base      = apb2periph_base + UINT32_C(0x00004800);

        // AHB1 peripherals.
        constexpr std::uint32_t dma1_base             = ahb1periph_base + UINT32_C(0x00000000);
        constexpr std::uint32_t dma1_channel1_base    = ahb1periph_base + UINT32_C(0x00000008);
        constexpr std::uint32_t dma1_channel2_base    = ahb1periph_base + UINT32_C(0x0000001c);
        constexpr std::uint32_t dma1_channel3_base    = ahb1periph_base + UINT32_C(0x00000030);
        constexpr std::uint32_t dma1_channel4_base    = ahb1periph_base + UINT32_C(0x00000044);
        constexpr std::uint32_t dma1_channel5_base    = ahb1periph_base + UINT32_C(0x00000058);
        constexpr std::uint32_t dma1_channel6_base    = ahb1periph_base + UINT32_C(0x0000006c);
        constexpr std::uint32_t dma1_channel7_base    = ahb1periph_base + UINT32_C(0x00000080);
        constexpr std::uint32_t dma2_base             = ahb1periph_base + UINT32_C(0x00000400);
        constexpr std::uint32_t dma2_channel1_base    = ahb1periph_base + UINT32_C(0x00000408);
        constexpr std::uint32_t dma2_channel2_base    = ahb1periph_base + UINT32_C(0x0000041c);
        constexpr std::uint32_t dma2_channel3_base    = ahb1periph_base + UINT32_C(0x00000430);
        constexpr std::uint32_t dma2_channel4_base    = ahb1periph_base + UINT32_C(0x00000444);
        constexpr std::uint32_t dma2_channel5_base    = ahb1periph_base + UINT32_C(0x00000458);
        constexpr std::uint32_t rcc_base              = ahb1periph_base + UINT32_C(0x00001000);
        constexpr std::uint32_t flash_r_base          = ahb1periph_base + UINT32_C(0x00002000); /*!< flash registers base address */
        constexpr std::uint32_t ob_base               = UINT32_C(0x1ffff800);     /*!< flash option bytes base address */
        constexpr std::uint32_t crc_base              = ahb1periph_base + UINT32_C(0x00003000);
        constexpr std::uint32_t tsc_base              = ahb1periph_base + UINT32_C(0x00004000);

        // AHB2 peripherals.
        constexpr std::uint32_t gpioa_base      = ahb2periph_base + UINT32_C(0x0000);
        constexpr std::uint32_t gpiob_base      = ahb2periph_base + UINT32_C(0x0400);
        constexpr std::uint32_t gpioc_base      = ahb2periph_base + UINT32_C(0x0800);
        constexpr std::uint32_t gpiod_base      = ahb2periph_base + UINT32_C(0x0c00);
        constexpr std::uint32_t gpioe_base      = ahb2periph_base + UINT32_C(0x1000);
        constexpr std::uint32_t gpiof_base      = ahb2periph_base + UINT32_C(0x1400);

        // AHB3 peripherals.
        constexpr std::uint32_t adc1_base       = ahb3periph_base + UINT32_C(0x0000);
        constexpr std::uint32_t adc2_base       = ahb3periph_base + UINT32_C(0x0100);
        constexpr std::uint32_t adc1_2_base     = ahb3periph_base + UINT32_C(0x0300);
        constexpr std::uint32_t adc3_base       = ahb3periph_base + UINT32_C(0x0400);
        constexpr std::uint32_t adc4_base       = ahb3periph_base + UINT32_C(0x0500);
        constexpr std::uint32_t adc3_4_base     = ahb3periph_base + UINT32_C(0x0700);

        constexpr std::uint32_t dbgmcu_base     = UINT32_C(0xE0042000); /*!< Debug MCU registers base address */


        // --------------------------------------
        // Port registers.

        // Port A.
        constexpr std::uint32_t gpioa_moder     = gpioa_base + UINT32_C(0x0000);  // 32-bit register.
        constexpr std::uint32_t gpioa_otyper    = gpioa_base + UINT32_C(0x0004);  // 32-bit register.
        constexpr std::uint32_t gpioa_ospeedr   = gpioa_base + UINT32_C(0x0008);  // 32-bit register.
        constexpr std::uint32_t gpioa_pupdr     = gpioa_base + UINT32_C(0x000C);  // 32-bit register.
        constexpr std::uint32_t gpioa_idr       = gpioa_base + UINT32_C(0x0010);  // 32-bit register.
        constexpr std::uint32_t gpioa_odr       = gpioa_base + UINT32_C(0x0014);  // 32-bit register.
        constexpr std::uint32_t gpioa_bsrr      = gpioa_base + UINT32_C(0x0018);  // 32-bit register.
        constexpr std::uint32_t gpioa_lckr      = gpioa_base + UINT32_C(0x001C);  // 32-bit register.
        constexpr std::uint32_t gpioa_afrl      = gpioa_base + UINT32_C(0x0020);  // 32-bit register.
        constexpr std::uint32_t gpioa_afrh      = gpioa_base + UINT32_C(0x0024);  // 32-bit register.
        constexpr std::uint32_t gpioa_brr       = gpioa_base + UINT32_C(0x0028);  // 32-bit register.

        // Port B.
        constexpr std::uint32_t gpiob_moder     = gpiob_base + UINT32_C(0x0000);  // 32-bit register.
        constexpr std::uint32_t gpiob_otyper    = gpiob_base + UINT32_C(0x0004);  // 32-bit register.
        constexpr std::uint32_t gpiob_ospeedr   = gpiob_base + UINT32_C(0x0008);  // 32-bit register.
        constexpr std::uint32_t gpiob_pupdr     = gpiob_base + UINT32_C(0x000C);  // 32-bit register.
        constexpr std::uint32_t gpiob_idr       = gpiob_base + UINT32_C(0x0010);  // 32-bit register.
        constexpr std::uint32_t gpiob_odr       = gpiob_base + UINT32_C(0x0014);  // 32-bit register.
        constexpr std::uint32_t gpiob_bsrr      = gpiob_base + UINT32_C(0x0018);  // 32-bit register.
        constexpr std::uint32_t gpiob_lckr      = gpiob_base + UINT32_C(0x001C);  // 32-bit register.
        constexpr std::uint32_t gpiob_afrl      = gpiob_base + UINT32_C(0x0020);  // 32-bit register.
        constexpr std::uint32_t gpiob_afrh      = gpiob_base + UINT32_C(0x0024);  // 32-bit register.
        constexpr std::uint32_t gpiob_brr       = gpiob_base + UINT32_C(0x0028);  // 32-bit register.

        // Port C.
        constexpr std::uint32_t gpioc_moder     = gpioc_base + UINT32_C(0x0000);  // 32-bit register.
        constexpr std::uint32_t gpioc_otyper    = gpioc_base + UINT32_C(0x0004);  // 32-bit register.
        constexpr std::uint32_t gpioc_ospeedr   = gpioc_base + UINT32_C(0x0008);  // 32-bit register.
        constexpr std::uint32_t gpioc_pupdr     = gpioc_base + UINT32_C(0x000C);  // 32-bit register.
        constexpr std::uint32_t gpioc_idr       = gpioc_base + UINT32_C(0x0010);  // 32-bit register.
        constexpr std::uint32_t gpioc_odr       = gpioc_base + UINT32_C(0x0014);  // 32-bit register.
        constexpr std::uint32_t gpioc_bsrr      = gpioc_base + UINT32_C(0x0018);  // 32-bit register.
        constexpr std::uint32_t gpioc_lckr      = gpioc_base + UINT32_C(0x001C);  // 32-bit register.
        constexpr std::uint32_t gpioc_afrl      = gpioc_base + UINT32_C(0x0020);  // 32-bit register.
        constexpr std::uint32_t gpioc_afrh      = gpioc_base + UINT32_C(0x0024);  // 32-bit register.
        constexpr std::uint32_t gpioc_brr       = gpioc_base + UINT32_C(0x0028);  // 32-bit register.

        // Port D.
        constexpr std::uint32_t gpiod_moder     = gpiod_base + UINT32_C(0x0000);  // 32-bit register.
        constexpr std::uint32_t gpiod_otyper    = gpiod_base + UINT32_C(0x0004);  // 32-bit register.
        constexpr std::uint32_t gpiod_ospeedr   = gpiod_base + UINT32_C(0x0008);  // 32-bit register.
        constexpr std::uint32_t gpiod_pupdr     = gpiod_base + UINT32_C(0x000C);  // 32-bit register.
        constexpr std::uint32_t gpiod_idr       = gpiod_base + UINT32_C(0x0010);  // 32-bit register.
        constexpr std::uint32_t gpiod_odr       = gpiod_base + UINT32_C(0x0014);  // 32-bit register.
        constexpr std::uint32_t gpiod_bsrr      = gpiod_base + UINT32_C(0x0018);  // 32-bit register.
        constexpr std::uint32_t gpiod_lckr      = gpiod_base + UINT32_C(0x001C);  // 32-bit register.
        constexpr std::uint32_t gpiod_afrl      = gpiod_base + UINT32_C(0x0020);  // 32-bit register.
        constexpr std::uint32_t gpiod_afrh      = gpiod_base + UINT32_C(0x0024);  // 32-bit register.
        constexpr std::uint32_t gpiod_brr       = gpiod_base + UINT32_C(0x0028);  // 32-bit register.

        // Port E.
        constexpr std::uint32_t gpioe_moder     = gpioe_base + UINT32_C(0x0000);  // 32-bit register.
        constexpr std::uint32_t gpioe_otyper    = gpioe_base + UINT32_C(0x0004);  // 32-bit register.
        constexpr std::uint32_t gpioe_ospeedr   = gpioe_base + UINT32_C(0x0008);  // 32-bit register.
        constexpr std::uint32_t gpioe_pupdr     = gpioe_base + UINT32_C(0x000C);  // 32-bit register.
        constexpr std::uint32_t gpioe_idr       = gpioe_base + UINT32_C(0x0010);  // 32-bit register.
        constexpr std::uint32_t gpioe_odr       = gpioe_base + UINT32_C(0x0014);  // 32-bit register.
        constexpr std::uint32_t gpioe_bsrr      = gpioe_base + UINT32_C(0x0018);  // 32-bit register.
        constexpr std::uint32_t gpioe_lckr      = gpioe_base + UINT32_C(0x001C);  // 32-bit register.
        constexpr std::uint32_t gpioe_afrl      = gpioe_base + UINT32_C(0x0020);  // 32-bit register.
        constexpr std::uint32_t gpioe_afrh      = gpioe_base + UINT32_C(0x0024);  // 32-bit register.
        constexpr std::uint32_t gpioe_brr       = gpioe_base + UINT32_C(0x0028);  // 32-bit register.

        // Port F.
        constexpr std::uint32_t gpiof_moder     = gpiof_base + UINT32_C(0x0000);  // 32-bit register.
        constexpr std::uint32_t gpiof_otyper    = gpiof_base + UINT32_C(0x0004);  // 32-bit register.
        constexpr std::uint32_t gpiof_ospeedr   = gpiof_base + UINT32_C(0x0008);  // 32-bit register.
        constexpr std::uint32_t gpiof_pupdr     = gpiof_base + UINT32_C(0x000C);  // 32-bit register.
        constexpr std::uint32_t gpiof_idr       = gpiof_base + UINT32_C(0x0010);  // 32-bit register.
        constexpr std::uint32_t gpiof_odr       = gpiof_base + UINT32_C(0x0014);  // 32-bit register.
        constexpr std::uint32_t gpiof_bsrr      = gpiof_base + UINT32_C(0x0018);  // 32-bit register.
        constexpr std::uint32_t gpiof_lckr      = gpiof_base + UINT32_C(0x001C);  // 32-bit register.
        constexpr std::uint32_t gpiof_afrl      = gpiof_base + UINT32_C(0x0020);  // 32-bit register.
        constexpr std::uint32_t gpiof_afrh      = gpiof_base + UINT32_C(0x0024);  // 32-bit register.
        constexpr std::uint32_t gpiof_brr       = gpiof_base + UINT32_C(0x0028);  // 32-bit register.

        // --------------------------------------
        // Reset and Clock Control.
        constexpr std::uint32_t rcc_cr          = rcc_base + UINT32_C(0x0000);  /*!< RCC clock control register,                Address offset: 0x00 */
        constexpr std::uint32_t rcc_cfgr        = rcc_base + UINT32_C(0x0004);  /*!< RCC clock configuration register,          Address offset: 0x04 */
        constexpr std::uint32_t rcc_cir         = rcc_base + UINT32_C(0x0008);  /*!< RCC clock interrupt register,              Address offset: 0x08 */
        constexpr std::uint32_t rcc_apb2rstr    = rcc_base + UINT32_C(0x000C);  /*!< RCC APB2 peripheral reset register,        Address offset: 0x0C */
        constexpr std::uint32_t rcc_apb1rstr    = rcc_base + UINT32_C(0x0010);  /*!< RCC APB1 peripheral reset register,        Address offset: 0x10 */
        constexpr std::uint32_t rcc_ahbenr      = rcc_base + UINT32_C(0x0014);  /*!< RCC AHB peripheral clock register,         Address offset: 0x14 */
        constexpr std::uint32_t rcc_apb2enr     = rcc_base + UINT32_C(0x0018);  /*!< RCC APB2 peripheral clock enable register, Address offset: 0x18 */
        constexpr std::uint32_t rcc_apb1enr     = rcc_base + UINT32_C(0x001C);  /*!< RCC APB1 peripheral clock enable register, Address offset: 0x1C */
        constexpr std::uint32_t rcc_bdcr        = rcc_base + UINT32_C(0x0020);  /*!< RCC Backup domain control register,        Address offset: 0x20 */
        constexpr std::uint32_t rcc_csr         = rcc_base + UINT32_C(0x0024);  /*!< RCC clock control & status register,       Address offset: 0x24 */
        constexpr std::uint32_t rcc_ahbrstr     = rcc_base + UINT32_C(0x0028);  /*!< RCC AHB peripheral reset register,         Address offset: 0x28 */
        constexpr std::uint32_t rcc_cfgr2       = rcc_base + UINT32_C(0x002C);  /*!< RCC clock configuration register 2,        Address offset: 0x2C */
        constexpr std::uint32_t rcc_cfgr3       = rcc_base + UINT32_C(0x0030);  /*!< RCC clock configuration register 3,        Address offset: 0x30 */
    }
}

#endif // INCLUDE_MCAL_REG_H
