/* Copyright 2024 MBoutray
 * Custom keycode implementations for advanced features
 */

#include "custom_keycodes.h"
#include "quantum.h"

/* Tap Dance implementations */
// Define tap dance actions
void dance_space_paren_finished(qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
        tap_code(KC_SPC);
    } else if (state->count == 2) {
        tap_code16(KC_LPRN);
        tap_code16(KC_RPRN);
        tap_code(KC_LEFT);
    }
}

void dance_shift_caps_finished(qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
        register_code(KC_LSFT);
    } else if (state->count == 2) {
        tap_code(KC_CAPS);
    }
}

void dance_shift_caps_reset(qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
        unregister_code(KC_LSFT);
    }
}

// Tap Dance definitions
qk_tap_dance_action_t tap_dance_actions[] = {
    [TD_SPC_PAREN] = ACTION_TAP_DANCE_FN(dance_space_paren_finished),
    [TD_SHIFT_CAPS] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, dance_shift_caps_finished, dance_shift_caps_reset),
    [TD_ESC_TILDE] = ACTION_TAP_DANCE_DOUBLE(KC_ESC, KC_TILD),
    [TD_QUOT_DQUOT] = ACTION_TAP_DANCE_DOUBLE(KC_QUOT, KC_DQUO),
};

/* Leader key sequences */
LEADER_EXTERNS();

void matrix_scan_user(void) {
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
            send_unicode_string("Bonjour");
        }
        
        SEQ_THREE_KEYS(KC_M, KC_R, KC_C) {
            send_unicode_string("Merci");
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

/* Helper function for sending Unicode strings */
void send_unicode_string(const char *str) {
    while (*str) {
        uint16_t keycode = 0;
        
        // Map characters to keycodes (simplified for common chars)
        if (*str >= 'a' && *str <= 'z') {
            keycode = KC_A + (*str - 'a');
        } else if (*str >= 'A' && *str <= 'Z') {
            keycode = S(KC_A + (*str - 'A'));
        } else if (*str >= '0' && *str <= '9') {
            keycode = KC_0 + (*str - '0');
        } else {
            // Special characters
            switch (*str) {
                case ' ': keycode = KC_SPC; break;
                case '.': keycode = KC_DOT; break;
                case ',': keycode = KC_COMM; break;
                case '!': keycode = S(KC_1); break;
                case '?': keycode = S(KC_SLSH); break;
                case '@': keycode = S(KC_2); break;
                case '#': keycode = S(KC_3); break;
                case '$': keycode = S(KC_4); break;
                case '%': keycode = S(KC_5); break;
                case '^': keycode = S(KC_6); break;
                case '&': keycode = S(KC_7); break;
                case '*': keycode = S(KC_8); break;
                case '(': keycode = S(KC_9); break;
                case ')': keycode = S(KC_0); break;
                case '-': keycode = KC_MINS; break;
                case '_': keycode = S(KC_MINS); break;
                case '=': keycode = KC_EQL; break;
                case '+': keycode = S(KC_EQL); break;
                case '[': keycode = KC_LBRC; break;
                case ']': keycode = KC_RBRC; break;
                case '{': keycode = S(KC_LBRC); break;
                case '}': keycode = S(KC_RBRC); break;
                case ';': keycode = KC_SCLN; break;
                case ':': keycode = S(KC_SCLN); break;
                case '\'': keycode = KC_QUOT; break;
                case '"': keycode = S(KC_QUOT); break;
                case '/': keycode = KC_SLSH; break;
                case '\\': keycode = KC_BSLS; break;
                case '<': keycode = S(KC_COMM); break;
                case '>': keycode = S(KC_DOT); break;
                
                // French special characters (requires Unicode input method)
                case 'é': send_string(SS_LALT("0233")); str++; continue;
                case 'è': send_string(SS_LALT("0232")); str++; continue;
                case 'à': send_string(SS_LALT("0224")); str++; continue;
                case 'ù': send_string(SS_LALT("0249")); str++; continue;
                case 'ç': send_string(SS_LALT("0231")); str++; continue;
                case 'É': send_string(SS_LALT("0201")); str++; continue;
                case 'È': send_string(SS_LALT("0200")); str++; continue;
                case 'À': send_string(SS_LALT("0192")); str++; continue;
                case 'Ç': send_string(SS_LALT("0199")); str++; continue;
            }
        }
        
        if (keycode) {
            tap_code16(keycode);
        }
        
        str++;
    }
}