#ifndef MCU_GPIO_H_
#define MCU_GPIO_H_

#include "interface_gpio.h"
#include "stm32g0xx_hal.h"

void mcu_gpio_set(gpio_ctx_t *ctx);
void mcu_gpio_clear(gpio_ctx_t *ctx);
void mcu_gpio_toggle(gpio_ctx_t *ctx);
uint32_t mcu_gpio_read(gpio_ctx_t *ctx);
void mcu_gpio_init(gpio_ctx_t *ctx);

#endif
