/*
 * HLED.h
 *
 * Created: 1/2/2025 3:07:53 PM
 *  Author: Yasmeen
 */ 


#ifndef HLED_H_
#define HLED_H_

#include "HLED_config.h"
#include "STD_TYPES.h"

void HLED_vLED_init(void);

HLED_enuErrorStatus_t HLED_enuSetLedState( u8 Copy_u8LedName, HLED_enuState_t Copy_enuState);




#endif /* HLED_H_ */