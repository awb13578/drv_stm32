#include "drv_adc_core.h"
#include "board_config.h"

#ifdef ENABLE_ADC

void drv_adc_init (void) {
	for (uint8_t i=0; i<ADC_ID_MAX; i++) {
		adc_obj_t *obj = &adc_inst[i];
		if (obj->method && obj->method->init) {
			adc_ctx_t ctx = {
					.id 	= i,
					.hw_cfg = {
							.hadc 	= obj->ctx.hw_cfg.hadc,
					},
			};
			obj->method->init(&ctx);
		}
	}
}

void drv_adc_calibrate (void) {
	void *last_hadc = NULL;
	for (uint8_t i=0; i<ADC_ID_MAX; i++) {
		adc_obj_t *obj = &adc_inst[i];
		if (obj->method && obj->method->calibrate) {
			if (last_hadc==NULL || last_hadc!=obj->ctx.hw_cfg.hadc) {
				adc_ctx_t ctx = {
						.id 	= i,
						.hw_cfg = {
								.hadc 	= obj->ctx.hw_cfg.hadc,
						},
				};
				obj->method->calibrate(&ctx);
				last_hadc = obj->ctx.hw_cfg.hadc;
			}
		}
	}
}

void drv_adc_start_of_conversation (void) {
	void *last_hadc = NULL;
	for (uint8_t i=0; i<ADC_ID_MAX; i++) {
		adc_obj_t *obj = &adc_inst[i];
		if (obj->method && obj->method->start_conversation) {
			if (last_hadc==NULL || last_hadc!=obj->ctx.hw_cfg.hadc) {
				adc_ctx_t ctx = {
						.id 	= i,
						.hw_cfg = {
								.hadc 	= obj->ctx.hw_cfg.hadc,
						},
				};
				obj->method->start_conversation(&ctx);
				last_hadc = obj->ctx.hw_cfg.hadc;
			}
		}
	}
}

uint16_t drv_adc_get_value (uint8_t id) {
	if (id >= ADC_ID_MAX) return 0;
	adc_obj_t *obj = &adc_inst[id];
	if (obj->method && obj->method->get_value) {
		adc_ctx_t ctx = {
				.id		= id,
				.hw_cfg = {
						.hadc 	= obj->ctx.hw_cfg.hadc,
				},
		};
		obj->ctx.sw_data.value = obj->method->get_value(&ctx);
		return obj->method->get_value(&ctx);
	}
	return 0;
}

#endif /* ENABLE_ADC */
