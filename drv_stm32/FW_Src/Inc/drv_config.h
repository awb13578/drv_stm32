#ifndef DRV_CONFIG_H_
#define DRV_CONFIG_H_

#include <stdint.h>
#include <stdbool.h>
#include "main.h"

#define TX_BUFFER_SIZE      150U
#define RX_BUFFER_SIZE      150U


/* Danh sách các chân GPIO xuất/nhập tín hiệu (LED, Relay, Fan, v.v.) */
typedef enum {
    LED1                = 0,  /* PA12/PA10 (Pin 23) */
    LED2                = 1,  /* PA11/PA9  (Pin 22) */
    LED3                = 2,  /* PC6       (Pin 20) */
    LED4                = 3,  /* PA9       (Pin 19) */
    MCU_PFC_RELAY           = 4,  /* PB3       (Pin 27) */
    MCU_LLC_RELAY           = 5,  /* PB4       (Pin 28) */
    GPIO_ID_MAX
} gpio_id_e;

/* Danh sách các Timer dùng trong hệ thống */
//typedef enum {
//    TIM_ID_TIMER1               = 0,
//    TIM_ID_TIMER2               = 1,
//    TIM_ID_MAX
//} timer_id_e;

/* Danh sách tín hiệu Analog đọc qua ADC dựa trên Schematic */
typedef enum {
    MCU_VAC_SENS             = 0,  /* PA0 (Pin 7)  - Đo điện áp AC vào */
    MCU_THERMAL_PFC_SENSE    = 1,  /* PA1 (Pin 8)  - Cảm biến nhiệt PFC */
    MCU_VBAT_SENS            = 2,  /* PA2 (Pin 9)  - Đo điện áp Acquy/Pin */
    MCU_IBAT_SENS            = 3,  /* PA3 (Pin 10) - Đo dòng điện Acquy/Pin */
    MCU_VOUT_SENS            = 4,  /* PA4 (Pin 11) - Đo điện áp đầu ra */
    MCU_THERMAL_SR_SENSE     = 5,  /* PA5 (Pin 12) - Cảm biến nhiệt SR */
    MCU_IPRI_SENS            = 6,  /* PB0 (Pin 15) - Đo dòng sơ cấp (mcuIpri_sens) */
    ADC_ID_MAX
} adc_id_e;

/* Danh sách các cổng xuất xung PWM */
//typedef enum {
//    PWM_ID_LLC_L                = 0,  /* PB1 (Pin 16) - Xung điều khiển LLC Low-side */
//    PWM_ID_LLC_H                = 1,  /* PA10(Pin 21) - Xung điều khiển LLC High-side */
//    PWM_ID_FAN_PWM              = 2,  /* PB7 (Pin 31) - Điều khiển tốc độ Quạt */
//    PWM_ID_MAX
//} pwm_id_e;

/* Danh sách bộ DAC (Nếu không dùng xuất analog ra ngoài có thể để trống/dùng debug) */
//typedef enum {
//    DAC_ID_DBG_DAC1             = 0,
//    DAC_ID_DBG_DAC2             = 1,
//    DAC_ID_MAX
//} dac_id_e;

/* Danh sách bộ truyền thông USART/UART */
//typedef enum {
//    USART_ID_LLC                = 0,  /* PB8 (TX), PB9 (RX) - Cổng UART giao tiếp */
//    NUMBER_OF_USART
//} usart_id_e;

/* Cổng giao tiếp CAN Bus */
//typedef enum {
//    CAN_ID_A                    = 0,  /* PB5 (RX), PB6 (TX) - CANA_Rx / CANA_Tx */
//    NUMBER_OF_CAN
//} can_id_e;

/* Comparator/Bộ so sánh phần cứng (nếu dùng cho bảo vệ quá dòng/quá áp) */
//typedef enum {
//    COMP_ID_PFC                 = 0,
//    COMP_ID_MAX
//} comp_id_e;

/* Input Capture / Đo tần số xung */
//typedef enum {
//    ECAP_ID_1                   = 0,
//    ECAP_ID_MAX
//} ecap_id_e;

#endif /* DRV_CONFIG_H_ */
