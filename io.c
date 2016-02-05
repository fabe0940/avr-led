#include <inttypes.h>
#include <avr/io.h>
#include "io.h"

void io_out(uint8_t port, uint8_t val) {
	switch(port) {
		case PORT_A:
			DDRA = 0xFF;
			PORTA = ~val;
			break;
		case PORT_B:
			DDRB = 0xFF;
			PORTB = ~val;
			break;
		case PORT_C:
			DDRC = 0xFF;
			PORTC = ~val;
			break;
		case PORT_D:
			DDRD = 0xFF;
			PORTD = ~val;
			break;
	}

	return;
}

uint8_t io_in(uint8_t port) {
	uint8_t res;

	switch(port) {
		case PORT_A:
			DDRA = 0x00;
			res = ~PINA;
			break;
		case PORT_B:
			DDRB = 0x00;
			res = ~PINB;
			break;
		case PORT_C:
			DDRC = 0x00;
			res = ~PINC;
			break;
		case PORT_D:
			DDRD = 0x00;
			res = ~PIND;
			break;
	}

	return res;
}
