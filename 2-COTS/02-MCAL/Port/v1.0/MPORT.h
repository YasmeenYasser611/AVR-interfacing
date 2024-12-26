/*
 * MPORT.h
 *
 * Created: 12/25/2024 1:55:01 PM
 *  Author: TUF
 */ 


#ifndef MPORT_H_
#define MPORT_H_


#include "STD_TYPES.h"
#include "MPORT_PRIVATE.h"



void MDIO_vPortInit(void);

MPORT_enuErrorStatus_t MPORT_enuSetPinDirection( u8 Copy_enuPinNum  ,  u8  Copy_enuPinDirection  );

MPORT_enuErrorStatus_t MPORT_enuSetPinMode( u8 Copy_enuPinNum  ,  MPORT_enuPinMode_t Copy_enuPinMode );


#endif /* MPORT_H_ */