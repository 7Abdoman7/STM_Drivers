/*
 * GPIO_Interface.h
 *
 *  Created on: Aug 13, 2024
 *      Author: Abdo
 */

#include "../LIB/STD_TYPES.h"
#include "../LIB/BIT_MATH.h"

#include "GPIO_Registers.h"
#include "GPIO_Config.h"

#ifndef GPIO_GPIO_INTERFACE_H_
#define GPIO_GPIO_INTERFACE_H_

typedef enum {
	PORTA,
	PORTB,
	PORTC,
} GPIO_Port_t;

typedef enum {
    PIN0,
    PIN1,
    PIN2,
    PIN3,
    PIN4,
    PIN5,
    PIN6,
    PIN7,
    PIN8,
    PIN9,
    PIN10,
    PIN11,
    PIN12,
    PIN13,
    PIN14,
    PIN15
} GPIO_Pin_t;

typedef enum {
    GPIO_MODE_INPUT_FLOATING	= 0b01,
    GPIO_MODE_INPUT_PULLUP		= 0b10,
	GPIO_MODE_INPUT_PULLDOWN	= 0b10,
    GPIO_MODE_INPUT_ANALOG		= 0b00,

    GPIO_MODE_OUTPUT_PUSHPULL	= 0b00,
    GPIO_MODE_OUTPUT_OPENDRAIN	= 0b01,

    GPIO_MODE_AF_PUSHPULL		= 0b10,
    GPIO_MODE_AF_OPENDRAIN		= 0b11,
} GPIO_Mode_t;

typedef enum {
	GPIO_SPEED_2MHZ 	= 0b10,
	GPIO_SPEED_10MHZ	= 0b01,
	GPIO_SPEED_50MHZ	= 0b11,
} GPIO_Speed_t;

typedef struct {
	GPIO_Port_t port;
	GPIO_Pin_t pinNumber;
	GPIO_Mode_t mode;
	GPIO_Speed_t speed;
} GPIO_Config_t;

void MCAL_GPIO_voidInit(GPIO_Config_t * config);
GPIO_Pin_State_t MCAL_GPIO_voidReadPin(GPIO_RegDef_t* GPIOx, u8 pinNumber);
void MCAL_GPIO_voidWritePin(GPIO_RegDef_t* GPIOx, u8 pinNumber, u8 value);

#endif /* GPIO_GPIO_INTERFACE_H_ */
