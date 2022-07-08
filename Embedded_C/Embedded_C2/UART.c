#include"UART.h"
#define UART0DR *((volatile unsigned int*) ((unsigned int*)0x101f1000))

void send_uartString(unsigned char *ptr_string)
{
	while(*ptr_string != '\0')
	{
		UART0DR = (unsigned int) (*ptr_string);
		ptr_string++;
	}
}