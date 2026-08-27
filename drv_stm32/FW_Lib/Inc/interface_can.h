#ifndef INTERFACE_CAN_H_
#define INTERFACE_CAN_H_

#include "_config_lib.h"
#include "drv_config.h"
#include <stdint.h>
#include <stddef.h>

#define CAN_FD_BUFFER_SIZE 64

typedef enum {
	CAN_OK,
	CAN_ERROR,
	CAN_BUSY,
	CAN_TIMEOUT,
} can_status_t;

typedef struct {
	void *hfdcan;
} can_hw_cfg_t;

typedef struct {
	uint32_t *RxID;
	uint32_t TxID;
	void *RxHeader;
	void *TxHeader;
	void *sFilterConfig;
	uint8_t *RxData;
	uint8_t *TxData;
} can_sw_data_t;

typedef struct {
	can_id_t id;
	can_hw_cfg_t hw_cfg;
	can_sw_data_t sw_data;
} can_ctx_t;

typedef struct {
	can_status_t (*init) (can_ctx_t *ctx);
	can_status_t (*send) (can_ctx_t *ctx);
	can_status_t (*receive) (can_ctx_t *ctx);
} can_method_t;

typedef struct {
	can_ctx_t ctx;
	const can_method_t *method;
} can_obj_t;

#endif /* INTERFACE_CAN_H_ */
