#pragma once
#ifdef TAP_DANCE_ENABLE

// Tap Dance Declarations
enum {
    SFT_CTRL_B = 0,
};

typedef enum {
    SINGLE_TAP,
    SINGLE_HOLD,
    DOUBLE_SINGLE_TAP,
} td_state_t;

#    define TD_SFT TD(SFT_CTRL_B)

#endif
