/*
 * Timer2_Config.h
 *
 * Created: 3/5/2025 11:02:30 AM
 *  Author: TUF
 */ 


#ifndef TIMER2_CONFIG_H_
#define TIMER2_CONFIG_H_

#include "Timer2.h"

Timer2_Config_t Timer2_Config =
{
	.mode = TIMER2_OVF_MODE,         // Choose: TIMER0_OVF_MODE or TIMER0_CTC_MODE
	.prescaler = TIMER2_PRESCALE_8,  // Choose from prescaler macros
	.compare_output_mode = TIMER2_DISCONNECT_OC2  // Configure OC0 toggle on compare match
	};
#endif /* TIMER2_CONFIG_H_ */
