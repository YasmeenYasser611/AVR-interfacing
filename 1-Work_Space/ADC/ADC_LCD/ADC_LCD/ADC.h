/*
 * ADC.h
 *
 * Created: 3/3/2025 1:12:47 PM
 *  Author: TUF
 */ 


#ifndef ADC_H_
#define ADC_H_

#include "STD_TYPES.h"
#include "ADC_conf.h"

typedef enum
{
	channel_0=0,
	channel_1,
	channel_2,
	channel_3,
	channel_4,
	channel_5,
	channel_6,
	channel_7,
}Channels;

void ADC_voidInit(void);
void ADC_u16ADCStartConversion(Channels Copy_enuChannelNumber);

u16 ADC_u16Read_Polling(Channels Copy_enuChannelNumber);

void ADC_voidInterruptEnable(void);
void ADC_voidCallBack(void(*ptr)(void));
u16 ADC_u16Read_Interrupt();



#endif /* ADC_H_ */