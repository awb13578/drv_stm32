#ifndef MCU_STM32G0XX_CAN_H_
#define MCU_STM32G0XX_CAN_H_

#include "interface_can.h"
#include "stm32g0xx_hal.h"

#ifdef ENABLE_CAN

extern const can_method_t stm32_can_method;

#endif /* ENABLE_CAN */
#endif /* MCU_STM32G0XX_CAN_H_ */
