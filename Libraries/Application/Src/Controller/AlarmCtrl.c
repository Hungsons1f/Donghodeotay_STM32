/**
  ******************************************************************************
  * @file    AlarmCtrl.c
  * @author  Nguyen Hung Son
  * @version V1.0
  * @date    19/12/2024
  * @brief   Alarm controller function
   ******************************************************************************
  */


/* Includes ------------------------------------------------------------------*/
#include "AlarmCtrl.h"

/* Global Variables ----------------------------------------------------------*/
uint8_t Alarmline = AlarmLine1;
uint8_t AlarmPos = APNull;

/* Private functions ---------------------------------------------------------*/
uint8_t CheckAlarm (volatile stAlarm *stSavedAlarm, volatile stDispTime *stCurrentTime )
{
	uint8_t alarmon = 0;

	uint8_t alarmtemp = 0;
	uint8_t timetemp = 0;

	uint8_t i = 0;
	uint8_t date = 0x80;
	for (i = 1; i<= 7; i++)
	{
		date >>= 1;
		alarmtemp = stSavedAlarm->date;
		timetemp = stCurrentTime->date;
		if ((alarmtemp&date) == (timetemp&date))
		{
			alarmtemp = stSavedAlarm->hour10 * 10 + stSavedAlarm->hour;
			timetemp = stCurrentTime->hour10 * 10 + stCurrentTime->hour;
			if (alarmtemp == timetemp)
			{
				alarmtemp = stSavedAlarm->min10 * 10 + stSavedAlarm->min;
				timetemp = stCurrentTime->min10 * 10 + stCurrentTime->min;
				if (alarmtemp == timetemp)
				{
					alarmon = 1;
				}
			}
		}
	}
	return alarmon;
}

void AlarmStateAction(volatile stAlarm *AlarmData, uint8_t *NumOfIcon) {
	DispAlarmLine(AlarmData, &Alarmline, &AlarmPos);

	uint8_t ii = 0, on = 0;
	for (ii = 0; ii< 4; ii++)
	{
	  if ((AlarmData+ii)->enable) on++;
	}
	if (on) *NumOfIcon |= IAlarm;
	else *NumOfIcon &=~ IAlarm;

	DispTopRightIcon(NumOfIcon);
}

uint8_t AlarmState(volatile stAlarm astAlarm[5], stButton *btnPush, stButton *btnUp, stButton *btnDown) {
	switch (AlarmPos) {
		case APNull:
			if (btnDown->rising) {
				Alarmline++;
				if (Alarmline > AlarmBack)	Alarmline = AlarmLine1;
			}
			if (btnUp->rising) {
		        Alarmline--;
				if (Alarmline < AlarmLine1)	Alarmline = AlarmBack;
			}
			if (btnPush->rising) {
				if (Alarmline == AlarmBack) {
					Alarmline = AlarmLine1;
					return BackToMenu;
				}
				else AlarmPos = APEnable;
			}
			break;

		case APEnable:
			if (btnUp->rising || btnDown->rising) astAlarm[Alarmline-1].enable ^= 0x01;
			if (btnPush->rising) AlarmPos = APHour;
		    break;

		case APHour:
			uint8_t AlarmHour = astAlarm[Alarmline-1].hour10 * 10 + astAlarm[Alarmline-1].hour;
			if (btnUp->rising) 		AlarmHour ++;
			if (btnDown->rising) 	AlarmHour --;
			if (AlarmHour > 23) 	AlarmHour = 0;
			if (AlarmHour == 0xFF) 	AlarmHour = 23;
			if (btnPush->rising) 	AlarmPos = APMin10;
			astAlarm[Alarmline-1].hour10 = AlarmHour/10;
			astAlarm[Alarmline-1].hour = AlarmHour - astAlarm[Alarmline-1].hour10*10;
			break;

		case APMin10:
			if (btnUp->rising) 					astAlarm[Alarmline-1].min10 ++;
			if (btnDown->rising)				astAlarm[Alarmline-1].min10 --;
			if (astAlarm[Alarmline-1].min10 > 5) astAlarm[Alarmline-1].min10 = 0;
			if (astAlarm[Alarmline-1].min10 == 0xFF) astAlarm[Alarmline-1].min10 = 5;
			if (btnPush->rising) AlarmPos = APMin;
			break;

		case APMin:
			if (btnUp->rising)					astAlarm[Alarmline-1].min ++;
			if (btnDown->rising)				astAlarm[Alarmline-1].min --;
			if (astAlarm[Alarmline-1].min > 9) 	astAlarm[Alarmline-1].min = 0;
			if (astAlarm[Alarmline-1].min == 0xFF) astAlarm[Alarmline-1].min = 9;
			if (btnPush->rising) AlarmPos = APMon;
			break;

		case APMon:
			if (btnUp->rising || btnDown->rising)	astAlarm[Alarmline-1].date ^= Monday;
			if (btnPush->rising) AlarmPos = APTue;
			break;

		case APTue:
			if (btnUp->rising || btnDown->rising)	astAlarm[Alarmline-1].date ^= Tuesday;
			if (btnPush->rising) AlarmPos = APWed;
			break;

		case APWed:
			if (btnUp->rising || btnDown->rising)	astAlarm[Alarmline-1].date ^= Wednesday;
			if (btnPush->rising) AlarmPos = APThu;
			break;

		case APThu:
			if (btnUp->rising || btnDown->rising)	astAlarm[Alarmline-1].date ^= Thursday;
			if (btnPush->rising) AlarmPos = APFri;
			break;

		case APFri:
			if (btnUp->rising || btnDown->rising)	astAlarm[Alarmline-1].date ^= Friday;
			if (btnPush->rising) AlarmPos = APSat;
			break;

		case APSat:
			if (btnUp->rising || btnDown->rising)	astAlarm[Alarmline-1].date ^= Saturday;
			if (btnPush->rising) AlarmPos = APSun;
			break;

		case APSun:
			if (btnUp->rising || btnDown->rising)	astAlarm[Alarmline-1].date ^= Sunday;
			if (btnPush->rising) AlarmPos = APNull;
			break;
	}
	return StayInFunc;
}
