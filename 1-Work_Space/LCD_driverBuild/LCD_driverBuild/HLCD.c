/*
 * HLCD.c
 *
 * Created: 1/28/2025 1:24:18 PM
 *  Author: TUF
 */ 

#include "HLCD.h"
#include "HLCD_congih.h"
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "MPORT.h"
#include "MDIO.h"
#define F_CPU 8000000UL
#include <util/delay.h>

#define NULL ((void*)0)

#define IS_INVALID_LCD_NAME(X)			((((u8)X) > Num_of_LCD) || (((u8)X) < 0))
#define IS_INVALID_LCD_Y(X)			((((u8)X) > 15) || (((u8)X) < 0))
#define IS_INVALID_LCD_X(X)			((((u8)X) > 1) || (((u8)X) < 0))
#define IS_INVALID_LCD_BLOCK(X)			((((u8)X) > 8) || (((u8)X) < 0))
#define IS_INVALID_LCD_PATTERN(X)				((X) == NULL)
#define IS_INVALID_LCD_BLOCK_BIT(X)			((((u8)X) > 8) || (((u8)X) < 0))



extern  HLCD_strLCDCONFG_8BIT_t HLCD_ArrLCDCongf[Num_of_LCD];

void HLCD_vLCD_init(void)
{
     u8 Local_u8_LCd_D0=0 , Local_u8_LCd_D1=0 , Local_u8_LCd_D2=0 , Local_u8_LCd_D3=0 , Local_u8_LCd_D4=0 , Local_u8_LCd_D5=0 , Local_u8_LCd_D6=0 , Local_u8_LCd_D7=0 , Local_u8_LCd_RS=0 , Local_u8_LCd_RW=0 , Local_u8_LCd_E=0;
	 for (int i = 0; i < Num_of_LCD; i++) 
	 {

		
		 /*1-Wait for more than 30msafter VDD rises to 4.5V.*/
		 _delay_ms(35);
		 u8 functionSetCmd = 0x20; // Base value: 0b00100000
		 /*2-send function set command*/

		 // Set DL (Data Length)
		 if (HLCD_ArrLCDCongf[i].DL == HLCD_enu_8Bits) 
		 {
		 Local_u8_LCd_D0 = ((HLCD_ArrLCDCongf[i].D0_Port<<4) + HLCD_ArrLCDCongf[i].D0_Pin);
		 MPORT_enuSetPinDirection(Local_u8_LCd_D0 , MPORT_enuPINOUTPUT);
		 Local_u8_LCd_D1 = ((HLCD_ArrLCDCongf[i].D1_Port<<4) + HLCD_ArrLCDCongf[i].D1_Pin);
		 MPORT_enuSetPinDirection(Local_u8_LCd_D1 , MPORT_enuPINOUTPUT);
		 Local_u8_LCd_D2 = ((HLCD_ArrLCDCongf[i].D2_Port<<4) + HLCD_ArrLCDCongf[i].D2_Pin);
		 MPORT_enuSetPinDirection(Local_u8_LCd_D2 , MPORT_enuPINOUTPUT);
		 Local_u8_LCd_D3 = ((HLCD_ArrLCDCongf[i].D3_Port<<4) + HLCD_ArrLCDCongf[i].D3_Pin);
		 MPORT_enuSetPinDirection(Local_u8_LCd_D3 , MPORT_enuPINOUTPUT);
		 Local_u8_LCd_D4 = ((HLCD_ArrLCDCongf[i].D4_Port<<4) + HLCD_ArrLCDCongf[i].D4_Pin);
		 MPORT_enuSetPinDirection(Local_u8_LCd_D4 , MPORT_enuPINOUTPUT);
		 Local_u8_LCd_D5 = ((HLCD_ArrLCDCongf[i].D5_Port<<4) + HLCD_ArrLCDCongf[i].D5_Pin);
		 MPORT_enuSetPinDirection(Local_u8_LCd_D5 , MPORT_enuPINOUTPUT);
		 Local_u8_LCd_D6 = ((HLCD_ArrLCDCongf[i].D6_Port<<4) + HLCD_ArrLCDCongf[i].D6_Pin);
		 MPORT_enuSetPinDirection(Local_u8_LCd_D6 , MPORT_enuPINOUTPUT);
		 Local_u8_LCd_D7 = ((HLCD_ArrLCDCongf[i].D7_Port<<4) + HLCD_ArrLCDCongf[i].D7_Pin);
		 MPORT_enuSetPinDirection(Local_u8_LCd_D7 , MPORT_enuPINOUTPUT);
		 Local_u8_LCd_RS = ((HLCD_ArrLCDCongf[i].RS_Port<<4) + HLCD_ArrLCDCongf[i].RS_Pin);
		 MPORT_enuSetPinDirection(Local_u8_LCd_RS , MPORT_enuPINOUTPUT);
		 Local_u8_LCd_RW = ((HLCD_ArrLCDCongf[i].RW_Port<<4) + HLCD_ArrLCDCongf[i].RW_Pin);
		 MPORT_enuSetPinDirection(Local_u8_LCd_RW , MPORT_enuPINOUTPUT);
		 Local_u8_LCd_E = ((HLCD_ArrLCDCongf[i].E_Port<<4) + HLCD_ArrLCDCongf[i].E_Pin);
		 MPORT_enuSetPinDirection(Local_u8_LCd_E , MPORT_enuPINOUTPUT);
		 
		 functionSetCmd |= 0x10; // Set DL to 1

		 }
		 else if(HLCD_ArrLCDCongf[i].DL == HLCD_enu_4Bits)
		 {
		 Local_u8_LCd_D4 = ((HLCD_ArrLCDCongf[i].D4_Port<<4) + HLCD_ArrLCDCongf[i].D4_Pin);
		 MPORT_enuSetPinDirection(Local_u8_LCd_D4 , MPORT_enuPINOUTPUT);
		 Local_u8_LCd_D5 = ((HLCD_ArrLCDCongf[i].D5_Port<<4) + HLCD_ArrLCDCongf[i].D5_Pin);
		 MPORT_enuSetPinDirection(Local_u8_LCd_D5 , MPORT_enuPINOUTPUT);
		 Local_u8_LCd_D6 = ((HLCD_ArrLCDCongf[i].D6_Port<<4) + HLCD_ArrLCDCongf[i].D6_Pin);
		 MPORT_enuSetPinDirection(Local_u8_LCd_D6 , MPORT_enuPINOUTPUT);
		 Local_u8_LCd_D7 = ((HLCD_ArrLCDCongf[i].D7_Port<<4) + HLCD_ArrLCDCongf[i].D7_Pin);
		 MPORT_enuSetPinDirection(Local_u8_LCd_D7 , MPORT_enuPINOUTPUT);
		 Local_u8_LCd_RS = ((HLCD_ArrLCDCongf[i].RS_Port<<4) + HLCD_ArrLCDCongf[i].RS_Pin);
		 MPORT_enuSetPinDirection(Local_u8_LCd_RS , MPORT_enuPINOUTPUT);
		 Local_u8_LCd_RW = ((HLCD_ArrLCDCongf[i].RW_Port<<4) + HLCD_ArrLCDCongf[i].RW_Pin);
		 MPORT_enuSetPinDirection(Local_u8_LCd_RW , MPORT_enuPINOUTPUT);
		 Local_u8_LCd_E = ((HLCD_ArrLCDCongf[i].E_Port<<4) + HLCD_ArrLCDCongf[i].E_Pin);
		 MPORT_enuSetPinDirection(Local_u8_LCd_E , MPORT_enuPINOUTPUT);
		 
		  HLCD_enuLCD_WriteCommand(i, 0b00000010 );
		 }
		 // Set N (Number of Display Lines)
		 if (HLCD_ArrLCDCongf[i].N == HLCD_enu_2Lines) {
			 functionSetCmd |= 0x08; // Set N to 1
		 }
		 // Set F (Font Type)
		 if (HLCD_ArrLCDCongf[i].F == HLCD_enu_5x11) {
			 functionSetCmd |= 0x04; // Set F to 1
		 }
		 HLCD_enuLCD_WriteCommand(i, functionSetCmd );
		 
		 /*3-wait more than 39us*/
		 _delay_us(50);
		 
		 
		 /*4-display on / off control */
		 // Display ON/OFF Control Command
		 u8 displayCtrlCmd = 0x08; // Base value: 0b00001000
		 // Set D (Display ON/OFF)
		 if (HLCD_ArrLCDCongf[i].D == HLCD_enu_LCD_on) {
			 displayCtrlCmd |= 0x04; // Set D to 1
		 }
		 // Set C (Cursor ON/OFF)
		 if (HLCD_ArrLCDCongf[i].C == HLCD_enu_Cursor_on) {
			 displayCtrlCmd |= 0x02; // Set C to 1
		 }
		 // Set B (Blink ON/OFF)
		 if (HLCD_ArrLCDCongf[i].B == HLCD_enu_Blink_on) {
			 displayCtrlCmd |= 0x01; // Set B to 1
		 }
		 // Send the Display ON/OFF Control command to the LCD
		 HLCD_enuLCD_WriteCommand(i, displayCtrlCmd);
		 
		 /*5- delay more than 39 us*/
		 _delay_us(50);
		 
		 /*6-display clear*/
		 HLCD_vLCD_ClearDisplay(i);
		 
		 /*7-delay more than 1.53ms*/
		 _delay_ms(2);
		 
		 /*8-entry mode set*/
		 u8 entryModeCmd = 0x04; // Base value: 0b00000100
		 // Set I/D (Increment/Decrement)
		 if (HLCD_ArrLCDCongf[i].I_D == HLCD_enu_INC) {
			 entryModeCmd |= 0x02; // Set I/D to 1
		 }
		 // Set SH (Shift Entire Display)
		 if (HLCD_ArrLCDCongf[i].S == HLCD_enu_EnableShift) {
			 entryModeCmd |= 0x01; // Set SH to 1
		 }
		 // Send the Entry Mode Set command to the LCD
		 HLCD_enuLCD_WriteCommand(i, entryModeCmd);
		 
	 }
	
}
void HLCD_vLCD_ClearDisplay(u8 Copy_enuLCDNum)
{
	HLCD_enuLCD_WriteCommand(Copy_enuLCDNum, 0x01);
	
}
HLCD_enuErrorStatus_t HLCD_enuLCD_WriteCommand(u8 Copy_enuLCDNum,u8 Copy_u8Command)
{
	HLCD_enuErrorStatus_t Ret_enuError = HLCD_enuNOK;
	if(IS_INVALID_LCD_NAME(Copy_enuLCDNum))
	{
		Ret_enuError =HLCD_enuINVALIDLCDNAME ; 
		
	}
	else
	{
	 Ret_enuError = HLCD_enuOK;
	/*1-rw->low for writing*/
	MDIO_enuSetPinValue(HLCD_ArrLCDCongf[Copy_enuLCDNum].RW_Port , HLCD_ArrLCDCongf[Copy_enuLCDNum].RW_Pin, MDIO_enuLOW);
	/*2-rs-> low for command*/
	MDIO_enuSetPinValue(HLCD_ArrLCDCongf[Copy_enuLCDNum].RS_Port , HLCD_ArrLCDCongf[Copy_enuLCDNum].RS_Pin, MDIO_enuLOW);
	 if(HLCD_ArrLCDCongf[Copy_enuLCDNum].DL == HLCD_enu_8Bits)
	 {

	/*3-send command*/
	MDIO_enuSetPinValue(HLCD_ArrLCDCongf[Copy_enuLCDNum].D0_Port , HLCD_ArrLCDCongf[Copy_enuLCDNum].D0_Pin,(Copy_u8Command >> 0) & 0x01 );
	MDIO_enuSetPinValue(HLCD_ArrLCDCongf[Copy_enuLCDNum].D1_Port , HLCD_ArrLCDCongf[Copy_enuLCDNum].D1_Pin,(Copy_u8Command >> 1) & 0x01 );
	MDIO_enuSetPinValue(HLCD_ArrLCDCongf[Copy_enuLCDNum].D2_Port , HLCD_ArrLCDCongf[Copy_enuLCDNum].D2_Pin,(Copy_u8Command >> 2) & 0x01 );
	MDIO_enuSetPinValue(HLCD_ArrLCDCongf[Copy_enuLCDNum].D3_Port , HLCD_ArrLCDCongf[Copy_enuLCDNum].D3_Pin,(Copy_u8Command >> 3) & 0x01 );
	MDIO_enuSetPinValue(HLCD_ArrLCDCongf[Copy_enuLCDNum].D4_Port , HLCD_ArrLCDCongf[Copy_enuLCDNum].D4_Pin,(Copy_u8Command >> 4) & 0x01 );
	MDIO_enuSetPinValue(HLCD_ArrLCDCongf[Copy_enuLCDNum].D5_Port , HLCD_ArrLCDCongf[Copy_enuLCDNum].D5_Pin,(Copy_u8Command >> 5) & 0x01 );
	MDIO_enuSetPinValue(HLCD_ArrLCDCongf[Copy_enuLCDNum].D6_Port , HLCD_ArrLCDCongf[Copy_enuLCDNum].D6_Pin,(Copy_u8Command >> 6) & 0x01 );
	MDIO_enuSetPinValue(HLCD_ArrLCDCongf[Copy_enuLCDNum].D7_Port , HLCD_ArrLCDCongf[Copy_enuLCDNum].D7_Pin,(Copy_u8Command >> 7) & 0x01 );
	}
	else if(HLCD_ArrLCDCongf[Copy_enuLCDNum].DL == HLCD_enu_4Bits)
	{
		/*3-send command*/
		
	/* 1. Send the higher nibble (bits 7-4) */
    MDIO_enuSetPinValue(HLCD_ArrLCDCongf[Copy_enuLCDNum].D4_Port , HLCD_ArrLCDCongf[Copy_enuLCDNum].D4_Pin, (Copy_u8Command >> 4) & 0x01);
    MDIO_enuSetPinValue(HLCD_ArrLCDCongf[Copy_enuLCDNum].D5_Port , HLCD_ArrLCDCongf[Copy_enuLCDNum].D5_Pin, (Copy_u8Command >> 5) & 0x01);
    MDIO_enuSetPinValue(HLCD_ArrLCDCongf[Copy_enuLCDNum].D6_Port , HLCD_ArrLCDCongf[Copy_enuLCDNum].D6_Pin, (Copy_u8Command >> 6) & 0x01);
    MDIO_enuSetPinValue(HLCD_ArrLCDCongf[Copy_enuLCDNum].D7_Port , HLCD_ArrLCDCongf[Copy_enuLCDNum].D7_Pin, (Copy_u8Command >> 7) & 0x01);

    /* 2. Enable pulse (to latch the higher nibble) */
    MDIO_enuSetPinValue(HLCD_ArrLCDCongf[Copy_enuLCDNum].E_Port , HLCD_ArrLCDCongf[Copy_enuLCDNum].E_Pin, MDIO_enuHIGH);
    _delay_us(1);
    MDIO_enuSetPinValue(HLCD_ArrLCDCongf[Copy_enuLCDNum].E_Port , HLCD_ArrLCDCongf[Copy_enuLCDNum].E_Pin, MDIO_enuLOW);
    _delay_us(1);
	


    /* 3. Send the lower nibble (bits 3-0) */
    MDIO_enuSetPinValue(HLCD_ArrLCDCongf[Copy_enuLCDNum].D4_Port , HLCD_ArrLCDCongf[Copy_enuLCDNum].D4_Pin, (Copy_u8Command >> 0) & 0x01);
    MDIO_enuSetPinValue(HLCD_ArrLCDCongf[Copy_enuLCDNum].D5_Port , HLCD_ArrLCDCongf[Copy_enuLCDNum].D5_Pin, (Copy_u8Command >> 1) & 0x01);
    MDIO_enuSetPinValue(HLCD_ArrLCDCongf[Copy_enuLCDNum].D6_Port , HLCD_ArrLCDCongf[Copy_enuLCDNum].D6_Pin, (Copy_u8Command >> 2) & 0x01);
    MDIO_enuSetPinValue(HLCD_ArrLCDCongf[Copy_enuLCDNum].D7_Port , HLCD_ArrLCDCongf[Copy_enuLCDNum].D7_Pin, (Copy_u8Command >> 3) & 0x01);
		
		
	}
	/*4-enable */
	MDIO_enuSetPinValue(HLCD_ArrLCDCongf[Copy_enuLCDNum].E_Port , HLCD_ArrLCDCongf[Copy_enuLCDNum].E_Pin, MDIO_enuHIGH);
	_delay_us(1);
	MDIO_enuSetPinValue(HLCD_ArrLCDCongf[Copy_enuLCDNum].E_Port , HLCD_ArrLCDCongf[Copy_enuLCDNum].E_Pin, MDIO_enuLOW);
	_delay_us(1);
	}
return Ret_enuError ;
}
HLCD_enuErrorStatus_t HLCD_enuLCD_WriteCharacter(u8 Copy_enuLCDNum, u8 Copy_u8Data)
{
	HLCD_enuErrorStatus_t Ret_enuError = HLCD_enuNOK;
	if(IS_INVALID_LCD_NAME(Copy_enuLCDNum))
	{
		Ret_enuError =HLCD_enuINVALIDLCDNAME ; 
		
	}
	else
	{
	 Ret_enuError = HLCD_enuOK;
     /*1-rw->low for writing*/
	MDIO_enuSetPinValue(HLCD_ArrLCDCongf[Copy_enuLCDNum].RW_Port , HLCD_ArrLCDCongf[Copy_enuLCDNum].RW_Pin, MDIO_enuLOW);
	/*2-rs-> low for data*/
	MDIO_enuSetPinValue(HLCD_ArrLCDCongf[Copy_enuLCDNum].RS_Port , HLCD_ArrLCDCongf[Copy_enuLCDNum].RS_Pin, MDIO_enuHIGH);
	 if(HLCD_ArrLCDCongf[Copy_enuLCDNum].DL == HLCD_enu_8Bits)
	 {
	/*3-send data*/
	MDIO_enuSetPinValue(HLCD_ArrLCDCongf[Copy_enuLCDNum].D0_Port , HLCD_ArrLCDCongf[Copy_enuLCDNum].D0_Pin,(Copy_u8Data >> 0) & 0x01 );
	MDIO_enuSetPinValue(HLCD_ArrLCDCongf[Copy_enuLCDNum].D1_Port , HLCD_ArrLCDCongf[Copy_enuLCDNum].D1_Pin,(Copy_u8Data >> 1) & 0x01 );
	MDIO_enuSetPinValue(HLCD_ArrLCDCongf[Copy_enuLCDNum].D2_Port , HLCD_ArrLCDCongf[Copy_enuLCDNum].D2_Pin,(Copy_u8Data >> 2) & 0x01 );
	MDIO_enuSetPinValue(HLCD_ArrLCDCongf[Copy_enuLCDNum].D3_Port , HLCD_ArrLCDCongf[Copy_enuLCDNum].D3_Pin,(Copy_u8Data >> 3) & 0x01 );
	MDIO_enuSetPinValue(HLCD_ArrLCDCongf[Copy_enuLCDNum].D4_Port , HLCD_ArrLCDCongf[Copy_enuLCDNum].D4_Pin,(Copy_u8Data >> 4) & 0x01 );
	MDIO_enuSetPinValue(HLCD_ArrLCDCongf[Copy_enuLCDNum].D5_Port , HLCD_ArrLCDCongf[Copy_enuLCDNum].D5_Pin,(Copy_u8Data >> 5) & 0x01 );
	MDIO_enuSetPinValue(HLCD_ArrLCDCongf[Copy_enuLCDNum].D6_Port , HLCD_ArrLCDCongf[Copy_enuLCDNum].D6_Pin,(Copy_u8Data >> 6) & 0x01 );
	MDIO_enuSetPinValue(HLCD_ArrLCDCongf[Copy_enuLCDNum].D7_Port , HLCD_ArrLCDCongf[Copy_enuLCDNum].D7_Pin,(Copy_u8Data >> 7) & 0x01 );
	 }
	 else if(HLCD_ArrLCDCongf[Copy_enuLCDNum].DL == HLCD_enu_4Bits)
	 {
		/*3-send command*/
		
		/* 1. Send the higher nibble (bits 7-4) */
		MDIO_enuSetPinValue(HLCD_ArrLCDCongf[Copy_enuLCDNum].D4_Port , HLCD_ArrLCDCongf[Copy_enuLCDNum].D4_Pin, (Copy_u8Data >> 4) & 0x01);
		MDIO_enuSetPinValue(HLCD_ArrLCDCongf[Copy_enuLCDNum].D5_Port , HLCD_ArrLCDCongf[Copy_enuLCDNum].D5_Pin, (Copy_u8Data >> 5) & 0x01);
		MDIO_enuSetPinValue(HLCD_ArrLCDCongf[Copy_enuLCDNum].D6_Port , HLCD_ArrLCDCongf[Copy_enuLCDNum].D6_Pin, (Copy_u8Data >> 6) & 0x01);
		MDIO_enuSetPinValue(HLCD_ArrLCDCongf[Copy_enuLCDNum].D7_Port , HLCD_ArrLCDCongf[Copy_enuLCDNum].D7_Pin, (Copy_u8Data >> 7) & 0x01);

		/* 2. Enable pulse (to latch the higher nibble) */
		MDIO_enuSetPinValue(HLCD_ArrLCDCongf[Copy_enuLCDNum].E_Port , HLCD_ArrLCDCongf[Copy_enuLCDNum].E_Pin, MDIO_enuHIGH);
		_delay_us(1);
		MDIO_enuSetPinValue(HLCD_ArrLCDCongf[Copy_enuLCDNum].E_Port , HLCD_ArrLCDCongf[Copy_enuLCDNum].E_Pin, MDIO_enuLOW);
		_delay_us(1);

		/* 3. Send the lower nibble (bits 3-0) */
		MDIO_enuSetPinValue(HLCD_ArrLCDCongf[Copy_enuLCDNum].D4_Port , HLCD_ArrLCDCongf[Copy_enuLCDNum].D4_Pin, (Copy_u8Data >> 0) & 0x01);
		MDIO_enuSetPinValue(HLCD_ArrLCDCongf[Copy_enuLCDNum].D5_Port , HLCD_ArrLCDCongf[Copy_enuLCDNum].D5_Pin, (Copy_u8Data >> 1) & 0x01);
		MDIO_enuSetPinValue(HLCD_ArrLCDCongf[Copy_enuLCDNum].D6_Port , HLCD_ArrLCDCongf[Copy_enuLCDNum].D6_Pin, (Copy_u8Data >> 2) & 0x01);
		MDIO_enuSetPinValue(HLCD_ArrLCDCongf[Copy_enuLCDNum].D7_Port , HLCD_ArrLCDCongf[Copy_enuLCDNum].D7_Pin, (Copy_u8Data >> 3) & 0x01);
	 }
	/*4-enable */
	MDIO_enuSetPinValue(HLCD_ArrLCDCongf[Copy_enuLCDNum].E_Port , HLCD_ArrLCDCongf[Copy_enuLCDNum].E_Pin, MDIO_enuHIGH);
	_delay_us(1);
	MDIO_enuSetPinValue(HLCD_ArrLCDCongf[Copy_enuLCDNum].E_Port , HLCD_ArrLCDCongf[Copy_enuLCDNum].E_Pin, MDIO_enuLOW);
	_delay_us(1);
	}
return Ret_enuError ;
	
}

