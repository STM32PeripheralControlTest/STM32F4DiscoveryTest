/**
  ******************************************************************************
  * File Name          : gpio.c
  * Description        : This file provides code for the configuration
  *                      of all used GPIO pins.
  ******************************************************************************
  *
  * COPYRIGHT(c) 2016 STMicroelectronics
  *
  * Redistribution and use in source and binary forms, with or without modification,
  * are permitted provided that the following conditions are met:
  *   1. Redistributions of source code must retain the above copyright notice,
  *      this list of conditions and the following disclaimer.
  *   2. Redistributions in binary form must reproduce the above copyright notice,
  *      this list of conditions and the following disclaimer in the documentation
  *      and/or other materials provided with the distribution.
  *   3. Neither the name of STMicroelectronics nor the names of its contributors
  *      may be used to endorse or promote products derived from this software
  *      without specific prior written permission.
  *
  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
  * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
  * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
  * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
  * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
  * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
  * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
  *
  ******************************************************************************
  */

/* Includes ------------------------------------------------------------------*/
#include "gpio.h"
/* USER CODE BEGIN 0 */
typedef struct{
	GPIO_TypeDef* group;
	uint16_t pinNumber;
}GPIO_PIN_DEF_t;
/* USER CODE END 0 */

/*----------------------------------------------------------------------------*/
/* Configure GPIO                                                             */
/*----------------------------------------------------------------------------*/
/* USER CODE BEGIN 1 */
//! static function pointer for GPIO Interrupt
static void (*funcPtr0)() = NULL;
static void (*funcPtr1)() = NULL;
static void (*funcPtr2)() = NULL;
static void (*funcPtr3)() = NULL;
static void (*funcPtr4)() = NULL;
static void (*funcPtr5)() = NULL;
static void (*funcPtr6)() = NULL;
static void (*funcPtr7)() = NULL;
static void (*funcPtr8)() = NULL;
static void (*funcPtr9)() = NULL;
static void (*funcPtr10)() = NULL;
static void (*funcPtr11)() = NULL;
static void (*funcPtr12)() = NULL;
static void (*funcPtr13)() = NULL;
static void (*funcPtr14)() = NULL;
static void (*funcPtr15)() = NULL;

static GPIO_PIN_DEF_t getGPIOPinDef(GPIO_PORT_NAME_t GPIO_PortName);
static void GPIOIRQEnable(GPIO_PORT_NAME_t GPIO_PortName);
static void GPIOIRQDisable(GPIO_PORT_NAME_t GPIO_PortName);

/* USER CODE END 1 */

