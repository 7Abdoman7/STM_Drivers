/**
  **************************
  * @file    : RCC_Registers.h
  * @author  : Abdelrahman Elsayed Ahmed
  * @date	 : 12 / 5 / 2024
  * @version : V1.0
  **************************
*/

#include "../LIB/STD_TYPES.h"
#include "../LIB/BIT_MATH.h"

#ifndef RCC_RCC_REGISTERS_H_
#define RCC_RCC_REGISTERS_H_

#define RCC_BASE_ADDR	(0x40021000)

typedef struct {
	volatile u32 CR;
	volatile u32 CFGR;
	volatile u32 CIR;
	volatile u32 APB2RSTR;
	volatile u32 APB1RSTR;
	volatile u32 AHBENR;
	volatile u32 APB2ENR;
	volatile u32 APB1ENR;
	volatile u32 BDCR;
	volatile u32 CSR;
} RCC_RegDef_t;

#define RCC		((RCC_RegDef_t *) RCC_BASE_ADDR)

#define RCC_CR_HSION_BIT 		(0)
#define RCC_CR_HSIRDY_BIT 		(1)
#define RCC_CR_HSEON_BIT		(16)
#define RCC_CR_HSERDY_BIT		(17)
#define RCC_CR_HSEBYP_BIT		(18)
#define RCC_CR_PLLON_BIT		(24)
#define	RCC_CR_PLLRDY_BIT		(25)

#define RCC_CFGR_SW0_BIT 		(0)
#define RCC_CFGR_SW1_BIT 		(1)
#define RCC_CFGR_PLLSRC_BIT		(16)

#define RCC_CFGR_HPRE_SHIFT 	(4)
#define RCC_CFGR_PPRE1_SHIFT	(8)
#define RCC_CFGR_PPRE2_SHIFT	(11)

#endif /* RCC_RCC_REGISTERS_H_ */
