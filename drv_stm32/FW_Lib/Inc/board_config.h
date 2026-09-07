#ifndef BOARD_CONFIG_H_
#define BOARD_CONFIG_H_

#include "stm32g0xx_hal.h"
#include "interface_gpio.h"
#include "interface_timer.h"
#include "interface_adc.h"
#include "interface_uart.h"
#include "interface_can.h"

extern gpio_obj_t gpio_inst[GPIO_ID_MAX];

extern TIM_HandleTypeDef htim2;
extern timer_obj_t timer_inst[TIMER_ID_MAX];

extern ADC_HandleTypeDef hadc1;
extern adc_obj_t adc_inst[ADC_ID_MAX];

extern UART_HandleTypeDef huart3;
extern uart_obj_t uart_inst[UART_ID_MAX];

extern FDCAN_HandleTypeDef hfdcan2;
extern can_obj_t can_inst[CAN_ID_MAX];

#endif /* BOARD_CONFIG_H_ */
