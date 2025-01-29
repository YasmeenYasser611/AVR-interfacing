/*
 * HSWITCH_config.h
 *
 * Created: 1/2/2025 8:46:39 PM
 *  Author: Yasmeen
 */ 


#ifndef HSWITCH_CONFIG_H_
#define HSWITCH_CONFIG_H_


#include "STD_TYPES.h"

typedef enum
{
	HSWITCH_enuPullUP =0 ,
	HSWITCH_enuPullDown
	
}HSWITCH_enuSWITCH_ConnectionOptions_t;


typedef enum
{
	HSWITCH_enuPORTA = 0,
	HSWITCH_enuPORTB,
	HSWITCH_enuPORTC,
	HSWITCH_enuPORTD
} HSWITCH_enuPortNum_t;

typedef enum
{
	HSWITCH_enuOK = 0,
	HSWITCH_enuNOK,
	HSWITCH_enuINVALID_PortNum,
	HSWITCH_enuINVALID_PinNum,
	HSWITCH_enuINVALID_PinStatus,
	HSWITCH_enuINVALID_SwitchName ,
	HSWITCH_enuNULL_PTR ,
	HSWITCH_enuINVALID_SWITCHConnection
	
} HSWITCH_enuErrorStatus_t;


typedef enum
{
	HSWITCH_enuPIN0 = 0,
	HSWITCH_enuPIN1,
	HSWITCH_enuPIN2,
	HSWITCH_enuPIN3,
	HSWITCH_enuPIN4,
	HSWITCH_enuPIN5,
	HSWITCH_enuPIN6,
	HSWITCH_enuPIN7
} HSWITCH_enuPinNum_t;


typedef struct
{
	u8 PORT;
	u8 PIN;
	HSWITCH_enuSWITCH_ConnectionOptions_t CONNECTION;
} HSWITCH_strSWITCHCONFG_t;

#define Num_of_SWITCH 2


#define  SWITCH1 0
#define  SWITCH2 1


#endif /* HSWITCH_CONFIG_H_ */