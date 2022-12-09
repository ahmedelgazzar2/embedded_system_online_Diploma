/*
 * stm32f103c6_gpio_driver.c
 *
 *  Created on: Dec 5, 2022
 *      Author: Ahmed ELgazzar
 */
#include"stm32f103c6_gpio_driver.h"

/**================================================================
 * @Fn				-Get_CRLH_position
 * @brief 			-it is function to get the pin position on the register CRL OR CRH...
 * @parameter[in]	-PinNumber :it is the number of the pin we want to get its position
 * 						according to @ref GPIO_PINS...
 * @return			-the position of the pin on the register..
 * Note				-None
 */
uint8_t Get_CRLH_position(uint16_t PinNumber)
{
	switch(PinNumber)
	{
	case GPIO_PIN0:
		return 0;
		break;

	case GPIO_PIN1:
		return 4;
		break;

	case GPIO_PIN2:
		return 8;
		break;

	case GPIO_PIN3:
		return 12;
		break;

	case GPIO_PIN4:
		return 16;
		break;

	case GPIO_PIN5:
		return 20;
		break;

	case GPIO_PIN6:
		return 24;
		break;

	case GPIO_PIN7:
		return 28;
		break;

	case GPIO_PIN8:
		return 0;
		break;

	case GPIO_PIN9:
		return 4;
		break;

	case GPIO_PIN10:
		return 8;
		break;

	case GPIO_PIN11:
		return 12;
		break;

	case GPIO_PIN12:
		return 16;
		break;

	case GPIO_PIN13:
		return 20;
		break;

	case GPIO_PIN14:
		return 24;
		break;

	case GPIO_PIN15:
		return 28;
		break;
	}
	return 1;
}

/**================================================================
 * @Fn				-MCAL_GPIO_INIT
 * @brief 			-it is function to initialize the GPIOX and PINy to the specific parameter
 * 						from pin config..
 * @parameter[in]	-GPIOX :it is pointer to the selection of the GPIO port (A,B,C,D,E,F,G)...
 * @parameter[in] 	-Pinconfig :it is pointer to Pin_config_t structure that contain of configuration
 * 						information of the specific GPIO PIN...
 *@parameter[out]  	-None
 * @return			-None
 * Note				- it is called first before use GPIO...
 * 						stm32F103C6 has GPIO PORT(A,B,C,D,E,F,G) but..
 * 						LQFP48 has PORT A ,B fully and part of PORT C,D and hasnot PORT E,F,G...
 */
void MCAL_GPIO_INIT(GPIO_t *GPIOX,Pin_config_t *Pinconfig)
{
	//CNFy[1:0] MODEy[1:0]
	//if the pin number from 0 >>> 7 you write on CRL register..
	//else if the pin number from 8 >>> 15 you write on CRH register..
	volatile uint32_t* config_register = NULL;
	uint8_t pin_config = 0;
	config_register = (Pinconfig->GPIO_PinNumber < GPIO_PIN8) ? &GPIOX->CRL : &GPIOX->CRH;

	//clear register (CNFy[1:0] MODEy[1:0])...
	(*config_register) &=~ (0x0f << Get_CRLH_position(Pinconfig->GPIO_PinNumber));

	//if the pin is output ......In output mode (MODE[1:0] > 00): CNFy[1:0] MODEy[1:0]
	if((Pinconfig->GPIO_MODE == GPIO_MODE_OUTPUT_PP) || (Pinconfig->GPIO_MODE == GPIO_MODE_OUTPUT_OD) || (Pinconfig->GPIO_MODE == GPIO_MODE_AF_PP) || (Pinconfig->GPIO_MODE == GPIO_MODE_AF_OD) )
	{
		pin_config = ( (((Pinconfig->GPIO_MODE - 4) << 2) | Pinconfig->GPIO_OUTPUT_speed) & 0x0F);
	}
	//else >>> pin is input MODEy[1:0] = 00..
	else
	{
		//if the input floating or analog..
		if((Pinconfig->GPIO_MODE == GPIO_MODE_INPUT_ANALOG) || (Pinconfig->GPIO_MODE == GPIO_MODE_INPUT_FLOAT) )
		{
			pin_config = ( ((Pinconfig->GPIO_MODE << 2) | 0x0) & 0x0f);
		}
		//else if the input is alternative ...it is like input floating..
		else if(Pinconfig->GPIO_MODE == GPIO_MODE_AF_INPUT)
		{
			pin_config = ( ((Pinconfig->GPIO_MODE << 2) | 0x0) & 0x0f);
		}
		//input pull-up or pull-down....
		else
		{
			pin_config = ( ((Pinconfig->GPIO_MODE << 2) | 0x0) & 0x0f);
			//pull-up >>> ODR = 1..Table 20. Port bit configuration table..
			if(Pinconfig->GPIO_MODE == GPIO_MODE_INPUT_PU)
			{
				GPIOX->ODR |= Pinconfig->GPIO_PinNumber;
			}
			//Pull-Down ODR = 0..Table 20. Port bit configuration table..
			else
			{
				GPIOX->ODR &=~ Pinconfig->GPIO_PinNumber;
			}
		}
	}

	//write the result in the CRL or CRH register...
	(*config_register) |= (pin_config<< Get_CRLH_position(Pinconfig->GPIO_PinNumber));
}
/**================================================================
 * @Fn				-MCAL_GPIO_DEINIT
 * @brief 			-it is function to reset all PORT Value...
 * @parameter[in]	-GPIOX :it is pointer to the selection of the GPIO port (A,B,C,D,E,F,G)...
 * @return			-None
 * Note				-None
 */
