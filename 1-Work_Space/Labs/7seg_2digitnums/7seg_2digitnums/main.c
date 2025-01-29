/*
 * traffic_light.c
 *
 * Created: 1/28/2025 8:37:14 AM
 * Author : TUF
 */ 

#include "HSEVENSEG.h"
#define F_CPU 8000000UL
#include <util/delay.h>
#include "STD_TYPES.h"

int main(void)
{
	
	HSEVENSEG_vInit();
	
	while (1)
	{
		for (u8 i = 0; i <=99 ; i++) 
		{
			if(i==0)
			{
				HSEVENSEG_vSetValue(SEVENSEG1 , 0);
				_delay_ms(1000);
			}
			else
			{
				
				HSEVENSEG_enuSetMultiDigitValue(i);
				_delay_ms(1000);
			}
		}
		
		
	}
}
