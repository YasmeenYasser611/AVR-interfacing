/*
 * MDIO.h
 *
 * Created: 12/17/2024 1:28:39 PM
 *  Author: TUF
 */ 


#ifndef MDIO_H_
#define MDIO_H_

#include "STD_TYPES.h"
#define NULL ((void*)0)


typedef enum
{
	MDIO_enuOK ,
	MDIO_enuNOK ,
	MDIO_enuINVALID_PortNum,
	MDIO_enuINVALID_PinNum,
	MDIO_enuINVALID_Configration,
	MDIO_enuINVALID_PinStatus ,
	MDIO_enuINVALID_PortStatus,	
	MDIO_enuNULL_PTR
	
}MDIO_enuErrorStatus_t;
typedef enum
{
	MDIO_enuPORTA ,
	MDIO_enuPORTB ,
	MDIO_enuPORTC ,
	MDIO_enuPORTD

}MDIO_enuPortNum;
typedef enum
{
	MDIO_enuPIN0 ,
	MDIO_enuPIN1 ,
	MDIO_enuPIN2 ,
	MDIO_enuPIN3 ,
	MDIO_enuPIN4 ,
	MDIO_enuPIN5 ,
	MDIO_enuPIN6 ,
	MDIO_enuPIN7 
}MDIO_enuPinNum;
typedef enum
{
	MDIO_enuOUTPUT  ,
	MDIO_enuINPUT_PULLUP ,
	MDIO_enuINPUT_PULLDOWN ,
	MDIO_enuALL_OUTPUT = 0xff  ,
	MDIO_enuALL_INPUT_PULLUP =0x00 ,
	MDIO_enuALL_INPUT_PULLDOWN = 0x00 
	
	
	
}MDIO_enuConfigration;
typedef enum
{
	MDIO_enuLOW =0 ,
	MDIO_enuHIGH =1 
	 
	
}MDIO_enuState;
typedef enum
{
	MDIO_enuAll_HIGH = 0xff ,
	MDIO_enuAll_LOW = 0x00
	
}MDIO_enuPortState;


MDIO_enuErrorStatus_t MDIO_enuSetPinConfigration(MDIO_enuPortNum Copy_enuPortNum,MDIO_enuPinNum Copy_enuPinNum,MDIO_enuConfigration Copy_enuConfigration);
MDIO_enuErrorStatus_t MDIO_enuSetPortConfigration(MDIO_enuPortNum Copy_enuPortNum,MDIO_enuConfigration Copy_enuConfigration);
MDIO_enuErrorStatus_t MDIO_enuSetPinValue( MDIO_enuPortNum Copy_enuPortNum, MDIO_enuPinNum Copy_enuPinNum, MDIO_enuState Copy_enuState);
MDIO_enuErrorStatus_t MDIO_enuSetPortValue(MDIO_enuPortNum Copy_enuPortNum,MDIO_enuPortState Copy_enuPortState);
MDIO_enuErrorStatus_t MDIO_enuGetPinValue(MDIO_enuPortNum Copy_enuPortNum,MDIO_enuPinNum Copy_enuPinNum,u8* Add_pu8PinValue); 





#endif /* MDIO_H_ */