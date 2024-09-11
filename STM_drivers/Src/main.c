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

#include "../ECUAL/LCD/LCD_Interface.h"

int main(void) {
    MCAL_RCC_voidInit();
    MCAL_RCC_voidEnablePeripheral(RCC_APB2_GPIOA);
    MCAL_RCC_voidEnablePeripheral(RCC_APB2_GPIOB);

    MCAL_SYSTICK_voidInit();

    LCD_t lcd;
    lcd.LCD_EN_Port = GPIO_PORTA;
    lcd.LCD_EN_Pin = GPIO_PIN1;
    lcd.LCD_RS_Port = GPIO_PORTA;
    lcd.LCD_RS_Pin = GPIO_PIN0;
    lcd.LCD_Mode = LCD_MODE_4_BIT;
    lcd.LCD_Columns = 16;
    lcd.LCD_Rows = 4;
    lcd.LCD_DATA_Port = GPIO_PORTA;
    lcd.LCD_DATA_Pin[0] = GPIO_PIN2;
    lcd.LCD_DATA_Pin[1] = GPIO_PIN3;
    lcd.LCD_DATA_Pin[2] = GPIO_PIN4;
    lcd.LCD_DATA_Pin[3] = GPIO_PIN5;

    GPIO_Config_t led;
    led.mode = GPIO_MODE_OUTPUT_PUSHPULL;
    led.port = GPIO_PORTB;
    led.speed = GPIO_SPEED_2MHZ;
    led.pinNumber = GPIO_PIN5;

    GPIO_Config_t led2;
    led2.mode = GPIO_MODE_OUTPUT_PUSHPULL;
    led2.port = GPIO_PORTB;
    led2.speed = GPIO_SPEED_2MHZ;
    led2.pinNumber = GPIO_PIN6;

    ECUAL_LCD_voidInit(&lcd);

    MCAL_GPIO_voidInit(&led);
    MCAL_GPIO_voidInit(&led2);

    MCAL_SYSTICK_voidDelayMilliSeconds(100);

    u8 arr[2] = {GPIO_PIN5, GPIO_PIN6};

    ECUAL_LCD_voidSendCommand(&lcd, LCD_CMD_CLEAR_DISPLAY);

    while (1) {/*
    	MCAL_GPIO_voidWritePinArray(led.port, arr, 2, 1);
        MCAL_SYSTICK_voidDelayMilliSeconds(1000);
        MCAL_GPIO_voidWritePinArray(led.port, arr, 2, 2);
        MCAL_SYSTICK_voidDelayMilliSeconds(1000);
        MCAL_GPIO_voidWritePinArray(led.port, arr, 2,3);
        MCAL_SYSTICK_voidDelayMilliSeconds(1000);
        MCAL_GPIO_voidWritePinArray(led.port, arr, 2, 0);
        MCAL_SYSTICK_voidDelayMilliSeconds(1000);
        */

    	ECUAL_LCD_voidSendChar(&lcd, 'A');
    	MCAL_SYSTICK_voidDelayMilliSeconds(1000);
    	ECUAL_LCD_voidSendCommand(&lcd, LCD_CMD_CLEAR_DISPLAY);
    	MCAL_SYSTICK_voidDelayMilliSeconds(1000);
    }

    return 0;
}

