/*
 * stm32f103c6.h
 *
 *  Created on: Dec 5, 2022
 *      Author: Ahmed ELgazzar
 */

#ifndef INC_STM32F103C6_H_
#define INC_STM32F103C6_H_

//-----------------------------
//Includes
//-----------------------------
#include"stdint.h"
#include"stdlib.h"
#include"stdio.h"
/*======================================================================================*/
//-----------------------------
//Base addresses for Memories
//-----------------------------
#define FLASH_MEMORY_BASE							0x08000000UL
#define SYSTEM_MEMORY_BASE							0x1FFFF000UL
#define SRAM_Address_BASE 							0x20000000UL

#define Peripheral_Address_BASE						0x40000000UL

#define Cortex_M3_internal_peripherals_BASE			0xE0000000UL

/*======================================================================================*/

//-----------------------------
//Base addresses for AHB BUS Peripherals
//-----------------------------
//RCC
#define RCC_BASE	(Peripheral_Address_BASE + 0x00021000UL)

//-----------------------------
//Base addresses for ABP1 BUS Peripherals
//-----------------------------

//-----------------------------
//Base addresses for ABP2 BUS Peripherals
//-----------------------------
//GPIO BASE
//in LQPF48 PORT A AND B is fully included.
#define GPIOA_BASE	(Peripheral_Address_BASE + 0x00010800UL)
#define GPIOB_BASE	(Peripheral_Address_BASE + 0x00010C00UL)

//in LQPF48 PORT C AND D is partially included.
#define GPIOC_BASE	(Peripheral_Address_BASE + 0x00011000UL)
#define GPIOD_BASE	(Peripheral_Address_BASE + 0x00011400UL)

//in LQPF48 PORT E,G and F isnot included.
#define GPIOE_BASE	(Peripheral_Address_BASE + 0x00011800UL)
#define GPIOF_BASE  (Peripheral_Address_BASE + 0x00011C00UL)
#define GPIOG_BASE  (Peripheral_Address_BASE + 0x00012000UL)

//EXTI BASE
#define EXTI_BASE	(Peripheral_Address_BASE + 0x00010400UL)

//AFIO BASE
#define AFIO_BASE	(Peripheral_Address_BASE + 0x00010000UL)

/*======================================================================================*/
//-*-*-*-*-*-*-*-*-*-*-*-
//peripherals register:
//-*-*-*-*-*-*-*-*-*-*-*

//-*-*-*-*-*-*-*-*-*-*-*-
//RCC register:
//-*-*-*-*-*-*-*-*-*-*-*
typedef struct {
	volatile uint32_t CRR;
	volatile uint32_t CFGR;
	volatile uint32_t CIR;
	volatile uint32_t APB2RSTR;
	volatile uint32_t APB1RSTR;
	volatile uint32_t AHBENR;
	volatile uint32_t APB2ENR;
	volatile uint32_t APB1ENR;
	volatile uint32_t BDCR;
	volatile uint32_t CSR;
	volatile uint32_t AHBSTR;
	volatile uint32_t CFGR2;
}RCC_t;

//-*-*-*-*-*-*-*-*-*-*-*-
//GPIO register:
//-*-*-*-*-*-*-*-*-*-*-*
typedef struct
{
	volatile uint32_t CRL;
	volatile uint32_t CRH;
	volatile uint32_t IDR;
	volatile uint32_t ODR;
	volatile uint32_t BSRR;
	volatile uint32_t BRR;
	volatile uint32_t LCKR;

} GPIO_t;

//-*-*-*-*-*-*-*-*-*-*-*-
//EXTI register:
//-*-*-*-*-*-*-*-*-*-*-*
typedef struct
{
	volatile uint32_t IMR;
	volatile uint32_t EMR;
	volatile uint32_t RTSR;
	volatile uint32_t FTSR;
	volatile uint32_t SWIER;
	volatile uint32_t PR;

} EXTI_t;

//-*-*-*-*-*-*-*-*-*-*-*-
//AFIO register:
//-*-*-*-*-*-*-*-*-*-*-*
typedef struct
{
	volatile uint32_t EVCR;
	volatile uint32_t MAPR;
	volatile uint32_t EXTICR1;
	volatile uint32_t EXTICR2;
	volatile uint32_t EXTICR3;
	volatile uint32_t EXTICR4;
	uint32_t          RESERVED0;//0x18
	volatile uint32_t MAPR2;//0x1C
} AFIO_t;

/*======================================================================================*/

//-*-*-*-*-*-*-*-*-*-*-*-
//Peripheral Instants:
//-*-*-*-*-*-*-*-*-*-*-*
//RCC
#define RCC ((RCC_t*)RCC_BASE)

//GPIO
#define GPIOA ((GPIO_t *)GPIOA_BASE)
#define GPIOB ((GPIO_t *)GPIOB_BASE)
#define GPIOC ((GPIO_t *)GPIOC_BASE)
#define GPIOD ((GPIO_t *)GPIOD_BASE)
#define GPIOE ((GPIO_t *)GPIOE_BASE)
#define GPIOF ((GPIO_t *)GPIOF_BASE)
#define GPIOG ((GPIO_t *)GPIOG_BASE)

//AFIO
#define AFIO ((AFIO_t *)AFIO_BASE)

//EXTI
#define EXTI ((EXTI_t *)EXTI_BASE)

/*======================================================================================*/

//-*-*-*-*-*-*-*-*-*-*-*-
//clock enable Macros:
//-*-*-*-*-*-*-*-*-*-*-*
//Enable GPIO
#define GPIOA_CLK_EN() (RCC->APB2ENR |= (1<<2))
#define GPIOB_CLK_EN() (RCC->APB2ENR |= (1<<3))
#define GPIOC_CLK_EN() (RCC->APB2ENR |= (1<<4))
#define GPIOD_CLK_EN() (RCC->APB2ENR |= (1<<5))
#define GPIOE_CLK_EN() (RCC->APB2ENR |= (1<<6))
#define GPIOF_CLK_EN() (RCC->APB2ENR |= (1<<7))
#define GPIOG_CLK_EN() (RCC->APB2ENR |= (1<<8))

//Enable AFIO
#define AFIO_CLK_EN() (RCC->APB2ENR |= (1<<0))
/*======================================================================================*/
//-*-*-*-*-*-*-*-*-*-*-*-
//Generic Macros:
//-*-*-*-*-*-*-*-*-*-*-*

#endif /* INC_STM32F103C6_H_ */
