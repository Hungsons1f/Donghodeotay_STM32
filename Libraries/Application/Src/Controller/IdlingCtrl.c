/**
  ******************************************************************************
  * @file    IdlingCtrl.h
  * @author  Nguyen Hung Son
  * @version V1.0
  * @date    21/12/2024
  * @brief   Idling controller function
   ******************************************************************************
  */


/* Includes ------------------------------------------------------------------*/
#include "IdlingCtrl.h"

/* Global Variables ----------------------------------------------------------*/


/* Private functions ---------------------------------------------------------*/
void IdlingStateAction (uint8_t *NumberOfIcon, volatile stDispTime *Realtime )
{
	DispTopRightIcon(NumberOfIcon);
    DispBotTime(Realtime, YES);
    DispMainTime(Realtime);
}
