#include"UART.h"

unsigned char ptr_tx_string[100] = "learn-in-depth: <Ahmed ELgazzar>";

void main(void)
{
	send_uartString(ptr_tx_string);
}