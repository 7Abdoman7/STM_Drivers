/*
 * SYSTICK_Interface.H
 *
 *  Created on: Sep 7, 2024
 *      Author: Abdo
 */

#ifndef SYSTICK_SYSTICK_INTERFACE_H_
#define SYSTICK_SYSTICK_INTERFACE_H_

#include "SYSTICK_Config.h"
#include "SYSTICK_Registers.h"

void MCAL_SYSTICK_voidInit(void);

void MCAL_SYSTICK_voidDelayMilliSeconds(u32 ms);
void MCAL_SYSTICK_voidDelayMicroSeconds(u32 us);

u32 MCAL_SYSTICK_voidGetRemaningTime(void);
u32 MCAL_SYSTICK_voidGetElapsedTime(void);
void MCAL_SYSTICK_voidEnableInterupt(void);
void MCAL_SYSTICK_voidDisableInterupt(void);

void MCAL_SYSTICK_voidStartCountMillisecondsIT(u32 ms, void (*ptr)(void));
void MCAL_SYSTICK_voidStartCountMicrosecondsIT(u32 ms, void (*ptr)(void));

#endif /* SYSTICK_SYSTICK_INTERFACE_H_ */
