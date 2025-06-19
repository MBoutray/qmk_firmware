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

// ASCII-to-keycode lookup for common chars
const uint16_t ascii_map[128] = {
    [' '] = KC_SPC,      ['.'] = KC_DOT,      [','] = KC_COMM,
    ['!'] = S(KC_1),     ['?'] = S(KC_SLSH),  ['@'] = S(KC_2),
    ['#'] = S(KC_3),     ['$'] = S(KC_4),     ['%'] = S(KC_5),
    ['^'] = S(KC_6),     ['&'] = S(KC_7),     ['*'] = S(KC_8),
    ['('] = S(KC_9),     [')'] = S(KC_0),     ['-'] = KC_MINS,
    ['_'] = S(KC_MINS),  ['='] = KC_EQL,      ['+'] = S(KC_EQL),
    ['['] = KC_LBRC,     [']'] = KC_RBRC,     ['{'] = S(KC_LBRC),
    ['}'] = S(KC_RBRC),  [';'] = KC_SCLN,     [':'] = S(KC_SCLN),
    ['\''] = KC_QUOT,    ['"'] = S(KC_QUOT),  ['/'] = KC_SLSH,
    ['\\'] = KC_BSLS,    ['<'] = S(KC_COMM),  ['>'] = S(KC_DOT)
};

// Unicode hex codes for French accents (indexed by unsigned char)
const uint32_t PROGMEM unicode_map[] = {
    [FR_EACU_MAJ] = 0x00C9,  // É
    [FR_EGRV_MAJ] = 0x00C8,  // È
    [FR_AGRV_MAJ] = 0x00C0,  // À
    [FR_ECIR_MAJ] = 0x00CA,  // Ê
    [FR_CCED_MAJ] = 0x00C7   // Ç
};

void type_unicode_string(const char *str) {
    while (*str) {
        uint8_t c = (uint8_t)*str;

        // Letters
        if (c >= 'a' && c <= 'z') {
            tap_code(KC_A + (c - 'a'));
        } else if (c >= 'A' && c <= 'Z') {
            tap_code(S(KC_A + (c - 'A')));
        }
        // Digits
        else if (c >= '0' && c <= '9') {
            tap_code(KC_0 + (c - '0'));
        }
        // Common ASCII symbols
        else if (c < 128 && ascii_map[c]) {
            tap_code(ascii_map[c]);
        }
        // Accented letters via Unicode
        else {
            uint32_t code = pgm_read_dword(&unicode_map[c]);
            if (code) {
                register_unicode(code);
            }
        }

        str++;
    }
}
