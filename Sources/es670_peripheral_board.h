/* ******************************************************************* */
/* File name:        es670_peripheral_board.h                          */
/* File description: Header file containing the peripherals mapping    */
/*                   of the peripheral board for the ES670 hardware    */
/* Author name:      dloubach / Henrique Vicente Souza / Davi Rodrigues*/
/* Creation date:    16out2015                                         */
/* Revision date:    28june2016                                        */
/* ******************************************************************* */

#ifndef SOURCES_ES670_PERIPHERAL_BOARD_H_
#define SOURCES_ES670_PERIPHERAL_BOARD_H_

/* system includes */
#include <MKL25Z4.h>

/*                 General uC definitions                 */

/* Clock gate control */
#define  CGC_CLOCK_DISABLED         0x00u
#define  CGC_CLOCK_ENABLED          0x01u

/* GPIO input / output */
#define GPIO_INPUT                  0x00u
#define GPIO_OUTPUT                 0x01u

/* Internal Clock */
#define  TPMSRC_MCGIRCLK            0x11u

/* TPM Clock */
#define TPM_SC_CMOD_LPTPM_COUNTER   0x01u
#define TPM_SC_PS_DIVIDE_128        0x111u

/*                 END OF General uC definitions         */

/*                 BUZZER Definitions                    */
#define BUZZER_PORT_BASE_PNT        PORTD      /* peripheral port base pointer */
#define BUZZER_GPIO_BASE_PNT        PTD        /* peripheral gpio base pointer */

#define BUZZER_PIN                  1u               /* buzzer pin */
#define BUZZER_DIR                  kGpioDigitalOutput
#define BUZZER_ALT                  0x01u
/*                 END OF BUZZER definitions             */

/*                 DISPLAY 7 SEGMENTS definitions				*/

#define DISPLAY7_PORT_BASE_PNT      PORTC
#define DISPLAY7_GPIO_BASE_PNT      PTC

/* DISPLAY 7 SEGMENTS A PIN */
#define DISPLAY7_SEGA_PIN           0u
#define	DISPLAY7_SEGA_DIR_OUTPUT    (GPIO_OUTPUT << DISPLAY7_SEGA_PIN)
#define DISPLAY7_SEGA_ALT           0x01u
//
/* DISPLAY 7 SEGMENTS B PIN */
#define DISPLAY7_SEGB_PIN           1u
#define	DISPLAY7_SEGB_DIR_OUTPUT    (GPIO_OUTPUT << DISPLAY7_SEGB_PIN)
#define DISPLAY7_SEGB_ALT           0x01u

/* DISPLAY 7 SEGMENTS C PIN */
#define DISPLAY7_SEGC_PIN           2u
#define	DISPLAY7_SEGC_DIR_OUTPUT    (GPIO_OUTPUT << DISPLAY7_SEGC_PIN)
#define DISPLAY7_SEGC_ALT           0x01u

/* DISPLAY 7 SEGMENTS D PIN */
#define DISPLAY7_SEGD_PIN           3u
#define	DISPLAY7_SEGD_DIR_OUTPUT    (GPIO_OUTPUT << DISPLAY7_SEGD_PIN)
#define DISPLAY7_SEGD_ALT           0x01u

/* DISPLAY 7 SEGMENTS E PIN */
#define DISPLAY7_SEGE_PIN           4u
#define	DISPLAY7_SEGE_DIR_OUTPUT    (GPIO_OUTPUT << DISPLAY7_SEGE_PIN)
#define DISPLAY7_SEGE_ALT           0x01u

/* DISPLAY 7 SEGMENTS F PIN */
#define DISPLAY7_SEGF_PIN           5u
#define	DISPLAY7_SEGF_DIR_OUTPUT    (GPIO_OUTPUT << DISPLAY7_SEGF_PIN)
#define DISPLAY7_SEGF_ALT           0x01u

/* DISPLAY 7 SEGMENTS G PIN */
#define DISPLAY7_SEGG_PIN           6u
#define	DISPLAY7_SEGG_DIR_OUTPUT    (GPIO_OUTPUT << DISPLAY7_SEGG_PIN)
#define DISPLAY7_SEGG_ALT           0x01u

/* DISPLAY 7 SEGMENTS DP PIN */
#define DISPLAY7_SEGDP_PIN          7u
#define	DISPLAY7_SEGDP_DIR_OUTPUT   (GPIO_OUTPUT << DISPLAY7_SEGDP_PIN)
#define DISPLAY7_SEGDP_ALT				0x01u

/* DISPLAY 7 SEGMENTS 1 PIN */
#define DISPLAY7_1_PIN              13u
#define	DISPLAY7_1_DIR_OUTPUT       (GPIO_OUTPUT << DISPLAY7_1_PIN)
#define DISPLAY7_1_ALT              0x01u

/* DISPLAY 7 SEGMENTS 2 PIN */
#define DISPLAY7_2_PIN              12u
#define	DISPLAY7_2_DIR_OUTPUT       (GPIO_OUTPUT << DISPLAY7_2_PIN)
#define DISPLAY7_2_ALT              0x01u

/* DISPLAY 7 SEGMENTS 3 PIN */
#define DISPLAY7_3_PIN              11u
#define	DISPLAY7_3_DIR_OUTPUT       (GPIO_OUTPUT << DISPLAY7_3_PIN)
#define DISPLAY7_3_ALT              0x01u

