/* *************************************************************** */
/* File name:        encoder.c                                     */
/* File description: This file has a couple of useful functions to */
/*                   control encoder functions                     */
/* Author name:      Henrique Vicente Souza / Davi Rodrigues       */
/* Creation date:    06april2016                                   */
/* Revision date:    28june2016                                    */
/* *************************************************************** */

#include "mcg_hal.h"
#include "encoder_hal.h"
#include "es670_peripheral_board.h"
#include "lcd_hal.h"
#include "tc_hal.h"
#include "stdio.h"

/* ************************************************ */
/* Method name:        encoder_initEncoder          */
/* Method description: As the hardware board was    */
/*                     designed with 2 infrared LEDs*/
/* 					   and clocks,                  */
/* 					   this method configures all   */
/* 					   displays and segments  		*/
/* Input params:       n/a						    */
/* Outpu params:       n/a                          */
/* ************************************************ */
void encoder_initEncoder()
{
   /* un-gate port clock*/
   SIM_SCGC5 |= SIM_SCGC5_PORTE(CGC_CLOCK_ENABLED);

   /* set pin as gpio */
   PORTE_PCR29 |= PORT_PCR_MUX(ENCODER_ALT);

   /* configure ENCODER as output  */
   //GPIOE_PDDR |= GPIO_PDDR_PDD(ENCODER_DIR_OUTPUT);
   /* INIT TPM */
   //Init TPM Clock source as OSCERCLOCK
   SIM_SOPT2 |= SIM_SOPT2_TPMSRC(2);
   //TPM0 ClockIn0
   SIM_SOPT4 |= SIM_SOPT4_TPM0CLKSEL(0);
   //Enable clock to TPM0
   SIM_SCGC6 |= SIM_SCGC6_TPM0(1);
   //Select External Clock Source for TPM module
   TPM0_SC |= TPM_SC_CMOD(2);
   //Prescale 1:1
   TPM0_SC |= TPM_SC_PS(0);

}

/* ************************************************ */
/* Method name:        encoder_rps                  */
/* Method description: Determine the motor velocity*/
/*                     and put it in the LCD        */
/* Input params:       n/a                          */
/* Outpu params:       n/a                          */
/* ************************************************ */
void encoder_rps()
{
   int irps = (TPM_RD_CNT(TPM0)) / 7;
   int iporc = (int) ((100 * TPM1_C1V) / 65535); // calculo da % do PWM
   TPM0_CNT = 0;

   if (iporc != 0)
   {
      if (iporc != 100)
         iporc++;
   }

   char cvelocity[10], cPWMValue[10];
   sprintf(cvelocity, "%d", irps);
   sprintf(cPWMValue, "%d", iporc);
   lcd_sendCommand(CMD_CLEAR);
   lcd_setCursor(0, 0);
   lcd_writeString(cvelocity);
   lcd_writeString("rps");
   lcd_setCursor(1, 0);
   lcd_writeString("PWM ");
   lcd_writeString(cPWMValue);
   lcd_writeString("%");
}

