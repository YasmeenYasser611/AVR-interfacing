/*
 * HDCMOTOR_Confg.h
 *
 * Created: 2/17/2025 2:04:09 PM
 *  Author: TUF
 */ 


#ifndef HDCMOTOR_CONFG_H_
#define HDCMOTOR_CONFG_H_


#include "STD_TYPES.h"

typedef enum
{
	HMOTOR_enuForward = 0,
	HMOTOR_enuReverse
} HMOTOR_enuConnection_t;

typedef enum
{
	HMOTOR_enuPORTA = 0,
	HMOTOR_enuPORTB,
	HMOTOR_enuPORTC,
	HMOTOR_enuPORTD
} HMOTOR_enuPort_t;

typedef enum
{
	HMOTOR_enuPIN0 = 0,
	HMOTOR_enuPIN1,
	HMOTOR_enuPIN2,
	HMOTOR_enuPIN3,
	HMOTOR_enuPIN4,
	HMOTOR_enuPIN5,
	HMOTOR_enuPIN6,
	HMOTOR_enuPIN7
} HMOTOR_enuPin_t;

typedef enum
{
	HMOTOR_enuSTOP = 0,
	HMOTOR_enuFORWARD,
	HMOTOR_enuREVERSE
} HMOTOR_enuState_t;

typedef struct
{
	u8 PORT_A;
	u8 PIN_A;
	u8 PORT_B;
	u8 PIN_B;
} HMOTOR_strMotorConfig_t;

#define Num_of_Motors 1

#define Motor1 0







#endif /* HDCMOTOR_CONFG_H_ */