void MCAL_GPIO_DEINIT(GPIO_t *GPIOX)
{
	//there is two methods to reset the peripheral...
	/*
	//first method is to reset registers manually...
	GPIOX->BRR = 0x00000000;
	GPIOX->BSRR = 0x00000000;
	GPIOX->CRL = 0x44444444;
	GPIOX->CRH = 0x44444444;
	//GPIOX->IDR = (read only);
	GPIOX->LCKR = 0x00000000;
	GPIOX->ODR = 0x00000000;
	 */

	//second method if the MCU have a reset register resetting by soft ware...
	//in our driver stm32F103C6 have reset register RCC_ABP2RSTR...
	if(GPIOX == GPIOA)//Bit 2 IOPARST: I/O port A reset ..Set and cleared by software.
	{
		RCC->APB2RSTR |= (1<<2);
		RCC->APB2RSTR &=~ (1<<2);
	}
	else if(GPIOX == GPIOB)//Bit 3 IOPBRST: I/O port B reset ..Set and cleared by software.
	{
		RCC->APB2RSTR |= (1<<3);
		RCC->APB2RSTR &=~ (1<<3);
	}
	else if(GPIOX == GPIOC)//Bit 4 IOPCRST: I/O port C reset ..Set and cleared by software.
	{
		RCC->APB2RSTR |= (1<<4);
		RCC->APB2RSTR &=~ (1<<4);
	}
	else if(GPIOX == GPIOD)//Bit 5 IOPDRST: I/O port D reset ..Set and cleared by software.
	{
		RCC->APB2RSTR |= (1<<5);
		RCC->APB2RSTR &=~ (1<<5);
	}
	else if(GPIOX == GPIOE)//Bit 6 IOPERST: I/O port E reset ..Set and cleared by software.
	{
		RCC->APB2RSTR |= (1<<6);
		RCC->APB2RSTR &=~ (1<<6);
	}
}
/**================================================================
 * @Fn				-MCAL_GPIO_WritePin
 * @brief 			-it is function to write value on selected Pin...
 * @parameter[in]	-GPIOX :it is pointer to the selection of the GPIO port (A,B,C,D,E,F,G)...
 * @parameter[in]	-PinNumber : it is the number of the pin that will be written on it
 * 						according to @ref GPIO_PINS...
 * @parameter[in]	-value : the value we want to write on the pin..
 * @return			-None
 * Note				-None
 */
void MCAL_GPIO_WritePin(GPIO_t *GPIOX,uint16_t PinNumber,uint8_t value)
{
	if(value != GPIO_PIN_RESET)
	{
		GPIOX->ODR |= PinNumber;
		//or GPIO->BSRR = PinNumber;
	}
	else
	{
		GPIOX->ODR &=~ PinNumber;
		//or GPIO->BRR = PinNumber;
	}
}
/**================================================================
 * @Fn				-MCAL_GPIO_WritePORT
 * @brief 			-it is function to write value on selected PORT...
 * @parameter[in]	-GPIOX :it is pointer to the selection of the GPIO port (A,B,C,D,E,F,G)...
 * @parameter[in]	-value : the value we want to write on the port..
 * @return			-None
 * Note				-None
 */
