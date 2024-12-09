/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2024 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32f4xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define Vibrator_Pin GPIO_PIN_13
#define Vibrator_GPIO_Port GPIOC
#define Ultrsonic_Pin GPIO_PIN_0
#define Ultrsonic_GPIO_Port GPIOA
#define T1_Pin GPIO_PIN_1
#define T1_GPIO_Port GPIOA
#define T2_Pin GPIO_PIN_2
#define T2_GPIO_Port GPIOA
#define T3_Pin GPIO_PIN_3
#define T3_GPIO_Port GPIOA
#define T4_Pin GPIO_PIN_4
#define T4_GPIO_Port GPIOA
#define PR_SEN_Pin GPIO_PIN_7
#define PR_SEN_GPIO_Port GPIOA
#define Water_Res_Pin GPIO_PIN_0
#define Water_Res_GPIO_Port GPIOB
#define Det_Switch_Pin GPIO_PIN_13
#define Det_Switch_GPIO_Port GPIOB

/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
