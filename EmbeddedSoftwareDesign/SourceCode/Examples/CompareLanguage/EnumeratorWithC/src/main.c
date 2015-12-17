/******************************************************//**
* \file     main.c
* \brief    The Main Program.
* \author   Thomas Zöchbauer
* \version  V1.0
* \date     01-August-2015
**********************************************************/

#include "stm32f30x_conf.h"
#include "stm32f3_discovery_systick.h"
#include "stm32f30x_rcc.h"
#include "stm32f30x_gpio.h"

//#define OUT     0x0E    // Define OUT before uesed in enum Mode.

// Definition of Mode enumeration:
enum Mode
{
	IN   = 0x00, // Input Mode
	OUT  = 0x01, // Output Mode
	AF   = 0x02, // Alternate function Mode
	AN   = 0x03,  // Analog In/Out Mode
	FIRST_MODE = IN,
	LAST_MODE = AN,
	NUM_MODES = 0x04    // Number of Modes.
};

// Define another Enumerator:
// Definition of Pull-Up and Pull-Down enumeration:
enum PuPd
{
    NOPULL = 0x00,
    UP     = 0x01,
    DOWN   = 0x02
    //, OUT           // error: redeclaration of enumerator 'OUT'
};

//#define OUT 0x0E    // Overwrite OUT from enum Mode.

typedef enum Mode Mode_TypeDef;
typedef enum PuPd PuPd_TypeDef;


int main(void)
{
    SystemInit();
    // Init SysTick.
    SystemCoreClockUpdate();
    if (SysTick_Config(SystemCoreClock / 1000) != 0)
    {
        /* Capture error */
        while (1);
    }

    /* ----------------------------------------------- */
    /* "Normal" Enumerator Usage */

    // Usage of Mode enumeration:
    enum Mode mode0 = OUT;
    enum Mode mode1 = IN;

    enum Mode mode3 = 0x03;    // Same as AN.

    int mode_var = OUT;         // Same as 0x01.
    enum Mode mode4 = mode_var; // Same as OUT.

    enum Mode mode5 = 0x0A;     // Not a valid Mode, but a valid cast.

    /* ----------------------------------------------- */
    /* "Mixed" Enumerator Usage */

    enum Mode mode6 = NOPULL;   // Mode variable gets a PuPd value.
    enum PuPd pupd0 = OUT;      // PuPd variable gets a Mode value.

    /* ----------------------------------------------- */
    /* Variable Names: */

    int OUT = DOWN;         // OUT == 2
    enum Mode mode7 = OUT;  // mode7 ?= OUT or AF.




//    Mode_TypeDef mode6 = AN;
//    Mode_TypeDef mode7 = IN;
//    Mode_TypeDef mode8 = 0x0B;  // Not a valid Mode.
//    Mode_TypeDef mode9 = 0x0C;  // Not a valid Mode.


    // Enable the GPIOE Clock.
    RCC_AHBPeriphClockCmd(RCC_AHBPeriph_GPIOE, ENABLE);

    // Initialize GPIOE.9 as output (pin is connected to LED3):
    GPIO_InitTypeDef InitStructure;
    InitStructure.GPIO_Mode = GPIO_Mode_OUT;
    InitStructure.GPIO_OType = GPIO_OType_PP;
    InitStructure.GPIO_PuPd = GPIO_PuPd_UP;
    InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    InitStructure.GPIO_Pin = GPIO_Pin_9;
    GPIO_Init(GPIOE, &InitStructure);

    while(1)
    {
        GPIO_SetBits(GPIOE, GPIO_Pin_9);
        Delay(500);
        GPIO_ResetBits(GPIOE, GPIO_Pin_9);
        Delay(200);
    }
}