HLCD_enuErrorStatus_t HLCD_enuLCD_GotoXY(u8 Copy_enuLCDNum,u8 Copy_u8X , u8 Copy_u8Y )
{
	HLCD_enuErrorStatus_t Ret_enuError = HLCD_enuNOK;
	if(IS_INVALID_LCD_NAME(Copy_enuLCDNum))
	{
		Ret_enuError =HLCD_enuINVALIDLCDNAME ; 
		
	}
	else if(IS_INVALID_LCD_Y(Copy_u8Y))
	{
		Ret_enuError =HLCD_enuINVALIDLCDY;
		
	}
	else if(IS_INVALID_LCD_X(Copy_u8X))
	{
		Ret_enuError =HLCD_enuINVALIDLCDX;
	}
	else
	{
	 Ret_enuError = HLCD_enuOK;
	 u8 location=0;
	 _delay_ms(2);
	 if(Copy_u8X == 0)
	 {
		 location=Copy_u8Y;
	 }
	 else
	 {
		 location=Copy_u8Y + 0x40; //the second row
	 }
	 HLCD_enuLCD_WriteCommand(Copy_enuLCDNum , 128+location); /*1xxxxxxx*/
  
	}
    return Ret_enuError ;
	
}

HLCD_enuErrorStatus_t HLCD_enuLCD_GotoXY_CGRAM(u8 Copy_enuLCDNum, u8 Copy_u8BlockNumber , u8 Copy_u8bit )
{
	HLCD_enuErrorStatus_t Ret_enuError = HLCD_enuNOK;

	if (IS_INVALID_LCD_NAME(Copy_enuLCDNum))
	{
		Ret_enuError = HLCD_enuINVALIDLCDNAME;
	}
	else if (IS_INVALID_LCD_BLOCK(Copy_u8BlockNumber))
	{
		Ret_enuError = HLCD_enuINVALIDBLOCK;
	}
	else if(IS_INVALID_LCD_BLOCK_BIT(Copy_u8bit))
	{
		Ret_enuError = HLCD_enuINVALIDBLOCK_BIT;
	}
	else
	{
		u8 location = 0;
		Ret_enuError = HLCD_enuOK;

		// Calculate CGRAM address
		location = Copy_u8BlockNumber * 8 + Copy_u8bit;

		// Write the CGRAM address command
		HLCD_enuLCD_WriteCommand(Copy_enuLCDNum, 64 + location); /* 01xxxxxx */

		// Add delay for the command to process
		_delay_us(40);
	}

	return Ret_enuError;
}


