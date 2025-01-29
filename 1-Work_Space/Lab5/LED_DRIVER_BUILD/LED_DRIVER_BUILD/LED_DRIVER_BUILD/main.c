/*
 * LED_DRIVER_BUILD.c
 *
 * Created: 1/2/2025 3:04:28 PM
 * Author : Yasmeen
 */ 


#include "HLED.h"

int main(void)
{
	
	 HLED_vLED_init(); /*initialize led1 , led2*/
    while (1) 
    {
		HLED_enuSetLedState( Led_start, HLED_enuON);
		HLED_enuSetLedState( Led_stop, HLED_enuON);
		
		
    }
}

