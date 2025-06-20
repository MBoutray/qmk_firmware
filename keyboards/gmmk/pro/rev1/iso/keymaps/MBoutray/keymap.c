/* Copyright 2024 MBoutray
 * Multi-layout keymap for GMMK Pro ISO
 * Supports AZERTY, QWERTY, and BÉPO layouts with advanced features
 */

#include QMK_KEYBOARD_H
#include "sendstring_french.h"
#include "eeconfig.h"
#include "leader.h"
#include "features/custom_keycodes.h"
#include "features/vim_navigation.h"

/* Current layout tracking */
static uint8_t current_layout = LAYOUT_AZERTY_STANDARD;

/* Alt-Tab tracking */
static bool is_alt_tab_active = false;
static uint16_t alt_tab_timer;

/* Tap dance state */
bool sym_one_shot = false;

/* EEPROM layout storage */
typedef union {
    uint32_t raw;
    struct {
        uint8_t layout :2;
        uint8_t rgb_mode :6;
    };
} user_config_t;

user_config_t user_config;

/* Initialize keyboard */
void keyboard_post_init_user(void) {
    // Load saved layout from EEPROM
    user_config.raw = eeconfig_read_kb();
    current_layout = user_config.layout;

    // Set initial RGB mode based on layout
    #ifdef RGB_MATRIX_ENABLE
    switch (current_layout) {
        case LAYOUT_AZERTY_STANDARD:
            rgb_matrix_sethsv_noeeprom(0, 255, 255);    // Red for AZERTY standard
            break;
        case LAYOUT_AZERTY_AFNOR:
            rgb_matrix_sethsv_noeeprom(21, 255, 192);   // Orange for AZERTY Afnor
            break;
        case LAYOUT_QWERTY:
            rgb_matrix_sethsv_noeeprom(120, 255, 255);  // Green for QWERTY
            break;
        case LAYOUT_BEPO:
            rgb_matrix_sethsv_noeeprom(240, 255, 255);  // Blue for BÉPO
            break;
    }
    #endif
}

