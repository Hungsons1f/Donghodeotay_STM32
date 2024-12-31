/**
  ******************************************************************************
  * @file    FlashView.h
  * @author  Nguyen Hung Son
  * @version V1.0
  * @date    29/12/2024
  * @brief   Flash View function
   ******************************************************************************
  */


/* Includes ------------------------------------------------------------------*/
#include "TypeStruct.h"
#include "ScreenUtilites.h"
#include "FirmwareInclude.h"

/* Private defines -----------------------------------------------------------*/
/* Flash Lines---------------*/
#ifndef FLASHFUNC_H_
#define FLASHFUNC_H_

#define FlashLine1						1
#define FlashLine2						2
#define FlashLine3						3
#define FlashBack						4

#endif

/* Flash Blink state---------------*/
#define BlinkStateOff					0
#define BlinkStateOn					1
#define BlinkStateShortOn				2
#define BlinkStateShortOff				3

/* Private Function Prototypes -----------------------------------------------*/
void DispFlashLine(uint8_t *FlashLine);
void FlashModeLight();
void FlashModeBlink();
void FlashModeSOS();
void FlashReset();
