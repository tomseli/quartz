/*
 * Tasks.c
 *
 *  Created on: 9 mrt. 2023
 *      Author: Tom
 */
#include "main.h"
#include "cmsis_os.h"
#include "header.h"
#include "uart.h"

extern uint32_t adc_values[3];

int number = 0;
int countup = 1;

void task01_function()
{
//	if(countup)
//		number++;
//	else
//		number--;
//
//	if(number == 100)
//		countup = 0;
//	else if(number == 0)
//		countup = 1;
//
//	UART_int(number);
//	UART_char('\t');
//	UART_char('\n');
	osDelay(50);
}


void task02_function()
{
	UART_int(adc_values[0] << 2);
	UART_char('\t');

	UART_int(adc_values[1] << 2);
	UART_char('\t');

	UART_int(adc_values[2] << 2);
	UART_char('\t');
	UART_char('\n');
	osDelay(5);
}
