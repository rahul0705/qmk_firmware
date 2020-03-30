#pragma once
#include "rahul0705.h"
#include "custom_tap_dance.h"

enum custom_layers {
    _BASE = 0,
    _GAME,
    _FUNC,
    _EMJI,
    _KEYMAP_LAYER_SAFE_RANGE,
};

bool process_record_keymap(uint16_t keycode, keyrecord_t *record);
