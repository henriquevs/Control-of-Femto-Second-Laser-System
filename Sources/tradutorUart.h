/* ***************************************************************** */
/* File name:        motor.h                                         */
/* File description: This file has a couple of useful functions to   */
/*                   control motor functions                         */
/* Author name:      Henrique Vicente Souza / Davi Rodrigues         */
/* Creation date:    06april2016                                     */
/* Revision date:    28june2016                                      */
/* ***************************************************************** */

#ifndef SOURCES_TRADUTORUART_HAL_H_
#define SOURCES_TRADUTORUART_HAL_H_

/* ************************************************ */
/* Method name:        maxsize                      */
/* Method description: From a string, the function  */
/*                     determine the max size of that*/
/*                     string                       */
/*                     to do with it                */
/* Input params:       char cperiferico[]           */
/* Outpu params:       int imax                     */
/* ************************************************ */
int tradutorUart_maxsize(char cdata[], char uiReceiveBuff);

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
void tradutorUart_identifyCommand(char periferico[]);

#endif /* SOURCES_DISPLAY7SEG_HAL_H_ */
