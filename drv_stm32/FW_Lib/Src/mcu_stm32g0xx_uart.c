#include "mcu_stm32g0xx_uart.h"

#ifdef ENABLE_UART

static uart_ctx_t *uart_ctx = NULL;

static void mcu_uart_send_message (uart_ctx_t *ctx) {
	if (ctx && ctx->hw_cfg.huart) {
		HAL_UART_Transmit_DMA(ctx->hw_cfg.huart, ctx->sw_data.tx_buffer, ctx->sw_data.tx_size);
		ctx->sw_data.flag_tx_busy = 1;
//		if (HAL_UART_Transmit_DMA(ctx->hw_cfg.huart, ctx->sw_data.tx_buffer, ctx->sw_data.tx_size) != HAL_OK) ctx->sw_data.flag_tx_busy = 0;
	}
}

void HAL_UART_TxCpltCallback (UART_HandleTypeDef *huart) {
	if (uart_ctx && uart_ctx->hw_cfg.huart == huart) {
	        uart_ctx->sw_data.flag_tx_busy = 0;
	    }
}

static void mcu_uart_receive_message (uart_ctx_t *ctx) {
	if (ctx && ctx->hw_cfg.huart) {
		uart_ctx = ctx;
		HAL_UARTEx_ReceiveToIdle_DMA(ctx->hw_cfg.huart, ctx->sw_data.rx_buffer, sizeof(ctx->sw_data.rx_buffer));
	}
}

extern void drv_uart_rx_callback(uint16_t size);

void HAL_UARTEx_RxEventCallback(UART_HandleTypeDef *huart, uint16_t Size) {
	if (uart_ctx == NULL || !uart_ctx->hw_cfg.huart) return;
	uart_ctx->sw_data.rx_size = Size;
	drv_uart_rx_callback(uart_ctx->sw_data.rx_size);
	// Clear UART flags
	__HAL_UART_CLEAR_FLAG(huart, UART_CLEAR_OREF | UART_CLEAR_NEF | UART_CLEAR_PEF | UART_CLEAR_FEF | UART_CLEAR_IDLEF);
	HAL_UARTEx_ReceiveToIdle_DMA(uart_ctx->hw_cfg.huart, uart_ctx->sw_data.rx_buffer, sizeof(uart_ctx->sw_data.rx_buffer));
}

const uart_method_t stm32_uart_method = {
		.init		= NULL,
		.send		= mcu_uart_send_message,
		.receive	= mcu_uart_receive_message,
};

#endif /* ENABLE_UART */
