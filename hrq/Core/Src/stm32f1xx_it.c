/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file    stm32f1xx_it.c
  * @brief   Interrupt Service Routines.
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
  ******************************************************************************
  */
/* USER CODE END Header */

/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "stm32f1xx_it.h"
/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN TD */

/* USER CODE END TD */

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
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */
#include "oled.h"
/* USER CODE END 0 */

/* External variables --------------------------------------------------------*/
extern TIM_HandleTypeDef htim1;
/* USER CODE BEGIN EV */
uint8_t seconds = 0;
uint8_t WE_flag = 0;
uint8_t SN_flag = 0;
uint8_t WE_flag1 = 0;
uint8_t SN_flag1 = 0;

uint8_t time_red_WE = 15;
uint8_t time_yellow_WE = 3;
uint8_t time_green_WE = 12;

uint8_t time_red_SN = 15;
uint8_t time_yellow_SN = 3;
uint8_t time_green_SN = 12;

extern uint8_t HW_timer1;
extern uint8_t HW_timeg1;
extern uint8_t HW_timer2;
extern uint8_t HW_timeg2;

/* USER CODE END EV */

/******************************************************************************/
/*           Cortex-M3 Processor Interruption and Exception Handlers          */
/******************************************************************************/
/**
  * @brief This function handles Non maskable interrupt.
  */
void NMI_Handler(void)
{
    /* USER CODE BEGIN NonMaskableInt_IRQn 0 */

    /* USER CODE END NonMaskableInt_IRQn 0 */
    /* USER CODE BEGIN NonMaskableInt_IRQn 1 */
    while (1)
    {
    }
    /* USER CODE END NonMaskableInt_IRQn 1 */
}

/**
  * @brief This function handles Hard fault interrupt.
  */
void HardFault_Handler(void)
{
    /* USER CODE BEGIN HardFault_IRQn 0 */

    /* USER CODE END HardFault_IRQn 0 */
    while (1)
    {
        /* USER CODE BEGIN W1_HardFault_IRQn 0 */
        /* USER CODE END W1_HardFault_IRQn 0 */
    }
}

/**
  * @brief This function handles Memory management fault.
  */
void MemManage_Handler(void)
{
    /* USER CODE BEGIN MemoryManagement_IRQn 0 */

    /* USER CODE END MemoryManagement_IRQn 0 */
    while (1)
    {
        /* USER CODE BEGIN W1_MemoryManagement_IRQn 0 */
        /* USER CODE END W1_MemoryManagement_IRQn 0 */
    }
}

/**
  * @brief This function handles Prefetch fault, memory access fault.
  */
void BusFault_Handler(void)
{
    /* USER CODE BEGIN BusFault_IRQn 0 */

    /* USER CODE END BusFault_IRQn 0 */
    while (1)
    {
        /* USER CODE BEGIN W1_BusFault_IRQn 0 */
        /* USER CODE END W1_BusFault_IRQn 0 */
    }
}

/**
  * @brief This function handles Undefined instruction or illegal state.
  */
void UsageFault_Handler(void)
{
    /* USER CODE BEGIN UsageFault_IRQn 0 */

    /* USER CODE END UsageFault_IRQn 0 */
    while (1)
    {
        /* USER CODE BEGIN W1_UsageFault_IRQn 0 */
        /* USER CODE END W1_UsageFault_IRQn 0 */
    }
}

/**
  * @brief This function handles System service call via SWI instruction.
  */
void SVC_Handler(void)
{
    /* USER CODE BEGIN SVCall_IRQn 0 */

    /* USER CODE END SVCall_IRQn 0 */
    /* USER CODE BEGIN SVCall_IRQn 1 */

    /* USER CODE END SVCall_IRQn 1 */
}

/**
  * @brief This function handles Debug monitor.
  */
void DebugMon_Handler(void)
{
    /* USER CODE BEGIN DebugMonitor_IRQn 0 */

    /* USER CODE END DebugMonitor_IRQn 0 */
    /* USER CODE BEGIN DebugMonitor_IRQn 1 */

    /* USER CODE END DebugMonitor_IRQn 1 */
}

/**
  * @brief This function handles Pendable request for system service.
  */
void PendSV_Handler(void)
{
    /* USER CODE BEGIN PendSV_IRQn 0 */

    /* USER CODE END PendSV_IRQn 0 */
    /* USER CODE BEGIN PendSV_IRQn 1 */

    /* USER CODE END PendSV_IRQn 1 */
}

/**
  * @brief This function handles System tick timer.
  */
void SysTick_Handler(void)
{
    /* USER CODE BEGIN SysTick_IRQn 0 */

    /* USER CODE END SysTick_IRQn 0 */
    HAL_IncTick();
    /* USER CODE BEGIN SysTick_IRQn 1 */

    /* USER CODE END SysTick_IRQn 1 */
}

/******************************************************************************/
/* STM32F1xx Peripheral Interrupt Handlers                                    */
/* Add here the Interrupt Handlers for the used peripherals.                  */
/* For the available peripheral interrupt handler names,                      */
/* please refer to the startup file (startup_stm32f1xx.s).                    */
/******************************************************************************/

/**
  * @brief This function handles TIM1 update interrupt.
  */
