#include "mcu_stm32g0xx_adc.h"

#ifdef ENABLE_ADC

static void mcu_adc_init (adc_ctx_t *ctx) {
	if (ctx==NULL || ctx->hw_cfg.hadc==NULL) return;
	HAL_ADC_Init((ADC_HandleTypeDef  * )ctx->hw_cfg.hadc);
}

static void mcu_adc_start_cnv (adc_ctx_t *ctx) {
	if (ctx && ctx->hw_cfg.hadc) {
		HAL_ADC_Start((ADC_HandleTypeDef *)ctx->hw_cfg.hadc);
	}
}

static void mcu_adc_calibrate (adc_ctx_t *ctx) {
	if (ctx && ctx->hw_cfg.hadc) {
		HAL_ADCEx_Calibration_Start((ADC_HandleTypeDef *)ctx->hw_cfg.hadc);
	}
}

static float mcu_adc_get_voltage (adc_ctx_t *ctx) {
	if (ctx && ctx->hw_cfg.hadc) {
			if (HAL_ADC_PollForConversion((ADC_HandleTypeDef *)ctx->hw_cfg.hadc,10) == HAL_OK) {
				uint16_t raw = HAL_ADC_GetValue((ADC_HandleTypeDef *)ctx->hw_cfg.hadc);
				return ((float)raw * 3.3f) / 4095.0f;
			}
			return ADC_STATE_ERROR;
		}
	return ADC_STATE_ERROR;
}

const adc_method_t stm32_adc_method = {
		.init	  	 = mcu_adc_init,
		.start_cnv 	 = mcu_adc_start_cnv,
		.calibrate 	 = mcu_adc_calibrate,
		.get_voltage = mcu_adc_get_voltage,
};

#endif /* ENABLE_ADC */
