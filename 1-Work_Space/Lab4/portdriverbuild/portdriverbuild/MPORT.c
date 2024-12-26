/*
 * MPORT.c
 *
 * Created: 12/26/2024 6:48:09 AM
 *  Author: TUF
 */ 


#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "MPORT.h"
#include "MPORT_config.h"
#include "MPORT_PRIVATE.h"


// Macros to validate inputs

#define IS_INVALID_PORT_NUM(X)			((((MPORT_enuPortNum_t)X) > MPORT_enuPORTD) || (((MPORT_enuPortNum_t)X) < MPORT_enuPORTA))
#define IS_INVALID_PIN_NUM(X)			((((MPORT_enuPinNum_t)X) > MPORT_enuPIN7) || (((MPORT_enuPinNum_t)X) < MPORT_enuPIN0))
#define IS_INVALID_PIN_Direction(X)		((((MPORT_enuPinDirection_t)X) != MPORT_enuPINOUTPUT) && (((MPORT_enuPinDirection_t)X) != MPORT_enuPININPUT))
#define IS_INVALID_PIN_MODE(X)		((((MPORT_enuPinMode_t)X) > MPORT_PIN_MODE_UART) || (((MPORT_enuPinMode_t)X) < MPORT_enuINPUT_PULL_UP))
#define IS_INVALID_PIN_CONFIG(X)		((((MPORT_enuConfigration_t)X) != MPORT_enuOUTPUT) && (((MPORT_enuConfigration_t)X) != MPORT_enuINPUT_PULLUP) && (((MPORT_enuConfigration_t)X) != MPORT_enuINPUT_PULLDOWN))


// Function: MPORT_vPortInit
// Initializes all pins in all ports with their configuration based on MPORT_enuArrPinConfig array.
void MPORT_vPortInit(void)
{
	u8 Local_u8_i;
	MPORT_enuPortNum_t Local_enuCurrentPort;
	MPORT_enuPinNum_t Local_enuCurrentPin;

	// Loop through all pins in all ports and set their configurations
	for (Local_u8_i = 0; Local_u8_i < (MPORT_NUM_OF_PORTS * MPORT_NUM_OF_PINS); Local_u8_i++)
	{
		Local_enuCurrentPort = Local_u8_i / MPORT_NUM_OF_PINS ;  // Determine port number
		Local_enuCurrentPin = Local_u8_i % MPORT_NUM_OF_PINS; // Determine pin number
		MPORT_enuSetPinConfigrationHelp(Local_enuCurrentPort ,Local_enuCurrentPin , MPORT_enuArrPinConfig[Local_u8_i] );
		
	}

}

// Function: MDIO_enuSetPinConfigration
// Sets the configuration of a specific pin in a given port it is helper function foor the initialization and the user will not use it.
MPORT_enuErrorStatus_t MPORT_enuSetPinConfigrationHelp(MPORT_enuPortNum_t Copy_enuPortNum,MPORT_enuPinNum_t Copy_enuPinNum,MPORT_enuConfigration_t Copy_enuConfigration)
{
	
	MPORT_enuErrorStatus_t Ret_enuError= MPORT_enuOK;
	// Validate input parameters
	if (IS_INVALID_PORT_NUM(Copy_enuPortNum))
	{
		Ret_enuError = MPORT_enuINVALID_PortNum;
		
	}
	else if (IS_INVALID_PIN_NUM(Copy_enuPinNum))
	{
		Ret_enuError = MPORT_enuINVALID_PinNum;
	}
	else if (IS_INVALID_PIN_CONFIG(Copy_enuConfigration))
	{
		Ret_enuError = MPORT_enuINVALID_PinConf;
	}
	else
	{
		Ret_enuError = MPORT_enuOK;
		// Get the address of the port registers
		MPORT_strPortRegElement_t* Local_strPtrCurrPort =(((MPORT_PORT_REG_BASE_ADD) - (((u8)Copy_enuPortNum) * 3)));
		// Configure pin direction and state based on the requested configuration
		if(Copy_enuConfigration == MPORT_enuOUTPUT)// Output mode
		{
			SET_BIT(Local_strPtrCurrPort->DDR,Copy_enuPinNum);
		}
		else if(Copy_enuConfigration == MPORT_enuINPUT_PULLUP) // Input with pull-up
		{
			CLR_BIT(Local_strPtrCurrPort->DDR ,Copy_enuPinNum );
			SET_BIT(Local_strPtrCurrPort->PORT,Copy_enuPinNum);
			
		}
		else if(Copy_enuConfigration == MPORT_enuINPUT_PULLDOWN) // Input with pull-down
		{
			CLR_BIT(Local_strPtrCurrPort->DDR ,Copy_enuPinNum );
			CLR_BIT(Local_strPtrCurrPort->PORT,Copy_enuPinNum );
		}

	}
	return Ret_enuError;
	
}


