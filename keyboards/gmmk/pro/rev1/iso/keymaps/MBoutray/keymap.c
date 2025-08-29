/* Copyright 2024 MBoutray
 * Multi-layout keymap for GMMK Pro ISO
 * Supports AZERTY, QWERTY, and BÉPO layouts with advanced features
 */

#include QMK_KEYBOARD_H
#include "eeconfig.h"
#include "leader.h"
#include "features/index.h"
#include "layout/index.h"

static uint8_t current_layout = BASE;

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
        case BASE:
            rgb_matrix_sethsv_noeeprom(120, 255, 255);  // Green for QWERTY
            break;
    }
    #endif
}

/* Main keymap */
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [BASE] = LAYOUT(
        /* 1       2        3        4        5        6        7        8        9        10       11       12       13       14       15       16  */
        KC_ESC,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_DEL,           KC_MUTE,
        KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC,          KC_PSCR,
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC,                   KC_INS,
        KC_CAPS, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, KC_NUHS, KC_ENT,           KC_PGUP,
        KC_LSFT, KC_NUBS, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,          KC_UP,   KC_PGDN,
        KC_LCTL, MO_FUNC, KC_LALT,                            KC_SPC,                             KC_RALT, KC_RGUI, KC_RCTL, KC_LEFT, KC_DOWN, KC_RGHT
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
    /* System Layer - System controls and utilities */
    [SYST] = LAYOUT(
        /* 1        2        3        4        5        6        7        8        9       10       11       12       13       14       15       16  */
        TG_SYST, QK_BOOT, QK_MAKE, DB_TOGG, QK_RBT,  EE_CLR,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,          XXXXXXX,
        XXXXXXX, TO_NUMP, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, QK_BOOT,          XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   TG_SYST,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,          XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,          XXXXXXX, XXXXXXX,
        XXXXXXX, MO_RGB,  XXXXXXX,                            XXXXXXX,                            XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
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
    switch (keycode) {
        /* Layout switching */
        case BASE:
            if (record->event.pressed) {
                current_layout = BASE;
                user_config.layout = current_layout;
                eeconfig_update_kb(user_config.raw);
                #ifdef RGB_MATRIX_ENABLE
                rgb_matrix_sethsv_noeeprom(0, 255, 255);    // Red for AZERTY standard
                #endif
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

        default:
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
        default:
            // Return to layout-specific color
            break;
    }
    #endif

    return state;
}
