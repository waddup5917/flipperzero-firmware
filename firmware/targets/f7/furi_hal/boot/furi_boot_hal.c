#include <furi_boot_hal.h>
#include <stm32wbxx_ll_utils.h>
#include <stm32wbxx_ll_pwr.h>

// Boot to DFU pin
#define BOOT_DFU_PORT GPIOB
#define BOOT_DFU_PIN LL_GPIO_PIN_11
// USB pins
#define BOOT_USB_PORT GPIOA
#define BOOT_USB_DM_PIN LL_GPIO_PIN_11
#define BOOT_USB_DP_PIN LL_GPIO_PIN_12
#define BOOT_USB_PIN (BOOT_USB_DM_PIN | BOOT_USB_DP_PIN)

#define RTC_CLOCK_IS_READY() (LL_RCC_LSE_IsReady() && LL_RCC_LSI1_IsReady())

static void furi_boot_hal_clock_init() {
    LL_Init1msTick(4000000);
    LL_SetSystemCoreClock(4000000);

    LL_AHB2_GRP1_EnableClock(LL_AHB2_GRP1_PERIPH_GPIOA);
    LL_AHB2_GRP1_EnableClock(LL_AHB2_GRP1_PERIPH_GPIOB);
    LL_AHB2_GRP1_EnableClock(LL_AHB2_GRP1_PERIPH_GPIOC);
    LL_AHB2_GRP1_EnableClock(LL_AHB2_GRP1_PERIPH_GPIOD);
    LL_AHB2_GRP1_EnableClock(LL_AHB2_GRP1_PERIPH_GPIOE);
    LL_AHB2_GRP1_EnableClock(LL_AHB2_GRP1_PERIPH_GPIOH);

    LL_APB2_GRP1_EnableClock(LL_APB2_GRP1_PERIPH_SPI1);
    LL_APB1_GRP1_EnableClock(LL_APB1_GRP1_PERIPH_SPI2);
}

static void furi_boot_hal_gpio_pin_init() {
    // USB D+
    LL_GPIO_SetPinMode(BOOT_USB_PORT, BOOT_USB_DP_PIN, LL_GPIO_MODE_OUTPUT);
    LL_GPIO_SetPinSpeed(BOOT_USB_PORT, BOOT_USB_DP_PIN, LL_GPIO_SPEED_FREQ_VERY_HIGH);
    LL_GPIO_SetPinOutputType(BOOT_USB_PORT, BOOT_USB_DP_PIN, LL_GPIO_OUTPUT_OPENDRAIN);
    // USB D-
    LL_GPIO_SetPinMode(BOOT_USB_PORT, BOOT_USB_DM_PIN, LL_GPIO_MODE_OUTPUT);
    LL_GPIO_SetPinSpeed(BOOT_USB_PORT, BOOT_USB_DM_PIN, LL_GPIO_SPEED_FREQ_VERY_HIGH);
    LL_GPIO_SetPinOutputType(BOOT_USB_PORT, BOOT_USB_DM_PIN, LL_GPIO_OUTPUT_OPENDRAIN);
    // Button: back
    LL_GPIO_SetPinMode(BOOT_DFU_PORT, BOOT_DFU_PIN, LL_GPIO_MODE_INPUT);
    LL_GPIO_SetPinPull(BOOT_DFU_PORT, BOOT_DFU_PIN, LL_GPIO_PULL_UP);
}


static void furi_boot_hal_rtc_init() {
    // LSE and RTC
    LL_PWR_EnableBkUpAccess();
    if(!RTC_CLOCK_IS_READY()) {
        // Start LSI1 needed for CSS
        LL_RCC_LSI1_Enable();
        // Try to start LSE normal way
        LL_RCC_LSE_SetDriveCapability(LL_RCC_LSEDRIVE_HIGH);
        LL_RCC_LSE_Enable();
        uint32_t c = 0;
        while(!RTC_CLOCK_IS_READY() && c < 200) {
            LL_mDelay(10);
            c++;
        }
        // Plan B: reset backup domain
        if(!RTC_CLOCK_IS_READY()) {
            //target_led_control("-R.R.R.");
            LL_RCC_ForceBackupDomainReset();
            LL_RCC_ReleaseBackupDomainReset();
            NVIC_SystemReset();
        }
        // Set RTC domain clock to LSE
        LL_RCC_SetRTCClockSource(LL_RCC_RTC_CLKSOURCE_LSE);
        // Enable LSE CSS
        LL_RCC_LSE_EnableCSS();
    }
    // Enable clocking
    LL_RCC_EnableRTC();
    LL_APB1_GRP1_EnableClock(LL_APB1_GRP1_PERIPH_RTCAPB);
}

void furi_boot_hal_init() {
    furi_boot_hal_clock_init();
    furi_boot_hal_gpio_pin_init();

    furi_boot_hal_rtc_init();
    furi_boot_hal_i2c_init();
    furi_boot_hal_light_init();
    furi_boot_hal_spi_init();
}

void furi_boot_hal_delay_ms(float milliseconds) {
    LL_mDelay((uint32_t)milliseconds);
}

void furi_boot_hal_delay_us(float microseconds) {
    microseconds = microseconds / 1000;
    if(microseconds < 1) {
        microseconds = 1;
    }
    LL_mDelay((uint32_t)microseconds);
}