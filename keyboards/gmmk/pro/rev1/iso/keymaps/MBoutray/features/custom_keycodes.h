/* Copyright 2024 MBoutray
 * Custom keycode definitions for multi-layout GMMK Pro configuration
 */

#pragma once

#include "quantum.h"
#include "keymap_french.h"

// Defining Afnor specific keycodes
#define AF_AT   KC_GRV   // @
#define AF_AGRV KC_1     // à
#define AF_EACU FR_EACU  // é
#define AF_EGRV KC_3     // è
#define AF_ECIR KC_4     // ê
#define AF_LPRN FR_LPRN  // (
#define AF_RPRN KC_6     // )
#define AF_LSQU KC_7     // ‘
#define AF_RSQU KC_8     // ’
#define AF_LDAQ KC_9     // «
#define AF_RDAQ KC_0     // »
#define AF_QUOT KC_MINS  // '
#define AF_CIRC KC_EQL   // ^ (dead)
#define AF_A    FR_A     // A
#define AF_Z    FR_Z     // Z
#define AF_E    FR_E     // E
#define AF_R    FR_R     // R
#define AF_T    FR_T     // T
#define AF_Y    FR_Y     // Y
#define AF_U    FR_U     // U
#define AF_I    FR_I     // I
#define AF_O    FR_O     // O
#define AF_P    FR_P     // P
#define AF_MINS KC_LBRC  // -
#define AF_PLUS KC_RBRC  // +
#define AF_Q    FR_Q     // Q
#define AF_S    FR_S     // S
#define AF_D    FR_D     // D
#define AF_F    FR_F     // F
#define AF_G    FR_G     // G
#define AF_H    FR_H     // H
#define AF_J    FR_J     // J
#define AF_K    FR_K     // K
#define AF_L    FR_L     // L
#define AF_M    FR_M     // M
#define AF_SLSH KC_QUOT  // /
#define AF_ASTR FR_ASTR  // *
#define AF_LABK FR_LABK  // <
#define AF_W    FR_W     // W
#define AF_X    FR_X     // X
#define AF_C    FR_C     // C
#define AF_V    FR_V     // V
#define AF_B    FR_B     // B
#define AF_N    FR_N     // N
#define AF_DOT  KC_M     // .
#define AF_COMM KC_COMM  // ,
#define AF_COLN FR_COLN  // :
#define AF_SCLN KC_SLSH  // ;
#define AF_HASH S(AF_AT)        // #
#define AF_1    S(AF_AGRV)      // 1
#define AF_2    S(AF_EACU)      // 2
#define AF_3    S(AF_EGRV)      // 3
#define AF_4    S(AF_ECIR)      // 4
#define AF_5    S(AF_LPRN)      // 5
#define AF_6    S(AF_RPRN)      // 6
#define AF_7    S(AF_LSQU)      // 7
#define AF_8    S(AF_RSQU)      // 8
#define AF_9    S(AF_LDAQ)      // 9
#define AF_0    S(AF_RDAQ)      // 0
#define AF_DQUO S(AF_QUOT)      // "
#define AF_DIAE S(AF_CIRC)      // ¨ (dead)
#define AF_NDSH S(AF_MINS)      // –
#define AF_PLMN S(AF_PLUS)      // ±
#define AF_BSLS S(AF_SLSH)      // (backslash)
#define AF_HALF S(AF_ASTR)      // ½
#define AF_RABK S(AF_LABK)      // >
#define AF_QUES S(AF_DOT)       // ?
#define AF_EXLM S(AF_COMM)      // !
#define AF_ELLP S(AF_COLN)      // …
#define AF_EQL  S(AF_SCLN)      // =
#define AF_BREV ALGR(AF_AT)     // ˘ (dead)
#define AF_SECT ALGR(AF_AGRV)   // §
#define AF_ACUT ALGR(AF_EACU)   // ´ (dead)
#define AF_GRV  ALGR(AF_EGRV)   // ` (dead)
#define AF_AMPR ALGR(AF_ECIR)   // &
#define AF_LBRC ALGR(AF_LPRN)   // [
#define AF_RBRC ALGR(AF_RPRN)   // ]
#define AF_MACR ALGR(AF_LSQU)   // ¯ (dead)
#define AF_UNDS ALGR(AF_RSQU)   // _
#define AF_LDQU ALGR(AF_LDAQ)   // “
#define AF_RDQU ALGR(AF_RDAQ)   // ”
#define AF_DEG  ALGR(AF_QUOT)   // °
#define AF_CARN ALGR(AF_CIRC)   // ˇ (dead)
#define AF_AE   ALGR(AF_A)      // æ
#define AF_PND  ALGR(AF_Z)      // £
#define AF_EURO ALGR(AF_E)      // €
#define AF_REGD ALGR(AF_R)      // ®
#define AF_LCBR ALGR(AF_T)      // {
#define AF_RCBR ALGR(AF_Y)      // }
#define AF_UGRV ALGR(AF_U)      // ù
#define AF_DOTA ALGR(AF_I)      // ˙ (dead)
#define AF_OE   ALGR(AF_O)      // œ
#define AF_PERC ALGR(AF_P)      // %
#define AF_MMNS ALGR(AF_MINS)   // −
#define AF_DAGG ALGR(AF_PLUS)   // †
#define AF_THET ALGR(AF_Q)      // θ
#define AF_SS   ALGR(AF_S)      // ß
#define AF_DLR  ALGR(AF_D)      // $
#define AF_CURR ALGR(AF_F)      // ¤ (dead monetary key)
#define AF_DGRK ALGR(AF_G)      // µ (dead Greek key)
#define AF_EU   ALGR(AF_H)      // Eu (dead European symbol key)
#define AF_DSLS ALGR(AF_K)      // ∕ (dead)
#define AF_PIPE ALGR(AF_L)      // |
#define AF_INFN ALGR(AF_M)      // ∞
#define AF_DIV  ALGR(AF_SLSH)   // ÷
#define AF_MUL  ALGR(AF_ASTR)   // ×
#define AF_LEQL ALGR(AF_LABK)   // ≤
#define AF_EZH  ALGR(AF_W)      // ʒ
#define AF_COPY ALGR(AF_X)      // ©
#define AF_CCED ALGR(AF_C)      // ç
#define AF_CEDL ALGR(AF_V)      // ¸ (dead)
#define AF_DMNS ALGR(AF_B)      // − (dead)
#define AF_DTIL ALGR(AF_N)      // ~ (dead)
#define AF_IQUE ALGR(AF_DOT)    // ¿
#define AF_IEXL ALGR(AF_COMM)     // ¡
#define AF_MDDT ALGR(AF_COLN)     // ·
#define AF_AEQL ALGR(AF_SCLN)     // ≃
#define AF_IBRV S(ALGR(AF_AT))    // ̑  (dead)
#define AF_DACU S(ALGR(AF_LPRN))  // ˝ (dead)
#define AF_DGRV S(ALGR(AF_RPRN))  // ̏  (dead)
#define AF_MDSH S(ALGR(AF_RSQU))  // —
#define AF_LSAQ S(ALGR(AF_LDAQ))  // ‹
#define AF_RSAQ S(ALGR(AF_RDAQ))  // ›
#define AF_RNGA S(ALGR(AF_QUOT))  // ˚ (dead)
#define AF_TM   S(ALGR(AF_T))     // ™
#define AF_DOTB S(ALGR(AF_I))     // ̣  (dead)
#define AF_PERM S(ALGR(AF_P))     // ‰
#define AF_NBHY S(ALGR(AF_MINS))  // ‑ (non-breaking hyphen)
#define AF_DDAG S(ALGR(AF_PLUS))  // ‡
#define AF_MACB S(ALGR(AF_H))     // ˍ (dead)
#define AF_SQRT S(ALGR(AF_SLSH))  // √
#define AF_QRTR S(ALGR(AF_ASTR))  // ¼
#define AF_GEQL S(ALGR(AF_LABK))  // ≥
#define AF_OGON S(ALGR(AF_V))     // ˛ (dead)
#define AF_DCMM S(ALGR(AF_COMM))  // ̦  (dead)
#define AF_NEQL S(ALGR(AF_SCLN))  // ≠

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
