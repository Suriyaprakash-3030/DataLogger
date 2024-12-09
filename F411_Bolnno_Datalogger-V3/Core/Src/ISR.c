/*
 * ISR.c
 *
 *  Created on: Dec 5, 2024
 *      Author: suriya.prakash
 */

#include <main.h>
#include "ISR.h"
#include <stdbool.h>
#include "UART.h"
#include "SD_Card.h"
#include "Define.h"
#include "Data.h"
#include "NTC.h"


//extern struct DataSet;


float Sleep_Thre = 0;

bool Sleep_flag = false;


float Sleep_Count = 0;

float Timer_Count = 0;
/**
 * @brief Callback function called when the timer period elapses.
 *        This function handles reading ADC values, logging data, and managing system sleep mode.
 * @param htim Timer handler pointer
 */


void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim) {
		if (htim->Instance == TIM3 && !Sleep_flag) {

			DATA_LOG();
			Timer_Count+=0.5;
			Sleep_mode();

		}
	 else if (Sleep_flag) {
		if (htim->Instance == TIM4) {
			Sleep_flag = false;
//            UART_Printf("Hello \n");
		}
	}
}

//extern DataSet Store_Data();

void Sleep_mode() {

	int Tot_Sensor = 4;
	int* NTC_Temp = NTC_Array(Tot_Sensor);

	for (int i = 0; i < Tot_Sensor; i++)
	{
			NTC_Temp[i];
	}

	if (NTC_Temp[0] >= Sleep_temp) {
		Sleep_Count += 1.0;
		Sleep_flag = true;
//		HAL_TIM_Base_Start_IT(&htim4);
//		HAL_TIM_Base_Stop_IT(&htim3);
		UART_Printf("********* Over Temp Sys going to Sleep Mode************\n");


//		UART_Printf("********* Sleep Count %d************\n",Sleep_Count);

		HAL_SuspendTick();
		HAL_PWR_EnterSLEEPMode(PWR_MAINREGULATOR_ON, PWR_SLEEPENTRY_WFI);
		HAL_ResumeTick();
//		HAL_TIM_Base_Start_IT(&htim4);
//		HAL_TIM_Base_Start_IT(&htim4);
	}

}



