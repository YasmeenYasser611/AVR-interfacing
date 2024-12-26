/*
 * MDIO.h
 *
 * Created: 12/17/2024 1:28:39 PM
 *  Author: Yasmeen
 */ 


#ifndef MDIO_H_
#define MDIO_H_

#include "STD_TYPES.h"
#include "MDIO_PRIVATE.h"



/*
to initialize all pins in all ports
*/
void MDIO_voidInit(void);


/*
Purpose:
This API configures a specific pin within a port with the desired functionality, such as input, output, or pull-up/down configuration. It allows precise control over individual pins in a microcontroller's GPIO.

Parameters:

Copy_enuPortNum:
Specifies the port containing the pin to configure (e.g., MDIO_enuPORTA, MDIO_enuPORTB, MDIO_enuPORTC, MDIO_enuPORTD).

Copy_enuPinNum:
Specifies the pin within the port to configure (e.g., MDIO_enuPIN0, MDIO_enuPIN1, MDIO_enuPIN2, MDIO_enuPIN3,MDIO_enuPIN4,MDIO_enuPIN5,MDIO_enuPIN6,MDIO_enuPIN7,MDIO_enuPIN8).

Copy_enuConfigration:
Specifies the desired configuration for the pin. Examples:
MDIO_enuOUTPUT,MDIO_enuINPUT_PULLUP,MDIO_enuINPUT_PULLDOWN
Return:
MDIO_enuOK, MDIO_enuNOK, MDIO_enuINVALID_PortNum , MDIO_enuINVALID_PinNum ,MDIO_enuINVALID_Configration 
*/
MDIO_enuErrorStatus_t MDIO_enuSetPinConfigration(MDIO_enuPortNum_t Copy_enuPortNum,MDIO_enuPinNum_t Copy_enuPinNum,MDIO_enuConfigration_t Copy_enuConfigration);
/*
Purpose:
This API configures all pins in a specific port at once, saving time when multiple pins need the same configuration (e.g., all as inputs or outputs).

Parameters:

Copy_enuPortNum:
Specifies the port to configure  (e.g., MDIO_enuPORTA, MDIO_enuPORTB, MDIO_enuPORTC, MDIO_enuPORTD).

Copy_enuConfigration:
Specifies the configuration to apply to all pins in the port (MDIO_enuALL_OUTPUT, MDIO_enuALL_INPUT_PULLUP, MDIO_enuALL_INPUT_PULLDOWN).
Return:
MDIO_enuOK, MDIO_enuINVALID_PortNum, MDIO_enuNOK , MDIO_enuINVALID_Configration
*/
MDIO_enuErrorStatus_t MDIO_enuSetPortConfigration(MDIO_enuPortNum_t Copy_enuPortNum,MDIO_enuConfigration_t Copy_enuConfigration);
/*
Purpose:
This API sets the logical state of a specific pin (e.g., HIGH or LOW).

Parameters:

Copy_enuPortNum:
Specifies the port containing the pin  (e.g., MDIO_enuPORTA, MDIO_enuPORTB, MDIO_enuPORTC, MDIO_enuPORTD).

Copy_enuPinNum:
Specifies the pin within the port to set (e.g., MDIO_enuPIN0, MDIO_enuPIN1, MDIO_enuPIN2, MDIO_enuPIN3,MDIO_enuPIN4,MDIO_enuPIN5,MDIO_enuPIN6,MDIO_enuPIN7,MDIO_enuPIN8).

Copy_enuState:
Specifies the desired state for the pin: MDIO_enuLOW,MDIO_enuHIGH
Return:
MDIO_enuOK, MDIO_enuINVALID_PortNum, MDIO_enuNOK , MDIO_enuINVALID_PinStatus , MDIO_enuINVALID_PinNum .

*/
MDIO_enuErrorStatus_t MDIO_enuSetPinValue( MDIO_enuPortNum_t Copy_enuPortNum, MDIO_enuPinNum_t Copy_enuPinNum, MDIO_enuState_t Copy_enuState);
/*
Purpose:
This API sets the logical states of all pins in a specified port at once, which is useful for initializing or modifying the state of a port efficiently.
Parameters:

Copy_enuPortNum:
Specifies the port to modify  (e.g., MDIO_enuPORTA, MDIO_enuPORTB, MDIO_enuPORTC, MDIO_enuPORTD).

Copy_enuPortState:
Specifies the collective state for all pins in the port (MDIO_enuAll_HIGH, MDIO_enuAll_LOW).
Return:
MDIO_enuOK, MDIO_enuINVALID_PortStatus, MDIO_enuNOK , MDIO_enuINVALID_PortNum .


*/
MDIO_enuErrorStatus_t MDIO_enuSetPortValue(MDIO_enuPortNum_t Copy_enuPortNum,MDIO_enuPortState_t Copy_enuPortState);
/*
Purpose:
This API retrieves the logical state (HIGH or LOW) of a specific pin.

Copy_enuPortNum:
Specifies the port containing the pin to read  (e.g., MDIO_enuPORTA, MDIO_enuPORTB, MDIO_enuPORTC, MDIO_enuPORTD).

Copy_enuPinNum:
Specifies the pin within the port to read (e.g., MDIO_enuPIN0, MDIO_enuPIN1, MDIO_enuPIN2, MDIO_enuPIN3,MDIO_enuPIN4,MDIO_enuPIN5,MDIO_enuPIN6,MDIO_enuPIN7,MDIO_enuPIN8).

Add_pu8PinValue:
Pointer to store the retrieved pin value.

Return: MDIO_enuOK, MDIO_enuINVALID_PortStatus, MDIO_enuINVALID_PinNum, MDIO_enuNOK , MDIO_enuNULL_PTR .

*/
MDIO_enuErrorStatus_t MDIO_enuGetPinValue(MDIO_enuPortNum_t Copy_enuPortNum,MDIO_enuPinNum_t Copy_enuPinNum,u8* Add_pu8PinValue); 





#endif /* MDIO_H_ */