#include <furi_boot_hal_spi_config.h>
#include <furi_boot_hal_resources.h>

/* SPI Presets */

const LL_SPI_InitTypeDef furi_boot_hal_spi_preset_2edge_low_8m = {
    .Mode = LL_SPI_MODE_MASTER,
    .TransferDirection = LL_SPI_FULL_DUPLEX,
    .DataWidth = LL_SPI_DATAWIDTH_8BIT,
    .ClockPolarity = LL_SPI_POLARITY_LOW,
    .ClockPhase = LL_SPI_PHASE_2EDGE,
    .NSS = LL_SPI_NSS_SOFT,
    .BaudRate = LL_SPI_BAUDRATEPRESCALER_DIV8,
    .BitOrder = LL_SPI_MSB_FIRST,
    .CRCCalculation = LL_SPI_CRCCALCULATION_DISABLE,
    .CRCPoly = 7,
};

const LL_SPI_InitTypeDef furi_boot_hal_spi_preset_1edge_low_8m = {
    .Mode = LL_SPI_MODE_MASTER,
    .TransferDirection = LL_SPI_FULL_DUPLEX,
    .DataWidth = LL_SPI_DATAWIDTH_8BIT,
    .ClockPolarity = LL_SPI_POLARITY_LOW,
    .ClockPhase = LL_SPI_PHASE_1EDGE,
    .NSS = LL_SPI_NSS_SOFT,
    .BaudRate = LL_SPI_BAUDRATEPRESCALER_DIV8,
    .BitOrder = LL_SPI_MSB_FIRST,
    .CRCCalculation = LL_SPI_CRCCALCULATION_DISABLE,
    .CRCPoly = 7,
};

const LL_SPI_InitTypeDef furi_boot_hal_spi_preset_1edge_low_4m = {
    .Mode = LL_SPI_MODE_MASTER,
    .TransferDirection = LL_SPI_FULL_DUPLEX,
    .DataWidth = LL_SPI_DATAWIDTH_8BIT,
    .ClockPolarity = LL_SPI_POLARITY_LOW,
    .ClockPhase = LL_SPI_PHASE_1EDGE,
    .NSS = LL_SPI_NSS_SOFT,
    .BaudRate = LL_SPI_BAUDRATEPRESCALER_DIV16,
    .BitOrder = LL_SPI_MSB_FIRST,
    .CRCCalculation = LL_SPI_CRCCALCULATION_DISABLE,
    .CRCPoly = 7,
};

const LL_SPI_InitTypeDef furi_boot_hal_spi_preset_1edge_low_16m = {
    .Mode = LL_SPI_MODE_MASTER,
    .TransferDirection = LL_SPI_FULL_DUPLEX,
    .DataWidth = LL_SPI_DATAWIDTH_8BIT,
    .ClockPolarity = LL_SPI_POLARITY_LOW,
    .ClockPhase = LL_SPI_PHASE_1EDGE,
    .NSS = LL_SPI_NSS_SOFT,
    .BaudRate = LL_SPI_BAUDRATEPRESCALER_DIV2,
    .BitOrder = LL_SPI_MSB_FIRST,
    .CRCCalculation = LL_SPI_CRCCALCULATION_DISABLE,
    .CRCPoly = 7,
};

const LL_SPI_InitTypeDef furi_boot_hal_spi_preset_1edge_low_2m = {
    .Mode = LL_SPI_MODE_MASTER,
    .TransferDirection = LL_SPI_FULL_DUPLEX,
    .DataWidth = LL_SPI_DATAWIDTH_8BIT,
    .ClockPolarity = LL_SPI_POLARITY_LOW,
    .ClockPhase = LL_SPI_PHASE_1EDGE,
    .NSS = LL_SPI_NSS_SOFT,
    .BaudRate = LL_SPI_BAUDRATEPRESCALER_DIV32,
    .BitOrder = LL_SPI_MSB_FIRST,
    .CRCCalculation = LL_SPI_CRCCALCULATION_DISABLE,
    .CRCPoly = 7,
};

/* SPI Buses */

