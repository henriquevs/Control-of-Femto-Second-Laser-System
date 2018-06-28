/* ***************************************************************** */
/* File name:        lcd_hal.h                                       */
/* File description: File dedicated to the hardware abstraction layer*/
/*                   related to the LCD HARDWARE based on the KS006U */
/*                   controller                                      */
/* Author name:      Henrique Vicente Souza / Davi Rodrigues         */
/* Creation date:    16out2015                                       */
/* Revision date:    28june2016                                      */
/* ***************************************************************** */

#ifndef SOURCES_LCD_HAL_H_
#define SOURCES_LCD_HAL_H_

/* lcd basic commands list */
#define CMD_INIT_LCD        0x0F
#define CMD_CLEAR           0x01
#define CMD_NO_CURSOR       0x0C
#define CMD_CURSOR2R        0x06 /* cursor to right */
#define CMD_NO_CUR_NO_BLINK 0x38 /* no cursor, no blink */

void display7seg_initDisplay7seg();

/* ************************************************ */
/* Method name:        lcd_calcLogic                  */
/* Method description: Gets the binary of the 'n' left shift of a number*/
/* Input params:       ucBuffer ->char to be writen */
/*   					iShift -> logical shift to be done*/
/* Output params:       ilogic -> defines if a set is needed or not*/
/* ************************************************ */
int lcd_calcLogic(unsigned char ucBuffer, int iShift);

/* ************************************************ */
/* Method name:        lcd_SetClearLogic                  */
/* Method description: Define if the PIN is gona be set or clear*/
/* Input params:       ucBuffer ->char to be writen  */
/*   					iShift -> logical shift to be done*/
/* Output params:       n/a                         */
/* ************************************************ */
void lcd_setClearLogic(unsigned char ucBuffer, int iShift);

/* ************************************************ */
/* Method name:        lcd_initLcd                  */
/* Method description: Initialize the LCD function  */
/* Input params:       n/a                          */
/* Output params:      n/a                          */
/* ************************************************ */
void lcd_initLcd(void);

/* ************************************************ */
/* Method name:        lcd_writeData                */
/* Method description: Write data to be displayed   */
/* Input params:       ucData => char to be written */
/* Output params:      n/a                          */
/* ************************************************ */
void lcd_writeData(unsigned char ucData);

/* ************************************************ */
/* Method name:        lcd_sendCommand              */
/* Method description: Write command to LCD         */
/* Input params:       ucCmd=>command to be executed*/
/* Output params:      n/a                          */
/* ************************************************ */
void lcd_sendCommand(unsigned char ucCmd);

/* ************************************************ */
/* Method name:        lcd_WriteString              */
/* Method description: Write string to be displayed */
/* Input params:       cBuffer => string to be      */
/*                     written in LCD               */
/* Output params:      n/a                          */
/* ************************************************ */
void lcd_writeString(const char *cBuffer);

/* ************************************************ */
/* Method name:        lcd_setCursor                */
/* Method description: Set cursor line and column   */
/* Input params:       cLine = LINE0..LINE1         */
/*                     cColumn = COLUMN0..MAX_COLUMN*/
/* Output params:      n/a                          */
/* ************************************************ */
void lcd_setCursor(unsigned char cLine, unsigned char cColumn);

/* ************************************************ */
/* Method name:        lcd_dummyText                */
/* Method description: Write a dummy hard coded text*/
/* Input params:       n/a                          */
/* Output params:      n/a                          */
/* ************************************************ */
void lcd_dummyText(void);

/* ************************************************ */
/* Method name:        lcd_groupMembers             */
/* Method description: Write the group members      */
/* Input params:       n/a                          */
/* Output params:      n/a                          */
/* ************************************************ */
void lcd_groupMembers(void);

#endif /* SOURCES_LCD_HAL_H_ */
