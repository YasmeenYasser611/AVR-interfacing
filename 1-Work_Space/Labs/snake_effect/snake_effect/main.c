/*
 * snake_effect.c
 *
 * Created: 1/28/2025 7:15:07 AM
 * Author : TUF
 */ 

#include "HLED.h"
#define F_CPU 8000000UL
#include <util/delay.h>
#include "STD_TYPES.h"

int main(void)
{
    
	HLED_vLED_init();
    while (1) 
    {
		for(u8 i =0 ; i<Num_of_Led ; i++)
		{
			HLED_enuSetLedState(i , HLED_enuON);
			_delay_ms(1000);
			HLED_enuSetLedState(i , HLED_enuOFF);
		}
		
    }
}

