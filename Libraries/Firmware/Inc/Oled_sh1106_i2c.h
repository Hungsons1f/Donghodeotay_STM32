/**
  ******************************************************************************
  * @file    Oled_sh1106_i2c.h
  * @author  Nguyen Hung Son
  * @version V1.1
  * @date    05/12/2024
  * @brief   Oled defines, function headers, running with I2C communication
   ******************************************************************************
  */


/* Includes ------------------------------------------------------------------*/
#include "main.h"

/* Private defines -----------------------------------------------------------*/
#define SH1106_I2C_ADDR		0x78
#define SH1106_TIMEOUT		1000

#define ctrl				0x00
#define data				0x40
#define ColumnMax				127
#define PageMax				7

#define Contrast 				0x81
#define ChargePump 			0x8D
#define AddressMode 			0x20
#define EntireDisplay				0xA4
#define Inverse				0xA6
#define DisplayOn				0xAE
#define ColumnAddress			0x21
#define PageAddress 			0x22
#define MuxRatio				0xA8
#define DisplayOffset			0xD3
#define DisplayStartLine			0x40
#define SegmentRemap			0xA0
#define COMOutScanDir063			0xC0
#define COMOutScanDir630			0xC8
#define COMPinHWConf			0xDA
#define DisplayOscFreq			0xD5
#define Precharge 				0xD9
#define SetVcomDetect			0xDB

#define LowColStartAdd                  0x00
#define HighColStartAdd                 0x10
#define PageStartAdd                    0xB0



/* Private function prototypes -----------------------------------------------*/
uint8_t Oled_WriteCmd (uint8_t iCommand, uint8_t iNumberOfPara, uint8_t iPara1, uint8_t iPara2);
uint8_t Oled_Init(I2C_HandleTypeDef *pI2c);
uint8_t Oled_Update (uint8_t *uScreen, uint8_t uInverse);
uint8_t Oled_Enable (uint8_t on);
