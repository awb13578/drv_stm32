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
