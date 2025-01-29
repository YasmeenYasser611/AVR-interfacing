/*
 * SEVENSEG_DRIVER_BUILD.c
 *
 * Created: 1/5/2025 11:12:07 AM
 * Author : yasmeen
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
	
		
		for(u8 i =0 ; i< 10 ; i++)
		{
			HSEVENSEG_vSetValue(SEVENSEG1 , i);
			HSEVENSEG_vSetValue(SEVENSEG2 , i);
			_delay_ms(1000);
		}
		HSEVENSEG_enuSetMultiDigitValue(56) ;
		_delay_ms(1000);
		
    }
}

