#include <flipper_boot_led.h>

#include <furi_hal_light.h>
#include <furi_hal_delay.h>

void flipper_boot_led_sequence(const char* c) {
    return;
    furi_hal_light_set(LightRed, 0x00);
    furi_hal_light_set(LightGreen, 0x00);
    furi_hal_light_set(LightBlue, 0x00);
    do {
        switch(*(c++)) {
        case 'R':
            furi_hal_light_set(LightRed, 0xFF);
            break;
        case 'G':
            furi_hal_light_set(LightGreen, 0xFF);
            break;
        case 'B':
            furi_hal_light_set(LightBlue, 0xFF);
            break;
        case 'W':
            furi_hal_light_set(LightRed, 0xFF);
            furi_hal_light_set(LightGreen, 0xFF);
            furi_hal_light_set(LightBlue, 0xFF);
            break;
        case 'Y':
            furi_hal_light_set(LightRed, 0xFF);
            furi_hal_light_set(LightGreen, 0xFF);
            break;
        case 'M':
            furi_hal_light_set(LightRed, 0xFF);
            furi_hal_light_set(LightBlue, 0xFF);
            break;
        case '.':
            furi_hal_delay_ms(125);
            furi_hal_light_set(LightRed, 0xFF);
            furi_hal_light_set(LightGreen, 0xFF);
            furi_hal_light_set(LightBlue, 0xFF);
            furi_hal_delay_ms(125);
            break;
        case '-':
            furi_hal_delay_ms(250);
            furi_hal_light_set(LightRed, 0xFF);
            furi_hal_light_set(LightGreen, 0xFF);
            furi_hal_light_set(LightBlue, 0xFF);
            furi_hal_delay_ms(250);
            break;
        default:
            break;
        }
    } while(*c != 0);
}