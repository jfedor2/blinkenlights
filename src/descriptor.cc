#include "descriptor.h"

const uint8_t report_descriptor[] = {
    0x05, 0x01,  // Usage Page (Generic Desktop Ctrls)
    0x09, 0x05,  // Usage (Game Pad)
    0xA1, 0x01,  // Collection (Application)
    0x85, 0x01,  //   Report ID (1)
    0x95, 0x08,  //   Report Count (8)
    0x75, 0x01,  //   Report Size (1)
    0x05, 0x08,  //   Usage Page (LEDs)
    0x09, 0x01,  //   Usage (Num Lock)
    0x09, 0x02,  //   Usage (Caps Lock)
    0x09, 0x03,  //   Usage (Scroll Lock)
    0x09, 0x04,  //   Usage (Compose)
    0x09, 0x05,  //   Usage (Kana)
    0x09, 0x27,  //   Usage (Stand-by)
    0x09, 0x4C,  //   Usage (System Suspend)
    0x09, 0x09,  //   Usage (Mute)
    0x91, 0x02,  //   Output (Data,Var,Abs,No Wrap,Linear,Preferred State,No Null Position,Non-volatile)
    0xC0,        // End Collection
};

const uint32_t report_descriptor_length = sizeof(report_descriptor);
