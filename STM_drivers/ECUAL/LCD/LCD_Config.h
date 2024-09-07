/*
 * LCD_Config.h
 *
 *  Created on: Sep 7, 2024
 *      Author: Abdo
 */

#ifndef LCD_LCD_CONFIG_H_
#define LCD_LCD_CONFIG_H_

#include "../MCAL/GPIO/GPIO_Interface.h"

typedef enum {
    LCD_MODE_8_BIT,
    LCD_MODE_4_BIT,
} LCD_Mode_t;

typedef struct {
    GPIO_Port_t LCD_EN_Port;
    GPIO_Pin_t LCD_EN_Pin;

    GPIO_Port_t LCD_RS_Port;
    GPIO_Pin_t LCD_RS_Pin;

    GPIO_Port_t LCD_DATA_Port;
    GPIO_Pin_t LCD_DATA_Pin[8];

    LCD_Mode_t LCD_Mode;

    u8 LCD_Rows;
    u8 LCD_Columns;
} LCD_t;

#endif /* LCD_LCD_CONFIG_H_ */
