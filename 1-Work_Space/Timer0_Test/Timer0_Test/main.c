/*
 * Timer0_DriverBuild.c
 *
 * Created: 3/3/2025 7:55:53 PM
 * Author : TUF
 */ 


#include "Timer0.h"
#include "HLED.h"
#include "HLCD.h"
#include <util/delay.h>


#define F_CPU 8000000UL  // Assume 8MHz system clock
/*
#define REQUIRED_TIME 1 //1msec
#define TIMER_RESOLUTION 8  // 8-bit Timer0
#define prescale 8
void Timer0_Callback(void)
{
	static HLED_enuState_t led_state = HLED_enuOFF;  // Track LED state
    led_state = (led_state == HLED_enuOFF) ? HLED_enuON : HLED_enuOFF;
    HLED_enuSetLedState(Led_start, led_state );
	
}*/

int main(void)
{
	HLED_vLED_init();
	//HLCD_vLCD_init();
	
 /*  if (Timer0_Config.mode == TIMER0_OVF_MODE)
   {
	   Timer0_CalculateNormalConfig(REQUIRED_TIME, F_CPU, TIMER_RESOLUTION, prescale);
   }
   else if (Timer0_Config.mode == TIMER0_CTC_MODE)
   {
	   Timer0_CalculateCTCConfig(REQUIRED_TIME,199 ,  F_CPU, prescale);
   }*/

   Timer0_Init(); /*Select Mode */

   
  //Timer0_SETCallBack(Timer0_Callback);
  
  //prescale
  //HLCD_enuLCD_WriteNumber(LCD1, Timer0_GetPreloadOrCompare());
  
  //num of ovf or compares 
 // HLCD_enuLCD_WriteNumber(LCD1,Timer0_GetNumOVFOrCompareMatches());
  
  //if ctc show the ocr value 
 // HLCD_enuLCD_WriteNumber(LCD1,Timer0_GetCompareMatcheValue());

 //Pwm_SetDutyCycle(80);
   while (1)
   {
	   
	      for(u8 i=0 ; i< 100 ; i++)
	      {
		      
		      Pwm_SetDutyCycle(i);
			  _delay_ms(100);
	      }
   }
 }

