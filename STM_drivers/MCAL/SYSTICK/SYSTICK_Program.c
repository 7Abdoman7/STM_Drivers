/*
 * SYSTICK_Program.c
 *
 *  Created on: Sep 7, 2024
 *      Author: Abdo
 */

#include "SYSTICK_Interface.h"

void MCAL_SYSTICK_voidInit(void) {
	if (SYSTICK_CLOCK_SOURCE == SYSTICK_AHB_DIV1) {
		SET_BIT(SYSTICK->CTRL, SYSTICK_CTRL_CLKSOURCE_BIT);
	}
	else {
		CLR_BIT(SYSTICK->CTRL, SYSTICK_CTRL_CLKSOURCE_BIT);
	}
}

void MCAL_SYSTICK_voidDelayMilliSeconds(u32 ms) {
	SYSTICK->LOAD = (SYSTEM_CLOCK / 1000) * ms - 1;
	SYSTICK->VAL = 0;
	SET_BIT(SYSTICK->CTRL, SYSTICK_CTRL_ENABLE_BIT);

	while (!(GET_BIT(SYSTICK->CTRL, SYSTICK_CTRL_COUNTFLAG_BIT)));

	CLR_BIT(SYSTICK->CTRL, SYSTICK_CTRL_ENABLE_BIT);
	SYSTICK->VAL = 0;
}

void MCAL_SYSTICK_voidDelayMicroSeconds(u32 us) {
	SYSTICK->LOAD = (SYSTEM_CLOCK / 1000000) * us - 1;
	SYSTICK->VAL = 0;
	SET_BIT(SYSTICK->CTRL, SYSTICK_CTRL_ENABLE_BIT);

	while (!(GET_BIT(SYSTICK->CTRL, SYSTICK_CTRL_COUNTFLAG_BIT)));

	CLR_BIT(SYSTICK->CTRL, SYSTICK_CTRL_ENABLE_BIT);
	SYSTICK->VAL = 0;
}

u32 MCAL_SYSTICK_voidGetRemaningTime(void) {
	return SYSTICK->VAL;
}

u32 MCAL_SYSTICK_voidGetElapsedTime(void) {
	return SYSTICK->LOAD - SYSTICK->VAL;
}

void MCAL_SYSTICK_voidEnableInterupt(void) {
	SET_BIT(SYSTICK->CTRL, SYSTICK_CTRL_TICKINT_BIT);
}

void MCAL_SYSTICK_voidDisableInterupt(void) {
	CLR_BIT(SYSTICK->CTRL, SYSTICK_CTRL_TICKINT_BIT);
}

void (*SYSTICK_CallBack)(void);

void MCAL_SYSTICK_voidStartCountMillisecondsIT(u32 ms, void (*ptr)(void)) {
	SYSTICK_CallBack = ptr;

	SYSTICK->LOAD = (SYSTEM_CLOCK / 1000) * ms;
	SYSTICK->VAL = 0;

	MCAL_SYSTICK_voidEnableInterupt();
	SET_BIT(SYSTICK->CTRL, SYSTICK_CTRL_ENABLE_BIT);
}

void MCAL_SYSTICK_voidStartCountMicrosecondsIT(u32 us, void (*ptr)(void)) {
	SYSTICK_CallBack = ptr;

	SYSTICK->LOAD = (SYSTEM_CLOCK / 1000000) * us;
	SYSTICK->VAL = 0;

	MCAL_SYSTICK_voidEnableInterupt();
	SET_BIT(SYSTICK->CTRL, SYSTICK_CTRL_ENABLE_BIT);
}

void SysTick_Handler(void) {
	SYSTICK_CallBack();
	if (SYSTICK_INT_MODE == SYSTICK_INT_NON_PERIODIC) {
		CLR_BIT(SYSTICK->CTRL, SYSTICK_CTRL_ENABLE_BIT);
		MCAL_SYSTICK_voidDisableInterupt();
	}
	else {

	}
}
