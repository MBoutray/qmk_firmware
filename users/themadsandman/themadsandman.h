#pragma once
#include keymap_french.h

#include "keymap_french.h"
#ifdef TAP_DANCE_ENABLE
    #include "tap_dance.h"
#endif

//Custom keys
#define KC_GAME     MO(_GM)
#define KC_FN       MO(_FN)

//Layers
enum userspace_layers {
  _EK,      //Base EurKey keymap
  _AZ,      //Base AZERTY keymap
  _EK_S,     //EurKey + Shift
  _EK_A,     //EurKey + Alt Gr
  _EK_SA,    //EurKey + Shift & Alt Gr
  _AZ_S,     //AZERTY + Shift
  _AZ_A,     //AZERTY + Alt Gr
  _AZ_SA,    //AZERTY + Shift & Alt Gr
  _GM,      //Gaming layer (basic AZERTY without shortcuts)
  _FN,      //Function layer
  _SYS      //System layer
};

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
