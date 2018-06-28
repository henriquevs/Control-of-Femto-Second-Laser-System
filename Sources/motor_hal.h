/* ***************************************************************** */
/* File name:        motor.h                                         */
/* File description: This file has a couple of useful functions to   */
/*                   control motor functions                         */
/* Author name:      Henrique Vicente Souza / Davi Rodrigues         */
/* Creation date:    06april2016                                     */
/* Revision date:    28june2016                                      */
/* ***************************************************************** */

/* ************************************************ */
/* Method name:        motor_initMotor              */
/* Method description: As the hardware board was    */
/*                     designed with a motor this   */
/*                      method configures it        */
/* 					   displays and segments  		*/
/* Input params:       n/a						    */
/* Outpu params:       n/a                          */
/* ************************************************ */
void motor_initMotor();

/* ************************************************ */
/* Method name:        motor_initMotor              */
/* Method description: turn the motor on     		*/
/* Input params:       n/a						    */
/* Outpu params:       n/a                          */
/* ************************************************ */
void motor_setMotor();

/* ************************************************ */
/* Method name:        motor_initMotor              */
/* Method description: turn the motor off     		*/
/* Input params:       n/a						    */
/* Outpu params:       n/a                          */
/* ************************************************ */
void motor_clearMotor();

/* ************************************************** */
/* Method name:        motor_direction A              */
/* Method description: turns the motor in direction A */
/* Input params:       n/a						      */
/* Outpu params:       n/a                            */
/* ************************************************** */
void motor_directionAMotor();

/* ************************************************** */
/* Method name:        motor_direction B              */
/* Method description: turns the motor in direction B */
/* Input params:       n/a						      */
/* Outpu params:       n/a                            */
/* ************************************************** */
void motor_directionBMotor();

/* ********************************************************* */
/* Method name:        motor_dutyCycleMotor                  */
/* Method description: computes the duty cycle for the motor */
/* Input params:       n/a                                   */
/* Outpu params:       n/a                                   */
/* ********************************************************* */
float motor_dutyCycleMotor(char cperiferico[]);
