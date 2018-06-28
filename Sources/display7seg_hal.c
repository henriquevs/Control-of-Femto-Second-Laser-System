/* ******************************************************************* */
/* File name:        display7seg.c                                     */
/* File description: This file has a couple of useful functions to     */
/*                   control display and segments from peripheral board*/
/* Author name:      Henrique Vicente Souza / Davi Rodrigues           */
/* Creation date:    07april2016                                       */
/* Revision date:    28june2016                                        */
/* ******************************************************************* */

#include "display7seg_hal.h"
#include "es670_peripheral_board.h"
#include "util.h"

/* ************************************************ */
/* Method name:        display7seg_initdisplay7seg  */
/* Method description: As the hardware board was    */
/*                     designed with 4 displays each*/
/* 					   with 7 segments plus a point */
/* 					   this method configures all   */
/* 					   displays and segments  		*/
/* Input params:       n/a						    */
/* Outpu params:       n/a                          */
/* ************************************************ */
void display7seg_initDisplay7seg()
{
   /* un-gate port clock*/
   SIM_SCGC5 |= SIM_SCGC5_PORTC(CGC_CLOCK_ENABLED);

   /* set pin as GPIO  for each display*/
   PORTC_PCR10 = PORT_PCR_MUX(DISPLAY7_4_ALT);
   PORTC_PCR11 = PORT_PCR_MUX(DISPLAY7_3_ALT);
   PORTC_PCR12 = PORT_PCR_MUX(DISPLAY7_2_ALT);
   PORTC_PCR13 = PORT_PCR_MUX(DISPLAY7_1_ALT);

   /* set pin as GPIO  for each segment*/
   PORTC_PCR0 = PORT_PCR_MUX(DISPLAY7_SEGA_ALT);
   PORTC_PCR1 = PORT_PCR_MUX(DISPLAY7_SEGB_ALT);
   PORTC_PCR2 = PORT_PCR_MUX(DISPLAY7_SEGC_ALT);
   PORTC_PCR3 = PORT_PCR_MUX(DISPLAY7_SEGD_ALT);
   PORTC_PCR4 = PORT_PCR_MUX(DISPLAY7_SEGE_ALT);
   PORTC_PCR5 = PORT_PCR_MUX(DISPLAY7_SEGF_ALT);
   PORTC_PCR6 = PORT_PCR_MUX(DISPLAY7_SEGG_ALT);
   PORTC_PCR7 = PORT_PCR_MUX(DISPLAY7_SEGDP_ALT);

   /* configure all displays and segments as output  */
   GPIOC_PDDR |=
         GPIO_PDDR_PDD(
               DISPLAY7_1_DIR_OUTPUT | DISPLAY7_2_DIR_OUTPUT | DISPLAY7_3_DIR_OUTPUT | DISPLAY7_4_DIR_OUTPUT | DISPLAY7_SEGA_DIR_OUTPUT | DISPLAY7_SEGB_DIR_OUTPUT | DISPLAY7_SEGC_DIR_OUTPUT | DISPLAY7_SEGD_DIR_OUTPUT | DISPLAY7_SEGE_DIR_OUTPUT | DISPLAY7_SEGF_DIR_OUTPUT | DISPLAY7_SEGG_DIR_OUTPUT | DISPLAY7_SEGDP_DIR_OUTPUT);

}

/* ************************************************ */
/* Method name:        SetDisplay7seg               */
/* Method description: set the correctly display and*/
/* 					   number		                */
/* Input params:       cDisplay7segNum = which display {1..4}*/
/*					   DisplayShowNum = {1..9}		*/
/* Outpu params:       n/a                          */
/* ************************************************ */
void display7seg_setDisplay7seg(char cDisplay7segNum, char DisplayShowNum)
{
   /* sanity check */
   if (cDisplay7segNum <= MAX_DISPLAY7SEG)
   {
      /* Clear all displays and segments */
      display7seg_clearDisplay7seg();
      /* display selection */
      switch (cDisplay7segNum)
      {
         /* set pin for display 1 */
         case 1:
            GPIOC_PSOR |= GPIO_PSOR_PTSO((0x01U << DISPLAY7_1_PIN));
            display7seg_setSegment(DisplayShowNum);
         break;
            /* set pin for display 2 */
         case 2:
            GPIOC_PSOR |= GPIO_PSOR_PTSO((0x01U << DISPLAY7_2_PIN));
            display7seg_setSegment(DisplayShowNum);
         break;
            /* set pin for display 3 */
         case 3:
            GPIOC_PSOR |= GPIO_PSOR_PTSO((0x01U << DISPLAY7_3_PIN));
            display7seg_setSegment(DisplayShowNum);
         break;
            /* set pin for display 4 */
         case 4:
            GPIOC_PSOR |= GPIO_PSOR_PTSO((0x01U << DISPLAY7_4_PIN));
            display7seg_setSegment(DisplayShowNum);
         break;
      } /* display selection */
      util_genDelay1ms();

   } /* if(cDisplay7segNum <= MAX_DISPLAY7SEG) */
}

