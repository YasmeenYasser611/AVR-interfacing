/*
 * HDCMOTOR.c
 *
 * Created: 2/17/2025 2:03:01 PM
 *  Author: TUF
 */ 
#include "MPORT.h"
#include "MDIO.h"
#include "HDCMOTOR.h"
#include "HDCMOTOR_Confg.h"

extern HMOTOR_strMotorConfig_t HMOTOR_enuArrMotorConfig[Num_of_Motors];

void HMOTOR_vMotor_init(void)
{
	u8 i;
	for (i = 0; i < Num_of_Motors; i++)
	{
		// Set motor pins as output
		MPORT_enuSetPinDirection((HMOTOR_enuArrMotorConfig[i].PORT_A << 4) + HMOTOR_enuArrMotorConfig[i].PIN_A, MPORT_enuPINOUTPUT);
		MPORT_enuSetPinDirection((HMOTOR_enuArrMotorConfig[i].PORT_B << 4) + HMOTOR_enuArrMotorConfig[i].PIN_B, MPORT_enuPINOUTPUT);
	}
}

HMOTOR_enuState_t HMOTOR_enuSetMotorState(u8 Copy_u8MotorName, HMOTOR_enuState_t Copy_enuState)
{
	if (Copy_u8MotorName >= Num_of_Motors)
	return HMOTOR_enuSTOP; // Invalid motor name

	switch (Copy_enuState)
	{
		case HMOTOR_enuFORWARD:
		MDIO_enuSetPinValue(HMOTOR_enuArrMotorConfig[Copy_u8MotorName].PORT_A, HMOTOR_enuArrMotorConfig[Copy_u8MotorName].PIN_A, MDIO_enuHIGH);
		MDIO_enuSetPinValue(HMOTOR_enuArrMotorConfig[Copy_u8MotorName].PORT_B, HMOTOR_enuArrMotorConfig[Copy_u8MotorName].PIN_B, MDIO_enuLOW);
		break;
		
		case HMOTOR_enuREVERSE:
		MDIO_enuSetPinValue(HMOTOR_enuArrMotorConfig[Copy_u8MotorName].PORT_A, HMOTOR_enuArrMotorConfig[Copy_u8MotorName].PIN_A, MDIO_enuLOW);
		MDIO_enuSetPinValue(HMOTOR_enuArrMotorConfig[Copy_u8MotorName].PORT_B, HMOTOR_enuArrMotorConfig[Copy_u8MotorName].PIN_B, MDIO_enuHIGH);
		break;

		case HMOTOR_enuSTOP:
		default:
		MDIO_enuSetPinValue(HMOTOR_enuArrMotorConfig[Copy_u8MotorName].PORT_A, HMOTOR_enuArrMotorConfig[Copy_u8MotorName].PIN_A, MDIO_enuLOW);
		MDIO_enuSetPinValue(HMOTOR_enuArrMotorConfig[Copy_u8MotorName].PORT_B, HMOTOR_enuArrMotorConfig[Copy_u8MotorName].PIN_B, MDIO_enuLOW);
		break;
	}
	
	return Copy_enuState;
}
