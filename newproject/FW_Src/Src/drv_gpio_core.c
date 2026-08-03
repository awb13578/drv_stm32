#include "drv_gpio_core.h"
#include "board_config.h"
// giả sử có file board config chứa dữ liệu các nút
// mcu.h sẽ dc khai báo trong board config
// hàm g_board_gpio_map sẽ có trong board config
static drv_gpio_obj_t gpio_inst[GPIO_ID_MAX];

void drv_gpio_init(void)
{
    for (uint8_t i = 0; i < GPIO_ID_MAX; i++)
    {
        gpio_inst[i].ctx.id          = i;
        gpio_inst[i].ctx.hw_cfg.port = g_board_gpio_map[i].port;
        gpio_inst[i].ctx.hw_cfg.pin  = g_board_gpio_map[i].pin;
        gpio_inst[i].method          = *g_board_gpio_map[i].method;

        if (gpio_inst[i].method.init != NULL)
        {
            gpio_inst[i].method.init(&gpio_inst[i].ctx);
        }
    }
}

void drv_gpio_set_pin(uint8_t gpio_id)
{
    if (gpio_id < GPIO_ID_MAX && gpio_inst[gpio_id].method.set != NULL)
    {
        gpio_inst[gpio_id].method.set(&gpio_inst[gpio_id].ctx);
    }
}

void drv_gpio_clear_pin(uint8_t gpio_id)
{
    if (gpio_id < GPIO_ID_MAX && gpio_inst[gpio_id].method.clear != NULL)
    {
        gpio_inst[gpio_id].method.clear(&gpio_inst[gpio_id].ctx);
    }
}

void drv_gpio_toggle_pin(uint8_t gpio_id)
{
    if (gpio_id < GPIO_ID_MAX && gpio_inst[gpio_id].method.toggle != NULL)
    {
        gpio_inst[gpio_id].method.toggle(&gpio_inst[gpio_id].ctx);
    }
}

uint32_t drv_gpio_read_pin(uint8_t gpio_id)
{
    if (gpio_id < GPIO_ID_MAX && gpio_inst[gpio_id].method.read != NULL)
    {
        return gpio_inst[gpio_id].method.read(&gpio_inst[gpio_id].ctx);
    }
    return 0;
}
