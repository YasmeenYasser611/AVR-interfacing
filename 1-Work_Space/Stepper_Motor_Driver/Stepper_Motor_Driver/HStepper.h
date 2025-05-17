/*
 * HStepper.h
 *
 * Created: 2/17/2025 3:11:54 PM
 *  Author: TUF
 */ 

#ifndef HSTEPPER_H_
#define HSTEPPER_H_

#include "STD_TYPES.h"
#include "HStepper_config.h"

typedef enum
{
	HSTEPPER_enuCLOCKWISE = 0,
	HSTEPPER_enuCOUNTERCLOCKWISE
} HSTEPPER_enuDirection_t;

typedef enum
{
	HSTEPPER_enuOK = 0,
	HSTEPPER_enuNOK,
	HSTEPPER_enuINVALID_Motor,
	HSTEPPER_enuINVALID_Direction
} HSTEPPER_enuErrorStatus_t;

void HSTEPPER_vStepper_init(void);
HSTEPPER_enuErrorStatus_t HSTEPPER_enuRotate(u8 Copy_u8MotorName, HSTEPPER_enuDirection_t Copy_enuDirection, u16 Copy_u16Angle);
HSTEPPER_enuErrorStatus_t HSTEPPER_enuStop(u8 Copy_u8MotorName);

#endif /* HSTEPPER_H_ */
