/*
 * ADC_conf.h
 *
 * Created: 3/3/2025 1:52:28 PM
 *  Author: TUF
 */ 


#ifndef ADC_CONF_H_
#define ADC_CONF_H_


// Reference Voltage Options
#define AREF        0
#define AVCC        1
#define INTERNAL_2V56 3

#define ADC_REFERENCE_VOLTAGE  AVCC  

// Adjustment Options
#define RIGHT_ADJUST 0
#define LEFT_ADJUST  1

#define ADC_ADJUSTMENT RIGHT_ADJUST 

// Prescaler Selection Options
#define PRESCALE_2   1
#define PRESCALE_4   2
#define PRESCALE_8   3
#define PRESCALE_16  4
#define PRESCALE_32  5
#define PRESCALE_64  6
#define PRESCALE_128 7

#define ADC_PRESCALER PRESCALE_128  






#endif /* ADC_CONF_H_ */