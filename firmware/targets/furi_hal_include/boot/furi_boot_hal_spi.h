#pragma once

#include <furi_boot_hal_spi_config.h>
#include <stdbool.h>

#ifdef __cplusplus
extern "C" {
#endif

/** Initialize SPI HAL */
void furi_boot_hal_spi_init();

/** Initialize SPI Bus
 *
 * @param      handle  pointer to FuriBootHalSpiBus instance
 */
void furi_boot_hal_spi_bus_init(FuriBootHalSpiBus* bus);

/** Deinitialize SPI Bus
 *
 * @param      handle  pointer to FuriBootHalSpiBus instance
 */
void furi_boot_hal_spi_bus_deinit(FuriBootHalSpiBus* bus);

/** Initialize SPI Bus Handle
 *
 * @param      handle  pointer to FuriBootHalSpiBusHandle instance
 */
void furi_boot_hal_spi_bus_handle_init(FuriBootHalSpiBusHandle* handle);

/** Deinitialize SPI Bus Handle
 *
 * @param      handle  pointer to FuriBootHalSpiBusHandle instance
 */
void furi_boot_hal_spi_bus_handle_deinit(FuriBootHalSpiBusHandle* handle);

/** Acquire SPI bus
 *
 * @warning blocking, calls `furi_crash` on programming error, CS transition is up to handler event routine
 *
 * @param      handle  pointer to FuriBootHalSpiBusHandle instance
 */
void furi_boot_hal_spi_acquire(FuriBootHalSpiBusHandle* handle);

/** Release SPI bus
 *
 * @warning calls `furi_crash` on programming error, CS transition is up to handler event routine
 * 
 * @param      handle  pointer to FuriBootHalSpiBusHandle instance
 */
void furi_boot_hal_spi_release(FuriBootHalSpiBusHandle* handle);

/** SPI Receive
 *
 * @param      handle   pointer to FuriBootHalSpiBusHandle instance
 * @param      buffer   receive buffer
 * @param      size     transaction size (buffer size)
 * @param      timeout  operation timeout in ms
 *
 * @return     true on sucess
 */
bool furi_boot_hal_spi_bus_rx(
    FuriBootHalSpiBusHandle* handle,
    uint8_t* buffer,
    size_t size,
    uint32_t timeout);

/** SPI Transmit
 *
 * @param      handle   pointer to FuriBootHalSpiBusHandle instance
 * @param      buffer   transmit buffer
 * @param      size     transaction size (buffer size)
 * @param      timeout  operation timeout in ms
 *
 * @return     true on success
 */
bool furi_boot_hal_spi_bus_tx(
    FuriBootHalSpiBusHandle* handle,
    uint8_t* buffer,
    size_t size,
    uint32_t timeout);

/** SPI Transmit and Receive
 *
 * @param      handle     pointer to FuriBootHalSpiBusHandle instance
 * @param      tx_buffer  pointer to tx buffer
 * @param      rx_buffer  pointer to rx buffer
 * @param      size       transaction size (buffer size)
 * @param      timeout    operation timeout in ms
 *
 * @return     true on success
 */
bool furi_boot_hal_spi_bus_trx(
    FuriBootHalSpiBusHandle* handle,
    uint8_t* tx_buffer,
    uint8_t* rx_buffer,
    size_t size,
    uint32_t timeout);

#ifdef __cplusplus
}
#endif