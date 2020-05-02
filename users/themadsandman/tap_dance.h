#pragma once
#include "themadsandman.h"

//#ifdef TAP_DANCE_ENABLE //Deactivate tap dances if file too big
enum {
    TD_SPC_ENT = 0,    // Space | Enter | Hold: Fn
    TD_BSPC_CAPS,       // Backspace | Caps lock
    TD_PGUP_HOME,       // Page up | Home
    TD_PGDO_END,        // Page down | End
    TD_LPRN_LCBR_LBRC,  // Left parenthesis | Left curly bracket | Left bracket
    TD_RPRN_RCBR_RBRC,  // Right parenthesis | Right curly bracket | Right bracket
};
//#endif

//Advanced tap dances
typedef struct {
  bool is_press_action;
  int state;
} tap;

enum {
  SINGLE_TAP = 1,
  SINGLE_HOLD = 2,
  DOUBLE_TAP = 3,
  DOUBLE_HOLD = 4,
  DOUBLE_SINGLE_TAP = 5, //send two single taps
  TRIPLE_TAP = 6,
  TRIPLE_HOLD = 7
};

int cur_dance (qk_tap_dance_state_t *state);

