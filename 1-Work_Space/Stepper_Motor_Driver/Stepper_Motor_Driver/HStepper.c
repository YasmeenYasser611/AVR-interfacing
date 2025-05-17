/*
 * HStepper.c
 *
 * Created: 2/17/2025 3:10:10 PM
 *  Author: TUF
 */ 
#include "HSTEPPER.h"
#include "HStepper_config.h"
#include "MDIO.h"
#include "MPORT.h"
#include "STD_TYPES.h"
#define F_CPU (8000000UL)
#include <util/delay.h>

#define STEP_ANGLE 0.17578f  // 2048 steps for a full rotation (360/2048)

extern HSTEPPER_strStepperElement_t HSTEPPER_enuArrStepperConfig[Num_of_Stepper];

void HSTEPPER_vStepper_init(void)
{
	u8 Local_u8_currentPinPort = 0;
	for (u8 i = 0; i < Num_of_Stepper; i++)
	{
		for (u8 phase = 0; phase < HSTEPPER_PHASES; phase++)
		{
			Local_u8_currentPinPort = ((HSTEPPER_enuArrStepperConfig[i].Phases[phase].STEPPER_PORT << 4) +HSTEPPER_enuArrStepperConfig[i].Phases[phase].STEPPER_PIN);
			MPORT_enuSetPinDirection(Local_u8_currentPinPort, MPORT_enuPINOUTPUT);
			MDIO_enuSetPinValue(HSTEPPER_enuArrStepperConfig[i].Phases[phase].STEPPER_PORT , HSTEPPER_enuArrStepperConfig[i].Phases[phase].STEPPER_PIN , MDIO_enuHIGH );
		}
	}
}

HSTEPPER_enuErrorStatus_t HSTEPPER_enuRotate(u8 Copy_u8MotorName, HSTEPPER_enuDirection_t Copy_enuDirection, u16 Copy_u16Angle)
{
	HSTEPPER_enuErrorStatus_t Ret_enuError = HSTEPPER_enuOK;

	if (Copy_u8MotorName >= Num_of_Stepper)
	{
		Ret_enuError = HSTEPPER_enuINVALID_Motor; 
	}
	else if (Copy_enuDirection > HSTEPPER_enuCOUNTERCLOCKWISE)
	{
		Ret_enuError = HSTEPPER_enuINVALID_Direction;
	}
	else
	{
		u32 steps = (u32)((f32)Copy_u16Angle / STEP_ANGLE);

		u8 PhaseSequence[2][HSTEPPER_PHASES] = {
			 {0b1110, 0b1101, 0b1011, 0b0111}, // Clockwise
			 {0b0111, 0b1011, 0b0100, 0b1110}  // Counterclockwise
		};
		

		for (u32 step = 0; step < steps / 4; step++)
		{
			for (u8 phase = 0; phase < HSTEPPER_PHASES; phase++)
			{
				for (u8 pin = 0; pin < HSTEPPER_PHASES; pin++)
				{
					MDIO_enuSetPinValue(HSTEPPER_enuArrStepperConfig[Copy_u8MotorName].Phases[pin].STEPPER_PORT,HSTEPPER_enuArrStepperConfig[Copy_u8MotorName].Phases[pin].STEPPER_PIN,(PhaseSequence[Copy_enuDirection][phase] >> pin) & 1);
				}
				_delay_ms(10); 
			}
		}
	}

	return Ret_enuError; 
}

HSTEPPER_enuErrorStatus_t HSTEPPER_enuStop(u8 Copy_u8MotorName)
{
	HSTEPPER_enuErrorStatus_t Ret_enuError = HSTEPPER_enuOK;

	
	if (Copy_u8MotorName >= Num_of_Stepper)
	{
		Ret_enuError = HSTEPPER_enuINVALID_Motor; 
	}
	else
	{
		for (u8 pin = 0; pin < HSTEPPER_PHASES; pin++)
		{
			MDIO_enuSetPinValue(HSTEPPER_enuArrStepperConfig[Copy_u8MotorName].Phases[pin].STEPPER_PORT,HSTEPPER_enuArrStepperConfig[Copy_u8MotorName].Phases[pin].STEPPER_PIN,MDIO_enuHIGH);
		}
	}

	return Ret_enuError; 
}
