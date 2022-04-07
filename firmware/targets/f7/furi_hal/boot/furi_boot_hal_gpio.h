#pragma once
#include "stdbool.h"
#include "hardware_mapping.h"
#include <stm32wbxx_ll_gpio.h>
#include <stm32wbxx_ll_system.h>
#include <stm32wbxx_ll_exti.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 * Number of gpio on one port
 */
#define GPIO_NUMBER (16U)

/**
 * Interrupt callback prototype
 */
typedef void (*BootGpioExtiCallback)(void* ctx);

/**
 * BootGpio interrupt type
 */
typedef struct {
    BootGpioExtiCallback callback;
    void* context;
    volatile bool ready;
} BootGpioInterrupt;

/**
 * BootGpio modes
 */
typedef enum {
    BootGpioModeInput,
    BootGpioModeOutputPushPull,
    BootGpioModeOutputOpenDrain,
    BootGpioModeAltFunctionPushPull,
    BootGpioModeAltFunctionOpenDrain,
    BootGpioModeAnalog,
    BootGpioModeInterruptRise,
    BootGpioModeInterruptFall,
    BootGpioModeInterruptRiseFall,
    BootGpioModeEventRise,
    BootGpioModeEventFall,
    BootGpioModeEventRiseFall,
} BootGpioMode;

/**
 * BootGpio pull modes
 */
typedef enum {
    BootGpioPullNo,
    BootGpioPullUp,
    BootGpioPullDown,
} BootGpioPull;

/**
 * BootGpio speed modes
 */
typedef enum {
    BootGpioSpeedLow,
    BootGpioSpeedMedium,
    BootGpioSpeedHigh,
    BootGpioSpeedVeryHigh,
} BootGpioSpeed;

/**
 * BootGpio alternate functions
 */
