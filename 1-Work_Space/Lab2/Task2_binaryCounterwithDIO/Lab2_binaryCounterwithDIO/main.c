/*
 * Lab2_binaryCounterwithDIO.c
 *
 * Created: 12/18/2024 1:10:30 PM
 * Author : TUF
 */ 

#include "MDIO.h"
#define F_CPU 8000000UL
#include <util/delay.h>
#include "BIT_MATH.h"

int main(void)
{
	// Initialize the PORTA as output for the binary counter
	MDIO_enuErrorStatus_t status1 = MDIO_enuSetPortConfigration(MDIO_enuPORTA, MDIO_enuALL_OUTPUT);
	
	// Initialize PIN7 of PORTC as input with pull-up for the switch
	MDIO_enuErrorStatus_t status2 = MDIO_enuSetPinConfigration(MDIO_enuPORTC, MDIO_enuPIN7, MDIO_enuINPUT_PULLUP);

	u8 counter = 0; // Counter variable to hold binary count
	u8 buttonState = 1; // Variable to store the current button state

	// Display the initial counter value on PORTA
	//MDIO_enuSetPortValue(MDIO_enuPORTA, (MDIO_enuPortState)counter);
    MDIO_enuSetPortValue(MDIO_enuPORTA, MDIO_enuAll_LOW);
	while (1)
	{
		if (status1 == MDIO_enuOK && status2 == MDIO_enuOK)
		{
			// Read the state of the button (PIN7 of PORTC)
			MDIO_enuErrorStatus_t status3 = MDIO_enuGetPinValue(MDIO_enuPORTC, MDIO_enuPIN7, &buttonState);

			if (status3 == MDIO_enuOK && buttonState == 0) // If button is pressed (active low)
			{
				_delay_ms(50); // Debounce delay

				// Check the button state again after the debounce delay
				MDIO_enuGetPinValue(MDIO_enuPORTC, MDIO_enuPIN7, &buttonState);

				if (buttonState == 0) // Confirm the button is still pressed
				{
					counter++; // Increment the counter

					// Display the updated counter value on PORTA
					//MDIO_enuSetPortValue(MDIO_enuPORTA, (MDIO_enuPortState)counter);
					for(int i=0 ; i<8 ; i++)
					{
						MDIO_enuSetPinValue(MDIO_enuPORTA , i , GET_BIT(counter,i));
					}

					// Reset the counter if it reaches 256 (overflow)
					if (counter == 256)
					{
						counter = 0; // Reset counter to 0
						MDIO_enuSetPortValue(MDIO_enuPORTA, MDIO_enuAll_LOW);
					}

					// Wait until the button is released
					do
					{
						MDIO_enuGetPinValue(MDIO_enuPORTC, MDIO_enuPIN7, &buttonState);
					} while (buttonState == 0);

					_delay_ms(50); // Debounce delay after button release
				}
			}
		}
	}
}
