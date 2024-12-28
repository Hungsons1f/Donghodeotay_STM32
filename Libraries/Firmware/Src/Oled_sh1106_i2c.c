/**
  ******************************************************************************
  * @file    Oled_sh1106_i2c.c
  * @author  Nguyen Hung Son
  * @version V1.1
  * @date    05/12/2024
  * @brief   Oled main function running with I2C
   ******************************************************************************
  */


/* Includes ------------------------------------------------------------------*/
#include "Oled_sh1106_i2c.h"

/* Global Variables ----------------------------------------------------------*/
I2C_HandleTypeDef *pI2cCtrlSh1106;

/* Private functions ---------------------------------------------------------*/
uint8_t Oled_Init(I2C_HandleTypeDef *pI2c) {
	pI2cCtrlSh1106 = pI2c;

	if (Oled_WriteCmd((DisplayOn|DISABLE), 0, 0, 0) != SUCCESS) {
		return ERROR;
	};
	if (Oled_WriteCmd(MuxRatio, 1, 0x3F, 0) != SUCCESS) {
		return ERROR;
	};
	if (Oled_WriteCmd(DisplayOffset, 1, 0x00, 0) != SUCCESS) {
		return ERROR;
	};
	if (Oled_WriteCmd(DisplayStartLine, 0, 0, 0) != SUCCESS) {
		return ERROR;
	};
	if (Oled_WriteCmd((SegmentRemap|ENABLE), 0, 0, 0) != SUCCESS) {
		return ERROR;
	};
	if (Oled_WriteCmd(COMOutScanDir630, 0, 0, 0) != SUCCESS) {
		return ERROR;
	};
	if (Oled_WriteCmd(COMPinHWConf, 1, 0x12, 0) != SUCCESS) {
		return ERROR;
	};
	if (Oled_WriteCmd(DisplayOscFreq, 1, 0xF0, 0) != SUCCESS) {
		return ERROR;
	};
	if (Oled_WriteCmd(Precharge, 1, 0x22, 0) != SUCCESS) {
		return ERROR;
	};
	if (Oled_WriteCmd(ChargePump, 1, 0x14, 0) != SUCCESS) {
		return ERROR;
	};
	if (Oled_WriteCmd(SetVcomDetect, 1, 0x20, 0) != SUCCESS) {
		return ERROR;
	};

	if (Oled_WriteCmd(Contrast, 1, 0xFF, 0) != SUCCESS) {
		return ERROR;
	};
	if (Oled_WriteCmd((Inverse|DISABLE), 0, 0, 0) != SUCCESS) {
		return ERROR;
	};
	if (Oled_WriteCmd(AddressMode, 1, 0x10, 0) != SUCCESS) {
		return ERROR;
	};

	if (Oled_WriteCmd((PageStartAdd + 0), 0, 0, 0) != SUCCESS) {
		return ERROR;
	};
	if (Oled_WriteCmd((LowColStartAdd + 0), 0, 0, 0) != SUCCESS) {
		return ERROR;
	};
	if (Oled_WriteCmd((HighColStartAdd + 0), 1, 0x10, 0) != SUCCESS) {
		return ERROR;
	};

	if (Oled_WriteCmd((DisplayOn|ENABLE), 0, 0, 0) != SUCCESS) {
		return ERROR;
	};
	if (Oled_WriteCmd((EntireDisplay|DISABLE), 0, 0, 0) != SUCCESS) {
		return ERROR;
	}

	return SUCCESS;
}

uint8_t Oled_Enable (uint8_t on) {
	if (Oled_WriteCmd((DisplayOn|on), 0, 0, 0) != SUCCESS) {
		return ERROR;
	};
	return SUCCESS;
}

uint8_t Oled_Update (uint8_t *uScreen, uint8_t uInverse)
{
	//OledWriteCmd(PageAddress, 2, 0, 7);
	//OledWriteCmd(ColumnAddress, 2, 0, 127);

	uint8_t i = 0;
	uint8_t j = 0;
	uint16_t x = 0;
	uint8_t _uStatus = 0;
	uint8_t _uInverse = 0x00;

	if (uInverse == ENABLE)
		_uInverse = 0xFF;

	for (j = 0; j<= 7; j++)
	{
		Oled_WriteCmd((PageStartAdd + j), 0, 0, 0 );
		Oled_WriteCmd((LowColStartAdd + ((0+2)&0x0F)), 0,0,0);
		Oled_WriteCmd((HighColStartAdd + ((0+2)>>4)), 0, 0 ,0);

		uint8_t _uBytes[129];
		_uBytes[0] = data;
		for (i = 1; i<= 128; i++)
		{
			_uBytes[i] = ((uScreen[x++])^_uInverse);
		}

		_uStatus = HAL_I2C_Master_Transmit(pI2cCtrlSh1106, SH1106_I2C_ADDR, _uBytes, 129, SH1106_TIMEOUT);
		if (_uStatus != SUCCESS) {
			break;
		}
	}
	return _uStatus;
}

uint8_t Oled_WriteCmd (uint8_t iCommand, uint8_t iNumberOfPara, uint8_t iPara1, uint8_t iPara2) {
	uint8_t _uBytes[4] = {ctrl, iCommand, iPara1, iPara2};
	uint8_t _uStatus = HAL_I2C_Master_Transmit(pI2cCtrlSh1106, SH1106_I2C_ADDR, _uBytes, iNumberOfPara + 2, SH1106_TIMEOUT);
	return _uStatus;
}

