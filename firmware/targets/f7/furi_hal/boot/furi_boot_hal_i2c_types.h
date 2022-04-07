#pragma once

#include <stm32wbxx_ll_i2c.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct FuriBootHalI2cBus FuriBootHalI2cBus;
typedef struct FuriBootHalI2cBusHandle FuriBootHalI2cBusHandle;

/** FuriBootHal i2c bus states */
typedef enum {
    FuriBootHalI2cBusEventInit, /**< Bus initialization event, called on system start */
    FuriBootHalI2cBusEventDeinit, /**< Bus deinitialization event, called on system stop */
    FuriBootHalI2cBusEventLock, /**< Bus lock event, called before activation */
    FuriBootHalI2cBusEventUnlock, /**< Bus unlock event, called after deactivation */
    FuriBootHalI2cBusEventActivate, /**< Bus activation event, called before handle activation */
    FuriBootHalI2cBusEventDeactivate, /**< Bus deactivation event, called after handle deactivation  */
} FuriBootHalI2cBusEvent;

/** FuriBootHal i2c bus event callback */
typedef void (*FuriBootHalI2cBusEventCallback)(FuriBootHalI2cBus* bus, FuriBootHalI2cBusEvent event);

/** FuriBootHal i2c bus */
struct FuriBootHalI2cBus {
    I2C_TypeDef* i2c;
    FuriBootHalI2cBusHandle* current_handle;
    FuriBootHalI2cBusEventCallback callback;
};

/** FuriBootHal i2c handle states */
typedef enum {
    FuriBootHalI2cBusHandleEventActivate, /**< Handle activate: connect gpio and apply bus config */
    FuriBootHalI2cBusHandleEventDeactivate, /**< Handle deactivate: disconnect gpio and reset bus config */
} FuriBootHalI2cBusHandleEvent;

/** FuriBootHal i2c handle event callback */
typedef void (*FuriBootHalI2cBusHandleEventCallback)(
    FuriBootHalI2cBusHandle* handle,
    FuriBootHalI2cBusHandleEvent event);

/** FuriBootHal i2c handle */
struct FuriBootHalI2cBusHandle {
    FuriBootHalI2cBus* bus;
    FuriBootHalI2cBusHandleEventCallback callback;
};

#ifdef __cplusplus
}
#endif