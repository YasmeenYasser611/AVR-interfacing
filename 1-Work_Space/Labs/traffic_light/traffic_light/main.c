/*
 * traffic_light.c
 *
 * Created: 1/28/2025 8:37:14 AM
 * Author : TUF
 */ 

#include "HLED.h"
#include "HSEVENSEG.h"
#define F_CPU 8000000UL
#include <util/delay.h>
#include "STD_TYPES.h"
int main(void)
{
	HLED_vLED_init();
	HSEVENSEG_vInit();
	
	while (1)
	{
		HLED_enuSetLedState(Led_1, HLED_enuON);
		for (s8 i = 10; i >= 0; i--)  // Use signed integer here
		{
			HSEVENSEG_enuSetMultiDigitValue(i);
			_delay_ms(1000);
		}
		HSEVENSEG_vSetValue(SEVENSEG1 , 0);
		HSEVENSEG_vSetValue(SEVENSEG2 , 0);
		HLED_enuSetLedState(Led_1, HLED_enuOFF);
        _delay_ms(1000);
		HLED_enuSetLedState(Led_2, HLED_enuON);
		for (s8 i = 3; i >= 0; i--)  // Use signed integer here
		{
			HSEVENSEG_enuSetMultiDigitValue(i);
			_delay_ms(1000);
		}
		HSEVENSEG_vSetValue(SEVENSEG1 , 0);
		HSEVENSEG_vSetValue(SEVENSEG2 , 0);
		HLED_enuSetLedState(Led_2, HLED_enuOFF);
        _delay_ms(1000);
		HLED_enuSetLedState(Led_3, HLED_enuON);
		for (s8 i = 10; i >= 0; i--)  // Use signed integer here
		{
			HSEVENSEG_enuSetMultiDigitValue(i);
			_delay_ms(1000);
		}
		HSEVENSEG_vSetValue(SEVENSEG1 , 0);
		HSEVENSEG_vSetValue(SEVENSEG2 , 0);
		HLED_enuSetLedState(Led_3, HLED_enuOFF);
		_delay_ms(1000);
	}
}
