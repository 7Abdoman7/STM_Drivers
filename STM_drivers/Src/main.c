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

    MCAL_RCC_voidEnablePeripheral(RCC_APB2_GPIOC);
    MCAL_RCC_voidEnablePeripheral(RCC_APB2_GPIOA);

    GPIO_Config_t led;
    led.port = PORTC;
    led.pinNumber = 15;
    led.mode = GPIO_MODE_OUTPUT_PUSHPULL;
    led.speed = GPIO_SPEED_2MHZ;

    GPIO_Config_t btn;
    btn.port = PORTA;
    btn.pinNumber = 7;
    btn.mode = GPIO_MODE_INPUT_PULLUP;
    btn.speed = GPIO_SPEED_2MHZ;

    MCAL_GPIO_voidInit(&led);
    MCAL_GPIO_voidInit(&btn);

	MCAL_GPIO_voidWritePin(GPIOC, 15, GPIO_PIN_SET);

    while (1) {
    	/*
        if (MCAL_GPIO_voidReadPin(GPIOA, 7) == GPIO_PIN_SET) {
            MCAL_GPIO_voidWritePin(GPIOC, 15, GPIO_PIN_RESET);
        }
        else {
            MCAL_GPIO_voidWritePin(GPIOC, 15, GPIO_PIN_SET);
        }*/
    }

    return 0;
}
