/*
 * Traffic_Light.c
 *
 * Created: 12/11/2024 1:19:00 PM
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
	
	SET_BIT(DDRA,0); //led red
	SET_BIT(DDRA,1); // led yello
	SET_BIT(DDRA,2); //led green
	
	//loop forever
	while (1)
	{
		//led red on
		SET_BIT(PORTA , 0);
		_delay_ms(10000);
		//led red off
		CLR_BIT(PORTA , 0);
		_delay_ms(1000);
		
		//led yello on
		SET_BIT(PORTA , 1);
		_delay_ms(10000);
		//led off
		CLR_BIT(PORTA , 1);
		_delay_ms(1000);
		
		//led green on
		SET_BIT(PORTA , 2);
		_delay_ms(10000);
		//led green  off
		CLR_BIT(PORTA , 2);
		_delay_ms(1000);



	}
}


