#include "mcu_stm32g0xx_can.h"

#ifdef ENABLE_CAN

static can_ctx_t *can_ctx = NULL;

static can_status_t mcu_can_init (can_ctx_t *ctx) {
	can_ctx = ctx;
	if (ctx == NULL || ctx->hw_cfg.hfdcan == NULL) return CAN_ERROR;

	FDCAN_TxHeaderTypeDef *TxHeader_ctx = (FDCAN_TxHeaderTypeDef *)ctx->sw_data.TxHeader;
	if (TxHeader_ctx != NULL) {
		TxHeader_ctx->IdType 				= FDCAN_STANDARD_ID;
		TxHeader_ctx->TxFrameType 			= FDCAN_DATA_FRAME;
		TxHeader_ctx->DataLength 			= FDCAN_DLC_BYTES_1;
		TxHeader_ctx->ErrorStateIndicator 	= FDCAN_ESI_ACTIVE;
		TxHeader_ctx->BitRateSwitch 		= FDCAN_BRS_OFF;
		TxHeader_ctx->FDFormat 				= FDCAN_FD_CAN;
		TxHeader_ctx->TxEventFifoControl 	= FDCAN_NO_TX_EVENTS;
		TxHeader_ctx->MessageMarker 		= 0;
	}

	FDCAN_FilterTypeDef *sFilterConfig_ctx = (FDCAN_FilterTypeDef *)ctx->sw_data.sFilterConfig;
	if (sFilterConfig_ctx != NULL) {
		sFilterConfig_ctx->IdType 		= FDCAN_STANDARD_ID;
		sFilterConfig_ctx->FilterIndex 	= 0;
		sFilterConfig_ctx->FilterType 	= FDCAN_FILTER_MASK;
		sFilterConfig_ctx->FilterConfig = FDCAN_FILTER_TO_RXFIFO0;
		sFilterConfig_ctx->FilterID1 	= 0x000;
		sFilterConfig_ctx->FilterID2 	= 0x000;
		if (HAL_FDCAN_ConfigFilter(ctx->hw_cfg.hfdcan, ctx->sw_data.sFilterConfig) != HAL_OK) {
			return CAN_ERROR;
		}
	}

    if (HAL_FDCAN_Start(ctx->hw_cfg.hfdcan) != HAL_OK) {
        return CAN_ERROR;
    }
    if (HAL_FDCAN_ActivateNotification(ctx->hw_cfg.hfdcan, FDCAN_IT_RX_FIFO0_NEW_MESSAGE, 0) != HAL_OK) {
    	return CAN_ERROR;
    }
    return CAN_OK;
}

static can_status_t mcu_can_send_message (can_ctx_t *ctx) {
	if (ctx == NULL || ctx->hw_cfg.hfdcan == NULL) return CAN_ERROR;

	FDCAN_TxHeaderTypeDef *TxHeader_ctx = (FDCAN_TxHeaderTypeDef *)ctx->sw_data.TxHeader;
	if (TxHeader_ctx != NULL) {
	    TxHeader_ctx->Identifier = ctx->sw_data.TxID;
	}
	if (HAL_FDCAN_GetTxFifoFreeLevel(ctx->hw_cfg.hfdcan) == 0) return CAN_BUSY;
	return HAL_FDCAN_AddMessageToTxFifoQ(ctx->hw_cfg.hfdcan, TxHeader_ctx, ctx->sw_data.TxData);
}

static can_status_t mcu_can_receive_message (can_ctx_t *ctx) {
	if (ctx == NULL || ctx->hw_cfg.hfdcan == NULL) return CAN_ERROR;

	FDCAN_RxHeaderTypeDef *RxHeader_ctx = (FDCAN_RxHeaderTypeDef *)ctx->sw_data.RxHeader;
	if (HAL_FDCAN_GetRxFifoFillLevel(ctx->hw_cfg.hfdcan, FDCAN_RX_FIFO0) == 0) return CAN_BUSY;

	can_status_t status = HAL_FDCAN_GetRxMessage(ctx->hw_cfg.hfdcan, FDCAN_RX_FIFO0, RxHeader_ctx, ctx->sw_data.RxData);
	if (status == CAN_OK && ctx->sw_data.RxID != NULL) *ctx->sw_data.RxID = RxHeader_ctx->Identifier;
	return status;
}

extern void drv_can_rx_callback (void);

void HAL_FDCAN_RxFifo0Callback (FDCAN_HandleTypeDef *hfdcan, uint32_t RxFifo0ITs) {
	if ((RxFifo0ITs & FDCAN_IT_RX_FIFO0_NEW_MESSAGE) != 0) {
		FDCAN_RxHeaderTypeDef *RxHeader_ctx = (FDCAN_RxHeaderTypeDef *)can_ctx->sw_data.RxHeader;
		HAL_FDCAN_GetRxMessage(can_ctx->hw_cfg.hfdcan, FDCAN_RX_FIFO0, RxHeader_ctx, can_ctx->sw_data.RxData);
		*can_ctx->sw_data.RxID = RxHeader_ctx->Identifier;
		drv_can_rx_callback();
	}
}

const can_method_t stm32_can_method = {
		.init		= mcu_can_init,
		.send		= mcu_can_send_message,
		.receive 	= mcu_can_receive_message,
};

#endif /* ENABLE_CAN */
