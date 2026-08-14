#ifndef INTERFACE_ADC_H_
#define INTERFACE_ADC_H_

#include "_config_lib.h"
#include "drv_config.h"
#include <stdint.h>
#include <stddef.h>

typedef struct {
	void *hadc;
	uint32_t channel;
} adc_hw_cfg_t;

typedef struct {
	uint16_t value;
} adc_sw_data_t;

typedef struct {
	adc_id_t id;
	adc_hw_cfg_t hw_cfg;
	adc_sw_data_t sw_data;
} adc_ctx_t;

typedef struct {
	void (*init) (adc_ctx_t *ctx);
	void (*calibrate) (adc_ctx_t *ctx);
	void (*start_conversation) (adc_ctx_t *ctx);
	uint16_t (*get_value) (adc_ctx_t *ctx);
} adc_method_t;

#endif /* INTERFACE_H_ */
