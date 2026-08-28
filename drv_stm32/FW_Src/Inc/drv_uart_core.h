#ifndef DRV_UART_CORE_H_
#define DRV_UART_CORE_H_

#include "interface_uart.h"

#ifdef ENABLE_UART

void drv_uart_init (void);
void drv_uart_send_message (const uint8_t *data);
uint8_t* drv_uart_receive_message (void);

#endif /* ENABLE_UART */
#endif /* DRV_UART_CORE_H_ */
