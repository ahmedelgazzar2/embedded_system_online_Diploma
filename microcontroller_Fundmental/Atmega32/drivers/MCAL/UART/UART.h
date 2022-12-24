/*
 * UART.h
 *
 *  Created on: 23 Dec 2022
 *      Author: Dell
 */

#ifndef MCAL_UART_H_
#define MCAL_UART_H_

#include"MemMap.h"

void HAL_UART_init(void);

void HAL_UART_SendChar(uint8_t data);

uint8_t HAL_UART_RecieveChar();


#endif /* MCAL_UART_H_ */
