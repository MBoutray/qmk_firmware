/* Copyright 2024 MBoutray
 * Custom keycode implementations for advanced features
 */
#include QMK_KEYBOARD_H
#include "custom_keycodes.h"
#include "quantum.h"

extern bool sym_one_shot;

/* Forward declarations */
void dance_space_paren_finished(tap_dance_state_t *state, void *user_data);
void dance_shift_caps_finished(tap_dance_state_t *state, void *user_data);
void dance_shift_caps_reset(tap_dance_state_t *state, void *user_data);
void dance_rgui_sym_finished(tap_dance_state_t *state, void *user_data);
void dance_rgui_sym_reset(tap_dance_state_t *state, void *user_data);

/* Actions definitions */
tap_dance_action_t tap_dance_actions[] = {
    [TD_SPC_PAREN] = ACTION_TAP_DANCE_FN(dance_space_paren_finished),
    [TD_SHIFT_CAPS] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, dance_shift_caps_finished, dance_shift_caps_reset),
    [TD_ESC_TILDE] = ACTION_TAP_DANCE_DOUBLE(KC_ESC, KC_TILD),
    [TD_QUOT_DQUOT] = ACTION_TAP_DANCE_DOUBLE(KC_QUOT, KC_DQUO),
    [TD_RGUI_SYM] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, dance_rgui_sym_finished, dance_rgui_sym_reset),
};

/* Tap Dance implementations */
void dance_space_paren_finished(tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
        tap_code(KC_SPC);
    } else if (state->count == 2) {
        tap_code16(KC_LPRN);
        tap_code16(KC_RPRN);
        tap_code(KC_LEFT);
    }
}

void dance_shift_caps_finished(tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
        register_code(KC_LSFT);
    } else if (state->count == 2) {
        tap_code(KC_CAPS);
    }
}

void dance_shift_caps_reset(tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
        unregister_code(KC_LSFT);
    }
}

void dance_rgui_sym_finished(tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
        // Single tap: Right GUI
        tap_code16(KC_RGUI);
    } else if (state->count == 2) {
        // Double tap: Symbols layer
        layer_on(_SYM);
        sym_one_shot = true;  // Enable one-shot for symbols
    }
}

void dance_rgui_sym_reset(tap_dance_state_t *state, void *user_data) {

}

/* Leader key sequences */
LEADER_EXTERNS();

void leader_matrix_scan_user(void) {
    LEADER_DICTIONARY() {
        leading = false;
        leader_end();
        
        // Email addresses
        SEQ_TWO_KEYS(KC_E, KC_M) {
            SEND_STRING("your.email@example.com");
        }
        
        // Common code snippets
        SEQ_TWO_KEYS(KC_F, KC_N) {
            SEND_STRING("function ");
        }
        
        SEQ_THREE_KEYS(KC_C, KC_O, KC_N) {
            SEND_STRING("console.log();");
            tap_code(KC_LEFT);
            tap_code(KC_LEFT);
        }
        
        // Git commands
        SEQ_TWO_KEYS(KC_G, KC_S) {
            SEND_STRING("git status");
        }
        
        SEQ_TWO_KEYS(KC_G, KC_P) {
            SEND_STRING("git push");
        }
        
        SEQ_TWO_KEYS(KC_G, KC_C) {
            SEND_STRING("git commit -m \"\"");
            tap_code(KC_LEFT);
        }
        
        // French phrases
        SEQ_THREE_KEYS(KC_B, KC_J, KC_R) {
            type_unicode_string("Bonjour");
        }
        
        SEQ_THREE_KEYS(KC_M, KC_R, KC_C) {
            type_unicode_string("Merci");
        }
    }
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
        case LT(_NAV, KC_CAPS):
            return 150;  // Slightly faster for nav layer
        default:
            return TAPPING_TERM;
    }
}

/* Key override definitions */
const key_override_t delete_key_override = ko_make_basic(MOD_MASK_SHIFT, KC_BSPC, KC_DEL);
const key_override_t grave_key_override = ko_make_basic(MOD_MASK_SHIFT, KC_ESC, KC_GRV);

// Array of key overrides
const key_override_t *key_overrides[] = {
    &delete_key_override,
    &grave_key_override,
    NULL
};

// ASCII-to-keycode lookup for common chars
static const uint16_t ascii_map[128] = {
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
static const char *unicode_map[256] = {
    [0xE9] = "00E9",  // é
    [0xE8] = "00E8",  // è
    [0xE0] = "00E0",  // à
    [0xF9] = "00F9",  // ù
    [0xE7] = "00E7",  // ç
    [0xC9] = "00C9",  // É
    [0xC8] = "00C8",  // È
    [0xC0] = "00C0",  // À
    [0xC7] = "00C7"   // Ç
};

void type_unicode_string(const char *str) {
    while (*str) {
        unsigned char c = (unsigned char)*str;

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
        else if (unicode_map[c]) {
            send_unicode_string(unicode_map[c]);
        }

        str++;
    }
}