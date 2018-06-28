/* ***************************************************************** */
/* File name:        lcd_hal.c                                       */
/* File description: File dedicated to the hardware abstraction layer*/
/*                   related to the LCD HARDWARE based on the KS006U */
/*                   controller                                      */
/* Author name:      Henrique Vicente Souza / Davi Rodrigues         */
/* Creation date:    16out2015                                       */
/* Revision date:    28june2016                                      */
/* ***************************************************************** */

#include "lcd_hal.h"
#include "es670_peripheral_board.h"
#include "util.h"

/* system includes */
//#include "fsl_clock_manager.h"
//#include "fsl_port_hal.h"
//#include "fsl_gpio_hal.h"
/* line and columns */
#define LINE0        0U
#define COLUMN0        0U

#define L0C0_BASE    0x80 /* line 0, column 0 */
#define L1C0_BASE    0xC0 /* line 1, column 0 */
#define MAX_COLUMN  15U

/* ********************************************************************* */
/* Method name:        lcd_calcLogic                                     */
/* Method description: Gets the binary of the 'n' left shift of a number */
/* Input params:       ucBuffer ->char to be writen                      */
/*                     iShift -> logical shift to be done                */
/* Output params:      ilogic -> defines if a set is needed or not       */
/* ********************************************************************* */
int lcd_calcLogic(unsigned char ucBuffer, int iShift)
{
   int iBuffer = ucBuffer;
   int iLogic = iBuffer % 2;
   while (iShift > 0)
   {
      iBuffer = iBuffer / 2;
      iLogic = iBuffer % 2;
      iShift--;
   }
   return iLogic;
}

/* ************************************************************* */
/* Method name:        lcd_SetClearLogic                         */
/* Method description: Define if the PIN is gona be set or clear */
/* Input params:       ucBuffer ->char to be writen              */
/*                     iShift -> logical shift to be done        */
/* Output params:      n/a                                       */
/* ************************************************************* */
void lcd_setClearLogic(unsigned char ucBuffer, int iShift)
{
   int iLogic = lcd_calcLogic(ucBuffer, iShift);

   if (iLogic == 1)
   {
      GPIOC_PSOR = GPIO_PSOR_PTSO((0x01U << (iShift)));
   } else
      GPIOC_PCOR = GPIO_PCOR_PTCO((0x01U << (iShift)));

   return;
}

/* ************************************************ */
/* Method name:        lcd_initLcd                  */
/* Method description: Initialize the LCD function  */
/* Input params:        n/a                         */
/* Output params:       n/a                         */
/* ************************************************ */
void lcd_initLcd(void)
{
   /* pins configured as outputs */

   /* un-gate port clock*/
   SIM_SCGC5 |= SIM_SCGC5_PORTC(CGC_CLOCK_ENABLED);

   /* set pin as gpio */
   PORTC_PCR8 |= PORT_PCR_MUX(LCD_RS_ALT);
   PORTC_PCR9 |= PORT_PCR_MUX(LCD_ENABLE_ALT);
   PORTC_PCR0 |= PORT_PCR_MUX(LCD_DATA_ALT);
   PORTC_PCR1 |= PORT_PCR_MUX(LCD_DATA_ALT);
   PORTC_PCR2 |= PORT_PCR_MUX(LCD_DATA_ALT);
   PORTC_PCR3 |= PORT_PCR_MUX(LCD_DATA_ALT);
   PORTC_PCR4 |= PORT_PCR_MUX(LCD_DATA_ALT);
   PORTC_PCR5 |= PORT_PCR_MUX(LCD_DATA_ALT);
   PORTC_PCR6 |= PORT_PCR_MUX(LCD_DATA_ALT);
   PORTC_PCR7 |= PORT_PCR_MUX(LCD_DATA_ALT);

   /* set pin as digital output */
   GPIOC_PDDR |=
         GPIO_PDDR_PDD(
               LCD_RS_DIR | LCD_ENABLE_DIR | LCD_DATA_DB0_PIN | LCD_DATA_DB1_DIR | LCD_DATA_DB2_DIR | LCD_DATA_DB3_DIR | LCD_DATA_DB4_DIR | LCD_DATA_DB5_DIR | LCD_DATA_DB6_DIR | LCD_DATA_DB7_DIR);

   // turn-on LCD, with no cursor and no blink
   lcd_sendCommand(CMD_NO_CUR_NO_BLINK);

   // init LCD
   lcd_sendCommand(CMD_INIT_LCD);

   // clear LCD
   lcd_sendCommand(CMD_CLEAR);

   // LCD with no cursor
   lcd_sendCommand(CMD_NO_CURSOR);

   // cursor shift to right
   lcd_sendCommand(CMD_CURSOR2R);

   // set inicial position
   lcd_setCursor(0, 0);
}

