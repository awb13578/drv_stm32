#ifndef INTERFACE_GPIO_H_
#define INTERFACE_GPIO_H_

#include "_config_lib.h"
#include "drv_config.h"

typedef struct GPIO_Regs GPIO_Regs;

typedef struct {
	uint32_t status;
} gpio_sw_data_t;

typedef struct {
    GPIO_Regs *port;
    uint32_t pin;
} gpio_hw_cfg_t;

typedef struct {
    #ifdef ENABLE_GPIO
        gpio_id_e        id;
    #endif
    gpio_sw_data_t sw_data;
    gpio_hw_cfg_t  hw_cfg;
} gpio_ctx_t;

typedef struct {
    void (*init)(gpio_ctx_t *ctx);
    void (*set)(gpio_ctx_t *ctx);
    void (*clear)(gpio_ctx_t *ctx);
    uint32_t (*read)(gpio_ctx_t *ctx);
    void (*toggle)(gpio_ctx_t *ctx);
} gpio_method_t;

typedef struct {
    gpio_ctx_t    ctx;
    gpio_method_t *method;
} gpio_objt_t;

#endif
