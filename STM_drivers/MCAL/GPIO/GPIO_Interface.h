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


void MCAL_GPIO_voidInit(GPIO_Config_t * config);
GPIO_Pin_State_t MCAL_GPIO_voidReadPin(GPIO_RegDef_t* GPIOx, u8 pinNumber);
void MCAL_GPIO_voidWritePin(u8 port, u8 pinNumber, u8 value);
void MCAL_GPIO_voidWritePinArray(u8 port, u8* pinArray, u8 size, u8 value);

#endif /* GPIO_GPIO_INTERFACE_H_ */
