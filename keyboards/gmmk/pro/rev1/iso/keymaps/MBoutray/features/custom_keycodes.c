#include "custom_keycodes.h"

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
