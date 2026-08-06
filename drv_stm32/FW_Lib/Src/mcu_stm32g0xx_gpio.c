#include "mcu_stm32g0xx_gpio.h"

#ifdef ENABLE_GPIO

static void mcu_gpio_set(gpio_ctx_t *ctx) {
	if ( ctx && ctx->hw_cfg.port ) {
		HAL_GPIO_WritePin ((GPIO_TypeDef *)ctx->hw_cfg.port, ctx->hw_cfg.pin, GPIO_PIN_SET);
	}
}

static void mcu_gpio_clear(gpio_ctx_t *ctx) {
	if ( ctx && ctx->hw_cfg.port ) {
		HAL_GPIO_WritePin ((GPIO_TypeDef *)ctx->hw_cfg.port, ctx->hw_cfg.pin, GPIO_PIN_RESET);
	}
}

static void mcu_gpio_toggle(gpio_ctx_t *ctx) {
	if ( ctx && ctx->hw_cfg.port ) {
		HAL_GPIO_TogglePin ((GPIO_TypeDef *)ctx->hw_cfg.port, ctx->hw_cfg.pin);
	}
}

static uint32_t mcu_gpio_read(gpio_ctx_t *ctx) {
	if ( ctx && ctx->hw_cfg.port ) {
		return HAL_GPIO_ReadPin ((GPIO_TypeDef *)ctx->hw_cfg.port, ctx->hw_cfg.pin);
	}
	return GPIO_STATE_ERROR;
}

const gpio_method_t stm32_gpio_method = {
		.init	 = NULL,
		.set	 = mcu_gpio_set,
		.clear	 = mcu_gpio_clear,
		.toggle	 = mcu_gpio_toggle,
		.read	 = mcu_gpio_read,
};

#endif /* ENABLE_GPIO */
