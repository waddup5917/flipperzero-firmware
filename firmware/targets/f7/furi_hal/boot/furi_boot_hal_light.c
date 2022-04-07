#include <furi_boot_hal_light.h>
#include <furi_boot_hal_i2c.h>
#define FuriActiveHalI2cBusHandle FuriBootHalI2cBusHandle
#define LP5562_API(NAME) lp5562_boot_##NAME
#include <lp5562.h>

#define LED_CURRENT_RED 50
#define LED_CURRENT_GREEN 50
#define LED_CURRENT_BLUE 50
#define LED_CURRENT_WHITE 150

void furi_boot_hal_light_init() {
    furi_boot_hal_i2c_acquire(&furi_boot_hal_i2c_handle_power);

    LP5562_API(reset)(&furi_boot_hal_i2c_handle_power);

    LP5562_API(set_channel_current)(&furi_boot_hal_i2c_handle_power, LP5562ChannelRed, LED_CURRENT_RED);
    LP5562_API(set_channel_current)(&furi_boot_hal_i2c_handle_power, LP5562ChannelGreen, LED_CURRENT_GREEN);
    LP5562_API(set_channel_current)(&furi_boot_hal_i2c_handle_power, LP5562ChannelBlue, LED_CURRENT_BLUE);
    LP5562_API(set_channel_current)(&furi_boot_hal_i2c_handle_power, LP5562ChannelWhite, LED_CURRENT_WHITE);

    LP5562_API(set_channel_value)(&furi_boot_hal_i2c_handle_power, LP5562ChannelRed, 0x00);
    LP5562_API(set_channel_value)(&furi_boot_hal_i2c_handle_power, LP5562ChannelGreen, 0x00);
    LP5562_API(set_channel_value)(&furi_boot_hal_i2c_handle_power, LP5562ChannelBlue, 0x00);
    LP5562_API(set_channel_value)(&furi_boot_hal_i2c_handle_power, LP5562ChannelWhite, 0x00);

    LP5562_API(enable)(&furi_boot_hal_i2c_handle_power);
    LP5562_API(configure)(&furi_boot_hal_i2c_handle_power);

    furi_boot_hal_i2c_release(&furi_boot_hal_i2c_handle_power);
}

void furi_boot_hal_light_set(BootLight light, uint8_t value) {
    furi_boot_hal_i2c_acquire(&furi_boot_hal_i2c_handle_power);
    switch(light) {
    case BootLightRed:
        LP5562_API(set_channel_value)(&furi_boot_hal_i2c_handle_power, LP5562ChannelRed, value);
        break;
    case BootLightGreen:
        LP5562_API(set_channel_value)(&furi_boot_hal_i2c_handle_power, LP5562ChannelGreen, value);
        break;
    case BootLightBlue:
        LP5562_API(set_channel_value)(&furi_boot_hal_i2c_handle_power, LP5562ChannelBlue, value);
        break;
    case BootLightBacklight:
        LP5562_API(set_channel_value)(&furi_boot_hal_i2c_handle_power, LP5562ChannelWhite, value);
        break;
    default:
        break;
    }
    furi_boot_hal_i2c_release(&furi_boot_hal_i2c_handle_power);
}