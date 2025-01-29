/*
 * SWITCH_DRIVER_BUILD.c
 *
 * Created: 1/2/2025 8:42:48 PM
 * Author : Yasmeen
 */ 



#include "HSWITCH.h"
#include "HLED.h"
#define F_CPU 8000000UL
#include <util/delay.h>


int main(void)
{
	HSWITCH_vSWITCH_init();
	HLED_vLED_init();
	u8 result1 =0 , result2 =0 ;
	while(1)
	{
		HSWITCH_enuGetSwitchState(SWITCH1, &result1);
		HSWITCH_enuGetSwitchState(SWITCH2, &result2);
		if(result1 == 0)
		{
			HLED_enuSetLedState(Led_start , HLED_enuON);
		}
		else
		{
			HLED_enuSetLedState(Led_start , HLED_enuOFF);
		}
		if(result2 == 1)
		{
			HLED_enuSetLedState(Led_stop , HLED_enuON);
		}
		else
		{
			HLED_enuSetLedState(Led_stop , HLED_enuOFF);
		}
		
	}

}

