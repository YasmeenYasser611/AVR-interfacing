/*
 * HLCD_config.c
 *
 * Created: 1/28/2025 1:24:57 PM
 *  Author: TUF
 */ 

#include "HLCD_congih.h"

HLCD_strLCDCONFG_8BIT_t HLCD_ArrLCDCongf[Num_of_LCD] =
{
	
	[LCD1] = {
		.DL = HLCD_enu_4Bits,
		.N = HLCD_enu_2Lines,
		.F = HLCD_enu_5x8,
		.D = HLCD_enu_LCD_on,
		.C =HLCD_enu_Cursor_on ,
		.B=HLCD_enu_Blink_on ,
		.I_D =HLCD_enu_INC ,
		.S=HLCD_enu_NoShift ,
		.D4_Port=HLCD_enuPORTC,
		.D4_Pin=HLCD_enuPIN4,
		.D5_Port=HLCD_enuPORTC,
		.D5_Pin=HLCD_enuPIN5,
		.D6_Port=HLCD_enuPORTC,
		.D6_Pin=HLCD_enuPIN6,
		.D7_Port=HLCD_enuPORTC,
		.D7_Pin=HLCD_enuPIN7,
		.RS_Port=HLCD_enuPORTB ,
		.RS_Pin=HLCD_enuPIN4,
		.RW_Port=HLCD_enuPORTB ,
		.RW_Pin=HLCD_enuPIN5,
		.E_Port=HLCD_enuPORTB,
		.E_Pin=HLCD_enuPIN6
	}
	
};