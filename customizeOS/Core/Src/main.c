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
#include "cmsis_os.h"
#include "stdio.h" //print
#include "task.h" //xTaskCreate, xTaskgetTickCount

#define TICKS_PER_SECOND configTICK_RATE_HZ //to convert tick in time

/* Private variables ---------------------------------------------------------*/
UART_HandleTypeDef huart2;

unsigned int seconds, milliseconds;

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_USART2_UART_Init(void);

void StartTask1(void const * argument);
void StartTask2(void const * argument);
void StartTask3(void const * argument);

void convertTicksToTime(TickType_t ticks, unsigned int *seconds, unsigned int *milliseconds);

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */
int _write(int file, char *ptr, int len){
	int i = 0;
	for(i=0;i<len;i++){
		ITM_SendChar((*ptr++));
	}
	return len;
}
/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{
  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* Configure the system clock */
  SystemClock_Config();

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_USART2_UART_Init();

  /* definition and creation of Tasks */
  xTaskCreate(StartTask1, "Task1", configMINIMAL_STACK_SIZE, NULL, 3, NULL);
  xTaskCreate(StartTask2, "Task2", configMINIMAL_STACK_SIZE, NULL, 2, NULL);
  xTaskCreate(StartTask3, "Task3", configMINIMAL_STACK_SIZE, NULL, 1, NULL);

  /* Start scheduler */
  printf(" Start scheduling... \n");
  vTaskStartScheduler();

  /* We should never get here as control is now taken by the scheduler */
  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
    osErrorOS;
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
  __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE3);

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSI;
  RCC_OscInitStruct.PLL.PLLM = 16;
  RCC_OscInitStruct.PLL.PLLN = 336;
  RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV4;
  RCC_OscInitStruct.PLL.PLLQ = 2;
  RCC_OscInitStruct.PLL.PLLR = 2;
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

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_2) != HAL_OK)
  {
    Error_Handler();
  }
}

/**
  * @brief USART2 Initialization Function
  * @param None
  * @retval None
  */
static void MX_USART2_UART_Init(void)
{
  huart2.Instance = USART2;
  huart2.Init.BaudRate = 115200;
  huart2.Init.WordLength = UART_WORDLENGTH_8B;
  huart2.Init.StopBits = UART_STOPBITS_1;
  huart2.Init.Parity = UART_PARITY_NONE;
  huart2.Init.Mode = UART_MODE_TX_RX;
  huart2.Init.HwFlowCtl = UART_HWCONTROL_NONE;
  huart2.Init.OverSampling = UART_OVERSAMPLING_16;
  if (HAL_UART_Init(&huart2) != HAL_OK)
  {
    Error_Handler();
  }
}

/**
  * @brief GPIO Initialization Function
  * @param None
  * @retval None
  */
static void MX_GPIO_Init(void)
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOC_CLK_ENABLE();
  __HAL_RCC_GPIOH_CLK_ENABLE();
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(LD2_GPIO_Port, LD2_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin : B1_Pin */
  GPIO_InitStruct.Pin = B1_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_IT_FALLING;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(B1_GPIO_Port, &GPIO_InitStruct);

  /*Configure GPIO pin : LD2_Pin */
  GPIO_InitStruct.Pin = LD2_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(LD2_GPIO_Port, &GPIO_InitStruct);
}


/* function to convert tick in time */
void convertTicksToTime(TickType_t ticks, unsigned int *seconds, unsigned int *milliseconds) {
    //total time in milliseconds
    uint32_t totalMilliseconds = (ticks * 1000) / TICKS_PER_SECOND;
    //seconds and milliseconds
    *seconds = totalMilliseconds / 1000;
    *milliseconds = totalMilliseconds % 1000;
}


/* USER CODE BEGIN Header_StartDefaultTask */
/**
  * @brief  Function implementing the defaultTask thread.
  * @param  argument: Not used
  * @retval None
  */
/* USER CODE END Header_StartTask1 */
void StartTask1(void const * argument)
{
	TickType_t xLastWakeTime;
	TickType_t xLastRestTime;
	for(;;)
	{
		/*Initialize xLastWakeTime with the current ticks number */
		xLastWakeTime = xTaskGetTickCount();
		convertTicksToTime(xLastWakeTime, &seconds, &milliseconds);

		printf(" Start Task 1... ");
		printf(" %u seconds, %u milliseconds\n", seconds, milliseconds);

		const TickType_t xFrequency = pdMS_TO_TICKS(2000); //2000 ms

		TickType_t time = 0;
		while (time != xLastWakeTime+xFrequency)
		{
			/* code to run for 2 seconds */
			time = xTaskGetTickCount();
		}
		/*Initialize xLastWakeTime with the current ticks number */
		xLastRestTime = time;
		convertTicksToTime(xLastRestTime, &seconds, &milliseconds);
		printf(" End Task 1... ");
		printf(" %u seconds, %u milliseconds\n", seconds, milliseconds);
		vTaskDelay(pdMS_TO_TICKS(4000)); //4000 ms
	}
}

/* USER CODE END Header_StartTask2 */
void StartTask2(void const * argument)
{
	TickType_t xLastWakeTime;
	TickType_t xLastRestTime;
	for(;;)
	{
		xLastWakeTime = xTaskGetTickCount();
		convertTicksToTime(xLastWakeTime, &seconds, &milliseconds);

		printf(" Start Task 2... ");
		printf(" %u seconds, %u milliseconds\n", seconds, milliseconds);

		const TickType_t xFrequency = pdMS_TO_TICKS(1000); // 1000 ms

		TickType_t time = 0;
		while (time != xLastWakeTime+xFrequency)
		{
			time = xTaskGetTickCount();
		}
		xLastRestTime = time;
		convertTicksToTime(xLastRestTime, &seconds, &milliseconds);
		printf(" End Task 2... ");
		printf(" %u seconds, %u milliseconds\n", seconds, milliseconds);
		vTaskDelay(pdMS_TO_TICKS(2000)); //2000 ms
	}
}

/* USER CODE END Header_StartTask3 */
void StartTask3(void const * argument)
{
	TickType_t xLastWakeTime;
	TickType_t xLastRestTime;
	for(;;)
	{
		xLastWakeTime = xTaskGetTickCount();
		convertTicksToTime(xLastWakeTime, &seconds, &milliseconds);
		printf(" Start Task 3... ");
		printf(" %u seconds, %u milliseconds\n", seconds, milliseconds);
		const TickType_t xFrequency = pdMS_TO_TICKS(500); // 500 ms

		TickType_t time = 0;
		while (time != xLastWakeTime+xFrequency)
		{
			time = xTaskGetTickCount();
		}
		xLastRestTime = time;
		convertTicksToTime(xLastRestTime, &seconds, &milliseconds);
		printf(" End Task 3... ");
		printf(" %u seconds, %u milliseconds\n", seconds, milliseconds);
		vTaskDelay(pdMS_TO_TICKS(500)); //500 ms
	}
}

/**
  * @brief  Period elapsed callback in non blocking mode
  * @note   This function is called  when TIM1 interrupt took place, inside
  * HAL_TIM_IRQHandler(). It makes a direct call to HAL_IncTick() to increment
  * a global variable "uwTick" used as application time base.
  * @param  htim : TIM handle
  * @retval None
  */
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
  /* USER CODE BEGIN Callback 0 */

  /* USER CODE END Callback 0 */
  if (htim->Instance == TIM1) {
    HAL_IncTick();
  }
  /* USER CODE BEGIN Callback 1 */

  /* USER CODE END Callback 1 */
}

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
	  osErrorOS;
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
