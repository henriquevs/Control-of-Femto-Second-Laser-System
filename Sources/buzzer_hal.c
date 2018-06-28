/* ******************************************************************* */
/* File name:        buzzer_hal.c                                      */
/* File description: File dedicated to the hardware abstraction layer  */
/*                   related buzzer from the peripheral board          */
/* Author name:      dloubach / Henrique Vicente Souza / Davi Rodrigues*/
/* Creation date:    12jan2016                                         */
/* Revision date:    28june2016                                        */
/* ******************************************************************* */

#include "buzzer_hal.h"
#include "es670_peripheral_board.h"
#include "util.h"

/* ************************************************ */
/* Method name:        buzzer_init                  */
/* Method description: Initialize the buzzer device */
/* Input params:       n/a                          */
/* Output params:      n/a                          */
/* ************************************************ */
void buzzer_init(void)
{
   /* un-gate port clock*/
   SIM_SCGC5 |= SIM_SCGC5_PORTD(CGC_CLOCK_ENABLED);

   /* set pin as gpio */
   PORTD_PCR0 = PORT_PCR_MUX(BUZZER_ALT);

   /* set pin as digital output */
   GPIOD_PDDR |= GPIO_PDDR_PDD(BUZZER_PIN);

}

/* ************************************************ */
/* Method name:        buzzer_clearBuzz             */
/* Method description: Clear the buzzer             */
/* Input params:       n/a                          */
/* Output params:      n/a                          */
/* ************************************************ */
void buzzer_clearBuzz(void)
{
   /* clear desired led */
   GPIOD_PCOR = GPIO_PCOR_PTCO(0x01);

}

/* ************************************************ */
/* Method name:        buzzer_setBuz                */
/* Method description: Set the buzze                */
/* Input params:       n/a                          */
/* Output params:       n/a                         */
/* ************************************************ */
void buzzer_setBuzz(void)
{
   /* set desired led */
   GPIOD_PSOR = GPIO_PSOR_PTSO(0x01);

}

/* ************************************************ */
/* Method name:        buzzer_setBuzz               */
/* Method description: Set the buzzer               */
/* Input params:       n/a                          */
/* Output params:      n/a                          */
/* ************************************************ */
float buzzer_computeTime(char cperiferico[])
{
	return (cperiferico[1] - 48) * 100 + (cperiferico[2] - 48) * 10
            + (cperiferico[3] - 48);
}

/* *************************************************** */
/* Method name:        buzzer_ligaBuzzer               */
/* Method description: turns the buzzer on for a while */
/* Input params:       n/a                             */
/* Outpu params:       n/a                             */
/* *************************************************** */
void buzzer_ligaBuzzer() {
   int iTempoBuzzer = 1000;
   while (iTempoBuzzer > 1) /* liga o buzzer por determinado tempo */
         {
            buzzer_setBuzz();
            util_genDelay1ms();
            buzzer_clearBuzz();
            util_genDelay1ms();
            iTempoBuzzer -= 2;
         }
}
