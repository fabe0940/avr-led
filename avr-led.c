#include <inttypes.h>
#include <stdlib.h>
#include <avr/io.h>
#include <avr/pgmspace.h>
#include "io.h"
#include "state.h"
#include "timer.h"

uint8_t state;
uint8_t delay;
void init(void);

int main(void) {
	init();

	while(1) {
		io_out(PORT_B, io_in(PORT_A));
	}

/*
	while (1) {
		switch (state) 
			case STATE_START:
				break;
			case STATE_PRESS:
				break;
			case STATE_WAIT:
				break;
			case STATE_LED:
				break;
			case STATE_END:
				do nothing
				break;
		}
	}
*/
	
	exit(0);
}

void init(void) {
	state = STATE_START;
}
