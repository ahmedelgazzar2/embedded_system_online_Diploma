/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Auto-generated by STM32CubeIDE
 * @brief          : Main program body
 ******************************************************************************
 * @attention
 *
 * <h2><center>&copy; Copyright (c) 2022 STMicroelectronics.
 * All rights reserved.</center></h2>
 *
 * This software component is licensed by ST under BSD 3-Clause license,
 * the "License"; You may not use this file except in compliance with the
 * License. You may obtain a copy of the License at:
 *                        opensource.org/licenses/BSD-3-Clause
 *
 ******************************************************************************
 */
#include "platform_types.h"
#define RCC_BASE      0x40021000
#define GPIO_PORTA    0x40010800

#define APB2ENR     *((volatile u32*)(RCC_BASE + 0x18))
#define GPIO_CRH    *((volatile u32*)(GPIO_PORTA + 0x04))
#define GPIO_ODR    *((volatile u32*)(GPIO_PORTA + 0x0C))


int main(void)
{
	APB2ENR  |= 1<<2;
	GPIO_CRH &= 0xff0fffff;
	GPIO_CRH |= 0x00200000;
	/* Loop forever */
	while(1)
	{
		GPIO_ODR |= 1<<13;
		for(volatile int i = 0;i < 5000;i++);
		GPIO_ODR &= ~(1<<13);
		for(volatile int i = 0;i < 5000;i++);
	}
}
