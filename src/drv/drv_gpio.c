#include "drv_gpio.h"

static void gpio_enable_port(GPIO_TypeDef *port) {
    if (port == GPIOA) {
        RCC->APB2ENR |= (1 << RCC_APB2ENR_IOPAEN_Pos);
    } else if (port == GPIOB) {
        RCC->APB2ENR |= (1 << RCC_APB2ENR_IOPBEN_Pos);
    } else if (port == GPIOC) {
        RCC->APB2ENR |= (1 << RCC_APB2ENR_IOPCEN_Pos);
    } else if (port == GPIOD) {
        RCC->APB2ENR |= (1 << RCC_APB2ENR_IOPDEN_Pos);
    } else if (port == GPIOE) {
        RCC->APB2ENR |= (1 << RCC_APB2ENR_IOPEEN_Pos);
    }
}

void gpio_pin_init(const gpio_pin_t *pin) {
    volatile uint32_t *crx = &pin->port->CRL + (pin->pin >> 3);
    uint8_t shift = (pin->pin & 0x7) << 2;
    uint32_t modecfg = 0;
    gpio_enable_port(pin->port);
    *crx &= ~((GPIO_CRL_CNF0 | GPIO_CRL_MODE0) << shift);
    if (pin->dir == gpio_dir_input) {
        if (pin->pull == gpio_pull_floating) {
            modecfg |= GPIO_CRL_CNF0_0;
        } else {
            modecfg |= GPIO_CRL_CNF0_1; //Analog mode
            pin->port->BSRR = ((pin->pull == gpio_pull_up) ? GPIO_BSRR_BS0 : GPIO_BSRR_BR0) << pin->pin;
        } 
        } else { //if output or unknown
        if (pin->speed == gpio_speed_low) {
            modecfg |= GPIO_CRL_MODE0_1;
        } else if (pin->speed == gpio_speed_medium) {
            modecfg |= GPIO_CRL_MODE0_0;
        } else if (pin->speed == gpio_speed_high) {
            modecfg |= GPIO_CRL_MODE0;
        }
        if (pin->output == gpio_output_od) {
            modecfg |= GPIO_CRL_CNF0_0;
        }
        if (pin->func == gpio_func_alternate) {
            modecfg |= GPIO_CRL_CNF0_1;
        }
    }
    *crx |= modecfg << shift;
}   

void gpio_pin_set(const gpio_pin_t *pin) {
    if(pin->polarity == gpio_polarity_high) {
        pin->port->BSRR |= (1 << pin->pin);
    } else {
        pin->port->BRR |= (1 << pin->pin);
    }
}

void gpio_pin_clear(const gpio_pin_t *pin) {
    if(pin->polarity == gpio_polarity_high) {
        pin->port->BRR |= (1 << pin->pin);
    } else {
        pin->port->BSRR |= (1 << pin->pin);
    }
}


uint32_t gpio_pin_read(const gpio_pin_t *pin) {
    if (pin->polarity == gpio_polarity_high) {
        return (pin->port->IDR & (1 << pin->pin)) ? 1 : 0;
    } else {
        return (pin->port->IDR & (1 << pin->pin)) ? 0 : 1;
    }
}

void gpio_pin_toggle(const gpio_pin_t *pin) {
    pin->port->ODR ^= (1 << pin->pin);
}


volatile uint32_t *gpio_pin_get_bitband_clear_addr(const gpio_pin_t *pin) {
    volatile uint32_t result = 0;
    if (pin->port) {
        result = PERIPH_BB_BASE;
        result += ((uint32_t)(&pin->port->BSRR) - PERIPH_BASE) << 5;
        result += pin->pin << 2;
        if (pin->polarity == gpio_polarity_high) {
            result += GPIO_BSRR_BR0_Pos << 2;
        }
    }
    return (volatile uint32_t*)result;
}