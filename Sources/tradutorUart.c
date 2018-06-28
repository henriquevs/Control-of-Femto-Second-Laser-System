/* ********************************************************************** */
/* File name:        tradutorUart.c                                       */
/* File description: This file has a couple of useful functions to        */
/*                   control devices functions                            */
/* Author name:      Matheus Oliveira / Henrique Vicente / Davi Rodrigues */
/* Creation date:    15april2016                                          */
/* Revision date:    28june2016                                           */
/* ********************************************************************** */

#include "es670_peripheral_board.h"
#include <MKL25Z4.h>
#include "util.h"
#include "tradutorUart.h"
#include "buzzer_hal.h"
#include "debugUart.h"
#include "fsl_debug_console.h"
#include "lcd_hal.h"
#include "motor_hal.h"
#include "encoder_hal.h"
#include "tc_hal.h"
#include "fsl_lptmr_driver.h"

/* ************************************************ */
/* Method name:        maxsize                      */
/* Method description: From a string, the function  */
/*                     determine the max size of that*/
/*                     string                       */
/*                     to do with it                */
/* Input params:       char cperiferico[]           */
/* Outpu params:       int imax                     */
/* ************************************************ */
int tradutorUart_maxsize(char cdata[], char uiReceiveBuff)
{
   switch (cdata[0])
   {
      case 'B':
         return 4;
      break;
      case 'D':
         return 2;
      break;
      case 'C':
         if (cdata[1] == 'P')
            return 4;
         else if (cdata[1] == 'C')
            return 2;
         else if (cdata[1] == 'G')
            return 2;
         else if (cdata[1] == 'S')
         {
            if (10 == uiReceiveBuff)
               return -1;
            else
               return 18;
         }
      break;
      case 'V':
         if (cdata[1] == 'P')
            return 5;
         else
            return 2;
      break;
   }
   return 1;
}

/* ************************************************ */
/* Method name:        identifyCommand              */
/* Method description: From a string, the function  */
/*                     choose what to do, selecting */
/*                     what device is used and what */
/*                     to do with it                */
/* Input params:       char cperiferico[]           */
/* Outpu params:       n/a                          */
/* ************************************************ */
void tradutorUart_identifyCommand(char cperiferico[])
{
   int iTempoBuzzer, icount = 0;
   int LCD_size = 31;
   //int iPWM = 0;
   char LCD_string[LCD_size];
   /* verifica o primeiro caractere da string */
   switch (cperiferico[0])
   {
      case 'B': /* Buzzer */
      {
         iTempoBuzzer = buzzer_computeTime(cperiferico); /* calcula o tempo que o buzzer ficara ligado */
         while (iTempoBuzzer > 1) /* liga o buzzer por determinado tempo */
         {
            buzzer_setBuzz();
            util_genDelay1ms();
            buzzer_clearBuzz();
            util_genDelay1ms();
            iTempoBuzzer -= 2;
         }
         PUTCHAR('A');
         PUTCHAR('C');
         PUTCHAR('K');
         PUTCHAR(1);
         return;
      }
      break;
      case 'C': /* LCD */
         LPTMR_DRV_Stop(LPTMR0_IDX); // desliga interrupcao do encoder
         switch (cperiferico[1])
         {
            case 'S': /* set LCD, put the string in the LCD */
            {
               icount = 0;
               while (icount != LCD_size)
               {
                  LCD_string[icount] = ' ';
                  icount++;
               }
               icount = 3;
               while (10 != cperiferico[icount + 1] || LCD_size >= icount) /* 10 representa o \n*/
               {
                  if (10 == cperiferico[icount + 1])
                     break;
                  else
                  {
                     LCD_string[icount - 3] = cperiferico[icount];
                     icount++;
                  }
               }
               lcd_writeString(LCD_string);
               PUTCHAR('A');
               PUTCHAR('C');
               PUTCHAR('K');
               PUTCHAR(1);
               cperiferico = NULL; /* necessario para termos certeza que a string foi limpa */
               return;
            }
            case 'C': /* Clear the LCD */
            {
               lcd_sendCommand(CMD_CLEAR);
               PUTCHAR('A');
               PUTCHAR('C');
               PUTCHAR('K');
               PUTCHAR(1);
               return;
            }
            case 'P': /* Set LCD position */
            {
               lcd_setCursor(cperiferico[2] - 48, cperiferico[3] - 48);
               PUTCHAR('A');
               PUTCHAR('C');
               PUTCHAR('K');
               PUTCHAR(1);
               return;
            }
            case 'G': /* Put group name in LCD */
            {
               lcd_FEMTO();
               PUTCHAR('A');
               PUTCHAR('C');
               PUTCHAR('K');
               PUTCHAR(1);
               return;
            }
         }
      break;
      case 'V': /* Cooler */
         if (cperiferico[1] == 'S')
         {
        	motor_directionAMotor();

            TPM1_C1V = 65535;
            //Buzzer
            buzzer_ligaBuzzer();
            //Inicia leitura com lcd
            tc_installLptmr0(1000000, encoder_rps);

         } else if (cperiferico[1] == 'C')
         {
            //motor_clearMotor();
            TPM1_C1V = 0;
         } else if (cperiferico[1] == 'V')
         {
            tc_installLptmr0(1000000, encoder_rps);
         } else if (cperiferico[1] == 'P')
         {
            TPM1_C1V = motor_dutyCycleMotor(cperiferico); // duty cycle
         } else
         {
            break;
         }
         PUTCHAR('A');
         PUTCHAR('C');
         PUTCHAR('K');
         PUTCHAR(1);
         return;

      case 'D': /* Choose the motor direction */
    	  if (cperiferico[1] == 'A'){
    		  motor_directionAMotor();
    	  }
    	  else if(cperiferico[1] == 'B'){
    		  motor_directionBMotor();
    	  }
    	  else
    	  {
    		  break;
    	  }
    	  PUTCHAR('A');
    	  PUTCHAR('C');
    	  PUTCHAR('K');
    	  PUTCHAR(1);
    	  return;
   } /* switch(cperiferico[0]) */
   /* caso a entrada nao seja correta, retorna erro */
   PUTCHAR('E');
   PUTCHAR('R');
   PUTCHAR('R');
   PUTCHAR(1);
   return;
}
