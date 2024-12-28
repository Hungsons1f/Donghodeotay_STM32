/* Global Structs ------------------------------------------------------------*/
#include "main.h"

#ifndef REALTIMESTRUCT_H_
#define REALTIMESTRUCT_H_

typedef struct
{
    uint8_t sec;
    uint8_t min;
    uint8_t hour;
    uint8_t day;
    uint8_t date;
    uint8_t month;
    uint8_t year;
}stRtcTime;

typedef struct
{
	uint8_t hour10;
	uint8_t hour;
	uint8_t min10;
	uint8_t min;
	uint8_t sec10;
	uint8_t sec;
	uint8_t date;
	uint8_t day10;
	uint8_t day;
	uint8_t mon10;
	uint8_t mon;
	uint8_t year10;
	uint8_t year;
}stDispTime;

#endif

#ifndef COUNTERSTRUCT_H_
#define COUNTERSTRUCT_H_

typedef struct
{
	uint8_t min10;
	uint8_t min;
	uint8_t sec10;
	uint8_t sec;
	uint8_t decisec;
	uint8_t centisec;
	uint8_t enable;
}stCounter;

#endif

#ifndef ALARMSTRUCT_H_
#define ALARMSTRUCT_H_

typedef struct
{
	uint8_t hour10;
	uint8_t hour;
	uint8_t min10;
	uint8_t min;
	uint8_t date;
	uint8_t enable;
}stAlarm;

#endif

#ifndef YESNOENUM_H_
#define YESNOENUM_H_

#ifndef BUTTONSTRUCT_H_
#define BUTTONSTRUCT_H_

typedef struct
{
	uint8_t value;
	uint8_t rising;
	uint8_t falling;
	uint8_t lastvalue;
}stButton;

#endif

typedef enum
{
	YES = 1,
	NO = 0
}eYesNo;

#endif
