/*
 * MPORT.h
 *
 * Created: 12/26/2024 6:26:47 AM
 *  Author: TUF
 */ 


#ifndef MPORT_H_
#define MPORT_H_
#include "STD_TYPES.h"
#include "MPORT_PRIVATE.h"



/*
to initialize all pins in all ports
*/
void MPORT_vPortInit(void);


/*
Purpose:
The Port_SetPinDirection API is part of the AUTOSAR Port Driver module. it allows you to change the direction of a specific microcontroller pin at runtime.
Pin direction determines whether the pin:

Acts as an input  (reads data/signals from external devices).
Acts as an output (sends data/signals to external devices).

Parameters:

Copy_enuPinNum:
Typically defined using a combination of the port and pin numbers (e.g., 0x10 might represent Pin 0 on Port B in an 8-bit architecture).
Example : #define PIN_A0 0x00 // Port A, Pin 0      ,   #define PIN_C3  0x23 // Port C, Pin 3

Copy_enuPinDirection:
Specifies the desired configuration for the pin. Examples:
OUTPUT,INPUT.

Return:
MPORT_OK, MPORT_ERROR_INVALID_PIN, MPORT_NOK,MPORT_ERROR_INVALID_DIRECTION.

Example :
MPORT_enuSetPinDirection(PIN_A0 , OUTPUT);



*/
MPORT_enuErrorStatus_t MPORT_enuSetPinDirection( MPORT_enuPinNums_t Copy_enuPinNum  ,  MPORT_enuPinDirection_t  Copy_enuPinDirection  );


/*
Purpose :
The Port_SetPinMode function is part of the AUTOSAR Port Driver module. Its primary purpose is to configure the mode of a specific pin during runtime.
The mode determines the pin's behavior -> digital communication pin (e.g., UART, SPI), or if it uses internal pull-up or pull-down resistors.


Parmeters:

Copy_enuPinNum:
Typically defined using a combination of the port and pin numbers (e.g., 0x10 might represent Pin 0 on Port B in an 8-bit architecture).
Example : #define PIN_A0 0x00 // Port A, Pin 0      ,   #define PIN_C3  0x23 // Port C, Pin 3

Copy_enuPinMode:

Specifies the mode to be set for the pin.

Examples of possible modes (depending on microcontroller configuration):
PORT_PIN_MODE_INPUT_PULLUP  : Input with internal pull-up resistor.
PORT_PIN_MODE_INPUT_PULLDOWN: Input with pull-down resistor.
PORT_PIN_MODE_UART          : UART communication mode.
.
.
.

Return:
MPORT_OK, MPORT_ERROR_INVALID_PIN , MPORT_NOK , MPORT_ERROR_INVALID_MODE, MPORT_ERROR_UNCHANGEABLE_MODE .

Example :
MPORT_enuSetPinMode(PIN_A0 ,PORT_PIN_MODE_INPUT_PULLDOWN);
*/
MPORT_enuErrorStatus_t MPORT_enuSetPinMode( MPORT_enuPinNums_t Copy_enuPinNum  ,  MPORT_enuPinMode_t Copy_enuPinMode );




#endif /* MPORT_H_ */