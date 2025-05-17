/*
 * ADC.c
 *
 * Created: 3/3/2025 1:13:02 PM
 *  Author: TUF
 */ 
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "ADC_private.h"
#include "ADC.h"

void(*GLOBAL_PTR)(void)=NULL;

void ADC_voidInit(void)
{
	//1-reference voltage 
    ADMUX_Register &= ~(3 << REFS0); // Clear REFS1, REFS0
    ADMUX_Register |= (ADC_REFERENCE_VOLTAGE << REFS0); // Set Reference Voltage
	
    // Set Adjustment
    if (ADC_ADJUSTMENT == LEFT_ADJUST)
    {
		//1-left adjustment
        SET_BIT(ADMUX_Register, ADLAR);
    }
    else
    {
		//2-right adjustment
        CLR_BIT(ADMUX_Register, ADLAR);
    }
	
	
	//3-SELECT Prescaler
	
   
    ADCSRA_Register &= ~(7 << ADPS0); // Clear prescaler bits
    ADCSRA_Register |= (ADC_PRESCALER << ADPS0);  // Set Prescaler
	
	
	//4-ADc enable 
	SET_BIT(ADCSRA_Register , ADEN);
	
	
}
void ADC_u16ADCStartConversion(Channels Copy_enuChannelNumber)
{
	//1-SELECT CHANNEL
	ADMUX_Register &=ADC_MASK; //clear the register
	ADMUX_Register |= Copy_enuChannelNumber;
	
	//2- START CONVERTION
	SET_BIT(ADCSRA_Register , ADSC);
	
}

u16 ADC_u16Read_Polling(Channels Copy_enuChannelNumber)
{
	//1-POLLING 
	while(GET_BIT(ADCSRA_Register , ADIF)==0);
	
	//CLEAR FLAG
	SET_BIT(ADCSRA_Register , ADIF);
	
	//return digital value 
	return ADC_Register;
}

void ADC_voidInterruptEnable(void)
{
	SET_BIT(ADCSRA_Register , ADIE);
}

void ADC_voidCallBack(void(*ptr)(void))
{
	GLOBAL_PTR= ptr;
	
}

u16 ADC_u16Read_Interrupt()
{
	return ADC_Register;
	
}

void __vector_16(void) __attribute__((signal)); //adc 17 so we do it 16
void __vector_16(void)
{
	if (GLOBAL_PTR != NULL)
	{
		GLOBAL_PTR();
	}
}


