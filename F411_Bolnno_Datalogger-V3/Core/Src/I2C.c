/*
 * I2C.c
 *
 *  Created on: Dec 3, 2024
 *      Author: suriya.prakash
 */


#include "I2C.h"

/**
  * @brief I2C1 Initialization Function
  * @param None
  * @retval None
  */
 void MX_I2C1_Init(void)
{

  /* USER CODE BEGIN I2C1_Init 0 */

  /* USER CODE END I2C1_Init 0 */

  /* USER CODE BEGIN I2C1_Init 1 */

  /* USER CODE END I2C1_Init 1 */
  hi2c1.Instance = I2C1;
  hi2c1.Init.ClockSpeed = 100000;
  hi2c1.Init.DutyCycle = I2C_DUTYCYCLE_2;
  hi2c1.Init.OwnAddress1 = 0;
  hi2c1.Init.AddressingMode = I2C_ADDRESSINGMODE_7BIT;
  hi2c1.Init.DualAddressMode = I2C_DUALADDRESS_DISABLE;
  hi2c1.Init.OwnAddress2 = 0;
  hi2c1.Init.GeneralCallMode = I2C_GENERALCALL_DISABLE;
  hi2c1.Init.NoStretchMode = I2C_NOSTRETCH_DISABLE;
  if (HAL_I2C_Init(&hi2c1) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN I2C1_Init 2 */

  /* USER CODE END I2C1_Init 2 */

}


 void I2C_WriteByte(uint8_t reg, uint8_t data) {
     HAL_I2C_Mem_Write(&hi2c1, Device_Address << 1, reg, I2C_MEMADD_SIZE_8BIT, &data, 1, HAL_MAX_DELAY);
 }

 /**
  * @brief Reads multiple bytes from a specific register of the device over I2C.
  * @param reg: Register address
  * @param data: Pointer to data buffer to store read bytes
  * @param len: Number of bytes to read
  */
 void I2C_ReadData(uint8_t reg, uint8_t *data, uint16_t len) {
     HAL_I2C_Mem_Read(&hi2c1, Device_Address << 1, reg, I2C_MEMADD_SIZE_8BIT, data, len, HAL_MAX_DELAY);
 }
