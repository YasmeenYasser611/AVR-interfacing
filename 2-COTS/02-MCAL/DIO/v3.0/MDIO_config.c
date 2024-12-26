/*
 * MDIO_config.c
 *
 * Created:12/17/2024 1:28:20 PM
 *  Author: Yasmeen
 */ 

#include "MDIO_config.h"
#include "STD_TYPES.h"

/*
 * Configuration values for each pin:
 *   0 - Output
 *   1 - Input Pull-Up
 *   2 - Input Pull-Down
 */

/*
 * This array specifies the configuration for every pin in the system.
 * The array size is MDIO_NUM_OF_PORTS * MDIO_NUM_OF_PINS.
 * 
 * Pin mapping:
 *   - The first 8 entries correspond to PORTA pins (A0 to A7).
 *   - The next 8 entries correspond to PORTB pins (B0 to B7).
 *   - The next 8 entries correspond to PORTC pins (C0 to C7).
 *   - The final 8 entries correspond to PORTD pins (D0 to D7).
 * 
 * Example:
 *   MDIO_enuArrPinConfig[0] -> Configuration for A0.
 *   MDIO_enuArrPinConfig[9] -> Configuration for B1.
 */

u8 MDIO_enuArrPinConfig[MDIO_NUM_OF_PORTS * MDIO_NUM_OF_PINS] =
{
    // PORTA pin configurations
    0,  // A0: Output
    0,  // A1: Output
    0,  // A2: Output
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
    0,  // C0: Output
    0,  // C1: Output
    0,  // C2: Output
    0,  // C3: Output
    0,  // C4: Output
    0,  // C5: Output
    0,  // C6: Output
    1,  // C7: Input Pull-Up

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
