#include <stdint.h>

#define ISR_VECTOR_SIZE 76
#define SRAM_START (0x20000000U)
#define SRAM_SIZE (20U * 1024U)
#define SRAM_END (SRAM_START + SRAM_SIZE)
#define STACK_POINTER_INIT_ADDRESS (SRAM_END)

void default_handler(void);
void reset_handler(void);
void nmi_handler(void) __attribute__((weak, alias("default_handler")));
void hard_fault_handler(void) __attribute__((weak, alias("default_handler")));
void mem_manage_handler(void) __attribute__((weak, alias("default_handler")));
void bus_fault_handler(void) __attribute__((weak, alias("default_handler")));
void usage_fault_handler(void) __attribute__((weak, alias("default_handler")));
void svcall_handler(void) __attribute__((weak, alias("default_handler")));
void debug_monitor_handler(void) __attribute__((weak, alias("default_handler")));
void pendsv_handler(void) __attribute__((weak, alias("default_handler")));
void systick_handler(void) __attribute__((weak, alias("default_handler")));
void wwdg_interrupt_handler(void) __attribute__((weak, alias("default_handler")));
void pvd_interrupt_handler(void) __attribute__((weak, alias("default_handler")));
void tamper_interrupt_handler(void) __attribute__((weak, alias("default_handler")));
void rtc_interrupt_handler(void) __attribute__((weak, alias("default_handler")));
void flash_interrupt_handler(void) __attribute__((weak, alias("default_handler")));
void rcc_interrupt_handler(void) __attribute__((weak, alias("default_handler")));
void exti0_interrupt_handler(void) __attribute__((weak, alias("default_handler")));
void exti1_interrupt_handler(void) __attribute__((weak, alias("default_handler")));
void exti2_interrupt_handler(void) __attribute__((weak, alias("default_handler")));
void exti3_interrupt_handler(void) __attribute__((weak, alias("default_handler")));
void exti4_interrupt_handler(void) __attribute__((weak, alias("default_handler")));
void dma1_ch1_interrupt_handler(void) __attribute__((weak, alias("default_handler")));
void dma1_ch2_interrupt_handler(void) __attribute__((weak, alias("default_handler")));
void dma1_ch3_interrupt_handler(void) __attribute__((weak, alias("default_handler")));
void dma1_ch4_interrupt_handler(void) __attribute__((weak, alias("default_handler")));
void dma1_ch5_interrupt_handler(void) __attribute__((weak, alias("default_handler")));
void dma1_ch6_interrupt_handler(void) __attribute__((weak, alias("default_handler")));
void dma1_ch7_interrupt_handler(void) __attribute__((weak, alias("default_handler")));
void adc1_2_interrupt_handler(void) __attribute__((weak, alias("default_handler")));
void usb_hp_can_tx_interrupt_handler(void) __attribute__((weak, alias("default_handler")));
void usb_lp_can_rx0_interrupt_handler(void) __attribute__((weak, alias("default_handler")));
void can_rx1_interrupt_handler(void) __attribute__((weak, alias("default_handler")));
void can_sce_interrupt_handler(void) __attribute__((weak, alias("default_handler")));
void exti9_5_interrupt_handler(void) __attribute__((weak, alias("default_handler")));
void tim1_brk_interrupt_handler(void) __attribute__((weak, alias("default_handler")));
void tim1_up_interrupt_handler(void) __attribute__((weak, alias("default_handler")));
void tim1_trg_com_interrupt_handler(void) __attribute__((weak, alias("default_handler")));
void tim1_cc_interrupt_handler(void) __attribute__((weak, alias("default_handler")));
void tim2_interrupt_handler(void) __attribute__((weak, alias("default_handler")));
void tim3_interrupt_handler(void) __attribute__((weak, alias("default_handler")));
void tim4_interrupt_handler(void) __attribute__((weak, alias("default_handler")));
void i2c1_ev_interrupt_handler(void) __attribute__((weak, alias("default_handler")));
void i2c1_er_interrupt_handler(void) __attribute__((weak, alias("default_handler")));
void i2c2_ev_interrupt_handler(void) __attribute__((weak, alias("default_handler")));
void i2c2_er_interrupt_handler(void) __attribute__((weak, alias("default_handler")));
void spi1_interrupt_handler(void) __attribute__((weak, alias("default_handler")));
void spi2_interrupt_handler(void) __attribute__((weak, alias("default_handler")));
void usart1_interrupt_handler(void) __attribute__((weak, alias("default_handler")));
void usart2_interrupt_handler(void) __attribute__((weak, alias("default_handler")));
void usart3_interrupt_handler(void) __attribute__((weak, alias("default_handler")));
void exti15_10_interrupt_handler(void) __attribute__((weak, alias("default_handler")));
void rtc_alarm_interrupt_handler(void) __attribute__((weak, alias("default_handler")));
void usb_wakeup_interrupt_handler(void) __attribute__((weak, alias("default_handler")));
void tim8_brk_interrupt_handler(void) __attribute__((weak, alias("default_handler")));
void tim8_up_interrupt_handler(void) __attribute__((weak, alias("default_handler")));
void tim8_trg_com_interrupt_handler(void) __attribute__((weak, alias("default_handler")));
void tim8_cc_interrupt_handler(void) __attribute__((weak, alias("default_handler")));
void adc3_interrupt_handler(void) __attribute__((weak, alias("default_handler")));
void fsmc_interrupt_handler(void) __attribute__((weak, alias("default_handler")));
void sdio_interrupt_handler(void) __attribute__((weak, alias("default_handler")));
void tim5_interrupt_handler(void) __attribute__((weak, alias("default_handler")));
void spi3_interrupt_handler(void) __attribute__((weak, alias("default_handler")));
void uart4_interrupt_handler(void) __attribute__((weak, alias("default_handler")));
void uart5_interrupt_handler(void) __attribute__((weak, alias("default_handler")));
void tim6_interrupt_handler(void) __attribute__((weak, alias("default_handler")));
void tim7_interrupt_handler(void) __attribute__((weak, alias("default_handler")));
void dma2_ch1_interrupt_handler(void) __attribute__((weak, alias("default_handler")));
void dma2_ch2_interrupt_handler(void) __attribute__((weak, alias("default_handler")));
void dma2_ch3_interrupt_handler(void) __attribute__((weak, alias("default_handler")));
void dma2_ch4_5_interrupt_handler(void) __attribute__((weak, alias("default_handler")));

