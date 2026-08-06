/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2026 STMicroelectronics.
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
#include "stm32g0xx_hal.h"

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
#define mcu_Vac_sens_Pin GPIO_PIN_0
#define mcu_Vac_sens_GPIO_Port GPIOA
#define mcu_Thermal_PFC_sense_Pin GPIO_PIN_1
#define mcu_Thermal_PFC_sense_GPIO_Port GPIOA
#define mcuVbat_sens_Pin GPIO_PIN_2
#define mcuVbat_sens_GPIO_Port GPIOA
#define mcuIbat_sens_Pin GPIO_PIN_3
#define mcuIbat_sens_GPIO_Port GPIOA
#define mcuVout_sens_Pin GPIO_PIN_4
#define mcuVout_sens_GPIO_Port GPIOA
#define mcu_Thermal_SR_Sense_Pin GPIO_PIN_5
#define mcu_Thermal_SR_Sense_GPIO_Port GPIOA
#define mcuIpri_sens_Pin GPIO_PIN_0
#define mcuIpri_sens_GPIO_Port GPIOB
#define LED4_Pin GPIO_PIN_9
#define LED4_GPIO_Port GPIOA
#define LED3_Pin GPIO_PIN_6
#define LED3_GPIO_Port GPIOC
#define LED2_Pin GPIO_PIN_11
#define LED2_GPIO_Port GPIOA
#define LED1_Pin GPIO_PIN_12
#define LED1_GPIO_Port GPIOA
#define SWD_LLC_Pin GPIO_PIN_13
#define SWD_LLC_GPIO_Port GPIOA
#define SWCLK_LLC_Pin GPIO_PIN_14
#define SWCLK_LLC_GPIO_Port GPIOA

/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
