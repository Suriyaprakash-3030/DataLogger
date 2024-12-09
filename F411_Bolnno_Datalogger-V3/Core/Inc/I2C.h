/*
 * I2C.h
 *
 *  Created on: Dec 3, 2024
 *      Author: suriya.prakash
 */

#ifndef INC_I2C_H_
#define INC_I2C_H_

#include <main.h>
#include "Define.h"



extern I2C_HandleTypeDef hi2c1;



 void MX_I2C1_Init(void);
 void I2C_WriteByte(uint8_t reg, uint8_t data);
 void I2C_ReadData(uint8_t reg, uint8_t *data, uint16_t len);


#endif /* INC_I2C_H_ */
