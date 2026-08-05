#ifndef INTERFACE_ADC_H_
#define INTERFACE_ADC_H_

#include "_config_lib.h"
#include "drv_config.h"

#define MSP_ADC_RESOLUTION 4095U // 12-bit ADC max value
#define MSP_ADC_VREF_MV 3300U // Reference voltage in mV

typedef struct {
    uint16_t value;
} adc_sw_data_t;

typedef struct {
    void     *hadc;
    uint32_t  channel;
} adc_hw_cfg_t;

typedef struct {
    #ifdef ENABLE_ADC
        adc_id_e        id;
    #endif
    adc_sw_data_t sw_data;
    adc_hw_cfg_t  hw_cfg;
} adc_ctx_t;

typedef struct {
    void (*init)(adc_ctx_t *ctx);
    void (*start_cnv)(adc_ctx_t *ctx);
    uint16_t (*read_raw)(adc_ctx_t *ctx);
    uint32_t (*read_voltage_mv)(adc_ctx_t *ctx);
} adc_method_t;

typedef struct {
    adc_ctx_t    ctx;
    adc_method_t *method;
} adc_objt_t;

#endif /* INTERFACE_ADC_H_ */
