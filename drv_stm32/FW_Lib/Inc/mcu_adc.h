#ifndef MCU_ADC_H_
#define MCU_ADC_H_

#include "interface_adc.h"

#define MSP_ADC_RESOLUTION 4095U // 12-bit ADC max value
#define MSP_ADC_VREF_MV 3300U // Reference voltage in mV

void adc_create_obj(adc_objt_t *p_adc_obj);

#endif /* MCU_ADC_H_ */
