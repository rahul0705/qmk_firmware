#include "quantum.h"
#include "process_tap_dance.h"
#include "custom_tap_dance.h"
#include "custom_keycodes.h"

#ifdef TAP_DANCE_ENABLE

// create a global instance of the tapdance state type
static td_state_t td_state;

// determine the tapdance state to return
int cur_dance(qk_tap_dance_state_t *state) {
    if (state->count == 1) {
        if (state->interrupted || !state->pressed) {
            return SINGLE_TAP;
        } else {
            return SINGLE_HOLD;
        }
    }
    if (state->count == 2) {
        return DOUBLE_SINGLE_TAP;
    } else {
        return 3;
    }  // any number higher than the maximum state value you return above
}

void sftctrlb_finished(qk_tap_dance_state_t *state, void *user_data) {
    td_state = cur_dance(state);
    switch (td_state) {
        case SINGLE_TAP:
            register_code16(LCTL(KC_B));
            break;
        case SINGLE_HOLD:
            register_code(KC_RSFT);
            break;
        case DOUBLE_SINGLE_TAP:
            tap_code16(LCTL(KC_B));
            register_code16(KC_B);
    }
}

void sftctrlb_reset(qk_tap_dance_state_t *state, void *user_data) {
    switch (td_state) {
        case SINGLE_TAP:
            unregister_code16(LCTL(KC_B));
            break;
        case SINGLE_HOLD:
            unregister_code(KC_RSFT);
            break;
        case DOUBLE_SINGLE_TAP:
            unregister_code16(KC_B);
    }
}

// Tap Dance Definitions
qk_tap_dance_action_t tap_dance_actions[] = {
    [SFT_CTRL_B] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, sftctrlb_finished, sftctrlb_reset),
};

#endif
