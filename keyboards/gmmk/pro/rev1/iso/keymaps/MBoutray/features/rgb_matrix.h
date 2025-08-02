#pragma once

#include "quantum.h"
#include "rgb_matrix.h"
#include "custom_keycodes.h"

#ifdef RGB_MATRIX_ENABLE
bool rgb_matrix_process_record_user(uint16_t keycode, keyrecord_t *record);
// bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max);
#endif
