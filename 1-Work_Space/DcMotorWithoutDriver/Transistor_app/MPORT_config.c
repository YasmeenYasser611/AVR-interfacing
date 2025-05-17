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
 *   PIN_OUTPUT - Output
 *   PIN_INPUT_PULLUP - Input Pull-Up
 *    PIN_INPUT_PULLDOWN - Input Pull-Down
 */
#define  PIN_OUTPUT 0
#define  PIN_INPUT_PULLUP 1
#define  PIN_INPUT_PULLDOWN 2

u8 MPORT_enuArrPinConfig[MPORT_NUM_OF_PORTS * MPORT_NUM_OF_PINS] =
{
	// PORTA pin configurations
	PIN_OUTPUT,  // A0: Output for led1
	PIN_OUTPUT,  // A1: Output for led2
	PIN_OUTPUT,  // A2: Output for led3
	PIN_OUTPUT,  // A3: Output
	PIN_OUTPUT,  // A4: Output
	PIN_OUTPUT,  // A5: Output
	PIN_OUTPUT,  // A6: Output
	PIN_OUTPUT,  // A7: Output

	// PORTB pin configurations
	PIN_INPUT_PULLUP,  // B0: Output
	PIN_INPUT_PULLUP,  // B1: Output
	PIN_OUTPUT,  // B2: Output
	PIN_OUTPUT,  // B3: Output
	PIN_OUTPUT,  // B4: Output
	PIN_OUTPUT,  // B5: Output
	PIN_OUTPUT,  // B6: Output
	PIN_OUTPUT,  // B7: Output

	// PORTC pin configurations
	PIN_OUTPUT,  // C0: input pull up
	PIN_OUTPUT,  // C1: input pull up
	PIN_OUTPUT,  // C2: input pull up
	PIN_OUTPUT,  // C3: Output
	PIN_OUTPUT,  // C4: Output
	PIN_OUTPUT,  // C5: Output
	PIN_OUTPUT,  // C6: Output
	PIN_OUTPUT,  // C7: Input Pull-Up

	// PORTD pin configurations
	PIN_OUTPUT,  // D0: Output
	PIN_OUTPUT,  // D1: Output
	PIN_OUTPUT,  // D2: Output
	PIN_OUTPUT,  // D3: Output
	PIN_OUTPUT,  // D4: Output
	PIN_OUTPUT,  // D5: Output
	PIN_OUTPUT,  // D6: Output
	PIN_OUTPUT   // D7: Output
};

