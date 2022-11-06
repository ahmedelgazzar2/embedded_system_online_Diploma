/*
 * main.c
 *
 *  Created on: 3 Nov 2022
 *      Author: Ahmed ELgazzar
 */
#include"MemMap.h"
#include<util\delay.h>
#include"platform_types.h"

int main()
{
	DDRD |= (0b111<<5);//set pin D(5,6,7) output.
	while(1)
	{
		PORTD |= (1<<5);// led 5 is on
		_delay_ms(1000);
		PORTD |= (1<<6);//led 6 is on
		_delay_ms(1000);
		PORTD |= (1<<7);//led 7 is on
		_delay_ms(1000);
		PORTD &=~ (0b111<<5);//all leds is off.
		_delay_ms(1000);
	}
	return 0;
}
