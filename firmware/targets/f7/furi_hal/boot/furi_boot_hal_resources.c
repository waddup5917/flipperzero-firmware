#include "furi_boot_hal_resources.h"

const BootGpioPin boot_vibro_gpio = {.port = BOOT_VIBRO_GPIO_Port, .pin = BOOT_VIBRO_Pin};
const BootGpioPin boot_ibutton_gpio = {.port = BOOT_iBTN_GPIO_Port, .pin = BOOT_iBTN_Pin};

const BootGpioPin boot_gpio_cc1101_g0 = {.port = BOOT_CC1101_G0_GPIO_Port, .pin = BOOT_CC1101_G0_Pin};
const BootGpioPin boot_gpio_rf_sw_0 = {.port = BOOT_RF_SW_0_GPIO_Port, .pin = BOOT_RF_SW_0_Pin};

const BootGpioPin boot_gpio_subghz_cs = {.port = BOOT_CC1101_CS_GPIO_Port, .pin = BOOT_CC1101_CS_Pin};
const BootGpioPin boot_gpio_display_cs = {.port = BOOT_DISPLAY_CS_GPIO_Port, .pin = BOOT_DISPLAY_CS_Pin};
const BootGpioPin boot_gpio_display_rst = {.port = BOOT_DISPLAY_RST_GPIO_Port, .pin = BOOT_DISPLAY_RST_Pin};
const BootGpioPin boot_gpio_display_di = {.port = BOOT_DISPLAY_DI_GPIO_Port, .pin = BOOT_DISPLAY_DI_Pin};
const BootGpioPin boot_gpio_sdcard_cs = {.port = BOOT_SD_CS_GPIO_Port, .pin = BOOT_SD_CS_Pin};
const BootGpioPin boot_gpio_nfc_cs = {.port = BOOT_NFC_CS_GPIO_Port, .pin = BOOT_NFC_CS_Pin};

const BootGpioPin boot_gpio_spi_d_miso = {.port = BOOT_SPI_D_MISO_GPIO_Port, .pin = BOOT_SPI_D_MISO_Pin};
const BootGpioPin boot_gpio_spi_d_mosi = {.port = BOOT_SPI_D_MOSI_GPIO_Port, .pin = BOOT_SPI_D_MOSI_Pin};
const BootGpioPin boot_gpio_spi_d_sck = {.port = BOOT_SPI_D_SCK_GPIO_Port, .pin = BOOT_SPI_D_SCK_Pin};
const BootGpioPin boot_gpio_spi_r_miso = {.port = BOOT_SPI_R_MISO_GPIO_Port, .pin = BOOT_SPI_R_MISO_Pin};
const BootGpioPin boot_gpio_spi_r_mosi = {.port = BOOT_SPI_R_MOSI_GPIO_Port, .pin = BOOT_SPI_R_MOSI_Pin};
const BootGpioPin boot_gpio_spi_r_sck = {.port = BOOT_SPI_R_SCK_GPIO_Port, .pin = BOOT_SPI_R_SCK_Pin};

const BootGpioPin boot_gpio_ext_pc0 = {.port = GPIOC, .pin = LL_GPIO_PIN_0};
const BootGpioPin boot_gpio_ext_pc1 = {.port = GPIOC, .pin = LL_GPIO_PIN_1};
const BootGpioPin boot_gpio_ext_pc3 = {.port = GPIOC, .pin = LL_GPIO_PIN_3};
const BootGpioPin boot_gpio_ext_pb2 = {.port = GPIOB, .pin = LL_GPIO_PIN_2};
const BootGpioPin boot_gpio_ext_pb3 = {.port = GPIOB, .pin = LL_GPIO_PIN_3};
const BootGpioPin boot_gpio_ext_pa4 = {.port = GPIOA, .pin = LL_GPIO_PIN_4};
const BootGpioPin boot_gpio_ext_pa6 = {.port = GPIOA, .pin = LL_GPIO_PIN_6};
const BootGpioPin boot_gpio_ext_pa7 = {.port = GPIOA, .pin = LL_GPIO_PIN_7};

const BootGpioPin boot_gpio_rfid_pull = {.port = BOOT_RFID_PULL_GPIO_Port, .pin = BOOT_RFID_PULL_Pin};
const BootGpioPin boot_gpio_rfid_carrier_out = {.port = BOOT_RFID_OUT_GPIO_Port, .pin = BOOT_RFID_OUT_Pin};
const BootGpioPin boot_gpio_rfid_data_in = {.port = BOOT_RFID_RF_IN_GPIO_Port, .pin = BOOT_RFID_RF_IN_Pin};

const BootGpioPin boot_gpio_infrared_rx = {.port = BOOT_IR_RX_GPIO_Port, .pin = BOOT_IR_RX_Pin};
const BootGpioPin boot_gpio_infrared_tx = {.port = BOOT_IR_TX_GPIO_Port, .pin = BOOT_IR_TX_Pin};

const BootGpioPin boot_gpio_usart_tx = {.port = BOOT_USART1_TX_Port, .pin = BOOT_USART1_TX_Pin};
const BootGpioPin boot_gpio_usart_rx = {.port = BOOT_USART1_RX_Port, .pin = BOOT_USART1_RX_Pin};

const BootGpioPin boot_gpio_i2c_power_sda = {.port = GPIOA, .pin = LL_GPIO_PIN_10};
const BootGpioPin boot_gpio_i2c_power_scl = {.port = GPIOA, .pin = LL_GPIO_PIN_9};