HLCD_enuErrorStatus_t HLCD_enuLCD_StoreSpecialChar(u8 Copy_enuLCDNum, u8 Copy_u8BlockNumber, u8* pattern)
{
	HLCD_enuErrorStatus_t Ret_enuError = HLCD_enuNOK;

	if (IS_INVALID_LCD_NAME(Copy_enuLCDNum))
	{
		Ret_enuError = HLCD_enuINVALIDLCDNAME;
	}
	else if (IS_INVALID_LCD_BLOCK(Copy_u8BlockNumber))
	{
		Ret_enuError = HLCD_enuINVALIDBLOCK;
	}
	else if (IS_INVALID_LCD_PATTERN(pattern))
	{
		Ret_enuError = HLCD_enuINVALIDPTR;
	}
	else
	{
		Ret_enuError = HLCD_enuOK;


		// Write the pattern to CGRAM
		for (u8 i = 0; i < 8; i++)
		{
		    // Move to CGRAM location
		    HLCD_enuLCD_GotoXY_CGRAM(Copy_enuLCDNum, Copy_u8BlockNumber , i );
			HLCD_enuLCD_WriteCharacter(Copy_enuLCDNum, pattern[i]);
		}
	}

	return Ret_enuError;
}

HLCD_enuErrorStatus_t HLCD_enuLCD_WriteSpecialChar(u8 Copy_enuLCDNum , u8 Copy_u8BlockNumber , u8* pattern ,u8 Copy_u8X , u8 Copy_u8Y)
{
			HLCD_enuErrorStatus_t Ret_enuError = HLCD_enuNOK;
			if(IS_INVALID_LCD_NAME(Copy_enuLCDNum))
			{
				Ret_enuError =HLCD_enuINVALIDLCDNAME;
				
			}
			else if(IS_INVALID_LCD_BLOCK(Copy_u8BlockNumber))
			{
				Ret_enuError =HLCD_enuINVALIDBLOCK;
			}
			else if(IS_INVALID_LCD_PATTERN(pattern))
			{
				Ret_enuError =HLCD_enuINVALIDPTR;
			}
	        else if(IS_INVALID_LCD_Y(Copy_u8Y))
	        {
		        Ret_enuError =HLCD_enuINVALIDLCDY;
		
	        }
	        else if(IS_INVALID_LCD_X(Copy_u8X))
	        {
		       Ret_enuError =HLCD_enuINVALIDLCDX;
	        }
			else
			{
				Ret_enuError = HLCD_enuOK;
	            HLCD_enuLCD_StoreSpecialChar(Copy_enuLCDNum ,Copy_u8BlockNumber , pattern );
	            HLCD_enuLCD_GotoXY(Copy_enuLCDNum , Copy_u8X , Copy_u8Y);
	            HLCD_enuLCD_WriteCharacter(Copy_enuLCDNum , Copy_u8BlockNumber );
				
			}
			return Ret_enuError ;
}
HLCD_enuErrorStatus_t HLCD_enuLCD_WriteString(u8 Copy_enuLCDNum , u8* string)
{
			HLCD_enuErrorStatus_t Ret_enuError = HLCD_enuNOK;
			if(IS_INVALID_LCD_NAME(Copy_enuLCDNum))
			{
				Ret_enuError =HLCD_enuINVALIDLCDNAME;
				
			}
			else if(IS_INVALID_LCD_PATTERN(string))
			{
				Ret_enuError =HLCD_enuINVALIDPTR;
			}
			else
			{
				Ret_enuError = HLCD_enuOK;
	            while(*string != '\0' ) // \0 is the last element in the array
	            {
		          HLCD_enuLCD_WriteCharacter(Copy_enuLCDNum,*string);
		          string++;

	            }
			}
			return Ret_enuError ;


}


