/*
 * MPORT.c
 *
 * Created: 12/25/2024 1:55:17 PM
 *  Author: TUF
 */ 

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "MPORT.h"
#include "MPORT_config.h"
#include "MPORT_PRIVATE.h"




// Macros to validate inputs

#define IS_INVALID_PORT_NUM(X)			((((MDIO_enuPortNum_t)X) > 3) || (((MDIO_enuPortNum_t)X) < 0))
#define IS_INVALID_PIN_NUM(X)			((((MDIO_enuPinNum_t)X) > 7) || (((MDIO_enuPinNum_t)X) < 0))
#define IS_INVALID_PIN_CONFIG(X)		((((MDIO_enuConfigration_t)X) != MDIO_enuOUTPUT) && (((MDIO_enuConfigration_t)X) != MDIO_enuINPUT))
#define IS_INVALID_PIN_MODE(X)		((((MDIO_enuPinNum_t)X) > PORT_PIN_MODE_UART) || (((MDIO_enuPinNum_t)X) < MPORT_enuINPUT_PULL_UP))



// Function: MDIO_voidInit
// Initializes all pins in all ports with their configuration based on MDIO_enuArrPinConfig array.
void MDIO_vPortInit(void)
{
	u8 Local_u8_i;
	MDIO_enuPortNum_t Local_enuCurrentPort;
	MDIO_enuPinNum_t Local_enuCurrentPin;

	// Loop through all pins in all ports and set their configurations
	for (Local_u8_i = 0; Local_u8_i < (MDIO_NUM_OF_PORTS * MDIO_NUM_OF_PINS); Local_u8_i++)
	{
		Local_enuCurrentPort = Local_u8_i / MDIO_NUM_OF_PINS ;  // Determine port number
		Local_enuCurrentPin = Local_u8_i % MDIO_NUM_OF_PINS; // Determine pin number
		MPORT_enuSetPinConfigration(Local_enuCurrentPort ,Local_enuCurrentPin , MDIO_enuArrPinConfig[Local_u8_i] );
		
	}

	//return;
}


// Function: MDIO_enuSetPinConfigration
// Sets the configuration of a specific pin in a given port.
MPORT_enuErrorStatus_t MPORT_enuSetPinConfigration(MDIO_enuPortNum_t Copy_enuPortNum,MDIO_enuPinNum_t Copy_enuPinNum,MDIO_enuConfigration_t Copy_enuConfigration)
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



MPORT_enuErrorStatus_t MPORT_enuSetPinDirection( u8 Copy_enuPinNum  ,  MPORT_enuPINConfigration_t  Copy_enuPinDirection  )
{
	
	MDIO_enuErrorStatus_t Ret_enuError= MDIO_enuNOK;
	u8 LOC_u8portNumber = (Copy_enuPinNum >> 4) & 0x0F;
	u8 LOC_u8pinNumber = Copy_enuPinNum & 0x0F;
	// Validate input parameters
	if (IS_INVALID_PORT_NUM(LOC_u8portNumber))
	{
			Ret_enuError = MPORT_enuINVALID_PortNum;
	}
	else if (IS_INVALID_PIN_NUM(LOC_u8pinNumber))
	{
			Ret_enuError = MPORT_enuINVALID_PortNum;
	}
	else if (IS_INVALID_PIN_CONFIG(Copy_enuPinDirection))
	{
			Ret_enuError = MPORT_enuINVALID_PINConfigration;
	}
	else
	{
		Ret_enuError = MDIO_enuOK;
		// Get the address of the port registers
		
		MDIO_strPortRegElement_t* Local_strPtrCurrPort =(((MDIO_PORT_REG_BASE_ADD) - (((u8)LOC_u8portNumber) * 3)));
		
		// Configure pin direction and state based on the requested configuration
		if(Copy_enuPinDirection == MDIO_enuOUTPUT)// Output mode
		{
			SET_BIT(Local_strPtrCurrPort->DDR,Copy_enuPinNum);
		}
		else if(Copy_enuPinDirection == MDIO_enuINPUT) // Input no pull up
		{
			CLR_BIT(Local_strPtrCurrPort->DDR ,Copy_enuPinNum );
			CLR_BIT(Local_strPtrCurrPort->PORT,Copy_enuPinNum);
			
		}
	
	}
	return Ret_enuError;
	
}

MPORT_enuErrorStatus_t MPORT_enuSetPinMode( u8 Copy_enuPinNum  ,  MPORT_enuPinMode_t Copy_enuPinMode )
{
		MPORT_enuErrorStatus_t Ret_enuError= MDIO_enuNOK;
		u8 LOC_u8portNumber = (Copy_enuPinNum >> 4) & 0x0F;
		u8 LOC_u8pinNumber = Copy_enuPinNum & 0x0F;
		// Validate input parameters
		if (IS_INVALID_PORT_NUM(LOC_u8portNumber))
		{
			Ret_enuError = MPORT_enuINVALID_PortNum;
		}
	   else if (IS_INVALID_PIN_NUM(LOC_u8pinNumber))
		{
		  Ret_enuError = MPORT_enuINVALID_PortNum;
		}
		else if (IS_INVALID_PIN_MODE(Copy_enuPinMode))
		{
			Ret_enuError = MPORT_enuINVALID_MODE;
		}
		else
		{
			Ret_enuError = MDIO_enuOK;
			// Get the address of the port registers
			
			MDIO_strPortRegElement_t* Local_strPtrCurrPort =(((MDIO_PORT_REG_BASE_ADD) - (((u8)LOC_u8portNumber) * 3)));
			
			// Configure pin direction and state based on the requested configuration
	     if(Copy_enuPinMode == MDIO_enuINPUT_PULLUP) // Input with pull-up
	     {
		     CLR_BIT(Local_strPtrCurrPort->DDR ,Copy_enuPinNum );
		     SET_BIT(Local_strPtrCurrPort->PORT,Copy_enuPinNum);
		     
	     }
	     else if(Copy_enuPinMode == MDIO_enuINPUT_PULLDOWN) // Input with pull-down
	     {
		     CLR_BIT(Local_strPtrCurrPort->DDR ,Copy_enuPinNum );
		     CLR_BIT(Local_strPtrCurrPort->PORT,Copy_enuPinNum );
	     }
			
		}
		return Ret_enuError;
	
}