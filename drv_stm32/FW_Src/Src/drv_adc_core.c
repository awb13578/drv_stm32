#include "drv_adc_core.h"
#include "board_config.h"

#ifdef ENABLE_ADC

void drv_adc_init (void) {
	for (uint8_t i=0; i<ADC_ID_MAX; i++) {
		adc_obj_t *obj = &adc_inst[i];
		if (obj->method && obj->method->init) {
			obj->method->init(&obj->ctx);
		}
	}
}

void drv_adc_calibrate (void) {
	void *last_hadc = NULL;
	for (uint8_t i=0; i<ADC_ID_MAX; i++) {
		adc_obj_t *obj = &adc_inst[i];
		if (obj->method && obj->method->calibrate) {
			if (last_hadc==NULL || last_hadc!=obj->ctx.hw_cfg.hadc) {
				obj->method->calibrate(&obj->ctx);
				last_hadc = obj->ctx.hw_cfg.hadc;
			}
		}
	}
}

void drv_adc_start_of_conversion (void) {
	void *last_hadc = NULL;
	for (uint8_t i=0; i<ADC_ID_MAX; i++) {
		adc_obj_t *obj = &adc_inst[i];
		if (obj->method && obj->method->start_conversion) {
			if (last_hadc==NULL || last_hadc!=obj->ctx.hw_cfg.hadc) {
				obj->method->start_conversion(&obj->ctx);
				last_hadc = obj->ctx.hw_cfg.hadc;
			}
		}
	}
}

uint16_t drv_adc_get_value (uint8_t id) {
	if (id >= ADC_ID_MAX) return 0;
	adc_obj_t *obj = &adc_inst[id];
	if (obj->method && obj->method->get_value) {
		obj->ctx.sw_data.value = obj->method->get_value(&obj->ctx);
		return obj->method->get_value(&obj->ctx);
	}
	return 0;
}

#endif /* ENABLE_ADC */
