/*
 * HStepper_config.h
 *
 * Created: 2/17/2025 3:15:48 PM
 *  Author: TUF
 */ 
#ifndef HSTEPPER_CONFIG_H_
#define HSTEPPER_CONFIG_H_

#define Num_of_Stepper 1 // Define the number of stepper motors
#define Stepper1 0
#define HSTEPPER_PHASES 4  // Stepper motor has 4 control phases

typedef struct
{
	struct
	{
		u8 STEPPER_PORT;
		u8 STEPPER_PIN;
	} Phases[HSTEPPER_PHASES];

} HSTEPPER_strStepperElement_t;

extern HSTEPPER_strStepperElement_t HSTEPPER_enuArrStepperConfig[Num_of_Stepper];

#endif /* HSTEPPER_CONFIG_H_ */
