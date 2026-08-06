#ifndef MCU_STM32G0XX_GPIO_H_
#define MCU_STM32G0XX_GPIO_H_

#include "interface_gpio.h"
#include "stm32g0xx_hal.h"

#ifdef ENABLE_GPIO

extern const gpio_method_t stm32_gpio_method;

#endif /* ENABLE_GPIO */
#endif /* MCU_GPIO_H_ */
