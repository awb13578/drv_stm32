#ifndef DRV_TIMER_CORE_H_
#define DRV_TIMER_CORE_H_

#include "interface_timer.h"

#ifdef ENABLE_TIMER

void drv_timer_init (void);

uint32_t drv_get_counter_value (void);

void drv_timer_start_interrupt (void);

#endif /* ENABLE_TIMER */
#endif /* DRV_TIMER_CORE_H_ */
