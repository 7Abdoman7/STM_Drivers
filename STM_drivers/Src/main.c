/**
  ******************************************************************************
  * @file    : main.c
  * @author  : Abdelrahman Elsayed Ahmed
  * @date    : 9 / 5 / 2024
  * @version : V1.0
  ******************************************************************************
*/

#include "../MCAL/RCC/RCC_Interface.h"
#include "../MCAL/GPIO/GPIO_Interface.h"


int main(void) {
	MCAL_RCC_voidInit();

	MCAL_RCC_voidEnablePeripheral(RCC_APB2_GPIOA);
	MCAL_RCC_voidEnablePeripheral(RCC_APB2_GPIOC);

	GPIO_Config_t GPIO_Config;
	GPIO_Config_t led;

	GPIO_Config.port = PORTA;
	GPIO_Config.pinNumber = 5;
    GPIO_Config.mode = GPIO_MODE_OUTPUT_PUSHPULL;
    GPIO_Config.speed = GPIO_SPEED_2MHZ;
    MCAL_GPIO_voidInit(&GPIO_Config);
    MCAL_GPIO_voidWritePin(GPIOA, 5, GPIO_PIN_SET);


	led.port = PORTC;
	led.pinNumber = 13;
    led.mode = GPIO_MODE_OUTPUT_PUSHPULL;
    led.speed = GPIO_SPEED_2MHZ;
    MCAL_GPIO_voidInit(&led);
    MCAL_GPIO_voidWritePin(GPIOC, 13, GPIO_PIN_SET);

    while (1) {}

    return 0;
}
