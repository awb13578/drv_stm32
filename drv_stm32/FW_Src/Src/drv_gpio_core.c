#include "board_config.h"
#include "drv_gpio_core.h"

#ifdef ENABLE_GPIO

void drv_gpio_init(void) {
	for (uint8_t i=0; i<GPIO_ID_MAX; i++) {
	const drv_gpio_hw_map_t *map = &g_board_gpio_map[i];
		if (map->method && map->method->init) {
			gpio_ctx_t ctx = {
					.id 	= i,
					.hw_cfg = {
							.port 	= map->port,
							.pin 	= map->pin,
					},
			};
		map->method->init(&ctx);
		}
	}
}

void drv_gpio_set_pin(uint8_t gpio_id) {
	if (gpio_id>=GPIO_ID_MAX) return;
	const drv_gpio_hw_map_t *map = &g_board_gpio_map[gpio_id];
	if (map->method && map->method->set) {
		gpio_ctx_t ctx = {
			.id 	= gpio_id,
			.hw_cfg = {
				.port 	= map->port,
				.pin 	= map->pin,
			},
		};
		map->method->set(&ctx);
	}
}

void drv_gpio_clear_pin(uint8_t gpio_id) {
	if (gpio_id>=GPIO_ID_MAX) return;
	const drv_gpio_hw_map_t *map = &g_board_gpio_map[gpio_id];
	if (map->method && map->method->clear) {
		gpio_ctx_t ctx = {
			.id 	= gpio_id,
			.hw_cfg = {
				.port 	= map->port,
				.pin 	= map->pin,
			},
		};
		map->method->clear(&ctx);
	}
}

void drv_gpio_toggle_pin(uint8_t gpio_id) {
	if (gpio_id>=GPIO_ID_MAX) return;
	const drv_gpio_hw_map_t *map = &g_board_gpio_map[gpio_id];
	if (map->method && map->method->toggle) {
		gpio_ctx_t ctx = {
			.id 	= gpio_id,
			.hw_cfg = {
				.port 	= map->port,
				.pin 	= map->pin,
			},
		};
		map->method->toggle(&ctx);
	}
}

uint32_t drv_gpio_read_pin(uint8_t gpio_id) {
	if (gpio_id>=GPIO_ID_MAX) return GPIO_STATE_ERROR;
	const drv_gpio_hw_map_t *map = &g_board_gpio_map[gpio_id];
	if (map->method && map->method->read) {
		gpio_ctx_t ctx = {
			.id 	= gpio_id,
			.hw_cfg = {
				.port 	= map->port,
				.pin 	= map->pin,
			},
		};
		return map->method->read(&ctx);
	}
	return GPIO_STATE_ERROR;
}

#endif /* ENABLE_GPIO */
