#include "drv_adc_core.h"
#include "board_config.h"

#ifdef ENABLE_ADC

void drv_adc_init(void) {
	for (uint8_t i=0; i<ADC_ID_MAX; i++) {
	const drv_adc_hw_map_t *map = &g_board_adc_map[i];
		if (map->method && map->method->init) {
			adc_ctx_t ctx = {
					.id 	= i,
					.hw_cfg = {
							.hadc 		= map->hadc,
							.channel 	= map->channel,
							.dma_index	= map->dma_index,
					},
			};
			map->method->init(&ctx);
		};
	}
}

void drv_adc_start_of_conversion (uint8_t adc_id) {
	if (adc_id>=ADC_ID_MAX) return;
	const drv_adc_hw_map_t *map = &g_board_adc_map[adc_id];
	if (map->method && map->method->start_cnv) {
		adc_ctx_t ctx = {
				.id 	= adc_id,
				.hw_cfg = {
						.hadc 		= map->hadc,
						.channel 	= map->channel,
						.dma_index	= map->dma_index,
				},
		};
		map->method->start_cnv(&ctx);
	};
}


void drv_adc_calibrate (uint8_t adc_id) {
	if (adc_id>=ADC_ID_MAX) return;
	const drv_adc_hw_map_t *map = &g_board_adc_map[adc_id];
	if (map->method && map->method->calibrate) {
		adc_ctx_t ctx = {
				.id 	= adc_id,
				.hw_cfg = {
						.hadc 		= map->hadc,
						.channel 	= map->channel,
						.dma_index	= map->dma_index,
				},
		};
		map->method->calibrate(&ctx);
	};
}

float drv_adc_get_value (uint8_t adc_id) {
	if (adc_id>=ADC_ID_MAX) return ADC_STATE_ERROR;
	const drv_adc_hw_map_t *map = &g_board_adc_map[adc_id];
	if (map->method && map->method->get_voltage) {
		adc_ctx_t ctx = {
				.id 	= adc_id,
				.hw_cfg = {
						.hadc 		= map->hadc,
						.channel 	= map->channel,
						.dma_index	= map->dma_index,
				},
		};
		return map->method->get_voltage(&ctx);
	};
	return ADC_STATE_ERROR;
}

#endif /* ENABLE_ADC */
