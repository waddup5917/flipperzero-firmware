#include <furi_hal_light.h>
#include <furi_hal_i2c.h>
#define FuriActiveHalI2cBusHandle FuriHalI2cBusHandle
#define LP5562_API(NAME) lp5562_##NAME
#include <lp5562.h>

#define LED_CURRENT_RED 50
#define LED_CURRENT_GREEN 50
#define LED_CURRENT_BLUE 50
#define LED_CURRENT_WHITE 150

void furi_hal_light_init() {
    furi_hal_i2c_acquire(&furi_hal_i2c_handle_power);

    LP5562_API(reset)(&furi_hal_i2c_handle_power);

    LP5562_API(set_channel_current)(&furi_hal_i2c_handle_power, LP5562ChannelRed, LED_CURRENT_RED);
    LP5562_API(set_channel_current)(&furi_hal_i2c_handle_power, LP5562ChannelGreen, LED_CURRENT_GREEN);
    LP5562_API(set_channel_current)(&furi_hal_i2c_handle_power, LP5562ChannelBlue, LED_CURRENT_BLUE);
    LP5562_API(set_channel_current)(&furi_hal_i2c_handle_power, LP5562ChannelWhite, LED_CURRENT_WHITE);

    LP5562_API(set_channel_value)(&furi_hal_i2c_handle_power, LP5562ChannelRed, 0x00);
    LP5562_API(set_channel_value)(&furi_hal_i2c_handle_power, LP5562ChannelGreen, 0x00);
    LP5562_API(set_channel_value)(&furi_hal_i2c_handle_power, LP5562ChannelBlue, 0x00);
    LP5562_API(set_channel_value)(&furi_hal_i2c_handle_power, LP5562ChannelWhite, 0x00);

    LP5562_API(enable)(&furi_hal_i2c_handle_power);
    LP5562_API(configure)(&furi_hal_i2c_handle_power);

    furi_hal_i2c_release(&furi_hal_i2c_handle_power);
}

void furi_hal_light_set(Light light, uint8_t value) {
    uint8_t prev = 0;
    furi_hal_i2c_acquire(&furi_hal_i2c_handle_power);
    switch(light) {
    case LightRed:
        LP5562_API(set_channel_value)(&furi_hal_i2c_handle_power, LP5562ChannelRed, value);
        break;
    case LightGreen:
        LP5562_API(set_channel_value)(&furi_hal_i2c_handle_power, LP5562ChannelGreen, value);
        break;
    case LightBlue:
        LP5562_API(set_channel_value)(&furi_hal_i2c_handle_power, LP5562ChannelBlue, value);
        break;
    case LightBacklight:
        prev = LP5562_API(get_channel_value)(&furi_hal_i2c_handle_power, LP5562ChannelWhite);
        LP5562_API(execute_ramp)(
            &furi_hal_i2c_handle_power, LP5562Engine1, LP5562ChannelWhite, prev, value, 100);
        break;
    default:
        break;
    }
    furi_hal_i2c_release(&furi_hal_i2c_handle_power);
}
