/**
  ******************************************************************************
  * @file    Global.c
  * @author  Nguyen Hung Son
  * @version V1.0
  * @date    14/09/2019
  * @brief   General display function
   ******************************************************************************
  */


/* Includes ------------------------------------------------------------------*/
#include "GeneralDisplay.h"

/* Global Variables ----------------------------------------------------------*/

/* Global Structs ------------------------------------------------------------*/


/* Private functions ---------------------------------------------------------*/
void DispTopRightIcon(uint8_t* Gicon)
{
	uint8_t icon = *Gicon;
	uint8_t space = 0;

	if (icon & IBattery)
	{
		space += (lena(IconBattery) + Spacer);
		GotoXP(128-space,0);
		DrawIcon(IconBattery,lena(IconBattery));
	}
	if (icon & ICharge)
	{
		space += (lena(IconCharge) + Spacer);
		GotoXP(128-space,0);
		DrawIcon(IconCharge,lena(IconCharge));
	}
	if (icon & IAlarm)
	{
		space += (lena(IconAlarm) + Spacer);
		GotoXP(128-space,0);
		DrawIcon(IconAlarm,lena(IconAlarm));
	}
	if (icon & ISound)
	{
		space += (lena(IconSound) + Spacer);
		GotoXP(128-space,0);
		DrawIcon(IconSound,lena(IconSound));
	}
	if (icon & ICount)
	{
		space += (lena(IconCount) + Spacer);
		GotoXP(128-space,0);
		DrawIcon(IconCount,lena(IconCount));
	}
}

void DispBotTime(volatile stDispTime *time, uint8_t isIdleState)
{
	GotoXP(0,7);
	switch (isIdleState)
	{
	case ENABLE:
		WriteChar(time->hour10 + 48);
		WriteChar(time->hour + 48);
		WriteChar(':');
		WriteChar(time->min10 + 48);
		WriteChar(time->min + 48);
		break;
	default:
		GotoXP(30,7);
		break;
	}

	WriteString("   ");
    uint8_t i = time->date;
	WriteString((uint8_t*)(Datetype+i-1));
	WriteChar(time->day10 + 48);
	WriteChar(time->day + 48);
	WriteChar('/');
	WriteChar(time->mon10 + 48);
	WriteChar(time->mon + 48);
	WriteChar('/');
	WriteChar(time->year10 + 48);
	WriteChar(time->year + 48);
}

