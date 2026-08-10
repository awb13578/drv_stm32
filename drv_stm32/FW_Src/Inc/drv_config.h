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

typedef enum {
	MCU_VAC_SENS          = 0, /* PA0  (Pin 7)  */
	MCU_THERMAL_PFC_SENSE = 1, /* PA1  (Pin 8)  */
	MCU_VBAT_SENS         = 2, /* PA2  (Pin 9)  */
	MCU_IBAT_SENS         = 3, /* PA3  (Pin 10) */
	MCU_VOUT_SENS         = 4, /* PA4  (Pin 11) */
	MCU_THERMAL_SR_SENSE  = 5, /* PA5  (Pin 12) */
	MCU_IPRI_SENS         = 6, /* PB0  (Pin 15) */
	ADC_ID_MAX
} adc_id_t;

typedef enum {
	TIMER_2 	= 0,
	TIMER_ID_MAX
} timer_id_t;

#endif /* DRV_CONFIG_H_ */
