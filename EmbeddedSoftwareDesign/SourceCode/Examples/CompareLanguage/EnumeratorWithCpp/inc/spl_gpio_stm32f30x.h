#ifndef SPL_GPIO_STM32F30X_H_INCLUDED
#define SPL_GPIO_STM32F30X_H_INCLUDED

/********************************************//**
* \file     spl_gpio_stm32f30x.h
* \brief    SPL Module für GPIO Access.
* \author   Thomas Zöchbauer
* \version  V1.0
* \date     31-July-2015
***********************************************/

#ifdef __cplusplus
 extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32f30x.h"

namespace spl   // Standard Peripheral Library
{
    namespace gpio // General Purpose IO
    {
        /* Exported types ------------------------------------------------------------*/
        // General Purpose I/O
        struct Gpio_TypeDef
        {
            __IO uint32_t MODER;        /*!< GPIO port mode register,                  Address offset: 0x00 */
            __IO uint16_t OTYPER;       /*!< GPIO port output type register,           Address offset: 0x04 */
            uint16_t RESERVED0;         /*!< Reserved,                                                 0x06 */
            __IO uint32_t OSPEEDR;      /*!< GPIO port output speed register,          Address offset: 0x08 */
            __IO uint32_t PUPDR;        /*!< GPIO port pull-up/pull-down register,     Address offset: 0x0C */
            __IO uint16_t IDR;          /*!< GPIO port input data register,            Address offset: 0x10 */
            uint16_t RESERVED1;         /*!< Reserved,                                                 0x12 */
            __IO uint16_t ODR;          /*!< GPIO port output data register,           Address offset: 0x14 */
            uint16_t RESERVED2;         /*!< Reserved,                                                 0x16 */
            __IO uint32_t BSRR;         /*!< GPIO port bit set/reset registerBSRR,     Address offset: 0x18 */
            __IO uint32_t LCKR;         /*!< GPIO port configuration lock register,    Address offset: 0x1C */
            __IO uint32_t AFR[2];       /*!< GPIO alternate function low register,     Address offset: 0x20-0x24 */
            __IO uint16_t BRR;          /*!< GPIO bit reset register,                  Address offset: 0x28 */
            uint16_t RESERVED3;         /*!< Reserved,                                                 0x2A */
        };

        constexpr Gpio_TypeDef* gpioa = ((Gpio_TypeDef *) GPIOA_BASE);
        constexpr Gpio_TypeDef* gpiob = ((Gpio_TypeDef *) GPIOB_BASE);
        constexpr Gpio_TypeDef* gpioc = ((Gpio_TypeDef *) GPIOC_BASE);
        constexpr Gpio_TypeDef* gpiod = ((Gpio_TypeDef *) GPIOD_BASE);
        constexpr Gpio_TypeDef* gpioe = ((Gpio_TypeDef *) GPIOE_BASE);
        constexpr Gpio_TypeDef* gpiof = ((Gpio_TypeDef *) GPIOF_BASE);


        constexpr bool is_gpio_all_periph(Gpio_TypeDef * gpio)
        {
            return (((gpio) == gpioa) ||
                    ((gpio) == gpiob) ||
                    ((gpio) == gpioc) ||
                    ((gpio) == gpiod) ||
                    ((gpio) == gpioe) ||
                    ((gpio) == gpiof));
        }

        constexpr bool is_gpio_list_periph(Gpio_TypeDef * gpio)
        {
            return (((gpio) == gpioa) ||
                    ((gpio) == gpiob) ||
                    ((gpio) == gpiod));
        }

        // Configuration_Mode_enumeration
        enum class Mode_TypeDef
        {
            in  = 0x00, /*!< GPIO Input Mode */
            out = 0x01, /*!< GPIO Output Mode */
            af  = 0x02, /*!< GPIO Alternate function Mode */
            an  = 0x03  /*!< GPIO Analog In/Out Mode      */
        };

        constexpr bool is_gpio_mode(Mode_TypeDef mode)
        {
            return (((mode) == Mode_TypeDef::in) || ((mode) == Mode_TypeDef::out) ||
                    ((mode) == Mode_TypeDef::af) || ((mode) == Mode_TypeDef::an));
        }

