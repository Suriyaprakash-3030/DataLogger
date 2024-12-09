/*
 * Accelerometer.h
 *
 *  Created on: Dec 4, 2024
 *      Author: suriya.prakash
 */

#ifndef INC_ACCELEROMETER_H_
#define INC_ACCELEROMETER_H_
#include <main.h>
#include <stdbool.h>
#include "Define.h"
#include "Data.h"

// Accelerometer constants
typedef struct{

	float x,y,z;

}Acclerometer_Data;


extern bool Sys_Start;

uint8_t System_Start();
Acclerometer_Data Get_Axis();
bool Acc_Init(void);

#endif /* INC_ACCELEROMETER_H_ */
