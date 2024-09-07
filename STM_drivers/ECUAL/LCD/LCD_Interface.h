/*
 * LCD_Interface.h
 *
 *  Created on: Sep 7, 2024
 *      Author: Abdo
 */

#ifndef LCD_LCD_INTERFACE_H_
#define LCD_LCD_INTERFACE_H_

#include "LCD_Config.h"

void ECUAL_LCD_voidInit(LCD_t *LCD);
void ECUAL_LCD_voidSendCommand(LCD_t *LCD, u8 cmd);
void ECUAL_LCD_voidSendChar(LCD_t *LCD, u8 data);
void ECUAL_LCD_voidSendString(LCD_t *LCD, u8* str);
void ECUAL_LCD_voidSendString_XY(LCD_t *LCD, u8* str, u8 row, u8 col);
void ECUAL_LCD_voidSendNumber(LCD_t *LCD, s32 number);
void ECUAL_LCD_voidSendFloat(LCD_t *LCD, f32 number);

#endif /* LCD_LCD_INTERFACE_H_ */
