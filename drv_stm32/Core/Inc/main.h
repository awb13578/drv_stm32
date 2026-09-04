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
#define UART_RX_LLC_Pin GPIO_PIN_9
#define UART_RX_LLC_GPIO_Port GPIOB
#define MCU_VAC_SENS_Pin GPIO_PIN_0
#define MCU_VAC_SENS_GPIO_Port GPIOA
#define MCU_THERMAL_PFC_SENSE_Pin GPIO_PIN_1
#define MCU_THERMAL_PFC_SENSE_GPIO_Port GPIOA
#define MCU_VBAT_SENS_Pin GPIO_PIN_2
#define MCU_VBAT_SENS_GPIO_Port GPIOA
#define MCU_IBAT_SENS_Pin GPIO_PIN_3
#define MCU_IBAT_SENS_GPIO_Port GPIOA
#define MCU_VOUT_SENS_Pin GPIO_PIN_4
#define MCU_VOUT_SENS_GPIO_Port GPIOA
#define MCU_THERMAL_SR_SENSE_Pin GPIO_PIN_5
#define MCU_THERMAL_SR_SENSE_GPIO_Port GPIOA
#define MCU_IPRI_SENS_Pin GPIO_PIN_0
#define MCU_IPRI_SENS_GPIO_Port GPIOB
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
#define CANA_RX_Pin GPIO_PIN_5
#define CANA_RX_GPIO_Port GPIOB
#define CANA_TX_Pin GPIO_PIN_6
#define CANA_TX_GPIO_Port GPIOB
#define UART_TX_LLC_Pin GPIO_PIN_8
#define UART_TX_LLC_GPIO_Port GPIOB

/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
