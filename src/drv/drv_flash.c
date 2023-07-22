#include "drv_flash.h"
#include "drv_common.h"

void flash_set_latency(uint32_t latency) {
    Write_register_field(FLASH->ACR, FLASH_ACR_LATENCY, latency);
}

void flash_enable_prefetch_buff(void) {
    Set_register_bit(FLASH->ACR, FLASH_ACR_PRFTBE);
}
void flash_disable_prefetch_buff(void) {
    Clear_register_bit(FLASH->ACR, FLASH_ACR_PRFTBE);
}

void flash_enable_half_cycle(void) {
    Set_register_bit(FLASH->ACR, FLASH_ACR_HLFCYA);
}
void flash_disable_half_cycle(void) {
    Clear_register_bit(FLASH->ACR, FLASH_ACR_HLFCYA);
}