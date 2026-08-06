#ifndef INTERFACE_GPIO_H_
#define INTERFACE_GPIO_H_

#include "_config_lib.h"
#include "drv_config.h"
#include <stdint.h>
#include <stddef.h>

#define GPIO_STATE_ERROR 2

struct gpio_ctx;

typedef struct {
	void *port;
	uint16_t pin;
} gpio_hw_cfg_t ;

typedef struct gpio_ctx {
	uint8_t id;
	gpio_hw_cfg_t hw_cfg;
} gpio_ctx_t ;

typedef struct {
	void (*init) (gpio_ctx_t *ctx);
	void (*set) (gpio_ctx_t *ctx);
	void (*clear) (gpio_ctx_t *ctx);
	void (*toggle) (gpio_ctx_t *ctx);
	uint32_t (*read) (gpio_ctx_t *ctx);
} gpio_method_t ;

#endif /* INTERFACE_GPIO_H_ */
