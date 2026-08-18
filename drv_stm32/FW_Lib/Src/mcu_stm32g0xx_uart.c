#include "mcu_stm32g0xx_uart.h"

#ifdef ENABLE_UART

static uart_ctx_t *uart_ctx = NULL;

static void mcu_uart_send_message (uart_ctx_t *ctx) {
	if (ctx && ctx->hw_cfg.huart) {
		HAL_UART_Transmit_DMA(ctx->hw_cfg.huart, ctx->sw_data.tx_buffer, ctx->sw_data.tx_size);
	}
}

static void mcu_receive_message (uart_ctx_t *ctx) {
	if (ctx && ctx->hw_cfg.huart) {
		uart_ctx = ctx;
		HAL_UARTEx_ReceiveToIdle_DMA(ctx->hw_cfg.huart, ctx->sw_data.rx_buffer, sizeof(ctx->sw_data.rx_buffer));
	}
}

void HAL_UARTEx_RxEventCallback(UART_HandleTypeDef *huart, uint16_t Size) {
	if (uart_ctx == NULL || !uart_ctx->hw_cfg.huart) return;
	uart_ctx->sw_data.rx_size = Size;
	uart_ctx->sw_data.rx_flag_ready = 1;
}

const uart_method_t stm32_uart_method = {
		.init		= NULL,
		.send		= mcu_uart_send_message,
		.receive	= mcu_receive_message,
};

#endif /* ENABLE_UART */
