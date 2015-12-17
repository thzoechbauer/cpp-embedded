#ifndef LED_H_INCLUDED
#define LED_H_INCLUDED

/********************************************//**
* \file     led.h
* \brief    Definition of Led-Class.
* \author   Thomas Zöchbauer
* \version  V1.0
* \date     26-July-2015
************************************************/

#include <cstdint>
#include "stm32f30x_gpio.h"
#include "stm32f30x_rcc.h"


// Number of LEDs mounted on STM32F3Discovery.
constexpr uint8_t num_leds = 8U;

// Enumeration of LEDs mounted on STM32F3Discovery.
enum class led_enum_t : uint8_t
{
    led3 = 0,
    led4 = 1,
    led5 = 2,
    led6 = 3,
    led7 = 4,
    led8 = 5,
    led9 = 6,
    led10 = 7
};

class Led
{
private:
    // Attributes:
    GPIO_TypeDef* const mPort;
    uint16_t const mPin;
    uint32_t const mClock;

public:
    // CTor:
    Led(led_enum_t const led_enum);
    Led() = delete;							// Delete Default CTor.
    Led(const Led& rhs) = delete;			// Delete Default Copy CTor.

	// DTor:
    ~Led() = default;                       // Set Default DTor.

    // Operators:
    Led& operator=(const Led& rhs) = delete; // Delete Assignment Operator.

    // Functions:
    void init() const;                      // Initialze LED.
    void enable(bool enable) const;         // Enable or Disable LED.
    //void enable(int) = delete; // Forbid to call function with param of type int.
    void toggle() const;                    // Toggle LED.
};

class Led_static
{
private:
    // No private variables or functions!
public:
    // CTor:
    Led_static() = delete;     // Delete default constructor.
    Led_static(const Led_static& rhs) = delete;  // Delete copy constructor.
    // Operators:
    Led_static& operator=(const Led_static& rhs) = delete; // Delete assignment operator.
    // DTor:
    ~Led_static() = default;   // Set default destructor.

    // Static Functions:
    static void init(led_enum_t const led_enum);
    static void enable(led_enum_t const led_enum, bool enable);
    static void toggle(led_enum_t const led_enum);
};



#endif /* LED_H_INCLUDED */
