#pragma once

#include <stdint.h>
#include <stdbool.h>
//#include <furi_hal_i2c.h>

/** Channel types */
typedef enum {
    LP5562ChannelRed,
    LP5562ChannelGreen,
    LP5562ChannelBlue,
    LP5562ChannelWhite,
} LP5562Channel;

typedef enum {
    LP5562Direct = 0,
    LP5562Engine1 = 1,
    LP5562Engine2 = 2,
    LP5562Engine3 = 3,
} LP5562Engine;

/** Initialize Driver */
void LP5562_API(reset)(FuriActiveHalI2cBusHandle* handle);

/** Configure Driver */
void LP5562_API(configure)(FuriActiveHalI2cBusHandle* handle);

/** Enable Driver */
void LP5562_API(enable)(FuriActiveHalI2cBusHandle* handle);

/** Set channel current */
void LP5562_API(set_channel_current)(FuriActiveHalI2cBusHandle* handle, LP5562Channel channel, uint8_t value);

/** Set channel PWM value */
void LP5562_API(set_channel_value)(FuriActiveHalI2cBusHandle* handle, LP5562Channel channel, uint8_t value);

/** Get channel PWM value */
uint8_t LP5562_API(get_channel_value)(FuriActiveHalI2cBusHandle* handle, LP5562Channel channel);

/** Execute program sequence */
void LP5562_API(execute_program)(
    FuriActiveHalI2cBusHandle* handle,
    LP5562Engine eng,
    LP5562Channel ch,
    uint16_t* program);

/** Execute ramp program sequence */
void LP5562_API(execute_ramp)(
    FuriActiveHalI2cBusHandle* handle,
    LP5562Engine eng,
    LP5562Channel ch,
    uint8_t val_start,
    uint8_t val_end,
    uint16_t time);
