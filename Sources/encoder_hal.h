/* *************************************************************** */
/* File name:        encoder.h                                     */
/* File description: This file has a couple of useful functions to */
/*                   control encoder functions                     */
/* Author name:      Henrique Vicente Souza / Davi Rodrigues       */
/* Creation date:    06april2016                                   */
/* Revision date:    28june2016                                    */
/* *************************************************************** */

#ifndef SOURCES_ENCODER_HAL_H_
#define SOURCES_ENCODER_HAL_H_

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
void encoder_initEncoder();

/* ************************************************ */
/* Method name:        encoder_rps                  */
/* Method description: Determine the motor velocity*/
/*                     and put it in the LCD        */
/* Input params:       n/a                          */
/* Outpu params:       n/a                          */
/* ************************************************ */
void encoder_rps();

#endif /* SOURCES_ENCODER_HAL_H_ */