/* ************************************************ */
/* Method name:        ClearDisplay7seg             */
/* Method description: Clear every pin of			*/
/*					   display and segment			*/
/* Input params:       n/a							*/
/* Outpu params:       n/a                          */
/* ************************************************ */

void display7seg_clearDisplay7seg()
{
   /* clear pin for evey display*/
   GPIOC_PCOR |= GPIO_PCOR_PTCO((0x01U << DISPLAY7_1_PIN));
   GPIOC_PCOR |= GPIO_PCOR_PTCO((0x01U << DISPLAY7_2_PIN));
   GPIOC_PCOR |= GPIO_PCOR_PTCO((0x01U << DISPLAY7_3_PIN));
   GPIOC_PCOR |= GPIO_PCOR_PTCO((0x01U << DISPLAY7_4_PIN));

   /* clear pin for evey segment*/
   GPIOC_PCOR |= GPIO_PCOR_PTCO((0x01U << DISPLAY7_SEGA_PIN));
   GPIOC_PCOR |= GPIO_PCOR_PTCO((0x01U << DISPLAY7_SEGB_PIN));
   GPIOC_PCOR |= GPIO_PCOR_PTCO((0x01U << DISPLAY7_SEGC_PIN));
   GPIOC_PCOR |= GPIO_PCOR_PTCO((0x01U << DISPLAY7_SEGD_PIN));
   GPIOC_PCOR |= GPIO_PCOR_PTCO((0x01U << DISPLAY7_SEGE_PIN));
   GPIOC_PCOR |= GPIO_PCOR_PTCO((0x01U << DISPLAY7_SEGF_PIN));
   GPIOC_PCOR |= GPIO_PCOR_PTCO((0x01U << DISPLAY7_SEGG_PIN));
   GPIOC_PCOR |= GPIO_PCOR_PTCO((0x01U << DISPLAY7_SEGDP_PIN));
}

