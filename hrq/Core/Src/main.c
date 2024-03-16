/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2023 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
	引脚介绍
			********************oled**********************
			PB12	SCL
			PB13	SDA

			*******************红外检测*******************
							PA0		北红外1
							PA1		北红外2
							PA2		北红外3
			PA5		西红外3					PA3		东红外2
							PA4		南红外1

			********************led灯*********************
							PB9		北红灯
							PB8		北绿灯
			PB3		西红灯					PB7		东红灯
			PA15	西绿灯					PB6		东绿灯
							PB5		南红灯
							PB4		南绿灯

  ******************************************************************************
  */
/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "tim.h"
#include "gpio.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "stdio.h"
#include "oled.h"
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

/* USER CODE BEGIN PV */
uint8_t OledString[100];

uint8_t HWA0 = 0;
uint8_t HWA1 = 0;
uint8_t HWA2 = 0;
uint8_t HWA3 = 0;
uint8_t HWA4 = 0;
uint8_t HWA5 = 0;

uint8_t HW_count1 = 0;//东西
uint8_t HW_count2 = 0;//南北

uint8_t HW_timer1 = 0;//东西红
uint8_t HW_timeg1 = 0;//东西绿
uint8_t HW_timer2 = 0;//南北红
uint8_t HW_timeg2 = 0;//南北绿

extern uint8_t time_red_WE;
extern uint8_t time_yellow_WE;
extern uint8_t time_green_WE;

extern uint8_t time_red_SN;
extern uint8_t time_yellow_SN;
extern uint8_t time_green_SN;

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
    uint8_t test;
    if(htim->Instance == TIM1)
    {
        if(++test == 5)
        {
            HAL_GPIO_TogglePin(PC13_GPIO_Port,PC13_Pin);//单独输出电平取反
            HAL_GPIO_TogglePin(LEDNorth1_GPIO_Port,LEDNorth1_Pin);
            test = 0;
        }
    }
}
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
    MX_TIM1_Init();
    /* USER CODE BEGIN 2 */
    OLED_Init();//初始化OLED
    OLED_Clear();//清屏
	sprintf((char *)OledString,"R  Y  G");//红黄绿
    OLED_ShowString(56,0,OledString,12); //oled显示
    sprintf((char *)OledString,"East :");//东
    OLED_ShowString(0,1,OledString,12); //oled显示
    sprintf((char *)OledString,"West :");//西
    OLED_ShowString(0,3,OledString,12); //oled显示
    sprintf((char *)OledString,"South:");//南
    OLED_ShowString(0,5,OledString,12); //oled显示
    sprintf((char *)OledString,"North:");//北
    OLED_ShowString(0,7,OledString,12); //oled显示

    /* USER CODE END 2 */
    HAL_TIM_Base_Start_IT(&htim1);
    /* Infinite loop */
    /* USER CODE BEGIN WHILE */
    while (1)
    {
        /* USER CODE END WHILE */
        //OLED显示
        sprintf((char *)OledString,"%02d",time_red_WE);		//东-红
        OLED_ShowString(50,1,OledString,12);
        sprintf((char *)OledString,"%02d",time_yellow_WE);	//东-黄
        OLED_ShowString(75,1,OledString,12);
        sprintf((char *)OledString,"%02d",time_green_WE);	//东-绿
        OLED_ShowString(100,1,OledString,12);
        sprintf((char *)OledString,"%02d",time_red_WE);		//西-红
        OLED_ShowString(50,3,OledString,12);
        sprintf((char *)OledString,"%02d",time_yellow_WE);	//西-黄
        OLED_ShowString(75,3,OledString,12);
        sprintf((char *)OledString,"%02d",time_green_WE);	//西-绿
        OLED_ShowString(100,3,OledString,12);

        sprintf((char *)OledString,"%02d",time_red_SN);		//南-红
        OLED_ShowString(50,5,OledString,12);
        sprintf((char *)OledString,"%02d",time_yellow_SN);	//南-黄
        OLED_ShowString(75,5,OledString,12);
        sprintf((char *)OledString,"%02d",time_green_SN);	//南-绿
        OLED_ShowString(100,5,OledString,12);
        sprintf((char *)OledString,"%02d",time_red_SN);		//北-红
        OLED_ShowString(50,7,OledString,12);
        sprintf((char *)OledString,"%02d",time_yellow_SN);	//北-黄
        OLED_ShowString(75,7,OledString,12);
        sprintf((char *)OledString,"%02d",time_green_SN);	//北-绿
        OLED_ShowString(100,7,OledString,12);
		
		//红外检测
		if(HAL_GPIO_ReadPin(GPIOA,HWNorth1_Pin) == 0)
			HWA0 = 1;
		else 
			HWA0 = 0;
		if(HAL_GPIO_ReadPin(GPIOA,HWNorth2_Pin) == 0)
			HWA1 = 1;
		else 
			HWA1 = 0;
		if(HAL_GPIO_ReadPin(GPIOA,HWNorth3_Pin) == 0)
			HWA2 = 1;
		else
			HWA2 = 0;
		if(HAL_GPIO_ReadPin(GPIOA,HWEast_Pin) == 0)
			HWA3 = 2;
		else 
			HWA3 = 0;
		if(HAL_GPIO_ReadPin(GPIOA,HWSouth_Pin) == 0)
			HWA4 = 1;
		else
			HWA4 = 0;
		if(HAL_GPIO_ReadPin(GPIOA,HWWest_Pin) == 0)
			HWA5 = 3;
		else
			HWA5 = 0;
		HW_count1 = HWA3 + HWA5;//东西权值
		HW_count2 = HWA0 + HWA1 + HWA2 + HWA4;//南北权值
		sprintf((char *)OledString,"%d %d",HW_count1,HW_count2);
        OLED_ShowString(0,0,OledString,12);//oled显示权值
		//看绘图1
		if(HW_count1 > HW_count2)
		{
			if(HW_count1 <= 2)
			{
				HW_timer1 = 10;
				HW_timeg1 = 12;
				HW_timer2 = 15;
				HW_timeg2 = 7;
			}
			else if(HW_count1 == 3)
			{
				HW_timer1 = 15;
				HW_timeg1 = 17;
				HW_timer2 = 20;
				HW_timeg2 = 12;
			}
			else if(HW_count1 >= 3)
			{
				HW_timer1 = 10;
				HW_timeg1 = 17;
				HW_timer2 = 20;
				HW_timeg2 = 7;
			}
		}
		else if(HW_count1 < HW_count2)
		{
			if(HW_count1 <= 2)
			{
				HW_timer2 = 10;
				HW_timeg2 = 12;
				HW_timer1 = 15;
				HW_timeg1 = 7;
			}
			else if(HW_count1 == 3)
			{
				HW_timer2 = 15;
				HW_timeg2 = 17;
				HW_timer1 = 20;
				HW_timeg1 = 12;
			}
			else if(HW_count1 >= 3)
			{
				HW_timer2 = 10;
				HW_timeg2 = 17;
				HW_timer1 = 20;
				HW_timeg1 = 7;
			}
		}
		else if(HW_count1 == HW_count2)
		{
			HW_timer1 = 15;
			HW_timeg1 = 12;
			HW_timer2 = 15;
			HW_timeg2 = 12;
		}
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
    RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
    RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSI_DIV2;
    RCC_OscInitStruct.PLL.PLLMUL = RCC_PLL_MUL9;
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
    RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;
    RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

    if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_1) != HAL_OK)
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
