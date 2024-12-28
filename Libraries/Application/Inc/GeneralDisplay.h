/**
  ******************************************************************************
  * @file    Global.h
  * @author  Nguyen Hung Son
  * @version V1.0
  * @date    14/09/2019
  * @brief   Idling screen function
  ******************************************************************************
  */


/* Includes ------------------------------------------------------------------*/
//#include "stm8s.h"
#include "GeneralDisplayIcon.h"
#include "ScreenUtilites.h"
#include "GeneralUtilities.h"
#include "TypeStruct.h"

/* Private defines -----------------------------------------------------------*/
#define IBattery				0x01
#define ICharge					0x02
#define IAlarm					0x04
#define ISound					0x08
#define ICount					0x10

#define Spacer					2

#ifndef DATECHAR_H_
#define DATECHAR_H_
static const uint8_t Datetype[][6] = {"Sun, ","Mon, ", "Tue, ", "Wed, ", "Thu, ", "Fri, ", "Sat, "};
#endif

/* Private function prototypes -----------------------------------------------*/
void DispTopRightIcon(uint8_t* Gicon);
void DispBotTime(volatile stDispTime *time, uint8_t State);
