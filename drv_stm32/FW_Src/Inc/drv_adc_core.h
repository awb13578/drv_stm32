#ifndef DRV_ADC_CORE_H_
#define DRV_ADC_CORE_H_

#include "interface_adc.h"

#ifdef ENABLE_ADC

void drv_adc_init (void);
void drv_adc_start_of_conversion (uint8_t adc_id);
void drv_adc_calibrate (uint8_t adc_id);
float drv_adc_get_value (uint8_t adc_id);

#endif /* ENABLE_ADC */
#endif /* DRV_ADC_CORE_H_ */
