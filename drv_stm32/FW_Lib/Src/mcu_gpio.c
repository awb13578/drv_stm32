#include "mcu_gpio.h"

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

    GPIO_InitTypeDef GPIO_InitStruct = {0};

        GPIO_InitStruct.Pin = ctx->hw_cfg.pin;
        GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP; // Đặt làm Output
        GPIO_InitStruct.Pull = GPIO_NOPULL;
        GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;

        HAL_GPIO_Init((GPIO_TypeDef *)ctx->hw_cfg.port, &GPIO_InitStruct);
}
