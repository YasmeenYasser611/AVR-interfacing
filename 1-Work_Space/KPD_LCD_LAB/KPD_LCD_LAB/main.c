/*
 * KPD_Driver_Build.c
 *
 * Created: 2/4/2025 10:23:56 AM
 * Author : TUF
 */ 

#include "KPD.h"
#include "HLCD.h"
#define F_CPU 8000000UL
#include <util/delay.h>



int main(void)
{
	HKPD_vKPD_init();
	HLCD_vLCD_init();
	
	u8 KPD1_VAL = 100;
	u8 currentRow = 0, currentCol = 0;  // Track the current cursor position on the LCD

	while (1)
	{
		// Get the key from the keypad
		HKPD_enuKPD_GetKey(KPD1, &KPD1_VAL);

		// Only act if a key is pressed
		if (KPD1_VAL != 100)  // Assuming 100 is the default 'no key' value
		{
			switch(KPD1_VAL)
			{
				case '1':  // Clear the display
				HLCD_vLCD_ClearDisplay(LCD1);
				_delay_ms(100);
				break;
				
				case '2':  // Move right (increment column)
				if (currentCol < 15)  // assuming 16 columns max
				{
					currentCol++;
				}
				HLCD_enuLCD_GotoXY(LCD1, currentRow, currentCol);
				_delay_ms(100);
				break;
				
				case '3':  // Move left (decrement column)
				if (currentCol > 0)
				{
					currentCol--;
				}
				HLCD_enuLCD_GotoXY(LCD1, currentRow, currentCol);
				_delay_ms(100);
				break;
				
				case '4':  // Move up (decrement row)
				if (currentRow > 0)
				{
					currentRow--;
				}
				HLCD_enuLCD_GotoXY(LCD1, currentRow, currentCol);
				_delay_ms(100);
				break;
				
				case '5':  // Move down (increment row)
				if (currentRow < 1)  // assuming 2 rows max
				{
					currentRow++;
				}
				HLCD_enuLCD_GotoXY(LCD1, currentRow, currentCol);
				_delay_ms(100);
				break;
				
				case '6':  // display my name 
				HLCD_vLCD_ClearDisplay(LCD1);
				HLCD_enuLCD_GotoXY(LCD1, 0, 0);
				HLCD_enuLCD_WriteString(LCD1, "Yasmeen");
				_delay_ms(100);
				break;

				default:
				HLCD_vLCD_ClearDisplay(LCD1);
				HLCD_enuLCD_GotoXY(LCD1, 0, 0);
				HLCD_enuLCD_WriteString(LCD1, "WRONG!!!!");
				_delay_ms(100);
				break;
			}
			KPD1_VAL = 100;
		}
	}
}
