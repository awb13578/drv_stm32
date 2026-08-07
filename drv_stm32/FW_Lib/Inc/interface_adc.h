#ifndef INTERFACE_ADC_H_
#define INTERFACE_ADC_H_

#include "drv_config.h"
#include "_config_lib.h"
#include <stdint.h>
#include <stddef.h>

#define ADC_VREF_MV     3300U
#define ADC_MAX_RAW     4095U

#define ADC_STATE_ERROR -1.0f

struct adc_ctx;

typedef struct {
	void *hadc;
	uint32_t channel;
	uint8_t dma_index;
} adc_hw_cfg_t;

typedef struct {
	float voltage;
} adc_data_t;

typedef struct adc_ctx{
	uint8_t id;
	adc_data_t data;
	adc_hw_cfg_t hw_cfg;
} adc_ctx_t;

typedef struct {
	void (*init) (adc_ctx_t *ctx);
	void (*start_cnv) (adc_ctx_t *ctx);
	void (*calibrate) (adc_ctx_t *ctx);
	float (*get_voltage) (adc_ctx_t *ctx);
} adc_method_t;

#endif /* INTERFACE_ADC_H_ */
