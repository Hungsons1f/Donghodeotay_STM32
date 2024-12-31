/**
  ******************************************************************************
  * @file    FlashView.c
  * @author  Nguyen Hung Son
  * @version V1.0
  * @date    29/12/2024
  * @brief   Flash View function
   ******************************************************************************
  */


/* Includes ------------------------------------------------------------------*/
#include "FlashView.h"

/* Global Variables ----------------------------------------------------------*/
stTimer timBlinking500 = {DISABLE, 0, NO, 50, 0};
stTimer timBlinking200 = {DISABLE, 0, NO, 50, 0};
uint8_t uBlinkState = BlinkStateOn;
uint8_t uSosCount = 0;

/* Private functions ---------------------------------------------------------*/
void DispFlashLine(uint8_t *FlashLine) {
	GotoXP(0,0);
	WriteString("<FLASH>");

	uint8_t i;
	for (i = 2; i<= 4; i++) {
		GotoXP(0,i);
		if (*FlashLine == (i-1)) {
			WriteChar(92+32);
			WriteChar(' ');
		}
		else {
			WriteString("  ");
		}

		switch (i-1) {
		case FlashLine1:
			WriteString("Flash Light");
			break;
		case FlashLine2:
			WriteString("Blinking");
			break;
		case FlashLine3:
			WriteString("S.O.S");
			break;
		}
	}

	GotoXP(0,7);
	if (*FlashLine == FlashBack) {
		WriteChar(92+32);
		WriteChar(' ');
	}
	else {
		WriteString("  ");
	}
	WriteString("Back");
}

void FlashModeLight() {
	SolidFill(0xFF);
}

void FlashModeBlink() {
	timBlinking500.enable = ENABLE;
	if (timBlinking500.tick) uBlinkState ^= 0x01;

	switch (uBlinkState) {
		case BlinkStateOn:
			SolidFill(0xFF);
			break;
		case BlinkStateOff:
			SolidFill(0x00);
			break;
	}
}

void FlashModeSOS() {
	switch (uBlinkState) {
		case BlinkStateOn:
			timBlinking500.enable = ENABLE;
			SolidFill(0xFF);
			if (timBlinking500.tick && uSosCount < 2) {
				uBlinkState = BlinkStateOff;
				uSosCount++;
			}
			if (timBlinking500.tick && uSosCount < 2) {
				uBlinkState = BlinkStateOff;
			}
			break;
		default:
			break;
	}
}

void FlashReset () {
	timBlinking500.enable = DISABLE;
	uBlinkState = BlinkStateOn;
	SolidFill(0x00);
}

void FlashInit() {
	Timer_Append(&timBlinking500);
	Timer_Append(&timBlinking200);
}
