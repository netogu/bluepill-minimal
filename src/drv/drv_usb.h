/**
 * @file drv_usb.h
 * @author netogu (https://github.com/netogu)
 * @brief USB Driver for STM32F103C8T6
 * @version 0.1
 * @date 2023-08-04
 * 
 * @copyright Copyright (MIT) 2023
 * 
 */

#pragma once

#include <stdint.h>
#include <stddef.h>
#include "stm32f1xx.h"


/* USB Packet Memory Area*/

// typedef uint16_t usb_pma_word_t; // PMA max word size

// /**
//  * @brief USB Packet Memory Address to USB Peripheral Local Address
//  * 
//  */
// #define USB_LOCAL_ADDR(pma_addr) (uint32_t)((uint32_t)(pma_addr) + USB_PMAADDR))
// #define USB_LOCAL_ADDR_TO_PMA(local_addr) (usb_pma_word_t *)((uint32_t)(local_addr) - USB_PMAADDR))

// /**
//  * @brief USB Main Memory Address to USB Packet Memory Address
//  * 
//  */
// #define USB_PMA_TO_MAIN_MEMORY(pma_addr) (uint32_t *) ((USB_PMA_TO_LOCAL_ADDR(pma_addr)*2 + USB_PMAADDR)))
// #define USB_MAIN_MEMORY_TO_PMA(main_addr) ((usb_pma_word_t *)((main_addr) + USB_PMAADDR))

// static void usb_pma_copy_in(void *source, usb_pma_word_t *destination, uint16_t size) {
//     usb_pma_word_t *source_pma = USB_MAIN_MEMORY_TO_PMA(source);
//     for (size_t i = 0; i < size; i++) {
//         destination[i] = source_pma[i];
//     }
// }

// static void usb_pma_copy_out(void *source, usb_pma_word_t *destination, uint16_t size) {
//     usb_pma_word_t *destination_pma = USB_MAIN_MEMORY_TO_PMA(destination);
//     for (size_t i = 0; i < size; i++) {
//         destination_pma[i] = source[i];
//     }
// }

// #define USB_PACKET_BUFFER_ALIGNMENT 4

// typedef uint16_t    pb_word_t;
// typedef pb_word_t   pb_aligned_word_t __attribute__ ((aligned(USB_PACKET_BUFFER_ALIGNMENT)));


// typedef struct {
//     pb_aligned_word_t tx_offset;
//     pb_aligned_word_t tx_count;
//     pb_aligned_word_t rx_offset;
//     pb_aligned_word_t rx_count;
// } usb_packet_buffer_t;

// typedef struct {
//     pb_aligned_word_t data;
// } usb_pbuffer_data_t;

// #define USB_BTABLE_SIZE (sizeof(usb_btable_entity_t) * USB_NUM_ENDPOINTS)
// #define USB_BTABLE_SMALL_BLOCK_SIZE (sizeof(uint16_t))
// #define USB_BTABLE_LARGE_BLOCK_SIZE (USB_BTABLE_SMALL_BLOCK_SIZE<<4)
// #define USB_BTABLE_SMALL_BLOCK_SIZE_LIMIT ((USB_COUNT0_RX_NUM_BLOCK>>USB_COUNT0_RX_NUM_BLOCK_Pos)<<1)


// /* USB Endpoint Events */

// typedef enum {
//     usb_endpoint_event_data_received    = 0x01,
//     usb_endpoint_event_data_sent        = 0x02,
//     usb_endpoint_event_setup            = 0x03,
// } usb_endpoint_event_t;


// /* USB Endpoint Definition */

// typedef void (*usb_endpoint_event_handler_t)(uint8_t ep_num, usb_endpoint_event_t ep_event);

// typedef struct {
//     uint32_t type;
//     uint8_t rx_size;
//     uint8_t tx_size;
//     usb_endpoint_event_handler_t event_handler;
// } usb_endpoint_t;

// #define USB_NUM_ENDPOINTS (sizeof(usb_endpoints)/sizeof(*usb_endpoints)
// #define USB_MAX_ENDPOINTS 8

// /* USB Functions */

// /**
//  * @brief Initialize USB Peripheral and USB Driver:
//  * + Configure USB clocks
//  * + De-assert USB Peripheral Reset
//  * + Activate USB regiter macrocell
//  * + De-assert macrocell specific resets
//  * + Configure USB Analog & Power blocks
//  * + Initialize USB Packet Buffer Table
//  * + Enable USB Peripheral Interrupts
//  * + Enable USB Peripheral
//  */
// void usb_init(void);

// /**
//  * @brief Handles USB Reset Event:
//  */
// void usb_reset_handler(void);

// /**
//  * @brief Set USB Address
//  */
// void usb_set_address(uint8_t addr);



// void usb_reset(void);
// size_t usb_bytes_available(uint8_t ep_num);
// size_t usb_space_available(uint8_t ep_num);
// uint32_t usb_read(uint8_t ep_num, void *buffer, uint32_t size);
// uint32_t usb_write(uint8_t ep_num, const void *buffer, uint32_t size);
// void usb_endpoint_set_stall(uint8_t ep_num, usb_endpoint_direction_t direction, uint8_t stall);
// uint32_t usb_endpoint_is_stalled(uint8_t ep_num, usb_endpoint_direction_t direction);