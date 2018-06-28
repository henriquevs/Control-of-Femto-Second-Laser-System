/* ********************************************************************** */
/* File name:        timer_counter.h                                      */
/* File description: This file has a couple of useful functions to        */
/*                   configure the PWM                                    */
/* Author name:      Matheus Oliveira / Henrique Vicente / Davi Rodrigues */
/* Creation date:    25april2016                                          */
/* Revision date:    28june2016                                           */
/* ********************************************************************** */

/* ************************************************** */
/* Method name: 	   timer_initTPM1AsPWM            */
/* Method description: configure Timer1 to act as PWM */
/* Input params:	   n/a 							  */
/* Outpu params:	   n/a 							  */
/* ************************************************** */
void timer_initTPM1AsPWM(void);

/* ************************************************ */
/* Method name:        timer_coolerfan_init         */
/* Method description: Initialize the cooler device */
/* Input params:       n/a                          */
/* Output params:      n/a                          */
/* ************************************************ */
void timer_coolerfan_init(void);
