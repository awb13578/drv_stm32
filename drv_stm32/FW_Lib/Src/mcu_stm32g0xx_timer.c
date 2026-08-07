#include "mcu_stm32g0xx_timer.h"

#ifdef ENABLE_TIMER

static void mcu_timer_init (ctx_timer_t *ctx) {
	if (ctx && ctx->method) {
		HAL_TIM_Base_Start((TIM_TypeDef *)ctx->hw_cfg.htim);
	}
}

static uint32_t mcu_timer_get_cnt (ctx_timer_t *ctx) {
	if (ctx && ctx->method) {
		return __HAL_TIM_GET_COUNTER((TIM_TypeDef *)ctx->hw_cfg.htim);
	}
	return 0;
}

const stm32_timer_method = {
		.init		= mcu_timer_init,
		.get_cnt 	= mcu_timer_get_cnt
};

#endif /* ENABLE_TIMER */
