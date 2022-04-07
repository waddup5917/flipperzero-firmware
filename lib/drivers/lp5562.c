#include <furi_hal.h>

#define FuriActiveHalI2cBusHandle FuriHalI2cBusHandle
#define HAL_CALL(fn, args...) furi_hal_##fn(args)
#define LP5562_API(NAME) lp5562_##NAME

#include "lp5562.inc"