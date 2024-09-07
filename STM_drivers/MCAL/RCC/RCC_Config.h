/**
  **************************
  * @file    : RCC_Config.h
  * @author  : Abdelrahman Elsayed Ahmed
  * @date	 : 12 / 5 / 2024
  * @version : V1.0
  **************************
*/

#include "../LIB/STD_TYPES.h"
#include "../LIB/BIT_MATH.h"

#ifndef RCC_RCC_CONFIG_H_
#define RCC_RCC_CONFIG_H_

typedef enum {
	RCC_HSI,
	RCC_HSE_CRYSTAL,
	RCC_HSE_RC,
	RCC_PLL_HSI,
	RCC_PLL_HSE,
} RCC_Clock_t;

typedef enum {
	PLL_PRESCALE_MUL_2		= 0b0000,
	PLL_PRESCALE_MUL_3      = 0b0001,
	PLL_PRESCALE_MUL_4      = 0b0010,
	PLL_PRESCALE_MUL_5      = 0b0011,
	PLL_PRESCALE_MUL_6      = 0b0100,
	PLL_PRESCALE_MUL_7      = 0b0101,
	PLL_PRESCALE_MUL_8      = 0b0110,
	PLL_PRESCALE_MUL_9      = 0b0111,
	PLL_PRESCALE_MUL_10     = 0b1000,
	PLL_PRESCALE_MUL_11     = 0b1001,
	PLL_PRESCALE_MUL_12     = 0b1010,
	PLL_PRESCALE_MUL_13     = 0b1011,
	PLL_PRESCALE_MUL_14     = 0b1100,
	PLL_PRESCALE_MUL_15     = 0b1101,
	PLL_PRESCALE_MUL_16     = 0b1110,
} RCC_PLL_Prescale_t;

typedef enum {
	AHB_PRESCALE_NOT_DIV 	= 0b0000,
	AHB_PRESCALE_DIV_2		= 0b1000,
	AHB_PRESCALE_DIV_4		= 0b1001,
	AHB_PRESCALE_DIV_8		= 0b1010,
	AHB_PRESCALE_DIV_16		= 0b1011,
	AHB_PRESCALE_DIV_64		= 0b1100,
	AHB_PRESCALE_DIV_128	= 0b1101,
	AHB_PRESCALE_DIV_256	= 0b1110,
	AHB_PRESCALE_DIV_512	= 0b1111,
} AHB_Prescale_t;

typedef enum {
	APB1_PRESCALE_NOT_DIV	= 0b000,
	APB1_PRESCALE_DIV_2		= 0b100,
	APB1_PRESCALE_DIV_4		= 0b101,
	APB1_PRESCALE_DIV_8		= 0b110,
	APB1_PRESCALE_DIV_16	= 0b111,
} APB1_Prescale_t;

typedef enum {
	APB2_PRESCALE_NOT_DIV	= 0b000,
	APB2_PRESCALE_DIV_2 	= 0b100,
	APB2_PRESCALE_DIV_4		= 0b101,
	APB2_PRESCALE_DIV_8		= 0b110,
	APB2_PRESCALE_DIV_16	= 0b111,
} APB2_Prescale_t;


#define CLOCK_TYPE			(RCC_HSI)
#define PLL_MULTI_TYPE		(PLL_MULTIPLIER_2)
#define AHB_PRESCALE		(AHB_PRESCALE_NOT_DIV)
#define APB1_PRESCALE		(APB1_PRESCALE_NOT_DIV)
#define APB2_PRESCALE		(APB2_PRESCALE_NOT_DIV)

#endif /* RCC_RCC_CONFIG_H_ */
