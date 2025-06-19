/* Copyright 2024 MBoutray
 * Custom keycode definitions for multi-layout GMMK Pro configuration
 */

#pragma once

#include "quantum.h"
#include "keymap_french.h"

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
    LAY_AZE_STD = SAFE_RANGE,   // Switch to AZERTY Standard
    LAY_AZE_AFN,   // Switch to AZERTY Afnor
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
    FR_OE,                  // œ (not present on AZERTY kb)
    FR_AE,                  // æ (not present on AZERTY kb)

    // French accents (uppercase)
    FR_EACU_MAJ,            // É (not present on AZERTY kb)
    FR_EGRV_MAJ,            // È (not present on AZERTY kb)
    FR_AGRV_MAJ,            // À (not present on AZERTY kb)
    FR_ECIR_MAJ,            // Ê (not present on AZERTY kb)
    FR_CCED_MAJ,            // Ç (not present on AZERTY kb)

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
