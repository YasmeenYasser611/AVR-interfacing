/*
 * traffic_light.c
 *
 * Created: 1/28/2025 8:37:14 AM
 * Author : TUF
 */ 

#include "HSEVENSEG.h"
#include "HSWITCH.h"
#define F_CPU 8000000UL
#include <util/delay.h>
#include "STD_TYPES.h"
int main(void)
{
	HSEVENSEG_vInit();
	HSWITCH_vSWITCH_init();
	u8 counter = 0;      // Counter value to display
	u8 direction = 5;    
	u8 sw1_state = 1;    // Store state of SWITCH1
	u8 sw2_state = 0;    // Store state of SWITCH2

	while (1)
	{
		// Check the state of SWITCH1 (pull-up button for count up)
		if (HSWITCH_enuGetSwitchState(SWITCH1, &sw1_state) == 0 && sw1_state == 0)
		{
			direction = 0; // Set direction to counting up
		}

		// Check the state of SWITCH2 (pull-down button for count down)
		if (HSWITCH_enuGetSwitchState(SWITCH2, &sw2_state) == 0 && sw2_state == 1)
		{
			direction = 1; // Set direction to counting down
		}
		if(direction == 1 ||direction == 0 )
		{
			
			// Update the seven-segment display based on the direction
			HSEVENSEG_enuSetMultiDigitValue(counter);
			_delay_ms(500);

			if (direction == 0)
			{
				counter++; // Increment counter
				if (counter > 99)
				counter = 0; // Reset to 0 after reaching 99
			}
			else
			{
				if (counter == 0)
				counter = 99; // Reset to 99 after reaching 0
				else
				counter--; // Decrement counter
			}
			
			
		}

	}
}