typedef enum {
    BootGpioAltFn0MCO = 0, /*!< MCO Alternate Function mapping */
    BootGpioAltFn0LSCO = 0, /*!< LSCO Alternate Function mapping */
    BootGpioAltFn0JTMS_SWDIO = 0, /*!< JTMS-SWDIO Alternate Function mapping */
    BootGpioAltFn0JTCK_SWCLK = 0, /*!< JTCK-SWCLK Alternate Function mapping */
    BootGpioAltFn0JTDI = 0, /*!< JTDI Alternate Function mapping */
    BootGpioAltFn0RTC_OUT = 0, /*!< RCT_OUT Alternate Function mapping */
    BootGpioAltFn0JTD_TRACE = 0, /*!< JTDO-TRACESWO Alternate Function mapping */
    BootGpioAltFn0NJTRST = 0, /*!< NJTRST Alternate Function mapping */
    BootGpioAltFn0RTC_REFIN = 0, /*!< RTC_REFIN Alternate Function mapping */
    BootGpioAltFn0TRACED0 = 0, /*!< TRACED0 Alternate Function mapping */
    BootGpioAltFn0TRACED1 = 0, /*!< TRACED1 Alternate Function mapping */
    BootGpioAltFn0TRACED2 = 0, /*!< TRACED2 Alternate Function mapping */
    BootGpioAltFn0TRACED3 = 0, /*!< TRACED3 Alternate Function mapping */
    BootGpioAltFn0TRIG_INOUT = 0, /*!< TRIG_INOUT Alternate Function mapping */
    BootGpioAltFn0TRACECK = 0, /*!< TRACECK Alternate Function mapping */
    BootGpioAltFn0SYS = 0, /*!< System Function mapping */

    BootGpioAltFn1TIM1 = 1, /*!< TIM1 Alternate Function mapping */
    BootGpioAltFn1TIM2 = 1, /*!< TIM2 Alternate Function mapping */
    BootGpioAltFn1LPTIM1 = 1, /*!< LPTIM1 Alternate Function mapping */

    BootGpioAltFn2TIM2 = 2, /*!< TIM2 Alternate Function mapping */
    BootGpioAltFn2TIM1 = 2, /*!< TIM1 Alternate Function mapping */

    BootGpioAltFn3SAI1 = 3, /*!< SAI1_CK1 Alternate Function mapping */
    BootGpioAltFn3SPI2 = 3, /*!< SPI2 Alternate Function mapping */
    BootGpioAltFn3TIM1 = 3, /*!< TIM1 Alternate Function mapping */

    BootGpioAltFn4I2C1 = 4, /*!< I2C1 Alternate Function mapping */
    BootGpioAltFn4I2C3 = 4, /*!< I2C3 Alternate Function mapping */

    BootGpioAltFn5SPI1 = 5, /*!< SPI1 Alternate Function mapping */
    BootGpioAltFn5SPI2 = 5, /*!< SPI2 Alternate Function mapping */

    BootGpioAltFn6MCO = 6, /*!< MCO Alternate Function mapping */
    BootGpioAltFn6LSCO = 6, /*!< LSCO Alternate Function mapping */
    BootGpioAltFn6RF_DTB0 = 6, /*!< RF_DTB0 Alternate Function mapping */
    BootGpioAltFn6RF_DTB1 = 6, /*!< RF_DTB1 Alternate Function mapping */
    BootGpioAltFn6RF_DTB2 = 6, /*!< RF_DTB2 Alternate Function mapping */
    BootGpioAltFn6RF_DTB3 = 6, /*!< RF_DTB3 Alternate Function mapping */
    BootGpioAltFn6RF_DTB4 = 6, /*!< RF_DTB4 Alternate Function mapping */
    BootGpioAltFn6RF_DTB5 = 6, /*!< RF_DTB5 Alternate Function mapping */
    BootGpioAltFn6RF_DTB6 = 6, /*!< RF_DTB6 Alternate Function mapping */
    BootGpioAltFn6RF_DTB7 = 6, /*!< RF_DTB7 Alternate Function mapping */
    BootGpioAltFn6RF_DTB8 = 6, /*!< RF_DTB8 Alternate Function mapping */
    BootGpioAltFn6RF_DTB9 = 6, /*!< RF_DTB9 Alternate Function mapping */
    BootGpioAltFn6RF_DTB10 = 6, /*!< RF_DTB10 Alternate Function mapping */
    BootGpioAltFn6RF_DTB11 = 6, /*!< RF_DTB11 Alternate Function mapping */
    BootGpioAltFn6RF_DTB12 = 6, /*!< RF_DTB12 Alternate Function mapping */
    BootGpioAltFn6RF_DTB13 = 6, /*!< RF_DTB13 Alternate Function mapping */
    BootGpioAltFn6RF_DTB14 = 6, /*!< RF_DTB14 Alternate Function mapping */
    BootGpioAltFn6RF_DTB15 = 6, /*!< RF_DTB15 Alternate Function mapping */
    BootGpioAltFn6RF_DTB16 = 6, /*!< RF_DTB16 Alternate Function mapping */
    BootGpioAltFn6RF_DTB17 = 6, /*!< RF_DTB17 Alternate Function mapping */
    BootGpioAltFn6RF_DTB18 = 6, /*!< RF_DTB18 Alternate Function mapping */
    BootGpioAltFn6RF_MISO = 6, /*!< RF_MISO Alternate Function mapping */
    BootGpioAltFn6RF_MOSI = 6, /*!< RF_MOSI Alternate Function mapping */
    BootGpioAltFn6RF_SCK = 6, /*!< RF_SCK Alternate Function mapping */
    BootGpioAltFn6RF_NSS = 6, /*!< RF_NSS Alternate Function mapping */

    BootGpioAltFn7USART1 = 7, /*!< USART1 Alternate Function mapping */

    BootGpioAltFn8LPUART1 = 8, /*!< LPUART1 Alternate Function mapping */
    BootGpioAltFn8IR = 8, /*!< IR Alternate Function mapping */

    BootGpioAltFn9TSC = 9, /*!< TSC Alternate Function mapping */

    BootGpioAltFn10QUADSPI = 10, /*!< QUADSPI Alternate Function mapping */
    BootGpioAltFn10USB = 10, /*!< USB Alternate Function mapping */

    BootGpioAltFn11LCD = 11, /*!< LCD Alternate Function mapping */

    BootGpioAltFn12COMP1 = 12, /*!< COMP1 Alternate Function mapping */
    BootGpioAltFn12COMP2 = 12, /*!< COMP2 Alternate Function mapping */
    BootGpioAltFn12TIM1 = 12, /*!< TIM1 Alternate Function mapping */

    BootGpioAltFn13SAI1 = 13, /*!< SAI1 Alternate Function mapping */

    BootGpioAltFn14TIM2 = 14, /*!< TIM2 Alternate Function mapping */
    BootGpioAltFn14TIM16 = 14, /*!< TIM16 Alternate Function mapping */
    BootGpioAltFn14TIM17 = 14, /*!< TIM17 Alternate Function mapping */
    BootGpioAltFn14LPTIM2 = 14, /*!< LPTIM2 Alternate Function mapping */

    BootGpioAltFn15EVENTOUT = 15, /*!< EVENTOUT Alternate Function mapping */

    BootGpioAltFnUnused = 16, /*!< just dummy value */
} BootGpioAltFn;

