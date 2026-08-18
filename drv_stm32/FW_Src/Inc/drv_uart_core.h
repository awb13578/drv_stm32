#ifndef DRV_UART_CORE_H_
#define DRV_UART_CORE_H_

#include "interface_uart.h"

#ifdef ENABLE_UART

void drv_uart_init (void);
void drv_uart_send_num (uint8_t id, int32_t num);
void drv_uart_send_str (uint8_t id, const char *str);
char* drv_uart_receive_message (uint8_t id);

#define drv_uart_send_message(id, val) _Generic((val), 					\
    char*:          drv_uart_send_str, 									\
    const char*:    drv_uart_send_str, 									\
    uint8_t*:       (void (*)(uint8_t, const char*))drv_uart_send_str, 	\
    const uint8_t*: (void (*)(uint8_t, const char*))drv_uart_send_str, 	\
    default:        drv_uart_send_num  									\
)((id), (val))

#endif /* ENABLE_UART */
#endif /* DRV_UART_CORE_H_ */