/* Linker Labels*/
extern uint32_t _initial_sp;

#define RESERVED 0
uint32_t isr_vector[ISR_VECTOR_SIZE] __attribute__((section(".isr_vector"))) = {
    STACK_POINTER_INIT_ADDRESS,
    (uint32_t)&reset_handler,
    (uint32_t)&nmi_handler,
    (uint32_t)&hard_fault_handler,
    (uint32_t)&mem_manage_handler,
    (uint32_t)&bus_fault_handler,
    (uint32_t)&usage_fault_handler,
    RESERVED,
    RESERVED,
    RESERVED,
    RESERVED,
    (uint32_t)&svcall_handler,
    (uint32_t)&debug_monitor_handler,
    RESERVED,
    (uint32_t)&pendsv_handler,
    (uint32_t)&systick_handler,
    (uint32_t)&wwdg_interrupt_handler,
    (uint32_t)&pvd_interrupt_handler,
    (uint32_t)&tamper_interrupt_handler,
    (uint32_t)&rtc_alarm_interrupt_handler,
    (uint32_t)&flash_interrupt_handler,
    (uint32_t)&rcc_interrupt_handler,
    (uint32_t)&exti0_interrupt_handler,
    (uint32_t)&exti1_interrupt_handler,
    (uint32_t)&exti2_interrupt_handler,
    (uint32_t)&exti3_interrupt_handler,
    (uint32_t)&exti4_interrupt_handler,
    (uint32_t)&dma1_ch1_interrupt_handler,
    (uint32_t)&dma1_ch2_interrupt_handler,
    (uint32_t)&dma1_ch3_interrupt_handler,
    (uint32_t)&dma1_ch4_interrupt_handler,
    (uint32_t)&dma1_ch5_interrupt_handler,
    (uint32_t)&dma1_ch6_interrupt_handler,
    (uint32_t)&dma1_ch7_interrupt_handler,
    (uint32_t)&adc1_2_interrupt_handler,
    (uint32_t)&usb_hp_can_tx_interrupt_handler,
    (uint32_t)&usb_lp_can_rx0_interrupt_handler,
    (uint32_t)&can_rx1_interrupt_handler,
    (uint32_t)&can_sce_interrupt_handler,
    (uint32_t)&exti9_5_interrupt_handler,
    (uint32_t)&tim1_brk_interrupt_handler,
    (uint32_t)&tim1_up_interrupt_handler,
    (uint32_t)&tim1_trg_com_interrupt_handler,
    (uint32_t)&tim1_cc_interrupt_handler,
    (uint32_t)&tim2_interrupt_handler,
    (uint32_t)&tim3_interrupt_handler,
    (uint32_t)&tim4_interrupt_handler,
    (uint32_t)&i2c1_ev_interrupt_handler,
    (uint32_t)&i2c1_er_interrupt_handler,
    (uint32_t)&i2c2_ev_interrupt_handler,
    (uint32_t)&i2c2_er_interrupt_handler,
    (uint32_t)&spi1_interrupt_handler,
    (uint32_t)&spi2_interrupt_handler,
    (uint32_t)&usart1_interrupt_handler,
    (uint32_t)&usart2_interrupt_handler,
    (uint32_t)&usart3_interrupt_handler,
    (uint32_t)&exti15_10_interrupt_handler,
    (uint32_t)&rtc_alarm_interrupt_handler,
    (uint32_t)&usb_wakeup_interrupt_handler,
    (uint32_t)&tim8_brk_interrupt_handler,
    (uint32_t)&tim8_up_interrupt_handler,
    (uint32_t)&tim8_trg_com_interrupt_handler,
    (uint32_t)&tim8_cc_interrupt_handler,
    (uint32_t)&adc3_interrupt_handler,
    (uint32_t)&fsmc_interrupt_handler,
    (uint32_t)&sdio_interrupt_handler,
    (uint32_t)&tim5_interrupt_handler,
    (uint32_t)&spi3_interrupt_handler,
    (uint32_t)&uart4_interrupt_handler,
    (uint32_t)&uart5_interrupt_handler,
    (uint32_t)&tim6_interrupt_handler,
    (uint32_t)&tim7_interrupt_handler,
    (uint32_t)&dma2_ch1_interrupt_handler,
    (uint32_t)&dma2_ch2_interrupt_handler,
    (uint32_t)&dma2_ch3_interrupt_handler,
    (uint32_t)&dma2_ch4_5_interrupt_handler,
};

void default_handler(void) {
    while(1);
}

// Defining _exit function to avoid linker error
void _exit(int var) {
    while(1);
}

extern uint32_t _sidata, _etext, _sdata, _edata, _sbss, _ebss;
extern void SystemCoreClockUpdate(void); //from cmsis system_stm32f1xx.c

void main(void);

void reset_handler(void) {

    // Copy .data from FLASH to SRAM
    uint32_t data_size = (uint32_t)&_edata - (uint32_t)&_sdata;
    uint8_t *flash_data = (uint8_t *)&_sidata;
    uint8_t *sram_data = (uint8_t *)&_sdata;

    for (uint32_t i = 0; i < data_size; i++) {
        sram_data[i] = flash_data[i];
    }

    // Zero Fill .bss
    uint32_t bss_size = (uint32_t)&_ebss - (uint32_t)&_sbss;
    uint8_t *sram_bss = (uint8_t *)&_sbss;

    for (uint32_t i = 0; i < bss_size; i++) {
        sram_bss[i] = 0;
    }

    SystemCoreClockUpdate();
    // Jump to main
    main();
}
