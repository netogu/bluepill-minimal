#pragma once
#include <stdint.h>
#include "drv_usb_std.h"

#define USB_SETUP_MAX_PAYLOAD_SIZE 32
#define USB_SETUP_MAX_DATA_SIZE (sizeof(usb_setup_t) + USB_SETUP_MAX_PAYLOAD_SIZE)

// USB Control Endpoint Operation Status
typedef enum {
    usb_status_ack = 0x00,
    usb_status_nak = 0x01,
    usb_status_stall = 0x02,
} usb_status_t;

// USB Control Endpoint Exchange Complete Callback   
typedef void (*usb_tx_callback_t)(void);

// USB Control Endpoint Event Handler

// void usb_control_endpoint_event_handler(uint8_t ep_num, usb_endpoint_event_t ep_event);

// USB Device State

typedef enum {
    usb_device_state_reset = 0x00,
    usb_device_state_address_set = 0x01,
    usb_device_state_configured = 0x02,
} usb_device_state_t;


// Device Level Events

void usb_device_handle_reset(void);
void usb_device_handle_configured(void);
void usb_device_handle_suspend(void);
void usb_device_handle_wakeup(void);
void usb_device_handle_frame(void);
void usb_device_poll(void);



// void usb_device_handle_reset(void);
// void usb_device_handle_set_address(uint8_t address);
// void usb_device_handle_set_configuration(uint8_t configuration);
// void usb_device_handle_get_configuration(void);
// void usb_device_handle_get_descriptor(uint16_t wValue, uint16_t wIndex, uint16_t wLength);
// void usb_device_handle_get_status(uint16_t wValue, uint16_t wIndex, uint16_t wLength);
// void usb_device_handle_set_feature(uint16_t wValue, uint16_t wIndex, uint16_t wLength);
// void usb_device_handle_clear_feature(uint16_t wValue, uint16_t wIndex, uint16_t wLength);

