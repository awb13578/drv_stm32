#ifndef DRV_CONFIG_H_
#define DRV_CONFIG_H_

typedef enum {
    LED1                = 0,  /* PA12/PA10 (Pin 23) */
    LED2                = 1,  /* PA11/PA9  (Pin 22) */
    LED3                = 2,  /* PC6       (Pin 20) */
    LED4                = 3,  /* PA9       (Pin 19) */
    MCU_PFC_RELAY       = 4,  /* PB3       (Pin 27) */
    MCU_LLC_RELAY       = 5,  /* PB4       (Pin 28) */
    GPIO_ID_MAX
} gpio_id_t;

#endif /* DRV_CONFIG_H_ */
