/*
 * Stepper_Motor_Driver.c
 *
 * Created: 2/17/2025 3:08:25 PM
 * Author : TUF
 */ 

#include "HSTEPPER.h"
#include "util/delay.h"
#define F_CPU (8000000UL)

int main(void)
{
	
	HSTEPPER_vStepper_init(); // Initialize stepper motors


	while (1)
	{
		// Rotate Stepper Motor 0 Clockwise by 90 degrees
		HSTEPPER_enuRotate(Stepper1, HSTEPPER_enuCLOCKWISE, 180);
		_delay_ms(2000); // Wait for 1 second

		// Rotate Stepper Motor 0 Counterclockwise by 90 degrees
		HSTEPPER_enuRotate(Stepper1, HSTEPPER_enuCOUNTERCLOCKWISE, 90);
		_delay_ms(2000); // Wait for 1 second

		// Stop the motor
		HSTEPPER_enuStop(Stepper1);
		_delay_ms(2000); // Wait for 2 seconds before repeating
	}
}
