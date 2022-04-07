/**
 * @file furi_boot_hal_i2c.h
 * I2C HAL API
 */

#pragma once

#include <stdbool.h>
#include <stdint.h>
#include <stddef.h>
#include <furi_boot_hal_i2c_config.h>

#ifdef __cplusplus
extern "C" {
#endif

/** Init I2C
 */
void furi_boot_hal_i2c_init();

/** Acquire i2c bus handle
 *
 * @return     Instance of FuriBootHalI2cBus
 */
void furi_boot_hal_i2c_acquire(FuriBootHalI2cBusHandle* handle);

/** Release i2c bus handle
 *
 * @param      bus   instance of FuriBootHalI2cBus aquired in `furi_boot_hal_i2c_acquire`
 */
void furi_boot_hal_i2c_release(FuriBootHalI2cBusHandle* handle);

/** Perform I2C tx transfer
 *
 * @param      handle   pointer to FuriBootHalI2cBusHandle instance
 * @param      address  I2C slave address
 * @param      data     pointer to data buffer
 * @param      size     size of data buffer
 * @param      timeout  timeout in ticks
 *
 * @return     true on successful transfer, false otherwise
 */
bool furi_boot_hal_i2c_tx(
    FuriBootHalI2cBusHandle* handle,
    const uint8_t address,
    const uint8_t* data,
    const uint8_t size,
    uint32_t timeout);

/** Perform I2C rx transfer
 *
 * @param      handle   pointer to FuriBootHalI2cBusHandle instance
 * @param      address  I2C slave address
 * @param      data     pointer to data buffer
 * @param      size     size of data buffer
 * @param      timeout  timeout in ticks
 *
 * @return     true on successful transfer, false otherwise
 */
bool furi_boot_hal_i2c_rx(
    FuriBootHalI2cBusHandle* handle,
    const uint8_t address,
    uint8_t* data,
    const uint8_t size,
    uint32_t timeout);

/** Perform I2C tx and rx transfers
 *
 * @param      handle   pointer to FuriBootHalI2cBusHandle instance
 * @param      address  I2C slave address
 * @param      tx_data  pointer to tx data buffer
 * @param      tx_size  size of tx data buffer
 * @param      rx_data  pointer to rx data buffer
 * @param      rx_size  size of rx data buffer
 * @param      timeout  timeout in ticks
 *
 * @return     true on successful transfer, false otherwise
 */
bool furi_boot_hal_i2c_trx(
    FuriBootHalI2cBusHandle* handle,
    const uint8_t address,
    const uint8_t* tx_data,
    const uint8_t tx_size,
    uint8_t* rx_data,
    const uint8_t rx_size,
    uint32_t timeout);

/** Perform I2C device register read (8-bit)
 *
 * @param      handle   pointer to FuriBootHalI2cBusHandle instance
 * @param      i2c_addr I2C slave address
 * @param      reg_addr register address
 * @param      data     pointer to register value
 * @param      timeout  timeout in ticks
 *
 * @return     true on successful transfer, false otherwise
 */
bool furi_boot_hal_i2c_read_reg_8(
    FuriBootHalI2cBusHandle* handle,
    uint8_t i2c_addr,
    uint8_t reg_addr,
    uint8_t* data,
    uint32_t timeout);

/** Perform I2C device register read (16-bit)
 *
 * @param      handle   pointer to FuriBootHalI2cBusHandle instance
 * @param      i2c_addr I2C slave address
 * @param      reg_addr register address
 * @param      data     pointer to register value
 * @param      timeout  timeout in ticks
 *
 * @return     true on successful transfer, false otherwise
 */
bool furi_boot_hal_i2c_read_reg_16(
    FuriBootHalI2cBusHandle* handle,
    uint8_t i2c_addr,
    uint8_t reg_addr,
    uint16_t* data,
    uint32_t timeout);

/** Perform I2C device memory read
 *
 * @param      handle   pointer to FuriBootHalI2cBusHandle instance
 * @param      i2c_addr I2C slave address
 * @param      mem_addr memory start address
 * @param      data     pointer to data buffer
 * @param      len      size of data buffer
 * @param      timeout  timeout in ticks
 *
 * @return     true on successful transfer, false otherwise
 */
bool furi_boot_hal_i2c_read_mem(
    FuriBootHalI2cBusHandle* handle,
    uint8_t i2c_addr,
    uint8_t mem_addr,
    uint8_t* data,
    uint8_t len,
    uint32_t timeout);

/** Perform I2C device register write (8-bit)
 *
 * @param      handle   pointer to FuriBootHalI2cBusHandle instance
 * @param      i2c_addr I2C slave address
 * @param      reg_addr register address
 * @param      data     register value
 * @param      timeout  timeout in ticks
 *
 * @return     true on successful transfer, false otherwise
 */
bool furi_boot_hal_i2c_write_reg_8(
    FuriBootHalI2cBusHandle* handle,
    uint8_t i2c_addr,
    uint8_t reg_addr,
    uint8_t data,
    uint32_t timeout);

/** Perform I2C device register write (16-bit)
 *
 * @param      handle   pointer to FuriBootHalI2cBusHandle instance
 * @param      i2c_addr I2C slave address
 * @param      reg_addr register address
 * @param      data     register value
 * @param      timeout  timeout in ticks
 *
 * @return     true on successful transfer, false otherwise
 */
bool furi_boot_hal_i2c_write_reg_16(
    FuriBootHalI2cBusHandle* handle,
    uint8_t i2c_addr,
    uint8_t reg_addr,
    uint16_t data,
    uint32_t timeout);

/** Perform I2C device memory
 *
 * @param      handle   pointer to FuriBootHalI2cBusHandle instance
 * @param      i2c_addr I2C slave address
 * @param      mem_addr memory start address
 * @param      data     pointer to data buffer
 * @param      len      size of data buffer
 * @param      timeout  timeout in ticks
 *
 * @return     true on successful transfer, false otherwise
 */
bool furi_boot_hal_i2c_write_mem(
    FuriBootHalI2cBusHandle* handle,
    uint8_t i2c_addr,
    uint8_t mem_addr,
    uint8_t* data,
    uint8_t len,
    uint32_t timeout);

#ifdef __cplusplus
}
#endif
