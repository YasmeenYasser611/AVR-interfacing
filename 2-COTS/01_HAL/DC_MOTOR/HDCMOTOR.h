/*
 * HDCMOTOR.h
 *
 * Created: 2/17/2025 2:03:42 PM
 *  Author: TUF
 */ 


#ifndef HDCMOTOR_H_
#define HDCMOTOR_H_


#include "HDCMOTOR_Confg.h"
#include "STD_TYPES.h"

void HMOTOR_vMotor_init(void);
HMOTOR_enuState_t HMOTOR_enuSetMotorState(u8 Copy_u8MotorName, HMOTOR_enuState_t Copy_enuState);



#endif /* HDCMOTOR_H_ */