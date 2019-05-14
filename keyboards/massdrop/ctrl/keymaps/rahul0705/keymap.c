#include QMK_KEYBOARD_H
#include "rahul0705.h"

#define TG_NKRO MAGIC_TOGGLE_NKRO //Toggle 6KRO / NKRO mode

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Base Layer
 * ,------------------------------------------------------------------------------------------------------------------------.
 * | Esc  |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |        | Print| Scrlk| Pause|
 * |------+------+------+------+------+------+------+------+------+------+------+------+------+        +------+------+------|
 * |------+------+------+------+------+------+------+------+------+------+------+------+------+------+ +------+------+------|
 * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  |   -  |   =  | Bksp | | Ins  | Home | Pgup |
 * |------+------+------+------+------+------+------+------+------+------+------+------+------+------+ +------+------+------|
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  |   [  |   ]  |   \  | | Del  |  End | Pgdn |
 * |------+------+------+------+------+-------------+------+------+------+------+------+------+------+ +------+------+------|
 * | Esc  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |   '  |    Enter    |                      |
 * |------+------+------+------+------+------|------+------+------+------+------+------+-------------+        +------+      |
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |       Ctrl(B)      |        |  Up  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------+------+------+ +------+------+------|
 * | Ctrl | Meta | Alt  |                      Space                     | Alt  | FUNC |  GUI | Ctrl | | Left | Down |Right |
 * `------------------------------------------------------------------------------------------------------------------------'
 */
    [_BASE] = LAYOUT(
        KC_ESC,   KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,               KC_PSCR,  KC_SLCK,  KC_PAUS, \
        KC_GRV,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,  KC_EQL,   KC_BSPC,    KC_INS,   KC_HOME,  KC_PGUP, \
        KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,     KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_LBRC,  KC_RBRC,  KC_BSLS,    KC_DEL,   KC_END,   KC_PGDN, \
        KC_ESC,   KC_A,     KC_S,     KC_D,     KC_F,     KC_G,     KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,  KC_ENT,   \
        KC_LSFT,  KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,  LCTL(KC_B),                               KC_UP,    \
        KC_LCTL,  KC_LGUI,  KC_LALT,                      KC_SPC,                                 KC_RALT,  MO(_FUNC),KC_APP,   KC_RCTL,              KC_LEFT,  KC_DOWN,  KC_RGHT \
    ),
/* Function Layer
 * ,------------------------------------------------------------------------------------------------------------------------.
 * | Rahul|      |      |      |      |      |      |      |      |      |      |      |      |        | Mute |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------+------+        +------+------+------|
 * |------+------+------+------+------+------+------+------+------+------+------+------+------+------+ +------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |      |      | | Play | Stop | VolU |
 * |------+------+------+------+------+------+------+------+------+------+------+------+------+------+ +------+------+------|
 * |      | L_SPI| L_BRI| L_SPD| L_HUI| L_SAI|      |   ?  |   ?  |      |      |      |      | EMJI | | Prev | Next | VolD |
 * |------+------+------+------+------+-------------+------+------+------+------+------+------+------+ +------+------+------|
 * |      |L_MODP| L_DIM|L_MODN| L_HUD| L_SAD|      |      |      |      |      |      |             |                      |
 * |------+------+------+------+------+------|------+------+------+------+------+------+-------------+        +------+      |
 * |      | L_TOG|      |      |      | BOOT | NKRO |      |      |      |      |                    |        |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------+------+------+ +------+------+------|
 * |      |      |      |                                                |      |      |      |      | |      |      |      |
 * `------------------------------------------------------------------------------------------------------------------------'
 */
    [_FUNC] = LAYOUT(
        RAHUL,    KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,              KC_MUTE,  KC_TRNS,  KC_TRNS, \
        KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,    KC_MPLY,  KC_MSTP,  KC_VOLU, \
        KC_TRNS,  RGB_SPD,  RGB_VAI,  RGB_SPI,  RGB_HUI,  RGB_SAI,  KC_TRNS,  U_T_AUTO, U_T_AGCR, KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  TO(_EMJI),   KC_MPRV,  KC_MNXT,  KC_VOLD, \
        KC_TRNS,  RGB_RMOD, RGB_VAD,  RGB_MOD,  RGB_HUD,  RGB_SAD,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  \
        KC_TRNS,  RGB_TOG,  KC_TRNS,  KC_TRNS,  KC_TRNS,  MD_BOOT,  TG_NKRO,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,                                  KC_TRNS,  \
        KC_TRNS,  KC_TRNS,  KC_TRNS,                      KC_TRNS,                                KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,              KC_TRNS,  KC_TRNS,  KC_TRNS \
    ),
