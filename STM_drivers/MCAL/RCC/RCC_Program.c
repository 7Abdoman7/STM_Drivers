/**************************
  * @file    : RCC_Program.c
  * @author  : Abdelrahman Elsayed Ahmed
  * @date	 : 12 / 5 / 2024
  * @version : V1.0
  **************************
*/

#include "RCC_Interface.h"

void MCAL_RCC_voidInit(void) {
	switch (CLOCK_TYPE) {
		case RCC_HSI:
			SET_BIT(RCC->CR, RCC_CR_HSION_BIT);
			while (!GET_BIT(RCC->CR, RCC_CR_HSIRDY_BIT));
			CLR_BIT(RCC->CFGR, RCC_CFGR_SW1_BIT);
			CLR_BIT(RCC->CFGR, RCC_CFGR_SW0_BIT);
		break;
		case RCC_HSE_CRYSTAL:
			SET_BIT(RCC->CR, RCC_CR_HSEON_BIT);
			while (!GET_BIT(RCC->CR, RCC_CR_HSERDY_BIT));
			CLR_BIT(RCC->CR, RCC_CR_HSEBYP_BIT);
			CLR_BIT(RCC->CFGR, RCC_CFGR_SW1_BIT);
			SET_BIT(RCC->CFGR, RCC_CFGR_SW0_BIT);
		break;
		case RCC_HSE_RC:
			SET_BIT(RCC->CR, RCC_CR_HSEON_BIT);
			SET_BIT(RCC->CR, RCC_CR_HSEBYP_BIT);
			CLR_BIT(RCC->CFGR, RCC_CFGR_SW1_BIT);
			SET_BIT(RCC->CFGR, RCC_CFGR_SW0_BIT);
		break;
		case RCC_PLL_HSI:
			CLR_BIT(RCC->CFGR, RCC_CFGR_PLLSRC_BIT);
			SET_BIT(RCC->CR, RCC_CR_PLLON_BIT);
			while (!GET_BIT(RCC->CR, RCC_CR_PLLRDY_BIT));
			SET_BIT(RCC->CFGR, RCC_CFGR_SW1_BIT);
			CLR_BIT(RCC->CFGR, RCC_CFGR_SW0_BIT);
		break;
		case RCC_PLL_HSE:
			SET_BIT(RCC->CFGR, RCC_CFGR_PLLSRC_BIT);
			SET_BIT(RCC->CR, RCC_CR_PLLON_BIT);
			while (!GET_BIT(RCC->CR, RCC_CR_PLLRDY_BIT));
			SET_BIT(RCC->CFGR, RCC_CFGR_SW1_BIT);
			CLR_BIT(RCC->CFGR, RCC_CFGR_SW0_BIT);
		break;
		default:
		break;
	}

	RCC->CFGR |= (AHB_PRESCALE  << RCC_CFGR_HPRE_SHIFT);
	RCC->CFGR |= (APB1_PRESCALE << RCC_CFGR_PPRE1_SHIFT);
	RCC->CFGR |= (APB2_PRESCALE << RCC_CFGR_PPRE2_SHIFT);
}

void MCAL_RCC_voidEnablePeripheral(RCC_BusId_t u8BusId, u8 u8PeripheralId) {
	switch (u8BusId) {
		case RCC_BUS_AHB:
			SET_BIT(RCC->AHBENR ,u8PeripheralId);
		break;
		case RCC_BUS_APB1:
			SET_BIT(RCC->APB1ENR ,u8PeripheralId);
		break;
		case RCC_BUS_APB2:
			SET_BIT(RCC->APB2ENR ,u8PeripheralId);
		break;
		default:
		break;
	}
}

void MCAL_RCC_voidDisablePeripheral(RCC_BusId_t u8BusId, u8 u8PeripheralId) {
	switch (u8BusId) {
		case RCC_BUS_AHB:
			CLR_BIT(RCC->AHBENR ,u8PeripheralId);
		break;
		case RCC_BUS_APB1:
			CLR_BIT(RCC->APB1ENR ,u8PeripheralId);
		break;
		case RCC_BUS_APB2:
			CLR_BIT(RCC->APB2ENR ,u8PeripheralId);
		break;
		default:
		break;
	}
}
