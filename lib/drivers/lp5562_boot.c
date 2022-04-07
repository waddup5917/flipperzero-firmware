#include <furi_boot_hal.h>

#define FuriActiveHalI2cBusHandle FuriBootHalI2cBusHandle
#define HAL_CALL(fn, args...) furi_boot_hal_##fn(args)
#define LP5562_API(NAME) lp5562_boot_##NAME

#include "lp5562.inc"