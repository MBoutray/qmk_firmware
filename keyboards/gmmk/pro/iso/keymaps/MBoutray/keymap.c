#include QMK_KEYBOARD_H

// layers
#define _BASE 0
#define _FN 1
#define _SYST 2

// custom keycodes
enum custom_keycodes {
    SPEC_I = SAFE_RANGE,
    SPEC_J,
    SPEC_K,
    SPEC_L,
    SPEC_U,
    SPEC_O,
    RGB_REAC_WIDE,
    RGB_REAC_MWIDE,
    RGB_SPL,
    RGB_MULT_SPL,
    RGB_SOL_SPL,
    RGB_SOL_MULT_SPLASH,
};

// custom functions
static bool isNavPressed = false;

void enableAlt(void) {
    register_code(KC_LCTL);
    register_code(KC_LALT);
    unregister_code(KC_LCTL);
}

void disableAlt(void) {
    tap_code(KC_LCTL);
    unregister_code(KC_LALT);
}

void my_nav_keys(uint16_t key_pressed, uint16_t replaced_key, keyrecord_t *record) {
    if(record->event.pressed) {
        if(get_mods() & MOD_BIT(KC_LALT)) { // Vérifier que le Alt de gauche est appuyé
            // disableAlt();
            // register_code(replaced_key);
            // enableAlt();

            del_mods(MOD_BIT(KC_LALT));
            register_code(replaced_key);
            add_mods(MOD_BIT(KC_LALT));
        } else if((get_mods() & (MOD_BIT(KC_LALT) | MOD_BIT(KC_LCTL))) == (MOD_BIT(KC_LALT) | MOD_BIT(KC_LCTL))) {

        } else if((get_mods() & (MOD_BIT(KC_LALT) | MOD_BIT(KC_LCTL) | MOD_BIT(KC_LSFT))) == (MOD_BIT(KC_LALT) | MOD_BIT(KC_LCTL) | MOD_BIT(KC_LSFT))) {

        }  else {
            register_code(key_pressed);
        }
    } else {
        if(get_mods() & MOD_BIT(KC_LALT)) { // Vérifier que le Alt de gauche est appuyé
            unregister_code(replaced_key);
            // unregister_code(key_pressed);
            // enableAlt();
        } else {
            unregister_code(key_pressed);
        }
    }
}

// Macros
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode)
    {
    case KC_LALT:
        if(record->event.pressed) {
            isNavPressed = true;
        } else {
            isNavPressed = false;
        }
        break;
    case SPEC_U:
        my_nav_keys(KC_U, KC_HOME, record);
        break;
    case SPEC_I:
        my_nav_keys(KC_I, KC_UP, record);
        break;
    case SPEC_O:
        my_nav_keys(KC_O, KC_END, record);
        break;
    case SPEC_J:
        my_nav_keys(KC_J, KC_LEFT, record);
        break;
    case SPEC_K:
        my_nav_keys(KC_K, KC_DOWN, record);
        break;
    case SPEC_L:
        my_nav_keys(KC_L, KC_RIGHT, record);
        break;
    case RGB_REAC_WIDE:
        rgb_matrix_mode(RGB_MATRIX_SOLID_REACTIVE_WIDE);
        break;
    case RGB_REAC_MWIDE:
        rgb_matrix_mode(RGB_MATRIX_SOLID_REACTIVE_MULTIWIDE);
        break;
    case RGB_SPL:
        rgb_matrix_mode(RGB_MATRIX_SPLASH);
        break;
    case RGB_MULT_SPL:
        rgb_matrix_mode(RGB_MATRIX_MULTISPLASH);
        break;
    case RGB_SOL_SPL:
        rgb_matrix_mode(RGB_MATRIX_SOLID_SPLASH);
        break;
    case RGB_SOL_MULT_SPLASH:
        rgb_matrix_mode(RGB_MATRIX_SOLID_MULTISPLASH);
        break;
    default:
        return true;
    }
    return true;
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    // To put the keyboard in bootloader mode, use FN+backspace. If you accidentally put it into bootloader, you can just unplug the USB cable and
    // it'll be back to normal when you plug it back in.
    [_BASE] = LAYOUT(
        KC_ESC,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_DEL,           KC_MUTE,
        KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC,          KC_PSCR,
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC,                   KC_INS,
        KC_CAPS, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, KC_NUHS, KC_ENTER,         KC_PGUP,
        KC_LSFT, KC_NUBS, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,          KC_RSFT, KC_UP,   KC_PGDN,
        KC_LCTL, MO(_FN), KC_LALT,                            KC_SPC,                             KC_RALT, KC_RGUI, KC_RCTL, KC_LEFT, KC_DOWN, KC_RGHT
    ),
    // [_BASE] = LAYOUT(
    //     KC_ESC,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_DEL,           KC_MUTE,
    //     KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC,          KC_PSCR,
    //     KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    SPEC_U,  SPEC_I,  SPEC_O,  KC_P,    KC_LBRC, KC_RBRC,                   KC_INS,
    //     KC_CAPS, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    SPEC_J,  SPEC_K,  SPEC_L,  KC_SCLN, KC_QUOT, KC_NUHS, KC_ENTER,         KC_PGUP,
    //     KC_LSFT, KC_NUBS, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,          KC_RSFT, KC_UP,   KC_PGDN,
    //     KC_LCTL, MO(_FN), KC_LALT,                            KC_SPC,                             KC_RALT, KC_RGUI, KC_RCTL, KC_LEFT, KC_DOWN, KC_RGHT
    // ),

    [_FN] = LAYOUT(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_F13,           _______,
        _______, KC_MPRV, KC_MPLY, KC_MNXT, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          KC_F14,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,                   KC_F15,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          KC_F16,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, _______, KC_F17,
       MO(_SYST),_______, _______,                            _______,                            _______, _______, _______, _______, _______, _______
    ),
    [_SYST] = LAYOUT(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_SLEP, KC_PWR,  _______,          _______,
        _______, RGB_M_P, RGB_M_P, RGB_M_R, _______, _______, _______, _______, _______, _______, RGB_TOG, _______, _______, RESET,            _______,
        _______, _______, _______, _______, _______, _______, _______, _______, RGB_HUI, RGB_SAI, RGB_VAI, _______, _______,                   _______,
        _______, RGB_REAC_WIDE, RGB_REAC_MWIDE, RGB_SPL, RGB_MULT_SPL, RGB_SOL_SPL, RGB_SOL_MULT_SPLASH, _______, _______, _______, _______, _______, _______, _______,          _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, _______, _______,
        _______, _______, _______,                            _______,                            _______, _______, _______, _______, _______, _______
    ),
    // [X] = LAYOUT(
    //     _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
    //     _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
    //     _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,                   _______,
    //     _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
    //     _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, _______, _______,
    //     _______, _______, _______,                            _______,                            _______, _______, _______, _______, _______, _______
    // ),
};


bool encoder_update_user(uint8_t index, bool clockwise) {
    if (clockwise) {
      tap_code(KC_VOLU);
    } else {
      tap_code(KC_VOLD);
    }
    return true;
}