/* DISPLAY 7 SEGMENTS 4 PIN */
#define DISPLAY7_4_PIN              10u
#define	DISPLAY7_4_DIR_OUTPUT       (GPIO_OUTPUT << DISPLAY7_4_PIN)
#define DISPLAY7_4_ALT              0x01u

/*                 END OF DISPLAY 7 SEGMENTS definitions 			*/

/*                 LCD definitions                 */

/* LCD Register Selector
 * Used as register selector input
 * When (LCD_RS = LCD_RS_HIGH) => DATA register is selected
 * When (LCD_RS = LCD_RS_LOW)  => INSTRUCTION register is selected
 */
#define LCD_PORT_BASE_PNT           PORTC   /* peripheral port base pointer */
#define LCD_GPIO_BASE_PNT           PTC     /* peripheral gpio base pointer */

#define LCD_RS_HIGH                 1u
#define LCD_RS_DATA                 LCD_RS_HIGH

#define LCD_RS_LOW                  0u
#define LCD_RS_CMD                  LCD_RS_LOW

#define LCD_ENABLED                 1u
#define LCD_DISABLED                0u

#define LCD_DATA_DIR                1u //kGpioDigitalOutput        /* LCD data pins */
#define LCD_DATA_ALT                1u //kPortMuxAsGpio

#define LCD_RS_PIN                  8u      /* register selector */
#define LCD_RS_DIR                  (GPIO_OUTPUT << LCD_RS_PIN) //kGpioDigitalOutput
#define LCD_RS_ALT                  1u //kPortMuxAsGpio

#define LCD_ENABLE_PIN              9u      /* enable pin */
#define LCD_ENABLE_DIR              (GPIO_OUTPUT << LCD_ENABLE_PIN) //kGpioDigitalOutput
#define LCD_ENABLE_ALT              1u //kPortMuxAsGpio

#define LCD_DATA_DB0_PIN            0u
#define LCD_DATA_DB0_DIR            (GPIO_OUTPUT << LCD_DATA_DB0_PIN)
#define LCD_DATA_DB0_ALT			0x01u

#define LCD_DATA_DB1_PIN            1u
#define LCD_DATA_DB1_DIR            (GPIO_OUTPUT << LCD_DATA_DB1_PIN)
#define LCD_DATA_DB1_ALT			0x01u

#define LCD_DATA_DB2_PIN            2u
#define LCD_DATA_DB2_DIR            (GPIO_OUTPUT << LCD_DATA_DB2_PIN)
#define LCD_DATA_DB2_ALT			0x01u

#define LCD_DATA_DB3_PIN            3u
#define LCD_DATA_DB3_DIR            (GPIO_OUTPUT << LCD_DATA_DB3_PIN)
#define LCD_DATA_DB3_ALT			0x01u

#define LCD_DATA_DB4_PIN            4u
#define LCD_DATA_DB4_DIR            (GPIO_OUTPUT << LCD_DATA_DB4_PIN)
#define LCD_DATA_DB4_ALT			0x01u

#define LCD_DATA_DB5_PIN            5u
#define LCD_DATA_DB5_DIR            (GPIO_OUTPUT << LCD_DATA_DB5_PIN)
#define LCD_DATA_DB5_ALT			0x01u

#define LCD_DATA_DB6_PIN            6u
#define LCD_DATA_DB6_DIR            (GPIO_OUTPUT << LCD_DATA_DB6_PIN)
#define LCD_DATA_DB6_ALT			0x01u

#define LCD_DATA_DB7_PIN            7u
#define LCD_DATA_DB7_DIR            (GPIO_OUTPUT << LCD_DATA_DB7_PIN)
#define LCD_DATA_DB7_ALT			0x01u

/*                 END OF LCD definitions                 */

/* Encoder definitions */

#define ENCODER_PORT_BASE_PNT       PORTE
#define ENCODER_GPIO_BASE_PNT       PTE

/* ENCODER_PIN */
#define ENCODER_PIN                 29u
#define ENCODER_DIR_OUTPUT          (GPIO_OUTPUT << ENCODER_PIN)
#define ENCODER_ALT                 0x04u

/* END OF Encoder definitions */

/* Motor definitions */

#define MOTOR_BASE_PNT              PORTA
#define MOTOR_GPIO_BASE_PNT         PTA

/* MOTOR_PIN */
#define MOTOR_PIN                   13u
#define MOTOR_DIR_OUTPUT            (GPIO_OUTPUT << MOTOR_PIN)
#define MOTOR_ALT                   0x01u

#define MOTOR_SENTIDO_1_PIN         16u
#define MOTOR_SENTIDO_1_DIR_OUTPUT  (GPIO_OUTPUT << MOTOR_SENTIDO_1_PIN)
#define MOTOR_SENTIDO_1_ALT         0x01u

#define MOTOR_SENTIDO_2_PIN         17u
#define MOTOR_SENTIDO_2_DIR_OUTPUT  (GPIO_OUTPUT << MOTOR_SENTIDO_2_PIN)
#define MOTOR_SENTIDO_2_ALT         0x01u

/* END OF Motor definitions */

/**/
#define PWM1_ALT                    0x03u
/**/

#endif /* SOURCES_ES670_PERIPHERAL_BOARD_H_ */
