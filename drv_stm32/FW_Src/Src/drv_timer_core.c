#include "drv_timer_core.h"
#include "board_config.h"

#ifdef ENABLE_TIMER

void drv_timer_init (void) {
	const drv_timer_hw_map_t *map = &g_board_timer_map[TIMER2];
	if (map->method && map->method->init) {
		timer_ctx_t ctx = {
				.id			= TIMER2,
				.hw_cfg 	= {
						.htim 	= map->htim,
				},
		};
		map->method->init(&ctx);
	}
}

uint32_t drv_timer_get_counter_value (void) {
	const drv_timer_hw_map_t *map = &g_board_timer_map[TIMER2];
	if (map->method && map->method->get_counter) {
		timer_ctx_t ctx = {
				.id			= TIMER2,
				.hw_cfg 	= {
						.htim 	= map->htim,
				},
		};
		map->method->get_counter(&ctx);
	}
	return 0;
}

void drv_timer_start_interrupt (void) {
	const drv_timer_hw_map_t *map = &g_board_timer_map[TIMER2];
	if (map->method && map->method->start_interrupt) {
		timer_ctx_t ctx = {
				.id			= TIMER2,
				.hw_cfg 	= {
						.htim 	= map->htim,
				},
		};
		map->method->start_interrupt(&ctx);
	}
}

__weak void drv_interrupt_callback (void) {

}

#endif /* ENABLE_TIMER */