        // Output_type_enumeration
        enum class OType_TypeDef
        {
            pp = 0x00,    // Push-Pull.
            od = 0x01     // Open Drain.
        };

        constexpr bool is_gpio_otype(OType_TypeDef otype)
        {
            return (((otype) == OType_TypeDef::pp) || ((otype) == OType_TypeDef::od));
        }

        // Output_Maximum_frequency_enumeration
        enum class Speed_TypeDef
        {
            level_1  = 0x01, /*!< Fast Speed     */
            level_2  = 0x02, /*!< Meduim Speed   */
            level_3  = 0x03  /*!< High Speed     */
        };

        constexpr bool is_gpio_speed(Speed_TypeDef speed)
        {
            return (((speed) == Speed_TypeDef::level_1) || ((speed) == Speed_TypeDef::level_2) ||
                                      ((speed) == Speed_TypeDef::level_3));
        }

        // Configuration_Pull-Up_Pull-Down_enumeration
        enum class PuPd_TypeDef
        {
            nopull = 0x00,
            up     = 0x01,
            down   = 0x02
        };

        constexpr bool is_gpio_pupd(PuPd_TypeDef pupd)
        {
            return (((pupd) == PuPd_TypeDef::nopull) || ((pupd) == PuPd_TypeDef::up) ||
                                    ((pupd) == PuPd_TypeDef::down));
        }

        // Bit_SET_and_Bit_RESET_enumeration
        enum class BitAction
        {
            reset = 0,
            set
        };

        constexpr bool is_gpio_bit_action(BitAction action)
        {
            return (((action) == BitAction::reset) || ((action) == BitAction::set));
        }

        // GPIO Init structure definition
        struct InitTypeDef
        {
            uint32_t Pin;          /*!< Specifies the GPIO pins to be configured.
                                        This parameter can be any value of @ref GPIO_pins_define */

            Mode_TypeDef Mode;     /*!< Specifies the operating mode for the selected pins.
                                        This parameter can be a value of @ref GPIOMode_TypeDef   */

            Speed_TypeDef Speed;   /*!< Specifies the speed for the selected pins.
                                        This parameter can be a value of @ref GPIOSpeed_TypeDef  */

            OType_TypeDef OType;   /*!< Specifies the operating output type for the selected pins.
                                        This parameter can be a value of @ref GPIOOType_TypeDef  */

            PuPd_TypeDef PuPd;     /*!< Specifies the operating Pull-up/Pull down for the selected pins.
                                        This parameter can be a value of @ref GPIOPuPd_TypeDef   */
        };

        /* Exported constants --------------------------------------------------------*/
        // pins_define
        constexpr uint16_t Pin_0   = 0x0001;  /*!< Pin 0 selected    */
        constexpr uint16_t Pin_1   = 0x0002;  /*!< Pin 1 selected    */
        constexpr uint16_t Pin_2   = 0x0004;  /*!< Pin 2 selected    */
        constexpr uint16_t Pin_3   = 0x0008;  /*!< Pin 3 selected    */
        constexpr uint16_t Pin_4   = 0x0010;  /*!< Pin 4 selected    */
        constexpr uint16_t Pin_5   = 0x0020;  /*!< Pin 5 selected    */
        constexpr uint16_t Pin_6   = 0x0040;  /*!< Pin 6 selected    */
        constexpr uint16_t Pin_7   = 0x0080;  /*!< Pin 7 selected    */
        constexpr uint16_t Pin_8   = 0x0100;  /*!< Pin 8 selected    */
        constexpr uint16_t Pin_9   = 0x0200;  /*!< Pin 9 selected    */
        constexpr uint16_t Pin_10  = 0x0400;  /*!< Pin 10 selected   */
        constexpr uint16_t Pin_11  = 0x0800;  /*!< Pin 11 selected   */
        constexpr uint16_t Pin_12  = 0x1000;  /*!< Pin 12 selected   */
        constexpr uint16_t Pin_13  = 0x2000;  /*!< Pin 13 selected   */
        constexpr uint16_t Pin_14  = 0x4000;  /*!< Pin 14 selected   */
        constexpr uint16_t Pin_15  = 0x8000;  /*!< Pin 15 selected   */
        constexpr uint16_t Pin_All = 0xFFFF;  /*!< All pins selected */

