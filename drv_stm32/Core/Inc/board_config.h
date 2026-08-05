#ifndef BOARD_CONFIG_H_
#define BOARD_CONFIG_H_

#include "drv_gpio_core.h"
#include "drv_adc_core.h"

typedef struct {
    void *port;
    uint32_t pin;
    const gpio_method_t *method;
} drv_gpio_hw_map_t;

typedef struct {
    ADC_HandleTypeDef *hadc;    /* Con trỏ tới bộ ADC (hadc1) */
    GPIO_TypeDef      *port;    /* Port GPIO */
    uint16_t           pin;     /* Pin GPIO */
    uint32_t           channel; /* Kênh ADC tương ứng (ADC_CHANNEL_x) */
    const adc_method_t      *method;  /* Pointer chứa các hàm read, init... */
} drv_adc_hw_map_t;

extern const drv_gpio_hw_map_t g_board_gpio_map[GPIO_ID_MAX];

extern const drv_adc_hw_map_t g_board_adc_map[ADC_ID_MAX];

#endif /* BOARD_CONFIG_H_ */
