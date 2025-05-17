/*
 * Timer1_Config.h
 *
 * Created: 3/5/2025 1:11:49 PM
 *  Author: TUF
 */ 


#ifndef TIMER1_CONFIG_H_
#define TIMER1_CONFIG_H_

#include "Timer1.h"

Timer1_Config_t Timer1_Config =
{
	.mode = TIMER1_CTC_MODE_OCR1A,  // CTC mode
	.prescaler = TIMER1_PRESCALE_8,
	.compare_output_mode_A = TIMER1_TOGGLE_OC1A, 
	.compare_output_mode_B = TIMER1_DISCONNECT_OC1A_OC1B
};

#endif /* TIMER1_CONFIG_H_ */
