/*
 * main.c
 *
 *  Created on: 27 Oct 2022
 *      Author: Ahmed ELgazzar
 */

#define F_CPU 8000000ul
#include "util/delay.h"
#include <avr/io.h>
#include <avr/interrupt.h>

#define IO_Base 0x20
#define IO_PORTD  *(volatile unsigned int*)(IO_Base + 0x12)
#define IO_DDRD   *(volatile unsigned int*)(IO_Base + 0x11)
#define INT_MCUCR *(volatile unsigned int*)(IO_Base + 0x35)
#define INT_GICR  *(volatile unsigned int*)(IO_Base + 0x3B)
#define INT_MCUCSR *(volatile unsigned int*)(IO_Base + 0x34)
#define INT_SREG  *(volatile unsigned int*)(IO_Base + 0x3F)

int main(void)
{
	//SET PIN(5,6,7) OUTPUT.
	IO_DDRD |= (1<<5);
	IO_DDRD	|= (1<<6);
	IO_DDRD |= (1<<7);

	//enable global interrupt.
	INT_SREG |= (1<<7);

	//enable INT0,INT1,INT2
	INT_GICR |= (1<<5);
	INT_GICR |= (1<<6);
	INT_GICR |= (1<<7);

	//INT0 any change
	INT_MCUCR |= (1<<0);
	INT_MCUCR &= ~(1<<1);

	//INT1 rising edge
	INT_MCUCR |= (1<<2);
	INT_MCUCR |= (1<<3);

	//INT2 falling edge
	INT_MCUCSR &= ~(1<<6);

	while(1)
	{
		IO_PORTD &= ~(1<<5);
		IO_PORTD &= ~(1<<6);
		IO_PORTD &= ~(1<<7);
	}
}

ISR(INT0_vect)
{
	//led on pin 5 is on
	IO_PORTD |= (1<<5);
	_delay_ms(1000);
}

ISR(INT1_vect)
{
	//led on pin 6 is on
	IO_PORTD |= (1<<6);
	_delay_ms(1000);
}

ISR(INT2_vect)
{
	//led on pin 7 is on
	IO_PORTD |= (1<<7);
	_delay_ms(1000);
}
