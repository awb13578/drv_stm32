#include "board_config.h"
#include "drv_gpio_core.h"

#ifdef ENABLE_GPIO

void drv_gpio_init(void) {
	for (uint8_t i=0; i<GPIO_ID_MAX; i++) {
	gpio_obj_t *obj = &gpio_inst[i];
		if (obj->method && obj->method->init) {
			obj->method->init(&obj->ctx);
		}
	}
}

void drv_gpio_set_pin (uint8_t gpio_id) {
	if (gpio_id>=GPIO_ID_MAX) return;
	gpio_obj_t *obj = &gpio_inst[gpio_id];
	if (obj->method && obj->method->set) {
		obj->method->set(&obj->ctx);
		obj->ctx.sw_data.state = 1;
	}
}

void drv_gpio_clear_pin (uint8_t gpio_id) {
	if (gpio_id>=GPIO_ID_MAX) return;
	gpio_obj_t *obj = &gpio_inst[gpio_id];
	if (obj->method && obj->method->clear) {
		obj->method->clear(&obj->ctx);
		obj->ctx.sw_data.state = 0;
	}
}

void drv_gpio_toggle_pin (uint8_t gpio_id) {
	if (gpio_id>=GPIO_ID_MAX) return;
	gpio_obj_t *obj = &gpio_inst[gpio_id];
	if (obj->method && obj->method->toggle) {
		obj->method->toggle(&obj->ctx);
		obj->ctx.sw_data.state = !obj->ctx.sw_data.state;
	}
}

uint32_t drv_gpio_read_pin (uint8_t gpio_id) {
	if (gpio_id>=GPIO_ID_MAX) return GPIO_STATE_ERROR;
	gpio_obj_t *obj = &gpio_inst[gpio_id];
	if (obj->method && obj->method->read) {
		return obj->method->read(&obj->ctx);
	}
	return GPIO_STATE_ERROR;
}

#endif /* ENABLE_GPIO */
