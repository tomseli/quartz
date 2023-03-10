/* USER CODE BEGIN Header */
/**
 ******************************************************************************
 * File Name          : freertos.c
 * Description        : Code for freertos applications
 ******************************************************************************
 * @attention
 *
 * Copyright (c) 2023 STMicroelectronics.
 * All rights reserved.
 *
 * This software is licensed under terms that can be found in the LICENSE file
 * in the root directory of this software component.
 * If no LICENSE file comes with this software, it is provided AS-IS.
 *
 ******************************************************************************
 */
/* USER CODE END Header */

/* Includes ------------------------------------------------------------------*/
#include "FreeRTOS.h"
#include "task.h"
#include "main.h"
#include "cmsis_os.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "UART.h"
#include "header.h"
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */

/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
/* USER CODE BEGIN Variables */
unsigned char button = 0;

unsigned short dutyCycleLength = 1000; // in ms
unsigned short dutyCycle = 25;			// active in ms

/* USER CODE END Variables */
/* Definitions for Task01_ID */
osThreadId_t Task01_IDHandle;
const osThreadAttr_t Task01_ID_attributes =
{.name = "Task01_ID", .stack_size = 128 * 4, .priority =
		(osPriority_t) osPriorityNormal, };
/* Definitions for Task02_ID */
osThreadId_t Task02_IDHandle;
const osThreadAttr_t Task02_ID_attributes =
{.name = "Task02_ID", .stack_size = 128 * 4, .priority =
		(osPriority_t) osPriorityLow, };
/* Definitions for Task03_ID */
osThreadId_t Task03_IDHandle;
const osThreadAttr_t Task03_ID_attributes =
{.name = "Task03_ID", .stack_size = 128 * 4, .priority =
		(osPriority_t) osPriorityLow, };

/* Private function prototypes -----------------------------------------------*/
/* USER CODE BEGIN FunctionPrototypes */

/* USER CODE END FunctionPrototypes */

void
Task01(void *argument);
void
Task02(void *argument);
void
Task03(void *argument);

void
MX_FREERTOS_Init(void); /* (MISRA C 2004 rule 8.1) */

/**
 * @brief  FreeRTOS initialization
 * @param  None
 * @retval None
 */
void MX_FREERTOS_Init(void)
{
	/* USER CODE BEGIN Init */

	/* USER CODE END Init */

	/* USER CODE BEGIN RTOS_MUTEX */
	/* add mutexes, ... */
	/* USER CODE END RTOS_MUTEX */

	/* USER CODE BEGIN RTOS_SEMAPHORES */
	/* add semaphores, ... */
	/* USER CODE END RTOS_SEMAPHORES */

	/* USER CODE BEGIN RTOS_TIMERS */
	/* start timers, add new ones, ... */
	/* USER CODE END RTOS_TIMERS */

	/* USER CODE BEGIN RTOS_QUEUES */
	/* add queues, ... */
	/* USER CODE END RTOS_QUEUES */

	/* Create the thread(s) */
	/* creation of Task01_ID */
	Task01_IDHandle = osThreadNew(Task01, NULL, &Task01_ID_attributes);

	/* creation of Task02_ID */
	Task02_IDHandle = osThreadNew(Task02, NULL, &Task02_ID_attributes);

	/* creation of Task03_ID */
	Task03_IDHandle = osThreadNew(Task03, NULL, &Task03_ID_attributes);

	/* USER CODE BEGIN RTOS_THREADS */
	/* add threads, ... */
	/* USER CODE END RTOS_THREADS */

	/* USER CODE BEGIN RTOS_EVENTS */
	/* add events, ... */
	/* USER CODE END RTOS_EVENTS */

}

/* USER CODE BEGIN Header_Task01 */
/**
 * @brief  Function implementing the Task01_ID thread.
 * @param  argument: Not used
 * @retval None
 */
