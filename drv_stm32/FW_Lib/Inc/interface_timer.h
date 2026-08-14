#ifndef INTERFACE_TIMER_H_
#define INTERFACE_TIMER_H_

#include "_config_lib.h"
#include "drv_config.h"
#include <stdint.h>
#include <stddef.h>

typedef struct {
	void *htim;
} timer_hw_cfg_t;

typedef struct {
	uint32_t counter;
} timer_sw_data_t;

typedef struct {
	uint8_t id;
	timer_hw_cfg_t hw_cfg;
	timer_sw_data_t sw_data;
} timer_ctx_t;

typedef struct {
	void (*init) (timer_ctx_t *ctx);
	uint32_t (*get_counter) (timer_ctx_t *ctx);
	void (*start_interrupt) (timer_ctx_t *ctx);
} timer_method_t;

#endif /* INTERFACE_TIMER_H_ */
