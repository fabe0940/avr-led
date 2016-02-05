#include <avr/io.h>
#include <avr/interrupt.h>
#include "timer.h"

void timer_start(void) {
	/* Set timer prescaler to FCPU/256 */
	TCCR0 |= ((1 << CS02) | (0 << CS01) | (0 << CS00));

	/* Enable overflow interrupt */
	TIMSK |= (1 << TOIE0);

	/* Initialize timer register */
	TCNT0 = 0x00;

	/* Initialize overflow counter */
	timer = 0;

	return;
}

void timer_end(void) {
	/* Disable overflow interrupt */
	TIMSK |= (0 << TOIE0);

	return;
}

ISR(TIMER0_OVF_vect) {
	/* Interrupt service routine for TIME0 OVERFLOW interrupt */

	timer++;

	return;
}
