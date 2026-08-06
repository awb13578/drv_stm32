#include "board_config.h"
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