HLCD_enuErrorStatus_t HLCD_enuLCD_WriteNumber(u8 Copy_enuLCDNum ,u32 Copy_U32Number)
{
	
	HLCD_enuErrorStatus_t Ret_enuError = HLCD_enuNOK;
	if(IS_INVALID_LCD_NAME(Copy_enuLCDNum))
	{
		Ret_enuError =HLCD_enuINVALIDLCDNAME;
		
	}
	else
	{
	Ret_enuError = HLCD_enuOK;
	 // Handle special case for 0
	 if (Copy_U32Number == 0)
	 {
		 HLCD_enuLCD_WriteCharacter(Copy_enuLCDNum,'0');
		 
	 }
	 else
	 {
	u8 digits[10];  // Array to hold the digits (u32 has at most 10 digits)
	u8 count = 0;   // Counter for the number of digits
	// Extract digits and store them in the array
	 while (Copy_U32Number != 0)
	 {
		 digits[count++] = Copy_U32Number % 10;  // Store the last digit
		 Copy_U32Number /= 10;                   // Remove the last digit
	 }
	 if(count > 10)
	 {
		 Ret_enuError =HLCD_enuINVALIDNUMBER;
		 
	 }
	 else
	 {
	 // Print the digits in reverse order (from the array)
	 while (count > 0)
	 {
		 HLCD_enuLCD_WriteCharacter(Copy_enuLCDNum , digits[--count] + '0');  // Convert digit to ASCII and print
	 }
	 }
		 
	 }

	}
 return Ret_enuError ;
	
}