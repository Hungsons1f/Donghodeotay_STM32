/**
  ******************************************************************************
  * @file    Led_gpio.c
  * @author  Nguyen Hung Son
  * @version V1.0
  * @date    07/12/2024
  * @brief   Control Led status
   ******************************************************************************
  */


/* Includes ------------------------------------------------------------------*/
#include "Led_gpio.h"
#include "TypeStruct.h"

/* Global variables ----------------------------------------------------------*/
GPIO_TypeDef *pGpioCtrlLed1, *pGpioCtrlLed2;
uint16_t uGpioPin1, uGpioPin2;

/* Private functions ---------------------------------------------------------*/
void Led_Bright1 (uint8_t on) {
	HAL_GPIO_WritePin(pGpioCtrlLed1, uGpioPin1, (GPIO_PinState)on);
}

void Led_Bright2 (uint8_t on) {
	HAL_GPIO_WritePin(pGpioCtrlLed2, uGpioPin2, (GPIO_PinState)on);
}

void Led_Init (GPIO_TypeDef *pGpio1, uint16_t uPin1, GPIO_TypeDef *pGpio2, uint16_t uPin2) {
	pGpioCtrlLed1 = pGpio1;
	pGpioCtrlLed2 = pGpio2;
	uGpioPin1 = uPin1;
	uGpioPin2 = uPin2;
}
