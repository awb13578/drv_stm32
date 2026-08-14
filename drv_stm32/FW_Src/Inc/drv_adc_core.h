#ifndef DRV_ADC_CORE_H_
#define DRV_ADC_CORE_H_

#include "interface_adc.h"

#ifdef ENABLE_ADC

void drv_adc_init (void);
void drv_adc_calibrate (void);
void drv_adc_start_of_conversation (void);
uint16_t drv_adc_get_value (uint8_t id);

#endif /* ENABLE_ADC */
#endif /* DRV_ADC_CORE_H_ */
