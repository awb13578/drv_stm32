#include "board_config.h"
#include "stm32g0xx_hal.h"

extern gpio_method_t stm32_gpio_method;

const drv_gpio_hw_map_t g_board_gpio_map[GPIO_ID_MAX] = {
    [GPIO_ID_LED1] = {
        .port   = GPIOA,
        .pin    = GPIO_PIN_12,
        .method = &stm32_gpio_method
    },
    [GPIO_ID_LED2] = {
        .port   = GPIOA,
        .pin    = GPIO_PIN_11,
        .method = &stm32_gpio_method
    },
    [GPIO_ID_LED3] = {
        .port   = GPIOC,
        .pin    = GPIO_PIN_6,
        .method = &stm32_gpio_method
    },
    [GPIO_ID_LED4] = {
        .port   = GPIOA,
        .pin    = GPIO_PIN_9,
        .method = &stm32_gpio_method
    },
    [GPIO_ID_PFC_RELAY] = {
        .port   = GPIOB,
        .pin    = GPIO_PIN_3,
        .method = &stm32_gpio_method
    },
    [GPIO_ID_LLC_RELAY] = {
        .port   = GPIOB,
        .pin    = GPIO_PIN_4,
        .method = &stm32_gpio_method
    },
};

//const drv_adc_hw_map_t g_board_adc_map[ADC_ID_MAX] = {
//	[ADC_ID_VAC_SENS] = {
//		.port   = GPIOA,
//		.pin    = GPIO_PIN_0,
//		.method = &stm32_adc_method
//	},
//	[ADC_ID_THERMAL_PFC_SENSE] = {
//		.port   = GPIOA,
//		.pin    = GPIO_PIN_1,
//		.method = &stm32_adc_method
//	},
//	[ADC_ID_VBAT_SENS] = {
//		.port   = GPIOA,
//		.pin    = GPIO_PIN_2,
//		.method = &stm32_adc_method
//	},
//	[ADC_ID_IBAT_SENS] = {
//		.port   = GPIOA,
//		.pin    = GPIO_PIN_3,
//		.method = &stm32_adc_method
//	},
//	[ADC_ID_VOUT_SENS] = {
//		.port   = GPIOA,
//		.pin    = GPIO_PIN_4,
//		.method = &stm32_adc_method
//	},
//	[ADC_ID_THERMAL_SR_SENSE] = {
//		.port   = GPIOA,
//		.pin    = GPIO_PIN_5,
//		.method = &stm32_adc_method
//	},
//	[ADC_ID_IPRI_SENS] = {
//		.port   = GPIOB,
//		.pin    = GPIO_PIN_0,
//		.method = &stm32_adc_method
//	},
//	[ADC_ID_PFC_VCOMP] = {
//		.port   = GPIOA,
//		.pin    = GPIO_PIN_15,
//		.method = &stm32_adc_method
//	},
//};
