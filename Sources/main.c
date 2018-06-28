/* ***************************************************************** */
/* File name:        main.c                                          */
/* File description: test of the embedded system                     */
/* Author name:      Henrique Vicente Souza / Davi Rodrigues         */
/* Creation date:    28apr2016                                       */
/* Revision date:    28june2016                                      */
/* ***************************************************************** */

#include "fsl_device_registers.h"
#include "buzzer_hal.h"
#include "mcg_hal.h"
#include "util.h"
#include "es670_peripheral_board.h"

#include "display7seg_hal.h"

#include "debugUart.h"
#include "fsl_debug_console.h"
#include "tradutorUart.h"
#include "comunicacaoSerial.h"

#include "lcd_hal.h"

#include "motor_hal.h"
#include "encoder_hal.h"

#include "timer_counter.h"

int main(void)
{
   /* Inicializar o periferico de clock */
   mcg_clockInit();

   /* Inicializar o periferico do buzzer */
   buzzer_init();

   /* Inicializar o periferico Display 7 segmentos */
   display7seg_initDisplay7seg();

   /* Inicializar o UART0 */
   debugUart_init();

   /* Inicializar o LCD */
   lcd_initLcd();

   /* Inicializar o motor */
   motor_initMotor();

   /* Inicializar encoder */
   encoder_initEncoder();

   /* Inicializar PWM */
   timer_initTPM1AsPWM();
   timer_coolerfan_init();

   /* This for loop should be replaced. By default this loop allows a single stepping. */
   while (1)
   {
      comunicacaoSerial_stringCapture();
   }
   /* Never leave main */
   return 0;
}
