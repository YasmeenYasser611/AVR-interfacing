/*
 * Button_controlled_led.c
 *
 * Created: 12/11/2024 12:15:32 PM
 * Author : TUF
 */ 


#include <avr/io.h>
#include <util/delay.h>
#define F_CPU 8000000UL

#define SET_BIT(var , bit) (var|=(1<<bit))
#define CLR_BIT(var , bit) (var&=(~(1<<bit)))
#define TOGGLE_BIT(var , bit) (var^=(1<<bit))
#define GET_BIT(var , bit) ((var>>bit)&1)


int main(void)
{
	SET_BIT(DDRA,0); // portd pin0 as output for led
	CLR_BIT(DDRC,0); //portc pin0 as input for button
	SET_BIT(PORTC,0); // using pull up resistance for the button
	while (1)
	{
		//check if the button pressed
		if(GET_BIT(PINC,0)==0)
		{
			//turn the led on
			SET_BIT(PORTA , 0);

		}
		else
		{
			//turn the led off if not pressed
			CLR_BIT(PORTA , 0);
		}
		
	}
}