static void furi_boot_hal_spi_bus_r_event_callback(FuriBootHalSpiBus* bus, FuriBootHalSpiBusEvent event) {
    if(event == FuriBootHalSpiBusEventInit) {
        LL_APB2_GRP1_EnableClock(LL_APB2_GRP1_PERIPH_SPI1);
        LL_APB2_GRP1_ForceReset(LL_APB2_GRP1_PERIPH_SPI1);
        bus->current_handle = NULL;
    } else if(event == FuriBootHalSpiBusEventDeinit) {
    } else if(event == FuriBootHalSpiBusEventLock) {
    } else if(event == FuriBootHalSpiBusEventUnlock) {
    } else if(event == FuriBootHalSpiBusEventActivate) {
        LL_APB2_GRP1_ReleaseReset(LL_APB2_GRP1_PERIPH_SPI1);
    } else if(event == FuriBootHalSpiBusEventDeactivate) {
        LL_APB2_GRP1_ForceReset(LL_APB2_GRP1_PERIPH_SPI1);
    }
}

FuriBootHalSpiBus furi_boot_hal_spi_bus_r = {
    .spi = SPI1,
    .callback = furi_boot_hal_spi_bus_r_event_callback,
};

static void furi_boot_hal_spi_bus_d_event_callback(FuriBootHalSpiBus* bus, FuriBootHalSpiBusEvent event) {
    if(event == FuriBootHalSpiBusEventInit) {
        LL_APB1_GRP1_EnableClock(LL_APB1_GRP1_PERIPH_SPI2);
        LL_APB1_GRP1_ForceReset(LL_APB1_GRP1_PERIPH_SPI2);
        bus->current_handle = NULL;
    } else if(event == FuriBootHalSpiBusEventDeinit) {
    } else if(event == FuriBootHalSpiBusEventLock) {
    } else if(event == FuriBootHalSpiBusEventUnlock) {
    } else if(event == FuriBootHalSpiBusEventActivate) {
        LL_APB1_GRP1_ReleaseReset(LL_APB1_GRP1_PERIPH_SPI2);
    } else if(event == FuriBootHalSpiBusEventDeactivate) {
        LL_APB1_GRP1_ForceReset(LL_APB1_GRP1_PERIPH_SPI2);
    }
}

FuriBootHalSpiBus furi_boot_hal_spi_bus_d = {
    .spi = SPI2,
    .callback = furi_boot_hal_spi_bus_d_event_callback,
};

/* SPI Bus Handles */

inline static void furi_boot_hal_spi_bus_r_handle_event_callback(
    FuriBootHalSpiBusHandle* handle,
    FuriBootHalSpiBusHandleEvent event,
    const LL_SPI_InitTypeDef* preset) {
    if(event == FuriBootHalSpiBusHandleEventInit) {
        furi_boot_hal_gpio_write(handle->cs, true);
        furi_boot_hal_gpio_init(handle->cs, BootGpioModeOutputPushPull, BootGpioPullNo, BootGpioSpeedVeryHigh);
    } else if(event == FuriBootHalSpiBusHandleEventDeinit) {
        furi_boot_hal_gpio_write(handle->cs, true);
        furi_boot_hal_gpio_init(handle->cs, BootGpioModeAnalog, BootGpioPullNo, BootGpioSpeedLow);
    } else if(event == FuriBootHalSpiBusHandleEventActivate) {
        LL_SPI_Init(handle->bus->spi, (LL_SPI_InitTypeDef*)preset);
        LL_SPI_SetRxFIFOThreshold(handle->bus->spi, LL_SPI_RX_FIFO_TH_QUARTER);
        LL_SPI_Enable(handle->bus->spi);

        furi_boot_hal_gpio_init_ex(
            handle->miso,
            BootGpioModeAltFunctionPushPull,
            BootGpioPullNo,
            BootGpioSpeedVeryHigh,
            BootGpioAltFn5SPI1);
        furi_boot_hal_gpio_init_ex(
            handle->mosi,
            BootGpioModeAltFunctionPushPull,
            BootGpioPullNo,
            BootGpioSpeedVeryHigh,
            BootGpioAltFn5SPI1);
        furi_boot_hal_gpio_init_ex(
            handle->sck,
            BootGpioModeAltFunctionPushPull,
            BootGpioPullNo,
            BootGpioSpeedVeryHigh,
            BootGpioAltFn5SPI1);

        furi_boot_hal_gpio_write(handle->cs, false);
    } else if(event == FuriBootHalSpiBusHandleEventDeactivate) {
        furi_boot_hal_gpio_write(handle->cs, true);

        furi_boot_hal_gpio_init(handle->miso, BootGpioModeAnalog, BootGpioPullNo, BootGpioSpeedLow);
        furi_boot_hal_gpio_init(handle->mosi, BootGpioModeAnalog, BootGpioPullNo, BootGpioSpeedLow);
        furi_boot_hal_gpio_init(handle->sck, BootGpioModeAnalog, BootGpioPullNo, BootGpioSpeedLow);

        LL_SPI_Disable(handle->bus->spi);
    }
}