void TIM1_UP_IRQHandler(void)
{
    /* USER CODE BEGIN TIM1_UP_IRQn 0 */

    /* USER CODE END TIM1_UP_IRQn 0 */
    HAL_TIM_IRQHandler(&htim1);
    /* USER CODE BEGIN TIM1_UP_IRQn 1 */
    if(++seconds == 5)//1s¶¨Ê±Æ÷
    {
        switch(WE_flag)//¶«Î÷
        {
        case 0://ÂÌ
            time_green_WE -= 1;//ÂÌµÆµ¹¼ÆÊ±
            if(time_green_WE == 0)
			{
                WE_flag = 1;
				time_green_WE = HW_timeg1;//ÂÌµÆÖØÖÃ
			}
            HAL_GPIO_WritePin(GPIOB,LEDNorth1_Pin,GPIO_PIN_SET);//ÁÁºìµÆ
            HAL_GPIO_WritePin(GPIOB,LEDNorth2_Pin,GPIO_PIN_RESET);//ÃðÂÌµÆ
            HAL_GPIO_WritePin(GPIOB,LEDSouth2_Pin,GPIO_PIN_SET);//ÁÁÂÌµÆ
            HAL_GPIO_WritePin(GPIOB,LEDSouth1_Pin,GPIO_PIN_RESET);//ÃðºìµÆ
            break;
        case 1://»Æ
            time_yellow_WE -= 1;//»ÆµÆµ¹¼ÆÊ±
            if(time_yellow_WE == 0)
			{
				WE_flag = 2;
				time_yellow_WE = 3;//»ÆµÆÖØÖÃ
			}
            HAL_GPIO_WritePin(GPIOB,LEDNorth1_Pin,GPIO_PIN_RESET);//ÃðºìµÆ
            HAL_GPIO_WritePin(GPIOB,LEDNorth2_Pin,GPIO_PIN_RESET);//ÃðÂÌµÆ
            HAL_GPIO_WritePin(GPIOB,LEDSouth2_Pin,GPIO_PIN_RESET);//ÃðÂÌµÆ
            HAL_GPIO_WritePin(GPIOB,LEDSouth1_Pin,GPIO_PIN_RESET);//ÃðºìµÆ
            break;
        case 2://ºì
            time_red_WE -= 1;//ºìµÆµ¹¼ÆÊ±
            if(time_red_WE == 0)
			{
                WE_flag = 0;
				time_red_WE = HW_timer1;//ºìµÆÖØÖÃ
			}
            HAL_GPIO_WritePin(GPIOB,LEDNorth1_Pin,GPIO_PIN_RESET);//ÃðºìµÆ
            HAL_GPIO_WritePin(GPIOB,LEDNorth2_Pin,GPIO_PIN_SET);//ÁÁÂÌµÆ
            HAL_GPIO_WritePin(GPIOB,LEDSouth2_Pin,GPIO_PIN_RESET);//ÃðÂÌµÆ
            HAL_GPIO_WritePin(GPIOB,LEDSouth1_Pin,GPIO_PIN_SET);//ÁÁºìµÆ
            break;
        }
        switch(SN_flag)//ÄÏ±±
        {
        case 0://ºì
            time_red_SN -= 1;//ºìµÆµ¹¼ÆÊ±
            if(time_red_SN == 0)
			{
                SN_flag = 2;
				time_red_SN = HW_timer2;//ºìµÆÖØÖÃ
			}
			HAL_GPIO_WritePin(GPIOB,LEDWest1_Pin,GPIO_PIN_RESET);//ÃðºìµÆ
            HAL_GPIO_WritePin(GPIOA,LEDWest2_Pin,GPIO_PIN_SET);//ÁÁÂÌµÆ
            HAL_GPIO_WritePin(GPIOB,LEDEast1_Pin,GPIO_PIN_RESET);//ÃðÂÌµÆ
            HAL_GPIO_WritePin(GPIOB,LEDEast2_Pin,GPIO_PIN_SET);//ÁÁºìµÆ
            break;
        case 1://»Æ
            time_yellow_SN -= 1;//»ÆµÆµ¹¼ÆÊ±
            if(time_yellow_SN == 0)
			{
				SN_flag = 0;
				time_yellow_SN = 3;//»ÆµÆÖØÖÃ
			}
            HAL_GPIO_WritePin(GPIOB,LEDWest1_Pin,GPIO_PIN_RESET);//ÃðºìµÆ
            HAL_GPIO_WritePin(GPIOA,LEDWest2_Pin,GPIO_PIN_RESET);//ÃðÂÌµÆ
            HAL_GPIO_WritePin(GPIOB,LEDEast1_Pin,GPIO_PIN_RESET);//ÃðÂÌµÆ
            HAL_GPIO_WritePin(GPIOB,LEDEast2_Pin,GPIO_PIN_RESET);//ÃðºìµÆ
            break;
        case 2://ÂÌ
            time_green_SN -= 1;//ÂÌµÆµ¹¼ÆÊ±
            if(time_green_SN == 0)
			{
                SN_flag = 1;
				time_green_SN = HW_timeg2;//ÂÌµÆÖØÖÃ
			}
            HAL_GPIO_WritePin(GPIOB,LEDWest1_Pin,GPIO_PIN_SET);//ÁÁºìµÆ
            HAL_GPIO_WritePin(GPIOA,LEDWest2_Pin,GPIO_PIN_RESET);//ÃðÂÌµÆ
            HAL_GPIO_WritePin(GPIOB,LEDEast1_Pin,GPIO_PIN_SET);//ÁÁÂÌµÆ
            HAL_GPIO_WritePin(GPIOB,LEDEast2_Pin,GPIO_PIN_RESET);//ÃðºìµÆ
            break;
        }
        seconds = 0;
    }
    /* USER CODE END TIM1_UP_IRQn 1 */
}

/* USER CODE BEGIN 1 */

/* USER CODE END 1 */
