/*
 * MDIO.c
 *
 * Created: 12/17/2024 1:28:20 PM
 *  Author: Yasmeen
 */ 
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "MDIO.h"
#include "MDIO_config.h"
#include "MDIO_PRIVATE.h"

// Macros to validate inputs
#define IS_INVALID_PORT_NUM(X)			((((MDIO_enuPortNum_t)X) > MDIO_NUM_OF_PORTS) || (((MDIO_enuPortNum_t)X) < MDIO_enuPORTA))
#define IS_INVALID_PIN_NUM(X)			((((MDIO_enuPinNum_t)X) > MDIO_NUM_OF_PINS) || (((MDIO_enuPinNum_t)X) < MDIO_enuPIN0))
#define IS_INVALID_PIN_CONFIG(X)		((((MDIO_enuConfigration_t)X) != MDIO_enuOUTPUT) && (((MDIO_enuConfigration_t)X) != MDIO_enuINPUT_PULLUP) && (((MDIO_enuConfigration_t)X) != MDIO_enuINPUT_PULLDOWN))
#define IS_INVALID_PORT_CONFIG(X)		(((((MDIO_enuConfigration_t)X)) != MDIO_enuALL_OUTPUT) && (((MDIO_enuConfigration_t)X) != MDIO_enuALL_INPUT_PULLUP)&& (((MDIO_enuConfigration_t)X) != MDIO_enuALL_INPUT_PULLDOWN))
#define IS_INVALID_PIN_STATE(X)			((((MDIO_enuState_t)X) != MDIO_enuHIGH) && (((MDIO_enuState_t)X) != MDIO_enuLOW))
#define IS_INVALID_PORT_STATE(X)		((((MDIO_enuPortState_t)X) != MDIO_enuAll_HIGH) && (((MDIO_enuPortState_t)X) != MDIO_enuAll_LOW))
#define IS_INVALID_PTR(X)				((X) == NULL)



// Function: MDIO_voidInit
// Initializes all pins in all ports with their configuration based on MDIO_enuArrPinConfig array.
void MDIO_voidInit(void)
{
	u8 Local_u8_i;
	MDIO_enuPortNum_t Local_enuCurrentPort;
	MDIO_enuPinNum_t Local_enuCurrentPin;

    // Loop through all pins in all ports and set their configurations
	for (Local_u8_i = 0; Local_u8_i < (MDIO_NUM_OF_PORTS * MDIO_NUM_OF_PINS); Local_u8_i++)
	{
		Local_enuCurrentPort = Local_u8_i / MDIO_NUM_OF_PINS ;  // Determine port number
		Local_enuCurrentPin = Local_u8_i % MDIO_NUM_OF_PINS; // Determine pin number
		MDIO_enuSetPinConfigration(Local_enuCurrentPort ,Local_enuCurrentPin , MDIO_enuArrPinConfig[Local_u8_i] );
		
	}

	return;
}

// Function: MDIO_enuSetPinConfigration
// Sets the configuration of a specific pin in a given port.
MDIO_enuErrorStatus_t MDIO_enuSetPinConfigration(MDIO_enuPortNum_t Copy_enuPortNum,MDIO_enuPinNum_t Copy_enuPinNum,MDIO_enuConfigration_t Copy_enuConfigration)
{
	
		MDIO_enuErrorStatus_t Ret_enuError= MDIO_enuNOK;
		// Validate input parameters
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
		// Get the address of the port registers
		MDIO_strPortRegElement_t* Local_strPtrCurrPort =(((MDIO_PORT_REG_BASE_ADD) - (((u8)Copy_enuPortNum) * 3)));
		// Configure pin direction and state based on the requested configuration
	    if(Copy_enuConfigration == MDIO_enuOUTPUT)// Output mode
	     {
		  SET_BIT(Local_strPtrCurrPort->DDR,Copy_enuPinNum);
	     }
	     else if(Copy_enuConfigration == MDIO_enuINPUT_PULLUP) // Input with pull-up
	     {
		  CLR_BIT(Local_strPtrCurrPort->DDR ,Copy_enuPinNum );
		  SET_BIT(Local_strPtrCurrPort->PORT,Copy_enuPinNum);
				                   
		 }
		 else if(Copy_enuConfigration == MDIO_enuINPUT_PULLDOWN) // Input with pull-down
		{
		 CLR_BIT(Local_strPtrCurrPort->DDR ,Copy_enuPinNum );
         CLR_BIT(Local_strPtrCurrPort->PORT,Copy_enuPinNum );
	    }

	}
	return Ret_enuError;
	
}


// Function: MDIO_enuSetPortConfigration
// Sets the configuration of an entire port.

