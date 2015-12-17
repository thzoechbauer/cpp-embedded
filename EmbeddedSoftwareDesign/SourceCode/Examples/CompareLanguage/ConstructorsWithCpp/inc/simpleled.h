#ifndef SIMPLE_LED_H_INCLUDED
#define SIMPLE_LED_H_INCLUDED

/********************************************//**
* \file     simpleled.h
* \brief    Show default CTors with simple Led class.
* \author   Thomas Zöchbauer
* \version  V1.0
* \date     07-August-2015
***********************************************/

#include "stm32f30x_gpio.h"

class SimpleLed
{
private:
    GPIO_TypeDef* const mPort = nullptr;    // Directly initalized.
    uint16_t const mPin = 0;                // Directly initalized.
    uint32_t const mClock = 0;              // Directly initalized.

public:
    // Default CTors, DTors and Ops:
	SimpleLed() = delete;								// Default CTor.
	~SimpleLed() = default;								// Default DTor.
	SimpleLed(const SimpleLed& rhs) = delete;			// Default Copy CTor.
	SimpleLed(SimpleLed&& rhs) = delete;				// Default Move CTor.
	SimpleLed& operator=(const SimpleLed& rhs) = delete;// Default Assignment Operator.
	SimpleLed& operator=(SimpleLed&& rhs) = delete;		// Default Move Assignment Operator.

    // User defined CTor:
    SimpleLed(GPIO_TypeDef* const port, uint16_t pin, uint32_t clock) : mPort(port), mPin(pin), mClock(clock) {}
};


#endif // SIMPLE_LED_H_INCLUDED
