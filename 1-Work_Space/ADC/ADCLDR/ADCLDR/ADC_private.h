/*
 * ADC_private.h
 *
 * Created: 3/3/2025 1:53:07 PM
 *  Author: TUF
 */ 


#ifndef ADC_PRIVATE_H_
#define ADC_PRIVATE_H_

#define ADMUX_Register  *((volatile u8*)(0x27))
#define ADCSRA_Register *((volatile u8*)(0x26))
#define ADC_Register    *((volatile u16*)(0x24)) //the 2 registers ADCL +ADCH assume thay are 1 register
#define SFIOR_Register  *((volatile u8*)(0x50))

#define ADC_MASK 0b11100000

#define ADSC 6
#define ADIF 4


#define REFS1 7
#define REFS0 6
#define ADLAR 5
#define ADEN 7
#define ADPS0 0 
#define ADPS1 1
#define ADPS2 2

#define  ADIE 3

#endif /* ADC_PRIVATE_H_ */