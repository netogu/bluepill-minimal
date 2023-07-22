// Toggle PC13 Pin
#include <stdint.h>
#include "stm32f1xx.h"
#include "drv_rcc.h"
#include "drv_gpio.h"
#include "drv_flash.h"
#define LED_PIN 13


uint32_t ticks;
void systick_handler() {
    ticks++;
}
void delay_ms(uint32_t ms) {
    uint32_t start = ticks;
    uint32_t end = start + ms;
    if (end < start) {
        while (ticks > start);
    }
    while (ticks < end);
}

const rcc_clock_config_t rcc_hse_pll_72meghz_config = {
    .pll_hse_prescale = rcc_pll_hse_prescaler_div_1,
    .pll_source       = rcc_pll_source_hse,
    .pllm             = rcc_pll_mul_9,
    .sysclk_source    = rcc_sysclk_source_pll,
    .flash_latency    = rcc_flash_latency_2,
    .ahb_prescale     = rcc_ahb_prescaler_div_1,
    .apb1_prescale    = rcc_apb1_prescaler_div_1,
    .apb2_prescale    = rcc_apb2_prescaler_div_1,
    .usb_prescale     = rcc_usb_prescaler_div_1_5,
    .adc_prescale     = rcc_adc_prescaler_div_6,
};

int main(void) {
    
    rcc_configure_clock(&rcc_hse_pll_72meghz_config);
    SysTick_Config(SystemCoreClock/1000);
    __enable_irq();

    gpio_pin_t led_pin = {
        .port     = GPIOC,
        .pin      = LED_PIN,
        .dir      = gpio_dir_output,
        .func     = gpio_func_general,
        .output   = gpio_output_pp,
        .polarity = gpio_polarity_high,
        .speed    = gpio_speed_low,
    };

    gpio_pin_init(&led_pin);


    while(1) {
        // Toggle Pin
        gpio_pin_toggle(&led_pin);
        // Delay
        delay_ms(1000);
    }
}


