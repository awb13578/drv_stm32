#include "mcu_stm32g0xx_adc.h"

#ifdef ENABLE_ADC

static uint16_t adc_dma_buf[ADC_ID_MAX];

void mcu_adc_calibrate (adc_ctx_t *ctx) {
	if (ctx && ctx->hw_cfg.hadc) {
	    HAL_ADCEx_Calibration_Start((ADC_HandleTypeDef *)ctx->hw_cfg.hadc);
	}
}

void mcu_adc_start_conversation (adc_ctx_t *ctx) {
	if (ctx && ctx->hw_cfg.hadc) {
		HAL_ADC_Start_DMA((ADC_HandleTypeDef *)ctx->hw_cfg.hadc, (uint32_t *)adc_dma_buf, ADC_ID_MAX);
	}
}

uint16_t mcu_adc_get_value (adc_ctx_t *ctx) {
	if (ctx && ctx->hw_cfg.hadc) {
		return adc_dma_buf[ctx->id];
	}
	return 0;
}

const adc_method_t stm32_adc_method = {
		.init				= NULL,
		.calibrate			= mcu_adc_calibrate,
		.start_conversation	= mcu_adc_start_conversation,
		.get_value			= mcu_adc_get_value,
};

#endif /* ENABLE_ADC */
