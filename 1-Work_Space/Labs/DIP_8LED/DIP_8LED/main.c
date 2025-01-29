/*
 * DIP_8LED.c
 *
 * Created: 1/28/2025 7:46:52 AM
 * Author : TUF
 */ 

#include "HLED.h"
#include "HSWITCH.h"
#define F_CPU 8000000UL
#include <util/delay.h>
#include "STD_TYPES.h"
int main(void)
{
	HLED_vLED_init();         // Initialize the LEDs
	HSWITCH_vSWITCH_init();   // Initialize the DIP switches
	u8 state = 0;             // Variable to store the state of the DIP switch

	while (1)
	{
		for (u8 i = 0; i < Num_of_SWITCH; i++) // Iterate through each DIP switch
		{
			// Check if the current DIP switch is ON
			if (HSWITCH_enuGetSwitchState(i, &state) == 0 && state == 0)
			{
				// Flash the corresponding LED
				HLED_enuSetLedState(i, HLED_enuON);
				_delay_ms(500);
				HLED_enuSetLedState(i, HLED_enuOFF);
				_delay_ms(500);
			}
			else
			{
				// Ensure the LED is OFF if the DIP switch is OFF
				HLED_enuSetLedState(i, HLED_enuOFF);
			}
		}
	}
}
