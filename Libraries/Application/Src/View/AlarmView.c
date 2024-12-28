/**
  ******************************************************************************
  * @file    AlarmView.h
  * @author  Nguyen Hung Son
  * @version V1.0
  * @date    25/12/2024
  * @brief   Alarm screen function
   ******************************************************************************
  */


/* Includes ------------------------------------------------------------------*/
#include "TypeStruct.h"
#include "AlarmView.h"

/* Global Variables -----------------------------------------------------------*/


/* Private functions ------------------------------------------------*/
void DispAlarmLine(volatile stAlarm *AlarmData, uint8_t *AlarmLine, uint8_t *AlarmPos)
{
	GotoXP(0,0);
	WriteString("<ALARMS>");

	uint8_t i;
	for (i = 2; i<= 6; i++)
	{
		GotoXP(0,i);
		if (*AlarmLine == (i-1))
		{
			WriteChar(92+32);
			WriteChar(' ');
		}
		else
		{
			WriteString("  ");
		}

		if (((AlarmData+i-2)->enable) )
		{
			WriteChar(93+32);
			WriteChar(' ');
		}
		else
		{
			WriteString("  ");
		}

		WriteChar(((AlarmData+i-2)->hour10)+48);
		WriteChar(((AlarmData+i-2)->hour)+48);
		WriteChar(':');
		WriteChar(((AlarmData+i-2)->min10)+48);
		WriteChar(((AlarmData+i-2)->min)+48);
		WriteChar(' ');

		if (((AlarmData+i-2)->date) & Monday)
		{
			WriteChar('M');
		}
		else
		{
			WriteChar('-');
		}
		if (((AlarmData+i-2)->date) & Tuesday)
		{
			WriteChar('T');
		}
		else
		{
			WriteChar('-');
		}
		if (((AlarmData+i-2)->date) & Wednesday)
		{
			WriteChar('W');
		}
		else
		{
			WriteChar('-');
		}
		if (((AlarmData+i-2)->date) & Thursday)
		{
			WriteChar('T');
		}
		else
		{
			WriteChar('-');
		}
		if (((AlarmData+i-2)->date) & Friday)
		{
			WriteChar('F');
		}
		else
		{
			WriteChar('-');
		}
		if (((AlarmData+i-2)->date) & Saturday)
		{
			WriteChar('S');
		}
		else
		{
			WriteChar('-');
		}
		if (((AlarmData+i-2)->date) & Sunday)
		{
			WriteChar('S');
		}
		else
		{
			WriteChar('-');
		}

		if (*AlarmLine == (i-1))
		{
			switch (*AlarmPos)
			{
			case APEnable:
				InverseImage(12,17,i,i);
				break;
			case APHour:
				InverseImage(24,35,i,i);
				break;
			case APMin10:
				InverseImage(42,47,i,i);
				break;
			case APMin:
				InverseImage(48,53,i,i);
				break;
			case APMon:
				InverseImage(60,65,i,i);
				break;
			case APTue:
				InverseImage(66,71,i,i);
				break;
			case APWed:
				InverseImage(72,77,i,i);
				break;
			case APThu:
				InverseImage(78,83,i,i);
				break;
			case APFri:
				InverseImage(84,89,i,i);
				break;
			case APSat:
				InverseImage(90,95,i,i);
				break;
			case APSun:
				InverseImage(96,101,i,i);
				break;
			}
		}
	}

	GotoXP(0,7);
	if (*AlarmLine == 6)
	{
		WriteChar(92+32);
		WriteChar(' ');
	}
	else
	{
		WriteString("  ");
	}
	WriteString("Back");
}
