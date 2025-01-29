/*
 * HLCD_congih.h
 *
 * Created: 1/28/2025 1:25:15 PM
 *  Author: TUF
 */ 


#ifndef HLCD_CONGIH_H_
#define HLCD_CONGIH_H_

#include "STD_TYPES.h"

typedef enum
{
	HLCD_enuPORTA = 0,
	HLCD_enuPORTB,
	HLCD_enuPORTC,
	HLCD_enuPORTD
}HLCD_enuPortNum_t;


typedef enum
{
	HLCD_enuPIN0 = 0,
	HLCD_enuPIN1,
	HLCD_enuPIN2,
	HLCD_enuPIN3,
	HLCD_enuPIN4,
	HLCD_enuPIN5,
	HLCD_enuPIN6,
	HLCD_enuPIN7
}HLCD_enuPinNum_t;

typedef enum
{
	HLCD_enu_4Bits = 0,
	HLCD_enu_8Bits
}HLCD_enuDataLength_t;

typedef enum
{
	HLCD_enu_1Line = 0,
	HLCD_enu_2Lines
}HLCD_enuDisplayLines_N_t;

typedef enum
{
	HLCD_enu_5x8 = 0,
	HLCD_enu_5x11
}HLCD_enuCharFont_t;

typedef enum
{
	HLCD_enu_LCD_off = 0,
	HLCD_enu_LCD_on
}HLCD_enuLCD_on_off_t;

typedef enum
{
	HLCD_enu_Cursor_off = 0,
	HLCD_enu_Cursor_on
}HLCD_enuCursor_on_off_t;

typedef enum
{
	HLCD_enu_Blink_off = 0,
	HLCD_enu_Blink_on
}HLCD_enuCursor_blinking_t;

typedef enum
{
	HLCD_enu_DEC = 0,  /*cursor moves to the left*/
	HLCD_enu_INC       /*cursor moves to the right*/
}HLCD_enuCursor_moveDirection_t;


typedef enum
{
	HLCD_enu_NoShift = 0,  
	HLCD_enu_EnableShift       /*like scrolling*/
}HLCD_enuShift_EntireDisplay_t;

typedef struct
{
	HLCD_enuDataLength_t DL;
	HLCD_enuDisplayLines_N_t N;
	HLCD_enuCharFont_t F;
	HLCD_enuLCD_on_off_t D;
	HLCD_enuCursor_on_off_t C ;
	HLCD_enuCursor_blinking_t B;
	HLCD_enuCursor_moveDirection_t I_D ;
	HLCD_enuShift_EntireDisplay_t S;
	u8 D0_Port;
	u8 D0_Pin;
	u8 D1_Port;
	u8 D1_Pin;
	u8 D2_Port;
	u8 D2_Pin;
	u8 D3_Port;
	u8 D3_Pin;
	u8 D4_Port;
	u8 D4_Pin;
	u8 D5_Port;
	u8 D5_Pin;
	u8 D6_Port;
	u8 D6_Pin;
	u8 D7_Port;
	u8 D7_Pin;
	u8 RS_Port;
	u8 RS_Pin;
	u8 RW_Port;
	u8 RW_Pin;
	u8 E_Port;
	u8 E_Pin;
	
	
} HLCD_strLCDCONFG_8BIT_t;



#define Num_of_LCD 2


#define  LCD1 0
#define  LCD2 1



#endif /* HLCD_CONGIH_H_ */