/*
 * Ultrasonic.c
 *
 *  Created on: Dec 5, 2024
 *      Author: suriya.prakash
 */

#include <main.h>
#include <math.h>
#include "Define.h"
#include "ADC.h"
#include "Ultrasonic.h"


float U_adcBuffer = 0;
float Ultrasonic_Amplitude(float U_amp)
{

					ADC_ChannelConfTypeDef sConfig = {0};
		    		 sConfig.Channel = ADC_CHANNEL_0;
		    		 sConfig.Rank = 1;
		    		 sConfig.SamplingTime = ADC_SAMPLETIME_3CYCLES;
		    			  if (HAL_ADC_ConfigChannel(&hadc1, &sConfig) != HAL_OK)
		    			  {
		    			      Error_Handler();
		    			  }
		    			  HAL_ADC_Start(&hadc1);
		    			  HAL_ADC_PollForConversion(&hadc1, HAL_MAX_DELAY);
		    			  U_adcBuffer = HAL_ADC_GetValue(&hadc1);
		    			  HAL_ADC_Stop(&hadc1);

		    			  float khz = 20*log(U_adcBuffer/2234.2);
		    			  if (!isfinite(khz) || isnan(khz))
		    			  {
		    			         return 0.0; // Return 0 if value is -inf, inf, or nan
		    			  }
		    			  return khz;


}
