#ifndef DRV_GPIO_CORE_H_
#define DRV_GPIO_CORE_H_

#include "drv_config.h"
#include "interface_gpio.h"

void drv_gpio_init(void);

void drv_gpio_set_pin(uint8_t gpio_id);
void drv_gpio_clear_pin(uint8_t gpio_id);
void drv_gpio_toggle_pin(uint8_t gpio_id);
uint32_t drv_gpio_read_pin(uint8_t gpio_id);

#endif
