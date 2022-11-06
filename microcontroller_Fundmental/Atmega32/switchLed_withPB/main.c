/*
 * main.c
 *
 *  Created on: 3 Nov 2022
 *      Author: Ahmed ELgazzar
 */
#include"MemMap.h"
#include<util\delay.h>

int main()
{
	char Flag = 0;
	DDRD |= (0b111<<5);//set pin D(5,6,7) output.
	DDRD &=~ (1<<0);//set pin D0 input.
	while(1)
	{
		if(((PIND >> 0) & 1) == 1)
		{
			if(Flag == 0)
			{
				PORTD |= (1<<5);// led 5 is on
				_delay_ms(1000);
				Flag++;
			}
			else if(Flag == 1)
			{
				PORTD |= (1<<6);// led 6 is on
				_delay_ms(1000);
				Flag++;
			}
			else if(Flag == 2)
			{
				PORTD |= (1<<7);// led 7 is on
				_delay_ms(1000);
				Flag++;
			}
			else
			{
				Flag = 0;
				PORTD &=~ (0b111<<5);// all leds is off.
				_delay_ms(1000);
			}
		}
	}
	return 0;
}
