#include QMK_KEYBOARD_H

enum ctrl_layers {
    _LOCKED,
    _BASE,
    _FUNCTION,
};

enum ctrl_keycodes {
    U_T_AUTO = SAFE_RANGE, //USB Extra Port Toggle Auto Detect / Always Active
    U_T_AGCR,              //USB Toggle Automatic GCR control
    DBG_TOG,               //DEBUG Toggle On / Off
    DBG_MTRX,              //DEBUG Toggle Matrix Prints
    DBG_KBD,               //DEBUG Toggle Keyboard Prints
    DBG_MOU,               //DEBUG Toggle Mouse Prints
    MD_BOOT,               //Restart into bootloader after hold timeout
};

#define TG_NKRO MAGIC_TOGGLE_NKRO //Toggle 6KRO / NKRO mode

keymap_config_t keymap_config;

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Locked Layer
 * ,------------------------------------------------------------------------------------------------------------------------.
 * | NOOP |      | NOOP | NOOP | NOOP | NOOP | NOOP | NOOP | NOOP | NOOP | NOOP | NOOP | NOOP | NOOP | | NOOP | NOOP | NOOP |
 * |------+      +------+------+------+------+------+------+------+------+------+------+------+------+ +------+------+------|
 * |                                                                                                                        |
 * |------+------+------+------+------+------+------+------+------+------+------+------+------+------+ +------+------+------|
 * | NOOP | NOOP | NOOP | NOOP | NOOP | NOOP | NOOP | NOOP | NOOP | NOOP | NOOP | NOOP | NOOP | NOOP | | NOOP | NOOP | NOOP |
 * |------+------+------+------+------+------+------+------+------+------+------+------+------+------+ +------+------+------|
 * | NOOP | NOOP | NOOP | NOOP |   R  | NOOP | NOOP |   U  | NOOP | NOOP | NOOP | NOOP | NOOP | TO(1)| | NOOP | NOOP | NOOP |
 * |------+------+------+------+------+-------------+------+------+------+------+------+------+------+ +------+------+------|
 * | NOOP |   A  | NOOP | NOOP | NOOP | NOOP |   H  | NOOP | NOOP |   L  | NOOP | NOOP |    Enter    |                      |
 * |------+------+------+------+------+------|------+------+------+------+------+------+-------------+        +------+      |
 * |    NOOP     | NOOP | NOOP | NOOP | NOOP | NOOP | NOOP | NOOP | NOOP | NOOP | NOOP |    NOOP     |        | NOOP |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------+------+------+ +------+------+------|
 * | NOOP | NOOP | NOOP |                      Space                     | NOOP | NOOP | NOOP | NOOP | | NOOP | NOOP | NOOP |
 * `------------------------------------------------------------------------------------------------------------------------'
 */
    [_LOCKED] = LAYOUT(
        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,              KC_NO,   KC_NO,   KC_NO,   \
        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,     KC_NO,   KC_NO,   KC_NO,   \
        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_R,    KC_NO,   KC_NO,   KC_U,    KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   TO(1),     KC_NO,   KC_NO,   KC_NO,   \
        KC_NO,   KC_A,    KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_H,    KC_NO,   KC_NO,   KC_L,    KC_NO,   KC_NO,   KC_ENT, \
        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   TG_NKRO, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,                                KC_NO,   \
        KC_NO,   UC_M_OS, KC_NO,                     KC_SPC,                             KC_NO,   KC_NO,   KC_NO,   KC_NO,              KC_NO,   KC_NO,   KC_NO   \
    ),
/* Base Layer
 * ,------------------------------------------------------------------------------------------------------------------------.
 * | Esc  |      |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 | | Print| Scrlk| Pause|
 * |------+      +------+------+------+------+------+------+------+------+------+------+------+------+ +------+------+------|
 * |                                                                                                                        |
 * |------+------+------+------+------+------+------+------+------+------+------+------+------+------+ +------+------+------|
 * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  |   -  |   =  | Bksp | | Ins  | Home | Pgup |
 * |------+------+------+------+------+------+------+------+------+------+------+------+------+------+ +------+------+------|
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  |   [  |   ]  |   \  | | Del  |  End | Pgdn |
 * |------+------+------+------+------+-------------+------+------+------+------+------+------+------+ +------+------+------|
 * | Esc  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |   '  |    Enter    |                      |
 * |------+------+------+------+------+------|------+------+------+------+------+------+-------------+        +------+      |
 * |    Shift    |   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |    Shift    |        |  Up  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------+------+------+ +------+------+------|
 * | Ctrl | Meta | Alt  |                      Space                     | Alt  | MO(0)|  GUI | Ctrl | | Left | Down |Right |
 * `------------------------------------------------------------------------------------------------------------------------'
 */
    [_BASE] = LAYOUT(
        KC_ESC,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,             KC_PSCR, KC_SLCK, KC_PAUS, \
        KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC,   KC_INS,  KC_HOME, KC_PGUP, \
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS,   KC_DEL,  KC_END,  KC_PGDN, \
        KC_ESC,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, KC_ENT, \
        KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,                              KC_UP, \
        KC_LCTL, KC_LGUI, KC_LALT,                   KC_SPC,                             KC_RALT, MO(2),   KC_APP,  KC_RCTL,            KC_LEFT, KC_DOWN, KC_RGHT \
    ),