/** Configure pins as 
        * Analog 
        * Input 
        * Output
        * EVENT_OUT
        * EXTI
        * Free pins are configured automatically as Analog (this feature is enabled through 
        * the Code Generation settings)
     PC3   ------> I2S2_SD
     PA4   ------> I2S3_WS
     PA5   ------> SPI1_SCK
     PA6   ------> SPI1_MISO
     PA7   ------> SPI1_MOSI
     PB10   ------> I2S2_CK
     PC7   ------> I2S3_MCK
     PA9   ------> USB_OTG_FS_VBUS
     PA10   ------> USB_OTG_FS_ID
     PA11   ------> USB_OTG_FS_DM
     PA12   ------> USB_OTG_FS_DP
     PC10   ------> I2S3_CK
     PC12   ------> I2S3_SD
     PB6   ------> I2C1_SCL
     PB9   ------> I2C1_SDA
*/
void MX_GPIO_Init(void)
{

  GPIO_InitTypeDef GPIO_InitStruct;

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOE_CLK_ENABLE();
  __HAL_RCC_GPIOC_CLK_ENABLE();
  __HAL_RCC_GPIOH_CLK_ENABLE();
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();
  __HAL_RCC_GPIOD_CLK_ENABLE();

  /*Configure GPIO pins : PE2 PE4 PE5 PE6 
                           PE7 PE8 PE9 PE10 
                           PE11 PE12 PE13 PE14 
                           PE15 PE0 */
  GPIO_InitStruct.Pin = GPIO_PIN_2|GPIO_PIN_4|GPIO_PIN_5|GPIO_PIN_6 
                          |GPIO_PIN_7|GPIO_PIN_8|GPIO_PIN_9|GPIO_PIN_10 
                          |GPIO_PIN_11|GPIO_PIN_12|GPIO_PIN_13|GPIO_PIN_14 
                          |GPIO_PIN_15|GPIO_PIN_0;
  GPIO_InitStruct.Mode = GPIO_MODE_ANALOG;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(GPIOE, &GPIO_InitStruct);

  /*Configure GPIO pin : PtPin */
  GPIO_InitStruct.Pin = CS_I2C_SPI_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(CS_I2C_SPI_GPIO_Port, &GPIO_InitStruct);

  /*Configure GPIO pins : PC13 PC1 PC2 PC4 
                           PC5 PC6 PC8 PC9 
                           PC11 */
  GPIO_InitStruct.Pin = GPIO_PIN_13|GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_4 
                          |GPIO_PIN_5|GPIO_PIN_6|GPIO_PIN_8|GPIO_PIN_9 
                          |GPIO_PIN_11;
  GPIO_InitStruct.Mode = GPIO_MODE_ANALOG;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);

  /*Configure GPIO pin : PtPin */
  GPIO_InitStruct.Pin = OTG_FS_PowerSwitchOn_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(OTG_FS_PowerSwitchOn_GPIO_Port, &GPIO_InitStruct);

  /*Configure GPIO pin : PtPin */
  GPIO_InitStruct.Pin = PDM_OUT_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  GPIO_InitStruct.Alternate = GPIO_AF5_SPI2;
  HAL_GPIO_Init(PDM_OUT_GPIO_Port, &GPIO_InitStruct);

  /*Configure GPIO pin : PtPin */
  GPIO_InitStruct.Pin = B1_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_IT_RISING;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(B1_GPIO_Port, &GPIO_InitStruct);

  /*Configure GPIO pins : PA1 PA2 PA3 PA8 
                           PA15 */
  GPIO_InitStruct.Pin = GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_3|GPIO_PIN_8 
                          |GPIO_PIN_15;
  GPIO_InitStruct.Mode = GPIO_MODE_ANALOG;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /*Configure GPIO pin : PA4 */
  GPIO_InitStruct.Pin = GPIO_PIN_4;
  GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  GPIO_InitStruct.Alternate = GPIO_AF6_SPI3;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /*Configure GPIO pins : PA5 PA6 PA7 */
  GPIO_InitStruct.Pin = GPIO_PIN_5|GPIO_PIN_6|GPIO_PIN_7;
  GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  GPIO_InitStruct.Alternate = GPIO_AF5_SPI1;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /*Configure GPIO pins : PB0 PB1 PB11 PB12 
                           PB13 PB14 PB15 PB4 
                           PB5 PB7 PB8 */
  GPIO_InitStruct.Pin = GPIO_PIN_0|GPIO_PIN_1|GPIO_PIN_11|GPIO_PIN_12 
                          |GPIO_PIN_13|GPIO_PIN_14|GPIO_PIN_15|GPIO_PIN_4 
                          |GPIO_PIN_5|GPIO_PIN_7|GPIO_PIN_8;
  GPIO_InitStruct.Mode = GPIO_MODE_ANALOG;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

  /*Configure GPIO pin : PtPin */
  GPIO_InitStruct.Pin = BOOT1_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(BOOT1_GPIO_Port, &GPIO_InitStruct);

  /*Configure GPIO pin : PtPin */
  GPIO_InitStruct.Pin = CLK_IN_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  GPIO_InitStruct.Alternate = GPIO_AF5_SPI2;
  HAL_GPIO_Init(CLK_IN_GPIO_Port, &GPIO_InitStruct);

  /*Configure GPIO pins : PD8 PD9 PD10 PD11 
                           PD0 PD1 PD2 PD3 
                           PD6 PD7 */
  GPIO_InitStruct.Pin = GPIO_PIN_8|GPIO_PIN_9|GPIO_PIN_10|GPIO_PIN_11 
                          |GPIO_PIN_0|GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_3 
                          |GPIO_PIN_6|GPIO_PIN_7;
  GPIO_InitStruct.Mode = GPIO_MODE_ANALOG;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(GPIOD, &GPIO_InitStruct);

  /*Configure GPIO pins : PDPin PDPin PDPin PDPin 
                           PDPin */
  GPIO_InitStruct.Pin = LD4_Pin|LD3_Pin|LD5_Pin|LD6_Pin 
                          |Audio_RST_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOD, &GPIO_InitStruct);

  /*Configure GPIO pins : PC7 PCPin PC12 */
  GPIO_InitStruct.Pin = GPIO_PIN_7|I2S3_SCK_Pin|GPIO_PIN_12;
  GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  GPIO_InitStruct.Alternate = GPIO_AF6_SPI3;
  HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);

  /*Configure GPIO pin : PtPin */
  GPIO_InitStruct.Pin = VBUS_FS_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(VBUS_FS_GPIO_Port, &GPIO_InitStruct);

  /*Configure GPIO pins : PAPin PAPin PAPin */
  GPIO_InitStruct.Pin = OTG_FS_ID_Pin|OTG_FS_DM_Pin|OTG_FS_DP_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  GPIO_InitStruct.Alternate = GPIO_AF10_OTG_FS;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /*Configure GPIO pin : PtPin */
  GPIO_InitStruct.Pin = OTG_FS_OverCurrent_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(OTG_FS_OverCurrent_GPIO_Port, &GPIO_InitStruct);

  /*Configure GPIO pins : PBPin PBPin */
  GPIO_InitStruct.Pin = Audio_SCL_Pin|Audio_SDA_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_AF_OD;
  GPIO_InitStruct.Pull = GPIO_PULLUP;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  GPIO_InitStruct.Alternate = GPIO_AF4_I2C1;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

  /*Configure GPIO pin : PtPin */
  GPIO_InitStruct.Pin = MEMS_INT2_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_EVT_RISING;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(MEMS_INT2_GPIO_Port, &GPIO_InitStruct);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(CS_I2C_SPI_GPIO_Port, CS_I2C_SPI_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(OTG_FS_PowerSwitchOn_GPIO_Port, OTG_FS_PowerSwitchOn_Pin, GPIO_PIN_SET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOD, LD4_Pin|LD3_Pin|LD5_Pin|LD6_Pin 
                          |Audio_RST_Pin, GPIO_PIN_RESET);

  /* EXTI interrupt init*/
  HAL_NVIC_SetPriority(EXTI0_IRQn, 0, 0);
  HAL_NVIC_EnableIRQ(EXTI0_IRQn);

}

