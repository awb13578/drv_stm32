#ifndef DRV_GPIO_CORE_H_
#define DRV_GPIO_CORE_H_

#include "interface_gpio.h"

#ifdef ENABLE_GPIO

void drv_gpio_init(void);
void drv_gpio_set(uint8_t gpio_id);
void drv_gpio_clear(uint8_t gpio_id);
void drv_gpio_toggle(uint8_t gpio_id);
uint32_t drv_gpio_read(uint8_t gpio_id);

#endif /* ENABLE_GPIO */
#endif /* DRV_GPIO_CORE_H_ */
