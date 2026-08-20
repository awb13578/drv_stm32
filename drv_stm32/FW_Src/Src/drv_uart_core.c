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

void drv_uart_send_message (uint8_t id, const uint8_t *data, uint16_t size) {
	if (id >= UART_ID_MAX || data == NULL) return;
	uart_obj_t *obj = &uart_inst[id];
	if (obj->method && obj->method->send) {
		obj->ctx.sw_data.tx_size = size;
		memcpy(obj->ctx.sw_data.tx_buffer, data, obj->ctx.sw_data.tx_size);
		obj->method->send(&obj->ctx);
	}
}

uint8_t* drv_uart_receive_message (uint8_t id) {
	if (id >= UART_ID_MAX) return NULL;
	uart_obj_t *obj = &uart_inst[id];
	if (obj->method && obj->method->receive) {
	    obj->method->receive(&obj->ctx);
	}
	return obj->ctx.sw_data.rx_buffer;
}

__weak void drv_uart_rx_callback( uint16_t size) {

}

#endif /* ENABLE_UART */
