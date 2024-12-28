/**
  ******************************************************************************
  * @file    Beep_pwm.c
  * @author  Nguyen Hung Son
  * @version V1.0
  * @date    12/12/2024
  * @brief   Beep function for buzzer
   ******************************************************************************
  */


/* Includes ------------------------------------------------------------------*/
#include "Beep_pwm.h"

/* Global Variables ----------------------------------------------------------*/
TIM_HandleTypeDef *pTimCtrlBeep;
uint32_t uTimChannel;
uint8_t uBeepOn = DISABLE;
uint32_t uPeriod, uDuty;


/* Private functions ---------------------------------------------------------*/
void Beep_Init (TIM_HandleTypeDef *pTimer, uint32_t uTimChan) {
	pTimCtrlBeep = pTimer;
	uTimChannel = uTimChan;
}

//uint8_t Beep_OnDelay (uint16_t uDelayms, uint8_t uFreqkhz)
//{
//	uPeriod = (Beep_BaseFreqMhz*1000/uFreqkhz);
//	uDuty = uPeriod/2;
//
//	__HAL_TIM_SET_AUTORELOAD(pTimCtrlBeep, uPeriod - 1);
//	HAL_TIM_GenerateEvent(pTimCtrlBeep, TIM_EVENTSOURCE_UPDATE);
//
//	if (HAL_TIM_PWM_Start(pTimCtrlBeep, uTimChannel) != SUCCESS) {
//		return ERROR;
//	}
//	return SUCCESS;
//}

uint8_t Beep_Run (uint8_t on, uint8_t uFreqkhz) {
	switch (on) {
		case ENABLE:
			if (uBeepOn == DISABLE) {
				uPeriod = (Beep_BaseFreqMhz*1000/uFreqkhz);
				uDuty = uPeriod/2;

				__HAL_TIM_SET_AUTORELOAD(pTimCtrlBeep, uPeriod - 1);
				__HAL_TIM_SET_COMPARE(pTimCtrlBeep, uTimChannel, uDuty);
				HAL_TIM_GenerateEvent(pTimCtrlBeep, TIM_EVENTSOURCE_UPDATE);

				if (HAL_TIM_PWM_Start(pTimCtrlBeep, uTimChannel) != (HAL_StatusTypeDef)SUCCESS) {
					return ERROR;
				}
			}

			uBeepOn = ENABLE;
			return SUCCESS;
			break;
		case DISABLE:
			if (HAL_TIM_PWM_Stop(pTimCtrlBeep, uTimChannel) != (HAL_StatusTypeDef)SUCCESS) {
				return ERROR;
			}
			uBeepOn = DISABLE;
			return SUCCESS;
			break;
		default:
			return ERROR;
	}
}

