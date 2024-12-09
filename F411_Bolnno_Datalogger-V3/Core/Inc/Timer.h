/*
 * Timer.h
 *
 *  Created on: Dec 3, 2024
 *      Author: suriya.prakash
 */

#ifndef INC_TIMER_H_
#define INC_TIMER_H_

#include <main.h>

extern TIM_HandleTypeDef htim3;
extern TIM_HandleTypeDef htim4;

void MX_TIM3_Init(void);
void MX_TIM4_Init(void);

#endif /* INC_TIMER_H_ */
