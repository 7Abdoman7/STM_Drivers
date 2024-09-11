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

    u8 pinCount = (LCD->LCD_Mode == LCD_MODE_8_BIT) ? 8 : 4;
    for (u8 i = 0; i < pinCount; i++) {
        gpioTemp.port = LCD->LCD_DATA_Port;
        gpioTemp.pinNumber = LCD->LCD_DATA_Pin[i];
        MCAL_GPIO_voidInit(&gpioTemp);
    }

    MCAL_SYSTICK_voidDelayMilliSeconds(50);

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


    MCAL_SYSTICK_voidDelayMilliSeconds(50);
}

static void ECUAL_LCD_voidSendPulse(LCD_t *LCD) {
    MCAL_GPIO_voidWritePin(LCD->LCD_EN_Port, LCD->LCD_EN_Pin, GPIO_PIN_SET);
    MCAL_SYSTICK_voidDelayMilliSeconds(1);
    MCAL_GPIO_voidWritePin(LCD->LCD_EN_Port, LCD->LCD_EN_Pin, GPIO_PIN_RESET);
    MCAL_SYSTICK_voidDelayMilliSeconds(1);
}

void ECUAL_LCD_voidSendCommand(LCD_t *LCD, u8 cmd) {
    MCAL_GPIO_voidWritePin(LCD->LCD_RS_Port, LCD->LCD_RS_Pin, GPIO_PIN_RESET);

    if (LCD->LCD_Mode == LCD_MODE_4_BIT) {
        u8 highNibble = (cmd >> 4) & 0x0F;
        MCAL_GPIO_voidWritePinArray(LCD->LCD_DATA_Port, LCD->LCD_DATA_Pin, 4, highNibble);
        ECUAL_LCD_voidSendPulse(LCD);

        u8 lowNibble = cmd & 0x0F;
        MCAL_GPIO_voidWritePinArray(LCD->LCD_DATA_Port, LCD->LCD_DATA_Pin, 4, lowNibble);
        ECUAL_LCD_voidSendPulse(LCD);
    }
    else {
        MCAL_GPIO_voidWritePinArray(LCD->LCD_DATA_Port, LCD->LCD_DATA_Pin, 8, cmd);
        ECUAL_LCD_voidSendPulse(LCD);
    }

    MCAL_SYSTICK_voidDelayMilliSeconds(2);
}

void ECUAL_LCD_voidSendChar(LCD_t *LCD, u8 data) {
    MCAL_GPIO_voidWritePin(LCD->LCD_RS_Port, LCD->LCD_RS_Pin, GPIO_PIN_SET);

    if (LCD->LCD_Mode == LCD_MODE_4_BIT) {
        u8 highNibble = (data >> 4) & 0x0F;
        MCAL_GPIO_voidWritePinArray(LCD->LCD_DATA_Port, LCD->LCD_DATA_Pin, 4, highNibble);
        ECUAL_LCD_voidSendPulse(LCD);

        u8 lowNibble = data & 0x0F;
        MCAL_GPIO_voidWritePinArray(LCD->LCD_DATA_Port, LCD->LCD_DATA_Pin, 4, lowNibble);
        ECUAL_LCD_voidSendPulse(LCD);
    }
    else {
        MCAL_GPIO_voidWritePinArray(LCD->LCD_DATA_Port, LCD->LCD_DATA_Pin, 8, data);
        ECUAL_LCD_voidSendPulse(LCD);
    }

    MCAL_SYSTICK_voidDelayMilliSeconds(2);
}


void ECUAL_LCD_voidSendString(LCD_t *LCD, u8* str) {
    while (*str) {
        ECUAL_LCD_voidSendChar(LCD, *str++);
    }
}

void ECUAL_LCD_voidSendString_XY(LCD_t *LCD, u8* str, u8 row, u8 col) {
    u8 address = (row == 0) ? 0x80 + col : 0xC0 + col;
    ECUAL_LCD_voidSendCommand(LCD, address);
    ECUAL_LCD_voidSendString(LCD, str);
}

void ECUAL_LCD_voidSendNumber(LCD_t *LCD, s32 number) {
    u8 buffer[12];
    itoa(number, buffer, 10);
    ECUAL_LCD_voidSendString(LCD, buffer);
}

void ECUAL_LCD_voidSendFloat(LCD_t *LCD, f32 number) {
    s32 intPart = (s32) number;
    s32 fracPart = (s32) ((number - intPart) * 100);

    ECUAL_LCD_voidSendNumber(LCD, intPart);
    ECUAL_LCD_voidSendChar(LCD, '.');
    ECUAL_LCD_voidSendNumber(LCD, fracPart);
}


