/* Copyright 2024 MBoutray
 * Custom keycode implementations for advanced features
 */
#include QMK_KEYBOARD_H
#include "custom_keycodes.h"
#include "quantum.h"

extern bool sym_one_shot;

/* Tap Dance implementations */
void dance_rgui_sym_finished(tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
        // Single tap: Right GUI
        tap_code16(KC_RGUI);
    } else if (state->count == 2) {
        // Double tap: Symbols layer
        layer_on(SYMB);
        sym_one_shot = true;  // Enable one-shot for symbols
    }
}

void dance_rgui_sym_reset(tap_dance_state_t *state, void *user_data) {

}

/* Auto Shift configuration */
bool get_auto_shift_state(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        // Disable auto shift for these keys
        case KC_SPC:
        case KC_ENT:
        case KC_TAB:
        case KC_BSPC:
        case KC_DEL:
            return false;
        default:
            return true;
    }
}

/* Per-key tapping term */
uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case MT(MOD_LCTL, KC_ESC):
            return 100;  // Faster response for Ctrl/Esc
        case LT(NAVI, KC_CAPS):
            return 150;  // Slightly faster for nav layer
        default:
            return TAPPING_TERM;
    }
}
