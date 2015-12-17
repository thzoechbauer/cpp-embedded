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

#ifdef __cplusplus
 extern "C" {
#endif /* __cplusplus */
    void TimingDelay_Decrement(void);
    void Delay(__IO uint32_t nTime);
#ifdef __cplusplus
}
#endif /* __cplusplus */




#endif /* STM32F3_DISCOVERY_SYSTICK_H_INCLUDED */
