#include QMK_KEYBOARD_H

enum alt_layers {
    //_LOCKED,
    _BASE,
    _FUNCTION,
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
 * | Ctrl | Meta |  Alt |                      Space                     |  Alt | MO(0)| Left | Down | Right|
 * `--------------------------------------------------------------------------------------------------------'
 */
    [_BASE] = LAYOUT(
        KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC, KC_DEL,  \
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS, KC_HOME, \
        KC_ESC,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,          KC_ENT,  KC_PGUP, \
        KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, LCTL(KC_B),       KC_UP,   KC_PGDN, \
        KC_LCTL, KC_LGUI, KC_LALT,                            KC_SPC,                             KC_RALT, MO(1),   KC_LEFT, KC_DOWN, KC_RGHT  \
    ),
/* Function Layer
 * ,--------------------------------------------------------------------------------------------------------.
 * | Rahul|  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 | Bksp | Mute |
 * |------+------+------+------+------+------+------+------+------+------+------+------+------+------+------|
 * |      | L_SPI| L_BRI| L_SPD| L_HUI| L_SAI|      |   ?  |   ?  |      | Print| Scrlk| Pause|      | End  |
 * |------+------+------+------+------+-------------+------+------+------+------+------+------+------+------|
 * |      |L_MODP| L_DIM|L_MODN| L_HUD| L_SAD|      |      |      |      |      |      |             | VolU |
 * |------+------+------+------+------+------|------+------+------+------+------+------+--------------------|
 * |      | L_TOG|      |      |      | BOOT | NKRO |  DBG |      |      |      |             | Pgup | VolD |
 * |------+------+------+------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |                                                |      |      | Home | Pgdn | End  |
 * `--------------------------------------------------------------------------------------------------------'
 */
    [_FUNCTION] = LAYOUT(
        KC_RHL,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_TRNS, KC_MUTE, \
        KC_TRNS, RGB_SPD, RGB_VAI, RGB_SPI, RGB_HUI, RGB_SAI, KC_TRNS, U_T_AUTO,U_T_AGCR,KC_TRNS, KC_PSCR, KC_SLCK, KC_PAUS, KC_TRNS, KC_END, \
        KC_TRNS, RGB_RMOD,RGB_VAD, RGB_MOD, RGB_HUD, RGB_SAD, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,          KC_TRNS, KC_VOLU, \
        KC_TRNS, RGB_TOG, KC_TRNS, KC_TRNS, KC_TRNS, MD_BOOT, TG_NKRO, DBG_TOG, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,          KC_PGUP, KC_VOLD, \
        KC_TRNS, KC_TRNS, KC_TRNS,                            KC_TRNS,                            KC_TRNS, KC_TRNS, KC_HOME, KC_PGDN, KC_END  \
    ),
/* Function Layer
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
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,          KC_TRNS, KC_TRNS, \
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,          KC_TRNS, KC_TRNS, \
        KC_TRNS, KC_TRNS, KC_TRNS,                            KC_TRNS,                            KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS  \
    ),
    */
};

// Runs just one time when the keyboard initializes.
void matrix_init_user(void) {
};

// Runs constantly in the background, in a loop.
void matrix_scan_user(void) {
};

#define MODS_SHIFT  (get_mods() & MOD_BIT(KC_LSHIFT) || get_mods() & MOD_BIT(KC_RSHIFT))
#define MODS_CTRL  (get_mods() & MOD_BIT(KC_LCTL) || get_mods() & MOD_BIT(KC_RCTRL))
#define MODS_ALT  (get_mods() & MOD_BIT(KC_LALT) || get_mods() & MOD_BIT(KC_RALT))

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    static uint32_t key_timer;

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
        default:
            return true; //Process all other keycodes normally
    }
}
