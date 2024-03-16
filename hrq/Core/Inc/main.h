/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
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

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32f1xx_hal.h"

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
#define PC13_Pin GPIO_PIN_13
#define PC13_GPIO_Port GPIOC
#define HWNorth1_Pin GPIO_PIN_0
#define HWNorth1_GPIO_Port GPIOA
#define HWNorth2_Pin GPIO_PIN_1
#define HWNorth2_GPIO_Port GPIOA
#define HWNorth3_Pin GPIO_PIN_2
#define HWNorth3_GPIO_Port GPIOA
#define HWEast_Pin GPIO_PIN_3
#define HWEast_GPIO_Port GPIOA
#define HWSouth_Pin GPIO_PIN_4
#define HWSouth_GPIO_Port GPIOA
#define HWWest_Pin GPIO_PIN_5
#define HWWest_GPIO_Port GPIOA
#define OLED_SCL_Pin GPIO_PIN_12
#define OLED_SCL_GPIO_Port GPIOB
#define OLED_SDA_Pin GPIO_PIN_13
#define OLED_SDA_GPIO_Port GPIOB
#define LEDWest2_Pin GPIO_PIN_15
#define LEDWest2_GPIO_Port GPIOA
#define LEDWest1_Pin GPIO_PIN_3
#define LEDWest1_GPIO_Port GPIOB
#define LEDSouth2_Pin GPIO_PIN_4
#define LEDSouth2_GPIO_Port GPIOB
#define LEDSouth1_Pin GPIO_PIN_5
#define LEDSouth1_GPIO_Port GPIOB
#define LEDEast2_Pin GPIO_PIN_6
#define LEDEast2_GPIO_Port GPIOB
#define LEDEast1_Pin GPIO_PIN_7
#define LEDEast1_GPIO_Port GPIOB
#define LEDNorth2_Pin GPIO_PIN_8
#define LEDNorth2_GPIO_Port GPIOB
#define LEDNorth1_Pin GPIO_PIN_9
#define LEDNorth1_GPIO_Port GPIOB

/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