        constexpr bool is_gpio_pin(uint16_t pin)
        {
            return ((pin) != (uint16_t)0x00);
        }

//        #define IS_GET_GPIO_PIN(PIN) (((PIN) == GPIO_Pin_0) || \
//                                      ((PIN) == GPIO_Pin_1) || \
//                                      ((PIN) == GPIO_Pin_2) || \
//                                      ((PIN) == GPIO_Pin_3) || \
//                                      ((PIN) == GPIO_Pin_4) || \
//                                      ((PIN) == GPIO_Pin_5) || \
//                                      ((PIN) == GPIO_Pin_6) || \
//                                      ((PIN) == GPIO_Pin_7) || \
//                                      ((PIN) == GPIO_Pin_8) || \
//                                      ((PIN) == GPIO_Pin_9) || \
//                                      ((PIN) == GPIO_Pin_10) || \
//                                      ((PIN) == GPIO_Pin_11) || \
//                                      ((PIN) == GPIO_Pin_12) || \
//                                      ((PIN) == GPIO_Pin_13) || \
//                                      ((PIN) == GPIO_Pin_14) || \
//                                      ((PIN) == GPIO_Pin_15))

        /**
          * @}
          */

        // Pin_sources
        constexpr uint8_t PinSource0  = 0x00;
        constexpr uint8_t PinSource1  = 0x01;
        constexpr uint8_t PinSource2  = 0x02;
        constexpr uint8_t PinSource3  = 0x03;
        constexpr uint8_t PinSource4  = 0x04;
        constexpr uint8_t PinSource5  = 0x05;
        constexpr uint8_t PinSource6  = 0x06;
        constexpr uint8_t PinSource7  = 0x07;
        constexpr uint8_t PinSource8  = 0x08;
        constexpr uint8_t PinSource9  = 0x09;
        constexpr uint8_t PinSource10 = 0x0A;
        constexpr uint8_t PinSource11 = 0x0B;
        constexpr uint8_t PinSource12 = 0x0C;
        constexpr uint8_t PinSource13 = 0x0D;
        constexpr uint8_t PinSource14 = 0x0E;
        constexpr uint8_t PinSource15 = 0x0F;

//        #define IS_GPIO_PIN_SOURCE(PINSOURCE) (((PINSOURCE) == GPIO_PinSource0) || \
//                                               ((PINSOURCE) == GPIO_PinSource1) || \
//                                               ((PINSOURCE) == GPIO_PinSource2) || \
//                                               ((PINSOURCE) == GPIO_PinSource3) || \
//                                               ((PINSOURCE) == GPIO_PinSource4) || \
//                                               ((PINSOURCE) == GPIO_PinSource5) || \
//                                               ((PINSOURCE) == GPIO_PinSource6) || \
//                                               ((PINSOURCE) == GPIO_PinSource7) || \
//                                               ((PINSOURCE) == GPIO_PinSource8) || \
//                                               ((PINSOURCE) == GPIO_PinSource9) || \
//                                               ((PINSOURCE) == GPIO_PinSource10) || \
//                                               ((PINSOURCE) == GPIO_PinSource11) || \
//                                               ((PINSOURCE) == GPIO_PinSource12) || \
//                                               ((PINSOURCE) == GPIO_PinSource13) || \
//                                               ((PINSOURCE) == GPIO_PinSource14) || \
//                                               ((PINSOURCE) == GPIO_PinSource15))
        /**
          * @}
          */

