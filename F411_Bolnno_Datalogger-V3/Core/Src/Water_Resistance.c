/*
 * Water_Resistance.c
 *
 *  Created on: Dec 5, 2024
 *      Author: suriya.prakash
 */
#include <math.h>
#include <main.h>
#include "Define.h"
#include "ADC.h"
#include "Water_Resistance.h"

float w_adcBuffer = 0;
float Water_Res(float W_res)
{

					ADC_ChannelConfTypeDef sConfig = {0};
		    		 sConfig.Channel = ADC_CHANNEL_8;
		    		 sConfig.Rank = 1;
		    		 sConfig.SamplingTime = ADC_SAMPLETIME_3CYCLES;
		    			  if (HAL_ADC_ConfigChannel(&hadc1, &sConfig) != HAL_OK)
		    			  {
		    			      Error_Handler();
		    			  }
		    			  HAL_ADC_Start(&hadc1);
		    			  HAL_ADC_PollForConversion(&hadc1, HAL_MAX_DELAY);
		    			  w_adcBuffer = HAL_ADC_GetValue(&hadc1);
		    			  HAL_ADC_Stop(&hadc1);
		    			  float OP_voltage = w_adcBuffer * Volt_Ref / ADC_Res;
		    			  float Rwater = ((1000 * Volt_Ref)/ OP_voltage)-1000;// 1000 IS 1K ITS USED IN VOLT DIVIDER CIRCUIT IN DATALOGGER formula:R1 = ((R2XVIN)/VOUT)-R2
		    			  if (!isfinite(Rwater) || isnan(Rwater))
		    			  	{
		    				  return 0.0; // Return 0 if value is -inf, inf, or nan
		    			  	}


		    			  return Rwater;


}
