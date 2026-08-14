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
	void *htim;
	const timer_method_t *method;
} drv_timer_hw_map_t ;

extern TIM_HandleTypeDef htim2;
extern const drv_timer_hw_map_t g_board_timer_map[TIMER_ID_MAX];

typedef struct {
	void *hadc;
	const adc_method_t *method;
} drv_adc_hw_map_t ;

extern ADC_HandleTypeDef hadc1;
extern const drv_adc_hw_map_t g_board_adc_map[ADC_ID_MAX];

#endif /* BOARD_CONFIG_H_ */
