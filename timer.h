#ifndef _TIMER_H_
#define _TIMER_H_

#include <inttypes.h>

#define DELAY_ONE_SECOND 24

volatile uint32_t timer;
void timer_start(void);
void timer_end(void);

#endif /* _TIMER_H_ */
