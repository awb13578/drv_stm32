#include "drv_adc_core.h"
#include "board_config.h"

#ifdef ENABLE_ADC

void drv_adc_init (void) {
	for (uint8_t i=0; i<ADC_ID_MAX; i++) {
		const drv_adc_hw_map_t *map = &g_board_adc_map[i];
		if (map->method && map->method->init) {
			adc_ctx_t ctx = {
					.id 	= i,
					.hw_cfg = {
							.hadc 	= map->hadc,
					},
			};
			map->method->init(&ctx);
		}
	}
}

void drv_adc_calibrate (void) {
	void *last_hadc = NULL;
	for (uint8_t i=0; i<ADC_ID_MAX; i++) {
		const drv_adc_hw_map_t *map = &g_board_adc_map[i];
		if (map->method && map->method->calibrate) {
			if (last_hadc==NULL || last_hadc!=map->hadc) {
				adc_ctx_t ctx = {
						.id 	= i,
						.hw_cfg = {
								.hadc 	= map->hadc,
						},
				};
				map->method->calibrate(&ctx);
				last_hadc = map->hadc;
			}
		}
	}
}

void drv_adc_start_of_conversation (void) {
	void *last_hadc = NULL;
	for (uint8_t i=0; i<ADC_ID_MAX; i++) {
		const drv_adc_hw_map_t *map = &g_board_adc_map[i];
		if (map->method && map->method->start_conversation) {
			if (last_hadc==NULL || last_hadc!=map->hadc) {
				adc_ctx_t ctx = {
						.id 	= i,
						.hw_cfg = {
								.hadc 	= map->hadc,
						},
				};
				map->method->start_conversation(&ctx);
				last_hadc = map->hadc;
			}
		}
	}
}

uint16_t drv_adc_get_value (uint8_t id) {
	if (id >= ADC_ID_MAX) return 0;
	const drv_adc_hw_map_t *map = &g_board_adc_map[id];
	if (map->method && map->method->get_value) {
		adc_ctx_t ctx = {
				.id		= id,
				.hw_cfg = {
						.hadc 	= map->hadc,
				},
		};
		return map->method->get_value(&ctx);
	}
	return 0;
}

#endif /* ENABLE_ADC */
