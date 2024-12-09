/*
 * UART.h
 *
 *  Created on: Dec 3, 2024
 *      Author: suriya.prakash
 */

#ifndef INC_UART_H_
#define INC_UART_H_
#include <main.h>
#include <stdarg.h>
#include <string.h>
#include <stdio.h>
extern UART_HandleTypeDef huart1;


void UART_Printf(const char * fmt, ...);
void MX_USART1_UART_Init(void);

#endif /* INC_UART_H_ */
