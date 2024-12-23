/*
 * MDIO.c
 *
 * Created: 12/17/2024 1:28:20 PM
 *  Author: TUF
 */ 
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "STD_TYPES.h"
#include "MDIO.h"

#define PORTA (*((volatile u8*)0x3B))
#define DDRA (*((volatile u8*)0x3A))
#define PINA (*((volatile u8*)0x39))

#define PORTB (*((volatile u8*)0x38))
#define DDRB (*((volatile u8*)0x37))
#define PINB (*((volatile u8*)0x36))

#define PORTC (*((volatile u8*)0x35))
#define DDRC (*((volatile u8*)0x34))
#define PINC (*((volatile u8*)0x33))

#define PORTD (*((volatile u8*)0x32))
#define DDRD (*((volatile u8*)0x31))
#define PIND (*((volatile u8*)0x30))

MDIO_enuErrorStatus_t MDIO_enuSetPinConfigration(MDIO_enuPortNum Copy_enuPortNum,MDIO_enuPinNum Copy_enuPinNum,MDIO_enuConfigration Copy_enuConfigration)
{
	
		MDIO_enuErrorStatus_t Ret_enuError;
		Ret_enuError = MDIO_enuNOK;
		if(Copy_enuPortNum >MDIO_enuPORTD)
		{
			Ret_enuError = MDIO_enuINVALID_PortNum;
			
		}
		else if(Copy_enuPinNum >MDIO_enuPIN7)
		{
			Ret_enuError = MDIO_enuINVALID_PinNum;
		}
		else if(Copy_enuConfigration >MDIO_enuINPUT_PULLDOWN)
		{
			Ret_enuError = MDIO_enuINVALID_Configration;
		}
		else
		{
		Ret_enuError = MDIO_enuOK;
		switch(Copy_enuPortNum)
		{
		case MDIO_enuPORTA :
		                   if(Copy_enuConfigration == 0) //output
						   {
							   SET_BIT(DDRA,Copy_enuPinNum);
						   }
						   else if(Copy_enuConfigration == 1) //MDIO_enuINPUT_PULLUP
						   {
							  CLR_BIT(DDRA ,Copy_enuPinNum );
							  SET_BIT(PORTA,Copy_enuPinNum);
							  
						   }
						   else if(Copy_enuConfigration == 2) //MDIO_enuINPUT_PULLDOWN
						   {
							   CLR_BIT(DDRA ,Copy_enuPinNum );
							   CLR_BIT(PORTA,Copy_enuPinNum );
						   }
						   break;
		case MDIO_enuPORTB :
		                   if(Copy_enuConfigration == 0) //output
						   {
							   SET_BIT(DDRB,Copy_enuPinNum);
						   }
						   else if(Copy_enuConfigration == 1) //MDIO_enuINPUT_PULLUP
						   {
							  CLR_BIT(DDRB ,Copy_enuPinNum );
							  SET_BIT(PORTB,Copy_enuPinNum);
							  
						   }
						   else if(Copy_enuConfigration == 2) //MDIO_enuINPUT_PULLDOWN
						   {
							   CLR_BIT(DDRB ,Copy_enuPinNum );
							   CLR_BIT(PORTB,Copy_enuPinNum );
						   }
						   break;
		case MDIO_enuPORTC :
		                   if(Copy_enuConfigration == 0) //output
						   {
							   SET_BIT(DDRC,Copy_enuPinNum);
						   }
						   else if(Copy_enuConfigration == 1) //MDIO_enuINPUT_PULLUP
						   {
							  CLR_BIT(DDRC ,Copy_enuPinNum );
							  SET_BIT(PORTC,Copy_enuPinNum);
							  
						   }
						   else if(Copy_enuConfigration == 2) //MDIO_enuINPUT_PULLDOWN
						   {
							   CLR_BIT(DDRC ,Copy_enuPinNum );
							   CLR_BIT(PORTC,Copy_enuPinNum );
						   }
						   break;
		case MDIO_enuPORTD :
		                   if(Copy_enuConfigration == 0) //output
						   {
							   SET_BIT(DDRD,Copy_enuPinNum);
						   }
						   else if(Copy_enuConfigration == 1) //MDIO_enuINPUT_PULLUP
						   {
							  CLR_BIT(DDRD ,Copy_enuPinNum );
							  SET_BIT(PORTD,Copy_enuPinNum);
							  
						   }
						   else if(Copy_enuConfigration == 2) //MDIO_enuINPUT_PULLDOWN
						   {
							   CLR_BIT(DDRD ,Copy_enuPinNum );
							   CLR_BIT(PORTD,Copy_enuPinNum );
						   }
						   break;
						   
						   
	}
	}
	return Ret_enuError;
	
}
MDIO_enuErrorStatus_t MDIO_enuSetPortConfigration(MDIO_enuPortNum Copy_enuPortNum,MDIO_enuConfigration Copy_enuConfigration)
{
	
	MDIO_enuErrorStatus_t Ret_enuError;
	
	Ret_enuError = MDIO_enuNOK;
	if(Copy_enuPortNum >MDIO_enuPORTD)
	{
		Ret_enuError = MDIO_enuINVALID_PortNum;
		
	}
	else if(Copy_enuConfigration >MDIO_enuINPUT_PULLDOWN)
	{
		Ret_enuError = MDIO_enuINVALID_Configration;
	}
	else
	{
		Ret_enuError = MDIO_enuOK;
		switch(Copy_enuPortNum)
		{
			case MDIO_enuPORTA :
			if(Copy_enuConfigration == MDIO_enuALL_OUTPUT) //output
			{
				DDRA = MDIO_enuALL_OUTPUT ;
			}
			else if(Copy_enuConfigration == MDIO_enuALL_INPUT_PULLUP) //MDIO_enuINPUT_PULLUP
			{
				DDRA = MDIO_enuALL_INPUT_PULLUP;
				PORTA= MDIO_enuALL_OUTPUT;
				
			}
			else if(Copy_enuConfigration == MDIO_enuALL_INPUT_PULLDOWN) //MDIO_enuINPUT_PULLDOWN
			{
				DDRA = MDIO_enuALL_INPUT_PULLDOWN;
				PORTA= MDIO_enuALL_INPUT_PULLDOWN;
			}
			break;
			case MDIO_enuPORTB :
			if(Copy_enuConfigration == MDIO_enuALL_OUTPUT) //output
			{
				DDRB = MDIO_enuALL_OUTPUT ;
			}
			else if(Copy_enuConfigration == MDIO_enuALL_INPUT_PULLUP) //MDIO_enuINPUT_PULLUP
			{
				DDRB = MDIO_enuALL_INPUT_PULLUP;
				PORTB= MDIO_enuALL_OUTPUT;				
			}
			else if(Copy_enuConfigration ==MDIO_enuALL_INPUT_PULLDOWN ) //MDIO_enuINPUT_PULLDOWN
			{
				DDRA = MDIO_enuALL_INPUT_PULLDOWN;
				PORTA= MDIO_enuALL_INPUT_PULLDOWN;
			}
			break;
			case MDIO_enuPORTC :
			if(Copy_enuConfigration == MDIO_enuALL_OUTPUT) //output
			{
				DDRC = MDIO_enuALL_OUTPUT ;
			}
			else if(Copy_enuConfigration == MDIO_enuALL_INPUT_PULLUP) //MDIO_enuINPUT_PULLUP
			{
				DDRC = MDIO_enuALL_INPUT_PULLUP;
				PORTC= MDIO_enuALL_OUTPUT;
				
			}
			else if(Copy_enuConfigration == MDIO_enuALL_INPUT_PULLDOWN) //MDIO_enuINPUT_PULLDOWN
			{
				DDRC = MDIO_enuALL_INPUT_PULLDOWN;
				PORTC= MDIO_enuALL_INPUT_PULLDOWN;
			}
			break;
			case MDIO_enuPORTD :
			if(Copy_enuConfigration == MDIO_enuALL_OUTPUT) //output
			{
				DDRD = MDIO_enuALL_OUTPUT ;
			}
			else if(Copy_enuConfigration == MDIO_enuALL_INPUT_PULLUP) //MDIO_enuINPUT_PULLUP
			{
				DDRD = MDIO_enuALL_INPUT_PULLUP;
				PORTD= MDIO_enuALL_OUTPUT;				
			}
			else if(Copy_enuConfigration == MDIO_enuALL_INPUT_PULLDOWN) //MDIO_enuINPUT_PULLDOWN
			{
				DDRD = MDIO_enuALL_INPUT_PULLDOWN;
				PORTD= MDIO_enuALL_INPUT_PULLDOWN;
			}
			break;
			
			
		}
	}
	return Ret_enuError;
	
}
MDIO_enuErrorStatus_t MDIO_enuSetPinValue( MDIO_enuPortNum Copy_enuPortNum, MDIO_enuPinNum Copy_enuPinNum, MDIO_enuState Copy_enuState)
{
	
	MDIO_enuErrorStatus_t Ret_enuError;
	Ret_enuError = MDIO_enuNOK;
	if(Copy_enuPortNum >MDIO_enuPORTD)
	{
		Ret_enuError = MDIO_enuINVALID_PortNum;
		
	}
	else if(Copy_enuPinNum >MDIO_enuPIN7)
	{
		Ret_enuError = MDIO_enuINVALID_PinNum;
	}
	else if(Copy_enuState >MDIO_enuHIGH)
	{
		Ret_enuError = MDIO_enuINVALID_PinStatus;
	}
	else
	{
		Ret_enuError = MDIO_enuOK;
		switch(Copy_enuPortNum)
		{
			case MDIO_enuPORTA :
			if(Copy_enuState == MDIO_enuLOW) //low
			{
				CLR_BIT(PORTA,Copy_enuPinNum);
			}
			else if(Copy_enuState == MDIO_enuHIGH) //high
			{
				
				SET_BIT(PORTA,Copy_enuPinNum);
				
			}
			break;
			case MDIO_enuPORTB :
			if(Copy_enuState == MDIO_enuLOW) //low
			{
				CLR_BIT(PORTB,Copy_enuPinNum);
			}
			else if(Copy_enuState == MDIO_enuHIGH) //high
			{
				
				SET_BIT(PORTB,Copy_enuPinNum);
				
			}
			break;
			case MDIO_enuPORTC :
			if(Copy_enuState == MDIO_enuLOW) //low
			{
				CLR_BIT(PORTC,Copy_enuPinNum);
			}
			else if(Copy_enuState == MDIO_enuHIGH) //high
			{
				
				SET_BIT(PORTC,Copy_enuPinNum);
				
			}
			break;
			case MDIO_enuPORTD :
			if(Copy_enuState == MDIO_enuLOW) //LOW
			{
				CLR_BIT(PORTD,Copy_enuPinNum);
			}
			else if(Copy_enuState == MDIO_enuHIGH) //HIGH
			{
				
				SET_BIT(PORTD,Copy_enuPinNum);
				
			}
			break;
			
			
		}
	}
	return Ret_enuError;
	
}
MDIO_enuErrorStatus_t MDIO_enuSetPortValue(MDIO_enuPortNum Copy_enuPortNum,MDIO_enuPortState Copy_enuPortState)
{
	
	MDIO_enuErrorStatus_t Ret_enuError;
	
	Ret_enuError = MDIO_enuNOK;
	if(Copy_enuPortNum >MDIO_enuPORTD)
	{
		Ret_enuError = MDIO_enuINVALID_PortNum;
		
	}
	else if(Copy_enuPortState != (MDIO_enuAll_HIGH ||MDIO_enuAll_LOW))
	{
		Ret_enuError = MDIO_enuINVALID_PortStatus;
	}
	else
	{
		Ret_enuError = MDIO_enuOK;
		switch(Copy_enuPortNum)
		{
			case MDIO_enuPORTA :
			if(Copy_enuPortState == MDIO_enuAll_LOW) //all low
			{
				PORTA = 0x00 ;
			}
			else if(Copy_enuPortState == MDIO_enuAll_HIGH) //MDIO_enuINPUT_PULLUP
			{
				
				PORTA= 0xff;
				
			}
			break;
			case MDIO_enuPORTB :
			if(Copy_enuPortState == MDIO_enuAll_LOW) //all low
			{
				PORTB = 0x00 ;
			}
			else if(Copy_enuPortState == MDIO_enuAll_HIGH) //MDIO_enuINPUT_PULLUP
			{
				
				PORTB= 0xff;
				
			}
			break;
			case MDIO_enuPORTC :
			if(Copy_enuPortState == MDIO_enuAll_LOW) //all low
			{
				PORTC = 0x00 ;
			}
			else if(Copy_enuPortState == MDIO_enuAll_HIGH) //MDIO_enuINPUT_PULLUP
			{
				
				PORTC= 0xff;
				
			}
			break;
			case MDIO_enuPORTD :
			if(Copy_enuPortState == MDIO_enuAll_LOW) //all low
			{
				PORTD = 0x00 ;
			}
			else if(Copy_enuPortState == MDIO_enuAll_HIGH) //MDIO_enuINPUT_PULLUP
			{
				
				PORTD= 0xff;
				
			}
			break;
			
			
		}
	}
	return Ret_enuError;
	
}

