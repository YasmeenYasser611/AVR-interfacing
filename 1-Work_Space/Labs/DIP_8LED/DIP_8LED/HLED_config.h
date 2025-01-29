/*
 * HLED_config.h
 *
 * Created: 1/2/2025 3:08:15 PM
 *  Author: Yasmeen
 */ 


#ifndef HLED_CONFIG_H_
#define HLED_CONFIG_H_

#include "STD_TYPES.h"

typedef enum
{
	HLED_enuForward =0 ,
	HLED_enuReverse
	
}HLED_enuLed_ConnectionOptions_t;

typedef enum
{
	HLED_enuPORTA = 0,
	HLED_enuPORTB,
	HLED_enuPORTC,
	HLED_enuPORTD
} HLED_enuPortNum_t;

typedef enum
{
	HLED_enuOK = 0,
	HLED_enuNOK,
	HLED_enuINVALID_PortNum,
	HLED_enuINVALID_PinNum,
	HLED_enuINVALID_PinStatus,
	HLED_enuINVALID_LEDName ,
	HLED_enuINVALID_LEDValue ,
	HLED_enuINVALID_LEDConnection
	
	
} HLED_enuErrorStatus_t;


typedef enum
{
	HLED_enuPIN0 = 0,
	HLED_enuPIN1,
	HLED_enuPIN2,
	HLED_enuPIN3,
	HLED_enuPIN4,
	HLED_enuPIN5,
	HLED_enuPIN6,
	HLED_enuPIN7
} HLED_enuPinNum_t;


typedef enum
{
	HLED_enuON = 0,
	HLED_enuOFF
	
} HLED_enuState_t;

typedef struct
{
	u8 PORT;  
	u8 PIN;   
	HLED_enuLed_ConnectionOptions_t CONNECTION; 
} HLED_strLedCONFG_t;

#define Num_of_Led 8


#define  Led_start 0
#define  Led_1 1
#define  Led_2 2
#define  Led_3 3
#define  Led_4 4
#define  Led_5 5
#define  Led_6 6
#define  Led_7 7



#endif /* HLED_CONFIG_H_ */