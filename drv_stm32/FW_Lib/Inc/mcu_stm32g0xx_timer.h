#ifndef MCU_STM32G0XX_TIMER_H_
#define MCU_STM32G0XX_TIMER_H_

#include "interface_timer.h"
#include "stm32g0xx_hal.h"

#ifdef ENABLE_TIMER

extern const timer_method_t stm32_timer_method;

extern TIM_HandleTypeDef htim2;

#endif /* ENABLE_TIMER */
#endif /* MCU_STM32G0XX_TIMER_H_ */