/* ************************************************ */
/* Method name:        SetSegment	                */
/* Method description: set the correctly segment for*/
/* 					   a input number		        */
/* Input params:	   DisplayShowNum = {1..9}		*/
/* Outpu params:       n/a                          */
/* ************************************************ */
void display7seg_setSegment(char DisplayShowNum)
{
   switch (DisplayShowNum)
   {
      /* set pin for the correctly segments to show 0 */
      case 0:
         GPIOC_PSOR |= GPIO_PSOR_PTSO((0x01U << DISPLAY7_SEGA_PIN));
         GPIOC_PSOR |= GPIO_PSOR_PTSO((0x01U << DISPLAY7_SEGB_PIN));
         GPIOC_PSOR |= GPIO_PSOR_PTSO((0x01U << DISPLAY7_SEGC_PIN));
         GPIOC_PSOR |= GPIO_PSOR_PTSO((0x01U << DISPLAY7_SEGD_PIN));
         GPIOC_PSOR |= GPIO_PSOR_PTSO((0x01U << DISPLAY7_SEGE_PIN));
         GPIOC_PSOR |= GPIO_PSOR_PTSO((0x01U << DISPLAY7_SEGF_PIN));
      break;
         /* set pin for the correctly segments to show 1 */
      case 1:
         GPIOC_PSOR |= GPIO_PSOR_PTSO((0x01U << DISPLAY7_SEGB_PIN));
         GPIOC_PSOR |= GPIO_PSOR_PTSO((0x01U << DISPLAY7_SEGC_PIN));
      break;
         /* set pin for the correctly segments to show 2 */
      case 2:
         GPIOC_PSOR |= GPIO_PSOR_PTSO((0x01U << DISPLAY7_SEGA_PIN));
         GPIOC_PSOR |= GPIO_PSOR_PTSO((0x01U << DISPLAY7_SEGB_PIN));
         GPIOC_PSOR |= GPIO_PSOR_PTSO((0x01U << DISPLAY7_SEGG_PIN));
         GPIOC_PSOR |= GPIO_PSOR_PTSO((0x01U << DISPLAY7_SEGE_PIN));
         GPIOC_PSOR |= GPIO_PSOR_PTSO((0x01U << DISPLAY7_SEGD_PIN));
      break;
         /* set pin for the correctly segments to show 3 */
      case 3:
         GPIOC_PSOR |= GPIO_PSOR_PTSO((0x01U << DISPLAY7_SEGA_PIN));
         GPIOC_PSOR |= GPIO_PSOR_PTSO((0x01U << DISPLAY7_SEGB_PIN));
         GPIOC_PSOR |= GPIO_PSOR_PTSO((0x01U << DISPLAY7_SEGC_PIN));
         GPIOC_PSOR |= GPIO_PSOR_PTSO((0x01U << DISPLAY7_SEGD_PIN));
         GPIOC_PSOR |= GPIO_PSOR_PTSO((0x01U << DISPLAY7_SEGG_PIN));
      break;
         /* set pin for the correctly segments to show 4 */
      case 4:
         GPIOC_PSOR |= GPIO_PSOR_PTSO((0x01U << DISPLAY7_SEGB_PIN));
         GPIOC_PSOR |= GPIO_PSOR_PTSO((0x01U << DISPLAY7_SEGC_PIN));
         GPIOC_PSOR |= GPIO_PSOR_PTSO((0x01U << DISPLAY7_SEGF_PIN));
         GPIOC_PSOR |= GPIO_PSOR_PTSO((0x01U << DISPLAY7_SEGG_PIN));
      break;
         /* set pin for the correctly segments to show 5 */
      case 5:
         GPIOC_PSOR |= GPIO_PSOR_PTSO((0x01U << DISPLAY7_SEGA_PIN));
         GPIOC_PSOR |= GPIO_PSOR_PTSO((0x01U << DISPLAY7_SEGC_PIN));
         GPIOC_PSOR |= GPIO_PSOR_PTSO((0x01U << DISPLAY7_SEGD_PIN));
         GPIOC_PSOR |= GPIO_PSOR_PTSO((0x01U << DISPLAY7_SEGF_PIN));
         GPIOC_PSOR |= GPIO_PSOR_PTSO((0x01U << DISPLAY7_SEGG_PIN));
      break;
         /* set pin for the correctly segments to show 6 */
      case 6:
         GPIOC_PSOR |= GPIO_PSOR_PTSO((0x01U << DISPLAY7_SEGA_PIN));
         GPIOC_PSOR |= GPIO_PSOR_PTSO((0x01U << DISPLAY7_SEGC_PIN));
         GPIOC_PSOR |= GPIO_PSOR_PTSO((0x01U << DISPLAY7_SEGD_PIN));
         GPIOC_PSOR |= GPIO_PSOR_PTSO((0x01U << DISPLAY7_SEGE_PIN));
         GPIOC_PSOR |= GPIO_PSOR_PTSO((0x01U << DISPLAY7_SEGF_PIN));
         GPIOC_PSOR |= GPIO_PSOR_PTSO((0x01U << DISPLAY7_SEGG_PIN));
      break;
         /* set pin for the correctly segments to show 7 */
      case 7:
         GPIOC_PSOR |= GPIO_PSOR_PTSO((0x01U << DISPLAY7_SEGA_PIN));
         GPIOC_PSOR |= GPIO_PSOR_PTSO((0x01U << DISPLAY7_SEGB_PIN));
         GPIOC_PSOR |= GPIO_PSOR_PTSO((0x01U << DISPLAY7_SEGC_PIN));
      break;
         /* set pin for the correctly segments to show 8 */
      case 8:
         GPIOC_PSOR |= GPIO_PSOR_PTSO((0x01U << DISPLAY7_SEGA_PIN));
         GPIOC_PSOR |= GPIO_PSOR_PTSO((0x01U << DISPLAY7_SEGB_PIN));
         GPIOC_PSOR |= GPIO_PSOR_PTSO((0x01U << DISPLAY7_SEGC_PIN));
         GPIOC_PSOR |= GPIO_PSOR_PTSO((0x01U << DISPLAY7_SEGD_PIN));
         GPIOC_PSOR |= GPIO_PSOR_PTSO((0x01U << DISPLAY7_SEGE_PIN));
         GPIOC_PSOR |= GPIO_PSOR_PTSO((0x01U << DISPLAY7_SEGF_PIN));
         GPIOC_PSOR |= GPIO_PSOR_PTSO((0x01U << DISPLAY7_SEGG_PIN));
      break;
         /* set pin for the correctly segments to show 9 */
      case 9:
         GPIOC_PSOR |= GPIO_PSOR_PTSO((0x01U << DISPLAY7_SEGA_PIN));
         GPIOC_PSOR |= GPIO_PSOR_PTSO((0x01U << DISPLAY7_SEGB_PIN));
         GPIOC_PSOR |= GPIO_PSOR_PTSO((0x01U << DISPLAY7_SEGC_PIN));
         GPIOC_PSOR |= GPIO_PSOR_PTSO((0x01U << DISPLAY7_SEGD_PIN));
         GPIOC_PSOR |= GPIO_PSOR_PTSO((0x01U << DISPLAY7_SEGF_PIN));
         GPIOC_PSOR |= GPIO_PSOR_PTSO((0x01U << DISPLAY7_SEGG_PIN));
      break;
   }
}
