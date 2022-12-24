/*
 * main.c
 *
 *  Created on: 23 Dec 2022
 *      Author: Ahmed ELgazzar
 */

#include"lcd.h"
#include"keypad.h"
#include"UART.h"

int main()
{
	uint8_t receive = 0;
	LCD_INIT();
	Keypad_init();
	HAL_UART_init();
	LCD_GOTO_XY(0,0);
	LCD_WRITE_STRING("UART TR INIT");
	HAL_UART_SendChar('A');
	HAL_UART_SendChar('H');
	HAL_UART_SendChar('M');
	HAL_UART_SendChar('E');
	HAL_UART_SendChar('D');
	while(1)
	{
		LCD_GOTO_XY(2,0);
		receive = HAL_UART_RecieveChar();
		LCD_WRITE_CHAR(receive);
	}
	return 0;
}
