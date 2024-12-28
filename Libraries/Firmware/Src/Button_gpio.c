/**
  ******************************************************************************
  * @file    Button_gpio.c
  * @author  Nguyen Hung Son
  * @version V1.0
  * @date    23/12/2024
  * @brief   Control Button status
   ******************************************************************************
  */


/* Includes ------------------------------------------------------------------*/
#include "Button_gpio.h"

/* Global variables ----------------------------------------------------------*/
GPIO_TypeDef *pGpioCtrlBtnUp, *pGpioCtrlBtnDown, *pGpioCtrlBtnPush;
uint16_t uGpioPinUp, uGpioPinDown, uGpioPinPush;

/* Private functions ---------------------------------------------------------*/
void Button_Init (GPIO_TypeDef *pGpioUp, uint16_t uPinUp, GPIO_TypeDef *pGpioDown, uint16_t uPinDown, GPIO_TypeDef *pGpioPush, uint16_t uPinPush) {
	pGpioCtrlBtnUp = pGpioUp;
	pGpioCtrlBtnDown = pGpioDown;
	pGpioCtrlBtnPush = pGpioPush;
	uGpioPinUp = uPinUp;
	uGpioPinDown = uPinDown;
	uGpioPinPush = uPinPush;
}

void Button_ExePush (stButton *pstBtn) {
	pstBtn->value = HAL_GPIO_ReadPin(pGpioCtrlBtnPush, uGpioPinPush);
	if (pstBtn->value > pstBtn->lastvalue) {
		pstBtn->rising = 1;
	}
	else if (pstBtn->value < pstBtn->lastvalue) {
		pstBtn->falling = 1;
	}
	else if (pstBtn->value == pstBtn->lastvalue && (pstBtn->rising == 1 || pstBtn->falling == 1)) {
		pstBtn->rising = 0;
		pstBtn->falling = 0;
	}
	pstBtn->lastvalue = pstBtn->value;
}

void Button_ExeUp (stButton *pstBtn) {
	pstBtn->value = HAL_GPIO_ReadPin(pGpioCtrlBtnUp, uGpioPinUp);
	if (pstBtn->value > pstBtn->lastvalue) {
		pstBtn->rising = 1;
	}
	else if (pstBtn->value < pstBtn->lastvalue) {
		pstBtn->falling = 1;
	}
	else if (pstBtn->value == pstBtn->lastvalue && (pstBtn->rising == 1 || pstBtn->falling == 1)) {
		pstBtn->rising = 0;
		pstBtn->falling = 0;
	}
	pstBtn->lastvalue = pstBtn->value;
}

void Button_ExeDown (stButton *pstBtn) {
	pstBtn->value = HAL_GPIO_ReadPin(pGpioCtrlBtnDown, uGpioPinDown);
	if (pstBtn->value > pstBtn->lastvalue) {
		pstBtn->rising = 1;
	}
	else if (pstBtn->value < pstBtn->lastvalue) {
		pstBtn->falling = 1;
	}
	else if (pstBtn->value == pstBtn->lastvalue && (pstBtn->rising == 1 || pstBtn->falling == 1)) {
		pstBtn->rising = 0;
		pstBtn->falling = 0;
	}
	pstBtn->lastvalue = pstBtn->value;
}
