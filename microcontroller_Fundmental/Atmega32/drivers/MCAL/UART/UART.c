/*
 * UART.c
 *
 *  Created on: 23 Dec 2022
 *      Author: Ahmed ELgazzar
 */

#include"UART.h"

void HAL_UART_init(void)
{
	//Buadrate
	UBRRL = 51;

	//to be normal mode
	UCSRA &=~ (1<<1);

	//frame
	//no parity ----8 bit data (that is by default)

	//enable
	UCSRB |= (1<<3);
	UCSRB |= (1<<4);

}

void HAL_UART_SendChar(uint8_t data)
{
	while(!( (UCSRA>>5) & 1) );// ((reg>>bit) & 1)it will be 1 if the UDR is ready to receive
	UDR = data;
}

uint8_t HAL_UART_RecieveChar()
{
	while(!( (UCSRA>>7) & 1) );//it will be 1 if the receive is complete
	return UDR;
}
