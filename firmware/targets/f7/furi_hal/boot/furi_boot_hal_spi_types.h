#pragma once

#include <stdint.h>
#include <stddef.h>

#include <furi_boot_hal_gpio.h>

#include <stm32wbxx_ll_spi.h>
#include <stm32wbxx_ll_rcc.h>
#include <stm32wbxx_ll_bus.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct FuriBootHalSpiBus FuriBootHalSpiBus;
typedef struct FuriBootHalSpiBusHandle FuriBootHalSpiBusHandle;

/** FuriBootHal spi bus states */
typedef enum {
    FuriBootHalSpiBusEventInit, /**< Bus initialization event, called on system start */
    FuriBootHalSpiBusEventDeinit, /**< Bus deinitialization event, called on system stop */
    FuriBootHalSpiBusEventLock, /**< Bus lock event, called before activation */
    FuriBootHalSpiBusEventUnlock, /**< Bus unlock event, called after deactivation */
    FuriBootHalSpiBusEventActivate, /**< Bus activation event, called before handle activation */
    FuriBootHalSpiBusEventDeactivate, /**< Bus deactivation event, called after handle deactivation  */
} FuriBootHalSpiBusEvent;

/** FuriBootHal spi bus event callback */
typedef void (*FuriBootHalSpiBusEventCallback)(FuriBootHalSpiBus* bus, FuriBootHalSpiBusEvent event);

/** FuriBootHal spi bus */
struct FuriBootHalSpiBus {
    SPI_TypeDef* spi;
    FuriBootHalSpiBusEventCallback callback;
    FuriBootHalSpiBusHandle* current_handle;
};

/** FuriBootHal spi handle states */
typedef enum {
    FuriBootHalSpiBusHandleEventInit, /**< Handle init, called on system start, initialize gpio for idle state */
    FuriBootHalSpiBusHandleEventDeinit, /**< Handle deinit, called on system stop, deinitialize gpio for default state */
    FuriBootHalSpiBusHandleEventActivate, /**< Handle activate: connect gpio and apply bus config */
    FuriBootHalSpiBusHandleEventDeactivate, /**< Handle deactivate: disconnect gpio and reset bus config */
} FuriBootHalSpiBusHandleEvent;

/** FuriBootHal spi handle event callback */
typedef void (*FuriBootHalSpiBusHandleEventCallback)(
    FuriBootHalSpiBusHandle* handle,
    FuriBootHalSpiBusHandleEvent event);

/** FuriBootHal spi handle */
struct FuriBootHalSpiBusHandle {
    FuriBootHalSpiBus* bus;
    FuriBootHalSpiBusHandleEventCallback callback;
    const BootGpioPin* miso;
    const BootGpioPin* mosi;
    const BootGpioPin* sck;
    const BootGpioPin* cs;
};

#ifdef __cplusplus
}
#endif