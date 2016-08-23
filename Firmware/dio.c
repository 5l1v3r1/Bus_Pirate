/*
 * This file is part of the Bus Pirate project (http://code.google.com/p/the-bus-pirate/).
 *
 * Written and maintained by the Bus Pirate project.
 *
 * To the extent possible under law, the project has
 * waived all copyright and related or neighboring rights to Bus Pirate. This
 * work is published from United States.
 *
 * For details see: http://creativecommons.org/publicdomain/zero/1.0/.
 *
 *    This program is distributed in the hope that it will be useful,
 *    but WITHOUT ANY WARRANTY; without even the implied warranty of
 *    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 */

#include "base.h"

#ifdef BP_USE_DIO

#include "binIO.h"

/**
 * Bit #9 indicates whether it is to set the pin state or the pin direction.
 */
#define DIO_PIN_SET_STATE_FLAG_MASK 0b0000000010000000

void dio_setup(void) {
}

void dio_setup_execute(void) {
}

unsigned int dio_read(void) {
	return PORTB;
}

unsigned int dio_write(unsigned int value) {
    return (value & DIO_PIN_SET_STATE_FLAG_MASK) ? binBBpinset(value) :
        binBBpindirectionset(value);
}

#endif /* BP_USE_DIO */