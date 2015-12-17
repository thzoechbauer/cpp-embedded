/********************************************//**
 *  \brief
 *  \author    Thomas Zöchbauer
 *  \version   V1.0
 *  \date
 ***********************************************/

 #include "stm32f3_discovery_systick.h"

 /* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
static __IO uint32_t TimingDelay;
__IO uint32_t Systick_Time = 0;

/* Private function prototypes -----------------------------------------------*/
void Delay(__IO uint32_t nTime);

/* Private functions ---------------------------------------------------------*/

/**
  * @brief  Inserts a delay time.
  * @param  nTime: specifies the delay time length, in milliseconds.
  * @retval None
  */
void Delay(__IO uint32_t nTime)
{
  TimingDelay = nTime;

  while(TimingDelay != 0);
}

/**
  * @brief  Decrements the TimingDelay variable.
  * @param  None
  * @retval None
  */
//void TimingDelay_Decrement(void)
void __sys_tick_handler()
{
  if (TimingDelay != 0x00)
  {
    TimingDelay--;
  }
  Systick_Time++;
}
