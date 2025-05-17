/*
 * HSWITCH.h
 *
 * Created: 1/2/2025 8:46:14 PM
 *  Author: Yasmeen
 */ 


#ifndef HSWITCH_H_
#define HSWITCH_H_

#include "HSWITCH_config.h"
#include "STD_TYPES.h"

void HSWITCH_vSWITCH_init(void);

HSWITCH_enuErrorStatus_t HSWITCH_enuGetSwitchState(u8 Copy_u8SwitchName, u8* Add_pu8State);



#endif /* HSWITCH_H_ */