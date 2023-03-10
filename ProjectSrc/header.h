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

//INU
#define INUPIN 	GPIO_PIN_15
#define INUBANK 	GPIOB

//INV
#define INVPIN 	GPIO_PIN_11
#define INVBANK 	GPIOA

//INW
#define INWPIN 	GPIO_PIN_8
#define INWBANK 	GPIOA

//INHU
#define INHUPIN 	GPIO_PIN_10
#define INHUBANK 	GPIOB

//INHV
#define INHVPIN 	GPIO_PIN_15
#define INHVBANK 	GPIOA

//INHW
#define INHWPIN 	GPIO_PIN_3
#define INHWBANK 	GPIOB

//ADC_U
#define ADC_UPIN 	GPIO_PIN_2
#define ADC_UBANK 	GPIOC

//ADC_V
#define ADC_VPIN 	GPIO_PIN_3
#define ADC_VBANK 	GPIOC

//ADC_W
#define ADC_WPIN 	GPIO_PIN_1
#define ADC_WBANK 	GPIOA

// TASKS.C //
extern uint32_t adc_values[3];

void task01_function();
void task02_function();

#endif /* INC_HEADER_H_ */