// Function: MPORT_enuSetPinDirection
// Sets the direction of any pin after the initialization.
MPORT_enuErrorStatus_t MPORT_enuSetPinDirection( MPORT_enuPinNums_t Copy_enuPinNum  ,  MPORT_enuPinDirection_t  Copy_enuPinDirection  )
{
	MPORT_enuErrorStatus_t Ret_enuError= MPORT_enuOK;
	u8 LOC_u8portNumber = (Copy_enuPinNum >> 4) & 0x0F;
	u8 LOC_u8pinNumber = Copy_enuPinNum & 0x0F;
	// Validate input parameters
	if (IS_INVALID_PORT_NUM(LOC_u8portNumber))
	{
		Ret_enuError = MPORT_enuINVALID_PortNum;
		
	}
	else if (IS_INVALID_PIN_NUM(LOC_u8pinNumber))
	{
		Ret_enuError = MPORT_enuINVALID_PinNum;
	}
	else if (IS_INVALID_PIN_Direction(Copy_enuPinDirection))
	{
		Ret_enuError = MPORT_enuINVALID_PinDirection;
	}
	else
	{
		Ret_enuError = MPORT_enuOK;
		// Get the address of the port registers
		MPORT_strPortRegElement_t* Local_strPtrCurrPort =(((MPORT_PORT_REG_BASE_ADD) - (((u8)LOC_u8portNumber) * 3)));
		// Configure pin direction and state based on the requested configuration
		if(Copy_enuPinDirection == MPORT_enuPINOUTPUT)// Output 
		{
			SET_BIT(Local_strPtrCurrPort->DDR,LOC_u8pinNumber);
		}
		else if(Copy_enuPinDirection == MPORT_enuPININPUT) // Input 
		{
			CLR_BIT(Local_strPtrCurrPort->DDR ,LOC_u8pinNumber );
			CLR_BIT(Local_strPtrCurrPort->PORT,LOC_u8pinNumber);
			
		}
	
	}
	return Ret_enuError;
		
		
}


// Function: MPORT_enuSetPinMode
// set alternative mode to the pin.
MPORT_enuErrorStatus_t MPORT_enuSetPinMode( MPORT_enuPinNums_t Copy_enuPinNum  ,  MPORT_enuPinMode_t Copy_enuPinMode )
{
		MPORT_enuErrorStatus_t Ret_enuError= MPORT_enuOK;
		u8 LOC_u8portNumber = (Copy_enuPinNum >> 4) & 0x0F;
		u8 LOC_u8pinNumber = Copy_enuPinNum & 0x0F;
		// Validate input parameters
		if (IS_INVALID_PORT_NUM(LOC_u8portNumber))
		{
			Ret_enuError = MPORT_enuINVALID_PortNum;
			
		}
		else if (IS_INVALID_PIN_NUM(LOC_u8pinNumber))
		{
			Ret_enuError = MPORT_enuINVALID_PinNum;
		}
		else if (IS_INVALID_PIN_MODE(Copy_enuPinMode))
		{
			Ret_enuError = MPORT_enuINVALID_PinMode;
		}
		else
		{
			Ret_enuError = MPORT_enuOK;
			// Get the address of the port registers
			MPORT_strPortRegElement_t* Local_strPtrCurrPort =(((MPORT_PORT_REG_BASE_ADD) - (((u8)LOC_u8portNumber) * 3)));
			// Configure pin direction and state based on the requested configuration
			if(MPORT_enuINVALID_PinMode == MPORT_enuINPUT_PULL_UP)// pull up
			{
			    CLR_BIT(Local_strPtrCurrPort->DDR ,LOC_u8pinNumber );
				SET_BIT(Local_strPtrCurrPort->PORT,LOC_u8pinNumber);
			}
			else if(MPORT_enuINVALID_PinMode == MPORT_enuINPUT_PULL_DOWN) // Input with pull-down
			{
				CLR_BIT(Local_strPtrCurrPort->DDR ,LOC_u8pinNumber );
				CLR_BIT(Local_strPtrCurrPort->PORT,LOC_u8pinNumber);
				
			}
			else if(MPORT_enuINVALID_PinMode ==MPORT_PIN_MODE_UART)
			{
				// wait tell we take uart then comlete it
			}
			
		}
		return Ret_enuError;
	
}


