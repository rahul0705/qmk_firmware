#include "rahul0705.h"
#include "custom_keycodes.h"

__attribute__ ((weak))
bool process_record_keymap(uint16_t keycode, keyrecord_t *record){
    return true;
}
bool process_record_user(uint16_t keycode, keyrecord_t *record) {

    static struct {
        bool on;
        bool first;
    } w_i_d_e_t_e_x_t = {false, false};

    //borrowed from daniel5151, check his repo out for awesome changes
    //https://github.com/daniel5151/qmk_firmware
    if (w_i_d_e_t_e_x_t.on) {
        if (record->event.pressed) {
            switch (keycode) {
                case KC_A...KC_0:
                case KC_SPC:
                    if (w_i_d_e_t_e_x_t.first) {
                        w_i_d_e_t_e_x_t.first = false;
                    } else {
                        send_char(' ');
                    }
                    break;
                case KC_ENT:
                    w_i_d_e_t_e_x_t.first = true;
                    break;
                case KC_BSPC:
                    send_char('\b'); // backspace
                    break;
            }
        }
    }

    switch (keycode) {
        case RAHUL:
            if (record->event.pressed) {
                SEND_STRING("Rahul Mohandas");
            }
            return false;
        case SHRUG:
            if (record->event.pressed) {
                if (MODS_SHIFT) {
                    send_unicode_hex_string("0028 0020 0CA0 0020 0CA0 0020 0029");
                } else {
                    send_unicode_hex_string("00AF 005C 005F 0028 30C4 0029 005F 002F 00AF");
                }
            }
            return false;
        case ANGRY:
            if (record->event.pressed) {
                if (MODS_SHIFT) {
                    send_unicode_hex_string("0028 3000 FF9F 0414 FF9F 0029 FF1C 0021 0021");
                } else {
                    send_unicode_hex_string("0028 256F 00B0 25A1 00B0 0029 256F FE35 0020 253B 2501 253B");
                }
            }
            return false;
        case WIDETXT:
            if (record->event.pressed) {
                w_i_d_e_t_e_x_t.on = !w_i_d_e_t_e_x_t.on;
                w_i_d_e_t_e_x_t.first = true;
            }
            return false;
        default:
            return process_record_keymap(keycode, record); //Process all other keycodes normally
    }
}
