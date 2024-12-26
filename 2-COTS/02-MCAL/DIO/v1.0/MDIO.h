/*
 * MDIO.h
 *
 * Created: 12/17/2024 1:28:39 PM
 *  Author: TUF
 */ 


#ifndef MDIO_H_
#define MDIO_H_

#include "STD_TYPES.h"
#define NULL ((void*)0)


typedef enum
{
	MDIO_enuOK=0 ,
	MDIO_enuNOK ,
	MDIO_enuINVALID_PortNum,
	MDIO_enuINVALID_PinNum,
	MDIO_enuINVALID_Configration,
	MDIO_enuINVALID_PinStatus ,
	MDIO_enuINVALID_PortStatus,	
	MDIO_enuNULL_PTR
	
}MDIO_enuErrorStatus_t;
typedef enum
{
	MDIO_enuPORTA=0 ,
	MDIO_enuPORTB ,
	MDIO_enuPORTC ,
	MDIO_enuPORTD

}MDIO_enuPortNum_t;
typedef enum
{
	MDIO_enuPIN0 =0 ,
	MDIO_enuPIN1 ,
	MDIO_enuPIN2 ,
	MDIO_enuPIN3 ,
	MDIO_enuPIN4 ,
	MDIO_enuPIN5 ,
	MDIO_enuPIN6 ,
	MDIO_enuPIN7 
}MDIO_enuPinNum_t;
typedef enum
{
	MDIO_enuOUTPUT=0  ,
	MDIO_enuINPUT_PULLUP ,
	MDIO_enuINPUT_PULLDOWN ,
	MDIO_enuALL_OUTPUT = 0xFF  ,
	MDIO_enuALL_INPUT_PULLUP =0x00 ,
	MDIO_enuALL_INPUT_PULLDOWN = 0x00 
	
	
	
}MDIO_enuConfigration_t;
typedef enum
{
	MDIO_enuLOW =0 ,
	MDIO_enuHIGH  
	 
	
}MDIO_enuState_t;
typedef enum
{
	MDIO_enuAll_HIGH = 0xFF ,
	MDIO_enuAll_LOW = 0x00 
	
	
}MDIO_enuPortState_t;

/*
Purpose:
This API configures a specific pin within a port with the desired functionality, such as input, output, or pull-up/down configuration. It allows precise control over individual pins in a microcontroller's GPIO.

Parameters:

Copy_enuPortNum:
Specifies the port containing the pin to configure (e.g., PORTA, PORTB, PORTC, etc.).

Copy_enuPinNum:
Specifies the pin within the port to configure (e.g., PIN0, PIN1, PIN2, etc.).

Copy_enuConfigration:
Specifies the desired configuration for the pin. Examples:
OUTPUT,INPUT_PULLUP,INPUT_PULLDOWN
Return:
MDIO_OK, MDIO_INVALID_PARAM, MDIO_NOK .........
*/
MDIO_enuErrorStatus_t MDIO_enuSetPinConfigration(MDIO_enuPortNum_t Copy_enuPortNum,MDIO_enuPinNum_t Copy_enuPinNum,MDIO_enuConfigration_t Copy_enuConfigration);
/*
Purpose:
This API configures all pins in a specific port at once, saving time when multiple pins need the same configuration (e.g., all as inputs or outputs).

Parameters:

Copy_enuPortNum:
Specifies the port to configure (e.g., PORTA, PORTB, PORTC, etc.).

Copy_enuConfigration:
Specifies the configuration to apply to all pins in the port (e.g., all INPUT, all OUTPUT).
Return:
MDIO_OK, MDIO_INVALID_PARAM, MDIO_NOK .........
*/
MDIO_enuErrorStatus_t MDIO_enuSetPortConfigration(MDIO_enuPortNum_t Copy_enuPortNum,MDIO_enuConfigration_t Copy_enuConfigration);
/*
Purpose:
This API sets the logical state of a specific pin (e.g., HIGH or LOW).

Parameters:

Copy_enuPortNum:
Specifies the port containing the pin (e.g., PORTA, PORTB, etc.).

Copy_enuPinNum:
Specifies the pin within the port to set (e.g., PIN0, PIN1, PIN2, etc.).

Copy_enuState:
Specifies the desired state for the pin: HIGH,LOW
Return:
MDIO_OK, MDIO_INVALID_PARAM, MDIO_NOK .........

*/
MDIO_enuErrorStatus_t MDIO_enuSetPinValue( MDIO_enuPortNum_t Copy_enuPortNum, MDIO_enuPinNum_t Copy_enuPinNum, MDIO_enuState_t Copy_enuState);
/*
Purpose:
This API sets the logical states of all pins in a specified port at once, which is useful for initializing or modifying the state of a port efficiently.
Parameters:

Copy_enuPortNum:
Specifies the port to modify (e.g., PORTA, PORTB, etc.).

Copy_enuPortState:
Specifies the collective state for all pins in the port (e.g. all HIGH, all LOW).
Return:
MDIO_OK, MDIO_INVALID_PARAM, MDIO_NOK .........

Example: MDIO_enuSetPortValue(PORTC, all HIGH);


*/
MDIO_enuErrorStatus_t MDIO_enuSetPortValue(MDIO_enuPortNum_t Copy_enuPortNum,MDIO_enuPortState_t Copy_enuPortState);
/*
Purpose:
This API retrieves the logical state (HIGH or LOW) of a specific pin.

Copy_enuPortNum:
Specifies the port containing the pin to read (e.g., PORTA, PORTB, etc.).

Copy_enuPinNum:
Specifies the pin within the port to read (e.g., PIN0, PIN1, PIN2, etc.).

Add_pu8PinValue:
Pointer to store the retrieved pin value.

Return: MDIO_OK, MDIO_INVALID_PARAM, MDIO_NULL_PTR, MDIO_NOK.........
Example: MDIO_enuGetPinValue(PORTA, PIN1, &pinValue);
*/
MDIO_enuErrorStatus_t MDIO_enuGetPinValue(MDIO_enuPortNum_t Copy_enuPortNum,MDIO_enuPinNum_t Copy_enuPinNum,u8* Add_pu8PinValue); 





#endif /* MDIO_H_ */