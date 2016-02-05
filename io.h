#ifndef _IO_H_
#define _IO_H_

#include <inttypes.h>

#define PORT_A 0
#define PORT_B 1
#define PORT_C 2
#define PORT_D 3

void io_out(uint8_t port, uint8_t val);
uint8_t io_in(uint8_t port);

#endif /* _IO_H_ */
