/*
 * Data.c
 *
 *  Created on: Dec 5, 2024
 *      Author: suriya.prakash
 */


#include <stdio.h>
#include "Data.h"
#include "NTC.h"
#include "Accelerometer.h"
#include "Ultrasonic.h"
#include "Water_Resistance.h"
#include "Pressure_Sensor.h"
#include "ISR.h"

//extern struct CollectData;
extern float Sleep_Thre;

DataSet Store_Data()
{


	int Tot_Sensor = 4;
	int* NTC_Temp = NTC_Array(Tot_Sensor);

	for (int i = 0; i < Tot_Sensor; i++)
	{
			NTC_Temp[i];
	}




    Acclerometer_Data Angles = Get_Axis();

	float U_amp =  0.0;
	U_amp = Ultrasonic_Amplitude(U_amp);
	float W_res = 0.0;
	W_res = Water_Res(W_res);
	float Pres = 0.0;
	Pres = PresureSensorData(Pres);



	DataSet data = { Timer_Count, Angles.x, Angles.y, Angles.z, NTC_Temp[0],NTC_Temp[1],NTC_Temp[2], NTC_Temp[3],U_amp,W_res,Pres,Sleep_Count};

	return data;

}
