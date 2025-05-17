/*
 * ADC_DRIVER_BUILD.c
 *
 * Created: 3/3/2025 1:12:30 PM
 * Author : TUF
 */ 
#include "ADC.h"
#include "HLED.h"
#include "HLCD.h"
#include <util/delay.h>



int main(void)
{
	u16 reading1 =0;
	u16 reading2 =0;
	u32 millivolt_Temp =0;
	u32 millivolt_LDR =0;
	u32 Temp=0;
	HLED_vLED_init();

	MPORT_vPortInit();
	
	//ADC INIT 
	ADC_voidInit();
	
	HLCD_vLCD_init();
	
	
    while (1) 
    {
	HLCD_vLCD_ClearDisplay(LCD1);
	
	ADC_u16ADCStartConversion(channel_0);
	reading1=ADC_u16Read_Polling(channel_0);
	
	ADC_u16ADCStartConversion(channel_1);
	reading2=ADC_u16Read_Polling(channel_1);
	
	millivolt_Temp=((u32) reading1 * 5000 / 1024);
	Temp = millivolt_Temp/10;
	
	millivolt_LDR=((u32) reading2 * 5000 / 1024);
	
	HLCD_enuLCD_WriteString(LCD1, " Temp=");
	HLCD_enuLCD_WriteNumber(LCD1, Temp);
	HLCD_enuLCD_WriteCharacter(LCD1 , 'C');
	HLCD_enuLCD_GotoXY(LCD1 , 1 , 0);
	HLCD_enuLCD_WriteString(LCD1, " LDR=");
	HLCD_enuLCD_WriteNumber(LCD1,millivolt_LDR );
	HLCD_enuLCD_WriteString(LCD1 , "mV");
	
		if(Temp >=0 && Temp < 20)
		{
			HLED_enuSetLedState(Led1 , HLED_enuON);
		}
		else
		{
			HLED_enuSetLedState(Led1 , HLED_enuOFF);

	
		}
		if(millivolt_LDR >=0 && millivolt_LDR < 700) 
		{
			HLED_enuSetLedState(Led2 , HLED_enuON);

		}
		else
		{
			
			HLED_enuSetLedState(Led2 , HLED_enuOFF);
			
		}
	_delay_ms(1000);
    }
}

