#include "drv_adc_core.h"
#include "board_config.h"

#ifdef ENABLE_ADC



/* Mảng quản lý các đối tượng (Object) ADC dựa trên số lượng ID */
static adc_objt_t g_adc_objs[ADC_ID_MAX];

/* Mảng chứa cấu trúc method gán cho từng object */
static adc_method_t g_adc_methods[ADC_ID_MAX];

extern const drv_adc_hw_map_t g_board_adc_map[ADC_ID_MAX];
extern void adc_create_obj(adc_objt_t *p_adc_obj);

void drv_adc_init(void)
{
    for (uint8_t i = 0; i < ADC_ID_MAX; i++)
    {
        /* 1. Đánh dấu ID cho context */
        g_adc_objs[i].ctx.id = (adc_id_e)i;

        /* 2. Map cấu hình phần cứng từ board_config sang Context */
        g_adc_objs[i].ctx.hw_cfg.hadc    = g_board_adc_map[i].hadc;
        g_adc_objs[i].ctx.hw_cfg.channel = g_board_adc_map[i].channel;

        /* 3. Trỏ con trỏ method và gọi hàm tạo Object */
        g_adc_objs[i].method = &g_adc_methods[i];
        adc_create_obj(&g_adc_objs[i]);

        /* 4. Khởi tạo ngoại vi nếu có định nghĩa hàm init trong method */
        if (g_adc_objs[i].method && g_adc_objs[i].method->init)
        {
            g_adc_objs[i].method->init(&g_adc_objs[i].ctx);
        }
    }
}

uint16_t drv_adc_read_raw(adc_id_e id)
{
    if (id >= ADC_ID_MAX) return 0;

    /* Gọi con trỏ hàm get_value từ layer mcu_adc */
    if (g_adc_objs[id].method && g_adc_objs[id].method->read_raw)
    {
        return g_adc_objs[id].method->read_raw(&g_adc_objs[id].ctx);
    }

    return 0;
}

uint32_t drv_adc_read_voltage_mv(adc_id_e id)
{
    if (id >= ADC_ID_MAX) return 0;

    /* Lấy giá trị Raw rồi quy đổi ra mV */
    uint16_t raw = drv_adc_read_raw(id);
    return ((uint32_t)raw * MSP_ADC_VREF_MV) / MSP_ADC_RESOLUTION;
}

#endif /* ENABLE_ADC */
