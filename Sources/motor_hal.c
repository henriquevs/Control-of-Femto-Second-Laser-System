/* ***************************************************************** */
/* File name:        motor.c                                         */
/* File description: This file has a couple of useful functions to   */
/*                   control motor functions                         */
/* Author name:      Henrique Vicente Souza / Davi Rodrigues         */
/* Creation date:    06april2016                                     */
/* Revision date:    28june2016                                      */
/* ***************************************************************** */

#include "motor_hal.h"
#include "es670_peripheral_board.h"

/* ************************************************ */
/* Method name:        motor_initMotor              */
/* Method description: As the hardware board was    */
/*                     designed with a motor this   */
/*                      method configures it        */
/* 					   displays and segments  		*/
/* Input params:       n/a						    */
/* Outpu params:       n/a                          */
/* ************************************************ */
void motor_initMotor()
{
   /* un-gate port clock*/
   SIM_SCGC5 |= SIM_SCGC5_PORTA(CGC_CLOCK_ENABLED);

   /* set pin as gpio */
   PORTA_PCR13 |= PORT_PCR_MUX(MOTOR_ALT);
   PORTA_PCR16 |= PORT_PCR_MUX(MOTOR_SENTIDO_1_ALT);
   PORTA_PCR17 |= PORT_PCR_MUX(MOTOR_SENTIDO_2_ALT);

   /* configure motor as output  */
   GPIOA_PDDR |= GPIO_PDDR_PDD(MOTOR_DIR_OUTPUT | MOTOR_SENTIDO_1_DIR_OUTPUT | MOTOR_SENTIDO_2_DIR_OUTPUT);
}

/* ************************************************ */
/* Method name:        motor_initMotor              */
/* Method description: turn the motor on     		*/
/* Input params:       n/a						    */
/* Outpu params:       n/a                          */
/* ************************************************ */
void motor_setMotor()
{
   GPIOA_PSOR |= GPIO_PSOR_PTSO((0x01U << MOTOR_PIN));
}
/* ************************************************ */
/* Method name:        motor_initMotor              */
/* Method description: turn the motor off     		*/
/* Input params:       n/a						    */
/* Outpu params:       n/a                          */
/* ************************************************ */
void motor_clearMotor()
{
   GPIOA_PCOR |= GPIO_PCOR_PTCO((0x01U << MOTOR_PIN));
}

/* ************************************************** */
/* Method name:        motor_direction A              */
/* Method description: turns the motor in direction A */
/* Input params:       n/a						      */
/* Outpu params:       n/a                            */
/* ************************************************** */
void motor_directionAMotor()
{
   GPIOA_PSOR |= (0x01U << MOTOR_SENTIDO_1_PIN);
   GPIOA_PCOR |= (0x01U << MOTOR_SENTIDO_2_PIN);
}

/* ************************************************** */
/* Method name:        motor_direction B              */
/* Method description: turns the motor in direction B */
/* Input params:       n/a						      */
/* Outpu params:       n/a                            */
/* ************************************************** */
void motor_directionBMotor()
{
   GPIOA_PSOR |= (0x01U << MOTOR_SENTIDO_2_PIN);
   GPIOA_PCOR |= (0x01U << MOTOR_SENTIDO_1_PIN);
}

/* ********************************************************* */
/* Method name:        motor_dutyCycleMotor                  */
/* Method description: computes the duty cycle for the motor */
/* Input params:       n/a                                   */
/* Outpu params:       n/a                                   */
/* ********************************************************* */
float motor_dutyCycleMotor(char cperiferico[])
{
	return ((cperiferico[2] - 48) * 100 + (cperiferico[3] - 48) * 10
	         + (cperiferico[4] - 48) * 1) * 655.35;
}
