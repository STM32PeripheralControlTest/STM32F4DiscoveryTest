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
#include "adc.h"
#include "stm32f4_discovery.h"

static void callBack_GPIO_B1Pin();
static void callBack_Timer2();

static uint8_t isConverting = 0;
static uint32_t adcData = 0;
static void callBack_ADCComplete();
static void callBack_Timer2_forADC();

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
void testADC_TimerInterrupt()
{
	GPIOInitialize();

	TimerInitialize();
	TimerIRQAttach((void*)&callBack_Timer2_forADC);

	ADCInitialize();
	ADCIRQAttach((void*)&callBack_ADCComplete);

	TimerStart();

	while(1){

	}
}
void callBack_Timer2_forADC()
{
	if(!isConverting){
		ADCStart();

		isConverting = 1;
	}
}
void callBack_ADCComplete()
{
	isConverting = 0;

	adcData = ADCGetValue();
}
