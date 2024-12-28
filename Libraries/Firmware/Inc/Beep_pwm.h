/**
  ******************************************************************************
  * @file    Beep_pwm.h
  * @author  Nguyen Hung Son
  * @version V1.0
  * @date    12/12/2024
  * @brief   Beep function for buzzer
   ******************************************************************************
  */

/* Includes ------------------------------------------------------------------*/
#include "main.h"

/* Private defines -----------------------------------------------------------*/
#define Beep_BaseFreqMhz 1

/* Private defines -----------------------------------------------------------*/
void Beep_Init (TIM_HandleTypeDef *pTimer, uint32_t uTimChan);
uint8_t Beep_Run (uint8_t on, uint8_t uFreqkhz);
