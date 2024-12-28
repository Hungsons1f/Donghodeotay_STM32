/**
  ******************************************************************************
  * @file    MenuView.c
  * @author  Nguyen Hung Son
  * @version V1.1
  * @date    17/12/2024
  * @brief   Functions for main menu screen
   ******************************************************************************
  */


/* Includes ------------------------------------------------------------------*/
#include "MenuView.h"

/* Global Variables ----------------------------------------------------------*/
void DispMenuName (uint8_t status)
{
	GotoXP(14,2);
	WriteString("-MENU-");
	switch (status)
	{
	case 6:
		DeleteString(5, 5, 9);
		GotoXP(14,5);
		WriteString("<Back>   ");
		break;
	case 1:
		DeleteString(5, 5, 9);
		GotoXP(11,5);
		WriteString("<Alarm>  ");
		break;
	case 2:
		DeleteString(5, 5, 9);
		GotoXP(5,5);
		WriteString("<Counter>");
		break;
	case 3:
		DeleteString(5, 5, 9);
		GotoXP(11,5);
		WriteString("<Flash>  ");
		break;
	case 4:
		DeleteString(5, 5, 9);
		GotoXP(5,5);
		WriteString("<Setting>");
		break;
	case 5:
		DeleteString(5, 5, 9);
		GotoXP(8,5);
		WriteString("<Credit> ");
		break;
	default:
		break;
	}
}

void DispMenuIcon (uint8_t Status)
{
	switch (Status)
	{
	case 6:
		DrawImage(BackMenu, 82,113,2,5);
		break;
	case 1:
		DrawImage(AlarmMenu, 82,113,2,5);
		break;
	case 2:
		DrawImage(CounterMenu, 82,113,2,5);
		break;
	case 3:
		DrawImage(FlashMenu, 82,113,2,5);
		break;
	case 4:
		DrawImage(SettingMenu, 82,113,2,5);
		break;
	case 5:
		DrawImage(CreditMenu, 82,113,2,5);
		break;
	default:
	}
	GotoXP(78,1);
	WriteCol(0xF0);
	for (uint8_t i = 80; i<= 116; i++)
		WriteCol(0x10);
	WriteCol(0xF0);
	GotoXP(78,6);
	WriteCol(0x0F);
	for (uint8_t i = 80; i<= 116; i++)
		WriteCol(0x08);
	WriteCol(0x0F);
}