/* Main keymap */
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* AZERTY standard base layer*/
    [AZE_STD_BASE] = LAYOUT(
        /* 1       2        3        4        5        6        7        8        9        10       11       12       13       14       15       16  */
        KC_ESC,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_DEL,           KC_MUTE,
        FR_SUP2, FR_AMPR, FR_EACU, FR_DQUO, FR_QUOT, FR_LPRN, FR_MINS, FR_EGRV, FR_UNDS, FR_CCED, FR_AGRV, FR_RPRN, FR_EQL,  KC_BSPC,          KC_PSCR,
        KC_TAB,  FR_A,    FR_Z,    FR_E,    FR_R,    FR_T,    FR_Y,    FR_U,    FR_I,    FR_O,    FR_P,    FR_CIRC, FR_DLR,                    KC_INS,
        LT_NAVI, FR_Q,    FR_S,    FR_D,    FR_F,    FR_G,    FR_H,    FR_J,    FR_K,    FR_L,    FR_M,    FR_UGRV, FR_ASTR, KC_ENT,           KC_PGUP,
        KC_LSFT, FR_LABK, FR_W,    FR_X,    FR_C,    FR_V,    FR_B,    FR_N,    FR_COMM, FR_SCLN, FR_COLN, FR_EXLM,          KC_RSFT, KC_UP,   KC_PGDN,
        KC_LCTL, MO_FUNC, KC_LALT,                            KC_SPC,                             KC_RALT, TD_RGUI, KC_RCTL, KC_LEFT, KC_DOWN, KC_RGHT
    ),
    /* AZERTY Afnor base layer*/
    [AZE_AFN_BASE] = LAYOUT(
        /* 1       2        3        4        5        6        7        8        9        10       11       12       13       14       15       16  */
        KC_ESC,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_DEL,           KC_MUTE,
        FR_SUP2, FR_AMPR, FR_EACU, FR_DQUO, FR_QUOT, FR_LPRN, FR_MINS, FR_EGRV, FR_UNDS, FR_CCED, FR_AGRV, FR_RPRN, FR_EQL,  KC_BSPC,          KC_PSCR,
        KC_TAB,  FR_A,    FR_Z,    FR_E,    FR_R,    FR_T,    FR_Y,    FR_U,    FR_I,    FR_O,    FR_P,    FR_CIRC, FR_DLR,                    KC_INS,
        LT_NAVI, FR_Q,    FR_S,    FR_D,    FR_F,    FR_G,    FR_H,    FR_J,    FR_K,    FR_L,    FR_M,    FR_UGRV, FR_ASTR, KC_ENT,           KC_PGUP,
        KC_LSFT, FR_LABK, FR_W,    FR_X,    FR_C,    FR_V,    FR_B,    FR_N,    FR_COMM, FR_SCLN, FR_COLN, FR_EXLM,          KC_RSFT, KC_UP,   KC_PGDN,
        KC_LCTL, MO_FUNC, KC_LALT,                            KC_SPC,                             KC_RALT, TD_RGUI, KC_RCTL, KC_LEFT, KC_DOWN, KC_RGHT
    ),
    /* QWERTY base layer*/
    [QWE_BASE] = LAYOUT(
        /* 1       2        3        4        5        6        7        8        9        10       11       12       13       14       15       16  */
        KC_ESC,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_DEL,           KC_MUTE,
        KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC,          KC_PSCR,
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC,                   KC_INS,
        LT_NAVI, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, KC_NUHS, KC_ENT,           KC_PGUP,
        KC_LSFT, KC_NUBS, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,          KC_RSFT, KC_UP,   KC_PGDN,
        KC_LCTL, MO_FUNC, KC_LALT,                            KC_SPC,                             KC_RALT, TD_RGUI, KC_RCTL, KC_LEFT, KC_DOWN, KC_RGHT
    ),
    /* BEPO base layer*/
    [BEP_BASE] = LAYOUT(
        /* 1       2        3        4        5        6        7        8        9        10       11       12       13       14       15       16  */
        KC_ESC,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_DEL,           KC_MUTE,
        KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC,          KC_PSCR,
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC,                   KC_INS,
        LT_NAVI, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, KC_NUHS, KC_ENT,           KC_PGUP,
        KC_LSFT, KC_NUBS, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,          KC_RSFT, KC_UP,   KC_PGDN,
        KC_LCTL, MO_FUNC, KC_LALT,                            KC_SPC,                             KC_RALT, TD_RGUI, KC_RCTL, KC_LEFT, KC_DOWN, KC_RGHT
    ),
    /* Function layer */
    [FUNC] = LAYOUT(
        /* 1        2        3        4        5        6        7        8        9       10       11       12       13       14       15       16  */
        TO_SYST,  _______, _______, KC_F13, KC_F14,  KC_F15,  KC_F16,  KC_F17,  KC_F18,  KC_F19,  KC_F20,  KC_F21,  KC_F22,  _______,          _______,
        _______, KC_MPRV, KC_MPLY, KC_MNXT, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          KC_F23,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,                   KC_F24,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          KC_HOME,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, _______, KC_END,
        _______, _______, _______,                            _______,                            _______, _______, _______, _______, _______, _______
    ),
    /* Navigation layer - VIM-like cursor movement */
    [NAVI] = LAYOUT(
        /* 1        2        3        4        5        6        7        8        9       10       11       12       13       14       15       16  */
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
        _______, _______, VIM_W,   VIM_E,   _______, _______, _______, _______, _______, _______, _______, _______, _______,                   _______,
        _______, _______, _______, _______, _______, VIM_GG,  VIM_H,   VIM_J,   VIM_K,   VIM_L,   VIM_0,   VIM_DLR, _______, _______,          _______,
        _______, _______, _______, _______, _______, _______, VIM_B,   _______, _______, _______, _______, _______,          _______, _______, _______,
        _______, _______, _______,                            _______,                            _______, _______, _______, _______, _______, _______
    ),
    /* Symbols Layer - Programming & French Accents */
    [SYMB] = LAYOUT(
        /* 1        2           3        4           5             6        7        8           9         10           11       12             13           14       15       16  */
        _______, _______,    _______, _______,    _______,      _______, _______, _______,    _______,   _______,     _______, _______,       _______,     _______,          _______,
        _______, _______,    _______, _______,    _______,      _______, _______, _______,    _______,   _______,     _______, _______,       _______,     _______,          _______,
        _______, _______,    _______, _______,    FR_EACU,      _______, _______, FR_U_GRAVE, FR_I_CIRC, FR_O_CIRC,   _______, SMART_BRACKET, SMART_BRACE,                   _______,
        _______, _______,    _______, FR_EGRV,    _______,      _______, _______, _______,    _______,   _______,     _______, SMART_QUOTE,   _______,     _______,          _______,
        _______, _______,    _______, _______,    FR_C_CEDILLA, _______, _______, _______,    _______,   SMART_ANGLE, _______, _______,                    _______, _______, _______,
        _______, _______,    _______,                                    _______,                                     _______, _______,       _______,     _______, _______, _______
    ),
    /* Numpad Layer */
    [NUMP] = LAYOUT(
        /* 1        2        3        4        5        6        7        8        9       10       11       12       13       14       15       16  */
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
        _______, _______, _______, _______, _______, _______, _______, KC_P7,   KC_P8,   KC_P9,   KC_PSLS, _______, _______, _______,          TG_NUMP,
        _______, _______, _______, _______, _______, _______, _______, KC_P4,   KC_P5,   KC_P6,   KC_PAST, _______, _______,                   _______,
        _______, _______, _______, _______, _______, _______, _______, KC_P1,   KC_P2,   KC_P3,   KC_PMNS, _______, _______, KC_PENT,          _______,
        _______, _______, _______, _______, _______, _______, _______, KC_P0,   KC_P0,   KC_PDOT, KC_PPLS, _______,          _______, _______, _______,
        _______, _______, _______,                            _______,                            _______, _______, _______, _______, _______, _______
    ),
    /* Gaming Layer - No custom keys */
    [GAME] = LAYOUT(
        /* 1        2        3        4        5        6        7        8        9       10       11       12       13       14       15       16  */
        KC_ESC,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_DEL,           KC_MUTE,
        KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC,          TG_GAME,
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC,                   KC_INS,
        KC_CAPS, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, KC_NUHS, KC_ENT,           KC_PGUP,
        KC_LSFT, KC_NUBS, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,          KC_RSFT, KC_UP,   KC_PGDN,
        KC_LCTL, KC_LGUI, KC_LALT,                            KC_SPC,                             KC_RALT, KC_RGUI, KC_RCTL, KC_LEFT, KC_DOWN, KC_RGHT
    ),
    // /* System Administration Layer */
    // [_SYS] = LAYOUT(
    //     QK_BOOT, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, EEP_RST,          _______,
    //     _______, LAY_AZE, LAY_QWE, LAY_BPO, _______, _______, _______, _______, _______, _______, RGB_TOG, RGB_VAD, RGB_VAI, _______,          NK_TOGG,
    //     _______, _______, _______, _______, _______, _______, _______, _______, RGB_HUI, RGB_SAI, RGB_SPI, RGB_MOD, RGB_RMOD,                  AS_TOGG,
    //     _______, RGB_REAC_WIDE, RGB_REAC_MWIDE, RGB_SPL, RGB_MULT_SPL, RGB_SOL_SPL, RGB_SOL_MULT_SPL, _______, _______, _______, _______, _______, _______, _______,          TG_GAME,
    //     _______, _______, ______
    [SYST] = LAYOUT(
        /* 1        2        3        4        5        6        7        8        9       10       11       12       13       14       15       16  */
        TG_SYST, QK_BOOT, QK_MAKE, DB_TOGG, QK_RBT,  EE_CLR,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,          XXXXXXX,
        XXXXXXX, LAY_AZE_STD, LAY_QWE, LAY_BPO, XXXXXXX, TO_GAME, TO_NUMP, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, QK_BOOT,          XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,          XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,          XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX,                            XXXXXXX,                            XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
    ),
};

