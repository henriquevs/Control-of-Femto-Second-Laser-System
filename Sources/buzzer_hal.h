/* ******************************************************************* */
/* File name:        buzzer_hal.h                                      */
/* File description: File dedicated to the hardware abstraction layer  */
/*                   related buzzer from the peripheral board          */
/* Author name:      dloubach / Henrique Vicente Souza / Davi Rodrigues*/
/* Creation date:    12jan2016                                         */
/* Revision date:    28june2016                                        */
/* ******************************************************************* */

#ifndef SOURCES_BUZZER_HAL_H_
#define SOURCES_BUZZER_HAL_H_

/* ************************************************ */
/* Method name:        buzzer_init                  */
/* Method description: Initialize the buzzer device */
/* Input params:       n/a                          */
/* Output params:      n/a                          */
/* ************************************************ */
void buzzer_init(void);

/* ************************************************ */
/* Method name:        buzzer_clearBuzz             */
/* Method description: Clear the buzzer             */
/* Input params:       n/a                          */
/* Output params:      n/a                          */
/* ************************************************ */
void buzzer_clearBuzz(void);

/* ************************************************ */
/* Method name:        buzzer_setBuzz               */
/* Method description: Set the buzzer               */
/* Input params:       n/a                          */
/* Output params:      n/a                          */
/* ************************************************ */
void buzzer_setBuzz(void);

/* ************************************************ */
/* Method name:        buzzer_computeTime           */
/* Method description: computes the time for buzzer */
/* Input params:       n/a                          */
/* Output params:      n/a                          */
/* ************************************************ */
float buzzer_computeTime(char cperiferico[]);

/* *************************************************** */
/* Method name:        buzzer_ligaBuzzer               */
/* Method description: turns the buzzer on for a while */
/* Input params:       n/a                             */
/* Outpu params:       n/a                             */
/* *************************************************** */
void buzzer_ligaBuzzer();

#endif /* SOURCES_BUZZER_HAL_H_ */
