/*
 * NTC.c
 *
 *  Created on: Dec 3, 2024
 *      Author: suriya.prakash
 */


#include <main.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include "Define.h"
#include "UART.h"
#include "NTC.h"
#include "ADC.h"
#include "Data.h"

float NTC_ADC_Buffer[4];
float Divider_Resistor = 10000;
float T0 = 298.15;
float T1_Bvalue = 3435;
float T2_Bvalue = 3590;




int* NTC_Array(int Tot_Sensor)
{
    // Allocate memory for the array
    int* NTC_Data = (int*)malloc(Tot_Sensor * sizeof(int));

    // Check if memory allocation was successful
    if (NTC_Data == NULL) {
    	UART_Printf("Memory allocation failed!\n");
        exit(1); // Exit the program if allocation fails
    }

    // Initialize the NTC_Data with example values
    for (int i = 0; i < Tot_Sensor; i++) {


    	if(i==0)
    	{
    		 ADC_ChannelConfTypeDef sConfig = {0};
    		 sConfig.Channel = ADC_CHANNEL_1;
    		 sConfig.Rank = 1;
    		 sConfig.SamplingTime = ADC_SAMPLETIME_3CYCLES;
    			  if (HAL_ADC_ConfigChannel(&hadc1, &sConfig) != HAL_OK)
    			  {
    			      Error_Handler();
    			  }
    			  HAL_ADC_Start(&hadc1);
    			  HAL_ADC_PollForConversion(&hadc1, HAL_MAX_DELAY);
    			  NTC_ADC_Buffer [i]= HAL_ADC_GetValue(&hadc1);
    			  HAL_ADC_Stop(&hadc1);

    			  /*************************NTC CALCULATION*********************************/
//
//    			  float voltage = (NTC_ADC_Buffer[i] * Volt_Ref) / ADC_Res;
//
//    			  float Res = (Divider_Resistor * voltage ) / (Volt_Ref - voltage);
//
//    			  float logR = log(Res / Divider_Resistor);
//
//    			  NTC_Data[i] = 1.0 / ((logR / T1_Bvalue) + (1.0 / T0)) - 275.15;

    			  float resistance = Divider_Resistor * (4095.0 / NTC_ADC_Buffer[i] - 1);

    			  NTC_Data[i] = 1.0 / ((log(resistance / Divider_Resistor)) / T1_Bvalue + 1.0 / T0) - 273.15;

    			  /*************************NTC CALCULATION*********************************/

    	}

    	if(i==1)
    	{
    		 ADC_ChannelConfTypeDef sConfig = {0};
    		    		 sConfig.Channel = ADC_CHANNEL_2;
    		    		 sConfig.Rank = 1;
    		    		 sConfig.SamplingTime = ADC_SAMPLETIME_3CYCLES;
    		    			  if (HAL_ADC_ConfigChannel(&hadc1, &sConfig) != HAL_OK)
    		    			  {
    		    			      Error_Handler();
    		    			  }
    		    			  HAL_ADC_Start(&hadc1);
    		    			  HAL_ADC_PollForConversion(&hadc1, HAL_MAX_DELAY);
    		    			  NTC_ADC_Buffer[i] = HAL_ADC_GetValue(&hadc1);
    		    			  HAL_ADC_Stop(&hadc1);

    		    			  /*************************NTC CALCULATION*********************************/

    		    			  float voltage = (NTC_ADC_Buffer[i] * Volt_Ref) / ADC_Res;

    		    			  float Res = (Divider_Resistor * voltage ) / (Volt_Ref - voltage);

    		    			  float logR = log(Res / Divider_Resistor);

    		    			  NTC_Data[i] = 1.0 / ((logR / T2_Bvalue) + (1.0 / T0)) - 275.15;

    		    			  /*************************NTC CALCULATION*********************************/
    	}
    	if(i==2)
    	{
    		 ADC_ChannelConfTypeDef sConfig = {0};
    		    		 sConfig.Channel = ADC_CHANNEL_3;
    		    		 sConfig.Rank = 1;
    		    		 sConfig.SamplingTime = ADC_SAMPLETIME_3CYCLES;
    		    			  if (HAL_ADC_ConfigChannel(&hadc1, &sConfig) != HAL_OK)
    		    			  {
    		    			      Error_Handler();
    		    			  }
    		    			  HAL_ADC_Start(&hadc1);
    		    			  HAL_ADC_PollForConversion(&hadc1, HAL_MAX_DELAY);
    		    			  NTC_ADC_Buffer[i] = HAL_ADC_GetValue(&hadc1);
    		    			  HAL_ADC_Stop(&hadc1);

    		    			  /*************************NTC CALCULATION*********************************/

    		    			  float voltage = (NTC_ADC_Buffer[i] * Volt_Ref) / ADC_Res;

    		    			  float Res = (Divider_Resistor * voltage ) / (Volt_Ref - voltage);

    		    			  float logR = log(Res / Divider_Resistor);

    		    			  NTC_Data[i] = 1.0 / ((logR / T2_Bvalue) + (1.0 / T0)) - 275.15;

    		    			  /*************************NTC CALCULATION*********************************/

    	}
    	if(i==3)
    	{
    		 ADC_ChannelConfTypeDef sConfig = {0};
    		    		 sConfig.Channel = ADC_CHANNEL_4;
    		    		 sConfig.Rank = 1;
    		    		 sConfig.SamplingTime = ADC_SAMPLETIME_3CYCLES;
    		    			  if (HAL_ADC_ConfigChannel(&hadc1, &sConfig) != HAL_OK)
    		    			  {
    		    			      Error_Handler();
    		    			  }
    		    			  HAL_ADC_Start(&hadc1);
    		    			  HAL_ADC_PollForConversion(&hadc1, HAL_MAX_DELAY);
    		    			  NTC_ADC_Buffer[i] = HAL_ADC_GetValue(&hadc1);
    		    			  HAL_ADC_Stop(&hadc1);

    		    			  /*************************NTC CALCULATION*********************************/

    		    			  float voltage = (NTC_ADC_Buffer[i] * Volt_Ref) / ADC_Res;

    		    			  float Res = (Divider_Resistor * voltage ) / (Volt_Ref - voltage);

    		    			  float logR = log(Res / Divider_Resistor);

    		    			  NTC_Data[i] = 1.0 / ((logR / T2_Bvalue) + (1.0 / T0)) - 275.15;

    		    			  /*************************NTC CALCULATION*********************************/

    	}



    }

    // Return the pointer to the allocated NTC_Data
    return NTC_Data;
}
