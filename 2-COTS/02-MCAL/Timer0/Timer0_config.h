/*
 * Timer0_config.h
 *
 * Created: 3/3/2025 8:12:15 PM
 *  Author: TUF
 */ 


#ifndef TIMER0_CONFIG_H_
#define TIMER0_CONFIG_H_

#include "Timer0.h"

Timer0_Config_t Timer0_Config =
{
	.mode = TIMER0_CTC_MODE,         // Choose: TIMER0_OVF_MODE or TIMER0_CTC_MODE
	.prescaler = TIMER0_PRESCALE_8,  // Choose from prescaler macros
	.compare_output_mode = TIMER0_DISCONNECT_OC0  // Configure OC0 toggle on compare match PB3 
};


#endif /* TIMER0_CONFIG_H_ */


