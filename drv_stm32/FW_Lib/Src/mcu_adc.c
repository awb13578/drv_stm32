#include "mcu_adc.h"
#ifdef ENABLE_ADC

// 1. Hàm đọc giá trị số thô (Raw: 0 - 4095)
static uint16_t mcu_adc_read_raw(adc_ctx_t *ctx) {
    if (!ctx || !ctx->hw_cfg.hadc) return 0;

    ADC_HandleTypeDef *hadc = (ADC_HandleTypeDef *)ctx->hw_cfg.hadc;
    ADC_ChannelConfTypeDef sConfig = {.Channel = ctx->hw_cfg.channel, .Rank = ADC_REGULAR_RANK_1, .SamplingTime = LL_ADC_SAMPLINGTIME_12CYCLES_5};

    HAL_ADC_ConfigChannel(hadc, &sConfig);
    HAL_ADC_Start(hadc);

    uint16_t raw = 0;
    if (HAL_ADC_PollForConversion(hadc, 10) == HAL_OK) {
        raw = (uint16_t)HAL_ADC_GetValue(hadc);
    }
    HAL_ADC_Stop(hadc);
    return raw;
}

// 2. Hàm quy đổi từ Raw sang Điện áp (mV)
static uint32_t mcu_adc_read_voltage_mv(adc_ctx_t *ctx) {
    return ((uint32_t)mcu_adc_read_raw(ctx) * MSP_ADC_VREF_MV) / MSP_ADC_RESOLUTION;
}

// 3. Hàm gán Method (Con trỏ hàm) vào Object
void adc_create_obj(adc_objt_t *p_adc_obj) {
    if (!p_adc_obj) return;
    p_adc_obj->method->read_raw        = mcu_adc_read_raw;
    p_adc_obj->method->read_voltage_mv = mcu_adc_read_voltage_mv;
}
#endif
