#pragma once

#include <stdbool.h>
#include <stdint.h>
#include "stm32f1xx.h"

typedef enum {
    rcc_mco_output_disabled,
    rcc_mco_output_sysclk,
    rcc_mco_output_hsi,
    rcc_mco_output_hse,
    rcc_mco_output_pll_div_2,
} __attribute__ ((packed)) rcc_mco_output_t;

typedef enum {
    rcc_usb_prescaler_div_1_5,
    rcc_usb_prescaler_div_1,
} __attribute__ ((packed)) rcc_usb_prescaler_t;

typedef enum {
    rcc_pll_source_hsi_div_2,
    rcc_pll_source_hse,
} __attribute__ ((packed)) rcc_pll_source_t;

typedef enum {
    rcc_pll_hse_prescaler_div_1,
    rcc_pll_hse_prescaler_div_2,
} __attribute__ ((packed)) rcc_pll_hse_prescaler_t;

typedef enum {
    rcc_pll_mul_2,
    rcc_pll_mul_3,
    rcc_pll_mul_4,
    rcc_pll_mul_5,
    rcc_pll_mul_6,
    rcc_pll_mul_7,
    rcc_pll_mul_8,
    rcc_pll_mul_9,
    rcc_pll_mul_10,
    rcc_pll_mul_11,
    rcc_pll_mul_12,
    rcc_pll_mul_13,
    rcc_pll_mul_14,
    rcc_pll_mul_15,
    rcc_pll_mul_16,
} __attribute__ ((packed)) rcc_pll_mul_t;

typedef enum {
    rcc_ahb_prescaler_div_1,
    rcc_ahb_prescaler_div_2,
    rcc_ahb_prescaler_div_4,
    rcc_ahb_prescaler_div_8,
    rcc_ahb_prescaler_div_16,
    rcc_ahb_prescaler_div_64,
    rcc_ahb_prescaler_div_128,
    rcc_ahb_prescaler_div_256,
    rcc_ahb_prescaler_div_512,
} __attribute__ ((packed)) rcc_ahb_prescaler_t;

typedef enum {
    rcc_apb1_prescaler_div_1,
    rcc_apb1_prescaler_div_2,
    rcc_apb1_prescaler_div_4,
    rcc_apb1_prescaler_div_8,
    rcc_apb1_prescaler_div_16,
} __attribute__ ((packed)) rcc_apb1_prescaler_t;

typedef enum {
    rcc_apb2_prescaler_div_1,
    rcc_apb2_prescaler_div_2,
    rcc_apb2_prescaler_div_4,
    rcc_apb2_prescaler_div_8,
    rcc_apb2_prescaler_div_16,
} __attribute__ ((packed)) rcc_apb2_prescaler_t;

typedef enum {
    rcc_sysclk_source_hsi,
    rcc_sysclk_source_hse,
    rcc_sysclk_source_pll,
} __attribute__ ((packed)) rcc_sysclk_source_t;

typedef enum {
    rcc_flash_latency_0,
    rcc_flash_latency_1,
    rcc_flash_latency_2,
    rcc_flash_latency_3,
    rcc_flash_latency_4,
} __attribute__ ((packed)) rcc_flash_latency_t;

typedef enum {
    rcc_mco_source_hsi,
    rcc_mco_source_lse,
    rcc_mco_source_hse,
    rcc_mco_source_pll_div_2,
} __attribute__ ((packed)) rcc_mco_source_t;

typedef enum {
    rcc_mco_prescaler_div_1,
    rcc_mco_prescaler_div_2,
    rcc_mco_prescaler_div_4,
    rcc_mco_prescaler_div_8,
    rcc_mco_prescaler_div_16,
    rcc_mco_prescaler_div_32,
    rcc_mco_prescaler_div_64,
    rcc_mco_prescaler_div_128,
} __attribute__ ((packed)) rcc_mco_prescaler_t;

typedef enum {
    rcc_rtc_clock_source_no_clock,
    rcc_rtc_clock_source_lse,
    rcc_rtc_clock_source_lsi,
    rcc_rtc_clock_source_hse_div_128,
} __attribute__ ((packed)) rcc_rtc_clock_source_t;

typedef enum {
    rcc_adc_prescaler_div_2,
    rcc_adc_prescaler_div_4,
    rcc_adc_prescaler_div_6,
    rcc_adc_prescaler_div_8,
} __attribute__ ((packed)) rcc_adc_prescaler_t;

typedef enum {
    rcc_usb_clock_source_pll_div_1_5,
    rcc_usb_clock_source_pll,
} __attribute__ ((packed)) rcc_usb_clock_source_t;

// write enum for rcc_pll_mul_t


typedef struct {
    rcc_pll_source_t pll_source;
    rcc_pll_hse_prescaler_t pll_hse_prescale;
    rcc_pll_mul_t pllm;
    rcc_sysclk_source_t sysclk_source;
    rcc_flash_latency_t flash_latency;
    rcc_ahb_prescaler_t ahb_prescale;
    rcc_apb1_prescaler_t apb1_prescale;
    rcc_apb2_prescaler_t apb2_prescale;
    rcc_usb_prescaler_t usb_prescale;
    rcc_adc_prescaler_t adc_prescale;
} __attribute__ ((packed)) rcc_clock_config_t;

bool rcc_pll_is_locked(void);
void rcc_enable_pll(void);
void rcc_disable_pll(void);
void rcc_enable_css(void);
void rcc_disable_css(void);
void rcc_enable_hsebypass(void);
void rcc_disable_hsebypass(void);
bool rcc_hse_is_ready(void);
void rcc_enable_hse(void);
void rcc_disable_hse(void);
bool rcc_hsi_is_ready(void);
void rcc_enable_hsi(void);
void rcc_disable_hsi(void);
void rcc_select_mco_output(rcc_mco_output_t output);
void rcc_set_usb_prescaler(rcc_usb_prescaler_t prescale);
void rcc_set_pllmul(uint32_t m);
void rcc_set_pll_hse_prescaler(rcc_pll_hse_prescaler_t prescale);
void rcc_set_pll_source(rcc_pll_source_t source);
void rcc_set_apb2_prescaler(rcc_apb2_prescaler_t prescale);
void rcc_set_apb1_prescaler(rcc_apb1_prescaler_t prescale);
void rcc_set_ahb_prescaler(rcc_ahb_prescaler_t prescale);
void rcc_set_adc_prescaler(rcc_adc_prescaler_t prescale);
void rcc_set_sysclk_source(rcc_sysclk_source_t source);
rcc_sysclk_source_t rcc_get_sysclk_source(void);
void rcc_configure_clock(const rcc_clock_config_t *config);