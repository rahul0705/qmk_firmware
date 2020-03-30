#include "rahul0705.h"

__attribute__((weak)) void matrix_init_keymap(void) {}

void matrix_init_user(void) {
#ifdef RGB_MATRIC_ENABLE
    rgb_matrix_config.speed = UINT8_MAX / 20;
    rgb_matrix_mode(RGB_MATRIX_CUSTOM_up_down);
#endif
    matrix_init_keymap();
}

__attribute__((weak)) uint32_t layer_state_set_keymap(uint32_t state) { return state; }

uint32_t layer_state_set_user(uint32_t state) {
#ifdef RGB_MATRIX_ENABLE
    switch (biton32(state)) {
        case _EMJI:
            rgb_matrix_config.speed = UINT8_MAX / 2;
            rgb_matrix_mode(RGB_MATRIX_CYCLE_SPIRAL);
            break;
        case _FUNC:
            rgb_matrix_config.speed = UINT8_MAX / 2;
            rgb_matrix_mode(RGB_MATRIX_CYCLE_OUT_IN_DUAL);
            break;
        case _GAME:
            rgb_matrix_config.speed = UINT8_MAX / 10;
            rgb_matrix_mode(RGB_MATRIX_CYCLE_OUT_IN);
            break;
        default:
            rgb_matrix_config.speed = UINT8_MAX / 20;
            rgb_matrix_mode(RGB_MATRIX_CUSTOM_up_down);
            break;
    }
#endif
    return layer_state_set_keymap(state);
}
