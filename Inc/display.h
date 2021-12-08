/*
 * display.c
 *
 *  Created on: Nov 23, 2020
 *      Author: Stancoj
 */

#include "main.h"
#include <stdio.h>
#include <string.h>

#define SEGMENTA_PIN	LL_GPIO_PIN_1
#define SEGMENTA_PORT	GPIOA

#define SEGMENTB_PIN	LL_GPIO_PIN_0
#define SEGMENTB_PORT	GPIOA

#define SEGMENTC_PIN	LL_GPIO_PIN_8
#define SEGMENTC_PORT	GPIOA

#define SEGMENTD_PIN	LL_GPIO_PIN_5
#define SEGMENTD_PORT	GPIOB

#define SEGMENTE_PIN 	LL_GPIO_PIN_11
#define SEGMENTE_PORT	GPIOA

#define SEGMENTF_PIN 	LL_GPIO_PIN_3
#define SEGMENTF_PORT	GPIOA

#define SEGMENTG_PIN	LL_GPIO_PIN_4
#define SEGMENTG_PORT	GPIOB

#define SEGMENTDP_PIN	LL_GPIO_PIN_1
#define SEGMENTDP_PORT	GPIOB

#define DIGIT_1_ON		LL_GPIO_SetOutputPin(GPIOA, LL_GPIO_PIN_5)
#define DIGIT_2_ON		LL_GPIO_SetOutputPin(GPIOA, LL_GPIO_PIN_4)
#define DIGIT_3_ON		LL_GPIO_SetOutputPin(GPIOA, LL_GPIO_PIN_6)
#define DIGIT_4_ON		LL_GPIO_SetOutputPin(GPIOA, LL_GPIO_PIN_2)
#define DIGIT_TIME_ON	LL_GPIO_SetOutputPin(GPIOA, LL_GPIO_PIN_7)

#define DIGIT_1_OFF		LL_GPIO_ResetOutputPin(GPIOA, LL_GPIO_PIN_5)
#define DIGIT_2_OFF 	LL_GPIO_ResetOutputPin(GPIOA, LL_GPIO_PIN_4)
#define DIGIT_3_OFF		LL_GPIO_ResetOutputPin(GPIOA, LL_GPIO_PIN_6)
#define DIGIT_4_OFF		LL_GPIO_ResetOutputPin(GPIOA, LL_GPIO_PIN_2)
#define DIGIT_TIME_OFF	LL_GPIO_ResetOutputPin(GPIOA, LL_GPIO_PIN_7)

#define SEGMENT_A_ON 	LL_GPIO_ResetOutputPin(SEGMENTA_PORT, SEGMENTA_PIN);
#define SEGMENT_B_ON	LL_GPIO_ResetOutputPin(SEGMENTB_PORT, SEGMENTB_PIN);
#define SEGMENT_C_ON	LL_GPIO_ResetOutputPin(SEGMENTC_PORT, SEGMENTC_PIN);
#define SEGMENT_D_ON	LL_GPIO_ResetOutputPin(SEGMENTD_PORT, SEGMENTD_PIN);
#define SEGMENT_E_ON	LL_GPIO_ResetOutputPin(SEGMENTE_PORT, SEGMENTE_PIN);
#define SEGMENT_F_ON	LL_GPIO_ResetOutputPin(SEGMENTF_PORT, SEGMENTF_PIN);
#define SEGMENT_G_ON	LL_GPIO_ResetOutputPin(SEGMENTG_PORT, SEGMENTG_PIN);
#define SEGMENT_DP_ON	LL_GPIO_ResetOutputPin(SEGMENTDP_PORT, SEGMENTDP_PIN);

#define SEGMENT_A_OFF	LL_GPIO_SetOutputPin(SEGMENTA_PORT, SEGMENTA_PIN);
#define SEGMENT_B_OFF	LL_GPIO_SetOutputPin(SEGMENTB_PORT, SEGMENTB_PIN);
#define SEGMENT_C_OFF	LL_GPIO_SetOutputPin(SEGMENTC_PORT, SEGMENTC_PIN);
#define SEGMENT_D_OFF	LL_GPIO_SetOutputPin(SEGMENTD_PORT, SEGMENTD_PIN);
#define SEGMENT_E_OFF	LL_GPIO_SetOutputPin(SEGMENTE_PORT, SEGMENTE_PIN);
#define SEGMENT_F_OFF	LL_GPIO_SetOutputPin(SEGMENTF_PORT, SEGMENTF_PIN);
#define SEGMENT_G_OFF	LL_GPIO_SetOutputPin(SEGMENTG_PORT, SEGMENTG_PIN);
#define SEGMENT_DP_OFF	LL_GPIO_SetOutputPin(SEGMENTDP_PORT, SEGMENTDP_PIN);

typedef struct
{
	uint8_t digit[4];
	uint8_t digit_num;
	uint8_t negative;
	uint8_t resolution;
}display_data_;

void updateDisplayNumber(void);
void updateDisplayAlphabet(void);
void displayNumber(double num);
void displayString(uint8_t ch1, uint8_t ch2, uint8_t ch3, uint8_t ch4);
void setDigit(uint8_t pos);

void resetDigits(void);
void setDigits(void);
void resetSegments(void);
void setSegments(void);

unsigned char decode_7seg(unsigned char chr);
void setAsciiCharacter(unsigned char chr);

