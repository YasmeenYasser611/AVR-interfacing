/*
 * DC_Motor.c
 *
 * Created: 2/17/2025 2:02:27 PM
 * Author : TUF
 */ 


#include "HSWITCH.h"
#include "HDCMOTOR.h"
#include "STD_TYPES.h"
int main(void)
{
	HSWITCH_vSWITCH_init();
	HMOTOR_vMotor_init();  
	
	u8 state1, state2;
	
	while (1)
	{
		HSWITCH_enuGetSwitchState(SWITCH1, &state1);
		HSWITCH_enuGetSwitchState(SWITCH2, &state2);
		
		if (state1 == 0) 
		{
			HMOTOR_enuSetMotorState(Motor1, HMOTOR_enuFORWARD);
		}
	    if (state2 == 0) 
		{
			HMOTOR_enuSetMotorState(Motor1, HMOTOR_enuREVERSE);
		}
		/*else 
		{
			HMOTOR_enuSetMotorState(Motor1, HMOTOR_enuSTOP);
		}*/
	}
}

