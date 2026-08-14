#ifndef BOARD_CONFIG_H_
#define BOARD_CONFIG_H_

#include "stm32g0xx_hal.h"
#include "interface_gpio.h"
#include "interface_timer.h"
#include "interface_adc.h"

typedef struct {
	void *port;
	uint16_t pin;
	const gpio_method_t *method;
} drv_gpio_hw_map_t ;

extern const drv_gpio_hw_map_t g_board_gpio_map[GPIO_ID_MAX];

typedef struct {
	timer_ctx_t ctx;
	const timer_method_t *method;
} timer_obj_t ;

extern TIM_HandleTypeDef htim2;
extern timer_obj_t timer_inst[TIMER_ID_MAX];

typedef struct {
	adc_ctx_t ctx;
	const adc_method_t *method;
} adc_obj_t ;

extern ADC_HandleTypeDef hadc1;
extern adc_obj_t adc_inst[ADC_ID_MAX];

#endif /* BOARD_CONFIG_H_ */
