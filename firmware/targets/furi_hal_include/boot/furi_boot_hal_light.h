#pragma once

#include <stdbool.h>
#include <stdint.h>
#include <furi_boot_hal_resources.h>

#ifdef __cplusplus
extern "C" {
#endif

void furi_boot_hal_light_init();

void furi_boot_hal_light_set(BootLight light, uint8_t value);

#ifdef __cplusplus
}
#endif
