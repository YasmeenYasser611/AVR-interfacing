/*
 * MPORT_config.c
 *
 * Created: 12/26/2024 6:23:23 AM
 *  Author: TUF
 */ 
#include "MPORT_config.h"
#include "STD_TYPES.h"


/*This array specifies the configuration for every pin in the system.
 * Configuration values for each pin:
 *   0 - Output
 *   1 - Input Pull-Up
 *   2 - Input Pull-Down
 */

u8 MPORT_enuArrPinConfig[MPORT_NUM_OF_PORTS * MPORT_NUM_OF_PINS] =
{
	// PORTA pin configurations
	0,  // A0: Output for led1
	0,  // A1: Output for led2
	0,  // A2: Output for led3
	0,  // A3: Output
	0,  // A4: Output
	0,  // A5: Output
	0,  // A6: Output
	0,  // A7: Output

	// PORTB pin configurations
	0,  // B0: Output
	0,  // B1: Output
	0,  // B2: Output
	0,  // B3: Output
	0,  // B4: Output
	0,  // B5: Output
	0,  // B6: Output
	0,  // B7: Output

	// PORTC pin configurations
	0,  // C0: input pull up
	0,  // C1: input pull up
	0,  // C2: input pull up
	0,  // C3: Output
	0,  // C4: Output
	0,  // C5: Output
	0,  // C6: Output
	0,  // C7: Input Pull-Up

	// PORTD pin configurations
	0,  // D0: Output
	0,  // D1: Output
	0,  // D2: Output
	0,  // D3: Output
	0,  // D4: Output
	0,  // D5: Output
	0,  // D6: Output
	0   // D7: Output
};