/* Emoji Layer
 * ,------------------------------------------------------------------------------------------------------------------------.
 * | BASE |      |      |      |      |      |      |      |      |      |      |      |      |        |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------+------+        +------+------+------|
 * |------+------+------+------+------+------+------+------+------+------+------+------+------+------+ +------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |      |      | |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------+------+------+ +------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |      |      | |      |      |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------+------+------+ +------+------+------|
 * |      |      | POOP |      |      |      |      |      |      |      |      |      |             |                      |
 * |------+------+------+------+------+------|------+------+------+------+------+------+-------------+        +------+      |
 * | Shift|      |      |      |      |      |      |      |      |      | SHRUG|        Shift       |        |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------+------+------+ +------+------+------|
 * | E_MAC| W_WIN|      |                     WIDETXT                    |      |      |      |      | |      |      |      |
 * `------------------------------------------------------------------------------------------------------------------------'
 */
    [_EMJI] = LAYOUT(
        TO(_BASE),ANGRY,    KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,              KC_TRNS,  KC_TRNS,  KC_TRNS, \
        KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,    KC_TRNS,  KC_TRNS,  KC_TRNS, \
        KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,    KC_TRNS,  KC_TRNS,  KC_TRNS, \
        KC_TRNS,  KC_TRNS,  X(POO),   KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  \
        KC_LSFT,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  TG_NKRO,  KC_TRNS,  KC_TRNS,  KC_TRNS,  SHRUG,    KC_RSFT,                                  KC_TRNS,  \
        UC_M_OS,  UC_M_WC,  KC_TRNS,                      WIDETXT,                                KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,              KC_TRNS,  KC_TRNS,  KC_TRNS \
    ),
/* LayerN
 * ,------------------------------------------------------------------------------------------------------------------------.
 * |   K  |   K  |   K  |   K  |   K  |   K  |   K  |   K  |   K  |   K  |   K  |   K  |   K  |        |   K  |   K  |   K  |
 * |------+------+------+------+------+------+------+------+------+------+------+------+------+        +------+------+------|
 * |------+------+------+------+------+------+------+------+------+------+------+------+------+------+ +------+------+------|
 * |   K  |   K  |   K  |   K  |   K  |   K  |   K  |   K  |   K  |   K  |   K  |   K  |   K  |   K  | |   K  |   K  |   K  |
 * |------+------+------+------+------+------+------+------+------+------+------+------+------+------+ +------+------+------|
 * |   K  |   K  |   K  |   K  |   K  |   K  |   K  |   K  |   K  |   K  |   K  |   K  |   K  |   K  | |   K  |   K  |   K  |
 * |------+------+------+------+------+-------------+------+------+------+------+------+------+------+ +------+------+------|
 * |   K  |   K  |   K  |   K  |   K  |   K  |   K  |   K  |   K  |   K  |   K  |   K  |      K      |                      |
 * |------+------+------+------+------+------|------+------+------+------+------+------+-------------+        +------+      |
 * |   K  |   K  |   K  |   K  |   K  |   K  |   K  |   K  |   K  |   K  |   K  |          K         |        |   K  |      |
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

bool process_record_keymap(uint16_t keycode, keyrecord_t *record) {
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
