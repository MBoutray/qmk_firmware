#pragma once

#include "quantum.h"

/* Tap dance actions */
void dance_rgui_sym_finished(tap_dance_state_t *state, void *user_data);
void dance_rgui_sym_reset(tap_dance_state_t *state, void *user_data);

/* Auto shift */
bool get_auto_shift_state(uint16_t keycode, keyrecord_t *record);

/* Per-key tapping term */
uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record);

/* Custom Keycodes */
enum custom_keycodes {
    // Layout switching
    LAY_AZE_STD = SAFE_RANGE,   // Switch to AZERTY Standard
    LAY_AZE_AFN,                // Switch to AZERTY Afnor
    LAY_QWE,                    // Switch to QWERTY
    LAY_BPO,                    // Switch to BÉPO

    // Vim-style navigation
    VIM_H,                      // Left (with modifiers)
    VIM_J,                      // Down (with modifiers)
    VIM_K,                      // Up (with modifiers)
    VIM_L,                      // Right (with modifiers)
    VIM_W,                      // Word forward
    VIM_B,                      // Word backward
    VIM_E,                      // End of word
    VIM_0,                      // Beginning of line
    VIM_DLR,                    // End of line
    VIM_GG,                     // Beginning of document
    VIM_G,                      // End of document

    // AZERTY Afnor specific keycodes
    AF_AT,
    AF_AGRV,
    AF_EACU,
    AF_EGRV,
    AF_ECIR,
    AF_LPRN,
    AF_RPRN,
    AF_LSQU,
    AF_RSQU,
    AF_LDAQ,
    AF_RDAQ,
    AF_QUOT,
    AF_CIRC,
    AF_A,
    AF_Z,
    AF_E,
    AF_R,
    AF_T,
    AF_Y,
    AF_U,
    AF_I,
    AF_O,
    AF_P,
    AF_MINS,
    AF_PLUS,
    AF_Q,
    AF_S,
    AF_D,
    AF_F,
    AF_G,
    AF_H,
    AF_J,
    AF_K,
    AF_L,
    AF_M,
    AF_SLSH,
    AF_ASTR,
    AF_LABK,
    AF_W,
    AF_X,
    AF_C,
    AF_V,
    AF_B,
    AF_N,
    AF_DOT,
    AF_COMM,
    AF_COLN,
    AF_SCLN,

    // Smart brackets
    SMART_PAREN,                // ()
    SMART_BRACKET,              // []
    SMART_BRACE,                // {}
    SMART_ANGLE,                // <>
    SMART_QUOTE,                // ""
    SMART_SQUOTE,               // ''

    // RGB custom modes
    RGB_REAC_WIDE,
    RGB_REAC_MWIDE,
    RGB_SPL,
    RGB_MULT_SPL,
    RGB_SOL_SPL,
    RGB_SOL_MULT_SPL,

    // Special functions
    ALT_TAB,                // Alt-Tab functionality
    CMD_TAB,                // Cmd-Tab for macOS
    CLIPBOARD_COPY,         // Cross-platform copy
    CLIPBOARD_PASTE,        // Cross-platform paste
    CLIPBOARD_CUT,          // Cross-platform cut

    // Custom safe range for user
    NEW_SAFE_RANGE
};

/* Layer definitions */
enum layers {
    AZE_STD_BASE = 0,           // Base layer - AZERTY layout
    AZE_AFN_BASE,           // Base layer - AZERTY layout, AFNOR version
    QWE_BASE,               // Base layer - QWERTY layout
    BEP_BASE,               // Base layer - BÉPO layout
    FUNC,                   // Function layer
    SYST,                   // System administration layer
    NAVI,                   // Navigation layer
    SYMB,                   // Symbols layer
    GAME,                   // Gaming layer (no custom keys)
    NUMP                    // Numpad layer
};

/* Layout types */
enum layout_types {
    LAYOUT_AZERTY_STANDARD = 0,
    LAYOUT_AZERTY_AFNOR,
    LAYOUT_QWERTY,
    LAYOUT_BEPO,
    LAYOUT_COUNT
};

/* Tap Dance declarations */
enum tap_dances {
    TD_RGUI_SYM = 0,            // Right GUI / Symbols layer
};

/* Helper macros for cleaner keymap */
#define NAV_H VIM_H
#define NAV_J VIM_J
#define NAV_K VIM_K
#define NAV_L VIM_L

/* Momentary layer shortcuts */
#define MO_FUNC MO(FUNC)
#define MO_SYST MO(SYST)
#define MO_NAVI MO(NAVI)
#define MO_SYMB MO(SYMB)

/* Layer-tap shortcuts */
#define LT_NAVI LT(NAVI, KC_CAPS)

/* Tap dance */
#define TD_RGUI TD(TD_RGUI_SYM)

/* Layer toggle shortcuts */
#define TG_GAME TG(GAME)
#define TG_NUMP TG(NUMP)
#define TG_SYST TG(SYST)

/* Turn on a layer, turn off the rest (except base) */
#define TO_SYST TO(SYST)
#define TO_GAME TO(GAME)
#define TO_NUMP TO(NUMP)
