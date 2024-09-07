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
        case (GPIO_PORTA):
            gpioTemp = GPIOA;
            break;
        case (GPIO_PORTB):
            gpioTemp = GPIOB;
            break;
        case (GPIO_PORTC):
            gpioTemp = GPIOC;
            break;
    }

    if (config->pinNumber < 8) {
        if (config->mode == GPIO_MODE_INPUT_FLOATING) {
            gpioTemp->CRL &= ~(0b1111 << (GPIO_CRL_SHIFT * config->pinNumber));
            gpioTemp->CRL |= (0b0100 << (GPIO_CRL_SHIFT * config->pinNumber));
        }
        else if (config->mode == GPIO_MODE_INPUT_PULLUP) {
            gpioTemp->CRL &= ~(0b1111 << (GPIO_CRL_SHIFT * config->pinNumber));
            gpioTemp->CRL |= (0b1000 << (GPIO_CRL_SHIFT * config->pinNumber));
            SET_BIT(gpioTemp->ODR, config->pinNumber);
        }
        else if (config->mode == GPIO_MODE_INPUT_PULLDOWN) {
            gpioTemp->CRL &= ~(0b1111 << (GPIO_CRL_SHIFT * config->pinNumber));
            gpioTemp->CRL |= (0b1000 << (GPIO_CRL_SHIFT * config->pinNumber));
            CLR_BIT(gpioTemp->ODR, config->pinNumber);
        }
        else if (config->mode == GPIO_MODE_INPUT_ANALOG) {
            gpioTemp->CRL &= ~(0b1111 << (GPIO_CRL_SHIFT * config->pinNumber));
        }
        else if (config->mode == GPIO_MODE_OUTPUT_PUSHPULL) {
            gpioTemp->CRL &= ~(0b1111 << (GPIO_CRL_SHIFT * config->pinNumber));
            gpioTemp->CRL |= (config->speed << (GPIO_CRL_SHIFT * config->pinNumber));
            gpioTemp->CRL |= (0b00 << ((GPIO_CRL_SHIFT * config->pinNumber) + 2));
        }
        else if (config->mode == GPIO_MODE_OUTPUT_OPENDRAIN) {
            gpioTemp->CRL &= ~(0b1111 << (GPIO_CRL_SHIFT * config->pinNumber));
            gpioTemp->CRL |= (config->speed << (GPIO_CRL_SHIFT * config->pinNumber));
            gpioTemp->CRL |= (0b01 << ((GPIO_CRL_SHIFT * config->pinNumber) + 2));
        }
        else if (config->mode == GPIO_MODE_AF_PUSHPULL) {
            gpioTemp->CRL &= ~(0b1111 << (GPIO_CRL_SHIFT * config->pinNumber));
            gpioTemp->CRL |= (config->speed << (GPIO_CRL_SHIFT * config->pinNumber));
            gpioTemp->CRL |= (0b10 << ((GPIO_CRL_SHIFT * config->pinNumber) + 2));
        }
        else if (config->mode == GPIO_MODE_AF_OPENDRAIN) {
            gpioTemp->CRL &= ~(0b1111 << (GPIO_CRL_SHIFT * config->pinNumber));
            gpioTemp->CRL |= (config->speed << (GPIO_CRL_SHIFT * config->pinNumber));
            gpioTemp->CRL |= (0b11 << ((GPIO_CRL_SHIFT * config->pinNumber) + 2));
        }
    }
    else {
        if (config->mode == GPIO_MODE_INPUT_FLOATING) {
            gpioTemp->CRH &= ~(0b1111 << (GPIO_CRL_SHIFT * (config->pinNumber - 8)));
            gpioTemp->CRH |= (0b0100 << (GPIO_CRL_SHIFT * (config->pinNumber - 8)));
        }
        else if (config->mode == GPIO_MODE_INPUT_PULLUP) {
            gpioTemp->CRH &= ~(0b1111 << (GPIO_CRL_SHIFT * (config->pinNumber - 8)));
            gpioTemp->CRH |= (0b1000 << (GPIO_CRL_SHIFT * (config->pinNumber - 8)));
            SET_BIT(gpioTemp->ODR, config->pinNumber);
        }
        else if (config->mode == GPIO_MODE_INPUT_PULLDOWN) {
            gpioTemp->CRH &= ~(0b1111 << (GPIO_CRL_SHIFT * (config->pinNumber - 8)));
            gpioTemp->CRH |= (0b1000 << (GPIO_CRL_SHIFT * (config->pinNumber - 8)));
            CLR_BIT(gpioTemp->ODR, config->pinNumber);
        }
        else if (config->mode == GPIO_MODE_INPUT_ANALOG) {
            gpioTemp->CRH &= ~(0b1111 << (GPIO_CRL_SHIFT * (config->pinNumber - 8)));
        }
        else if (config->mode == GPIO_MODE_OUTPUT_PUSHPULL) {
            gpioTemp->CRH &= ~(0b1111 << (GPIO_CRL_SHIFT * (config->pinNumber - 8)));
            gpioTemp->CRH |= (config->speed << (GPIO_CRL_SHIFT * (config->pinNumber - 8)));
            gpioTemp->CRH |= (0b00 << ((GPIO_CRL_SHIFT * (config->pinNumber - 8)) + 2));
        }
        else if (config->mode == GPIO_MODE_OUTPUT_OPENDRAIN) {
            gpioTemp->CRH &= ~(0b1111 << (GPIO_CRL_SHIFT * (config->pinNumber - 8)));
            gpioTemp->CRH |= (config->speed << (GPIO_CRL_SHIFT * (config->pinNumber - 8)));
            gpioTemp->CRH |= (0b01 << ((GPIO_CRL_SHIFT * (config->pinNumber - 8)) + 2));
        }
        else if (config->mode == GPIO_MODE_AF_PUSHPULL) {
            gpioTemp->CRH &= ~(0b1111 << (GPIO_CRL_SHIFT * (config->pinNumber - 8)));
            gpioTemp->CRH |= (config->speed << (GPIO_CRL_SHIFT * (config->pinNumber - 8)));
            gpioTemp->CRH |= (0b10 << ((GPIO_CRL_SHIFT * (config->pinNumber - 8)) + 2));
        }
        else if (config->mode == GPIO_MODE_AF_OPENDRAIN) {
            gpioTemp->CRH &= ~(0b1111 << (GPIO_CRL_SHIFT * (config->pinNumber - 8)));
            gpioTemp->CRH |= (config->speed << (GPIO_CRL_SHIFT * (config->pinNumber - 8)));
            gpioTemp->CRH |= (0b11 << ((GPIO_CRL_SHIFT * (config->pinNumber - 8)) + 2));
        }
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

