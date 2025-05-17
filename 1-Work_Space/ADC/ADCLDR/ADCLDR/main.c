/*
 * ADC_DRIVER_BUILD.c
 *
 * Created: 3/3/2025 1:12:30 PM
 * Author : TUF
 */ 
#include "ADC.h"
#include "HLED.h"
#include "GIE.h"
	u16 reading =0;
	u32 millivolt =0;

void func(void)
{
	//of more than adc channel used , read mux to know we have interrupt according to any one
	reading=ADC_u16Read_Interrupt();
	millivolt=((u32) reading * 5000 / 1024);
	
		if(millivolt >=0 && millivolt < 700) //change the value according to the room light 
		{
			HLED_enuSetLedState(Led1 , HLED_enuON);

		}
		else
		{
			
			HLED_enuSetLedState(Led1 , HLED_enuOFF);
	
		}
	
}
int main(void)
{
	HLED_vLED_init();
	
    //SELECT ADC PIN INPUT (not input pull up)
	MPORT_vPortInit();
	
	//ADC INIT 
	ADC_voidInit();
	
	//fot interrupt
	GIE_VoidEnable();
	ADC_voidInterruptEnable();
	ADC_voidCallBack(func);
	
	
    while (1) 
    {
		ADC_u16ADCStartConversion(channel_0);
		
		/*
		if we will use more than adc channel in the same time 
		//if using interrupt we will neeed in func to know which one cause the interrupt
		ADC_u16ADCStartConversion(channel_0);
		_delay_ms(1000);//delay 1sec 
		ADC_u16ADCStartConversion(channel_1);
		_delay_ms(1000);//delay 1sec 
		
		//or polling in this case prefered
		reading1 = ADC_u16Read_Polling(channel_0);
		reading2 = ADC_u16Read_Polling(channel_1);
		
		//or using exti1 --- channel1
		
		polling is perfeared in this case
		
		 */
		
		
	
    }
}

