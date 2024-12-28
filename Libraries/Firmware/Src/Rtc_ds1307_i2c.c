/**
  ******************************************************************************
  * @file    rtc_ds3232_i2c.c
  * @author  Nguyen Hung Son
  * @version V2.0
  * @date    03/07/199
  * @brief   Realtime Clock function running with I2C
   ******************************************************************************
  */


/* Includes ------------------------------------------------------------------*/
#include "Rtc_ds1307_i2c.h"


/* Global Variables ----------------------------------------------------------*/
I2C_HandleTypeDef *pI2cController;


/* Private functions ---------------------------------------------------------*/
uint8_t DecodeBCD(uint8_t uBin) {
    return (((uBin & 0xf0) >> 4) * 10) + (uBin & 0x0f);
}

uint8_t EncodeBCD(uint8_t uDec) {
    return (uDec % 10 + ((uDec / 10) << 4));
}

uint8_t Rtc_SetRegByte(uint8_t uRegAddr, uint8_t uVal) {
    uint8_t _uBytes[2] = { uRegAddr, uVal };
    uint8_t _uStatus = HAL_I2C_Master_Transmit(pI2cController, DS1307_I2C_ADDR << 1, _uBytes, 2, DS1307_TIMEOUT);
    return _uStatus;
}

uint8_t Rtc_GetRegByte(uint8_t uRegAddr, uint8_t *puResult) {
    uint8_t _uVal;
    uint8_t _uStatus1 = HAL_I2C_Master_Transmit(pI2cController, DS1307_I2C_ADDR << 1, &uRegAddr, 1, DS1307_TIMEOUT);
    uint8_t _uStatus2 = HAL_I2C_Master_Receive(pI2cController, DS1307_I2C_ADDR << 1, &_uVal, 1, DS1307_TIMEOUT);
    *puResult = _uVal;
    return (_uStatus1 << 4) + _uStatus2;
}

uint8_t Rtc_GetTime(stRtcTime *pstRtcTime) {
	if (Rtc_GetRegByte(DS1307_REG_SECOND, &(pstRtcTime->sec)) != 0) {
		return 1;
	}
	if (Rtc_GetRegByte(DS1307_REG_MINUTE, &(pstRtcTime->min)) != 0) {
		return 1;
	}
	if (Rtc_GetRegByte(DS1307_REG_HOUR, &(pstRtcTime->hour)) != 0) {
		return 1;
	}
	if (Rtc_GetRegByte(DS1307_REG_DAY, &(pstRtcTime->day)) != 0) {
		return 1;
	}
	if (Rtc_GetRegByte(DS1307_REG_DATE, &(pstRtcTime->date)) != 0) {
		return 1;
	}
	if (Rtc_GetRegByte(DS1307_REG_MONTH, &(pstRtcTime->month)) != 0) {
		return 1;
	}
	if (Rtc_GetRegByte(DS1307_REG_YEAR, &(pstRtcTime->year)) != 0) {
		return 1;
	}

	pstRtcTime->sec=DecodeBCD(pstRtcTime->sec & 0x7f);
    pstRtcTime->min=DecodeBCD(pstRtcTime->min);
    pstRtcTime->hour=DecodeBCD(pstRtcTime->hour & 0x3f);
    pstRtcTime->day=DecodeBCD(pstRtcTime->day);
    pstRtcTime->date=DecodeBCD(pstRtcTime->date);
    pstRtcTime->month=DecodeBCD(pstRtcTime->month);
    pstRtcTime->year=DecodeBCD(pstRtcTime->year);
    return 0;
}

uint8_t Rtc_SetTime(stRtcTime *pstRtcTime) {
	if (Rtc_SetRegByte(DS1307_REG_SECOND, EncodeBCD(pstRtcTime->sec)) != 0) {
		return 1;
	}
	if (Rtc_SetRegByte(DS1307_REG_MINUTE, EncodeBCD(pstRtcTime->min)) != 0) {
		return 1;
	}
	if (Rtc_SetRegByte(DS1307_REG_HOUR, EncodeBCD(pstRtcTime->hour)) != 0) {
		return 1;
	}
	if (Rtc_SetRegByte(DS1307_REG_DAY, EncodeBCD(pstRtcTime->day)) != 0) {
		return 1;
	}
	if (Rtc_SetRegByte(DS1307_REG_DATE, EncodeBCD(pstRtcTime->date)) != 0) {
		return 1;
	}
	if (Rtc_SetRegByte(DS1307_REG_MONTH, EncodeBCD(pstRtcTime->month)) != 0) {
		return 1;
	}
	if (Rtc_SetRegByte(DS1307_REG_YEAR, EncodeBCD(pstRtcTime->year)) != 0) {
		return 1;
	}
	return 0;
}

uint8_t Rtc_Init(I2C_HandleTypeDef *pI2c) {
	pI2cController = pI2c;
	return 0;
}
