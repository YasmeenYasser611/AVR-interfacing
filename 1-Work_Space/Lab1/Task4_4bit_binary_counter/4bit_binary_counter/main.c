/*
 * 4bit_binary_counter.c
 *
 * Created: 12/11/2024 12:55:04 PM
 * Author : yasmeen
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
	SET_BIT(DDRA,0); // portd pin0 as output for led0
	SET_BIT(DDRA,1); // portd pin1 as output for led1
	SET_BIT(DDRA,2); // portd pin2 as output for led2
	SET_BIT(DDRA,3); // portd pin3 as output for led3
	
	CLR_BIT(DDRC,0); //portc pin0 as input for button
	SET_BIT(PORTC,0); // using pull up resistance for the button
	int counter=0; //counter to count the number
	PORTA= counter; //first print 
	_delay_ms(1000);
	while (1)
	{
		
		//check if the button pressed
		if(GET_BIT(PINC,0)==0)
		{
			//increment the counter
			counter++;
			//display the counter value
			PORTA= counter;
			
			if(counter==16)//check if counter reach 115 2^4 -1
			{
				//reset the counter and display the value
				counter=0;
				PORTA= counter;
				_delay_ms(1000);
			}
			while(GET_BIT(PINC,0)==0); //wait till the switch is not pressed 
			

		}
		
		
	}
}


