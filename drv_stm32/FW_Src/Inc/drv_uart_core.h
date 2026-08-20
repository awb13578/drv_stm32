#ifndef DRV_UART_CORE_H_
#define DRV_UART_CORE_H_

#include "interface_uart.h"

#ifdef ENABLE_UART

void drv_uart_init (void);
void drv_uart_send_message (uint8_t id, const uint8_t *data, uint16_t size);
uint8_t* drv_uart_receive_message (uint8_t id);

#endif /* ENABLE_UART */
#endif /* DRV_UART_CORE_H_ */
