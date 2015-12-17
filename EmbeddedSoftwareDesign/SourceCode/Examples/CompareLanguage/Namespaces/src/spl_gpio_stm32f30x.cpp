/********************************************//**
* \file     spl_gpio_stm32f30x.cpp
* \brief    SPL Module für GPIO Access.
* \author   Thomas Zöchbauer
* \version  V1.0
* \date     31-July-2015
***********************************************/

#include "spl_gpio_stm32f30x.h"
#include "stm32f30x_conf.h"

namespace spl
{
    namespace gpio
    {
        void Init(Gpio_Type* GPIOx, InitType* InitStruct)
        {
            uint32_t pinpos = 0x00, pos = 0x00 , currentpin = 0x00;

            /* Check the parameters */
            assert_param(is_gpio_all_periph(GPIOx));
            assert_param(is_gpio_pin(InitStruct->Pin));

            /*-------------------------- Configure the port pins -----------------------*/
            /*-- GPIO Mode Configuration --*/
            for (pinpos = 0x00; pinpos < 0x10; pinpos++)
            {
                pos = ((uint32_t)0x01) << pinpos;

                /* Get the port pins position */
                currentpin = (InitStruct->Pin) & pos;

                if (currentpin == pos)
                {
                    if ((InitStruct->Mode == Mode_Type::out) || (InitStruct->Mode == Mode_Type::af))
                    {
                        /* Speed mode configuration */
                        GPIOx->OSPEEDR &= ~(GPIO_OSPEEDER_OSPEEDR0 << (pinpos * 2));
                        GPIOx->OSPEEDR |= ((uint32_t)(InitStruct->Speed) << (pinpos * 2));

                        /* Output mode configuration */
                        GPIOx->OTYPER &= ~((GPIO_OTYPER_OT_0) << ((uint16_t)pinpos));
                        GPIOx->OTYPER |= (uint16_t)(((uint16_t)InitStruct->OType) << ((uint16_t)pinpos));
                    }

                    GPIOx->MODER  &= ~(GPIO_MODER_MODER0 << (pinpos * 2));

                    GPIOx->MODER |= (((uint32_t)InitStruct->Mode) << (pinpos * 2));

                    /* Pull-up Pull down resistor configuration */
                    GPIOx->PUPDR &= ~(GPIO_PUPDR_PUPDR0 << ((uint16_t)pinpos * 2));
                    GPIOx->PUPDR |= (((uint32_t)InitStruct->PuPd) << (pinpos * 2));
                }
            }
        }


        void SetBits(Gpio_Type* GPIOx, uint16_t Pin)
        {
            /* Check the parameters */
            assert_param(is_gpio_all_periph(GPIOx));
            assert_param(is_gpio_pin(Pin));

            GPIOx->BSRR = Pin;
        }

        void ResetBits(Gpio_Type* GPIOx, uint16_t Pin)
        {
            /* Check the parameters */
            assert_param(is_gpio_all_periph(GPIOx));
            assert_param(is_gpio_pin(Pin));

            GPIOx->BRR = Pin;
        }
    }
}

