#pragma once

#include "stm32f1xx.h"


void flash_set_latency(uint32_t latency);
void flash_enable_prefetch_buff(void);
void flash_disable_prefetch_buff(void);
void flash_enable_half_cycle(void);
void flash_disable_half_cycle(void);
