#ifndef MCU_STM32G0XX_ADC_H_
#define MCU_STM32G0XX_ADC_H_

#include "interface_adc.h"
#include "stm32g0xx_hal.h"

#ifdef ENABLE_ADC

extern const adc_method_t stm32_adc_method;

extern ADC_HandleTypeDef hadc1;

#endif /* ENABLE_GPIO */
#endif /* MCU_STM32G0XX_ADC_H_ */
