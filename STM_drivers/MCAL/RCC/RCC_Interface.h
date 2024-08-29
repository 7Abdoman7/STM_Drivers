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
    RCC_AHB_DMA1     = 0x10000,
    RCC_AHB_DMA2     = 0x10001,
    RCC_AHB_SRAM     = 0x10002,
    RCC_AHB_FLITF    = 0x10004,
    RCC_AHB_CRC      = 0x10006,
    RCC_AHB_OTGFS    = 0x10012,
    RCC_AHB_ETHMAC   = 0x10014,
    RCC_AHB_ETHMACTX = 0x10015,
    RCC_AHB_ETHMACRX = 0x10016,

    RCC_APB1_TIM2    = 0x20000,
    RCC_APB1_TIM3    = 0x20001,
    RCC_APB1_TIM4    = 0x20002,
    RCC_APB1_TIM5    = 0x20003,
    RCC_APB1_TIM6    = 0x20004,
    RCC_APB1_TIM7    = 0x20005,
    RCC_APB1_WWDG    = 0x20011,
    RCC_APB1_SPI2    = 0x20014,
    RCC_APB1_SPI3    = 0x20015,
    RCC_APB1_USART2  = 0x20017,
    RCC_APB1_USART3  = 0x20018,
    RCC_APB1_UART4   = 0x20019,
    RCC_APB1_UART5   = 0x2001A,
    RCC_APB1_I2C1    = 0x2001B,
    RCC_APB1_I2C2    = 0x2001C,
    RCC_APB1_CAN1    = 0x20025,
    RCC_APB1_CAN2    = 0x20026,
    RCC_APB1_BKP     = 0x20027,
    RCC_APB1_PWR     = 0x20028,
    RCC_APB1_DAC     = 0x20029,

    RCC_APB2_AFIO    = 0x30000,
    RCC_APB2_GPIOA   = 0x30002,
    RCC_APB2_GPIOB   = 0x30003,
    RCC_APB2_GPIOC   = 0x30004,
    RCC_APB2_GPIOD   = 0x30005,
    RCC_APB2_GPIOE   = 0x30006,
    RCC_APB2_ADC1    = 0x30009,
    RCC_APB2_TIM1    = 0x3000A,
    RCC_APB2_SPI1    = 0x3000B,
    RCC_APB2_USART1  = 0x30014,
} RCC_PeripheralId_t;


#define RCC_AHB_ID		(0x1)
#define RCC_APB1_ID		(0x2)
#define RCC_APB2_ID		(0x3)

void MCAL_RCC_voidInit(void);
void MCAL_RCC_voidEnablePeripheral(const RCC_PeripheralId_t peripheralId);
void MCAL_RCC_voidDisablePeripheral(const RCC_PeripheralId_t peripheralId);


#endif /* RCC_RCC_INTERFACE_H_ */
