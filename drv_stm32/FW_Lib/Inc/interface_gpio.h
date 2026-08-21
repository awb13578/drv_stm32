#ifndef INTERFACE_GPIO_H_
#define INTERFACE_GPIO_H_

#include "_config_lib.h"
#include "drv_config.h"
#include <stdint.h>
#include <stddef.h>

#define GPIO_STATE_ERROR 2

typedef struct {
	void *port;
	uint16_t pin;
} gpio_hw_cfg_t ;

typedef struct {
	uint8_t state;
} gpio_sw_data_t;

typedef struct {
	gpio_id_t id;
	gpio_hw_cfg_t hw_cfg;
	gpio_sw_data_t sw_data;
} gpio_ctx_t ;

typedef struct {
	void (*init) (gpio_ctx_t *ctx);
	void (*set) (gpio_ctx_t *ctx);
	void (*clear) (gpio_ctx_t *ctx);
	void (*toggle) (gpio_ctx_t *ctx);
	uint32_t (*read) (gpio_ctx_t *ctx);
} gpio_method_t ;

typedef struct {
	gpio_ctx_t ctx;
	const gpio_method_t *method;
} gpio_obj_t ;

#endif /* INTERFACE_GPIO_H_ */
