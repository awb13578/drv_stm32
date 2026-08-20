#include "board_config.h"
#include "mcu_stm32g0xx_gpio.h"
#include "mcu_stm32g0xx_timer.h"
#include "mcu_stm32g0xx_adc.h"
#include "mcu_stm32g0xx_uart.h"

gpio_obj_t gpio_inst[GPIO_ID_MAX] = {
		[LED1] = {
			.ctx 	= {
					.id		 = LED1,
					.hw_cfg	 = {
							.port	= GPIOA,
							.pin	= GPIO_PIN_12,
					},
					.sw_data = {
							.state = 0,
					},
			},
			.method = &stm32_gpio_method
		},
		[LED2] = {
			.ctx 	= {
					.id		= LED2,
					.hw_cfg	= {
							.port = GPIOA,
							.pin  = GPIO_PIN_11,
					},
					.sw_data = {
							.state = 0,
					},
			},
			.method = &stm32_gpio_method
		},
		[LED3] = {
			.ctx 	= {
					.id		= LED3,
					.hw_cfg	= {
							.port = GPIOC,
							.pin  = GPIO_PIN_6,
					},
					.sw_data = {
							.state = 0,
					},
			},
			.method = &stm32_gpio_method
		},
		[LED4] = {
			.ctx 	= {
					.id		= LED4,
					.hw_cfg	= {
							.port = GPIOA,
							.pin  = GPIO_PIN_9,
					},
					.sw_data = {
							.state = 0,
					},
			},
			.method = &stm32_gpio_method
		},
		[MCU_PFC_RELAY] = {
			.ctx 	= {
					.id		= MCU_PFC_RELAY,
					.hw_cfg	= {
							.port = GPIOB,
							.pin  = GPIO_PIN_3,
					},
					.sw_data = {
							.state = 0,
					},
			},
			.method = &stm32_gpio_method
		},
		[MCU_LLC_RELAY] = {
			.ctx 	= {
					.id		= MCU_LLC_RELAY,
					.hw_cfg	= {
							.port = GPIOB,
							.pin  = GPIO_PIN_4,
					},
					.sw_data = {
							.state = 0,
					},
			},
			.method = &stm32_gpio_method
		},
};

timer_obj_t timer_inst[TIMER_ID_MAX] = {
		[TIMER2] = {
			.ctx	= {
					.id	 	= TIMER2,
					.hw_cfg	= {
						.htim	= &htim2,
					},
					.sw_data	= {
						.counter	= 0,
					},
			},
			.method = &stm32_timer_method
		},
};

adc_obj_t adc_inst[ADC_ID_MAX] = {
		[MCU_VAC_SENS] = {
			.ctx	 = {
					.id		= MCU_VAC_SENS,
					.hw_cfg	= {
							.hadc    = &hadc1,
							.channel = ADC_CHANNEL_0,
					},
					.sw_data = {
							.value   = 0
					},
			},
			.method  = &stm32_adc_method
		},
		[MCU_THERMAL_PFC_SENSE] = {
			.ctx	 = {
					.id		= MCU_THERMAL_PFC_SENSE,
					.hw_cfg	= {
							.hadc    = &hadc1,
							.channel = ADC_CHANNEL_1,
					},
					.sw_data = {
							.value   = 0
					},
			},
			.method  = &stm32_adc_method
		},
		[MCU_VBAT_SENS] = {
			.ctx	 = {
					.id		= MCU_VBAT_SENS,
					.hw_cfg	= {
							.hadc    = &hadc1,
							.channel = ADC_CHANNEL_2,
					},
					.sw_data = {
							.value   = 0
					},
			},
			.method  = &stm32_adc_method
		},
		[MCU_IBAT_SENS] = {
			.ctx	 = {
					.id		= MCU_IBAT_SENS,
					.hw_cfg	= {
							.hadc    = &hadc1,
							.channel = ADC_CHANNEL_3,
					},
					.sw_data = {
							.value   = 0
					},
			},
			.method  = &stm32_adc_method
		},
		[MCU_VOUT_SENS] = {
			.ctx	 = {
					.id		= MCU_VOUT_SENS,
					.hw_cfg	= {
							.hadc    = &hadc1,
							.channel = ADC_CHANNEL_4,
					},
					.sw_data = {
							.value   = 0
					},
			},
			.method  = &stm32_adc_method
		},
		[MCU_THERMAL_SR_SENSE] = {
			.ctx	 = {
					.id		= MCU_THERMAL_SR_SENSE,
					.hw_cfg	= {
							.hadc    = &hadc1,
							.channel = ADC_CHANNEL_5,
					},
					.sw_data = {
							.value   = 0
					},
			},
			.method  = &stm32_adc_method
		},
		[MCU_IPRI_SENS] = {
			.ctx	 = {
					.id		= MCU_IPRI_SENS,
					.hw_cfg	= {
							.hadc    = &hadc1,
							.channel = ADC_CHANNEL_8,
					},
					.sw_data = {
							.value   = 0
					},
			},
			.method  = &stm32_adc_method
		},
};

uart_obj_t uart_inst[UART_ID_MAX] = {
		[UART_LLC] = {
			.ctx	= {
					.id	 	= UART_LLC,
					.hw_cfg	= {
						.huart	= &huart3,
					},
					.sw_data	= {
						.rx_size		= 0,
						.rx_buffer 		= {0},
						.tx_size		= 0,
						.tx_buffer		= {0},
						.flag_tx_busy		= 0,
					},
			},
			.method = &stm32_uart_method
		},
};