/* USER CODE END Header_Task01 */
void Task01(void *argument)
{
	/* USER CODE BEGIN Task01 */
	state_t state = step0;

	/* Infinite loop */
	for(;;)
	{
		switch(state)
		{
			case step0:
//				UART_string("\nStep0");
//				UART_string("\nHigh: U \nLow: W \nInhibit: V");
				HAL_GPIO_WritePin(INUBANK, INUPIN, 1);
				HAL_GPIO_WritePin(INWBANK, INWPIN, 0);
				HAL_GPIO_WritePin(INHVBANK, INHWPIN, 0);

				//uninhibit high and low
				HAL_GPIO_WritePin(INHUBANK, INHUPIN, 1);
				HAL_GPIO_WritePin(INHWBANK, INHWPIN, 1);
				state = step1;
				break;

			case step1:
//				UART_string("\nStep1");
//				UART_string("\nHigh: V \nLow: W \nInhibit: U");
				HAL_GPIO_WritePin(INVBANK, INVPIN, 1);
				HAL_GPIO_WritePin(INWBANK, INWPIN, 0);
				HAL_GPIO_WritePin(INHUBANK, INHUPIN, 0);

				//uninhibit high and low
				HAL_GPIO_WritePin(INHVBANK, INHVPIN, 1);
				HAL_GPIO_WritePin(INHWBANK, INHWPIN, 1);
				state = step2;
				break;

			case step2:
//				UART_string("\nStep2");
//				UART_string("\nHigh: V \nLow: U \nInhibit: W");
				HAL_GPIO_WritePin(INVBANK, INVPIN, 1);
				HAL_GPIO_WritePin(INUBANK, INUPIN, 0);
				HAL_GPIO_WritePin(INHWBANK, INHWPIN, 0);

				//uninhibit high and low
				HAL_GPIO_WritePin(INHVBANK, INHVPIN, 1);
				HAL_GPIO_WritePin(INHUBANK, INHUPIN, 1);
				state = step3;
				break;

			case step3:
//				UART_string("\nStep3");
//				UART_string("\nHigh: W \nLow: U \nInhibit: V");
				HAL_GPIO_WritePin(INWBANK, INWPIN, 1);
				HAL_GPIO_WritePin(INUBANK, INUPIN, 0);
				HAL_GPIO_WritePin(INHVBANK, INHVPIN, 0);

				//uninhibit high and low
				HAL_GPIO_WritePin(INHWBANK, INHWPIN, 1);
				HAL_GPIO_WritePin(INHUBANK, INHUPIN, 1);
				state = step4;
				break;

			case step4:
//				UART_string("\nStep4");
//				UART_string("\nHigh: W \nLow: V \nInhibit: U");
				HAL_GPIO_WritePin(INWBANK, INWPIN, 1);
				HAL_GPIO_WritePin(INVBANK, INVPIN, 0);
				HAL_GPIO_WritePin(INHUBANK, INHUPIN, 0);

				//uninhibit high and low
				HAL_GPIO_WritePin(INHWBANK, INHWPIN, 1);
				HAL_GPIO_WritePin(INHVBANK, INHVPIN, 1);
				state = step5;
				break;

			case step5:
//				UART_string("\nStep5");
//				UART_string("\nHigh: U \nLow: V \nInhibit: W");
				HAL_GPIO_WritePin(INUBANK, INUPIN, 1);
				HAL_GPIO_WritePin(INVBANK, INVPIN, 0);
				HAL_GPIO_WritePin(INHUBANK, INHUPIN, 0);

				//uninhibit high and low
				HAL_GPIO_WritePin(INHUBANK, INHUPIN, 1);
				HAL_GPIO_WritePin(INHVBANK, INHVPIN, 1);
				state = step0;
				break;

			default:
//				UART_string("Inhibit all");
				HAL_GPIO_WritePin(INHUBANK, INHUPIN, 0);
				HAL_GPIO_WritePin(INHVBANK, INHVPIN, 0);
				HAL_GPIO_WritePin(INHWBANK, INHWPIN, 0);
				break;
		}
		UART_char('\n');

		// determines torque (?)
		osDelay(dutyCycle);
		HAL_GPIO_WritePin(INHUBANK, INHUPIN, 0);
		HAL_GPIO_WritePin(INHVBANK, INHVPIN, 0);
		HAL_GPIO_WritePin(INHWBANK, INHWPIN, 0);

		// determines speed (?)
		osDelay(dutyCycleLength - dutyCycle);

		if(button == 1)
		{
			if(dutyCycleLength > 200)
			{
				dutyCycleLength -= 100;
			}
			else
			{
				dutyCycleLength = 1000;
			}
		}

	}
	/* USER CODE END Task01 */
}

/* USER CODE BEGIN Header_Task02 */
/**
 * @brief Function implementing the Task02_ID thread.
 * @param argument: Not used
 * @retval None
 */
/* USER CODE END Header_Task02 */
void Task02(void *argument)
{
	/* USER CODE BEGIN Task02 */
	/* Infinite loop */
	for(;;)
	{
		UART_int(adc_values[0]);
		UART_char('\t');

		UART_int(adc_values[1]);
		UART_char('\t');

		UART_int(adc_values[2]);
		UART_char('\t');

		UART_int(adc_values[3]);
		UART_char('\t');

		UART_int(adc_values[4]);
		UART_char('\t');

		UART_int(adc_values[5]);
		UART_char('\t');

		UART_int(dutyCycleLength);
		UART_char('\n');
		osDelay(1);
	}
	/* USER CODE END Task02 */
}

/* USER CODE BEGIN Header_Task03 */
/**
 * @brief Function implementing the Task03_ID thread.
 * @param argument: Not used
 * @retval None
 */
/* USER CODE END Header_Task03 */
void Task03(void *argument)
{
	/* USER CODE BEGIN Task03 */
	/* Infinite loop */
	for(;;)
	{
		button = HAL_GPIO_ReadPin(BUTTONBANK, BUTTONPIN);
		osDelay(50);
	}
	/* USER CODE END Task03 */
}

/* Private application code --------------------------------------------------*/
/* USER CODE BEGIN Application */

/* USER CODE END Application */

