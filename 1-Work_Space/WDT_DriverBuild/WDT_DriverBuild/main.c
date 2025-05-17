/*
 * Timer0_DriverBuild.c
 *
 * Created: 3/3/2025 7:55:53 PM
 * Author : TUF
 */ 


#include "WDT.h"
#include "HLED.h"
#include "avr/delay.h"

int main(void)
{
	HLED_vLED_init();
	
	HLED_enuSetLedState(Led_start , HLED_enuON);
	
	_delay_ms(1000);
	HLED_enuSetLedState(Led_start , HLED_enuOFF);

	WDG_Sleep(WDT_TIMEOUT_2S);
	WDG_TurnON(); //without turn off so the led will on again 

	WDG_TurnOff(); //the led will not on again no rest will happen

   while (1);
 }

