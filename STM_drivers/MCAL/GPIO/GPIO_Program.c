/*
 * GPIO_Program.c
 *
 *  Created on: Aug 13, 2024
 *      Author: Abdo
 */

#include "GPIO_Interface.h"

void MCAL_GPIO_voidInit(GPIO_Config_t * config) {
	GPIO_RegDef_t* gpioTemp;

	switch (config->port) {
		case (PORTA):
			gpioTemp = GPIOA;
		break;
		case (PORTB):
			gpioTemp = GPIOB;
		break;
		case (PORTC):
			gpioTemp = GPIOC;
		break;
	}

	if (8 > config->pinNumber) {
		if (config->mode == GPIO_MODE_INPUT_FLOATING
				|| config->mode == GPIO_MODE_INPUT_PULLUP
				|| config->mode == GPIO_MODE_INPUT_PULLDOWN
				|| config->mode == GPIO_MODE_INPUT_ANALOG) {
			gpioTemp->CRL &= ~(0b11 << GPIO_CRL_SHIFT * config->pinNumber);
			if (config->mode == GPIO_MODE_INPUT_PULLDOWN) {
				CLR_BIT(gpioTemp->ODR, config->pinNumber);
			}
			else if (config->mode == GPIO_MODE_INPUT_PULLUP) {
				SET_BIT(gpioTemp->ODR, config->pinNumber);
			}
		}
		else {
			gpioTemp->CRL &= ~(0b11 << GPIO_CRL_SHIFT * config->pinNumber);
			gpioTemp->CRL |= (config->speed << GPIO_CRL_SHIFT * config->pinNumber);
		}
		gpioTemp->CRL &= ~(0b11 << ((GPIO_CRL_SHIFT * config->pinNumber) + 2));
		gpioTemp->CRL |= (config->mode << ((GPIO_CRL_SHIFT * config->pinNumber) + 2));
	}
	else {
		if (config->mode == GPIO_MODE_INPUT_FLOATING
				|| config->mode == GPIO_MODE_INPUT_PULLUP
				|| config->mode == GPIO_MODE_INPUT_PULLDOWN
				|| config->mode == GPIO_MODE_INPUT_ANALOG) {
			gpioTemp->CRH &= ~(0b11 << GPIO_CRL_SHIFT * config->pinNumber);
			if (config->mode == GPIO_MODE_INPUT_PULLDOWN) {
				CLR_BIT(gpioTemp->ODR, config->pinNumber);
			}
			else if (config->mode == GPIO_MODE_INPUT_PULLUP) {
				SET_BIT(gpioTemp->ODR, config->pinNumber);
			}
		}
		else {
			gpioTemp->CRH &= ~(0b11 << GPIO_CRL_SHIFT * (config->pinNumber - 8));
			gpioTemp->CRH |= (config->speed << GPIO_CRL_SHIFT * (config->pinNumber - 8));
		}
		gpioTemp->CRH &= ~(0b11 << ((GPIO_CRL_SHIFT * (config->pinNumber - 8)) + 2));
		gpioTemp->CRH |= (config->mode << ((GPIO_CRL_SHIFT * (config->pinNumber - 8)) + 2));
	}
}

GPIO_Pin_State_t MCAL_GPIO_voidReadPin(GPIO_RegDef_t* GPIOx, u8 pinNumber) {
    return ((GPIOx->IDR >> pinNumber) & 0x01);
}

void MCAL_GPIO_voidWritePin(GPIO_RegDef_t* GPIOx, u8 pinNumber, u8 value) {
    if (value == GPIO_PIN_SET) {
        GPIOx->BSRR |= (1 << pinNumber);
    }
    else {
        GPIOx->BRR |= (1 << pinNumber);
    }
}

