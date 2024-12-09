/*
 * ISR.h
 *
 *  Created on: Dec 5, 2024
 *      Author: suriya.prakash
 */

#ifndef INC_ISR_H_
#define INC_ISR_H_

#include <main.h>

extern TIM_HandleTypeDef htim4;
extern TIM_HandleTypeDef htim3;



// Function prototype for the Timer ISR handler
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim);
void Sleep_mode();
//void Sleep_mode(void);


#endif /* INC_ISR_H_ */