        //Alternate_function_selection_define
        constexpr uint8_t AF_0 = 0x00; /* JTCK-SWCLK, JTDI, JTDO/TRACESW0, JTMS-SWDAT,
                                            MCO, NJTRST, TRACED, TRACECK */
        constexpr uint8_t AF_1 = 0x01; /*  OUT, TIM2, TIM15, TIM16, TIM17 */
        constexpr uint8_t AF_2 = 0x02; /* COMP1_OUT, TIM1, TIM2, TIM3, TIM4, TIM8, TIM15 */
        constexpr uint8_t AF_3 = 0x03; /* COMP7_OUT, TIM8, TIM15, Touch */
        constexpr uint8_t AF_4 = 0x04; /* I2C1, I2C2, TIM1, TIM8, TIM16, TIM17 */
        constexpr uint8_t AF_5 = 0x05; /* IR_OUT, I2S2, I2S3, SPI1, SPI2, TIM8, USART4, USART5 */
        constexpr uint8_t AF_6 = 0x06; /*  IR_OUT, I2S2, I2S3, SPI2, SPI3, TIM1, TIM8 */
        constexpr uint8_t AF_7 = 0x07; /* AOP2_OUT, CAN, COMP3_OUT, COMP5_OUT, COMP6_OUT,
                                            USART1, USART2, USART3 */
        constexpr uint8_t AF_8 = 0x08; /* COMP1_OUT, COMP2_OUT, COMP3_OUT, COMP4_OUT,
                                            COMP5_OUT, COMP6_OUT */
        constexpr uint8_t AF_9 = 0x09; /* AOP4_OUT, CAN, TIM1, TIM8, TIM15 */
        constexpr uint8_t AF_10 = 0x0A; /* AOP1_OUT, AOP3_OUT, TIM2, TIM3, TIM4, TIM8, TIM17 */
        constexpr uint8_t AF_11 = 0x0B; /* TIM1, TIM8 */
        constexpr uint8_t AF_12 = 0x0E; /* TIM1 */
        constexpr uint8_t AF_14 = 0x0E; /* USBDM, USBDP */
        constexpr uint8_t AF_15 = 0x0F; /* OUT */

//        #define IS_GPIO_AF(AF)   (((AF) == GPIO_AF_0)||((AF) == GPIO_AF_1)||\
//                                  ((AF) == GPIO_AF_2)||((AF) == GPIO_AF_3)||\
//                                  ((AF) == GPIO_AF_4)||((AF) == GPIO_AF_5)||\
//                                  ((AF) == GPIO_AF_6)||((AF) == GPIO_AF_7)||\
//                                  ((AF) == GPIO_AF_8)||((AF) == GPIO_AF_9)||\
//                                  ((AF) == GPIO_AF_10)||((AF) == GPIO_AF_11)||\
//                                  ((AF) == GPIO_AF_14)||((AF) == GPIO_AF_15))


        /** @defgroup GPIO_Speed_Legacy
          * @{
          */

        constexpr Speed_TypeDef Speed_10MHz = Speed_TypeDef::level_1;   /*!< Fast Speed:10MHz   */
        constexpr Speed_TypeDef Speed_2MHz  = Speed_TypeDef::level_2;   /*!< Medium Speed:2MHz  */
        constexpr Speed_TypeDef Speed_50MHz = Speed_TypeDef::level_3;   /*!< High Speed:50MHz   */


        /* Exported macro ------------------------------------------------------------*/
        /* Exported functions ------------------------------------------------------- */
        /* Function used to set the GPIO configuration to the default reset state *****/
        //void DeInit(GPIO_TypeDef* GPIOx);

        /* Initialization and Configuration functions *********************************/
        void Init(Gpio_TypeDef* GPIOx, InitTypeDef* InitStruct);
        //void GPIO_StructInit(GPIO_InitTypeDef* GPIO_InitStruct);
        //void GPIO_PinLockConfig(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin);

        /* GPIO Read and Write functions **********************************************/
        //uint8_t GPIO_ReadInputDataBit(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin);
        //uint16_t GPIO_ReadInputData(GPIO_TypeDef* GPIOx);
        //uint8_t GPIO_ReadOutputDataBit(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin);
        //uint16_t GPIO_ReadOutputData(GPIO_TypeDef* GPIOx);
        void SetBits(Gpio_TypeDef* GPIOx, uint16_t Pin);
        void ResetBits(Gpio_TypeDef* GPIOx, uint16_t Pin);
        //void GPIO_WriteBit(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin, BitAction BitVal);
        //void GPIO_Write(GPIO_TypeDef* GPIOx, uint16_t PortVal);

        /* GPIO Alternate functions configuration functions ***************************/
        //void GPIO_PinAFConfig(GPIO_TypeDef* GPIOx, uint16_t GPIO_PinSource, uint8_t GPIO_AF);
    }
}


#ifdef __cplusplus
}
#endif


#endif /* SPL_GPIO_STM32F30X_H_INCLUDED */
