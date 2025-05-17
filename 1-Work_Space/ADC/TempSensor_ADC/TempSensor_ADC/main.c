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
	u32 Temp=0;

void func(void)
{
	//of more than adc channel used , read mux to know we have interrupt according to any one
	reading=ADC_u16Read_Interrupt();
	millivolt=((u32) reading * 5000 / 1024);
	Temp = millivolt/10;
	
		if(Temp >=0 && Temp < 20)
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

    }
}

