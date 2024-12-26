/*
 * MDIO_PRIVATE.h
 *
 * Created:12/17/2024 1:28:20 PM
 *  Author: Yasmeen
 */ 

#ifndef MDIO_PRIVATE_H_
#define MDIO_PRIVATE_H_

/*
 * MDIO_PRIVATE.h
 * This file contains private definitions, macros, and data types for the MDIO driver.
 * These definitions are for internal use only and should not be accessed directly by user code.
 */

/* 
 * NULL Pointer Definition:
 *   Defines a NULL pointer for use in pointer-related operations.
 */
#define NULL ((void*)0)

/* 
 * Base Address of MDIO Port Registers:
 *   The starting memory address of the port registers in the AVR ATmega32 microcontroller.
 *   This address points to PORTA's PIN register and is decremented for accessing other ports.
 */
#define MDIO_PORT_REG_BASE_ADD  ((volatile u8*)(0x39))  // Base address of PORT registers

/* 
 * External Declaration of Pin Configuration Array:
 *   This array defines the configuration of each pin (input, output, pull-up, or pull-down).
 *   The array is defined in another file and used here as a reference.
 */
extern u8 MDIO_enuArrPinConfig[];

/* 
 * Structure for Port Register Elements:
 *   Represents the three registers associated with each port: PIN, DDR, and PORT.
 *   - PIN: Input pins register
 *   - DDR: Data direction register
 *   - PORT: Output register
 */
typedef struct
{
	volatile u8 PIN;   // Input Pins Register
	volatile u8 DDR;   // Data Direction Register
	volatile u8 PORT;  // Output Register
} MDIO_strPortRegElement_t;

/* 
 * Error Status Enumeration:
 *   Lists the possible error statuses returned by MDIO driver functions.
 *   - MDIO_enuOK: Operation successful
 *   - MDIO_enuNOK: Operation failed
 *   - MDIO_enuINVALID_PortNum: Invalid port number
 *   - MDIO_enuINVALID_PinNum: Invalid pin number
 *   - MDIO_enuINVALID_Configration: Invalid pin/port configuration
 *   - MDIO_enuINVALID_PinStatus: Invalid pin status (e.g., HIGH or LOW)
 *   - MDIO_enuINVALID_PortStatus: Invalid port status
 *   - MDIO_enuNULL_PTR: NULL pointer passed as an argument
 */
typedef enum
{
	MDIO_enuOK = 0,
	MDIO_enuNOK,
	MDIO_enuINVALID_PortNum,
	MDIO_enuINVALID_PinNum,
	MDIO_enuINVALID_Configration,
	MDIO_enuINVALID_PinStatus,
	MDIO_enuINVALID_PortStatus,
	MDIO_enuNULL_PTR
} MDIO_enuErrorStatus_t;

/* 
 * Port Number Enumeration:
 *   Enumerates the digital I/O ports available on the ATmega32.
 *   - MDIO_enuPORTA: Port A
 *   - MDIO_enuPORTB: Port B
 *   - MDIO_enuPORTC: Port C
 *   - MDIO_enuPORTD: Port D
 */
typedef enum
{
	MDIO_enuPORTA = 0,
	MDIO_enuPORTB,
	MDIO_enuPORTC,
	MDIO_enuPORTD
} MDIO_enuPortNum_t;

/* 
 * Pin Number Enumeration:
 *   Enumerates the pin numbers (0-7) for each port.
 *   - MDIO_enuPIN0 to MDIO_enuPIN7: Corresponds to pin 0 to pin 7 of a port
 */
typedef enum
{
	MDIO_enuPIN0 = 0,
	MDIO_enuPIN1,
	MDIO_enuPIN2,
	MDIO_enuPIN3,
	MDIO_enuPIN4,
	MDIO_enuPIN5,
	MDIO_enuPIN6,
	MDIO_enuPIN7
} MDIO_enuPinNum_t;

/* 
 * Configuration Enumeration:
 *   Enumerates possible pin/port configurations:
 *   - MDIO_enuOUTPUT: Pin configured as output
 *   - MDIO_enuINPUT_PULLUP: Pin configured as input with pull-up resistor
 *   - MDIO_enuINPUT_PULLDOWN: Pin configured as input with pull-down resistor
 *   - MDIO_enuALL_OUTPUT: All pins configured as output
 *   - MDIO_enuALL_INPUT_PULLUP: All pins configured as input with pull-up resistors
 *   - MDIO_enuALL_INPUT_PULLDOWN: All pins configured as input with pull-down resistors
 */
typedef enum
{
	MDIO_enuOUTPUT = 0,
	MDIO_enuINPUT_PULLUP = 1,
	MDIO_enuINPUT_PULLDOWN = 2,
	MDIO_enuALL_OUTPUT = 0xFF,
	MDIO_enuALL_INPUT_PULLUP = 0x00,
	MDIO_enuALL_INPUT_PULLDOWN = 0x00
} MDIO_enuConfigration_t;

/* 
 * Pin State Enumeration:
 *   Enumerates possible states for a pin:
 *   - MDIO_enuLOW: Pin state is low (0)
 *   - MDIO_enuHIGH: Pin state is high (1)
 */
typedef enum
{
	MDIO_enuLOW = 0,
	MDIO_enuHIGH
} MDIO_enuState_t;

/* 
 * Port State Enumeration:
 *   Enumerates possible states for an entire port:
 *   - MDIO_enuAll_HIGH: All pins in the port are high
 *   - MDIO_enuAll_LOW: All pins in the port are low
 */
typedef enum
{
	MDIO_enuAll_HIGH = 0xFF,
	MDIO_enuAll_LOW = 0x00
} MDIO_enuPortState_t;

#endif /* MDIO_PRIVATE_H_ */
