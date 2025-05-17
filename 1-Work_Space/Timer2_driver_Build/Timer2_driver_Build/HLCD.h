/*
 * HLCD.h
 *
 * Created: 1/28/2025 1:24:32 PM
 *  Author: TUF
 */ 


#ifndef HLCD_H_
#define HLCD_H_


#include "STD_TYPES.h"
#include "HLCD_congih.h"

typedef enum
{
	HLCD_enuNOK = 0,
	HLCD_enuOK ,
	HLCD_enuINVALIDLCDNAME ,
	HLCD_enuINVALIDLCDX,
	HLCD_enuINVALIDLCDY,
	HLCD_enuINVALIDBLOCK,
	HLCD_enuINVALIDPTR,
	HLCD_enuINVALIDBLOCK_BIT ,
	HLCD_enuINVALIDNUMBER
	
	
	
	
} HLCD_enuErrorStatus_t;


void HLCD_vLCD_init(void);
void HLCD_vLCD_ClearDisplay(u8 Copy_enuLCDNum);
HLCD_enuErrorStatus_t HLCD_enuLCD_WriteCommand(u8 Copy_enuLCDNum,u8 Copy_u8Command);
HLCD_enuErrorStatus_t HLCD_enuLCD_WriteCharacter(u8 Copy_enuLCDNum, u8 Copy_u8Data);
HLCD_enuErrorStatus_t HLCD_enuLCD_GotoXY(u8 Copy_enuLCDNum,u8 Copy_u8X , u8 Copy_u8Y );
HLCD_enuErrorStatus_t HLCD_enuLCD_WriteSpecialChar(u8 Copy_enuLCDNum , u8 Copy_u8BlockNumber , u8* pattern ,u8 Copy_u8X , u8 Copy_u8Y);

HLCD_enuErrorStatus_t HLCD_enuLCD_WriteString(u8 Copy_enuLCDNum , u8* string);
HLCD_enuErrorStatus_t HLCD_enuLCD_WriteNumber(u8 Copy_enuLCDNum ,u32 Copy_U32Number);


#endif /* HLCD_H_ */