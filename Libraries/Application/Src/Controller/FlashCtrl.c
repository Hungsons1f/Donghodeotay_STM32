/**
  ******************************************************************************
  * @file    FlashCtrl.c
  * @author  Nguyen Hung Son
  * @version V1.0
  * @date    26/12/2024
  * @brief   Flash controller function
   ******************************************************************************
  */


/* Includes ------------------------------------------------------------------*/
#include "FlashCtrl.h"

/* Global Variables ----------------------------------------------------------*/

/* Private functions ---------------------------------------------------------*/
uint8_t FlashState() {
	static uint8_t Flashline = FlashLine1;
	FlashFuncState(&Flashline);
	if (Down)
	{
        Down = 0;
		  Flashline++;
		  if (Flashline > FlashBack)	Flashline = FlashLine1;
	}
	if (Up)
	{
		Up = 0;
        Flashline--;
		  if (Flashline < FlashLine1)	Flashline = FlashBack;
	}

	if (Push)
	{
		Push = 0;
		if (Flashline == FlashBack)
		{
			StateLevel = MenuLevel;
			Flashline = FlashLine1;
			SolidFill(0x00);
		}
	}
}
