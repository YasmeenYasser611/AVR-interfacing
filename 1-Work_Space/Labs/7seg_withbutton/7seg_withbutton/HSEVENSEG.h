/*
 * HSEVENSEG.h
 *
 * Created: 1/5/2025 11:17:40 AM
 *  Author: yasmeen
 */ 


#ifndef HSEVENSEG_H_
#define HSEVENSEG_H_

#include "STD_TYPES.h"
#include "HSEVENSEG_config.h"


void HSEVENSEG_vInit(void);

HSEVENSEG_enuErrorStatus_t HSEVENSEG_vSetValue(u8 Copy_enuSevenSegNum , u8 Copy_u8Value);

HSEVENSEG_enuErrorStatus_t HSEVENSEG_enuSetMultiDigitValue(u16 Copy_u16Value);




#endif /* HSEVENSEG_H_ */