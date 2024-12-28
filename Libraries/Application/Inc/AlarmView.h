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
#include "ScreenUtilites.h"

/* Private defines -----------------------------------------------------------*/
#ifndef ALARMFUNC_H_
#define ALARMFUNC_H_
/* Alarm Date-----*/
#define Monday							0x40
#define Tuesday							0x20
#define Wednesday						0x10
#define Thursday						0x08
#define Friday							0x04
#define Saturday						0x02
#define Sunday							0x01

/* Alarm Line-----*/
#define AlarmLine1						1
#define AlarmLine2						2
#define AlarmLine3						3
#define AlarmLine4						4
#define AlarmLine5						5
#define AlarmBack						6

/* Alarm Position Cursors----*/
#define APNull							0
#define APEnable						1
#define APHour							2
#define APMin10							3
#define APMin							4
#define APMon							5
#define APTue							6
#define APWed							7
#define APThu							8
#define APFri							9
#define APSat							10
#define APSun							11

#endif

/* Private function prototypes------------------------------------------------*/
void DispAlarmLine(volatile stAlarm *AlarmData, uint8_t *AlarmLine, uint8_t *AlarmPos);
