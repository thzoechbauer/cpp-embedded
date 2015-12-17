#ifndef STM32F3_DISCOVERY_SYSTICK_H_INCLUDED
#define STM32F3_DISCOVERY_SYSTICK_H_INCLUDED

/********************************************//**
 *  \brief
 *  \author    Thomas Zöchbauer
 *  \version   V1.0
 *  \date
 ***********************************************/

 #include "stm32f30x.h"

/* Exported types ------------------------------------------------------------*/
/* Exported constants --------------------------------------------------------*/
/* Exported macro ------------------------------------------------------------*/
/* Exported functions ------------------------------------------------------- */
void TimingDelay_Decrement(void);
void Delay(__IO uint32_t nTime);


#endif /* STM32F3_DISCOVERY_SYSTICK_H_INCLUDED */
