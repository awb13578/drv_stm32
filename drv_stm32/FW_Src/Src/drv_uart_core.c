#include "drv_uart_core.h"
#include "board_config.h"
#include <string.h>
#include <stdio.h>

#ifdef ENABLE_UART

void drv_uart_init (void) {
	for (uint8_t i=0; i<UART_ID_MAX; i++) {
		uart_obj_t *obj = &uart_inst[i];
		if (obj->method && obj->method->init) {
			obj->method->init(&obj->ctx);
		}
		if (obj->method && obj->method->receive) {
		    obj->method->receive(&obj->ctx);
		}
	}
}

void drv_uart_send_str (uint8_t id, const char *data) {
	if (id >= UART_ID_MAX || data == NULL) return;
	uart_obj_t *obj = &uart_inst[id];
	uint16_t len = (uint16_t)strlen(data);
	if (len >= sizeof(obj->ctx.sw_data.tx_buffer)) {
	    len = sizeof(obj->ctx.sw_data.tx_buffer) - 1;
	}
	memcpy(obj->ctx.sw_data.tx_buffer, data, len);
	obj->ctx.sw_data.tx_size = len;
	if (obj->method && obj->method->send) {
		obj->method->send(&obj->ctx);
	}
}

void drv_uart_send_num (uint8_t id, int32_t num) {
	char temp_buffer[16];
	snprintf(temp_buffer, sizeof(temp_buffer), "%ld", num);
	drv_uart_send_str (id, temp_buffer);
}

char* drv_uart_receive_message (uint8_t id) {
	if (id >= UART_ID_MAX) return NULL;
	uart_obj_t *obj = &uart_inst[id];
	if (obj->ctx.sw_data.rx_flag_ready == 1) {
	    obj->ctx.sw_data.rx_flag_ready = 0;
	    if (obj->method && obj->method->receive) {
	        obj->method->receive(&obj->ctx);
	    }
	    return (char*)obj->ctx.sw_data.rx_buffer;
	}
	return NULL;
}

#endif /* ENABLE_UART */
