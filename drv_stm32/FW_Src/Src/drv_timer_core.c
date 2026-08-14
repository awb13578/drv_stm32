#include "drv_timer_core.h"
#include "board_config.h"

#ifdef ENABLE_TIMER

void drv_timer_init (void) {
	timer_obj_t *obj = &timer_inst[TIMER2];
	if (obj->method && obj->method->init) {
		obj->method->init(&obj->ctx);
	}
}

uint32_t drv_timer_get_counter_value (void) {
	timer_obj_t *obj = &timer_inst[TIMER2];
	if (obj->method && obj->method->get_counter) {
		obj->ctx.sw_data.counter = obj->method->get_counter(&obj->ctx);
		return obj->ctx.sw_data.counter;
	}
	return 0;
}

void drv_timer_start_interrupt (void) {
	timer_obj_t *obj = &timer_inst[TIMER2];
	if (obj->method && obj->method->start_interrupt) {
		obj->method->start_interrupt(&obj->ctx);
	}
}

__weak void drv_interrupt_callback (void) {

}

#endif /* ENABLE_TIMER */
