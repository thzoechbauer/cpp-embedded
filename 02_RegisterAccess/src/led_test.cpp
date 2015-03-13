#include "mcal_reg.h"
#include "mcal_reg_map.h"
#include "led_test.h"

/******************************* LED 6 ***********************************/

constexpr std::uint16_t led6_pin_bp = 15;
constexpr std::uint32_t led6_pin_bm = 1 << led6_pin_bp;
constexpr std::uint32_t led6_gpio_clk_bm = 1 << 21;
constexpr std::uint32_t led6_gpio_moder = mcal::reg::gpioe_moder;
constexpr std::uint32_t led6_gpio_otyper = mcal::reg::gpioe_otyper;
constexpr std::uint32_t led6_gpio_ospeedr = mcal::reg::gpioe_ospeedr;
constexpr std::uint32_t led6_gpio_pupdr = mcal::reg::gpioe_pupdr;
constexpr std::uint32_t led6_gpio_odr = mcal::reg::gpioe_odr;

template<const std::uint32_t addr>
using reg_map_32 = mcal::reg::reg_map<std::uint32_t, std::uint32_t, mcal::reg::bit32_type, addr>;

void led6::init()
{
    ///< Init Peripheral Clock.
    reg_map_32<mcal::reg::rcc_ahbenr>::value() |= led6_gpio_clk_bm;

    ///< Init LED-Pin of GPIO.
    /* Speed mode configuration: High Speed (0x03) */
    reg_map_32<led6_gpio_ospeedr>::value() |= ((std::uint32_t)0x03 << (led6_pin_bp * 2));

    /* Output type configuration: Push-Pull (0x00) */
    reg_map_32<led6_gpio_otyper>::value() &= ~((std::uint32_t)0x01 << led6_pin_bp);

    /* Output mode configuration: General Purpose Output Mode (0x01) */
    reg_map_32<led6_gpio_moder>::value() &= ~((std::uint32_t)0x03 << (led6_pin_bp * 2));
    reg_map_32<led6_gpio_moder>::value() |= ((std::uint32_t)0x01 << (led6_pin_bp * 2));

    /* Pull-up Pull down resistor configuration: No Pull (0x00) */
    reg_map_32<led6_gpio_pupdr>::value() &= ~((std::uint32_t)0x03 << (led6_pin_bp * 2));

    led6::off();
}

void led6::on()
{
    reg_map_32<led6_gpio_odr>::value() |= led6_pin_bm;
}

void led6::off()
{
    reg_map_32<led6_gpio_odr>::value() &= ~led6_pin_bm;
}

void led6::toggle()
{
    reg_map_32<led6_gpio_odr>::value() ^= led6_pin_bm;
}

/******************************* LED 7 ***********************************/

constexpr std::uint16_t led7_pin_bp = 11;
constexpr std::uint32_t led7_pin_bm = 1 << led7_pin_bp;
constexpr std::uint32_t led7_gpio_clk_bm = 1 << 21;
constexpr std::uint32_t led7_gpio_moder = mcal::reg::gpioe_moder;
constexpr std::uint32_t led7_gpio_otyper = mcal::reg::gpioe_otyper;
constexpr std::uint32_t led7_gpio_ospeedr = mcal::reg::gpioe_ospeedr;
constexpr std::uint32_t led7_gpio_pupdr = mcal::reg::gpioe_pupdr;
constexpr std::uint32_t led7_gpio_odr = mcal::reg::gpioe_odr;

template<const std::uint32_t addr>
using reg_map_32 = mcal::reg::reg_map<std::uint32_t, std::uint32_t, mcal::reg::bit32_type, addr>;

void led7::init()
{
    ///< Init Peripheral Clock.
    reg_map_32<mcal::reg::rcc_ahbenr>::value() |= led7_gpio_clk_bm;

    ///< Init LED-Pin of GPIO.
    /* Speed mode configuration: High Speed (0x03) */
    reg_map_32<led7_gpio_ospeedr>::value() |= ((std::uint32_t)0x03 << (led7_pin_bp * 2));

    /* Output type configuration: Push-Pull (0x00) */
    reg_map_32<led7_gpio_otyper>::value() &= ~((std::uint32_t)0x01 << led7_pin_bp);

    /* Output mode configuration: General Purpose Output Mode (0x01) */
    reg_map_32<led7_gpio_moder>::value() &= ~((std::uint32_t)0x03 << (led7_pin_bp * 2));
    reg_map_32<led7_gpio_moder>::value() |= ((std::uint32_t)0x01 << (led7_pin_bp * 2));

    /* Pull-up Pull down resistor configuration: No Pull (0x00) */
    reg_map_32<led7_gpio_pupdr>::value() &= ~((std::uint32_t)0x03 << (led7_pin_bp * 2));

    led7::off();
}

void led7::on()
{
    reg_map_32<led7_gpio_odr>::value() |= led7_pin_bm;
}

void led7::off()
{
    reg_map_32<led7_gpio_odr>::value() &= ~led7_pin_bm;
}

void led7::toggle()
{
    reg_map_32<led7_gpio_odr>::value() ^= led7_pin_bm;
}