/* Process custom keycodes */
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    // Process vim navigation first
    if (!process_vim_navigation(keycode, record)) {
        return false;
    }

    // Alt-Tab handling
    if (is_alt_tab_active) {
        if (timer_elapsed(alt_tab_timer) > 1000) {
            unregister_code(KC_LALT);
            is_alt_tab_active = false;
        }
    }

    switch (keycode) {
        /* Layout switching */
        case LAY_AZE_STD:
            if (record->event.pressed) {
                current_layout = LAYOUT_AZERTY_STANDARD;
                user_config.layout = current_layout;
                eeconfig_update_kb(user_config.raw);
                #ifdef RGB_MATRIX_ENABLE
                rgb_matrix_sethsv_noeeprom(0, 255, 255);    // Red for AZERTY standard
                #endif
            }
            return false;

        case LAY_AZE_AFN:
            if (record->event.pressed) {
                current_layout = LAYOUT_AZERTY_AFNOR;
                user_config.layout = current_layout;
                eeconfig_update_kb(user_config.raw);
                #ifdef RGB_MATRIX_ENABLE
                rgb_matrix_sethsv_noeeprom(21, 255, 192);    // Orange for AZERTY Afnor
                #endif
            }
            return false;

        case LAY_QWE:
            if (record->event.pressed) {
                current_layout = LAYOUT_QWERTY;
                user_config.layout = current_layout;
                eeconfig_update_kb(user_config.raw);
                #ifdef RGB_MATRIX_ENABLE
                rgb_matrix_sethsv_noeeprom(120, 255, 255);  // Green for QWERTY
                #endif
            }
            return false;

        case LAY_BPO:
            if (record->event.pressed) {
                current_layout = LAYOUT_BEPO;
                user_config.layout = current_layout;
                eeconfig_update_kb(user_config.raw);
                #ifdef RGB_MATRIX_ENABLE
                rgb_matrix_sethsv_noeeprom(240, 255, 255);  // Blue for BÉPO
                #endif
            }
            return false;

        /* French accents - uppercase (with shift) */
        case FR_EACU_MAJ:
            if (record->event.pressed) {
                type_unicode_string("É");
            }
            return false;

        case FR_EGRV_MAJ:
            if (record->event.pressed) {
                type_unicode_string("È");
            }
            return false;

        case FR_A_GRAVE_MAJ:
            if (record->event.pressed) {
                type_unicode_string("À");
            }
            return false;

        case FR_C_CEDILLA_MAJ:
            if (record->event.pressed) {
                type_unicode_string("Ç");
            }
            return false;

        /* Smart brackets */
        case SMART_PAREN:
            if (record->event.pressed) {
                tap_code16(KC_LPRN);
                tap_code16(KC_RPRN);
                tap_code(KC_LEFT);
            }
            return false;

        case SMART_BRACKET:
            if (record->event.pressed) {
                tap_code16(KC_LBRC);
                tap_code16(KC_RBRC);
                tap_code(KC_LEFT);
            }
            return false;

        case SMART_BRACE:
            if (record->event.pressed) {
                tap_code16(KC_LCBR);
                tap_code16(KC_RCBR);
                tap_code(KC_LEFT);
            }
            return false;

        case SMART_ANGLE:
            if (record->event.pressed) {
                tap_code16(KC_LT);
                tap_code16(KC_GT);
                tap_code(KC_LEFT);
            }
            return false;

        case SMART_QUOTE:
            if (record->event.pressed) {
                tap_code16(KC_DQUO);
                tap_code16(KC_DQUO);
                tap_code(KC_LEFT);
            }
            return false;

        case SMART_SQUOTE:
            if (record->event.pressed) {
                tap_code16(KC_DQUO);
                tap_code16(KC_DQUO);
                tap_code(KC_LEFT);
            }
            return false;

        /* RGB custom modes */
        case RGB_REAC_WIDE:
            if (record->event.pressed) {
                rgb_matrix_mode(RGB_MATRIX_SOLID_REACTIVE_WIDE);
            }
            return false;

        case RGB_REAC_MWIDE:
            if (record->event.pressed) {
                rgb_matrix_mode(RGB_MATRIX_SOLID_REACTIVE_MULTIWIDE);
            }
            return false;

        case RGB_SPL:
            if (record->event.pressed) {
                rgb_matrix_mode(RGB_MATRIX_SPLASH);
            }
            return false;

        case RGB_MULT_SPL:
            if (record->event.pressed) {
                rgb_matrix_mode(RGB_MATRIX_MULTISPLASH);
            }
            return false;

        case RGB_SOL_SPL:
            if (record->event.pressed) {
                rgb_matrix_mode(RGB_MATRIX_SOLID_SPLASH);
            }
            return false;

        case RGB_SOL_MULT_SPL:
            if (record->event.pressed) {
                rgb_matrix_mode(RGB_MATRIX_SOLID_MULTISPLASH);
            }
            return false;

        /* Alt-Tab functionality */
        case ALT_TAB:
            if (record->event.pressed) {
                if (!is_alt_tab_active) {
                    is_alt_tab_active = true;
                    register_code(KC_LALT);
                }
                alt_tab_timer = timer_read();
                tap_code16(KC_TAB);
            }
            return false;

        /* Cross-platform clipboard */
        case CLIPBOARD_COPY:
            if (record->event.pressed) {
                tap_code16(LCTL(KC_C));
            }
            return false;

        case CLIPBOARD_PASTE:
            if (record->event.pressed) {
                tap_code16(LCTL(KC_V));
            }
            return false;

        case CLIPBOARD_CUT:
            if (record->event.pressed) {
                tap_code16(LCTL(KC_X));
            }
            return false;

        /* Tad dance */
        case TD(TD_RGUI_SYM):
            break;  // Handled in tap dance function

        default:
            // Reset one-shot symbol layer if necessary
            if(sym_one_shot && record->event.pressed && keycode != TD(TD_RGUI_SYM)) {
                layer_off(SYMB);
                sym_one_shot = false;
            }
    }

    return true;
}

