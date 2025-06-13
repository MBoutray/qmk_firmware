/* Copyright 2024 MBoutray
 * Multi-layout keymap for GMMK Pro ISO
 * Supports AZERTY, QWERTY, and BÉPO layouts with advanced features
 */

#include QMK_KEYBOARD_H
#include "features/custom_keycodes.h"
#include "features/vim_navigation.h"

/* Current layout tracking */
static uint8_t current_layout = LAYOUT_AZERTY;

/* Alt-Tab tracking */
static bool is_alt_tab_active = false;
static uint16_t alt_tab_timer;

/* Macro recording state */
static bool is_recording = false;

/* Tap dance state */
static bool sym_one_shot = false;

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
    user_config.raw = eeconfig_read_user();
    current_layout = user_config.layout;
    
    // Set initial RGB mode based on layout
    #ifdef RGB_MATRIX_ENABLE
    switch (current_layout) {
        case LAYOUT_AZERTY:
            rgb_matrix_sethsv_noeeprom(0, 255, 255);    // Red for AZERTY
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
    /* Base Layer - Dynamic based on current_layout */
    [_BASE] = LAYOUT(
        KC_ESC,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_DEL,           KC_MUTE,
        KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC,          KC_PSCR,
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC,                   KC_INS,
        LT_NAV,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, KC_NUHS, KC_ENT,           KC_PGUP,
        KC_LSFT, KC_NUBS, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,          KC_RSFT, KC_UP,   KC_PGDN,
        KC_LCTL, MO_FN,   KC_LALT,                            KC_SPC,                             KC_RALT, TD_RGUI,  KC_RCTL, KC_LEFT, KC_DOWN, KC_RGHT
    ),

    /* Function Layer - Media & Function Keys */
    [_FN] = LAYOUT(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, _______, TG_NUM,
        _______, _______, _______,                            _______,                            _______, _______, _______, _______, _______, _______
    ),

    /* Navigation Layer - Vim-style */
    [_NAV] = LAYOUT(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
        _______, _______, VIM_W,   VIM_E,   _______, _______, _______, _______, _______, _______, _______, _______, _______,                   _______,
        _______, _______, _______, _______, _______, VIM_GG,  VIM_H,   VIM_J,   VIM_K,   VIM_L,   VIM_0,   VIM_DLR, _______, _______,          _______,
        _______, _______, _______, _______, _______, _______, VIM_B,   _______, _______, _______, _______, _______,          _______, _______, _______,
        _______, _______, _______,                            _______,                            _______, _______, _______, _______, _______, _______
    ),

    /* Symbols Layer - Programming & French Accents */
    [_SYM] = LAYOUT(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
        _______, _______, _______, FR_E_ACUTE, _______, _______, _______, FR_U_GRAVE, FR_I_CIRC, FR_O_CIRC, _______, SMART_BRACKET, SMART_BRACE,      _______,
        _______, FR_A_GRAVE, _______, _______, _______, _______, _______, _______, _______, _______, _______, SMART_QUOTE, _______, _______,          _______,
        _______, _______, _______, _______, FR_C_CEDILLA, _______, _______, _______, _______, SMART_ANGLE, _______, _______,     _______, _______, _______,
        _______, _______, _______,                            _______,                            _______, _______, _______, _______, _______, _______
    ),

    /* Gaming Layer - No custom keys */
    [_GAME] = LAYOUT(
        KC_ESC,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_DEL,           KC_MUTE,
        KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC,          TG_GAME,
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC,                   _______,
        KC_CAPS, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, KC_NUHS, KC_ENT,           _______,
        KC_LSFT, KC_NUBS, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,          KC_RSFT, KC_UP,   _______,
        KC_LCTL, KC_LGUI, KC_LALT,                            KC_SPC,                             KC_RALT, KC_RGUI, KC_RCTL, KC_LEFT, KC_DOWN, KC_RGHT
    ),

    /* Numpad Layer */
    [_NUM] = LAYOUT(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          TG_NUM,
        _______, _______, _______, _______, _______, _______, _______, KC_P7,   KC_P8,   KC_P9,   KC_PSLS, _______, _______, _______,          _______,
        _______, _______, _______, _______, _______, _______, _______, KC_P4,   KC_P5,   KC_P6,   KC_PAST, _______, _______,                   _______,
        _______, _______, _______, _______, _______, _______, _______, KC_P1,   KC_P2,   KC_P3,   KC_PMNS, _______, _______, KC_PENT,          _______,
        _______, _______, _______, _______, _______, _______, _______, KC_P0,   KC_P0,   KC_PDOT, KC_PPLS, _______,          _______, _______, _______,
        _______, _______, _______,                            _______,                            _______, _______, _______, _______, _______, _______
    ),

    /* Macro Layer */
    [_MACRO] = LAYOUT(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
        _______, DYN_REC_START1, DYN_REC_START2, DYN_REC_STOP, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,    _______,
        _______, DYN_MACRO_PLAY1, DYN_MACRO_PLAY2, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,             _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, _______, _______,
        _______, _______, _______,                            _______,                            _______, _______, _______, _______, _______, _______
    )
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
        case LAY_AZE:
            if (record->event.pressed) {
                current_layout = LAYOUT_AZERTY;
                user_config.layout = current_layout;
                eeconfig_update_user(user_config.raw);
                #ifdef RGB_MATRIX_ENABLE
                rgb_matrix_sethsv_noeeprom(0, 255, 255);    // Red for AZERTY
                #endif
            }
            return false;

        case LAY_QWE:
            if (record->event.pressed) {
                current_layout = LAYOUT_QWERTY;
                user_config.layout = current_layout;
                eeconfig_update_user(user_config.raw);
                #ifdef RGB_MATRIX_ENABLE
                rgb_matrix_sethsv_noeeprom(120, 255, 255);  // Green for QWERTY
                #endif
            }
            return false;

        case LAY_BPO:
            if (record->event.pressed) {
                current_layout = LAYOUT_BEPO;
                user_config.layout = current_layout;
                eeconfig_update_user(user_config.raw);
                #ifdef RGB_MATRIX_ENABLE
                rgb_matrix_sethsv_noeeprom(240, 255, 255);  // Blue for BÉPO
                #endif
            }
            return false;

        /* French accents - lowercase */
        case FR_E_ACUTE:
            if (record->event.pressed) {
                type_unicode_string("é");
            }
            return false;

        case FR_E_GRAVE:
            if (record->event.pressed) {
                type_unicode_string("è");
            }
            return false;

        case FR_A_GRAVE:
            if (record->event.pressed) {
                type_unicode_string("à");
            }
            return false;

        case FR_U_GRAVE:
            if (record->event.pressed) {
                type_unicode_string("ù");
            }
            return false;

        case FR_C_CEDILLA:
            if (record->event.pressed) {
                type_unicode_string("ç");
            }
            return false;

        /* French accents - uppercase (with shift) */
        case FR_E_ACUTE_MAJ:
            if (record->event.pressed) {
                type_unicode_string("É");
            }
            return false;

        case FR_E_GRAVE_MAJ:
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
                layer_off(_SYM);
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
            case _FN:
                // Media control on function layer
                if (clockwise) {
                    tap_code(KC_MNXT);
                } else {
                    tap_code(KC_MPRV);
                }
                break;
            case _SYS:
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

/* Dynamic key overrides based on layout */
const key_override_t **key_overrides = NULL;

/* Matrix scan for layout-specific key mapping */
void matrix_scan_user(void) {
    // This would be where we'd implement dynamic key remapping
    // based on current_layout if needed
}

/* Layer state handling */
layer_state_t layer_state_set_user(layer_state_t state) {
    // Visual feedback for active layers
    #ifdef RGB_MATRIX_ENABLE
    switch (get_highest_layer(state)) {
        case _FN:
            rgb_matrix_set_color_all(0, 0, 128);  // Blue for function layer
            break;
        case _SYS:
            rgb_matrix_set_color_all(128, 0, 0);  // Red for system layer
            break;
        case _NAV:
            rgb_matrix_set_color_all(0, 128, 0);  // Green for navigation
            break;
        case _SYM:
            rgb_matrix_set_color_all(128, 128, 0); // Yellow for symbols
            break;
        case _GAME:
            rgb_matrix_set_color_all(128, 0, 128); // Purple for gaming
            break;
        default:
            // Return to layout-specific color
            break;
    }
    #endif
    
    return state;
}_, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_SLEP,          _______,
        _______, KC_MPRV, KC_MPLY, KC_MNXT, _______, _______, _______, _______, _______, _______, KC_MUTE, KC_VOLD, KC_VOLU, _______,          KC_CALC,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,                   KC_MAIL,
        KC_CAPS, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          KC_HOME,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, _______, KC_END,
        _______, _______, _______,                            _______,                            _______, MO_SYS,  _______, _______, _______, _______
    ),

    /* System Administration Layer */
    [_SYS] = LAYOUT(
        QK_BOOT, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, EEP_RST,          _______,
        _______, LAY_AZE, LAY_QWE, LAY_BPO, _______, _______, _______, _______, _______, _______, RGB_TOG, RGB_VAD, RGB_VAI, _______,          NK_TOGG,
        _______, _______, _______, _______, _______, _______, _______, _______, RGB_HUI, RGB_SAI, RGB_SPI, RGB_MOD, RGB_RMOD,                  AS_TOGG,
        _______, RGB_REAC_WIDE, RGB_REAC_MWIDE, RGB_SPL, RGB_MULT_SPL, RGB_SOL_SPL, RGB_SOL_MULT_SPL, _______, _______, _______, _______, _______, _______, _______,          TG_GAME,
        _______, _______, ______