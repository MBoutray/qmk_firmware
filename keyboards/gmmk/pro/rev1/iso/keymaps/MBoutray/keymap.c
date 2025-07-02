/* Copyright 2024 MBoutray
 * Multi-layout keymap for GMMK Pro ISO
 * Supports AZERTY, QWERTY, and BÉPO layouts with advanced features
 */

#include QMK_KEYBOARD_H
#include "eeconfig.h"
#include "leader.h"
#include "features/index.h"
#include "layout/index.h"

/* Current layout tracking */
static uint8_t current_layout = LAYOUT_AZERTY_STANDARD;

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
        KC_LSFT, FR_LABK, FR_W,    FR_X,    FR_C,    FR_V,    FR_B,    FR_N,    FR_COMM, FR_SCLN, FR_COLN, FR_EXLM, KC_RSFT,          KC_UP,   KC_PGDN,
        KC_LCTL, MO_FUNC, KC_LALT,                            KC_SPC,                             KC_RALT, TD_RGUI, KC_RCTL, KC_LEFT, KC_DOWN, KC_RGHT
    ),
    /* AZERTY Afnor base layer*/
    [AZE_AFN_BASE] = LAYOUT(
        /* 1       2        3        4        5        6        7        8        9        10       11       12       13       14       15       16  */
        KC_ESC,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_DEL,           KC_MUTE,
        AF_AT,   AF_AGRV, AF_EACU, AF_EGRV, AF_ECIR, AF_LPRN, AF_RPRN, AF_LSQU, AF_RSQU, AF_LDAQ, AF_RDAQ, AF_QUOT, AF_CIRC, KC_BSPC,          KC_PSCR,
        KC_TAB,  AF_A,    AF_Z,    AF_E,    AF_R,    AF_T,    AF_Y,    AF_U,    AF_I,    AF_O,    AF_P,    AF_MINS, AF_PLUS,                   KC_INS,
        LT_NAVI, AF_Q,    AF_S,    AF_D,    AF_F,    AF_G,    AF_H,    AF_J,    AF_K,    AF_L,    AF_M,    AF_SLSH, AF_ASTR, KC_ENT,           KC_PGUP,
        KC_LSFT, AF_LABK, AF_W,    AF_X,    AF_C,    AF_V,    AF_B,    AF_N,    AF_DOT,  AF_COMM, AF_COLN, AF_SCLN, KC_RSFT,          KC_UP,   KC_PGDN,
        KC_LCTL, MO_FUNC, KC_LALT,                            KC_SPC,                             KC_RALT, TD_RGUI, KC_RCTL, KC_LEFT, KC_DOWN, KC_RGHT
    ),
    /* QWERTY base layer*/
    [QWE_BASE] = LAYOUT(
        /* 1       2        3        4        5        6        7        8        9        10       11       12       13       14       15       16  */
        KC_ESC,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_DEL,           KC_MUTE,
        KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC,          KC_PSCR,
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC,                   KC_INS,
        LT_NAVI, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, KC_NUHS, KC_ENT,           KC_PGUP,
        KC_LSFT, KC_NUBS, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,          KC_UP,   KC_PGDN,
        KC_LCTL, MO_FUNC, KC_LALT,                            KC_SPC,                             KC_RALT, TD_RGUI, KC_RCTL, KC_LEFT, KC_DOWN, KC_RGHT
    ),
    /* BEPO base layer*/
    [BEP_BASE] = LAYOUT(
        /* 1       2        3        4        5        6        7        8        9        10       11       12       13       14       15       16  */
        KC_ESC,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_DEL,           KC_MUTE,
        KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC,          KC_PSCR,
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC,                   KC_INS,
        LT_NAVI, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, KC_NUHS, KC_ENT,           KC_PGUP,
        KC_LSFT, KC_NUBS, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,          KC_UP,   KC_PGDN,
        KC_LCTL, MO_FUNC, KC_LALT,                            KC_SPC,                             KC_RALT, TD_RGUI, KC_RCTL, KC_LEFT, KC_DOWN, KC_RGHT
    ),
    /* Function layer */
    [FUNC] = LAYOUT(
        /* 1        2        3        4        5        6        7        8        9       10       11       12       13       14       15       16  */
        TO_SYST,  _______, _______, KC_F13, KC_F14,  KC_F15,  KC_F16,  KC_F17,  KC_F18,  KC_F19,  KC_F20,  KC_F21,  KC_F22,  _______,          _______,
        _______, KC_MPRV, KC_MPLY, KC_MNXT, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          KC_F23,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,                   KC_F24,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          KC_HOME,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, KC_END,
        _______, _______, _______,                            _______,                            _______, _______, _______, _______, _______, _______
    ),
    /* Navigation layer - VIM-like cursor movement */
    [NAVI] = LAYOUT(
        /* 1        2        3        4        5        6        7        8        9       10       11       12       13       14       15       16  */
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
        _______, _______, VIM_W,   VIM_E,   _______, _______, _______, _______, _______, _______, _______, _______, _______,                   _______,
        _______, _______, _______, _______, _______, VIM_GG,  VIM_H,   VIM_J,   VIM_K,   VIM_L,   VIM_0,   VIM_DLR, _______, _______,          _______,
        _______, _______, _______, _______, _______, _______, VIM_B,   _______, _______, _______, _______, _______, _______,          _______, _______,
        _______, _______, _______,                            _______,                            _______, _______, _______, _______, _______, _______
    ),
    /* Symbols Layer - Programming & French Accents */
    [SYMB] = LAYOUT(
        /* 1        2           3        4        5        6        7        8        9       10           11       12             13           14       15       16  */
        _______, _______,    _______, _______, _______, _______, _______, _______, _______, _______,     _______, _______,       _______,     _______,          _______,
        _______, _______,    _______, _______, _______, _______, _______, _______, _______, _______,     _______, _______,       _______,     _______,          _______,
        _______, _______,    _______, _______, FR_EACU, _______, _______, _______, _______, _______,     _______, SMART_BRACKET, SMART_BRACE,                   _______,
        _______, _______,    _______, FR_EGRV, _______, _______, _______, _______, _______, _______,     _______, SMART_QUOTE,   _______,     _______,          _______,
        _______, _______,    _______, _______, _______, _______, _______, _______, _______, SMART_ANGLE, _______, _______,       _______,              _______, _______,
        _______, _______,    _______,                            _______,                                _______, _______,       _______,     _______, _______, _______
    ),
    /* Numpad Layer */
    [NUMP] = LAYOUT(
        /* 1        2        3        4        5        6        7        8        9       10       11       12       13       14       15       16  */
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
        _______, _______, _______, _______, _______, _______, _______, KC_P7,   KC_P8,   KC_P9,   KC_PSLS, _______, _______, _______,          _______,
        _______, _______, _______, _______, _______, _______, _______, KC_P4,   KC_P5,   KC_P6,   KC_PAST, _______, _______,                   TG_NUMP,
        _______, _______, _______, _______, _______, _______, _______, KC_P1,   KC_P2,   KC_P3,   KC_PMNS, _______, _______, KC_PENT,          _______,
        _______, _______, _______, _______, _______, _______, _______, KC_P0,   KC_P0,   KC_PDOT, KC_PPLS, _______, _______,          _______, _______,
        _______, _______, _______,                            _______,                            _______, _______, _______, _______, _______, _______
    ),
    /* Gaming Layer - No custom keys */
    [GAME] = LAYOUT(
        /* 1        2        3        4        5        6        7        8        9       10       11       12       13       14       15       16  */
        KC_ESC,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_DEL,           KC_MUTE,
        KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC,          KC_INS,
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC,                   TG_GAME,
        KC_CAPS, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, KC_NUHS, KC_ENT,           KC_PGUP,
        KC_LSFT, KC_NUBS, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,          KC_UP,   KC_PGDN,
        KC_LCTL, KC_LGUI, KC_LALT,                            KC_SPC,                             KC_RALT, KC_RGUI, KC_RCTL, KC_LEFT, KC_DOWN, KC_RGHT
    ),
    /* System Layer - System controls and utilities */
    [SYST] = LAYOUT(
        /* 1        2            3            4        5        6        7        8        9       10       11       12       13       14       15       16  */
        TG_SYST, QK_BOOT,     QK_MAKE,     DB_TOGG, QK_RBT,  EE_CLR,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,          XXXXXXX,
        XXXXXXX, LAY_AZE_STD, LAY_AZE_AFN, LAY_QWE, LAY_BPO, TO_GAME, TO_NUMP, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, QK_BOOT,          XXXXXXX,
        XXXXXXX, XXXXXXX,     XXXXXXX,     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   TG_SYST,
        XXXXXXX, XXXXXXX,     XXXXXXX,     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,          XXXXXXX,
        XXXXXXX, XXXXXXX,     XXXXXXX,     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,          XXXXXXX, XXXXXXX,
        XXXXXXX, MO_RGB,     XXXXXXX,                                XXXXXXX,                            XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
    ),
    /* RGB Layer */
    [RGB_MAT] = LAYOUT(
        /* 1        2                          3                          4                          5                   6                7                  8                     9                     10                    11                   12                        13                    14       15       16  */
        RM_NONE, _______,                   _______,                   _______,                   _______,            _______,         _______,           _______,              _______,               _______,              _______,             _______,                  _______,              _______,          _______,
        _______, RM_ALPHAS_MODS,            RM_GRAD_UP_DOWN,           RM_GRAD_LEFT_RIGHT,        RM_BREATHING,       RM_BAND_SAT,     RM_BAND_VAL,       RM_BAND_PINWHEEL_SAT, RM_BAND_PINWHEEL_VAL,  RM_BAND_SPIRAL_SAT,   RM_BAND_SPIRAL_VAL,  RM_CYC_ALL,               RM_CYC_LEFT_RIGHT,    _______,          _______,
        _______, RM_CYC_UP_DOWN,            RM_RAINBOW_MOVING_CHEVRON, RM_CYC_OUT_IN,             RM_CYC_OUT_IN_DUAL, RM_CYC_PINWHEEL, RM_CYC_SPIRAL,     RM_DUAL_BEACON,       RM_RAINBOW_BEACON,     RM_RAINBOW_PINWHEELS, RM_RAINDROPS,        RM_JELLYBEAN_RAINDROPS,   RM_HUE_BREATHING,                       _______,
        _______, RM_HUE_PENDULUM,           RM_HUE_WAVE,               RM_PIX_FRACTAL,            RM_PIX_FLOW,        RM_PIX_RAIN,     RM_TYPING_HEATMAP, RM_DIGITAL_RAIN,      RM_SOLID_REACT_SIMPLE, RM_SOLID_REACT,       RM_SOLID_REACT_WIDE, RM_SOLID_REACT_MULTIWIDE, RM_SOLID_REACT_CROSS, _______,          _______,
        _______, RM_SOLID_REACT_MULTICROSS, RM_SOLID_REACT_NEXUS,      RM_SOLID_REACT_MULTINEXUS, RM_SPLASH,          RM_MULTISPLASH,  RM_SOLID_SPLASH,   RM_SOLID_MULTISPLASH, _______,               _______,              _______,             _______,                  _______,                       _______, _______,
        _______, _______,                   _______,                                                                                   _______,                                                                              _______,             _______,                  _______,              _______, _______, _______
    )
};

