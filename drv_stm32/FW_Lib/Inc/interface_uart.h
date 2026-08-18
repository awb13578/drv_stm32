#ifndef INTERFACE_UART_H_
#define INTERFACE_UART_H_

#include "_config_lib.h"
#include "drv_config.h"
#include <stdint.h>
#include <stddef.h>

#define UART_RX_BUFFER_SIZE 32
#define UART_TX_BUFFER_SIZE 32

typedef struct {
	void *huart;
} uart_hw_cfg_t;

typedef struct {
	uint8_t rx_size;
	uint8_t rx_buffer[UART_RX_BUFFER_SIZE];
	uint8_t rx_flag_ready;
	uint8_t tx_size;
	uint8_t tx_buffer[UART_TX_BUFFER_SIZE];
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

#endif /* INTERFACE_UART_H_ */