MDIO_enuErrorStatus_t MDIO_enuGetPinValue(MDIO_enuPortNum Copy_enuPortNum,MDIO_enuPinNum Copy_enuPinNum,u8* Add_pu8PinValue)
{
	
	MDIO_enuErrorStatus_t Ret_enuError;
	Ret_enuError = MDIO_enuNOK;
	if(Copy_enuPortNum >MDIO_enuPORTD)
	{
		Ret_enuError = MDIO_enuINVALID_PortNum;
		
	}
	else if(Copy_enuPinNum >MDIO_enuPIN7)
	{
		Ret_enuError = MDIO_enuINVALID_PinNum;
	}
	else if(Add_pu8PinValue == NULL)
	{
		Ret_enuError = MDIO_enuNULL_PTR;
	}
	else
	{
		Ret_enuError = MDIO_enuOK;
		switch(Copy_enuPortNum)
		{
			case MDIO_enuPORTA :
			*Add_pu8PinValue = GET_BIT(PINA, Copy_enuPinNum);
			break;
			case MDIO_enuPORTB :
            *Add_pu8PinValue = GET_BIT(PINB , Copy_enuPinNum);
			break;
			case MDIO_enuPORTC :
            *Add_pu8PinValue = GET_BIT(PINC , Copy_enuPinNum);
			break;
			case MDIO_enuPORTD :
            *Add_pu8PinValue = GET_BIT(PIND , Copy_enuPinNum);
			break;
			
			
		}
	}
	return Ret_enuError;
	
}









