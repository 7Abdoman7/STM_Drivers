/*
 * SYSTICK_Config.h
 *
 *  Created on: Sep 7, 2024
 *      Author: Abdo
 */

#ifndef SYSTICK_SYSTICK_CONFIG_H_
#define SYSTICK_SYSTICK_CONFIG_H_

#include "SYSTICK_Registers.h"

typedef enum {
	SYSTICK_AHB_DIV1,
	SYSTICK_AHB_DIV8,
} SYSTICK_AHB_Mode_t;

typedef enum {
	SYSTICK_INT_PERIODIC,
	SYSTICK_INT_NON_PERIODIC,
} SYSTICK_INT_Mode_t;

#define SYSTICK_CLOCK_SOURCE	SYSTICK_AHB_DIV1
#define	SYSTEM_CLOCK			(8000000)

#define SYSTICK_INT_MODE		(SYSTICK_INT_NON_PERIODIC)

#endif /* SYSTICK_SYSTICK_CONFIG_H_ */
