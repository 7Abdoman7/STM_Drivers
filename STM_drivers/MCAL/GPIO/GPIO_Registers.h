/*
 * GPIO_Registers.h
 *
 *  Created on: Aug 13, 2024
 *      Author: Abdo
 */

#include "../LIB/STD_TYPES.h"
#include "../LIB/BIT_MATH.h"

#ifndef GPIO_GPIO_REGISTERS_H_
#define GPIO_GPIO_REGISTERS_H_

#define GPIOA_ADDR_BASE             (0x40010800)
#define GPIOB_ADDR_BASE             (0x40010C00)

typedef struct {
	volatile u32 CRL;
	volatile u32 CRH;
	volatile u32 IDR;
	volatile u32 ODR;
	volatile u32 BSRR;
	volatile u32 BRR;
	volatile u32 LCKR;
} GPIO_RegDef_t;

#define GPIOA                       ((GPIO_RegDef_t*) GPIOA_ADDR_BASE)
#define GPIOB                       ((GPIO_RegDef_t*) GPIOB_ADDR_BASE)
#define GPIOC                       ((GPIO_RegDef_t*) GPIOB_ADDR_BASE)

#define GPIO_CRL_SHIFT				(4)

#endif /* GPIO_GPIO_REGISTERS_H_ */
