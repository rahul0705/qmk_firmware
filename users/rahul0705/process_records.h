#pragma once
#include "rahul0705.h"
#include "custom_tap_dance.h"

enum custom_layers {
    _BASE = 0,
    _GAME,
    _FUNC,
    _EMJI,
};

bool process_record_keymap(uint16_t keycode, keyrecord_t *record);
