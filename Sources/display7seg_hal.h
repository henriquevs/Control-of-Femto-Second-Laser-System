/* ******************************************************************* */
/* File name:        display7seg.h                                     */
/* File description: This file has a couple of useful functions to     */
/*                   control display and segments from peripheral board*/
/* Author name:      Henrique Vicente Souza / Davi Rodrigues           */
/* Creation date:    07april2016                                       */
/* Revision date:    28june2016                                        */
/* ******************************************************************* */

#ifndef SOURCES_DISPLAY7SEG_HAL_H_
#define SOURCES_DISPLAY7SEG_HAL_H_

#define MAX_DISPLAY7SEG        04

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
void display7seg_initDisplay7seg();

/* ************************************************ */
/* Method name:        ClearDisplay7seg             */
/* Method description: Clear every pin of			*/
/*					   display and segment			*/
/* Input params:       n/a							*/
/* Outpu params:       n/a                          */
/* ************************************************ */
void display7seg_setDisplay7seg(char cDisplay7segNum, char displayShowNum);

/* ************************************************ */
/* Method name:        ClearDisplay7seg             */
/* Method description: Clear every pin of			*/
/*					   display and segment			*/
/* Input params:       n/a							*/
/* Outpu params:       n/a                          */
/* ************************************************ */
void display7seg_clearDisplay7seg();

/* ************************************************ */
/* Method name:        SetSegment	                */
/* Method description: set the correctly segment for*/
/* 					   a input number		        */
/* Input params:	   DisplayShowNum = {1..9}		*/
/* Outpu params:       n/a                          */
/* ************************************************ */
void display7seg_setSegment(char displayShowNum);

#endif /* SOURCES_DISPLAY7SEG_HAL_H_ */
