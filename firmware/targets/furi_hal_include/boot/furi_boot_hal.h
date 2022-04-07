#pragma once

#include <furi_boot_hal_i2c.h>
#include <furi_boot_hal_light.h>
//#include <furi_boot_hal_resources.h>
#include <furi_boot_hal_spi.h>

//#define furi_assert(value) (void)(value)

void furi_boot_hal_init();

void furi_boot_hal_delay_ms(float milliseconds);

void furi_boot_hal_delay_us(float microseconds);
