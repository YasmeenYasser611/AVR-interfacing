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
	reading=ADC_u16Read_Interrupt();
	millivolt=((u32) reading * 5000 / 1024);
	
		if(millivolt >=0 && millivolt < 1500)
		{
			HLED_enuSetLedState(Led1 , HLED_enuON);
			HLED_enuSetLedState(Led2 , HLED_enuOFF);
			HLED_enuSetLedState(Led3 , HLED_enuOFF);
		}
		else if(millivolt >=1500 && millivolt <3000)
		{
			HLED_enuSetLedState(Led2 , HLED_enuON);
			HLED_enuSetLedState(Led1 , HLED_enuOFF);
			HLED_enuSetLedState(Led3 , HLED_enuOFF);
		}
		else
		{
			HLED_enuSetLedState(Led3 , HLED_enuON);
			HLED_enuSetLedState(Led1 , HLED_enuOFF);
			HLED_enuSetLedState(Led2 , HLED_enuOFF);
		}
	
}
int main(void)
{
	//u16 reading =0;
	//u32 millivolt =0;
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
		
		/**************polling*/
		/*reading= ADC_u16Read_Polling(channel_0);
		//calculate analog value = digital * (ref volt / 2^ resolution )
		//we will use millli volt not voit  0:499
		millivolt=((u32) reading * 5000 / 1024);
		
		if(millivolt >=0 && millivolt < 1500)
		{
			HLED_enuSetLedState(Led1 , HLED_enuON);
			HLED_enuSetLedState(Led2 , HLED_enuOFF);
			HLED_enuSetLedState(Led3 , HLED_enuOFF);
		}
		else if(millivolt >=1500 && millivolt <3000)
		{
			HLED_enuSetLedState(Led2 , HLED_enuON);
			HLED_enuSetLedState(Led1 , HLED_enuOFF);
			HLED_enuSetLedState(Led3 , HLED_enuOFF);
		}
		else
		{
			HLED_enuSetLedState(Led3 , HLED_enuON);
			HLED_enuSetLedState(Led1 , HLED_enuOFF);
			HLED_enuSetLedState(Led2 , HLED_enuOFF);
		}*/
    }
}