void MCAL_GPIO_WritePORT(GPIO_t *GPIOX,uint16_t value)
{
	GPIOX->ODR = (uint32_t)value;
}
/**================================================================
 * @Fn				-MCAL_GPIO_ReadPin
 * @brief 			-it is function to read value from the selected PIN...
 * @parameter[in]	-GPIOX :it is pointer to the selection of the GPIO port (A,B,C,D,E,F,G)...
 * @parameter[in]	-PinNumber : it is the number of the pin that will be read its value
 * 					 according to @ref GPIO_PINS...
 * @return			-input pin value(uint8_t) according to @ref GPIO_PIN_status..
 * Note				-None
 */
uint8_t MCAL_GPIO_ReadPin(GPIO_t *GPIOX,uint16_t PinNumber)
{
	uint8_t pin_status = 2;
	if( ((GPIOX->IDR) & PinNumber) != GPIO_PIN_RESET)
	{
		pin_status = GPIO_PIN_SET;
	}
	else
	{
		pin_status = GPIO_PIN_RESET;
	}
	return pin_status;
}
/**================================================================
 * @Fn				-MCAL_GPIO_ReadPORT
 * @brief 			-it is function to read value from the selected PORT...
 * @parameter[in]	-GPIOX :it is pointer to the selection of the GPIO port (A,B,C,D,E,F,G)...
 * @return			-port value(uint16_t)..
 * Note				-None
 */
uint16_t MCAL_GPIO_ReadPORT(GPIO_t *GPIOX)
{
	uint16_t Port_Val;
	Port_Val = (uint16_t)GPIOX->IDR;
	return Port_Val;

}
/**================================================================
 * @Fn				-MCAL_GPIO_TogglePin
 * @brief 			-it is function to Toggle selected PIN...
 * @parameter[in]	-GPIOX :it is pointer to the selection of the GPIO port (A,B,C,D,E,F,G)...
 * @parameter[in]	-PinNumber : it is the number of the pin that will be toggled
 * 						according to @ref GPIO_PINS...
 * @return			-None
 * Note				-None
 */
void MCAL_GPIO_TogglePin(GPIO_t *GPIOX,uint16_t PinNumber)
{
	GPIOX->ODR ^= PinNumber;
}
/**================================================================
 * @Fn				-MCAL_GPIO_LockPin
 * @brief 			-it is function to Lock selected PIN...
 * @parameter[in]	-GPIOX :it is pointer to the selection of the GPIO port (A,B,C,D,E,F,G)...
 * @parameter[in]	-PinNumber : it is the number of the pin that will be Locked
 * 						according to @ref GPIO_PINS...
 * @return			-the status of the Lock configuration according to @ref Lock Pin status
 * Note				-None
 */
uint8_t MCAL_GPIO_LockPin(GPIO_t *GPIOX,uint16_t PinNumber)
{
	/*
	LCKK[16]: Lock key
	This bit can be read anytime. It can only be modified using the Lock Key Writing Sequence.
 	 0: Port configuration lock key not active
  	 1: Port configuration lock key active. GPIOx_LCKR register is locked until the next reset.
  	 LOCK key writing sequence:
 	 Write 1
  	 Write 0
	 Write 1
	 Read 0
	 Read 1 (this read is optional but confirms that the lock is active)
		        */
	uint32_t temp = (1 << 16);//set LCKK[16]: Lock key

	//LOCK the selected pin
	temp |= PinNumber;
	//Apply sequence on LCKK[16]: Lock key
	// Write 1 on LCKK[16]: Lock key
	GPIOX->LCKR |= temp;
	// Write 0 on LCKK[16]: Lock key... pin number always bit 16 is 0...
	GPIOX->LCKR = PinNumber;
	// Write 1 on LCKK[16]: Lock key
	GPIOX->LCKR |= temp;
	//Read 0 from LCKK[16]: Lock key
	temp = GPIOX->LCKR;

	// Read 1 (this read is optional but confirms that the lock is active)
	if ( (uint32_t)((GPIOX->LCKR) & (1 << 16)) )
	{
		return GPIO_LOCK_PIN_ENABLE;
	}
	else
	{
		return GPIO_LOCK_PIN_ERROR;
	}
}
/*****************************************************************
 * end stm32F103C6_gpio_driver.c
 ****************************************************************/


