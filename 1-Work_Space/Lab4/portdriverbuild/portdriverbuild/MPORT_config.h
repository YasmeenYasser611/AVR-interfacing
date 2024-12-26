/*
 * MPORT_config.h
 *
 * Created: 12/26/2024 6:20:53 AM
 *  Author: TUF
 */ 


#ifndef MPORT_CONFIG_H_
#define MPORT_CONFIG_H_


/* 
 * Number of Ports:
 *   The ATmega32 microcontroller has 4 digital I/O ports (PORTA, PORTB, PORTC, and PORTD).
 *   MPORT_NUM_OF_PORTS defines the total number of available ports.
 */
#define MPORT_NUM_OF_PORTS   0x04  // Total number of ports: 4


/*
 * Number of Pins per Port:
 *   Each port on the ATmega32 has 8 digital pins, making it an 8-bit wide port.
 *   MPORT_NUM_OF_PINS defines the total number of pins per port.
 */
#define MPORT_NUM_OF_PINS    0x08  // Total number of pins per port: 8


#endif /* MPORT_CONFIG_H_ */