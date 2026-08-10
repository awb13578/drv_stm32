#include "drv_timer_core.h"
#include "board_config.h"

#ifdef ENABLE_TIMER

void drv_timer_init (void) {
	const drv_timer_hw_map_t *map = &g_board_timer_map[0];
	if (map->method && map->method->init) {
		timer_ctx_t ctx = {
				.id 		= TIMER_2,
				.hw_cfg 	= {
						.htim = map->htim,
				},
		};
		map->method->init(&ctx);
	}
}

uint32_t drv_get_counter_value (void) {
	const drv_timer_hw_map_t *map = &g_board_timer_map[0];
	if (map->method && map->method->get_cnt) {
		timer_ctx_t ctx = {
				.id 		= TIMER_2,
				.hw_cfg 	= {
						.htim = map->htim,
				},
		};
		return map->method->get_cnt(&ctx);
	}
	return 0;
}

void drv_timer_start_interrupt (void) {
	const drv_timer_hw_map_t *map = &g_board_timer_map[0];
	if (map->method && map->method->init) {
		timer_ctx_t ctx = {
				.id 		= TIMER_2,
				.hw_cfg 	= {
						.htim = map->htim,
				},
		};
		map->method->start_it(&ctx);
	}
}

__attribute__((weak))void  drv_timer_interrupt_callback(void) {

}

#endif /* ENABLE_TIMER */
