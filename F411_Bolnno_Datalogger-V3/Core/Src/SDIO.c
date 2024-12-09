/*
 * SDIO.c
 *
 *  Created on: Dec 3, 2024
 *      Author: suriya.prakash
 */


#include "SDIO.h"



/**
  * @brief SDIO Initialization Function
  * @param None
  * @retval None
  */
 void MX_SDIO_SD_Init(void)
{

  /* USER CODE BEGIN SDIO_Init 0 */

  /* USER CODE END SDIO_Init 0 */

  /* USER CODE BEGIN SDIO_Init 1 */

  /* USER CODE END SDIO_Init 1 */
	 hsd.Instance = SDIO;
		  hsd.Init.ClockEdge = SDIO_CLOCK_EDGE_RISING;
		  hsd.Init.ClockBypass = SDIO_CLOCK_BYPASS_DISABLE;
		  hsd.Init.ClockPowerSave = SDIO_CLOCK_POWER_SAVE_DISABLE;
		  hsd.Init.BusWide = SDIO_BUS_WIDE_1B;
		  hsd.Init.HardwareFlowControl = SDIO_HARDWARE_FLOW_CONTROL_DISABLE;
		  hsd.Init.ClockDiv = 6;
  /* USER CODE BEGIN SDIO_Init 2 */

  /* USER CODE END SDIO_Init 2 */

}
