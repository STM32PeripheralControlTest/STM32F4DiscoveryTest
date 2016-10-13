/**
  ******************************************************************************
  * @file    main.c
  * @author  Ac6
  * @version V1.0
  * @date    01-December-2013
  * @brief   Default main function.
  ******************************************************************************
*/


#include "stm32f4xx_hal.h"
#include "stm32f4_discovery.h"
			

int main(void)
{
	BSP_LED_Init(LED3);

	while(1){
		BSP_LED_Toggle(LED3);
		HAL_Delay(1000);
	}
}
