#include QMK_KEYBOARD_H
#include "rahul0705.h"

#define TG_NKRO MAGIC_TOGGLE_NKRO  // Toggle 6KRO / NKRO mode

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
     * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |       TD_SFT       |        |  Up  |      |
     * |------+------+------+------+------+------+------+------+------+------+------+------+------+------+ +------+------+------|
     * | Ctrl | Meta | Alt  |                      Space                     | Alt  | FUNC |  GUI | Ctrl | | Left | Down |Right |
     * `------------------------------------------------------------------------------------------------------------------------'
     */
    [_BASE] = LAYOUT(  // clang-format off
        KC_ESC,   KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,               KC_PSCR,  KC_SLCK,  KC_PAUS, \
        KC_GRV,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,  KC_EQL,   KC_BSPC,    KC_INS,   KC_HOME,  KC_PGUP, \
        KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,     KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_LBRC,  KC_RBRC,  KC_BSLS,    KC_DEL,   KC_END,   KC_PGDN, \
        KC_ESC,   KC_A,     KC_S,     KC_D,     KC_F,     KC_G,     KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,  KC_ENT,   \
        KC_LSFT,  KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,  TD_SFT,                                   KC_UP,    \
        KC_LCTL,  KC_LGUI,  KC_LALT,                                KC_SPC,                                 KC_RALT,  MO(_FUNC),KC_APP,   KC_RCTL,    KC_LEFT,  KC_DOWN,  KC_RGHT  // clang-format on
        ),
    /* Game Layer
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
     * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |        Shift       |        |  Up  |      |
     * |------+------+------+------+------+------+------+------+------+------+------+------+------+------+ +------+------+------|
     * | Ctrl | Meta | Alt  |                      Space                     | Alt  | FUNC |  GUI | Ctrl | | Left | Down |Right |
     * `------------------------------------------------------------------------------------------------------------------------'
     */
    [_GAME] = LAYOUT(  // clang-format off
        KC_ESC,   KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,               KC_PSCR,  KC_SLCK,  KC_PAUS, \
        KC_GRV,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,  KC_EQL,   KC_BSPC,    KC_INS,   KC_HOME,  KC_PGUP, \
        KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,     KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_LBRC,  KC_RBRC,  KC_BSLS,    KC_DEL,   KC_END,   KC_PGDN, \
        KC_ESC,   KC_A,     KC_S,     KC_D,     KC_F,     KC_G,     KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,  KC_ENT,   \
        KC_LSFT,  KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,  KC_RSFT,                                  KC_UP,    \
        KC_LCTL,  KC_LGUI,  KC_LALT,                                KC_SPC,                                 KC_RALT,  MO(_FUNC),KC_APP,   KC_RCTL,    KC_LEFT,  KC_DOWN,  KC_RGHT  // clang-format on
        ),
    /* Function Layer
     * ,------------------------------------------------------------------------------------------------------------------------.
     * | Rahul|      |      |      |      |      |      |      |      |      |      |      |      |        | Mute |      |      |
     * |------+------+------+------+------+------+------+------+------+------+------+------+------+        +------+------+------|
     * |------+------+------+------+------+------+------+------+------+------+------+------+------+------+ +------+------+------|
     * |      |      |      |      |      |      |      |      |      |      |      |      |      |      | | Play | Stop | VolU |
     * |------+------+------+------+------+------+------+------+------+------+------+------+------+------+ +------+------+------|
     * |      | L_SPD| L_BRI| L_SPI|      |      |      |   ?  |   ?  |      |      |      |      | EMJI | | Prev | Next | VolD |
     * |------+------+------+------+------+-------------+------+------+------+------+------+------+------+ +------+------+------|
     * |      |L_MODP| L_DIM|L_MODN|      | GAME |      |      |      |      |      |      |             |                      |
     * |------+------+------+------+------+------|------+------+------+------+------+------+-------------+        +------+      |
     * |      | L_TOG|      |      |      | BOOT | NKRO |      |      |      |      |                    |        | L_SAI|      |
     * |------+------+------+------+------+------+------+------+------+------+------+------+------+------+ +------+------+------|
     * |      |      |      |                                                |      |      |      |      | | L_HUD| L_SAD| L_HUI|
     * `------------------------------------------------------------------------------------------------------------------------'
     */
    [_FUNC] = LAYOUT(  // clang-format off
        RAHUL,    KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,              KC_MUTE,  KC_TRNS,  KC_TRNS, \
        KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,    KC_MPLY,  KC_MSTP,  KC_VOLU, \
        KC_TRNS,  RGB_SPD,  RGB_VAI,  RGB_SPI,  KC_TRNS,  KC_TRNS,  KC_TRNS,  U_T_AUTO, U_T_AGCR, KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  TG(_EMJI),  KC_MPRV,  KC_MNXT,  KC_VOLD, \
        KC_TRNS,  RGB_RMOD, RGB_VAD,  RGB_MOD,  KC_TRNS,  TG(_GAME),KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  \
        KC_TRNS,  RGB_TOG,  KC_TRNS,  KC_TRNS,  KC_TRNS,  MD_BOOT,  TG_NKRO,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,                                  RGB_SAI,  \
        KC_TRNS,  KC_TRNS,  KC_TRNS,                                KC_TRNS,                                KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,    RGB_HUD,  RGB_SAD,  RGB_HUI  // clang-format on
        ),
    /* Emoji Layer
     * ,------------------------------------------------------------------------------------------------------------------------.
     * |      |      |      |      |      |      |      |      |      |      |      |      |      |        |      |      |      |
     * |------+------+------+------+------+------+------+------+------+------+------+------+------+        +------+------+------|
     * |------+------+------+------+------+------+------+------+------+------+------+------+------+------+ +------+------+------|
     * |      | ANGRY|      |      |      |      |      |      |      |      |      |      |      |      | |      |      |      |
     * |------+------+------+------+------+------+------+------+------+------+------+------+------+------+ +------+------+------|
     * |      |      |      |      |      |      |      |      |      |      |      |      |      |      | |      |      |      |
     * |------+------+------+------+------+-------------+------+------+------+------+------+------+------+ +------+------+------|
     * |      |      | POOP |      |      |      |      |      |      |      |      |      |             |                      |
     * |------+------+------+------+------+------|------+------+------+------+------+------+-------------+        +------+      |
     * | Shift|      |      |      |      |      |      |      |      |      | SHRUG|        Shift       |        |      |      |
     * |------+------+------+------+------+------+------+------+------+------+------+------+------+------+ +------+------+------|
     * | E_MAC| W_WIN|      |                     WIDETXT                    |      | FUNC |      |      | |      |      |      |
     * `------------------------------------------------------------------------------------------------------------------------'
     */
    [_EMJI] = LAYOUT(  // clang-format off
        KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,              KC_TRNS,  KC_TRNS,  KC_TRNS, \
        KC_TRNS,  ANGRY,    KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,    KC_TRNS,  KC_TRNS,  KC_TRNS, \
        KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,    KC_TRNS,  KC_TRNS,  KC_TRNS, \
        KC_TRNS,  KC_TRNS,  X(POO),   KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  \
        KC_LSFT,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  TG_NKRO,  KC_TRNS,  KC_TRNS,  KC_TRNS,  SHRUG,    KC_RSFT,                                  KC_TRNS,  \
        UC_M_OS,  UC_M_WC,  KC_TRNS,                                WIDETXT,                                KC_TRNS,  MO(_FUNC),KC_TRNS,  KC_TRNS,    KC_TRNS,  KC_TRNS,  KC_TRNS  // clang-format on
        ),
    /* Layer N
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
    [X] = LAYOUT( // clang-format on
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,            KC_TRNS, KC_TRNS, KC_TRNS, \
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,   KC_TRNS, KC_TRNS, KC_TRNS, \
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,   KC_TRNS, KC_TRNS, KC_TRNS, \
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, \
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                              KC_TRNS, \
        KC_TRNS, KC_TRNS, KC_TRNS,                            KC_TRNS,                            KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,   KC_TRNS, KC_TRNS, KC_TRNS // clang-format om
    ),
    */
    /* LED Map
     * ,------------------------------------------------------------------------------------------------------------------------.
     * |   0  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |  10  |  11  |  12  |        |  13  |  14  |  15  |
     * |------+------+------+------+------+------+------+------+------+------+------+------+------+        +------+------+------|
     * |------+------+------+------+------+------+------+------+------+------+------+------+------+------+ +------+------+------|
     * |  16  |  17  |  18  |  19  |  20  |  21  |  22  |  23  |  24  |  25  |  26  |  27  |  28  |  29  | |  30  |  31  |  32  |
     * |------+------+------+------+------+------+------+------+------+------+------+------+------+------+ +------+------+------|
     * |  33  |  34  |  35  |  36  |  37  |  38  |  39  |  40  |  41  |  42  |  43  |  44  |  45  |  46  | |  47  |  48  |  49  |
     * |------+------+------+------+------+-------------+------+------+------+------+------+------+------+ +------+------+------|
     * |  50  |  51  |  52  |  53  |  54  |  55  |  56  |  57  |  58  |  59  |  60  |  61  |     62      |                      |
     * |------+------+------+------+------+------|------+------+------+------+------+------+-------------+        +------+      |
     * |  63  |  64  |  65  |  66  |  67  |  68  |  69  |  70  |  71  |  72  |  73  |         74         |        |  75  |      |
     * |------+------+------+------+------+------+------+------+------+------+------+------+------+------+ +------+------+------|
     * |  76  |  77  |  78  |                       79                       |  80  |  81  |  82  |  83  | |  84  |  85  |  86  |
     * `------------------------------------------------------------------------------------------------------------------------'
     */
};

