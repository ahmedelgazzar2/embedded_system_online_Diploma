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

//NVIC register map
#define NVIC_BASE		                            0xE000E100UL
#define NVIC_ISER0                                  (*(volatile uint32_t *)(NVIC_BASE + 0x00))
#define NVIC_ISER1                                  (*(volatile uint32_t *)(NVIC_BASE + 0x04))
#define NVIC_ISER2                                  (*(volatile uint32_t *)(NVIC_BASE + 0x08))
#define NVIC_ICER0                                  (*(volatile uint32_t *)(NVIC_BASE + 0x80))
#define NVIC_ICER1                                  (*(volatile uint32_t *)(NVIC_BASE + 0x84))
#define NVIC_ICER2                                  (*(volatile uint32_t *)(NVIC_BASE + 0x88))

/*======================================================================================*/

//-----------------------------
//Base addresses for AHB BUS Peripherals
//-----------------------------
//RCC
#define RCC_BASE	(Peripheral_Address_BASE + 0x00021000UL)

//-----------------------------
//Base addresses for ABP1 BUS Peripherals
//-----------------------------

//UART2,3 BASE

#define UART2_BASE (Peripheral_Address_BASE + 0x00004400UL)
#define UART3_BASE (Peripheral_Address_BASE + 0x00004800UL)

//SPI2 BASE
#define SPI2_BASE  (Peripheral_Address_BASE + 0x00013800UL)

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

//UART1 BASE
#define UART1_BASE (Peripheral_Address_BASE + 0x00013800UL)

//SPI1 BASE
#define SPI1_BASE  (Peripheral_Address_BASE + 0x00013000UL)

/*======================================================================================*/
//-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-
//=================peripherals register:======================
//-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-

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
	volatile uint32_t EXTICR[4] ;
	uint32_t          RESERVED0;//0x18
	volatile uint32_t MAPR2;//0x1C
} AFIO_t;

//-*-*-*-*-*-*-*-*-*-*-*-
//UART register:
//-*-*-*-*-*-*-*-*-*-*-*
typedef struct
{
	volatile uint32_t SR;
	volatile uint32_t DR;
	volatile uint32_t BRR;
	volatile uint32_t CR1;
	volatile uint32_t CR2;
	volatile uint32_t CR3;
	volatile uint32_t GTPR;

}UART_t;

//-*-*-*-*-*-*-*-*-*-*-*-
//SPI register:
//-*-*-*-*-*-*-*-*-*-*-*
typedef struct
{
	volatile uint32_t CR1;
	volatile uint32_t CR2;
	volatile uint32_t SR;
	volatile uint32_t DR;
	volatile uint32_t CRCPR;
	volatile uint32_t RXCRCR;
	volatile uint32_t TXCRCR;
	volatile uint32_t I2SCFGR;
	volatile uint32_t I2SPR;

}SPI_t;
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

//UART
#define UART1 ((UART_t *)UART1_BASE)
#define UART2 ((UART_t *)UART2_BASE)
#define UART3 ((UART_t *)UART3_BASE)

//SPI
#define SPI1 ((SPI_t *)SPI1_BASE)
#define SPI2 ((SPI_t *)SPI2_BASE)

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

//Enable UART
#define UART1_CLK_EN() (RCC->APB2ENR |= (1<<14))
#define UART2_CLK_EN() (RCC->APB1ENR |= (1<<17))
#define UART3_CLK_EN() (RCC->APB1ENR |= (1<<18))

//Disable UART
#define UART1_CLK_RESET() (RCC->APB2RSTR |= (1<<14))
#define UART2_CLK_RESET() (RCC->APB1RSTR |= (1<<17))
#define UART3_CLK_RESET() (RCC->APB1RSTR |= (1<<18))

//Enable SPI
#define SPI1_CLK_EN() (RCC->APB2ENR |= (1<<12))
#define SPI2_CLK_EN() (RCC->APB1ENR |= (1<<14))

//Disable SPI
#define SPI1_CLK_RESET() (RCC->APB2RSTR |= (1<<12))
#define SPI2_CLK_RESET() (RCC->APB1RSTR |= (1<<14))


//=================================================================
//-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-
//	=========== IVT =============
//-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-
//EXTI

