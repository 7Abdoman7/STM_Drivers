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
	RCC_BUS_AHB,
	RCC_BUS_APB1,
	RCC_BUS_APB2,
} RCC_BusId_t;


void MCAL_RCC_voidInit(void);
void MCAL_RCC_voidEnablePeripheral(RCC_BusId_t u8BusId, u8 u8PeripheralId);
void MCAL_RCC_voidDisablePeripheral(RCC_BusId_t u8BusId, u8 u8PeripheralId);


#endif /* RCC_RCC_INTERFACE_H_ */
