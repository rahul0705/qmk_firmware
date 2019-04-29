#include QMK_KEYBOARD_H

extern rgb_config_t rgb_matrix_config;

enum alt_layers {
    BASE,
    FUNC,
    EMJI,
};

enum alt_keycodes {
    U_T_AUTO = SAFE_RANGE, //USB Extra Port Toggle Auto Detect / Always Active
    U_T_AGCR,              //USB Toggle Automatic GCR control
    DBG_TOG,               //DEBUG Toggle On / Off
    DBG_MTRX,              //DEBUG Toggle Matrix Prints
    DBG_KBD,               //DEBUG Toggle Keyboard Prints
    DBG_MOU,               //DEBUG Toggle Mouse Prints
    MD_BOOT,               //Restart into bootloader after hold timeout
    KC_RHL,                //Rahul
    SHRUG,                 //Shrug
    ANGRY,                 //Angry
    WIDETXT,               //w i d e t e x t   f o r   a   w i d e   b o y
};

enum unicode_names {
  POOP,
};

const uint32_t PROGMEM unicode_map[] = {
  [POOP] = 0x1F4A9,
};

#define TG_NKRO MAGIC_TOGGLE_NKRO //Toggle 6KRO / NKRO mode

keymap_config_t keymap_config;

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Base Layer
 * ,--------------------------------------------------------------------------------------------------------.
 * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  |   -  |   =  | Bksp |  Del |
 * |------+------+------+------+------+------+------+------+------+------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  |   [  |   ]  |   \  | Home |
 * |------+------+------+------+------+-------------+------+------+------+------+------+------+------+------|
 * | Esc  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |   '  |    Enter    | Pgup |
 * |------+------+------+------+------+------|------+------+------+------+------+------+--------------------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |   Ctrl(B)   |  Up  | Pgdn |
 * |------+------+------+------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl | Meta |  Alt |                      Space                     |  Alt | FUNC | Left | Down | Right|
 * `--------------------------------------------------------------------------------------------------------'
 */
    [BASE] = LAYOUT(
        KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC, KC_DEL,  \
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS, KC_HOME, \
        KC_ESC,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, KC_ENT,           KC_PGUP, \
        KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, LCTL(KC_B),       KC_UP,   KC_PGDN, \
        KC_LCTL, KC_LGUI, KC_LALT,                            KC_SPC,                             KC_RALT, MO(FUNC),KC_LEFT, KC_DOWN, KC_RGHT  \
    ),
/* Function Layer
 * ,--------------------------------------------------------------------------------------------------------.
 * | Rahul|  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 | Bksp | Mute |
 * |------+------+------+------+------+------+------+------+------+------+------+------+------+------+------|
 * |      | L_SPI| L_BRI| L_SPD| L_HUI| L_SAI|      |   ?  |   ?  |      | Print| Scrlk| Pause| EMJI | End  |
 * |------+------+------+------+------+-------------+------+------+------+------+------+------+------+------|
 * |      |L_MODP| L_DIM|L_MODN| L_HUD| L_SAD|      |      |      |      |      |      |             | VolU |
 * |------+------+------+------+------+------|------+------+------+------+------+------+--------------------|
 * |      | L_TOG|      |      |      | BOOT | NKRO |  DBG |      |      |      |             | Pgup | VolD |
 * |------+------+------+------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |                                                |      |      | Home | Pgdn | End  |
 * `--------------------------------------------------------------------------------------------------------'
 */
    [FUNC] = LAYOUT(
        KC_RHL,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_TRNS, KC_MUTE, \
        KC_TRNS, RGB_SPD, RGB_VAI, RGB_SPI, RGB_HUI, RGB_SAI, KC_TRNS, U_T_AUTO,U_T_AGCR,KC_TRNS, KC_PSCR, KC_SLCK, KC_PAUS, TO(EMJI),KC_END,  \
        KC_TRNS, RGB_RMOD,RGB_VAD, RGB_MOD, RGB_HUD, RGB_SAD, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,          KC_VOLU, \
        KC_TRNS, RGB_TOG, KC_TRNS, KC_TRNS, KC_TRNS, MD_BOOT, TG_NKRO, DBG_TOG, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,          KC_PGUP, KC_VOLD, \
        KC_TRNS, KC_TRNS, KC_TRNS,                            KC_TRNS,                            KC_TRNS, KC_TRNS, KC_HOME, KC_PGDN, KC_END   \
    ),
/* Emoji Layer
 * ,--------------------------------------------------------------------------------------------------------.
 * | BASE | ANGRY|      |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------+------+------+------|
 * |      |      | POOP |      |      |      |      |      |      |      |      |      |             |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------+--------------------|
 * | Shift|      |      |      |      |      |      |      |      |      | SHRUG|    Shift    |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |                     WIDETXT                    |      |      |      |      |      |
 * `--------------------------------------------------------------------------------------------------------'
 */
    [EMJI] = LAYOUT(
        TO(BASE),ANGRY,   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, \
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, \
        KC_TRNS, KC_TRNS, X(POOP), KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,          KC_TRNS, \
        KC_LSFT, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, SHRUG,   KC_RSFT,          KC_TRNS, KC_TRNS, \
        KC_TRNS, UC_M_WC, KC_TRNS,                            WIDETXT,                            KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS  \
    ),