/* Encoder functionality */
bool encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) {
        // Check which layer we're on
        switch (get_highest_layer(layer_state)) {
            case FUNC:
                // Media control on function layer
                if (clockwise) {
                    tap_code(KC_MNXT);
                } else {
                    tap_code(KC_MPRV);
                }
                break;
            case SYST:
                // RGB brightness on system layer
                if (clockwise) {
                    rgb_matrix_increase_val();
                } else {
                    rgb_matrix_decrease_val();
                }
                break;
            default:
                // Volume control on other layers
                if (clockwise) {
                    tap_code(KC_VOLU);
                } else {
                    tap_code(KC_VOLD);
                }
                break;
        }
    }
    return false;
}

/* Matrix scan for layout-specific key mapping */
void matrix_scan_user(void) {
    // This would be where we'd implement dynamic key remapping
    // based on current_layout if needed
}

/* Actions definitions */
tap_dance_action_t tap_dance_actions[] = {
    [TD_RGUI_SYM] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, dance_rgui_sym_finished, dance_rgui_sym_reset),
};

/* Layer state handling */
layer_state_t layer_state_set_user(layer_state_t state) {
    // Visual feedback for active layers
    #ifdef RGB_MATRIX_ENABLE
    switch (get_highest_layer(state)) {
        case FUNC:
            rgb_matrix_set_color_all(0, 0, 128);  // Blue for function layer
            break;
        case SYST:
            rgb_matrix_set_color_all(128, 0, 0);  // Red for system layer
            break;
        case NAVI:
            rgb_matrix_set_color_all(0, 128, 0);  // Green for navigation
            break;
        case SYMB:
            rgb_matrix_set_color_all(128, 128, 0); // Yellow for symbols
            break;
        case GAME:
            rgb_matrix_set_color_all(128, 0, 128); // Purple for gaming
            break;
        default:
            // Return to layout-specific color
            break;
    }
    #endif

    return state;
}
