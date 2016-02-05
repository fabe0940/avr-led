#include <inttypes.h>
#include <stdlib.h>
#include <avr/io.h>
#include <avr/pgmspace.h>

int i;

void delay (unsigned int dly) {
	for(i = dly; i != 0; i--) ;
}


int main(void) {
	uint8_t cnt;

	DDRB = 0xff;

	while (1)
	for ( cnt=0; cnt <= 0xff; cnt++ ) {
		PORTB = ~cnt;
		delay(65000U);
	}
	
	exit(0);
}
