#include "rahul0705.h"

const uint32_t PROGMEM unicode_map[] = {
    [THINK]     = 0x1F914,
    [GRIN]      = 0x1F600,
    [BBB]       = 0x1F171,
    [POO]       = 0x1F4A9,
    [HUNDR]     = 0x1F4AF,
    [SMRK]      = 0x1F60F,
    [WEARY]     = 0x1F629,
    [EGGPL]     = 0x1F346,
    [WATER]     = 0x1F4A6,
    [LIT]       = 0x1F525,
    [UNAMU]     = 0x1F612,
    [SNEK]      = 0x1F40D,
    [PENGUIN]   = 0x1F427,
    [BOAR]      = 0x1F417,
    [MONKEY]    = 0x1F412,
    [CHICK]     = 0x1F425,
    [DRAGON]    = 0x1F409,
    [OKOK]      = 0x1F44C,
    [EFFU]      = 0x1F595,
    [INUP]      = 0x1F446,
    [THDN]      = 0x1F44E,
    [THUP]      = 0x1F44D,
    [TUMBLER]   = 0x1F943,
    [BANG]      = 0x0203D,
    [IRONY]     = 0x02E2E,
    [DEGREE]    = 0x000B0
 };

__attribute__ ((weak))
void matrix_init_keymap(void){
}
void matrix_init_user(void) {
    rgb_matrix_config.speed = UINT8_MAX/20;
    rgb_matrix_mode(RGB_MATRIX_CUSTOM_up_down);
    matrix_init_keymap();
}

__attribute__ ((weak))
uint32_t layer_state_set_keymap(uint32_t state) {
    return state;
}
uint32_t layer_state_set_user(uint32_t state) {
    switch (biton32(state)){
        case _FUNC:
            rgb_matrix_config.speed = UINT8_MAX/2;
            rgb_matrix_mode(RGB_MATRIX_CYCLE_OUT_IN);
            break;
        case _EMJI:
            rgb_matrix_config.speed = UINT8_MAX/2;
            rgb_matrix_mode(RGB_MATRIX_CYCLE_OUT_IN_DUAL);
            break;
        default:
            rgb_matrix_config.speed = UINT8_MAX/20;
            rgb_matrix_mode(RGB_MATRIX_CUSTOM_up_down);
            break;
    }
    return layer_state_set_keymap(state);
}