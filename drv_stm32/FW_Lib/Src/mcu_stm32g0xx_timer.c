#include "mcu_stm32g0xx_timer.h"

#ifdef ENABLE_TIMER

static void mcu_timer_init (timer_ctx_t *ctx) {
	if ( ctx && ctx->hw_cfg.htim ) {
		HAL_TIM_Base_Start((TIM_HandleTypeDef *)ctx->hw_cfg.htim);
	}
}

static uint32_t mcu_get_counter (timer_ctx_t *ctx) {
	if ( ctx && ctx->hw_cfg.htim ) {
		return __HAL_TIM_GET_COUNTER((TIM_HandleTypeDef *)ctx->hw_cfg.htim);
		}
	return 0;
}

static void mcu_start_interrupt (timer_ctx_t *ctx) {
	if ( ctx && ctx->hw_cfg.htim ) {
		HAL_TIM_Base_Start_IT((TIM_HandleTypeDef *)ctx->hw_cfg.htim);
	}
}

extern void drv_interrupt_callback (void);

void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim){
	drv_interrupt_callback();
}

const timer_method_t stm32_timer_method = {
		.init 				= mcu_timer_init,
		.get_counter		= mcu_get_counter,
		.start_interrupt	= mcu_start_interrupt,
};

#endif /* ENABLE_TIMER */
