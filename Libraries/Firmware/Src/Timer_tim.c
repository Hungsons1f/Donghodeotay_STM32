/**
  ******************************************************************************
  * @file    Timer_tim.c
  * @author  Nguyen Hung Son
  * @version V1.0
  * @date    30/12/2024
  * @brief   Control Timers
  ******************************************************************************
  */


/* Includes ------------------------------------------------------------------*/
#include "Timer_tim.h"

/* Global variables ----------------------------------------------------------*/
uint8_t uSize;
stTimer *astTimer[100];

/* Private functions ---------------------------------------------------------*/
void Timer_Append (stTimer *timer) {
	astTimer[uSize] = timer;
	astTimer[uSize]->pointer = (uint32_t)timer;
	uSize++;
}

void Timer_Exe (uint8_t *tick)
{
	uint8_t _tick = *tick;

	for (uint8_t i = 0; i < uSize; i++) {
		if (astTimer[i]->enable == ENABLE) {
			astTimer[i]->value += tick;

			if (astTimer[i]->value >= astTimer[i]->preset) {
				astTimer[i]->value = 0;
				astTimer[i]->tick = YES;
			}
			else astTimer[i]->tick = NO;
		}
		else {
			astTimer[i]->value = 0;
			astTimer[i]->tick = NO;
		}
	}
	*tick -= _tick;
}