static void furi_boot_hal_spi_bus_handle_subghz_event_callback(
    FuriBootHalSpiBusHandle* handle,
    FuriBootHalSpiBusHandleEvent event) {
    furi_boot_hal_spi_bus_r_handle_event_callback(handle, event, &furi_boot_hal_spi_preset_1edge_low_8m);
}

FuriBootHalSpiBusHandle furi_boot_hal_spi_bus_handle_subghz = {
    .bus = &furi_boot_hal_spi_bus_r,
    .callback = furi_boot_hal_spi_bus_handle_subghz_event_callback,
    .miso = &boot_gpio_spi_r_miso,
    .mosi = &boot_gpio_spi_r_mosi,
    .sck = &boot_gpio_spi_r_sck,
    .cs = &boot_gpio_subghz_cs,
};

static void furi_boot_hal_spi_bus_handle_nfc_event_callback(
    FuriBootHalSpiBusHandle* handle,
    FuriBootHalSpiBusHandleEvent event) {
    furi_boot_hal_spi_bus_r_handle_event_callback(handle, event, &furi_boot_hal_spi_preset_2edge_low_8m);
}

FuriBootHalSpiBusHandle furi_boot_hal_spi_bus_handle_nfc = {
    .bus = &furi_boot_hal_spi_bus_r,
    .callback = furi_boot_hal_spi_bus_handle_nfc_event_callback,
    .miso = &boot_gpio_spi_r_miso,
    .mosi = &boot_gpio_spi_r_mosi,
    .sck = &boot_gpio_spi_r_sck,
    .cs = &boot_gpio_nfc_cs,
};

static void furi_boot_hal_spi_bus_handle_external_event_callback(
    FuriBootHalSpiBusHandle* handle,
    FuriBootHalSpiBusHandleEvent event) {
    furi_boot_hal_spi_bus_r_handle_event_callback(handle, event, &furi_boot_hal_spi_preset_1edge_low_2m);
}

FuriBootHalSpiBusHandle furi_boot_hal_spi_bus_handle_external = {
    .bus = &furi_boot_hal_spi_bus_r,
    .callback = furi_boot_hal_spi_bus_handle_external_event_callback,
    .miso = &boot_gpio_ext_pa6,
    .mosi = &boot_gpio_ext_pa7,
    .sck = &boot_gpio_ext_pb3,
    .cs = &boot_gpio_ext_pa4,
};

