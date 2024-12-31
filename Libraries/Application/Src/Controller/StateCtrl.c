/**
  ******************************************************************************
  * @file    StateCtrl.c
  * @author  Nguyen Hung Son
  * @version V1.0
  * @date    20/12/2024
  * @brief   Main state machine controller function
   ******************************************************************************
  */


/* Includes ------------------------------------------------------------------*/
#include "StateCtrl.h"

/* Global Variables ----------------------------------------------------------*/
uint8_t uStateLevel = IdlingLevel;
uint8_t uFuncMenu = AlarmFunc;

uint8_t uNumIcon = 0;//IBattery | ICharge | IAlarm | ISound | ICount;
volatile stDispTime stCurrentTime = {0,0,0,0,0,0,1,0,1,0,1,0,0};
volatile stAlarm stAlarm1[5] = {				/* Struct store alarms information, including 5 alarms */
		0,0,0,0,0,0,
		0,0,0,0,0,0,
		0,0,0,0,0,0,
		0,0,0,0,0,0,
		0,0,0,0,0,0
};

/* Buttons ------*/
volatile uint8_t uUp;
volatile uint8_t uDown;
volatile uint8_t uPush;

stButton btnUp;
stButton btnDown;
stButton btnPush;



/* Private functions ---------------------------------------------------------*/
void MainStateInit () {
	FlashCtrlInit();
}

void MainStateMachine () {
	switch (uStateLevel) {

		case IdlingLevel:
			if (btnPush.rising) {
				uStateLevel = MenuLevel;
				SolidFill(0x00);			//Clear the screen
			}
			break;


		case MenuLevel:
			if (btnDown.rising) {
				uFuncMenu++;
				if (uFuncMenu > BackFunc) uFuncMenu = AlarmFunc;
			}
			if (btnUp.rising) {
				uFuncMenu--;
				if (uFuncMenu < AlarmFunc) uFuncMenu = BackFunc;
			}
			if (btnPush.rising) {
				if (uFuncMenu == BackFunc) {
					uStateLevel = IdlingLevel;
					uFuncMenu = AlarmFunc;
				}
				else {
					uStateLevel = FunctionLevel;
				}
				SolidFill(0x00);			//Clear the screen
			}
			break;


		case FunctionLevel:
			switch (uFuncMenu) {
				case AlarmFunc:
					if (!AlarmState(stAlarm1, &btnPush, &btnUp, &btnDown)) {
						uStateLevel = MenuLevel;
						SolidFill(0x00);
					}
					break;

				case FlashFunc:
					if (!FlashState(&btnPush, &btnUp, &btnDown)) {
						uStateLevel = MenuLevel;
						SolidFill(0x00);
					}
					break;

				case CounterFunc:
					//counter state
					break;

				case SettingFunc:
					//setting state
					break;

				case CreditFunc:
					//credit state
					break;
			}
			break;
	}
}

void MainStateAction () {
	switch (uStateLevel) {
		case IdlingLevel:
			IdlingStateAction(&uNumIcon, &stCurrentTime);
			break;

		case MenuLevel:
			MenuStateAction(&uNumIcon, uFuncMenu, &stCurrentTime);
			break;

		case FunctionLevel:
			switch (uFuncMenu) {
				case AlarmFunc:
					AlarmStateAction(stAlarm1, &uNumIcon);
					break;
				case FlashFunc:
					FlastStateAction(&uNumIcon);
					break;
			}

			break;

		default:
			break;
	}

	Button_ExeUp(&btnUp);
	Button_ExeDown(&btnDown);
	Button_ExePush(&btnPush);
}


