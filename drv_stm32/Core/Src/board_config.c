#include "board_config.h"
#include "stm32g0xx_hal.h"

extern gpio_method_t stm32_gpio_method;

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

extern adc_method_t stm32_adc_method;
extern ADC_HandleTypeDef hadc1;

const drv_adc_hw_map_t g_board_adc_map[ADC_ID_MAX] = {
    [MCU_VAC_SENS] = {
        .hadc    = &hadc1,
        .port    = GPIOA,
        .pin     = GPIO_PIN_0,
        .channel = ADC_CHANNEL_0,
        .method  = &stm32_adc_method
    },
    [MCU_THERMAL_PFC_SENSE] = {
        .hadc    = &hadc1,
        .port    = GPIOA,
        .pin     = GPIO_PIN_1,
        .channel = ADC_CHANNEL_1,
        .method  = &stm32_adc_method
    },
    [MCU_VBAT_SENS] = {
        .hadc    = &hadc1,
        .port    = GPIOA,
        .pin     = GPIO_PIN_2,
        .channel = ADC_CHANNEL_2,
        .method  = &stm32_adc_method
    },
    [MCU_IBAT_SENS] = {
        .hadc    = &hadc1,
        .port    = GPIOA,
        .pin     = GPIO_PIN_3,
        .channel = ADC_CHANNEL_3,
        .method  = &stm32_adc_method
    },
    [MCU_VOUT_SENS] = {
        .hadc    = &hadc1,
        .port    = GPIOA,
        .pin     = GPIO_PIN_4,
        .channel = ADC_CHANNEL_4,
        .method  = &stm32_adc_method
    },
    [MCU_THERMAL_SR_SENSE] = {
        .hadc    = &hadc1,
        .port    = GPIOA,
        .pin     = GPIO_PIN_5,
        .channel = ADC_CHANNEL_5,
        .method  = &stm32_adc_method
    },
    [MCU_IPRI_SENS] = {
        .hadc    = &hadc1,
        .port    = GPIOB,
        .pin     = GPIO_PIN_0,
        .channel = ADC_CHANNEL_8,
        .method  = &stm32_adc_method
    },
};
