#ifndef DRV_CAN_CORE_H_
#define DRV_CAN_CORE_H_

#include "interface_can.h"

#ifdef ENABLE_CAN

can_status_t drv_can_init (void);
can_status_t drv_can_send_message(uint32_t id ,uint8_t *Data);
can_status_t drv_can_receive_message(uint32_t *id ,uint8_t *Data);

#endif /* ENABLE_CAN */
#endif /* DRV_CAN_CORE_H_ */
