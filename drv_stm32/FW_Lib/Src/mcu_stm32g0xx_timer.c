#include "mcu_stm32g0xx_timer.h"

#ifdef ENABLE_TIMER

static void mcu_timer_init (timer_ctx_t *ctx) {
	if (ctx && ctx->hw_cfg.htim) {
		HAL_TIM_Base_Start((TIM_HandleTypeDef *)ctx->hw_cfg.htim);
	}
}

static uint32_t mcu_timer_get_cnt (timer_ctx_t *ctx) {
	if (ctx && ctx->hw_cfg.htim) {
		return __HAL_TIM_GET_COUNTER((TIM_HandleTypeDef *)ctx->hw_cfg.htim);
	}
	return 0;
}

static void mcu_timer_start_it (timer_ctx_t *ctx) {
	if (ctx && ctx->hw_cfg.htim) {
		HAL_TIM_Base_Start_IT((TIM_HandleTypeDef *)ctx->hw_cfg.htim);
	}
}

void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim) {
	if (htim->Instance == &htim2) {
		drv_timer_interrupt_callback();
	}
}

const timer_method_t stm32_timer_method = {
		.init		= mcu_timer_init,
		.get_cnt 	= mcu_timer_get_cnt,
		.start_it	= mcu_timer_start_it,
};

#endif /* ENABLE_TIMER */
