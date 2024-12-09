/*
 * Define.h
 *
 *  Created on: Dec 3, 2024
 *      Author: suriya.prakash
 */

#ifndef INC_DEFINE_H_
#define INC_DEFINE_H_

#include <main.h>

#define Pi 3.141


/**System start**/
#define P_X_Max 80                   // Positive max threshold
#define P_X_Min 45                   // Positive min threshold
#define N_X_Max -80                  // Negative max threshold
#define N_X_Min -45                  // Negative min threshold

#define P_Y_Max 80                   // Positive max threshold
#define P_Y_Min 45                   // Positive min threshold
#define N_Y_Max -80                  // Negative max threshold
#define N_Y_Min -45                  // Negative min threshold

#define P_Z_Max 80                   // Positive max threshold
#define P_Z_Min 45                   // Positive min threshold
#define N_Z_Max -80                  // Negative max threshold
#define N_Z_Min -45                  // Negative min threshold


#define ADC_Res 4095
#define Volt_Ref 3.3


#define Loop_Time 500          //give in ms
#define Sleep_Time 10000         //give in ms
#define Sleep_temp 40.0

#define Total_Ntc_Sensor 4
#define CTRL1_REG_ADDR 0x20          // Control register for configuration
#define Device_Address 0x19          // I2C device address for the accelerometer

#endif /* INC_DEFINE_H_ */
