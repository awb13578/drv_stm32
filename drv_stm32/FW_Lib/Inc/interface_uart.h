#ifndef INTERFACE_UART_H_
#define INTERFACE_UART_H_

#include "_config_lib.h"
#include "drv_config.h"
#include <stdint.h>
#include <stddef.h>
#include <string.h>

#define UART_RX_BUFFER_SIZE 128

typedef struct {
	void *huart;
} uart_hw_cfg_t;

typedef struct {
	uint8_t rx_buffer[UART_RX_BUFFER_SIZE];
	uint8_t tx_data;
	volatile uint8_t flag_tx_busy;
} uart_sw_data_t;

typedef struct {
	uart_id_t id;
	uart_hw_cfg_t hw_cfg;
	uart_sw_data_t sw_data;
} uart_ctx_t;

typedef struct {
	void (*init) (uart_ctx_t *ctx);
	void (*send) (uart_ctx_t *ctx);
	void (*receive) (uart_ctx_t *ctx);
} uart_method_t;

typedef struct {
	uart_ctx_t ctx;
	const uart_method_t *method;
} uart_obj_t;

#endif /* INTERFACE_UART_H_ */
