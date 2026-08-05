#ifndef DRV_ADC_CORE_H_
#define DRV_ADC_CORE_H_

#include "interface_adc.h"

#ifdef ENABLE_ADC

/* Hàm khởi tạo toàn bộ các kênh ADC đã khai báo trong board_config.c */
void drv_adc_init(void);

/* Hàm kích hoạt ADC */
void drv_adc_start_of_conversion(adc_id_e id);

/* Hàm đọc giá trị số thô (Raw: 0 -> 4095) theo ID */
uint16_t drv_adc_get_value(adc_id_e id);

/* Hàm đọc giá trị điện áp (mV) quy đổi theo ID */
uint32_t drv_adc_calibrate(adc_id_e id);

#endif /* ENABLE_ADC */

#endif /* DRV_ADC_CORE_H_ */
