#include "board_config.h"
#include "main.h"

#include "mcu_stm32g0xx_gpio.h"

const drv_gpio_hw_map_t g_board_gpio_map[GPIO_ID_MAX] = {
		[LED1] = {
				.port   = GPIOA,
				.pin    = GPIO_PIN_12,
				.method = &stm32_gpio_method
		},
		[LED2] = {
				.port   = GPIOA,
				.pin    = GPIO_PIN_11,
				.method = &stm32_gpio_method
		},
		[LED3] = {
				.port   = GPIOC,
				.pin    = GPIO_PIN_6,
				.method = &stm32_gpio_method
		},
		[LED4] = {
				.port   = GPIOA,
				.pin    = GPIO_PIN_9,
				.method = &stm32_gpio_method
		},
		[MCU_PFC_RELAY] = {
				.port   = GPIOB,
				.pin    = GPIO_PIN_3,
				.method = &stm32_gpio_method
		},
		[MCU_LLC_RELAY] = {
				.port   = GPIOB,
				.pin    = GPIO_PIN_4,
				.method = &stm32_gpio_method
		},
};

#include "mcu_stm32g0xx_adc.h"

const drv_adc_hw_map_t g_board_adc_map[ADC_ID_MAX] = {
		[MCU_VAC_SENS] = {
				.hadc      = &hadc1,
				.channel   = ADC_CHANNEL_0,
				.dma_index = 0,
				.method    = &stm32_adc_method
		},
		[MCU_THERMAL_PFC_SENSE] = {
				.hadc      = &hadc1,
				.channel   = ADC_CHANNEL_1,
				.dma_index = 1,
				.method    = &stm32_adc_method
		},
		[MCU_VBAT_SENS] = {
				.hadc      = &hadc1,
				.channel   = ADC_CHANNEL_2,
				.dma_index = 2,
				.method    = &stm32_adc_method
		},
		[MCU_IBAT_SENS] = {
				.hadc      = &hadc1,
				.channel   = ADC_CHANNEL_3,
				.dma_index = 3,
				.method    = &stm32_adc_method
		},
		[MCU_VOUT_SENS] = {
				.hadc      = &hadc1,
				.channel   = ADC_CHANNEL_4,
				.dma_index = 4,
				.method    = &stm32_adc_method
		},
		[MCU_THERMAL_SR_SENSE] = {
				.hadc      = &hadc1,
				.channel   = ADC_CHANNEL_5,
				.dma_index = 5,
				.method    = &stm32_adc_method
		},
		[MCU_IPRI_SENS] = {
				.hadc      = &hadc1,
				.channel   = ADC_CHANNEL_8,
				.dma_index = 6,
				.method    = &stm32_adc_method
		},
};

#include "mcu_stm32g0xx_timer.h"

const drv_timer_hw_map_t g_board_timer_map[TIMER_ID_MAX] = {
		[TIMER_2] = {
				.htim	= &htim2,
				.method = &stm32_timer_method
		},
};
