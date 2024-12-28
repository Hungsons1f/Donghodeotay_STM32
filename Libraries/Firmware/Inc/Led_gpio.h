/**
  ******************************************************************************
  * @file    Led_gpio.h
  * @author  Nguyen Hung Son
  * @version V1.0
  * @date    07/12/2024
  * @brief   Control Led status
   ******************************************************************************
  */


/* Includes ------------------------------------------------------------------*/
#include "main.h"

/* Private defines -----------------------------------------------------------*/
/* Firmware defines -----------*/


/* Private function prototypes -----------------------------------------------*/
void Led_Bright1 (uint8_t on);
void Led_Bright2 (uint8_t on);
void Led_Init (GPIO_TypeDef *pGpio1, uint16_t uPin1, GPIO_TypeDef *pGpio2, uint16_t uPin2);
