/*
 * MPORT_PRIVATE.h
 *
 * Created: 12/25/2024 1:56:43 PM
 *  Author: TUF
 */ 


#ifndef MPORT_PRIVATE_H_
#define MPORT_PRIVATE_H_


#define NULL ((void*)0)

#define PIN_A0 0x00
#define PIN_A1 0x01
#define PIN_A2 0x02
#define PIN_A3 0x03
#define PIN_A4 0x04
#define PIN_A5 0x05
#define PIN_A6 0x06
#define PIN_A7 0x07

#define PIN_B0 0x10
#define PIN_B1 0x11
#define PIN_B2 0x12
#define PIN_B3 0x13
#define PIN_B4 0x14
#define PIN_B5 0x15
#define PIN_B6 0x16
#define PIN_B7 0x17


#define PIN_C0 0x20
#define PIN_C1 0x21
#define PIN_C2 0x22
#define PIN_C3 0x23
#define PIN_C4 0x24
#define PIN_C5 0x25
#define PIN_C6 0x26
#define PIN_C7 0x27


#define PIN_D0 0x30
#define PIN_D1 0x31
#define PIN_D2 0x32
#define PIN_D3 0x33
#define PIN_D4 0x34
#define PIN_D5 0x35
#define PIN_D6 0x36
#define PIN_D7 0x37

#define MPORT_PORT_REG_BASE_ADD  ((volatile u8*)(0x39))  // Base address of PORT registers

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


typedef enum
{
	MPORT_enuOK = 0,
	MPORT_enuNOK ,
	MPORT_enuINVALID_MODE ,
	MPORT_enuINVALID_PinNum ,
	MPORT_enuINVALID_PortNum ,
	MPORT_enuINVALID_PINConfigration
	
} MPORT_enuErrorStatus_t;



typedef enum
{
	
	MPORT_enuINPUT_PULL_UP=0 ,
	MPORT_enuINPUT_PULL_DOWN ,
	MPORT_PIN_MODE_UART
	
	
} MPORT_enuPinMode_t;

/*
to initialize all pins in all ports
*/



typedef enum
{
	MDIO_enuOUTPUT = 0,
	MDIO_enuINPUT = 1
	
} MPORT_enuPINConfigration_t;


#endif /* MPORT_PRIVATE_H_ */