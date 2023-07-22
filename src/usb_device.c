#include "drv_usb_std.h"
#include "drv_usb_cdc.h"

// From Universal Serial Bus Class Definitions for Communications Devices
// Table 8

static const struct usb_device_descriptor cdc_device_desc = {
    .bLength = USB_DEVICE_DESCRIPTOR_SIZE,
    .bDescriptorType = USB_DEVICE_DESCRIPTOR,
    .bcdUSB = 0x0200, // USB 2.0
    .bDeviceClass = USB_CDC_CLASS,
    .bDeviceSubclass = 0,
    .bDeviceProtocol = 0,
    .bMaxPacketSize = 64,
    .idVendor = 0x0483,
    .idProduct = 0x5740,
    .bcdDevice = 0x0200,
    .iManufacturer = 1,
    .iProduct = 2,
    .iSerialNumber = 3,
    .bNumConfigurations =1,
};

// Notification endpoint. (Not Implemented)
static const struct usb_endpoint_descriptor comm_ep = {
    .bLength = USB_ENDPOINT_DESCRIPTOR_SIZE,
    .bDescriptorType = USB_ENDPOINT_DESCRIPTOR,
    .bEndpointAddress = USB_EP_ADDR_IN(3),
    .bmAttributes = USB_EP_ATTR_INTERRUPT,
    .wMaxPacketSize = 16,
    .bInterval = 255,
};

// Data endpoints
static const struct usb_endpoint_descriptor data_ep[] = {
    {
        .bLength = USB_ENDPOINT_DESCRIPTOR_SIZE,
        .bDescriptorType = USB_ENDPOINT_DESCRIPTOR,
        .bEndpointAddress = USB_EP_ADDR_OUT(1),
        .bmAttributes = USB_EP_ATTR_BULK,
        .wMaxPacketSize = 64,
        .bInterval = 1,
    },
    {
        .bLength = USB_ENDPOINT_DESCRIPTOR_SIZE,
        .bDescriptorType = USB_ENDPOINT_DESCRIPTOR,
        .bEndpointAddress = USB_EP_ADDR_IN(2),
        .bmAttributes = USB_EP_ATTR_BULK,
        .wMaxPacketSize = 64,
        .bInterval = 1,
    }
};

// Functional