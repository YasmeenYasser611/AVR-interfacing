/*
 * MPORT_PRIVATE.h
 *
 * Created: 12/26/2024 9:55:54 AM
 *  Author: TUF
 */ 


#ifndef MPORT_PRIVATE_H_
#define MPORT_PRIVATE_H_


/* 
 * Base Address of MDIO Port Registers:
 *   The starting memory address of the port registers in the AVR ATmega32 microcontroller.
 *   This address points to PORTA's PIN register and is decremented for accessing other ports.
 */
#define MPORT_PORT_REG_BASE_ADD  ((volatile u8*)(0x39))  // Base address of PORT registers
/* 
 * External Declaration of Pin Configuration Array:
 *   This array defines the configuration of each pin (input, output, pull-up, or pull-down).
 *   The array is defined in another file and used here as a reference.
 */
extern u8 MPORT_enuArrPinConfig[];

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
} MPORT_strPortRegElement_t;

/* 
 * Error Status Enumeration:
 *   Lists the possible error statuses returned by MDIO driver functions.
 */
typedef enum
{
	MPORT_enuOK = 0,
	MPORT_enuNOK,
	MPORT_enuINVALID_PortNum,
	MPORT_enuINVALID_PinNum,
	MPORT_enuINVALID_PinDirection,
	MPORT_enuINVALID_PinMode ,
	MPORT_enuINVALID_PinConf
	
} MPORT_enuErrorStatus_t;


/* 
 * Port Number Enumeration:
 *   Enumerates the digital I/O ports available on the ATmega32.
 *  MPORT_enuPIN_A0 = portA + PIN 0
 */
typedef enum
{
	MPORT_enuPIN_A0=0x00 ,
	MPORT_enuPIN_A1=0x01 ,
	MPORT_enuPIN_A2=0x02,
	MPORT_enuPIN_A3=0x03,
	MPORT_enuPIN_A4=0x04,
	MPORT_enuPIN_A5=0x05,
	MPORT_enuPIN_A6=0x06,
	MPORT_enuPIN_A7=0x07,

	MPORT_enuPIN_B0=0x10 ,
	MPORT_enuPIN_B1=0x11,
	MPORT_enuPIN_B2=0x12,
	MPORT_enuPIN_B3=0x13,
	MPORT_enuPIN_B4=0x14,
	MPORT_enuPIN_B5=0x15,
	MPORT_enuPIN_B6=0x16,
	MPORT_enuPIN_B7=0x17,


	MPORT_enuPIN_C0=0x20 ,
	MPORT_enuPIN_C1=0x21,
	MPORT_enuPIN_C2=0x22,
	MPORT_enuPIN_C3=0x23,
	MPORT_enuPIN_C4=0x24,
	MPORT_enuPIN_C5=0x25,
	MPORT_enuPIN_C6=0x26,
	MPORT_enuPIN_C7=0x27,


	MPORT_enuPIN_D0=0x30 ,
	MPORT_enuPIN_D1=0x31,
	MPORT_enuPIN_D2=0x32,
	MPORT_enuPIN_D3=0x33,
	MPORT_enuPIN_D4=0x34,
	MPORT_enuPIN_D5=0x35,
	MPORT_enuPIN_D6=0x36,
	MPORT_enuPIN_D7=0x37
	
} MPORT_enuPinNums_t;


/* 
 * Pin direction Enumeration:
 *   Enumerates possible direction for a pin output or input
 */
typedef enum
{
	MPORT_enuPINOUTPUT = 0,
	MPORT_enuPININPUT = 1
	
} MPORT_enuPinDirection_t;


/* 
 * Pin mode Enumeration:
 *   Enumerates possible mode for a pin
 */
typedef enum
{
	
	MPORT_enuINPUT_PULL_UP=0 ,
	MPORT_enuINPUT_PULL_DOWN ,
	MPORT_PIN_MODE_UART
	
	
} MPORT_enuPinMode_t;

/* 
 * Port Number Enumeration:
 *   Enumerates the digital I/O ports available on the ATmega32.
 */
typedef enum
{
	MPORT_enuPORTA = 0,
	MPORT_enuPORTB,
	MPORT_enuPORTC,
	MPORT_enuPORTD
} MPORT_enuPortNum_t;


/* 
 * Pin Number Enumeration:
 *   Enumerates the pin numbers (0-7) for each port.
 */
typedef enum
{
	MPORT_enuPIN0 = 0,
	MPORT_enuPIN1,
	MPORT_enuPIN2,
	MPORT_enuPIN3,
	MPORT_enuPIN4,
	MPORT_enuPIN5,
	MPORT_enuPIN6,
	MPORT_enuPIN7
} MPORT_enuPinNum_t;

/* 
 * Configuration Enumeration:
 *   Enumerates possible pin/port configurations
 */
typedef enum
{
	MPORT_enuOUTPUT = 0,
	MPORT_enuINPUT_PULLUP = 1,
	MPORT_enuINPUT_PULLDOWN = 2,
} MPORT_enuConfigration_t;


/* 
 * helper function used in initialization 
 */
MPORT_enuErrorStatus_t MPORT_enuSetPinConfigrationHelp(MPORT_enuPortNum_t Copy_enuPortNum,MPORT_enuPinNum_t Copy_enuPinNum,MPORT_enuConfigration_t Copy_enuConfigration);

#endif /* MPORT_PRIVATE_H_ */