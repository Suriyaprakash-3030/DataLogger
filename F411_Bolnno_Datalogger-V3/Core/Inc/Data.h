/*
 * Data.h
 *
 *  Created on: Dec 5, 2024
 *      Author: suriya.prakash
 */

#ifndef INC_DATA_H_
#define INC_DATA_H_

#include <main.h>
#include "Accelerometer.h"
#include "Ultrasonic.h"
#include "Water_Resistance.h"
#include "Pressure_Sensor.h"
#include "ISR.h"

typedef struct
{
	float Timer_Count;
	float XAxis;
	float YAxis;
	float ZAxis;
	float On_Board_Temp;
	float EXT_Temp1;
	float EXT_Temp2;
	float EXT_Temp3;
	float Amplitude;
	float Water_Resistance;
	float Pressure;
	float Sleep_Count;

} DataSet;


DataSet Store_Data();
extern float Timer_Count;
extern float Sleep_Count;



#endif /* INC_DATA_H_ */
