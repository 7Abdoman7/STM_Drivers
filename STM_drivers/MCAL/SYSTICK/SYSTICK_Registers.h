/*
 * SYSTICK_Registers.h
 *
 *  Created on: Sep 7, 2024
 *      Author: Abdo
 */

#ifndef SYSTICK_SYSTICK_REGISTERS_H_
#define SYSTICK_SYSTICK_REGISTERS_H_

#include "../LIB/STD_TYPES.h"
#include "../LIB/BIT_MATH.h"

#define SYSTICK_BASE_ADDR		(0xE000E010)

typedef struct {
	u32 CTRL;
	u32 LOAD;
	u32 VAL;
	u32 CALIB;
} SYSTICK_RegDef_t;

#define SYSTICK 	((SYSTICK_RegDef_t *) SYSTICK_BASE_ADDR)

#define SYSTICK_CTRL_ENABLE_BIT			(0)
#define SYSTICK_CTRL_TICKINT_BIT		(1)
#define SYSTICK_CTRL_CLKSOURCE_BIT		(2)
#define SYSTICK_CTRL_COUNTFLAG_BIT		(16)

#endif /* SYSTICK_SYSTICK_REGISTERS_H_ */
