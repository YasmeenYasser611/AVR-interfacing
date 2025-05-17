/*
 * HStepper_config.c
 *
 * Created: 2/17/2025 3:16:41 PM
 *  Author: TUF
 */ 
#include "HSTEPPER.h"
#include "HSTEPPER_config.h"
#include "MPORT.h"
#include "MDIO.h"
#include "util/delay.h"

HSTEPPER_strStepperElement_t HSTEPPER_enuArrStepperConfig[Num_of_Stepper] = {
	[Stepper1] = {  // Stepper Motor 1
		.Phases = {
			{.STEPPER_PORT = MPORT_enuPORTC, .STEPPER_PIN = MPORT_enuPIN0},
			{.STEPPER_PORT = MPORT_enuPORTC, .STEPPER_PIN = MPORT_enuPIN1},
			{.STEPPER_PORT = MPORT_enuPORTC, .STEPPER_PIN = MPORT_enuPIN2},
			{.STEPPER_PORT = MPORT_enuPORTC, .STEPPER_PIN = MPORT_enuPIN3},
		}
	}
	
};
