/*
 * testFuncs.cpp
 *
 *  Created on: 2016/10/19
 *      Author: admin
 */


#include "testFuncs.hpp"
#include "stm32f4xx_hal.h"
#include "gpio.h"
#include "tim.h"
#include "stm32f4_discovery.h"

static void callBack_GPIO_B1Pin();
static void callBack_Timer2();

void testGPIO_SystikBlink()
{
	GPIOInitialize();

	BSP_LED_Init(LED3);

	while(1){
		BSP_LED_Toggle(LED3);
		HAL_Delay(1000);
	  }
}
void testGPIO_ButtonInterruptBlink()
{
	GPIOInitialize();

	BSP_LED_Init(LED4);

	GPIOIRQAttach((void*)callBack_GPIO_B1Pin,PA0,GPIO_MODE_IT_RISING);

	while(1){

	}
}
void testGPIO_TimerInterruptBlink()
{
	GPIOInitialize();
	TimerInitialize();

	BSP_LED_Init(LED5);

	TimerIRQAttach((void*)callBack_Timer2);

	TimerStart();
}
void callBack_GPIO_B1Pin()
{
	BSP_LED_Toggle(LED4);
}
void callBack_Timer2()
{
	BSP_LED_Toggle(LED5);
}
