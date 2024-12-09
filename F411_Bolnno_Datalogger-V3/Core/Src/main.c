/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
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
/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "fatfs.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include <stdio.h>
#include <stdbool.h>
#include "GPIO.h"
#include "SDIO.h"
#include "Timer.h"
#include "I2C.h"
#include "ADC.h"
#include "SD_Card.h"
#include "Accelerometer.h"
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */

/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */






/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
ADC_HandleTypeDef hadc1;

I2C_HandleTypeDef hi2c1;

SD_HandleTypeDef hsd;

TIM_HandleTypeDef htim3;
TIM_HandleTypeDef htim4;

UART_HandleTypeDef huart1;

/* USER CODE BEGIN PV */

bool Sys_Start = 0;
uint8_t Current_Log_File_No = 0;





const int Tot_Sensor = 4;

int* NTC_Temp;
/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */
void UART_Printf(const char * fmt, ...);
void MX_USART1_UART_Init(void);
uint8_t File_Number_Create();
uint8_t Num_Sys_Create();
uint8_t HTML_File_Create();
uint8_t Read_Log_Number(uint8_t FileNo);
uint8_t Read_Number_Sys(uint8_t sys_type);
void Create_DataLog_File();
void DATA_LOG();
void Update_Log_Num();
/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{
  /* USER CODE BEGIN 1 */

  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_ADC1_Init();
  MX_I2C1_Init();
  MX_SDIO_SD_Init();
  MX_TIM3_Init();
  MX_TIM4_Init();
  MX_USART1_UART_Init();
  MX_FATFS_Init();
  /* USER CODE BEGIN 2 */


  /************************Accelerometer_status*****************************/
  bool Acc_Status = 0;
  uint8_t i = 0;
  while(!Acc_Status)
  {
	  Acc_Status = Acc_Init();
	  UART_Printf("Acclerometer Testing time %d\n",i);
	  i++;
	  HAL_Delay(500);
	   if(i>10)
	   {
		   NVIC_SystemReset();
	   }
  }
  UART_Printf("Accelerometer Working \n");
  /************************Accelerometer_status*****************************/


  /************************SD CARD_status*****************************/

  uint8_t sdCardStatus = SD_Card_Test();
   while (sdCardStatus != FR_OK)
   {
     sdCardStatus = SD_Card_Test();
     HAL_Delay(500);
   }

  /************************SD CARD_status*****************************/

   /************************SD CARD_Create Number file.txt*****************************/

 uint8_t F_N_C = File_Number_Create();
  while(F_N_C != FR_OK)
  {
	  F_N_C = File_Number_Create();
   HAL_Delay(500);
  }

   /************************SD CARD_Create Number file.txt*****************************/


   /************************SD CARD_Create Num_sys.txt*****************************/

  uint8_t Num_SYS = Num_Sys_Create();
  while(Num_SYS != FR_OK)
  {
	  Num_SYS = Num_Sys_Create();  //Germany OR USA
   HAL_Delay(500);
  }

   /************************SD CARD_Create Num_sys.txt*****************************/

   /************************SD CARD_Create HTML*****************************/
  uint8_t HTML = HTML_File_Create();
  while (HTML !=FR_OK)
  {
   HTML = HTML_File_Create();
   HAL_Delay(500);
  }

   /************************SD CARD_Create HTML*****************************/

   uint8_t Sys_Type = 0;
   Sys_Type = Read_Number_Sys(Sys_Type);
   (Sys_Type == 1)? UART_Printf("Device Storage Type is GERMANY \n"):UART_Printf("Device Storage Type is USA \n");



   /************************Get Log file Number*****************************/

      Current_Log_File_No =  Read_Log_Number(Current_Log_File_No);
      UART_Printf("Current Log File Number is %d \n",Current_Log_File_No);

   /************************Get Log file Number*****************************/


   /************************SD CARD_Create DataLog*****************************/

   Create_DataLog_File();

   /************************SD CARD_Create DataLog*****************************/



   /************************System_Start*****************************/
   while(!Sys_Start)
   {
   System_Start();
   HAL_Delay(500);
   }
   /************************System_Start*****************************/



  /************************Start_Timer_Interrupt*****************************/

   HAL_TIM_Base_Start_IT(&htim3);
   HAL_TIM_Base_Start_IT(&htim4);

  /************************Start_Timer_Interrupt*****************************/

  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */

  while (1)
  {
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */


  }
  /* USER CODE END 3 */
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Configure the main internal regulator output voltage
  */
  __HAL_RCC_PWR_CLK_ENABLE();
  __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE1);

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
  RCC_OscInitStruct.HSEState = RCC_HSE_ON;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
  RCC_OscInitStruct.PLL.PLLM = 16;
  RCC_OscInitStruct.PLL.PLLN = 192;
  RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV2;
  RCC_OscInitStruct.PLL.PLLQ = 4;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }

  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV2;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_3) != HAL_OK)
  {
    Error_Handler();
  }
}



/* USER CODE BEGIN 4 */

/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  __disable_irq();
  while (1)
  {
  }
  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */
