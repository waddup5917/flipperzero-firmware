#include "furi_boot_hal_spi.h"
#include "furi_boot_hal_resources.h"

#include <stdbool.h>
#include <string.h>
#include <assert.h>

#include <stm32wbxx_ll_spi.h>
#include <stm32wbxx_ll_utils.h>
#include <stm32wbxx_ll_cortex.h>

void furi_boot_hal_spi_init() {
    furi_boot_hal_spi_bus_init(&furi_boot_hal_spi_bus_r);
    furi_boot_hal_spi_bus_init(&furi_boot_hal_spi_bus_d);

    furi_boot_hal_spi_bus_handle_init(&furi_boot_hal_spi_bus_handle_subghz);
    furi_boot_hal_spi_bus_handle_init(&furi_boot_hal_spi_bus_handle_nfc);
    furi_boot_hal_spi_bus_handle_init(&furi_boot_hal_spi_bus_handle_display);
    furi_boot_hal_spi_bus_handle_init(&furi_boot_hal_spi_bus_handle_sd_fast);
    furi_boot_hal_spi_bus_handle_init(&furi_boot_hal_spi_bus_handle_sd_slow);
}

void furi_boot_hal_spi_bus_init(FuriBootHalSpiBus* bus) {
    assert(bus);
    bus->callback(bus, FuriBootHalSpiBusEventInit);
}

void furi_boot_hal_spi_bus_deinit(FuriBootHalSpiBus* bus) {
    assert(bus);
    bus->callback(bus, FuriBootHalSpiBusEventDeinit);
}

void furi_boot_hal_spi_bus_handle_init(FuriBootHalSpiBusHandle* handle) {
    assert(handle);
    handle->callback(handle, FuriBootHalSpiBusHandleEventInit);
}

void furi_boot_hal_spi_bus_handle_deinit(FuriBootHalSpiBusHandle* handle) {
    assert(handle);
    handle->callback(handle, FuriBootHalSpiBusHandleEventDeinit);
}

void furi_boot_hal_spi_acquire(FuriBootHalSpiBusHandle* handle) {
    assert(handle);

    handle->bus->callback(handle->bus, FuriBootHalSpiBusEventLock);
    handle->bus->callback(handle->bus, FuriBootHalSpiBusEventActivate);

    assert(handle->bus->current_handle == NULL);

    handle->bus->current_handle = handle;
    handle->callback(handle, FuriBootHalSpiBusHandleEventActivate);
}

void furi_boot_hal_spi_release(FuriBootHalSpiBusHandle* handle) {
    assert(handle);
    assert(handle->bus->current_handle == handle);

    // Handle event and unset handle
    handle->callback(handle, FuriBootHalSpiBusHandleEventDeactivate);
    handle->bus->current_handle = NULL;

    // Bus events
    handle->bus->callback(handle->bus, FuriBootHalSpiBusEventDeactivate);
    handle->bus->callback(handle->bus, FuriBootHalSpiBusEventUnlock);
}

static void furi_boot_hal_spi_bus_end_txrx(FuriBootHalSpiBusHandle* handle, uint32_t timeout) {
    while(LL_SPI_GetTxFIFOLevel(handle->bus->spi) != LL_SPI_TX_FIFO_EMPTY)
        ;
    while(LL_SPI_IsActiveFlag_BSY(handle->bus->spi))
        ;
    while(LL_SPI_GetRxFIFOLevel(handle->bus->spi) != LL_SPI_RX_FIFO_EMPTY) {
        LL_SPI_ReceiveData8(handle->bus->spi);
    }
}

bool furi_boot_hal_spi_bus_rx(
    FuriBootHalSpiBusHandle* handle,
    uint8_t* buffer,
    size_t size,
    uint32_t timeout) {
    assert(handle);
    assert(handle->bus->current_handle == handle);
    assert(buffer);
    assert(size > 0);

    return furi_boot_hal_spi_bus_trx(handle, buffer, buffer, size, timeout);
}

bool furi_boot_hal_spi_bus_tx(
    FuriBootHalSpiBusHandle* handle,
    uint8_t* buffer,
    size_t size,
    uint32_t timeout) {
    assert(handle);
    assert(handle->bus->current_handle == handle);
    assert(buffer);
    assert(size > 0);
    bool ret = true;

    while(size > 0) {
        if(LL_SPI_IsActiveFlag_TXE(handle->bus->spi)) {
            LL_SPI_TransmitData8(handle->bus->spi, *buffer);
            buffer++;
            size--;
        }
    }

    furi_boot_hal_spi_bus_end_txrx(handle, timeout);
    LL_SPI_ClearFlag_OVR(handle->bus->spi);

    return ret;
}

bool furi_boot_hal_spi_bus_trx(
    FuriBootHalSpiBusHandle* handle,
    uint8_t* tx_buffer,
    uint8_t* rx_buffer,
    size_t size,
    uint32_t timeout) {
    assert(handle);
    assert(handle->bus->current_handle == handle);
    assert(tx_buffer);
    assert(rx_buffer);
    assert(size > 0);

    bool ret = true;
    size_t tx_size = size;
    bool tx_allowed = true;

    while(size > 0) {
        if(tx_size > 0 && LL_SPI_IsActiveFlag_TXE(handle->bus->spi) && tx_allowed) {
            LL_SPI_TransmitData8(handle->bus->spi, *tx_buffer);
            tx_buffer++;
            tx_size--;
            tx_allowed = false;
        }

        if(LL_SPI_IsActiveFlag_RXNE(handle->bus->spi)) {
            *rx_buffer = LL_SPI_ReceiveData8(handle->bus->spi);
            rx_buffer++;
            size--;
            tx_allowed = true;
        }
    }

    furi_boot_hal_spi_bus_end_txrx(handle, timeout);

    return ret;
}
