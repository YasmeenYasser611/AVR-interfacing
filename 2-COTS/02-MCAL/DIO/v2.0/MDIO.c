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
#define NULL ((void*)0)
/*
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
*/

#define MDIO_PORT_REG_BASE_ADD  ((volatile u8*)(0x39))

typedef struct
{
	volatile u8 PIN;
	volatile u8 DDR;
	volatile u8 PORT;
} MDIO_strPortRegElement_t;


#define IS_INVALID_PORT_NUM(X)			((((MDIO_enuPortNum_t)X) > MDIO_enuPORTD) || (((MDIO_enuPortNum_t)X) < MDIO_enuPORTA))
#define IS_INVALID_PIN_NUM(X)			((((MDIO_enuPinNum_t)X) > MDIO_enuPIN7) || (((MDIO_enuPinNum_t)X) < MDIO_enuPIN0))
#define IS_INVALID_PIN_CONFIG(X)		((((MDIO_enuConfigration_t)X) != MDIO_enuOUTPUT) && (((MDIO_enuConfigration_t)X) != MDIO_enuINPUT_PULLUP) && (((MDIO_enuConfigration_t)X) != MDIO_enuINPUT_PULLDOWN))
#define IS_INVALID_PORT_CONFIG(X)		(((((MDIO_enuConfigration_t)X)) != MDIO_enuALL_OUTPUT) && (((MDIO_enuConfigration_t)X) != MDIO_enuALL_INPUT_PULLUP)&& (((MDIO_enuConfigration_t)X) != MDIO_enuALL_INPUT_PULLDOWN))
#define IS_INVALID_PIN_STATE(X)			((((MDIO_enuState_t)X) != MDIO_enuHIGH) && (((MDIO_enuState_t)X) != MDIO_enuLOW))
#define IS_INVALID_PORT_STATE(X)		((((MDIO_enuPortState_t)X) != MDIO_enuAll_HIGH) && (((MDIO_enuPortState_t)X) != MDIO_enuAll_LOW))
#define IS_INVALID_PTR(X)				((X) == NULL)



MDIO_enuErrorStatus_t MDIO_enuSetPinConfigration(MDIO_enuPortNum_t Copy_enuPortNum,MDIO_enuPinNum_t Copy_enuPinNum,MDIO_enuConfigration_t Copy_enuConfigration)
{
	
		MDIO_enuErrorStatus_t Ret_enuError= MDIO_enuNOK;
		
		if (IS_INVALID_PORT_NUM(Copy_enuPortNum))
		{
			Ret_enuError = MDIO_enuINVALID_PortNum;
			
		}
		else if (IS_INVALID_PIN_NUM(Copy_enuPinNum))
		{
			Ret_enuError = MDIO_enuINVALID_PinNum;
		}
		else if (IS_INVALID_PIN_CONFIG(Copy_enuConfigration))
		{
			Ret_enuError = MDIO_enuINVALID_Configration;
		}
		else
		{
		Ret_enuError = MDIO_enuOK;
		MDIO_strPortRegElement_t* Local_strPtrCurrPort =(((MDIO_PORT_REG_BASE_ADD) - (((u8)Copy_enuPortNum) * 3)));
	    if(Copy_enuConfigration == MDIO_enuOUTPUT) //output
	     {
		  SET_BIT(Local_strPtrCurrPort->DDR,Copy_enuPinNum);
	     }
	     else if(Copy_enuConfigration == MDIO_enuINPUT_PULLUP) //MDIO_enuINPUT_PULLUP
	     {
		  CLR_BIT(Local_strPtrCurrPort->DDR ,Copy_enuPinNum );
		  SET_BIT(Local_strPtrCurrPort->PORT,Copy_enuPinNum);
				                   
		 }
		 else if(Copy_enuConfigration == MDIO_enuINPUT_PULLDOWN) //MDIO_enuINPUT_PULLDOWN
		{
		 CLR_BIT(Local_strPtrCurrPort->DDR ,Copy_enuPinNum );
         CLR_BIT(Local_strPtrCurrPort->PORT,Copy_enuPinNum );
	    }

	}
	return Ret_enuError;
	
}




