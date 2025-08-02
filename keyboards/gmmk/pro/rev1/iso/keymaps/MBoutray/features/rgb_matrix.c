#include "rgb_matrix.h"

#ifdef RGB_MATRIX_ENABLE
bool rgb_matrix_process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case RM_NONE:
            if (record->event.pressed) {
                rgb_matrix_mode(RGB_MATRIX_NONE);
            }
            return false;
        case RM_ALPHAS_MODS:
            if (record->event.pressed) {
                rgb_matrix_mode(RGB_MATRIX_ALPHAS_MODS);
            }
            return false;
        case RM_GRAD_UP_DOWN:
            if (record->event.pressed) {
                rgb_matrix_mode(RGB_MATRIX_GRADIENT_UP_DOWN);
            }
            return false;
        case RM_GRAD_LEFT_RIGHT:
            if (record->event.pressed) {
                rgb_matrix_mode(RGB_MATRIX_GRADIENT_LEFT_RIGHT);
            }
            return false;
        case RM_BREATHING:
            if (record->event.pressed) {
                rgb_matrix_mode(RGB_MATRIX_BREATHING);
            }
            return false;
        case RM_BAND_SAT:
            if (record->event.pressed) {
                rgb_matrix_mode(RGB_MATRIX_BAND_SAT);
            }
            return false;
        case RM_BAND_VAL:
            if (record->event.pressed) {
                rgb_matrix_mode(RGB_MATRIX_BAND_VAL);
            }
            return false;
        case RM_BAND_PINWHEEL_SAT:
            if (record->event.pressed) {
                rgb_matrix_mode(RGB_MATRIX_BAND_PINWHEEL_SAT);
            }
            return false;
        case RM_BAND_PINWHEEL_VAL:
            if (record->event.pressed) {
                rgb_matrix_mode(RGB_MATRIX_BAND_PINWHEEL_VAL);
            }
            return false;
        case RM_BAND_SPIRAL_SAT:
            if (record->event.pressed) {
                rgb_matrix_mode(RGB_MATRIX_BAND_SPIRAL_SAT);
            }
            return false;
        case RM_BAND_SPIRAL_VAL:
            if (record->event.pressed) {
                rgb_matrix_mode(RGB_MATRIX_BAND_SPIRAL_VAL);
            }
            return false;
        case RM_CYC_ALL:
            if (record->event.pressed) {
                rgb_matrix_mode(RGB_MATRIX_CYCLE_ALL);
            }
            return false;
        case RM_CYC_LEFT_RIGHT:
            if (record->event.pressed) {
                rgb_matrix_mode(RGB_MATRIX_CYCLE_LEFT_RIGHT);
            }
            return false;
        case RM_CYC_UP_DOWN:
            if (record->event.pressed) {
                rgb_matrix_mode(RGB_MATRIX_CYCLE_UP_DOWN);
            }
            return false;
        case RM_RAINBOW_MOVING_CHEVRON:
            if (record->event.pressed) {
                rgb_matrix_mode(RGB_MATRIX_RAINBOW_MOVING_CHEVRON);
            }
            return false;
        case RM_CYC_OUT_IN:
            if (record->event.pressed) {
                rgb_matrix_mode(RGB_MATRIX_CYCLE_OUT_IN);
            }
            return false;
        case RM_CYC_OUT_IN_DUAL:
            if (record->event.pressed) {
                rgb_matrix_mode(RGB_MATRIX_CYCLE_OUT_IN_DUAL);
            }
            return false;
        case RM_CYC_PINWHEEL:
            if (record->event.pressed) {
                rgb_matrix_mode(RGB_MATRIX_CYCLE_PINWHEEL);
            }
            return false;
        case RM_CYC_SPIRAL:
            if (record->event.pressed) {
                rgb_matrix_mode(RGB_MATRIX_CYCLE_SPIRAL);
            }
            return false;
        case RM_DUAL_BEACON:
            if (record->event.pressed) {
                rgb_matrix_mode(RGB_MATRIX_DUAL_BEACON);
            }
            return false;
        case RM_RAINBOW_BEACON:
            if (record->event.pressed) {
                rgb_matrix_mode(RGB_MATRIX_RAINBOW_BEACON);
            }
            return false;
        case RM_RAINBOW_PINWHEELS:
            if (record->event.pressed) {
                rgb_matrix_mode(RGB_MATRIX_RAINBOW_PINWHEELS);
            }
            return false;
        case RM_RAINDROPS:
            if (record->event.pressed) {
                rgb_matrix_mode(RGB_MATRIX_RAINDROPS);
            }
            return false;
        case RM_JELLYBEAN_RAINDROPS:
            if (record->event.pressed) {
                rgb_matrix_mode(RGB_MATRIX_JELLYBEAN_RAINDROPS);
            }
            return false;
        case RM_HUE_BREATHING:
            if (record->event.pressed) {
                rgb_matrix_mode(RGB_MATRIX_HUE_BREATHING);
            }
            return false;
        case RM_HUE_PENDULUM:
            if (record->event.pressed) {
                rgb_matrix_mode(RGB_MATRIX_HUE_PENDULUM);
            }
            return false;
        case RM_HUE_WAVE:
            if (record->event.pressed) {
                rgb_matrix_mode(RGB_MATRIX_HUE_WAVE);
            }
            return false;
        case RM_PIX_FRACTAL:
            if (record->event.pressed) {
                rgb_matrix_mode(RGB_MATRIX_PIXEL_FRACTAL);
            }
            return false;
        case RM_PIX_FLOW:
            if (record->event.pressed) {
                rgb_matrix_mode(RGB_MATRIX_PIXEL_FLOW);
            }
            return false;
        case RM_PIX_RAIN:
            if (record->event.pressed) {
                rgb_matrix_mode(RGB_MATRIX_PIXEL_RAIN);
            }
            return false;
        case RM_TYPING_HEATMAP:
            if (record->event.pressed) {
                rgb_matrix_mode(RGB_MATRIX_TYPING_HEATMAP);
            }
            return false;
        case RM_DIGITAL_RAIN:
            if (record->event.pressed) {
                rgb_matrix_mode(RGB_MATRIX_DIGITAL_RAIN);
            }
            return false;
        case RM_SOLID_REACT_SIMPLE:
            if (record->event.pressed) {
                rgb_matrix_mode(RGB_MATRIX_SOLID_REACTIVE_SIMPLE);
            }
            return false;
        case RM_SOLID_REACT:
            if (record->event.pressed) {
                rgb_matrix_mode(RGB_MATRIX_SOLID_REACTIVE);
            }
            return false;
        case RM_SOLID_REACT_WIDE:
            if (record->event.pressed) {
                rgb_matrix_mode(RGB_MATRIX_SOLID_REACTIVE_WIDE);
            }
            return false;
        case RM_SOLID_REACT_MULTIWIDE:
            if (record->event.pressed) {
                rgb_matrix_mode(RGB_MATRIX_SOLID_REACTIVE_MULTIWIDE);
            }
            return false;
        case RM_SOLID_REACT_CROSS:
            if (record->event.pressed) {
                rgb_matrix_mode(RGB_MATRIX_SOLID_REACTIVE_CROSS);
            }
            return false;
        case RM_SOLID_REACT_MULTICROSS:
            if (record->event.pressed) {
                rgb_matrix_mode(RGB_MATRIX_SOLID_REACTIVE_MULTICROSS);
            }
            return false;
        case RM_SOLID_REACT_NEXUS:
            if (record->event.pressed) {
                rgb_matrix_mode(RGB_MATRIX_SOLID_REACTIVE_NEXUS);
            }
            return false;
        case RM_SOLID_REACT_MULTINEXUS:
            if (record->event.pressed) {
                rgb_matrix_mode(RGB_MATRIX_SOLID_REACTIVE_MULTINEXUS);
            }
            return false;
        case RM_SPLASH:
            if (record->event.pressed) {
                rgb_matrix_mode(RGB_MATRIX_SPLASH);
            }
            return false;
        case RM_MULTISPLASH:
            if (record->event.pressed) {
                rgb_matrix_mode(RGB_MATRIX_MULTISPLASH);
            }
            return false;
        case RM_SOLID_SPLASH:
            if (record->event.pressed) {
                rgb_matrix_mode(RGB_MATRIX_SOLID_SPLASH);
            }
            return false;
        case RM_SOLID_MULTISPLASH:
            if (record->event.pressed) {
                rgb_matrix_mode(RGB_MATRIX_SOLID_MULTISPLASH);
            }
            return false;
    }
    return true;
}

// bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
//     // mettre les mods de la couleur de la layer active
//     // surligner zqsd sur la layer game
//     // surligner les touches de navigation sur la layer nav
//     // surligner les touches de la layer func
//     // surligner les touches de la layer sys
//     // surligner les touches de la layer nump
//     if (host_keyboard_led_state().caps_lock) {
//         for (uint8_t i = led_min; i < led_max; i++) {
//             if (g_led_config.flags[i] & LED_FLAG_KEYLIGHT) {
//                 rgb_matrix_set_color(i, RGB_RED);
//             }
//         }
//     }
//     return false;
// }

// led_config_t g_led_config = { {
//     // Key Matrix to LED Index
//     {1, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, 2},
//     {20, 19, 18, 17, 16, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3},
//     {21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, NO_LED, 36, 37},
//     {52, 51, 50, 49, 48, 47, 46, 45, 44, 43, 41, 40, NO_LED, NO_LED, 39, 38},
//     {53, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED},
//     {NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED},
//     {NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED},
//     {NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED},
//   }, {
//     // LED Index to Physical Position
//     { 188,  16 }, { 187,  48 }, { 149,  64 }, { 112,  64 }, {  37,  48 }, {  38,  16 }
//   }, {
//     // LED Index to Flag
//     1, 4, 4, 4, 4, 1
//   } };
#endif
