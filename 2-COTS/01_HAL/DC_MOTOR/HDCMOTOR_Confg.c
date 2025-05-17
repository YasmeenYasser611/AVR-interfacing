/*
 * HDCMOTOR_Confg.c
 *
 * Created: 2/17/2025 2:03:21 PM
 *  Author: TUF
 */ 
#include "HDCMOTOR_Confg.h"

HMOTOR_strMotorConfig_t HMOTOR_enuArrMotorConfig[Num_of_Motors] =
{
	[Motor1] = {
		.PORT_A = HMOTOR_enuPORTA,
		.PIN_A = HMOTOR_enuPIN0,
		.PORT_B = HMOTOR_enuPORTA,
		.PIN_B = HMOTOR_enuPIN1
	}
};
