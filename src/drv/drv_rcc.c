#include "drv_rcc.h"
#include "drv_common.h"
#include "drv_flash.h"




bool rcc_pll_is_locked(void) {
    return Read_register_field(RCC->CR, RCC_CR_PLLRDY)
}

void rcc_enable_pll(void) {
    Set_register_bit(RCC->CR, RCC_CR_PLLON)
}

void rcc_disable_pll(void) {
    Clear_register_bit(RCC->CR, RCC_CR_PLLON)
}


void rcc_enable_css(void) {
    Set_register_bit(RCC->CR, RCC_CR_CSSON)
}

void rcc_disable_css(void) {
    Clear_register_bit(RCC->CR, RCC_CR_CSSON)
}

void rcc_enable_hsebypass(void) {
    Set_register_bit(RCC->CR, RCC_CR_HSEBYP)
}

void rcc_disable_hsebypass(void) {
    Clear_register_bit(RCC->CR, RCC_CR_HSEBYP)
}

bool rcc_hse_is_ready(void) {
    return RCC->CR & RCC_CR_HSERDY;
}

void rcc_enable_hse(void) {
    Set_register_bit(RCC->CR, RCC_CR_HSEON)
}

void rcc_disable_hse(void) {
    Clear_register_bit(RCC->CR, RCC_CR_HSEON)
}

bool rcc_hsi_is_ready(void) {
    return RCC->CR & RCC_CR_HSIRDY;
}

void rcc_enable_hsi(void) {
    Set_register_bit(RCC->CR, RCC_CR_HSION)
}

void rcc_disable_hsi(void) {
    Clear_register_bit(RCC->CR, RCC_CR_HSION)
}


void rcc_select_mco_output(rcc_mco_output_t output) {
    uint32_t mco = output + 4;
    Write_register_field(RCC->CFGR, RCC_CFGR_MCO, mco)
}

void rcc_set_usb_prescaler(rcc_usb_prescaler_t prescale) {
    Write_register_field(RCC->CFGR, RCC_CFGR_USBPRE, prescale)
}

void rcc_set_pllmul(uint32_t m) {
    m = m - 2;
    Write_register_field(RCC->CFGR, RCC_CFGR_PLLMULL, m)
}

void rcc_set_pll_hse_prescaler(rcc_pll_hse_prescaler_t prescale) {
    Write_register_field(RCC->CFGR, RCC_CFGR_PLLXTPRE, prescale)
}

void rcc_set_pll_source(rcc_pll_source_t source) {
    Write_register_field(RCC->CFGR, RCC_CFGR_PLLSRC, source)
}


void rcc_set_apb2_prescaler(rcc_apb2_prescaler_t prescale) {
    uint32_t ppre2 = prescale ? prescale + 3 : 0;
    Write_register_field(RCC->CFGR, RCC_CFGR_PPRE2, ppre2)
}

void rcc_set_apb1_prescaler(rcc_apb1_prescaler_t prescale) {
    uint32_t ppre1 = prescale ? prescale + 3 : 0;
    Write_register_field(RCC->CFGR, RCC_CFGR_PPRE1, ppre1)
}

void rcc_set_ahb_prescaler(rcc_ahb_prescaler_t prescale) {
    uint32_t ahb = prescale ? prescale + 7 : 0;
    Write_register_field(RCC->CFGR, RCC_CFGR_HPRE, ahb)
}

void rcc_set_adc_prescaler(rcc_adc_prescaler_t prescale) {
    Write_register_field(RCC->CFGR, RCC_CFGR_ADCPRE, prescale)
}

void rcc_set_sysclk_source(rcc_sysclk_source_t source) {
    Write_register_field(RCC->CFGR, RCC_CFGR_SW, source)
}

rcc_sysclk_source_t rcc_get_sysclk_source(void) {
    return Read_register_field(RCC->CFGR, RCC_CFGR_SWS)
}

void rcc_configure_clock(const rcc_clock_config_t *config) {
    rcc_enable_hsi();
    while (!rcc_hsi_is_ready());
    rcc_set_sysclk_source(rcc_sysclk_source_hsi);

    if (config->pll_source == rcc_pll_source_hse) {
        rcc_enable_hse();
        while (!rcc_hse_is_ready());
    }

    rcc_set_ahb_prescaler(config->ahb_prescale);
    rcc_set_apb1_prescaler(config->apb1_prescale);
    rcc_set_apb2_prescaler(config->apb2_prescale);

    if (config->sysclk_source == rcc_sysclk_source_pll) {
        rcc_disable_pll();
        while (rcc_pll_is_locked()); // wait for pll to unlock

        rcc_set_pll_source(config->pll_source);
        rcc_set_pllmul(config->pllm);
        rcc_enable_pll();

        while (!rcc_pll_is_locked());
    }

    // Flash Config
    flash_set_latency(config->flash_latency);

    rcc_set_sysclk_source(config->sysclk_source);

    while (rcc_get_sysclk_source() != config->sysclk_source); 

    if (config->pll_source == rcc_pll_source_hse) {
        rcc_disable_hsi();
    }

    SystemCoreClockUpdate();
}