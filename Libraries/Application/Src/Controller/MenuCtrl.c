/**
  ******************************************************************************
  * @file    MenuCtrl.h
  * @author  Nguyen Hung Son
  * @version V1.0
  * @date    21/12/2024
  * @brief   Menu controller function
   ******************************************************************************
  */


/* Includes ------------------------------------------------------------------*/
#include "MenuCtrl.h"

/* Global Variables ----------------------------------------------------------*/


/* Private functions ---------------------------------------------------------*/
void MenuStateAction (uint8_t *NumberOfIcon, uint8_t Function, volatile stDispTime *Realtime)
{
	DispTopRightIcon(NumberOfIcon);
	DispMenuName(Function);
	DispMenuIcon(Function);
	DispBotTime(Realtime, NO);
}