/* ************************************************ */
/* Method name:        lcd_write2Lcd                */
/* Method description: Send command or data to LCD  */
/* Input params:       ucBuffer => char to be send  */
/*                     cDataType=>command LCD_RS_CMD*/
/*                     or data LCD_RS_DATA          */
/* Output params:      n/a                          */
/* ************************************************ */
void lcd_write2Lcd(unsigned char ucBuffer, unsigned char cDataType)
{
   /* writing data or command */
   if (LCD_RS_CMD == cDataType)
      /* will send a command */
      GPIOC_PCOR = GPIO_PCOR_PTCO((0x01U << LCD_RS_PIN));
   else
      /* will send data */
      GPIOC_PSOR = GPIO_PSOR_PTSO((0x01U << LCD_RS_PIN));

   /* write in the LCD bus */
   lcd_setClearLogic(ucBuffer, LCD_DATA_DB0_PIN);
   lcd_setClearLogic(ucBuffer, LCD_DATA_DB1_PIN);
   lcd_setClearLogic(ucBuffer, LCD_DATA_DB2_PIN);
   lcd_setClearLogic(ucBuffer, LCD_DATA_DB3_PIN);
   lcd_setClearLogic(ucBuffer, LCD_DATA_DB4_PIN);
   lcd_setClearLogic(ucBuffer, LCD_DATA_DB5_PIN);
   lcd_setClearLogic(ucBuffer, LCD_DATA_DB6_PIN);
   lcd_setClearLogic(ucBuffer, LCD_DATA_DB7_PIN);

   /* enable, delay, disable LCD */
   /* this generates a pulse in the enable pin */
   GPIOC_PSOR = GPIO_PSOR_PTSO((0x01U << LCD_ENABLE_PIN));
   util_genDelay1ms();
   GPIOC_PCOR = GPIO_PCOR_PTCO((0x01U << LCD_ENABLE_PIN));
   util_genDelay1ms();
   util_genDelay1ms();
}

/* ************************************************ */
/* Method name:        lcd_writeData                */
/* Method description: Write data to be displayed   */
/* Input params:       ucData => char to be written */
/* Output params:      n/a                          */
/* ************************************************ */
void lcd_writeData(unsigned char ucData)
{
   /* just a relay to send data */
   lcd_write2Lcd(ucData, LCD_RS_DATA);
}

/* ************************************************ */
/* Method name:        lcd_sendCommand              */
/* Method description: Write command to LCD         */
/* Input params:       ucCmd=>command to be executed*/
/* Output params:      n/a                          */
/* ************************************************ */
void lcd_sendCommand(unsigned char ucCmd)
{
   /* just a relay to send command */
   lcd_write2Lcd(ucCmd, LCD_RS_CMD);
}

/* ************************************************ */
/* Method name:        lcd_setCursor                */
/* Method description: Set cursor line and column   */
/* Input params:       cLine = LINE0..LINE1         */
/*                     cColumn = COLUMN0..MAX_COLUMN*/
/* Output params:       n/a                         */
/* ************************************************ */
void lcd_setCursor(unsigned char cLine, unsigned char cColumn)
{
   char cCommand;

   if (LINE0 == cLine)
      /* line 0 */
      cCommand = L0C0_BASE;
   else
      /* line 1 */
      cCommand = L1C0_BASE;

   /* maximum MAX_COLUMN columns */
   cCommand += (cColumn & MAX_COLUMN);

   // send the command to set the cursor
   lcd_sendCommand(cCommand);
}

/* ************************************************ */
/* Method name:        lcd_writeString              */
/* Method description: Write string to be displayed */
/* Input params:       cBuffer => string to be      */
/*                     written in LCD               */
/* Output params:      n/a                          */
/* ************************************************ */
void lcd_writeString(const char *cBuffer)
{
   while (*cBuffer)
   {
      lcd_writeData(*cBuffer++);
   };
}

/* ************************************************ */
/* Method name:        lcd_FEMTO                    */
/* Method description: Write the group members      */
/* Input params:       n/a                          */
/* Output params:      n/a                          */
/* ************************************************ */
void lcd_FEMTO(void)
{
   // clear LCD
   lcd_sendCommand(CMD_CLEAR);

   lcd_setCursor(0, 0);
   lcd_writeString("FEMTO PROJECT");
   lcd_setCursor(1, 0);
   lcd_writeString("Physics is here!!");
}