inline static void furi_boot_hal_spi_bus_d_handle_event_callback(
    FuriBootHalSpiBusHandle* handle,
    FuriBootHalSpiBusHandleEvent event,
    const LL_SPI_InitTypeDef* preset) {
    if(event == FuriBootHalSpiBusHandleEventInit) {
        furi_boot_hal_gpio_write(handle->cs, true);
        furi_boot_hal_gpio_init(handle->cs, BootGpioModeOutputPushPull, BootGpioPullUp, BootGpioSpeedVeryHigh);

        furi_boot_hal_gpio_init_ex(
            handle->miso,
            BootGpioModeAltFunctionPushPull,
            BootGpioPullNo,
            BootGpioSpeedVeryHigh,
            BootGpioAltFn5SPI2);
        furi_boot_hal_gpio_init_ex(
            handle->mosi,
            BootGpioModeAltFunctionPushPull,
            BootGpioPullNo,
            BootGpioSpeedVeryHigh,
            BootGpioAltFn5SPI2);
        furi_boot_hal_gpio_init_ex(
            handle->sck,
            BootGpioModeAltFunctionPushPull,
            BootGpioPullNo,
            BootGpioSpeedVeryHigh,
            BootGpioAltFn5SPI2);

    } else if(event == FuriBootHalSpiBusHandleEventDeinit) {
        furi_boot_hal_gpio_write(handle->cs, true);
        furi_boot_hal_gpio_init(handle->cs, BootGpioModeAnalog, BootGpioPullUp, BootGpioSpeedLow);
    } else if(event == FuriBootHalSpiBusHandleEventActivate) {
        LL_SPI_Init(handle->bus->spi, (LL_SPI_InitTypeDef*)preset);
        LL_SPI_SetRxFIFOThreshold(handle->bus->spi, LL_SPI_RX_FIFO_TH_QUARTER);
        LL_SPI_Enable(handle->bus->spi);
        furi_boot_hal_gpio_write(handle->cs, false);
    } else if(event == FuriBootHalSpiBusHandleEventDeactivate) {
        furi_boot_hal_gpio_write(handle->cs, true);
        LL_SPI_Disable(handle->bus->spi);
    }
}

static void furi_boot_hal_spi_bus_handle_display_event_callback(
    FuriBootHalSpiBusHandle* handle,
    FuriBootHalSpiBusHandleEvent event) {
    furi_boot_hal_spi_bus_d_handle_event_callback(handle, event, &furi_boot_hal_spi_preset_1edge_low_4m);
}

FuriBootHalSpiBusHandle furi_boot_hal_spi_bus_handle_display = {
    .bus = &furi_boot_hal_spi_bus_d,
    .callback = furi_boot_hal_spi_bus_handle_display_event_callback,
    .miso = &boot_gpio_spi_d_miso,
    .mosi = &boot_gpio_spi_d_mosi,
    .sck = &boot_gpio_spi_d_sck,
    .cs = &boot_gpio_display_cs,
};

static void furi_boot_hal_spi_bus_handle_sd_fast_event_callback(
    FuriBootHalSpiBusHandle* handle,
    FuriBootHalSpiBusHandleEvent event) {
    furi_boot_hal_spi_bus_d_handle_event_callback(handle, event, &furi_boot_hal_spi_preset_1edge_low_16m);
}

FuriBootHalSpiBusHandle furi_boot_hal_spi_bus_handle_sd_fast = {
    .bus = &furi_boot_hal_spi_bus_d,
    .callback = furi_boot_hal_spi_bus_handle_sd_fast_event_callback,
    .miso = &boot_gpio_spi_d_miso,
    .mosi = &boot_gpio_spi_d_mosi,
    .sck = &boot_gpio_spi_d_sck,
    .cs = &boot_gpio_sdcard_cs,
};

static void furi_boot_hal_spi_bus_handle_sd_slow_event_callback(
    FuriBootHalSpiBusHandle* handle,
    FuriBootHalSpiBusHandleEvent event) {
    furi_boot_hal_spi_bus_d_handle_event_callback(handle, event, &furi_boot_hal_spi_preset_1edge_low_2m);
}

FuriBootHalSpiBusHandle furi_boot_hal_spi_bus_handle_sd_slow = {
    .bus = &furi_boot_hal_spi_bus_d,
    .callback = furi_boot_hal_spi_bus_handle_sd_slow_event_callback,
    .miso = &boot_gpio_spi_d_miso,
    .mosi = &boot_gpio_spi_d_mosi,
    .sck = &boot_gpio_spi_d_sck,
    .cs = &boot_gpio_sdcard_cs,
};