/* USER CODE BEGIN 2 */
void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)
{
	switch (GPIO_Pin) {
		case GPIO_PIN_0:
			if(funcPtr0 != NULL){
				funcPtr0();
			}
			break;
		case GPIO_PIN_1:
			if(funcPtr1 != NULL){
				funcPtr1();
			}
			break;
		case GPIO_PIN_2:
			if(funcPtr2 != NULL){
				funcPtr2();
			}
			break;
		case GPIO_PIN_3:
			if(funcPtr3 != NULL){
				funcPtr3();
			}
			break;
		case GPIO_PIN_4:
			if(funcPtr4 != NULL){
				funcPtr4();
			}
			break;
		case GPIO_PIN_5:
			if(funcPtr5 != NULL){
				funcPtr5();
			}
			break;
		case GPIO_PIN_6:
			if(funcPtr6 != NULL){
				funcPtr6();
			}
			break;
		case GPIO_PIN_7:
			if(funcPtr7 != NULL){
				funcPtr7();
			}
			break;
		case GPIO_PIN_8:
			if(funcPtr8 != NULL){
				funcPtr8();
			}
			break;
		case GPIO_PIN_9:
			if(funcPtr9 != NULL){
				funcPtr9();
			}
			break;
		case GPIO_PIN_10:
			if(funcPtr10 != NULL){
				funcPtr10();
			}
			break;
		case GPIO_PIN_11:
			if(funcPtr11 != NULL){
				funcPtr11();
			}
			break;
		case GPIO_PIN_12:
			if(funcPtr12 != NULL){
				funcPtr12();
			}
			break;
		case GPIO_PIN_13:
			if(funcPtr13 != NULL){
				funcPtr13();
			}
			break;
		case GPIO_PIN_14:
			if(funcPtr14 != NULL){
				funcPtr14();
			}
			break;
		case GPIO_PIN_15:
			if(funcPtr15 != NULL){
				funcPtr15();
			}
			break;

		default:
			break;
	}
}
void GPIOInitialize()
{
	MX_GPIO_Init();
}
void GPIOIRQAttach(void* funcPtr,GPIO_PORT_NAME_t GPIO_PortName)
{
	GPIOIRQEnable(GPIO_PortName);

	GPIO_PIN_DEF_t GPIO_PinStruct;
	GPIO_PinStruct = getGPIOPinDef(GPIO_PortName);

	switch (GPIO_PinStruct.pinNumber) {
		case GPIO_PIN_0:
			funcPtr0 = funcPtr;
			break;
		case GPIO_PIN_1:
			funcPtr1 = funcPtr;
			break;
		case GPIO_PIN_2:
			funcPtr2 = funcPtr;
			break;
		case GPIO_PIN_3:
			funcPtr3 = funcPtr;
			break;
		case GPIO_PIN_4:
			funcPtr4 = funcPtr;
			break;
		case GPIO_PIN_5:
			funcPtr5 = funcPtr;
			break;
		case GPIO_PIN_6:
			funcPtr6 = funcPtr;
			break;
		case GPIO_PIN_7:
			funcPtr7 = funcPtr;
			break;
		case GPIO_PIN_8:
			funcPtr8 = funcPtr;
			break;
		case GPIO_PIN_9:
			funcPtr9 = funcPtr;
			break;
		case GPIO_PIN_10:
			funcPtr10 = funcPtr;
			break;
		case GPIO_PIN_11:
			funcPtr11 = funcPtr;
			break;
		case GPIO_PIN_12:
			funcPtr12 = funcPtr;
			break;
		case GPIO_PIN_13:
			funcPtr13 = funcPtr;
			break;
		case GPIO_PIN_14:
			funcPtr14 = funcPtr;
			break;
		case GPIO_PIN_15:
			funcPtr15 = funcPtr;
			break;
		default:
			break;
	}
}
void GPIOIRQDetach(GPIO_PORT_NAME_t GPIO_PortName)
{
	GPIOIRQDisable(GPIO_PortName);

	GPIO_PIN_DEF_t GPIO_PinStruct;
	GPIO_PinStruct = getGPIOPinDef(GPIO_PortName);

	switch (GPIO_PinStruct.pinNumber) {
		case GPIO_PIN_0:
			funcPtr0 = NULL;
			break;
		case GPIO_PIN_1:
			funcPtr1 = NULL;
			break;
		case GPIO_PIN_2:
			funcPtr2 = NULL;
			break;
		case GPIO_PIN_3:
			funcPtr3 = NULL;
			break;
		case GPIO_PIN_4:
			funcPtr4 = NULL;
			break;
		case GPIO_PIN_5:
			funcPtr5 = NULL;
			break;
		case GPIO_PIN_6:
			funcPtr6 = NULL;
			break;
		case GPIO_PIN_7:
			funcPtr7 = NULL;
			break;
		case GPIO_PIN_8:
			funcPtr8 = NULL;
			break;
		case GPIO_PIN_9:
			funcPtr9 = NULL;
			break;
		case GPIO_PIN_10:
			funcPtr10 = NULL;
			break;
		case GPIO_PIN_11:
			funcPtr11 = NULL;
			break;
		case GPIO_PIN_12:
			funcPtr12 = NULL;
			break;
		case GPIO_PIN_13:
			funcPtr13 = NULL;
			break;
		case GPIO_PIN_14:
			funcPtr14 = NULL;
			break;
		case GPIO_PIN_15:
			funcPtr15 = NULL;
			break;
		default:
			break;
	}
}
void GPIOWrite(GPIO_PORT_NAME_t GPIO_PortName,GPIO_PinState state)
{
	GPIO_PIN_DEF_t GPIO_PinStruct;
	GPIO_PinStruct = getGPIOPinDef(GPIO_PortName);

	HAL_GPIO_WritePin(GPIO_PinStruct.group,GPIO_PinStruct.pinNumber,state);
}
GPIO_PinState GPIORead(GPIO_PORT_NAME_t GPIO_PortName)
{
	GPIO_PIN_DEF_t GPIO_PinStruct;

	GPIO_PinStruct = getGPIOPinDef(GPIO_PortName);

	GPIO_PinState result;

	result = HAL_GPIO_ReadPin(GPIO_PinStruct.group,GPIO_PinStruct.pinNumber);

	return result;

}
GPIO_PIN_DEF_t getGPIOPinDef(GPIO_PORT_NAME_t GPIO_PortName)
{
	GPIO_PIN_DEF_t result;

	uint16_t groupNum;
	uint16_t pinNum;

	//! Quotient of GPIO_PortName/16 is GPIO_TypeDef
	groupNum = GPIO_PortName/16;

	//! Remainder of GPIO_PortName/16 is GPIO_Pin_number
	pinNum = GPIO_PortName%16;

	switch (groupNum) {
		case 0:
			result.group = GPIOA;
			break;
		case 1:
			result.group = GPIOB;
			break;
		case 2:
			result.group = GPIOC;
			break;
		case 3:
			result.group = GPIOD;
			break;
		case 4:
			result.group = GPIOE;
			break;
		default:
			break;
	}
	switch (pinNum) {
		case 0:
			result.pinNumber = GPIO_PIN_0;
			break;
		case 1:
			result.pinNumber = GPIO_PIN_1;
			break;
		case 2:
			result.pinNumber = GPIO_PIN_2;
			break;
		case 3:
			result.pinNumber = GPIO_PIN_3;
			break;
		case 4:
			result.pinNumber = GPIO_PIN_4;
			break;
		case 5:
			result.pinNumber = GPIO_PIN_5;
			break;
		case 6:
			result.pinNumber = GPIO_PIN_6;
			break;
		case 7:
			result.pinNumber = GPIO_PIN_7;
			break;
		case 8:
			result.pinNumber = GPIO_PIN_8;
			break;
		case 9:
			result.pinNumber = GPIO_PIN_9;
			break;
		case 10:
			result.pinNumber = GPIO_PIN_10;
			break;
		case 11:
			result.pinNumber = GPIO_PIN_11;
			break;
		case 12:
			result.pinNumber = GPIO_PIN_12;
			break;
		case 13:
			result.pinNumber = GPIO_PIN_13;
			break;
		case 14:
			result.pinNumber = GPIO_PIN_14;
			break;
		case 15:
			result.pinNumber = GPIO_PIN_15;
			break;
		default:
			break;
	}

	return result;
}
void GPIOIRQEnable(GPIO_PORT_NAME_t GPIO_PortName)
{
	GPIO_PIN_DEF_t GPIO_PinStruct;
	GPIO_PinStruct = getGPIOPinDef(GPIO_PortName);


	GPIO_InitTypeDef GPIO_InitStruct;

	GPIO_InitStruct.Pin = GPIO_PinStruct.pinNumber;
    GPIO_InitStruct.Mode = GPIO_MODE_IT_RISING;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    HAL_GPIO_Init(GPIO_PinStruct.group, &GPIO_InitStruct);


    switch (GPIO_PinStruct.pinNumber) {
		case GPIO_PIN_0:
			HAL_NVIC_SetPriority(EXTI0_IRQn, 0, 0);
			HAL_NVIC_EnableIRQ(EXTI0_IRQn);
			break;
		case GPIO_PIN_1:
			HAL_NVIC_SetPriority(EXTI1_IRQn, 0, 0);
			HAL_NVIC_EnableIRQ(EXTI1_IRQn);
			break;
		case GPIO_PIN_2:
			HAL_NVIC_SetPriority(EXTI2_IRQn, 0, 0);
			HAL_NVIC_EnableIRQ(EXTI2_IRQn);
			break;
		case GPIO_PIN_3:
			HAL_NVIC_SetPriority(EXTI3_IRQn, 0, 0);
			HAL_NVIC_EnableIRQ(EXTI3_IRQn);
			break;
		case GPIO_PIN_4:
			HAL_NVIC_SetPriority(EXTI4_IRQn, 0, 0);
			HAL_NVIC_EnableIRQ(EXTI4_IRQn);
			break;
		case GPIO_PIN_5:
		case GPIO_PIN_6:
		case GPIO_PIN_7:
		case GPIO_PIN_8:
		case GPIO_PIN_9:
			HAL_NVIC_SetPriority(EXTI9_5_IRQn, 0, 0);
			HAL_NVIC_EnableIRQ(EXTI9_5_IRQn);
			break;
		case GPIO_PIN_10:
		case GPIO_PIN_11:
		case GPIO_PIN_12:
		case GPIO_PIN_13:
		case GPIO_PIN_14:
		case GPIO_PIN_15:
			HAL_NVIC_SetPriority(EXTI15_10_IRQn, 0, 0);
			HAL_NVIC_EnableIRQ(EXTI15_10_IRQn);
			break;
		default:
			break;
	}

}
void GPIOIRQDisable(GPIO_PORT_NAME_t GPIO_PortName)
{
	GPIO_PIN_DEF_t GPIO_PinStruct;
	GPIO_PinStruct = getGPIOPinDef(GPIO_PortName);


	GPIO_InitTypeDef GPIO_InitStruct;

	GPIO_InitStruct.Pin = GPIO_PinStruct.pinNumber;
	GPIO_InitStruct.Mode = GPIO_MODE_ANALOG;
	GPIO_InitStruct.Pull = GPIO_NOPULL;
	HAL_GPIO_Init(GPIO_PinStruct.group, &GPIO_InitStruct);


	switch (GPIO_PinStruct.pinNumber) {
		case GPIO_PIN_0:
			HAL_NVIC_DisableIRQ(EXTI0_IRQn);
			break;
		case GPIO_PIN_1:
			HAL_NVIC_DisableIRQ(EXTI1_IRQn);
			break;
		case GPIO_PIN_2:
			HAL_NVIC_DisableIRQ(EXTI2_IRQn);
			break;
		case GPIO_PIN_3:
			HAL_NVIC_DisableIRQ(EXTI3_IRQn);
			break;
		case GPIO_PIN_4:
			HAL_NVIC_DisableIRQ(EXTI4_IRQn);
			break;
		case GPIO_PIN_5:
		case GPIO_PIN_6:
		case GPIO_PIN_7:
		case GPIO_PIN_8:
		case GPIO_PIN_9:
			HAL_NVIC_DisableIRQ(EXTI9_5_IRQn);
			break;
		case GPIO_PIN_10:
		case GPIO_PIN_11:
		case GPIO_PIN_12:
		case GPIO_PIN_13:
		case GPIO_PIN_14:
		case GPIO_PIN_15:
			HAL_NVIC_DisableIRQ(EXTI15_10_IRQn);
			break;
		default:
			break;
	}
}
/* USER CODE END 2 */

/**
  * @}
  */

/**
  * @}
  */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
