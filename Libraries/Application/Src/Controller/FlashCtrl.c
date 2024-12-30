/**
  ******************************************************************************
  * @file    FlashCtrl.c
  * @author  Nguyen Hung Son
  * @version V1.0
  * @date    26/12/2024
  * @brief   Flash controller function
   ******************************************************************************
  */


/* Includes ------------------------------------------------------------------*/
#include "FlashCtrl.h"

/* Global Variables ----------------------------------------------------------*/
uint8_t Flashline = FlashLine1;
uint8_t FlashOn;

/* Private functions ---------------------------------------------------------*/
uint8_t FlashState(stButton *btnPush, stButton *btnUp, stButton *btnDown) {
	switch (FlashOn) {
		case NO:
			if (btnDown->rising) {
				Flashline++;
				if (Flashline > FlashBack)	Flashline = FlashLine1;
			}
			if (btnUp->rising) {
		        Flashline--;
				if (Flashline < FlashLine1)	Flashline = FlashBack;
			}
			if (btnPush->rising) {
				if (Flashline == FlashBack) {
					Flashline = FlashLine1;
					return BackToMenu;
				}
				FlashOn = YES;
			}
			break;
		case YES:
			switch (Flashline) {
				case FlashLine1:
					if (btnPush->rising) {
						FlashOn = NO;
					}
					break;
				case FlashLine2:
					if (btnPush->rising) {
						FlashOn = NO;
					}
					break;
				case FlashLine3:
					if (btnPush->rising) {
						FlashOn = NO;
					}
					break;
				default:
					break;
			}
			break;
	}
	return StayInFunc;
}

void FlastStateAction (uint8_t *numOfIcon) {
	static uint8_t lastState;
	switch (FlashOn) {
		case NO:
			if (lastState == YES) SolidFill(0x00);

			DispFlashLine(&Flashline);
			DispTopRightIcon(numOfIcon);
			lastState = NO;
			break;
		case YES:
			switch (Flashline) {
				case FlashLine1:
					FlashModeLight();
					break;
				case FlashLine2:
					FlashModeBlink();
					break;
				case FlashLine3:
					FlashModeSOS();
					break;
			}
			lastState = YES;
	}
}


