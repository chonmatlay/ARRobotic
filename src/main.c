/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2020 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
  *
  ******************************************************************************
  */
/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include "main.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */
enum {
    STATE0,
    STATE1,
    STATE2,
    STATE3,
    STATE4,
    STATE5,
    STATE6,
    STATE7
} state ;
/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/

/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */
void GPIO_PIN_SET_motor(int i){
    switch (i)
    {
    case STATE0:
        HAL_GPIO_WritePin(GPIOA,IN1,GPIO_PIN_SET);
        HAL_GPIO_WritePin(GPIOA,IN2,GPIO_PIN_RESET);
        HAL_GPIO_WritePin(GPIOA,IN3,GPIO_PIN_RESET);
        HAL_GPIO_WritePin(GPIOA,IN4,GPIO_PIN_RESET);
        break;
        case STATE1:
        HAL_GPIO_WritePin(GPIOA,IN1,GPIO_PIN_RESET);
        HAL_GPIO_WritePin(GPIOA,IN2,GPIO_PIN_SET);
        HAL_GPIO_WritePin(GPIOA,IN3,GPIO_PIN_RESET);
        HAL_GPIO_WritePin(GPIOA,IN4,GPIO_PIN_RESET);
        break;
            case STATE2:
        HAL_GPIO_WritePin(GPIOA,IN1,GPIO_PIN_RESET);
        HAL_GPIO_WritePin(GPIOA,IN2,GPIO_PIN_RESET);
        HAL_GPIO_WritePin(GPIOA,IN3,GPIO_PIN_SET);
        HAL_GPIO_WritePin(GPIOA,IN4,GPIO_PIN_RESET);
        break;
            case STATE3:
        HAL_GPIO_WritePin(GPIOA,IN1,GPIO_PIN_RESET);
        HAL_GPIO_WritePin(GPIOA,IN2,GPIO_PIN_RESET);
        HAL_GPIO_WritePin(GPIOA,IN3,GPIO_PIN_RESET);
        HAL_GPIO_WritePin(GPIOA,IN4,GPIO_PIN_SET);
        break;
            case STATE4:
        HAL_GPIO_WritePin(GPIOA,IN1,GPIO_PIN_SET);
        HAL_GPIO_WritePin(GPIOA,IN2,GPIO_PIN_SET);
        HAL_GPIO_WritePin(GPIOA,IN3,GPIO_PIN_RESET);
        HAL_GPIO_WritePin(GPIOA,IN4,GPIO_PIN_RESET);
        break;
            case STATE5:
        HAL_GPIO_WritePin(GPIOA,IN1,GPIO_PIN_RESET);
        HAL_GPIO_WritePin(GPIOA,IN2,GPIO_PIN_SET);
        HAL_GPIO_WritePin(GPIOA,IN3,GPIO_PIN_SET);
        HAL_GPIO_WritePin(GPIOA,IN4,GPIO_PIN_RESET);
        break;
            case STATE6:
            
        HAL_GPIO_WritePin(GPIOA,IN1,GPIO_PIN_RESET);
        HAL_GPIO_WritePin(GPIOA,IN2,GPIO_PIN_RESET);
        HAL_GPIO_WritePin(GPIOA,IN3,GPIO_PIN_SET);
        HAL_GPIO_WritePin(GPIOA,IN4,GPIO_PIN_SET);
        break;
            case STATE7:
        HAL_GPIO_WritePin(GPIOA,IN1,GPIO_PIN_SET);
        HAL_GPIO_WritePin(GPIOA,IN2,GPIO_PIN_RESET);
        HAL_GPIO_WritePin(GPIOA,IN3,GPIO_PIN_RESET);
        HAL_GPIO_WritePin(GPIOA,IN4,GPIO_PIN_SET);
        break;
    default:
        break;
    }
}
void full_stepping(){
    GPIO_PIN_SET_motor(4);
    HAL_Delay(5);
    GPIO_PIN_SET_motor(5);
    HAL_Delay(5);
    GPIO_PIN_SET_motor(6);
    HAL_Delay(5);
    GPIO_PIN_SET_motor(7);
    HAL_Delay(5);
}
void wave_driving(){
      GPIO_PIN_SET_motor(0);
    HAL_Delay(5);
    GPIO_PIN_SET_motor(1);
    HAL_Delay(5);
    GPIO_PIN_SET_motor(2);
    HAL_Delay(5);
    GPIO_PIN_SET_motor(3);
    HAL_Delay(5);
}
void half_step(){
    GPIO_PIN_SET_motor(0);
    HAL_Delay(5);
    GPIO_PIN_SET_motor(4);
    HAL_Delay(5);
    GPIO_PIN_SET_motor(1);
    HAL_Delay(5);
    GPIO_PIN_SET_motor(5);
    HAL_Delay(5);
     GPIO_PIN_SET_motor(2);
    HAL_Delay(5);
    GPIO_PIN_SET_motor(6);
    HAL_Delay(5);
    GPIO_PIN_SET_motor(3);
    HAL_Delay(5);
    GPIO_PIN_SET_motor(7);
    HAL_Delay(5);
}

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

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

  /* GPIO_PIN_RESET of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  /* USER CODE BEGIN 2 */

  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
    /* USER CODE END WHILE */
   half_step();
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

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_NONE;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }
  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_HSI;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_0) != HAL_OK)
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
  __HAL_RCC_GPIOA_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_0|GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_3, GPIO_PIN_RESET);

  /*Configure GPIO pins : PA0 PA1 PA2 PA3 */
  GPIO_InitStruct.Pin = GPIO_PIN_0|GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_3;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

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
     tex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/