void rgb_matrix_indicators_user(void) {
    if (!rgb_matrix_get_suspend_state() && rgb_matrix_config.enable) {
        switch (biton32(layer_state)) {
            case _FUNC:
                // G - Game Layer
                rgb_matrix_set_color(55, 0xFF, 0xFF, 0xFF);
                // \ - EMOJI Layer
                rgb_matrix_set_color(46, 0xFF, 0xFF, 0xFF);

                // Insert - Play
                rgb_matrix_set_color(30, 0xFF, 0xFF, 0xFF);
                // Home - Stop
                rgb_matrix_set_color(31, 0xFF, 0xFF, 0xFF);
                // End - Next
                rgb_matrix_set_color(48, 0xFF, 0xFF, 0xFF);
                // Delete - Previous
                rgb_matrix_set_color(47, 0xFF, 0xFF, 0xFF);

                // Print - Mute
                rgb_matrix_set_color(13, 0xFF, 0x00, 0x00);
                // Page Up - Volume Up
                rgb_matrix_set_color(32, 0x00, 0xFF, 0x00);
                // Page Down - Volume Down
                rgb_matrix_set_color(49, 0xFF, 0xFF, 0x00);

                // D - RGB Next Mode
                rgb_matrix_set_color(53, 0xFF, 0xFF, 0xFF);
                // A - RGB Previous Mode
                rgb_matrix_set_color(51, 0xFF, 0xFF, 0xFF);

                // E - RGB Speed Increase
                rgb_matrix_set_color(36, 0x00, 0xFF, 0x00);
                // Q - RGB Speed Decrease
                rgb_matrix_set_color(34, 0xFF, 0xFF, 0x00);

                // Right - RGB Hue Increase
                rgb_matrix_set_color(86, 0xFF, 0xFF, 0xFF);
                // Left - RGB Hue Decrease
                rgb_matrix_set_color(84, 0xFF, 0xFF, 0xFF);

                // Up - RGB Saturation Increase
                rgb_matrix_set_color(75, 0xFF, 0xFF, 0xFF);
                // Down - RGB Saturation Decrease
                rgb_matrix_set_color(85, 0xFF, 0xFF, 0xFF);

                // W - RGB Value Increase
                rgb_matrix_set_color(35, 0xFF, 0xFF, 0xFF);
                // S - RGB Value Decrease
                rgb_matrix_set_color(52, 0xFF, 0xFF, 0xFF);

                // Z - RGB Toggle
                rgb_matrix_set_color(64, 0x00, 0x00, 0x00);

                // B - Boot
                rgb_matrix_set_color(68, 0xFF, 0xFF, 0xFF);

                // N - N Key Roll Over
                rgb_matrix_set_color(69, 0xFF, 0xFF, 0xFF);

                // Escape - RAHUL
                rgb_matrix_set_color(0, 0xFF, 0xFF, 0xFF);
                break;
        }
    }
}

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
            return true;  // Process all other keycodes normally
    }
}
