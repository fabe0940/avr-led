#include <inttypes.h>
#include <stdlib.h>
#include <avr/interrupt.h>
#include <avr/io.h>
#include <avr/pgmspace.h>
#include "io.h"
#include "state.h"
#include "timer.h"

uint8_t state;
uint32_t delay;
void init(void);

int main(void) {
	init();

	while (1) {
		switch (state) {
			case STATE_START:
				io_out(PORT_B, 0x00);

				if (io_in(PORT_A)) {
					timer_start();
					state = STATE_PRESS;
				}

				break;
			case STATE_PRESS:
				io_out(PORT_B, 0x00);

				if (!io_in(PORT_A)) {
					timer_end();
					delay = timer;
					timer_start();
					state = STATE_WAIT;
				}

				break;
			case STATE_WAIT:
				io_out(PORT_B, 0x01);

				if (timer >= DELAY_ONE_SECOND) {
					timer_end();
					state = STATE_LED;
					timer_start();
				}

				break;
			case STATE_LED:
				io_out(PORT_B, 0xFF);

				if (timer >= delay) {
					timer_end();
					state = STATE_END;
					timer_start();
				}

				break;
			case STATE_END:
				io_out(PORT_B, 0x00);
				break;
		}
	}
	
	exit(0);
}

void init(void) {
	/* Enable interupts */
	sei();

	state = STATE_START;
}
