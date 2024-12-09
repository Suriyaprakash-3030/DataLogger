/*
 * Pressure_Sensor.c
 *
 *  Created on: Dec 5, 2024
 *      Author: suriya.prakash
 */

#include <math.h>
#include <main.h>
#include "Define.h"
#include "Pressure_Sensor.h"


float Pressure_Adc =0;

float PresureSensorData(float P_SENS)
{
				 ADC_ChannelConfTypeDef sConfig = {0};
	    		 sConfig.Channel = ADC_CHANNEL_7;
	    		 sConfig.Rank = 1;
	    		 sConfig.SamplingTime = ADC_SAMPLETIME_3CYCLES;
	    			  if (HAL_ADC_ConfigChannel(&hadc1, &sConfig) != HAL_OK)
	    			  {
	    			      Error_Handler();
	    			  }
	    			  HAL_ADC_Start(&hadc1);
	    			  HAL_ADC_PollForConversion(&hadc1, HAL_MAX_DELAY);
	    			  Pressure_Adc = HAL_ADC_GetValue(&hadc1);
	    			  HAL_ADC_Stop(&hadc1);

	    			 float p_volt = (Pressure_Adc * Volt_Ref) /ADC_Res;
	    			 float Pressure = (p_volt / Volt_Ref) / 0.01155; //  1.5-3.5mV/V and 3.3V swing as per the circuit:
	    			 if (!isfinite(Pressure) || isnan(Pressure))
	    			{
	    				 return 0.0; // Return 0 if value is -inf, inf, or nan
	    			}

	    			 return Pressure;

}