/**
 * BootGpio structure
 */
typedef struct {
    GPIO_TypeDef* port;
    uint16_t pin;
} BootGpioPin;

/**
 * GPIO initialization function, simple version
 * @param gpio  BootGpioPin
 * @param mode  BootGpioMode
 */
void furi_boot_hal_gpio_init_simple(const BootGpioPin* gpio, const BootGpioMode mode);

/**
 * GPIO initialization function, normal version
 * @param gpio  BootGpioPin
 * @param mode  BootGpioMode
 * @param pull  BootGpioPull
 * @param speed BootGpioSpeed
 */
void furi_boot_hal_gpio_init(
    const BootGpioPin* gpio,
    const BootGpioMode mode,
    const BootGpioPull pull,
    const BootGpioSpeed speed);

/**
 * GPIO initialization function, extended version
 * @param gpio  BootGpioPin
 * @param mode  BootGpioMode
 * @param pull  BootGpioPull
 * @param speed BootGpioSpeed
 * @param alt_fn BootGpioAltFn
 */
void furi_boot_hal_gpio_init_ex(
    const BootGpioPin* gpio,
    const BootGpioMode mode,
    const BootGpioPull pull,
    const BootGpioSpeed speed,
    const BootGpioAltFn alt_fn);

/**
 * Add and enable interrupt
 * @param gpio BootGpioPin
 * @param cb   BootGpioExtiCallback
 * @param ctx  context for callback
 */
void furi_boot_hal_gpio_add_int_callback(const BootGpioPin* gpio, BootGpioExtiCallback cb, void* ctx);

/**
 * Enable interrupt
 * @param gpio BootGpioPin
 */
void furi_boot_hal_gpio_enable_int_callback(const BootGpioPin* gpio);

/**
 * Disable interrupt
 * @param gpio BootGpioPin
 */
void furi_boot_hal_gpio_disable_int_callback(const BootGpioPin* gpio);

/**
 * Remove interrupt
 * @param gpio BootGpioPin
 */
void furi_boot_hal_gpio_remove_int_callback(const BootGpioPin* gpio);

/**
 * GPIO write pin
 * @param gpio  BootGpioPin
 * @param state true / false
 */
static inline void furi_boot_hal_gpio_write(const BootGpioPin* gpio, const bool state) {
    // writing to BSSR is an atomic operation
    if(state == true) {
        gpio->port->BSRR = gpio->pin;
    } else {
        gpio->port->BSRR = (uint32_t)gpio->pin << GPIO_NUMBER;
    }
}

/**
 * GPIO read pin
 * @param gpio BootGpioPin
 * @return true / false
 */
static inline bool furi_boot_hal_gpio_read(const BootGpioPin* gpio) {
    if((gpio->port->IDR & gpio->pin) != 0x00U) {
        return true;
    } else {
        return false;
    }
}

/**
 * Get RFID IN level
 * @return false = LOW, true = HIGH
 */
bool furi_boot_hal_gpio_get_rfid_in_level();

#ifdef __cplusplus
}
#endif