MDIO_enuErrorStatus_t MDIO_enuSetPortConfigration(MDIO_enuPortNum_t Copy_enuPortNum,MDIO_enuConfigration_t Copy_enuConfigration)
{
	
	MDIO_enuErrorStatus_t Ret_enuError;
	
	Ret_enuError = MDIO_enuNOK;
	if (IS_INVALID_PORT_NUM(Copy_enuPortNum))
	{
		Ret_enuError = MDIO_enuINVALID_PortNum;
		
	}
	else if (IS_INVALID_PORT_CONFIG(Copy_enuConfigration))
	{
		Ret_enuError = MDIO_enuINVALID_Configration;
	}
	else
	{
		Ret_enuError = MDIO_enuOK;
		MDIO_enuPortState_t Loc_enuPortstatusHigh = MDIO_enuAll_HIGH ;
		MDIO_enuPortState_t Loc_enuPortstatusLow = MDIO_enuAll_LOW ;
		MDIO_strPortRegElement_t* Local_strPtrCurrPort =(((MDIO_PORT_REG_BASE_ADD) - (((u8)Copy_enuPortNum) * 3)));
	    if(Copy_enuConfigration == MDIO_enuALL_OUTPUT) // all output
	     {
			 Local_strPtrCurrPort->DDR = Loc_enuPortstatusHigh ;
			 Local_strPtrCurrPort->PORT=Loc_enuPortstatusLow ;
		  
	     }
	     else if(Copy_enuConfigration == MDIO_enuALL_INPUT_PULLUP) //MDIO_enuINPUT_PULLUP
	     {
	      	 Local_strPtrCurrPort->DDR = Loc_enuPortstatusLow;
	    	 Local_strPtrCurrPort->PORT= Loc_enuPortstatusHigh;
				                   
		 }
		else if(Copy_enuConfigration == MDIO_enuALL_INPUT_PULLDOWN) //MDIO_enuINPUT_PULLDOWN
		{
	    	 Local_strPtrCurrPort->DDR = Loc_enuPortstatusLow;
	    	 Local_strPtrCurrPort->PORT= Loc_enuPortstatusHigh;
	    }

	}
	return Ret_enuError;
	
}


MDIO_enuErrorStatus_t MDIO_enuSetPinValue( MDIO_enuPortNum_t Copy_enuPortNum, MDIO_enuPinNum_t Copy_enuPinNum, MDIO_enuState_t Copy_enuState)
{
	
	MDIO_enuErrorStatus_t Ret_enuError;
	Ret_enuError = MDIO_enuNOK;
	if (IS_INVALID_PORT_NUM(Copy_enuPortNum))
	{
		Ret_enuError = MDIO_enuINVALID_PortNum;
		
	}
	else if (IS_INVALID_PIN_NUM(Copy_enuPinNum))
	{
		Ret_enuError = MDIO_enuINVALID_PinNum;
	}
	else if (IS_INVALID_PIN_STATE(Copy_enuState))
	{
		Ret_enuError = MDIO_enuINVALID_PinStatus;
	}
	else
	{
		Ret_enuError = MDIO_enuOK;
		MDIO_strPortRegElement_t* Local_strPtrCurrPort =(((MDIO_PORT_REG_BASE_ADD) - (((u8)Copy_enuPortNum) * 3)));
		if(Copy_enuState == MDIO_enuLOW) //low
		{
				CLR_BIT(Local_strPtrCurrPort->PORT,Copy_enuPinNum);
		}
		else if(Copy_enuState == MDIO_enuHIGH) //high
		{
				
				SET_BIT(Local_strPtrCurrPort->PORT,Copy_enuPinNum);
				
		}

	}
	return Ret_enuError;
	
}


MDIO_enuErrorStatus_t MDIO_enuSetPortValue(MDIO_enuPortNum_t Copy_enuPortNum,MDIO_enuPortState_t Copy_enuPortState)
{
	
	MDIO_enuErrorStatus_t Ret_enuError;
	
	Ret_enuError = MDIO_enuNOK;
	if (IS_INVALID_PORT_NUM(Copy_enuPortNum))
	{
		Ret_enuError = MDIO_enuINVALID_PortNum;
		
	}
	else if (IS_INVALID_PORT_STATE(Copy_enuPortState))
	{
		Ret_enuError = MDIO_enuINVALID_PortStatus;
	}
	else
	{
		Ret_enuError = MDIO_enuOK;
		MDIO_strPortRegElement_t* Local_strPtrCurrPort =(((MDIO_PORT_REG_BASE_ADD) - (((u8)Copy_enuPortNum) * 3)));
		Local_strPtrCurrPort->PORT = (u8)Copy_enuPortState;
	
	}
	return Ret_enuError;
	
}

MDIO_enuErrorStatus_t MDIO_enuGetPinValue(MDIO_enuPortNum_t Copy_enuPortNum,MDIO_enuPinNum_t Copy_enuPinNum,u8* Add_pu8PinValue)
{
	
	MDIO_enuErrorStatus_t Ret_enuError;
	Ret_enuError = MDIO_enuNOK;
	if (IS_INVALID_PORT_NUM(Copy_enuPortNum))
	{
		Ret_enuError = MDIO_enuINVALID_PortNum;
		
	}
	else if (IS_INVALID_PIN_NUM(Copy_enuPinNum))
	{
		Ret_enuError = MDIO_enuINVALID_PinNum;
	}
	else if (IS_INVALID_PTR(Add_pu8PinValue))
	{
		Ret_enuError = MDIO_enuNULL_PTR;
	}
	else
	{
		Ret_enuError = MDIO_enuOK;
		MDIO_strPortRegElement_t* Local_strPtrCurrPort =(((MDIO_PORT_REG_BASE_ADD) - (((u8)Copy_enuPortNum) * 3)));
		*Add_pu8PinValue = GET_BIT(Local_strPtrCurrPort->PIN, Copy_enuPinNum);

	}
	return Ret_enuError;
	
}









