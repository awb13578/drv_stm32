#include "mcu_gpio.h"
#ifdef ENABLE_GPIO

const gpio_method_t stm32_gpio_method = {
    .init   = mcu_gpio_init,
    .set    = mcu_gpio_set,
    .clear  = mcu_gpio_clear,
    .toggle = mcu_gpio_toggle,
    .read   = mcu_gpio_read
};

void mcu_gpio_set(gpio_ctx_t *ctx)
{
    HAL_GPIO_WritePin((GPIO_TypeDef *)ctx->hw_cfg.port, ctx->hw_cfg.pin, GPIO_PIN_SET);
}

void mcu_gpio_clear(gpio_ctx_t *ctx)
{
	HAL_GPIO_WritePin((GPIO_TypeDef *)ctx->hw_cfg.port, ctx->hw_cfg.pin, GPIO_PIN_RESET);
}

void mcu_gpio_toggle(gpio_ctx_t *ctx)
{
    HAL_GPIO_TogglePin((GPIO_TypeDef *)ctx->hw_cfg.port, ctx->hw_cfg.pin);
}

uint32_t mcu_gpio_read(gpio_ctx_t *ctx)
{
    GPIO_PinState pin_state = HAL_GPIO_ReadPin((GPIO_TypeDef *)ctx->hw_cfg.port, ctx->hw_cfg.pin);

    return (pin_state == GPIO_PIN_SET) ? 1 : 0;
}

void mcu_gpio_init(gpio_ctx_t *ctx)
{
    if (ctx == NULL || ctx->hw_cfg.port == NULL) return;

}
#endif
