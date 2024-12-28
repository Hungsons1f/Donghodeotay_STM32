/**
  ******************************************************************************
  * @file    StateCtrl.h
  * @author  Nguyen Hung Son
  * @version V1.0
  * @date    20/12/2024
  * @brief   Main state machine controller function
   ******************************************************************************
  */


/* Includes ------------------------------------------------------------------*/
#include "TypeStruct.h"
#include "ScreenUtilites.h"
#include "AlarmCtrl.h"
#include "IdlingCtrl.h"
#include "MenuCtrl.h"
#include "GeneralDisplay.h"

/* Private defines -----------------------------------------------------------*/
/* Level ---------*/
#define IdlingLevel 					0
#define MenuLevel						1
#define FunctionLevel					2
#define LowerLevel						3
#define OutStateAlarmLevel				4

/* Function ------*/
#define AlarmFunc						1
#define CounterFunc						2
#define FlashFunc						3
#define SettingFunc						4
#define CreditFunc 						5
#define BackFunc						6

/* Button Done?---*/
#define done							0
#define nyet							1

/* Flash Lines---------------*/
#define FlashLine1						1
#define FlashLine2						2
#define FlashLine3						3
#define FlashBack						4

/* Counter Lines---------------*/
#define CounterLine1					1
#define CounterLine2					2
#define CounterBack						3

/* Setting Lines-----*/
#define SetLine1						1
#define SetLine2						2
#define SetSave							3
#define SetBack							4

/* Setting Position Cursors----*/
#define SPNull							0
#define SPHour							1
#define SPMin10							2
#define SPMin							3
#define	SPDate							4
#define SPDay							8
#define SPMonth							7
#define SPYear10						5
#define SPYear							6

/* Credit Picture Number--------*/
#define CreditNull						4
#define Cydeus							1
#define LMCuong							2
#define Payitforward					3


/* Private Function Prototypes -----------------------------------------------*/
void MainStateMachine ();
void MainStateAction ();
