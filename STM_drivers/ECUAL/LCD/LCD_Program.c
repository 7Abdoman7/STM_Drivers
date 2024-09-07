/*
 * LCD_Program.c
 *
 *  Created on: Sep 7, 2024
 *      Author: Abdo
 */


#include "LCD_Interface.h"

void ECUAL_LCD_voidInit(LCD_t *LCD) {
    GPIO_Config_t gpioTemp;

    gpioTemp.port = LCD->LCD_EN_Port;
    gpioTemp.pinNumber = LCD->LCD_EN_Pin;
    gpioTemp.mode = GPIO_MODE_OUTPUT_PUSHPULL;
    gpioTemp.speed = GPIO_SPEED_2MHZ;
    MCAL_GPIO_voidInit(&gpioTemp);

    gpioTemp.port = LCD->LCD_RS_Port;
    gpioTemp.pinNumber = LCD->LCD_RS_Pin;
    MCAL_GPIO_voidInit(&gpioTemp);

    for (u8 i = 0; i < (LCD->LCD_Mode == LCD_MODE_8_BIT ? 8 : 4); i++) {
        gpioTemp.port = LCD->LCD_DATA_Port;
        gpioTemp.pinNumber = LCD->LCD_DATA_Pin[i];
        MCAL_GPIO_voidInit(&gpioTemp);
    }

   // MCAL_Delay_ms(50);

    if (LCD->LCD_Mode == LCD_MODE_8_BIT) {
        ECUAL_LCD_voidSendCommand(LCD, 0x38);
    }
    else {
        ECUAL_LCD_voidSendCommand(LCD, 0x33);
        ECUAL_LCD_voidSendCommand(LCD, 0x32);
        ECUAL_LCD_voidSendCommand(LCD, 0x28);
    }

    ECUAL_LCD_voidSendCommand(LCD, 0x0C);
    ECUAL_LCD_voidSendCommand(LCD, 0x01);
    ECUAL_LCD_voidSendCommand(LCD, 0x06);

    //MCAL_Delay_ms(2);
}


void ECUAL_LCD_voidSendCommand(LCD_t *LCD, u8 cmd) {

}

void ECUAL_LCD_voidSendChar(LCD_t *LCD, u8 data) {

}

void ECUAL_LCD_voidSendString(LCD_t *LCD, u8* str) {

}

void ECUAL_LCD_voidSendString_XY(LCD_t *LCD, u8* str, u8 row, u8 col) {

}

void ECUAL_LCD_voidSendNumber(LCD_t *LCD, s32 number) {

}

void ECUAL_LCD_voidSendFloat(LCD_t *LCD, f32 number) {

}

