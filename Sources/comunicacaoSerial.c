/* ***************************************************************** */
/* File name:        comunicacaoSerial.c                             */
/* File description: This file deal with UART0 comunication,         */
/*                   controling the string input                     */
/* Author name:      Henrique Vicente Souza / Davi Rodrigues         */
/* Creation date:    28april2016                                     */
/* Revision date:    28june2016                                      */
/* ***************************************************************** */
#include "debugUart.h"
#include "fsl_debug_console.h"
#include "comunicacaoSerial.h"
#include "tradutorUart.h"
#include "fsl_device_registers.h"
#include "mcg_hal.h"

/* ***************************************************************** */
/* File name:        stringCapture.c                                 */
/* File description: The function capture characters from the serial */
/*               comunication and put them together to identification*/
/* Author name:      Vinicius David / Henrique Vicente               */
/* Creation date:    28april2016                                     */
/* Revision date:    29april2016                                     */
/* ***************************************************************** */
void comunicacaoSerial_stringCapture()
{
   char cdata[18];
   char uiReceiveBuff;
   int icount = 0;
   int imax = 1;
   for (icount = 0; icount < 31; icount++)
   {
      cdata[icount] = ' ';
   }
   icount = 0;
   while (1)
   {
      if (icount == imax)
      {
         tradutorUart_identifyCommand(cdata);
         return;
      } else if (UART0_BRD_S1_RDRF(UART0))
      {
         uiReceiveBuff = GETCHAR();
         //PUTCHAR(uiReceiveBuff);
         //PUTCHAR(1);
         cdata[icount] = uiReceiveBuff;
         icount = icount + 1;
         imax = tradutorUart_maxsize(cdata, uiReceiveBuff);
         if (imax == -1)
            imax = icount;
         else if (imax == 18)
            imax = 18;
      }
   }
}
