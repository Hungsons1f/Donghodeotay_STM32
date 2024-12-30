/**
  ******************************************************************************
  * @file    FlashCtrl.h
  * @author  Nguyen Hung Son
  * @version V1.0
  * @date    26/12/2024
  * @brief   Flash controller function
   ******************************************************************************
  */

/* Includes ------------------------------------------------------------------*/
#include "TypeStruct.h"
#include "GeneralDisplay.h"
#include "ScreenUtilites.h"
#include "FlashView.h"

/* Private Defines -----------------------------------------------------------*/
/* Flash Lines---------------*/
#ifndef FLASHFUNC_H_
#define FLASHFUNC_H_

#define FlashLine1						1
#define FlashLine2						2
#define FlashLine3						3
#define FlashBack						4

#endif

/* Private Function Prototypes -----------------------------------------------*/
uint8_t FlashState(stButton *btnPush, stButton *btnUp, stButton *btnDown);
void FlastStateAction (uint8_t *numOfIcon);
