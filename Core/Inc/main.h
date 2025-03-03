/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2022 STMicroelectronics.
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

void HAL_TIM_MspPostInit(TIM_HandleTypeDef *htim);

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define LED3_GREEN_Pin GPIO_PIN_1
#define LED3_GREEN_GPIO_Port GPIOA
#define LED1_RED_Pin GPIO_PIN_2
#define LED1_RED_GPIO_Port GPIOA
#define LED4_WHITE_Pin GPIO_PIN_3
#define LED4_WHITE_GPIO_Port GPIOA
#define LED2_YELLOW_Pin GPIO_PIN_4
#define LED2_YELLOW_GPIO_Port GPIOA
#define BRIDGE_1_EN_Pin GPIO_PIN_6
#define BRIDGE_1_EN_GPIO_Port GPIOA
#define BRIDGE_1A_Pin GPIO_PIN_2
#define BRIDGE_1A_GPIO_Port GPIOB
#define BRIDGE_2_EN_Pin GPIO_PIN_12
#define BRIDGE_2_EN_GPIO_Port GPIOB
#define BRIDGE_3A_Pin GPIO_PIN_13
#define BRIDGE_3A_GPIO_Port GPIOB

/* USER CODE BEGIN Private defines */
typedef struct {
uint32_t seq_no;
int32_t temp_oCx100;
} __attribute__((packed)) TEMPERATURE_OBJ_t;
/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
