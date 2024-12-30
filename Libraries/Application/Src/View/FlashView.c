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

}

void FlashModeSOS() {

}
