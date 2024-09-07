/*
 * GPIO_Config.h
 *
 *  Created on: Aug 13, 2024
 *      Author: Abdo
 */

#include "../LIB/STD_TYPES.h"
#include "../LIB/BIT_MATH.h"

#ifndef GPIO_GPIO_CONFIG_H_
#define GPIO_GPIO_CONFIG_H_

typedef enum {
	GPIO_PIN_RESET,
	GPIO_PIN_SET,
} GPIO_Pin_State_t;

typedef enum {
	GPIO_PORTA,
	GPIO_PORTB,
	GPIO_PORTC,
} GPIO_Port_t;

typedef enum {
    GPIO_PIN0,
	GPIO_PIN1,
	GPIO_PIN2,
	GPIO_PIN3,
	GPIO_PIN4,
	GPIO_PIN5,
	GPIO_PIN6,
	GPIO_PIN7,
	GPIO_PIN8,
	GPIO_PIN9,
	GPIO_PIN10,
	GPIO_PIN11,
	GPIO_PIN12,
	GPIO_PIN13,
	GPIO_PIN14,
	GPIO_PIN15
} GPIO_Pin_t;

typedef enum {
    GPIO_MODE_INPUT_FLOATING,
    GPIO_MODE_INPUT_PULLUP,
	GPIO_MODE_INPUT_PULLDOWN,
    GPIO_MODE_INPUT_ANALOG,

    GPIO_MODE_OUTPUT_PUSHPULL,
    GPIO_MODE_OUTPUT_OPENDRAIN,

    GPIO_MODE_AF_PUSHPULL,
    GPIO_MODE_AF_OPENDRAIN,
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

#endif /* GPIO_GPIO_CONFIG_H_ */
