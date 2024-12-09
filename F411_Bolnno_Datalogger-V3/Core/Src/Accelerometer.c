/*
 * Accelerometer.c
 *
 *  Created on: Dec 4, 2024
 *      Author: suriya.prakash
 */
#include <main.h>
#include <math.h>
#include <stdbool.h>
#include "Accelerometer.h"
#include "I2C.h"
#include "Define.h"
#include "UART.h"
#include "Data.h"

bool Accelerometer_Test_Flag = 0;

float pitch_angle_deg = 0.0;
float roll_angle_deg = 0.0;
float yaw_angle_deg = 0.0;

typedef enum {
    IDLE,
    POSITIVE_THRESHOLD,
    NEGATIVE_THRESHOLD
} TiltState;

TiltState tilt = IDLE;




bool Acc_Init(void) {
    // Configure accelerometer with control register
			uint8_t whoAmI = 0;
			I2C_WriteByte(CTRL1_REG_ADDR, 0x57);
			HAL_Delay(100);
			HAL_I2C_Mem_Read(&hi2c1, 0x33, 0x0F, 1, &whoAmI, 1, HAL_MAX_DELAY);
			Accelerometer_Test_Flag = (whoAmI == 0x33) ?   true :   false;
			HAL_Delay(100);
//			if(!Accelerometer_Test_Flag)NVIC_SystemReset();
			return Accelerometer_Test_Flag;
}


Acclerometer_Data Get_Axis()
{




	// Angle variables

			int32_t x=0, y=0, z=0;
		    uint8_t num = 255;
		    uint8_t rawData[6];
		    int16_t accelX=0, accelY=0, accelZ=0;




		    for (uint8_t i = 0; i < num; i++) {
		    	HAL_I2C_Mem_Read(&hi2c1, Device_Address << 1, 0xA8 | 0x80, 1, rawData, 6, HAL_MAX_DELAY);
		        accelX = (int16_t)((rawData[1] << 8) | rawData[0]);
		        accelY = (int16_t)((rawData[3] << 8) | rawData[2]);
		        accelZ = (int16_t)((rawData[5] << 8) | rawData[4]);

		        x += accelX;
		        y += accelY;
		        z += accelZ;
		    }

		    accelX = accelX / num;
		    accelY = accelY / num;
		    accelZ = accelZ / num;

		    float acceleration_x = (float)accelX / 32768.0 * 2.0;
		    float acceleration_y = (float)accelY / 32768.0 * 2.0;
		    float acceleration_z = (float)accelZ / 32768.0 * 2.0;

		    // Calculate angle in radians
		    float pitch_angle = atan2(acceleration_y, sqrt(acceleration_x * acceleration_x + acceleration_z * acceleration_z));
		    float roll_angle = atan2(-acceleration_x, acceleration_z);
		    float yaw_angle = atan2(sqrt(acceleration_x * acceleration_x + acceleration_y * acceleration_y), acceleration_z);

		    // radians to angle formula radian/(180/pi)
		    pitch_angle_deg = (pitch_angle * (180.0 / Pi));
		    roll_angle_deg = (roll_angle * (180.0 / Pi)); // PI VALUE ALSO MACRO
		    yaw_angle_deg = (yaw_angle * (180.0 / Pi));
		    pitch_angle_deg= (float)((int)(pitch_angle_deg * 100)) / 100;


		    Acclerometer_Data AXIS = {pitch_angle_deg , roll_angle_deg, yaw_angle_deg };
		    if(!Sys_Start)UART_Printf("X-AXIS = %d , Y-AXIS = %d ,Z-AXIS = %d  \n",(int)pitch_angle_deg, (int)roll_angle_deg, (int)yaw_angle_deg);
		    return AXIS;
}


uint8_t System_Start()
{

	Acclerometer_Data Angles = Get_Axis();


	switch (tilt) {
		        case IDLE:
		            if ((Angles.x >= P_X_Min && Angles.x < P_X_Max)  ||  // NEED A MACRO FOR THE VALUES 70
					   (Angles.y >= P_Y_Min && Angles.x < P_Y_Max)  ||
					   (Angles.z >= P_Z_Min && Angles.x < P_Z_Max))
		            {
		                tilt = POSITIVE_THRESHOLD;
		                UART_Printf("Axis reach Positive Threshold \n");
		            }
		            break;

		        case POSITIVE_THRESHOLD:
		            if ((Angles.x >= N_X_Max && Angles.x < N_X_Min)||
		                (Angles.y >= N_Y_Max && Angles.x < N_Y_Min) ||
					    (Angles.z >= N_Z_Max && Angles.x < N_Z_Min))

					{
		                tilt = NEGATIVE_THRESHOLD;
		                UART_Printf("Axis reach Negative Threshold \n");
		            }
		            break;

		        case NEGATIVE_THRESHOLD:
//		            if (System_On_Flag == true) {
		        		UART_Printf("System Starts \n");
		                HAL_GPIO_WritePin(GPIOC, GPIO_PIN_13, 1);
		                HAL_Delay(500);
		                HAL_GPIO_WritePin(GPIOC, GPIO_PIN_13, 0);
		                HAL_Delay(500);
		                HAL_GPIO_WritePin(GPIOC, GPIO_PIN_13, 1);
		                HAL_Delay(3000);
		                HAL_GPIO_WritePin(GPIOC, GPIO_PIN_13, 0);
		                Sys_Start = true;
//		            }
		            break;
		    }

return Sys_Start;

}

