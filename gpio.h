#ifndef GPIO_H
#define GPIO_H

#include "common_macros.h"
#include "stdint.h"
#include "C:\Keil_v5\EE319Kware\inc/tm4c123gh6pm.h"

#ifndef CLOCK
#define CLOCK 16000000UL
#endif // F_CPU
#define u8 unsigned char 
#define Pin0 0
#define Pin1 1
#define Pin2 2
#define Pin3 3
#define Pin4 4
#define Pin5 5
#define Pin6 6
#define Pin7 7

#define Port_A 0
#define Port_B 1
#define Port_C 2
#define Port_D 3
#define Port_E 4
#define Port_F 5

#define HIGH 1
#define LOW 0

#define INPUT 0
#define OUTPUT 1


#endif
void GPIO_clkEnable(u8 Port) ;
void GPIO_init(u8 Port);
void GPIO_setPortDirection(u8 Port , u8 directions);
void GPIO_setPinDirection(u8 Port , u8 Pin , u8 direction);
void GPIO_setPullUpResistor(u8 Port , u8 value);
void GPIO_setPinValue(u8 Port , u8 Pin , u8 value);
void GPIO_setPortValue(u8 Port , u8 value);
void GPIO_getPinValue(u8 Port , u8 Pin , u8* level);
