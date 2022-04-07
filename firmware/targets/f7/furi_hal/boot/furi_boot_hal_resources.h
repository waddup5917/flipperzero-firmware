#pragma once

#include <stm32wbxx.h>
#include <stm32wbxx_ll_gpio.h>
#include <furi_boot_hal_gpio.h>

#ifdef __cplusplus
extern "C" {
#endif

/* BootInput Keys */
typedef enum {
    BootInputKeyUp,
    BootInputKeyDown,
    BootInputKeyRight,
    BootInputKeyLeft,
    BootInputKeyOk,
    BootInputKeyBack,
} BootInputKey;

/* BootLight */
typedef enum {
    BootLightRed,
    BootLightGreen,
    BootLightBlue,
    BootLightBacklight,
} BootLight;

extern const BootGpioPin boot_vibro_gpio;
extern const BootGpioPin boot_ibutton_gpio;

extern const BootGpioPin boot_gpio_cc1101_g0;
extern const BootGpioPin boot_gpio_rf_sw_0;

extern const BootGpioPin boot_gpio_subghz_cs;
extern const BootGpioPin boot_gpio_display_cs;
extern const BootGpioPin boot_gpio_display_rst;
extern const BootGpioPin boot_gpio_display_di;
extern const BootGpioPin boot_gpio_sdcard_cs;
extern const BootGpioPin boot_gpio_nfc_cs;

extern const BootGpioPin boot_gpio_spi_d_miso;
extern const BootGpioPin boot_gpio_spi_d_mosi;
extern const BootGpioPin boot_gpio_spi_d_sck;
extern const BootGpioPin boot_gpio_spi_r_miso;
extern const BootGpioPin boot_gpio_spi_r_mosi;
extern const BootGpioPin boot_gpio_spi_r_sck;

extern const BootGpioPin boot_gpio_ext_pc0;
extern const BootGpioPin boot_gpio_ext_pc1;
extern const BootGpioPin boot_gpio_ext_pc3;
extern const BootGpioPin boot_gpio_ext_pb2;
extern const BootGpioPin boot_gpio_ext_pb3;
extern const BootGpioPin boot_gpio_ext_pa4;
extern const BootGpioPin boot_gpio_ext_pa6;
extern const BootGpioPin boot_gpio_ext_pa7;

extern const BootGpioPin boot_gpio_rfid_pull;
extern const BootGpioPin boot_gpio_rfid_carrier_out;
extern const BootGpioPin boot_gpio_rfid_data_in;

extern const BootGpioPin boot_gpio_infrared_rx;
extern const BootGpioPin boot_gpio_infrared_tx;

extern const BootGpioPin boot_gpio_usart_tx;
extern const BootGpioPin boot_gpio_usart_rx;

extern const BootGpioPin boot_gpio_i2c_power_sda;
extern const BootGpioPin boot_gpio_i2c_power_scl;

#ifdef __cplusplus
}
#endif
