#pragma once
#include "quantum.h"

#ifdef TAP_DANCE_ENABLE

#include "process_tap_dance.h"

//Tap Dance Declarations
enum {
  SFT_CTRL_B = 0 // `RSHFT` when held, `CTRL + B` when tapped
};

// define a type containing as many tapdance states as you need
typedef enum {
  SINGLE_TAP,
  SINGLE_HOLD,
  DOUBLE_SINGLE_TAP
} td_state_t;

#define TD_SFT TD(SFT_CTRL_B)

#endif
