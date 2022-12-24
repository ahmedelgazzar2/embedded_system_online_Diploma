/*
 * MemMap.h
 *
 *  Created on: 6 Nov 2022
 *      Author: Dell
 */

#ifndef MEMMAP_H_
#define MEMMAP_H_

#define F_CPU 8000000UL
/******   includes    **********************/

#include"stdint.h"
#include<util/delay.h>
#include"stdio.h"

/******       DIO        *******************/

#define DDRA  *((volatile uint8_t *)(0x3A))
#define PORTA *((volatile uint8_t *)(0x3B))
#define PINA  *((volatile uint8_t *)(0x39))

#define DDRB  *((volatile uint8_t *)(0x37))
#define PORTB *((volatile uint8_t *)(0x38))
#define PINB  *((volatile uint8_t *)(0x36))

#define DDRC  *((volatile uint8_t *)(0x35))
#define PORTC *((volatile uint8_t *)(0x34))
#define PINC  *((volatile uint8_t *)(0x33))

#define DDRD  *((volatile uint8_t *)(0x31))
#define PORTD *((volatile uint8_t *)(0x32))
#define PIND  *((volatile uint8_t *)(0x30))

/**********     UART       *****************/

#define UDR      *((volatile uint8_t*)0x2C)
#define UCSRA    *((volatile uint8_t*)0x2B)
#define UCSRB    *((volatile uint8_t*)0x2A)
#define UCSRC    *((volatile uint8_t*)0x40)
#define UBRRL    *((volatile uint8_t*)0x29)
#define UBRRH    *((volatile uint8_t*)0x40)

#endif /* MEMMAP_H_ */
