#include "drv_uart_core.h"
#include "board_config.h"

#ifdef ENABLE_UART

void drv_uart_init (void) {
	for (uint8_t i=0; i<UART_ID_MAX; i++) {
		uart_obj_t *obj = &uart_inst[i];
		if (obj->method && obj->method->init) {
			obj->method->init(&obj->ctx);
		}
	}
}

void drv_uart_send_message (const uint8_t *data) {
	if (data == NULL) return;
	uart_obj_t *obj = &uart_inst[UART_LLC];
	if (obj->method && obj->method->send) {
		if (obj->ctx.sw_data.flag_tx_busy) return;
		obj->ctx.sw_data.tx_data = *data;
		obj->method->send(&obj->ctx);
	}
}

uint8_t* drv_uart_receive_message (void) {
	uart_obj_t *obj = &uart_inst[UART_LLC];
	if (obj->method && obj->method->receive) {
	    obj->method->receive(&obj->ctx);
	}
	return obj->ctx.sw_data.rx_buffer;
}

__weak void drv_uart_rx_callback(void) {

}

#endif /* ENABLE_UART */
