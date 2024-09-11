/*
 * LCD_Config.h
 *
 *  Created on: Sep 7, 2024
 *      Author: Abdo
 */

#ifndef LCD_LCD_CONFIG_H_
#define LCD_LCD_CONFIG_H_

#include "../MCAL/GPIO/GPIO_Interface.h"
#include "../MCAL/SYSTICK/SYSTICK_Interface.h"

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

#define LCD_CMD_CLEAR_DISPLAY       	(0x01)
#define LCD_CMD_RETURN_HOME          	(0x02)
#define LCD_CMD_ENTRY_MODE_SET       	(0x06)
#define LCD_CMD_DISPLAY_OFF          	(0x08)
#define LCD_CMD_DISPLAY_ON           	(0x0C)
#define LCD_CMD_DISPLAY_ON_CURSOR_ON 	(0x0E)
#define LCD_CMD_DISPLAY_ON_BLINK_ON  	(0x0F)
#define LCD_CMD_MOVE_CURSOR_LEFT     	(0x10)
#define LCD_CMD_MOVE_CURSOR_RIGHT    	(0x14)
#define LCD_CMD_SET_CURSOR_POSITION  	(0x80)


#endif /* LCD_LCD_CONFIG_H_ */
