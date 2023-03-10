/*
 * header.h
 *
 *  Created on: Mar 9, 2023
 *      Author: Tom
 */

#ifndef INC_HEADER_H_
#define INC_HEADER_H_

// DEFINES //
//LD4, green LED
#define LEDPIN		GPIO_PIN_13
#define LEDBANK 	GPIOB

//B1, blue button
#define BUTTONPIN 	GPIO_PIN_13
#define BUTTONBANK	GPIOC

//INU - D11
#define INUPIN 	GPIO_PIN_15
#define INUBANK 	GPIOB

//INV - D10
#define INVPIN 	GPIO_PIN_11
#define INVBANK 	GPIOA

//INW - D9
#define INWPIN 	GPIO_PIN_8
#define INWBANK 	GPIOA

//INHU - D6
#define INHUPIN 	GPIO_PIN_10
#define INHUBANK 	GPIOB

//INHV - D5
#define INHVPIN 	GPIO_PIN_15
#define INHVBANK 	GPIOA

//INHW - D3
#define INHWPIN 	GPIO_PIN_3
#define INHWBANK 	GPIOB

//ADC_U - A3
#define ADC_UPIN 	GPIO_PIN_2
#define ADC_UBANK 	GPIOC

//ADC_V - A2
#define ADC_VPIN 	GPIO_PIN_3
#define ADC_VBANK 	GPIOC

//ADC_W - A1
#define ADC_WPIN 	GPIO_PIN_1
#define ADC_WBANK 	GPIOA

// GLOBAL VARIABLES //
extern uint32_t adc_values[6];

// FREERTOS.C //
typedef enum
{
	step0,
	step1,
	step2,
	step3,
	step4,
	step5
}state_t;

#endif /* INC_HEADER_H_ */
