#include "interface_adc.h"
#include "stm32g0xx_hal.h"

#ifndef MCU_STM32G0XX_ADC_H_
#define MCU_STM32G0XX_ADC_H_
#ifdef ENABLE_ADC

extern const adc_method_t stm32_adc_method;

#endif /* ENABLE_ADC */
#endif /* MCU_STM32G0XX_ADC_H_ */
