/*
 * stm32f103c6_gpio_driver.h
 *
 *  Created on: Dec 5, 2022
 *      Author: Dell
 */

#ifndef INC_STM32F103C6_GPIO_DRIVER_H_
#define INC_STM32F103C6_GPIO_DRIVER_H_

//-----------------------------
//Includes
//-----------------------------
#include "stm32f103c6.h"

//-----------------------------
//User type definitions (structures)
//-----------------------------
typedef struct{
	uint16_t GPIO_PinNumber;//specific which GPIO pin is configured
									//this parameter can be selected its value from @ref GPIO_PINS
	uint8_t GPIO_MODE;//specific operation mode for the selected pin
									//this parameter can be selected its value from @ref GPIO_MODE
	uint8_t GPIO_OUTPUT_speed;//specific which GPIO pin is configured
						   	   	   //this parameter can be selected its value from @ref GPIO_OUTPUT_speed
}Pin_config_t;

//-----------------------------
//Macros Configuration References
//-----------------------------

//@ref GPIO_PINS 0-->15
#define GPIO_PIN0  ((uint16_t)0x0001UL)//select pin 0
#define GPIO_PIN1  ((uint16_t)0x0002UL)//select pin 1
#define GPIO_PIN2  ((uint16_t)0x0004UL)//select pin 2
#define GPIO_PIN3  ((uint16_t)0x0008UL)//select pin 3
#define GPIO_PIN4  ((uint16_t)0x0010UL)//select pin 4
#define GPIO_PIN5  ((uint16_t)0x0020UL)//select pin 5
#define GPIO_PIN6  ((uint16_t)0x0040UL)//select pin 6
#define GPIO_PIN7  ((uint16_t)0x0080UL)//select pin 7
#define GPIO_PIN8  ((uint16_t)0x0100UL)//select pin 8
#define GPIO_PIN9  ((uint16_t)0x0200UL)//select pin 9
#define GPIO_PIN10 ((uint16_t)0x0400UL)//select pin 10
#define GPIO_PIN11 ((uint16_t)0x0800UL)//select pin 11
#define GPIO_PIN12 ((uint16_t)0x1000UL)//select pin 12
#define GPIO_PIN13 ((uint16_t)0x2000UL)//select pin 13
#define GPIO_PIN14 ((uint16_t)0x4000UL)//select pin 14
#define GPIO_PIN15 ((uint16_t)0x8000UL)//select pin 15

//@ref GPIO_MODE
/*
 * 0: Analog mode
 * 1: Floating input
 * 2: Input with pull-up
 * 3: Input with pull-down
 * 4: General purpose output push-pull
 * 5: General purpose output Open-drain
 * 6: Alternate function output Push-pull
 * 7: Alternate function output Open-drain
 * 8: Alternate function input
 */
#define GPIO_MODE_INPUT_ANALOG 			0x00000000UL
#define GPIO_MODE_INPUT_FLOAT		    0x00000001UL
#define GPIO_MODE_INPUT_PU 				0x00000002UL
#define GPIO_MODE_INPUT_PD 			    0x00000003UL
#define GPIO_MODE_OUTPUT_PP 			0x00000004UL
#define GPIO_MODE_OUTPUT_OD 	    	0x00000005UL
#define GPIO_MODE_AF_PP 			    0x00000006UL
#define GPIO_MODE_AF_OD 			    0x00000007UL
#define GPIO_MODE_AF_INPUT 			    0x00000008UL

//@ref GPIO_OUTPUT_speed
/*
 *1: Output mode, max speed 10 MHz
 *2: Output mode, max speed 2 MHz
 *3: Output mode, max speed 50 MHz
 */
#define GPIO_SPEED_10M 0x00000001UL
#define GPIO_SPEED_2M  0x00000002UL
#define GPIO_SPEED_50M 0x00000003UL

//@ref Lock Pin status
#define GPIO_LOCK_PIN_ENABLE	1
#define GPIO_LOCK_PIN_ERROR  	0

//@ref GPIO_PIN_status
#define GPIO_PIN_SET		1
#define GPIO_PIN_RESET  	0

// ===============================================
// APIs Supported by "MCAL GPIO DRIVER"
// ===============================================
void MCAL_GPIO_INIT(GPIO_t *GPIOX,Pin_config_t *Pinconfig);
void MCAL_GPIO_DEINIT(GPIO_t *GPIOX);

void MCAL_GPIO_WritePin(GPIO_t *GPIOX,uint16_t PinNumber,uint8_t value);
void MCAL_GPIO_WritePORT(GPIO_t *GPIOX,uint16_t value);

uint8_t MCAL_GPIO_ReadPin(GPIO_t *GPIOX,uint16_t PinNumber);
uint16_t MCAL_GPIO_ReadPORT(GPIO_t *GPIOX);

void MCAL_GPIO_TogglePin(GPIO_t *GPIOX,uint16_t PinNumber);

uint8_t MCAL_GPIO_LockPin(GPIO_t *GPIOX,uint16_t PinNumber);

#endif /* INC_STM32F103C6_GPIO_DRIVER_H_ */
