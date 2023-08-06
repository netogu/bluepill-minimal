#pragma once

/*---------------  USB CDC Class --------------- */
// From Universal Serial Bus Class Definitions for 
// Communications Devices

// Table 2
#define USB_CDC_CLASS           0x02
#define USB_CDC_INTERFACE_CLASS 0x02

// Table 4
#define USB_CDC_SUBCLASS_DLCM   0x01
#define USB_CDC_SUBCLASS_ACM    0x02
// Table 5
#define USB_CDC_PROTOCOL_NONE   0x00
#define USB_CDC_PROTOCOL_AT     0x01

// Table 6
#define USB_CDC_DATA_CLASS      0x0A

// Table 12 - bDescriptorType Field
#define USB_CDC_TYPE_CS_INTERFACE    0x24
#define USB_CDC_TYPE_CS_ENDPOINT     0x25

// Table 13 - bDescriptor SubType in CDC Functional Descriptor
#define USB_CDC_SUBTYPE_HEADER     0x00
#define USB_CDC_SUBTYPE_CALL_MGMT  0x01
#define USB_CDC_SUBTYPE_UNION      0x06

// Table 15- Class-Specific Descriptor Header Format
struct usb_cdc_header_descriptor {
    uint8_t bFunctionLength; // Size of this descriptor
    uint8_t bDescriptorType; // CS_INTERFACE descriptor type
    uint8_t bDescriptorSubtype; // Header functional subtype
    uint16_t bcdCDC; // USB Class Definitions for Communications Devices 
                     //Specification release number 
} __attribute__((packed));
#define USB_CDC_HEADER_DESCRIPTOR_SIZE sizeof(usb_cdc_header_descriptor)


// Table 16 - Union Interface Functional Descriptor
struct usb_cdc_union_descriptor {
    uint8_t bFunctionLength; // Size of this descriptor
    uint8_t bDescriptorType; // CS_INTERFACE descriptor type
    uint8_t bDescriptorSubtype; // Union functional subtype
    uint8_t bControlInterface; // Comm or Data class interface number 
                               // designated as the controlling interface
    uint8_t bSubordinateInterface0; // Interface no. of first subordinate interface
    /*...*/
} __attribute__((packed));
#define USB_CDC_UNION_DESCRIPTOR_SIZE sizeof(usb_cdc_union_descriptor)


//TODO: review USB PSTN Device spec

/*--------------- ACM Device --------------- */
/* Definitions for Abstract Control Model devices from:
 * "Universal Serial Bus Communications Class Subclass Specification for
 * PSTN Devices"
 */

/* Table 3: Call Management Functional Descriptor */
struct usb_cdc_call_management_descriptor {
	uint8_t bFunctionLength;
	uint8_t bDescriptorType;
	uint8_t bDescriptorSubtype;
	uint8_t bmCapabilities;
	uint8_t bDataInterface;
} __attribute__((packed));

/* Table 4: Abstract Control Management Functional Descriptor */
struct usb_cdc_acm_descriptor {
	uint8_t bFunctionLength;
	uint8_t bDescriptorType;
	uint8_t bDescriptorSubtype;
	uint8_t bmCapabilities;
} __attribute__((packed));

/* Table 13: Class-Specific Request Codes for PSTN subclasses */
/* ... */
#define USB_CDC_REQ_SET_LINE_CODING		0x20
#define USB_CDC_REQ_GET_LINE_CODING		0x21
#define USB_CDC_REQ_SET_CONTROL_LINE_STATE	0x22
/* ... */

/* Table 17: Line Coding Structure */
struct usb_cdc_line_coding {
	uint32_t dwDTERate;
	uint8_t bCharFormat;
	uint8_t bParityType;
	uint8_t bDataBits;
} __attribute__((packed));

enum usb_cdc_line_coding_bCharFormat {
	USB_CDC_1_STOP_BITS			= 0,
	USB_CDC_1_5_STOP_BITS			= 1,
	USB_CDC_2_STOP_BITS			= 2,
};

enum usb_cdc_line_coding_bParityType {
	USB_CDC_NO_PARITY			= 0,
	USB_CDC_ODD_PARITY			= 1,
	USB_CDC_EVEN_PARITY			= 2,
	USB_CDC_MARK_PARITY			= 3,
	USB_CDC_SPACE_PARITY			= 4,
};

/* Table 30: Class-Specific Notification Codes for PSTN subclasses */
/* ... */
#define USB_CDC_NOTIFY_SERIAL_STATE		0x20
/* ... */

/* Notification Structure */
struct usb_cdc_notification {
	uint8_t bmRequestType;
	uint8_t bNotification;
	uint16_t wValue;
	uint16_t wIndex;
	uint16_t wLength;
} __attribute__((packed));


