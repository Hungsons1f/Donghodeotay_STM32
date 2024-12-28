/**
  ******************************************************************************
  * @file    Rtc_ds1307_i2c.h
  * @author  Nguyen Hung Son
  * @version V1.0
  * @date    30/11/2024
  * @brief   Realtime Clock defines, function headers, running with I2C communication
   ******************************************************************************
  */


/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "..\Inc\TypeStruct.h"

/* Private defines -----------------------------------------------------------*/
#define DS1307_I2C_ADDR     0x68
#define DS1307_REG_SECOND     0x00
#define DS1307_REG_MINUTE     0x01
#define DS1307_REG_HOUR      0x02
#define DS1307_REG_DAY        0x03
#define DS1307_REG_DATE       0x04
#define DS1307_REG_MONTH      0x05
#define DS1307_REG_YEAR       0x06
#define DS1307_REG_CONTROL     0x07
#define DS1307_REG_UTC_HR    0x08
#define DS1307_REG_UTC_MIN    0x09
#define DS1307_REG_CENT        0x10
#define DS1307_TIMEOUT        1000

/* Private function Prototypes -----------------------------------------------*/
uint8_t DecodeBCD(uint8_t uBin);
uint8_t EncodeBCD(uint8_t uDec);
uint8_t Rtc_GetRegByte(uint8_t uRegAddr, uint8_t *puResult);
uint8_t Rtc_SetRegByte(uint8_t uRegAddr, uint8_t uVal);
uint8_t Rtc_GetTime(stRtcTime *pstRtcTime);
uint8_t Rtc_SetTime(stRtcTime *pstRtcTime);
uint8_t Rtc_Init(I2C_HandleTypeDef *pI2c);
