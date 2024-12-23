/*
 * DIO_LED_BLINK.c
 *
 * Created: 12/11/2024 12:05:17 PM
 * Author : Yasmeen
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
	//define porta pin0 as output
	SET_BIT(DDRA,0);
	//loop forever
	while (1)
	{
		//led on 
		SET_BIT(PORTA , 0);
		_delay_ms(1000);
		//led off 
		CLR_BIT(PORTA , 0);
		_delay_ms(1000);
	}
}

