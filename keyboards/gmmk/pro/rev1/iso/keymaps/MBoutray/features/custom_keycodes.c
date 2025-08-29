#include "custom_keycodes.h"

extern bool sym_one_shot;

/* Per-key tapping term */
uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case MT(MOD_LCTL, KC_ESC):
            return 100;  // Faster response for Ctrl/Esc
        default:
            return TAPPING_TERM;
    }
}
