/*
 * MDIO_config.h
 *
 * Created:12/17/2024 1:28:20 PM
 *  Author: Yasmeen
 */ 

#ifndef MDIO_CONFIG_H_
#define MDIO_CONFIG_H_

/*
 * Configuration file for the MDIO (Microcontroller Digital Input/Output) driver.
 * This file contains the hardware-specific configuration for the AVR ATmega32.
 */

/* 
 * Number of Ports:
 *   The ATmega32 microcontroller has 4 digital I/O ports (PORTA, PORTB, PORTC, and PORTD).
 *   MDIO_NUM_OF_PORTS defines the total number of available ports.
 */
#define MDIO_NUM_OF_PORTS   0x04  // Total number of ports: 4

/*
 * Number of Pins per Port:
 *   Each port on the ATmega32 has 8 digital pins, making it an 8-bit wide port.
 *   MDIO_NUM_OF_PINS defines the total number of pins per port.
 */
#define MDIO_NUM_OF_PINS    0x08  // Total number of pins per port: 8

#endif /* MDIO_CONFIG_H_ */