/* Process custom keycodes */
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    // Process vim navigation first
    if (!process_vim_navigation(keycode, record)) {
        return false;
    }

    switch (keycode) {
        /* Layout switching */
        case LAY_AZE_STD:
            if (record->event.pressed) {
                current_layout = LAYOUT_AZERTY_STANDARD;
                user_config.layout = current_layout;
                eeconfig_update_kb(user_config.raw);
                set_single_persistent_default_layer(AZE_STD_BASE);
                #ifdef RGB_MATRIX_ENABLE
                rgb_matrix_sethsv_noeeprom(0, 255, 255);    // Red for AZERTY standard
                #endif
                layer_move(AZE_STD_BASE);
            }
            return false;

            case LAY_AZE_AFN:
            if (record->event.pressed) {
                current_layout = LAYOUT_AZERTY_AFNOR;
                user_config.layout = current_layout;
                eeconfig_update_kb(user_config.raw);
                set_single_persistent_default_layer(AZE_AFN_BASE);
                #ifdef RGB_MATRIX_ENABLE
                rgb_matrix_sethsv_noeeprom(21, 255, 192);    // Orange for AZERTY Afnor
                #endif
                layer_move(AZE_AFN_BASE);
            }
            return false;

            case LAY_QWE:
            if (record->event.pressed) {
                current_layout = LAYOUT_QWERTY;
                user_config.layout = current_layout;
                eeconfig_update_kb(user_config.raw);
                set_single_persistent_default_layer(QWE_BASE);
                #ifdef RGB_MATRIX_ENABLE
                rgb_matrix_sethsv_noeeprom(120, 255, 255);  // Green for QWERTY
                #endif
                layer_move(QWE_BASE);
            }
            return false;

            case LAY_BPO:
            if (record->event.pressed) {
                current_layout = LAYOUT_BEPO;
                user_config.layout = current_layout;
                eeconfig_update_kb(user_config.raw);
                set_single_persistent_default_layer(BEP_BASE);
                #ifdef RGB_MATRIX_ENABLE
                rgb_matrix_sethsv_noeeprom(240, 255, 255);  // Blue for BÉPO
                #endif
                layer_move(BEP_BASE);
            }
            return false;

        /* Custom keycodes for Afnor specific characters */
        case AF_AT:   case AF_AGRV: case AF_EACU: case AF_EGRV: case AF_ECIR:
        case AF_LPRN: case AF_RPRN: case AF_LSQU: case AF_RSQU: case AF_LDAQ:
        case AF_RDAQ: case AF_QUOT: case AF_CIRC: case AF_A:    case AF_Z:
        case AF_E:    case AF_R:    case AF_T:    case AF_Y:    case AF_U:
        case AF_I:    case AF_O:    case AF_P:    case AF_MINS: case AF_PLUS:
        case AF_Q:    case AF_S:    case AF_D:    case AF_F:    case AF_G:
        case AF_H:    case AF_J:    case AF_K:    case AF_L:    case AF_M:
        case AF_SLSH: case AF_ASTR: case AF_LABK: case AF_W:    case AF_X:
        case AF_C:    case AF_V:    case AF_B:    case AF_N:    case AF_DOT:
        case AF_COMM: case AF_COLN: case AF_SCLN:
            return process_afnor_keycodes(keycode, record);

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

        // /* RGB custom modes */
        case RM_NONE:                  case RM_ALPHAS_MODS:       case RM_GRAD_UP_DOWN:           case RM_GRAD_LEFT_RIGHT:     case RM_BREATHING:
        case RM_BAND_SAT:              case RM_BAND_VAL:          case RM_BAND_PINWHEEL_SAT:      case RM_BAND_PINWHEEL_VAL:   case RM_BAND_SPIRAL_SAT:
        case RM_BAND_SPIRAL_VAL:       case RM_CYC_ALL:           case RM_CYC_LEFT_RIGHT:         case RM_CYC_UP_DOWN:         case RM_RAINBOW_MOVING_CHEVRON:
        case RM_CYC_OUT_IN:            case RM_CYC_OUT_IN_DUAL:   case RM_CYC_PINWHEEL:           case RM_CYC_SPIRAL:          case RM_DUAL_BEACON:
        case RM_RAINBOW_BEACON:        case RM_RAINBOW_PINWHEELS: case RM_RAINDROPS:              case RM_JELLYBEAN_RAINDROPS: case RM_HUE_BREATHING:
        case RM_HUE_PENDULUM:          case RM_HUE_WAVE:          case RM_PIX_FRACTAL:            case RM_PIX_FLOW:            case RM_PIX_RAIN:
        case RM_TYPING_HEATMAP:        case RM_DIGITAL_RAIN:      case RM_SOLID_REACT_SIMPLE:     case RM_SOLID_REACT:         case RM_SOLID_REACT_WIDE:
        case RM_SOLID_REACT_MULTIWIDE: case RM_SOLID_REACT_CROSS: case RM_SOLID_REACT_MULTICROSS: case RM_SOLID_REACT_NEXUS:   case RM_SOLID_REACT_MULTINEXUS:
        case RM_SPLASH:                case RM_MULTISPLASH:       case RM_SOLID_SPLASH:           case RM_SOLID_MULTISPLASH:
            if (record->event.pressed) {
                rgb_matrix_process_record_user(keycode, record);
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
