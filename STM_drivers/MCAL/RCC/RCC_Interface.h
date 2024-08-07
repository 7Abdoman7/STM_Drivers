 /**
  **************************
  * @file    : RCC_Interface.h
  * @author  : Abdelrahman Elsayed Ahmed
  * @date	 : 5 / 8 / 2024
  * @version : V1.0
  **************************
*/

#include "../LIB/STD_TYPES.h"
#include "../LIB/BIT_MATH.h"

#include "RCC_Config.h"
#include "RCC_Registers.h"

#ifndef RCC_RCC_INTERFACE_H_
#define RCC_RCC_INTERFACE_H_

typedef enum {
    RCC_AHB_DMA1 = 0x10000,
    RCC_AHB_DMA2,
    RCC_AHB_SRAM,
    RCC_AHB_FLITF,
    RCC_AHB_CRC,
    RCC_AHB_FSMC,
    RCC_AHB_SDIO,

    RCC_APB1_TIM2 = 0x20000,
    RCC_APB1_TIM3,
    RCC_APB1_TIM4,
    RCC_APB1_TIM5,
    RCC_APB1_TIM6,
    RCC_APB1_TIM7,
    RCC_APB1_TIM12,
    RCC_APB1_TIM13,
    RCC_APB1_TIM14,
    RCC_APB1_WWDG,
    RCC_APB1_SPI2,
    RCC_APB1_SPI3,
    RCC_APB1_USART2,
    RCC_APB1_USART3,
    RCC_APB1_UART4,
    RCC_APB1_UART5,
    RCC_APB1_I2C1,
    RCC_APB1_I2C2,
    RCC_APB1_USB,
    RCC_APB1_CAN,
    RCC_APB1_BKP,
    RCC_APB1_PWR,
    RCC_APB1_DAC,

    RCC_APB2_AFIO = 0x30000,
    RCC_APB2_GPIOA,
    RCC_APB2_GPIOB,
    RCC_APB2_GPIOC,
    RCC_APB2_GPIOD,
    RCC_APB2_GPIOE,
    RCC_APB2_GPIOF,
    RCC_APB2_GPIOG,
    RCC_APB2_ADC1,
    RCC_APB2_ADC2,
    RCC_APB2_TIM1,
    RCC_APB2_SPI1,
    RCC_APB2_TIM8,
    RCC_APB2_USART1,
    RCC_APB2_ADC3,
    RCC_APB2_TIM9,
    RCC_APB2_TIM10,
    RCC_APB2_TIM11
} RCC_PeripheralId_t;

#define RCC_AHB_ID		(0x1)
#define RCC_APB1_ID		(0x2)
#define RCC_APB2_ID		(0x3)

void MCAL_RCC_voidInit(void);
void MCAL_RCC_voidEnablePeripheral(RCC_PeripheralId_t u8PeripheralId);
void MCAL_RCC_voidDisablePeripheral(RCC_PeripheralId_t u8PeripheralId);


#endif /* RCC_RCC_INTERFACE_H_ */
