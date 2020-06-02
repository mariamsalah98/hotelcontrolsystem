#ifndef UART_H_INCLUDED
#define UART_H_INCLUDED

#include "common_macros.h"
#include "stdint.h"
#include "C:\Keil_v5\EE319Kware\inc/tm4c123gh6pm.h"

#ifndef CLOCK
#define CLOCK 16000000UL
#endif // F_CPU



#define UART_BAUDRATE 9600


void UART_init(void);

void printchar(const uint8_t data);

uint8_t recievebyte(void);

void printstring(const char *Str);


#endif /* UART_H_ */


