/* ********************************************************************** */
/* File name:        timer_counter.c                                      */
/* File description: This file has a couple of useful functions to        */
/*                   configure the PWM                                    */
/* Author name:      Matheus Oliveira / Henrique Vicente / Davi Rodrigues */
/* Creation date:    25april2016                                          */
/* Revision date:    28june2016                                           */
/* ********************************************************************** */

#include "es670_peripheral_board.h"

#include "fsl_tpm_hal.h"

/* ************************************************** */
/* Method name: 	   timer_initTPM1AsPWM            */
/* Method description: configure Timer1 to act as PWM */
/* Input params:	   n/a 							  */
/* Outpu params:	   n/a 							  */
/* ************************************************** */
void timer_initTPM1AsPWM(void)
{
   /* un-gate port clock*/
   SIM_SCGC6 |= SIM_SCGC6_TPM1(CGC_CLOCK_ENABLED); //Enable clock for TPM1

   TPM1_SC &= ~(1 << 5);   //up counting mode - CPWMS = 0

   TPM1_SC |= (1 << 3);
   TPM1_SC &= ~(1 << 4); //LPTPM Counter increments on every LPTPM counter clock ??? - CMOD = 0:1

   TPM1_SC &= ~((1 << 0) | (1 << 1) | (1 << 2)); //Prescale 1:1 ??? - PS = 0:0:0

   //TPM1_C1SC |= ((1 << 5) | (0 << 4) | (1 << 3) | (0 << 2)); // MSB = 1 / MSA = 0 / ELSB = 1 / ELSA = 0
   TPM1_C1SC = (0x28); // MSB / MSA / ELSB / ELSA

   TPM1_CNT |= 0x1; // count
   TPM1_MOD |= 0xFFFE; // period
   //TPM1_C1V |= 0xFFFF; //PWM 100%
   //TPM1_C1V = 0xBFFD; //PWM 75%
   //TPM1_C1V = 0x7FFF; //PWM 50%
   //TPM1_C1V = 0x3FFF; //PWM 25%
   TPM1_C1V = 0x0; //PWM 0%

}

/* ************************************************ */
/* Method name:        timer_coolerfan_init         */
/* Method description: Initialize the cooler device */
/* Input params:       n/a                          */
/* Output params:      n/a                          */
/* ************************************************ */
void timer_coolerfan_init(void)
{
   /* un-gate port clock*/
   SIM_SCGC5 |= SIM_SCGC5_PORTA(CGC_CLOCK_ENABLED);

   /* set pin as PWM */
   PORTA_PCR13 = PORT_PCR_MUX(PWM1_ALT);

}
