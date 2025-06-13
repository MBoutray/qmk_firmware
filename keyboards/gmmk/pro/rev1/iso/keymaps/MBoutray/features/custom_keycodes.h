/* Copyright 2024 MBoutray
 * Custom keycode definitions for multi-layout GMMK Pro configuration
 */

#pragma once

#include "quantum.h"

/* Tap dance actions */
void dance_rgui_sym_finished(tap_dance_state_t *state, void *user_data);
void dance_rgui_sym_reset(tap_dance_state_t *state, void *user_data);

/* Auto shift */
bool get_auto_shift_state(uint16_t keycode, keyrecord_t *record);

/* Per-key tapping term */
uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record);

/* Unicode handling */
void type_unicode_string(const char *str);

/* Custom Keycodes */
enum custom_keycodes {
    // Layout switching
    LAY_AZE = SAFE_RANGE,   // Switch to AZERTY
    LAY_QWE,                // Switch to QWERTY
    LAY_BPO,                // Switch to BÉPO

    // Vim-style navigation
    VIM_H,                  // Left (with modifiers)
    VIM_J,                  // Down (with modifiers)
    VIM_K,                  // Up (with modifiers)
    VIM_L,                  // Right (with modifiers)
    VIM_W,                  // Word forward
    VIM_B,                  // Word backward
    VIM_E,                  // End of word
    VIM_0,                  // Beginning of line
    VIM_DLR,                // End of line
    VIM_GG,                 // Beginning of document
    VIM_G,                  // End of document

    // French accents (lowercase)
    FR_E_ACUTE,             // é
    FR_E_GRAVE,             // è
    FR_A_GRAVE,             // à
    FR_U_GRAVE,             // ù
    FR_C_CEDILLA,           // ç
    FR_E_CIRC,              // ê
    FR_A_CIRC,              // â
    FR_I_CIRC,              // î
    FR_O_CIRC,              // ô
    FR_U_CIRC,              // û
    FR_E_TREMA,             // ë
    FR_I_TREMA,             // ï
    FR_U_TREMA,             // ü
    FR_OE,                  // œ
    FR_AE,                  // æ

    // French accents (uppercase)
    FR_E_ACUTE_MAJ,         // É
    FR_E_GRAVE_MAJ,         // È
    FR_A_GRAVE_MAJ,         // À
    FR_C_CEDILLA_MAJ,       // Ç

    // Smart brackets
    SMART_PAREN,            // ()
    SMART_BRACKET,          // []
    SMART_BRACE,            // {}
    SMART_ANGLE,            // <>
    SMART_QUOTE,            // ""
    SMART_SQUOTE,           // ''

    // RGB custom modes
    RGB_REAC_WIDE,
    RGB_REAC_MWIDE,
    RGB_SPL,
    RGB_MULT_SPL,
    RGB_SOL_SPL,
    RGB_SOL_MULT_SPL,

    // System functions
    SYS_SLEEP,              // System sleep
    SYS_WAKE,               // System wake
    EEPROM_RESET,           // Reset EEPROM

    // Macro recording
    DYN_REC_START1,         // Start recording macro 1
    DYN_REC_START2,         // Start recording macro 2
    DYN_REC_STOP,           // Stop recording
    DYN_MACRO_PLAY1,        // Play macro 1
    DYN_MACRO_PLAY2,        // Play macro 2

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
    _BASE = 0,              // Base layer (AZERTY/QWERTY/BÉPO)
    _FN,                    // Function layer
    _SYS,                   // System administration layer
    _NAV,                   // Navigation layer
    _SYM,                   // Symbols layer
    _GAME,                  // Gaming layer (no custom keys)
    _NUM,                   // Numpad layer
    _MACRO                  // Macro layer
};

/* Layout types */
enum layout_types {
    LAYOUT_AZERTY = 0,
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
#define MO_FN MO(_FN)
#define MO_SYS MO(_SYS)
#define MO_NAV MO(_NAV)
#define MO_SYM MO(_SYM)

/* Layer-tap shortcuts */
#define LT_NAV LT(_NAV, KC_CAPS)

/* Tap dance */
#define TD_RGUI TD(TD_RGUI_SYM)

/* Layer toggle shortcuts */
#define TG_GAME TG(_GAME)
#define TG_NUM TG(_NUM)
