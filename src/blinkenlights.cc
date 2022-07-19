#include <bsp/board.h>
#include <tusb.h>

#include "hardware/gpio.h"

uint8_t led_pins[] = { 1, 2, 4, 6, 8, 10, 12, 14 };

void pins_init() {
    for (uint i = 0; i < sizeof(led_pins); i++) {
        gpio_init(led_pins[i]);
        gpio_set_dir(led_pins[i], GPIO_OUT);
    }
}

int main() {
    board_init();
    pins_init();
    tusb_init();

    while (true) {
        tud_task();
    }

    return 0;
}

void tud_hid_set_report_cb(uint8_t instance, uint8_t report_id, hid_report_type_t report_type, uint8_t const* buffer, uint16_t bufsize) {
    if ((report_type == HID_REPORT_TYPE_OUTPUT) && (report_id == 1) && (bufsize >= 1)) {
        for (uint i = 0; i < 8; i++) {
            gpio_put(led_pins[i], (buffer[0] >> i) & 1);
        }
    }
}

uint16_t tud_hid_get_report_cb(uint8_t itf, uint8_t report_id, hid_report_type_t report_type, uint8_t* buffer, uint16_t reqlen) {
    return 0;
}
