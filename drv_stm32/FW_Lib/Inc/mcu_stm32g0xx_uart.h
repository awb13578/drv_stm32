#ifndef MCU_STM32G0XX_UART_H_
#define MCU_STM32G0XX_UART_H_

#include "interface_uart.h"
#include "stm32g0xx_hal.h"

#ifdef ENABLE_UART

extern const uart_method_t stm32_uart_method;

#endif /* ENABLE_UART */
#endif /* MCU_STM32G0XX_UART_H_ */
