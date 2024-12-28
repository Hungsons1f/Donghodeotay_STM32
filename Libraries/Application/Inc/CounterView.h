/**
  ******************************************************************************
  * @file    CounterView.h
  * @author  Nguyen Hung Son
  * @version V1.0
  * @date    19/12/2024
  * @brief   Counter screen function
   ******************************************************************************
  */


/* Includes ------------------------------------------------------------------*/
#include "TypeStruct.h"
#include "Number.h"
#include "ScreenUtilites.h"

/* Private defines -----------------------------------------------------------*/
#ifndef COUNTER_H_
#define COUNTER_H_

#define h10os					6		//0
#define hos						26		//20
#define dos						47		//40
#define m10os					58		//48
#define mos						78		//68
#define s10os					102		//88
#define sos						113		//113

#endif

/* Private function prototypes------------------------------------------------*/
void DispCounter (volatile stCounter *count);
