#include "board_config.h"
#include "drv_can_core.h"

#ifdef ENABLE_CAN

static uint8_t can_inited = 0;

can_status_t drv_can_init (void) {
	can_obj_t *obj = &can_inst[CANA];
	if (obj->method && obj->method->init) {
		if (obj->method->init(&obj->ctx) == CAN_OK) {
			can_inited = 1;
			return CAN_OK;
		}
	}
	return CAN_ERROR;
}

can_status_t drv_can_send_message(uint32_t id ,uint8_t *Data) {
	if (!can_inited || id > 0x7FF || Data == NULL) return CAN_ERROR;
	can_obj_t *obj = &can_inst[CANA];
	if (obj->method && obj->method->send) {
		obj->ctx.sw_data.TxID = id;
		obj->ctx.sw_data.TxData = Data;
		return obj->method->send(&obj->ctx);
	}
	return CAN_ERROR;
}

can_status_t drv_can_receive_message(uint32_t *id ,uint8_t *Data) {
	if (!can_inited || id == NULL || Data == NULL) return CAN_ERROR;
	can_obj_t *obj = &can_inst[CANA];
	if (obj->method && obj->method->receive) {
		obj->ctx.sw_data.RxID = id;
		obj->ctx.sw_data.RxData = Data;
		return obj->method->receive(&obj->ctx);
	}
	return CAN_ERROR;
}

__weak void drv_can_rx_callback (void) {

}

#endif /* ENABLE_CAN */