MDIO_enuErrorStatus_t MDIO_enuSetPortConfigration(MDIO_enuPortNum_t Copy_enuPortNum,MDIO_enuConfigration_t Copy_enuConfigration)
{
	
	MDIO_enuErrorStatus_t Ret_enuError = MDIO_enuNOK;
	
	// Validate input parameters
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
		// Set port direction and state based on the requested configuration
		MDIO_strPortRegElement_t* Local_strPtrCurrPort =(((MDIO_PORT_REG_BASE_ADD) - (((u8)Copy_enuPortNum) * 3)));
	    if(Copy_enuConfigration == MDIO_enuALL_OUTPUT) // all output
	     {
			 Local_strPtrCurrPort->DDR = Loc_enuPortstatusHigh ;  // Set all pins as output
			 Local_strPtrCurrPort->PORT=Loc_enuPortstatusLow ; // Set all pins to LOW
		  
	     }
	     else if(Copy_enuConfigration == MDIO_enuALL_INPUT_PULLUP) //MDIO_enuINPUT_PULLUP
	     {
	      	 Local_strPtrCurrPort->DDR = Loc_enuPortstatusLow; // Set all pins as input
	    	 Local_strPtrCurrPort->PORT= Loc_enuPortstatusHigh; // Enable pull-up resistors
				                   
		 }
		else if(Copy_enuConfigration == MDIO_enuALL_INPUT_PULLDOWN) //MDIO_enuINPUT_PULLDOWN
		{
	    	 Local_strPtrCurrPort->DDR = Loc_enuPortstatusLow; // Set all pins as input
	    	 Local_strPtrCurrPort->PORT= Loc_enuPortstatusHigh; // Disable pull-up resistors
	    }

	}
	return Ret_enuError;
	
}

// Function: MDIO_enuSetPinValue
// Sets the value of a specific pin in a given port (HIGH or LOW).
MDIO_enuErrorStatus_t MDIO_enuSetPinValue( MDIO_enuPortNum_t Copy_enuPortNum, MDIO_enuPinNum_t Copy_enuPinNum, MDIO_enuState_t Copy_enuState)
{
	
	MDIO_enuErrorStatus_t Ret_enuError = MDIO_enuNOK;
	
	 // Validate input parameters
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
		// Get the address of the port registers
		MDIO_strPortRegElement_t* Local_strPtrCurrPort =(((MDIO_PORT_REG_BASE_ADD) - (((u8)Copy_enuPortNum) * 3)));
		// Set the pin value (HIGH or LOW)
		if(Copy_enuState == MDIO_enuLOW) // Set pin to LOW
		{
				CLR_BIT(Local_strPtrCurrPort->PORT,Copy_enuPinNum);
		}
		else if(Copy_enuState == MDIO_enuHIGH)// Set pin to HIGH
		{
				
				SET_BIT(Local_strPtrCurrPort->PORT,Copy_enuPinNum);
				
		}

	}
	return Ret_enuError;
	
}

// Function: MDIO_enuSetPortValue
// Sets the value of an entire port (all pins HIGH or LOW).
MDIO_enuErrorStatus_t MDIO_enuSetPortValue(MDIO_enuPortNum_t Copy_enuPortNum,MDIO_enuPortState_t Copy_enuPortState)
{
	
	MDIO_enuErrorStatus_t Ret_enuError = MDIO_enuNOK;
	
	
	// Validate input parameters
	
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
		// Get the address of the port registers
		MDIO_strPortRegElement_t* Local_strPtrCurrPort =(((MDIO_PORT_REG_BASE_ADD) - (((u8)Copy_enuPortNum) * 3)));
		// Set the entire port value
		Local_strPtrCurrPort->PORT = (u8)Copy_enuPortState;
	
	}
	return Ret_enuError;
	
}
// Function: MDIO_enuGetPinValue
// Reads the value of a specific pin in a given port and stores it in the provided pointer.
MDIO_enuErrorStatus_t MDIO_enuGetPinValue(MDIO_enuPortNum_t Copy_enuPortNum,MDIO_enuPinNum_t Copy_enuPinNum,u8* Add_pu8PinValue)
{
	
	MDIO_enuErrorStatus_t Ret_enuError = MDIO_enuNOK;
	
	// Validate input parameters
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
		// Get the address of the port registers
		MDIO_strPortRegElement_t* Local_strPtrCurrPort =(((MDIO_PORT_REG_BASE_ADD) - (((u8)Copy_enuPortNum) * 3)));
		// Read the pin value and store it in the provided pointer
		*Add_pu8PinValue = GET_BIT(Local_strPtrCurrPort->PIN, Copy_enuPinNum);

	}
	return Ret_enuError;
	
}









