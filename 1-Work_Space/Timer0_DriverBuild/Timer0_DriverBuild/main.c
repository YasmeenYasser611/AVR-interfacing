/*
 * Timer0_DriverBuild.c
 *
 * Created: 3/3/2025 7:55:53 PM
 * Author : TUF
 */ 


#include "Timer0.h"


/*
#include "HLED.h"



#define F_CPU 8000000UL  // Assume 16MHz system clock
#define REQUIRED_TIME 5000  // 1000ms (1 second)
#define TIMER_RESOLUTION 8  // 8-bit Timer0

void Timer0_Callback(void)
{
	static HLED_enuState_t led_state = HLED_enuOFF;  // Track LED state
    led_state = (led_state == HLED_enuOFF) ? HLED_enuON : HLED_enuOFF;
    HLED_enuSetLedState(Led_start, led_state );
	
}

int main(void)
{
	HLED_vLED_init();
	
   if (Timer0_Config.mode == TIMER0_OVF_MODE)
   {
	   Timer0_CalculateNormalConfig(REQUIRED_TIME, F_CPU, TIMER_RESOLUTION, 1024);
   }
   else if (Timer0_Config.mode == TIMER0_CTC_MODE)
   {
	   Timer0_CalculateCTCConfig(REQUIRED_TIME, F_CPU, 1024);
   }

   Timer0_Init();
   
   Timer0_SETCallBack(Timer0_Callback);
  

   while (1);
 }*/


#include <util/delay.h>

int main(void)
{
	/* Initialize Timer0 (Configures OC0 as Output) */
	Timer0_Init();
	
	while (1)
	{
		//Pwm_SetDutyCycle(80);
		/* Gradually increase LED brightness */
		for (u8 duty = 0; duty <= 100; duty += 10)
		{
			Pwm_SetDutyCycle(duty);
			_delay_ms(500);
		}

		 /*Gradually decrease LED brightness */
		for (u8 duty = 100; duty > 0; duty -= 10)
		{
			Pwm_SetDutyCycle(duty);
			_delay_ms(500);
		}
	}
}