/* Layer
 * ,--------------------------------------------------------------------------------------------------------.
 * |   K  |   K  |   K  |   K  |   K  |   K  |   K  |   K  |   K  |   K  |   K  |   K  |   K  |   K  |   K  |
 * |------+------+------+------+------+------+------+------+------+------+------+------+------+------+------|
 * |   K  |   K  |   K  |   K  |   K  |   K  |   K  |   K  |   K  |   K  |   K  |   K  |   K  |   K  |   K  |
 * |------+------+------+------+------+-------------+------+------+------+------+------+------+------+------|
 * |   K  |   K  |   K  |   K  |   K  |   K  |   K  |   K  |   K  |   K  |   K  |   K  |      K      |   K  |
 * |------+------+------+------+------+------|------+------+------+------+------+------+--------------------|
 * |   K  |   K  |   K  |   K  |   K  |   K  |   K  |   K  |   K  |   K  |   K  |      K      |   K  |   K  |
 * |------+------+------+------+------+------+------+------+------+------+------+------+------+------+------|
 * |   K  |   K  |   K  |                        K                       |   K  |   K  |   K  |   K  |   K  |
 * `--------------------------------------------------------------------------------------------------------'
 */
    /*
    [X] = LAYOUT(
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, \
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, \
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,          KC_TRNS, \
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,          KC_TRNS, KC_TRNS, \
        KC_TRNS, KC_TRNS, KC_TRNS,                            KC_TRNS,                            KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS  \
    ),
    */
};

// Runs just one time when the keyboard initializes.
void matrix_init_user(void) {
    rgb_matrix_config.speed = UINT8_MAX/20;
    rgb_matrix_mode(RGB_MATRIX_CUSTOM_double_rainbow);
};

// Runs constantly in the background, in a loop.
void matrix_scan_user(void) {
};

#define MODS_SHIFT  (get_mods() & MOD_BIT(KC_LSHIFT) || get_mods() & MOD_BIT(KC_RSHIFT))
#define MODS_CTRL  (get_mods() & MOD_BIT(KC_LCTL) || get_mods() & MOD_BIT(KC_RCTRL))
#define MODS_ALT  (get_mods() & MOD_BIT(KC_LALT) || get_mods() & MOD_BIT(KC_RALT))

uint32_t layer_state_set_user(uint32_t state){
    switch (biton32(state)){
        case FUNC:
            rgb_matrix_config.speed = UINT8_MAX/2;
            rgb_matrix_mode(RGB_MATRIX_RAINDROPS);
            break;
        case EMJI:
            rgb_matrix_config.speed = UINT8_MAX/2;
            rgb_matrix_mode(RGB_MATRIX_RAINBOW_PINWHEELS);
            break;
        default:
            rgb_matrix_config.speed = UINT8_MAX/20;
            rgb_matrix_mode(RGB_MATRIX_CUSTOM_double_rainbow);
            break;
    }
    return state;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    static uint32_t key_timer;

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
        case U_T_AUTO:
            if (record->event.pressed && MODS_SHIFT && MODS_CTRL) {
                TOGGLE_FLAG_AND_PRINT(usb_extra_manual, "USB extra port manual mode");
            }
            return false;
        case U_T_AGCR:
            if (record->event.pressed && MODS_SHIFT && MODS_CTRL) {
                TOGGLE_FLAG_AND_PRINT(usb_gcr_auto, "USB GCR auto mode");
            }
            return false;
        case DBG_TOG:
            if (record->event.pressed) {
                TOGGLE_FLAG_AND_PRINT(debug_enable, "Debug mode");
            }
            return false;
        case DBG_MTRX:
            if (record->event.pressed) {
                TOGGLE_FLAG_AND_PRINT(debug_matrix, "Debug matrix");
            }
            return false;
        case DBG_KBD:
            if (record->event.pressed) {
                TOGGLE_FLAG_AND_PRINT(debug_keyboard, "Debug keyboard");
            }
            return false;
        case DBG_MOU:
            if (record->event.pressed) {
                TOGGLE_FLAG_AND_PRINT(debug_mouse, "Debug mouse");
            }
            return false;
        case MD_BOOT:
            if (record->event.pressed) {
                key_timer = timer_read32();
            } else {
                if (timer_elapsed32(key_timer) >= 500) {
                    reset_keyboard();
                }
            }
            return false;
        case KC_RHL:
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
            return true; //Process all other keycodes normally
    }
}
