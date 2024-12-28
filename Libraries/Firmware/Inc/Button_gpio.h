/**
  ******************************************************************************
  * @file    Button_gpio.h
  * @author  Nguyen Hung Son
  * @version V1.0
  * @date    23/12/2024
  * @brief   Control Button status
   ******************************************************************************
  */


/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "TypeStruct.h"

/* Private defines -----------------------------------------------------------*/
/* Firmware defines -----------*/


/* Private function prototypes -----------------------------------------------*/
void Button_Init (GPIO_TypeDef *pGpioUp, uint16_t uPinUp, GPIO_TypeDef *pGpioDown, uint16_t uPinDown, GPIO_TypeDef *pGpioPush, uint16_t uPinPush);
void Button_ExePush (stButton *pstBtn);
void Button_ExeUp (stButton *pstBtn);
void Button_ExeDown (stButton *pstBtn);
