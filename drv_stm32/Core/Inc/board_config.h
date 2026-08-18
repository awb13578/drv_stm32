#ifndef BOARD_CONFIG_H_
#define BOARD_CONFIG_H_

#include "stm32g0xx_hal.h"
#include "interface_gpio.h"
#include "interface_timer.h"
#include "interface_adc.h"
#include "interface_uart.h"

/*                              GPIO                                   */

typedef struct {
	gpio_ctx_t ctx;
	const gpio_method_t *method;
} gpio_obj_t ;

extern gpio_obj_t gpio_inst[GPIO_ID_MAX];

/*                              TIMER                                  */

typedef struct {
	timer_ctx_t ctx;
	const timer_method_t *method;
} timer_obj_t ;

extern TIM_HandleTypeDef htim2;
extern timer_obj_t timer_inst[TIMER_ID_MAX];

/*                               ADC                                    */

typedef struct {
	adc_ctx_t ctx;
	const adc_method_t *method;
} adc_obj_t ;

extern ADC_HandleTypeDef hadc1;
extern adc_obj_t adc_inst[ADC_ID_MAX];

/*                               UART                                   */

typedef struct {
	uart_ctx_t ctx;
	const uart_method_t *method;
} uart_obj_t;

extern UART_HandleTypeDef huart3;
extern uart_obj_t uart_inst[UART_ID_MAX];

#endif /* BOARD_CONFIG_H_ */