/* Function Layer
 * ,------------------------------------------------------------------------------------------------------------------------.
 * |      |      |      |      |      |      |      |      |      |      |      |      |      |      | |      |      |      |
 * |------+      +------+------+------+------+------+------+------+------+------+------+------+------+ +------+------+------|
 * |                                                                                                                        |
 * |------+------+------+------+------+------+------+------+------+------+------+------+------+------+ +------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |      |      | |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------+------+------+ +------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |      |      | |      |      |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------+------+------+ +------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |             |                      |
 * |------+------+------+------+------+------|------+------+------+------+------+------+-------------+        +------+      |
 * |             |      |      |      |      |      |      |      |      |      |      |             |        |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------+------+------+ +------+------+------|
 * |      |      |      |                                                |      |      |      |      | |      |      |      |
 * `------------------------------------------------------------------------------------------------------------------------'
 */
    [_FUNCTION] = LAYOUT(
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,            KC_MUTE, KC_TRNS, KC_TRNS, \
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, TO(0),     KC_MPLY, KC_MSTP, KC_VOLU, \
        KC_TRNS, RGB_SPD, RGB_VAI, RGB_SPI, RGB_HUI, RGB_SAI, KC_TRNS, U_T_AUTO,U_T_AGCR,KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,   KC_MPRV, KC_MNXT, KC_VOLD, \
        KC_TRNS, RGB_RMOD,RGB_VAD, RGB_MOD, RGB_HUD, RGB_SAD, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, \
        KC_TRNS, RGB_TOG, KC_TRNS, KC_TRNS, KC_TRNS, MD_BOOT, TG_NKRO, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                              KC_TRNS, \
        KC_TRNS, KC_TRNS, KC_TRNS,                   KC_TRNS,                            KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,            KC_TRNS, KC_TRNS, KC_TRNS \
    ),
/* LayerN
 * ,------------------------------------------------------------------------------------------------------------------------.
 * |   K  |      |   K  |   K  |   K  |   K  |   K  |   K  |   K  |   K  |   K  |   K  |   K  |   K  | |   K  |   K  |   K  |
 * |------+      +------+------+------+------+------+------+------+------+------+------+------+------+ +------+------+------|
 * |                                                                                                                        |
 * |------+------+------+------+------+------+------+------+------+------+------+------+------+------+ +------+------+------|
 * |   K  |   K  |   K  |   K  |   K  |   K  |   K  |   K  |   K  |   K  |   K  |   K  |   K  |   K  | |   K  |   K  |   K  |
 * |------+------+------+------+------+------+------+------+------+------+------+------+------+------+ +------+------+------|
 * |   K  |   K  |   K  |   K  |   K  |   K  |   K  |   K  |   K  |   K  |   K  |   K  |   K  |   K  | |   K  |   K  |   K  |
 * |------+------+------+------+------+-------------+------+------+------+------+------+------+------+ +------+------+------|
 * |   K  |   K  |   K  |   K  |   K  |   K  |   K  |   K  |   K  |   K  |   K  |   K  |      K      |                      |
 * |------+------+------+------+------+------|------+------+------+------+------+------+-------------+        +------+      |
 * |      K      |   K  |   K  |   K  |   K  |   K  |   K  |   K  |   K  |   K  |   K  |      K      |        |   K  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------+------+------+ +------+------+------|
 * |   K  |   K  |   K  |                        K                       |   K  |   K  |   K  |   K  | |   K  |   K  |   K  |
 * `------------------------------------------------------------------------------------------------------------------------'
 */
    /*
    [X] = LAYOUT(
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,            KC_TRNS, KC_TRNS, KC_TRNS, \
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,   KC_TRNS, KC_TRNS, KC_TRNS, \
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,   KC_TRNS, KC_TRNS, KC_TRNS, \
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, \
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, TG_NKRO, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                              KC_TRNS, \
        KC_TRNS, KC_TRNS, KC_TRNS,                   KC_TRNS,                            KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,            KC_TRNS, KC_TRNS, KC_TRNS \
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

bool locked = true;
void rgb_matrix_indicators_user(void) {
    uint8_t mode;
    switch (biton32(layer_state)){
        case _LOCKED:
            mode = RGB_MATRIX_DIGITAL_RAIN;
            if (rgb_matrix_get_mode() != mode) {
                rgb_matrix_mode(mode);
            }
            locked = true;
            break;
        case _BASE:
            if (locked) {
                mode = RGB_MATRIX_RAINDROPS;
                if (rgb_matrix_get_mode() != mode) {
                    rgb_matrix_mode(mode);
                }
                locked = false;
            }
            break;
        /*
        case _FUNCTION:
            mode = RGB_MATRIX_JELLYBEAN_RAINDROPS;
            if (rgb_matrix_get_mode() != mode) {
                rgb_matrix_mode(mode);
            }
            break;
        default:
            mode = RGB_MATRIX_RAINBOW_PINWHEELS;
            if (rgb_matrix_get_mode() != mode) {
                rgb_matrix_mode(mode);
            }
            break;
        */
    }
}

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
        default:
            return true; //Process all other keycodes normally
    }
}
