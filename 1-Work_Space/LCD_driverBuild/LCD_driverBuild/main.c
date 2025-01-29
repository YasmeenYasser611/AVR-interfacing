/*
 * LCD_driverBuild.c
 *
 * Created: 1/28/2025 1:20:40 PM
 * Author : TUF
 */ 

#include "HLCD.h"
#define F_CPU 8000000UL
#include <util/delay.h>


int main(void)
{
    HLCD_vLCD_init();
	u8 customChar[] = {
		0x0E,
		0x0A,
		0x0E,
		0x04,
		0x0E,
		0x04,
		0x0E,
		0x00
	};
    while (1) 
    {
		HLCD_enuLCD_WriteCharacter(LCD1 , 'Y');
		HLCD_enuLCD_WriteCharacter(LCD2 , 'Y');
		_delay_ms(1000);
		HLCD_enuLCD_WriteNumber(LCD1 ,666);
		HLCD_enuLCD_WriteNumber(LCD2 ,666);
		_delay_ms(1000);
		HLCD_enuLCD_WriteString(LCD1 , "you");
		HLCD_enuLCD_WriteString(LCD2 , "you");
		_delay_ms(1000);
		HLCD_enuLCD_WriteCharacter(LCD1 , 'Y');
		HLCD_enuLCD_WriteCharacter(LCD2 , 'Y');
		_delay_ms(1000);
		HLCD_enuLCD_WriteCharacter(LCD1 , 'A');
		HLCD_enuLCD_WriteCharacter(LCD2 , 'A');
		_delay_ms(1000);
		
		HLCD_enuLCD_WriteSpecialChar(LCD1 , 0 , customChar , 1 , 2);
		HLCD_enuLCD_WriteSpecialChar(LCD2 , 0 , customChar , 1 , 2);
		_delay_ms(1000);
		HLCD_vLCD_ClearDisplay(LCD1);
		HLCD_vLCD_ClearDisplay(LCD2);
		_delay_ms(1000);
		HLCD_enuLCD_GotoXY(LCD1 , 0 , 3);
		HLCD_enuLCD_GotoXY(LCD2 , 0 , 3);
    }
}