#define       EXTI0_IRQ              6
#define       EXTI1_IRQ              7
#define       EXTI2_IRQ              8
#define       EXTI3_IRQ              9
#define       EXTI4_IRQ              10
#define       EXTI5_IRQ              23
#define       EXTI6_IRQ              23
#define       EXTI7_IRQ              23
#define       EXTI8_IRQ              23
#define       EXTI9_IRQ              23
#define       EXTI10_IRQ             40
#define       EXTI11_IRQ             40
#define       EXTI12_IRQ             40
#define       EXTI13_IRQ             40
#define       EXTI14_IRQ             40
#define       EXTI15_IRQ             40

//UART
#define       UART1_IRQ             37
#define       UART2_IRQ             38
#define       UART3_IRQ             39

//EXTI
#define       EXTI0                  0
#define       EXTI1                  1
#define       EXTI2                  2
#define       EXTI3                  3
#define       EXTI4                  4
#define       EXTI5                  5
#define       EXTI6                  6
#define       EXTI7                  7
#define       EXTI8                  8
#define       EXTI9                  9
#define       EXTI10                 10
#define       EXTI11                 11
#define       EXTI12                 12
#define       EXTI13                 13
#define       EXTI14                 14
#define       EXTI15                 15

//SPI
#define       SPI1_IRQ                35
#define       SPI2_IRQ                36

/*======================================================================================*/
//=================================================
//-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-
//============Enable Macros============
//-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-

//EXTI

#define NVIC_IRQ6_EXTI0_Enable          (NVIC_ISER0 |= 1<<6)
#define NVIC_IRQ7_EXTI1_Enable          (NVIC_ISER0 |= 1<<7)
#define NVIC_IRQ8_EXTI2_Enable          (NVIC_ISER0 |= 1<<8)
#define NVIC_IRQ9_EXTI3_Enable          (NVIC_ISER0 |= 1<<9)
#define NVIC_IRQ10_EXTI4_Enable         (NVIC_ISER0 |= 1<<10)
#define NVIC_IRQ23_EXTI5_9_Enable       (NVIC_ISER0 |= 1<<23)
#define NVIC_IRQ40_EXTI10_15_Enable     (NVIC_ISER1 |= 1<<(EXTI10_IRQ - 32) ) //40-32

#define NVIC_IRQ6_EXTI0_Disable         (NVIC_ICER0 |= 1<<6)
#define NVIC_IRQ7_EXTI1_Disable         (NVIC_ICER0 |= 1<<7)
#define NVIC_IRQ8_EXTI2_Disable         (NVIC_ICER0 |= 1<<8)
#define NVIC_IRQ9_EXTI3_Disable         (NVIC_ICER0 |= 1<<9)
#define NVIC_IRQ10_EXTI4_Disable        (NVIC_ICER0 |= 1<<10)
#define NVIC_IRQ23_EXTI5_9_Disable      (NVIC_ICER0 |= 1<<23)
#define NVIC_IRQ40_EXTI10_15_Disable    (NVIC_ICER1 |= 1<<(EXTI10_IRQ - 32) ) //40-32

//UART
#define NVIC_UART1_IRQ37_Enable          (NVIC_ISER1 |= 1<<(UART1_IRQ - 32) )
#define NVIC_UART2_IRQ38_Enable          (NVIC_ISER1 |= 1<<(UART2_IRQ - 32) )
#define NVIC_UART3_IRQ39_Enable          (NVIC_ISER1 |= 1<<(UART3_IRQ - 32) )

#define NVIC_UART1_IRQ37_Disable         (NVIC_ICER1 |= 1<<(UART1_IRQ - 32) )
#define NVIC_UART2_IRQ38_Disable         (NVIC_ICER1 |= 1<<(UART2_IRQ - 32) )
#define NVIC_UART3_IRQ39_Disable         (NVIC_ICER1 |= 1<<(UART3_IRQ - 32) )

//SPI
#define NVIC_SPI1_IRQ35_Enable          (NVIC_ISER1 |= 1<<(SPI1_IRQ - 32) )
#define NVIC_SPI2_IRQ36_Enable          (NVIC_ISER1 |= 1<<(SPI2_IRQ - 32) )

#define NVIC_SPI1_IRQ35_Disable         (NVIC_ICER1 |= 1<<(SPI1_IRQ - 32) )
#define NVIC_SPI2_IRQ36_Disable         (NVIC_ICER1 |= 1<<(SPI2_IRQ - 32) )

//-*-*-*-*-*-*-*-*-*-*-*-
//Generic Macros:
//-*-*-*-*-*-*-*-*-*-*-*

typedef enum
{
	pollingEn,
	pollingDis
}polling_state_t;

#endif /* INC_STM32F103C6_H_ */
