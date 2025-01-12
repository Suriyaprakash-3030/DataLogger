/*
 * UART.c
 *
 *  Created on: Dec 3, 2024
 *      Author: suriya.prakash
 */


#include <main.h>
#include "UART.h"

/**
  * @brief USART1 Initialization Function
  * @param None
  * @retval None
  */
 void MX_USART1_UART_Init(void)
{

  /* USER CODE BEGIN USART1_Init 0 */

  /* USER CODE END USART1_Init 0 */

  /* USER CODE BEGIN USART1_Init 1 */

  /* USER CODE END USART1_Init 1 */
  huart1.Instance = USART1;
  huart1.Init.BaudRate = 115200;
  huart1.Init.WordLength = UART_WORDLENGTH_8B;
  huart1.Init.StopBits = UART_STOPBITS_1;
  huart1.Init.Parity = UART_PARITY_NONE;
  huart1.Init.Mode = UART_MODE_TX_RX;
  huart1.Init.HwFlowCtl = UART_HWCONTROL_NONE;
  huart1.Init.OverSampling = UART_OVERSAMPLING_16;
  if (HAL_UART_Init(&huart1) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN USART1_Init 2 */

  /* USER CODE END USART1_Init 2 */

}


 //-------------------------------------UART PRINT -->BEGIN-------------------------------------------//
 void UART_Printf(const char * fmt, ...) {
   char buff[256];
   va_list args;
   va_start(args, fmt);
   vsnprintf(buff, sizeof(buff), fmt, args);
   HAL_UART_Transmit( & huart1, (uint8_t * ) buff, strlen(buff), HAL_MAX_DELAY);
   va_end(args);
 }

 //-------------------------------------UART PRINT -->END-------------------------------------------//
