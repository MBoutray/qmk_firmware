#pragma once
#include QMK_KEYBOARD_H

#include "keymap_french.h"
#ifdef TAP_DANCE_ENABLE
    #include "tap_dance.h"
#endif

//Activation of tap dances if the feature is enabled
#ifdef TAP_DANCE_ENABLE
#    define KC_SPC_ENT TD(TD_SPC_ENT)
#    define KC_BSPC_CAPS TD(TD_BSPC_CAPS)
#    define KC_PGUP_HOME TD(TD_PGUP_HOME)
#    define KC_PGDO_END TD(TD_PGDO_END)
#    define KC_LPRN_LCBR_LBRC TD(TD_LPRN_LCBR_LBRC)
#    define KC_RPRN_RCBR_RBRC TD(TD_RPRN_RCBR_RBRC)
#else  // TAP_DANCE_ENABLE
#    define KC_SPC_ENT KC_SPC
#    define KC_BSPC_CAPS KC_CAPS
#    define KC_PGUP_HOME KC_PGUP
#    define KC_PGDO_END KC_PGDO
#    define KC_LPRN_LCBR_LBRC KC_LPRN
#    define KC_RPRN_RCBR_RBRC KC_RPRN
#endif  // TAP_DANCE_ENABLE
