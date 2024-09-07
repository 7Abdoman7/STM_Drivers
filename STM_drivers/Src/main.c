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
#include "../MCAL/SYSTICK/SYSTICK_Interface.h"

int main(void) {
    MCAL_RCC_voidInit();
    MCAL_RCC_voidEnablePeripheral(RCC_APB2_GPIOC);

    MCAL_SYSTICK_voidInit();

    GPIO_Config_t led;
    led.port = GPIO_PORTC;
    led.pinNumber = 15;
    led.mode = GPIO_MODE_OUTPUT_PUSHPULL;
    led.speed = GPIO_SPEED_2MHZ;

    MCAL_GPIO_voidInit(&led);

    while (1) {
    	MCAL_GPIO_voidWritePin(GPIOC, 15, GPIO_PIN_SET);
    	MCAL_SYSTICK_voidDelayMilliSeconds(500);
    	MCAL_GPIO_voidWritePin(GPIOC, 15, GPIO_PIN_RESET);
    	MCAL_SYSTICK_voidDelayMilliSeconds(500);
    }

    return 0;
}
