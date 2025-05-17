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
	.mode = TIMER0_FAST_PWM,        
	.prescaler = TIMER0_PRESCALE_8, 
	.compare_output_mode = TIMER0_CLEAR_OC0  /* Clear OC0 on compare match, set OC0 at BOTTOM*/
};


#endif /* TIMER0_CONFIG_H_ */


