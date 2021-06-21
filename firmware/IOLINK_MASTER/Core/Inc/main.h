/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2021 STMicroelectronics.
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

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32f0xx_hal.h"

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
#define T3_UC_SIO_Pin GPIO_PIN_15
#define T3_UC_SIO_GPIO_Port GPIOC
#define UC_T3_ENCQ_Pin GPIO_PIN_0
#define UC_T3_ENCQ_GPIO_Port GPIOC
#define UC_T3_RST_Pin GPIO_PIN_1
#define UC_T3_RST_GPIO_Port GPIOC
#define UC_T3_ENL_Pin GPIO_PIN_2
#define UC_T3_ENL_GPIO_Port GPIOC
#define T3_UC_IRQ_Pin GPIO_PIN_3
#define T3_UC_IRQ_GPIO_Port GPIOC
#define CS_ETH_Pin GPIO_PIN_4
#define CS_ETH_GPIO_Port GPIOA
#define UC_T2_RST_Pin GPIO_PIN_0
#define UC_T2_RST_GPIO_Port GPIOB
#define UC_T2_ENCQ_Pin GPIO_PIN_1
#define UC_T2_ENCQ_GPIO_Port GPIOB
#define UC_T2_ENL_Pin GPIO_PIN_2
#define UC_T2_ENL_GPIO_Port GPIOB
#define T2_UC_IRQ_Pin GPIO_PIN_10
#define T2_UC_IRQ_GPIO_Port GPIOB
#define T2_UC_SIO_Pin GPIO_PIN_11
#define T2_UC_SIO_GPIO_Port GPIOB
#define UC_T1_RST_Pin GPIO_PIN_12
#define UC_T1_RST_GPIO_Port GPIOB
#define UC_T1_ENCQ_Pin GPIO_PIN_13
#define UC_T1_ENCQ_GPIO_Port GPIOB
#define UC_T1_ENL_Pin GPIO_PIN_14
#define UC_T1_ENL_GPIO_Port GPIOB
#define T1_UC_IRQ_Pin GPIO_PIN_15
#define T1_UC_IRQ_GPIO_Port GPIOB
#define T0_UC_SIO_Pin GPIO_PIN_6
#define T0_UC_SIO_GPIO_Port GPIOC
#define T0_UC_IRQ_Pin GPIO_PIN_7
#define T0_UC_IRQ_GPIO_Port GPIOC
#define UC_T0_ENCQ_Pin GPIO_PIN_8
#define UC_T0_ENCQ_GPIO_Port GPIOC
#define UC_T0_ENL_Pin GPIO_PIN_9
#define UC_T0_ENL_GPIO_Port GPIOC
#define UC_T0_RST_Pin GPIO_PIN_8
#define UC_T0_RST_GPIO_Port GPIOA
#define T1_UC_SIO_Pin GPIO_PIN_15
#define T1_UC_SIO_GPIO_Port GPIOA
#define RST_ETH_Pin GPIO_PIN_10
#define RST_ETH_GPIO_Port GPIOC
#define INT_ETH_Pin GPIO_PIN_11
#define INT_ETH_GPIO_Port GPIOC
#define L_ON_Pin GPIO_PIN_3
#define L_ON_GPIO_Port GPIOB
#define USB_ENABLE_Pin GPIO_PIN_9
#define USB_ENABLE_GPIO_Port GPIOB
/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
