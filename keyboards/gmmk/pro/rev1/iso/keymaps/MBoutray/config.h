/* Copyright 2024 MBoutray
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 */

#pragma once

/* USB Device Configuration */
#define VENDOR_ID       0x320F
#define PRODUCT_ID      0x5044
#define DEVICE_VER      0x0001
#define MANUFACTURER    "Glorious"
#define PRODUCT         "GMMK Pro ISO Multi-Layout"

/* Key Matrix Configuration */
#define MATRIX_ROWS 11
#define MATRIX_COLS 8
#define DIODE_DIRECTION COL2ROW

/* Debounce Configuration */
#define DEBOUNCE 5

/* Feature Toggles */
#define TAPPING_TERM 200
#define TAPPING_TERM_PER_KEY
#define PERMISSIVE_HOLD
#define IGNORE_MOD_TAP_INTERRUPT
#define TAPPING_FORCE_HOLD

/* Auto Shift Configuration */
#define AUTO_SHIFT_TIMEOUT 175
#define NO_AUTO_SHIFT_NUMERIC
#define NO_AUTO_SHIFT_SPECIAL

/* RGB Matrix Configuration */
#ifdef RGB_MATRIX_ENABLE
    #define RGB_MATRIX_KEYPRESSES
    #define RGB_MATRIX_FRAMEBUFFER_EFFECTS
    #define RGB_DISABLE_TIMEOUT 1200000              // 20 minutes
    #define RGB_DISABLE_WHEN_USB_SUSPENDED
    #define RGB_MATRIX_LED_FLUSH_LIMIT 16
    #define RGB_MATRIX_MAXIMUM_BRIGHTNESS 150        // Limit brightness to reduce power consumption
    #define RGB_MATRIX_HUE_STEP 8
    #define RGB_MATRIX_SAT_STEP 8
    #define RGB_MATRIX_VAL_STEP 8
    #define RGB_MATRIX_SPD_STEP 10
    
    /* Enable specific RGB effects */
    #define ENABLE_RGB_MATRIX_BREATHING
    #define ENABLE_RGB_MATRIX_CYCLE_ALL
    #define ENABLE_RGB_MATRIX_SOLID_REACTIVE_WIDE
    #define ENABLE_RGB_MATRIX_SOLID_REACTIVE_MULTIWIDE
    #define ENABLE_RGB_MATRIX_SPLASH
    #define ENABLE_RGB_MATRIX_MULTISPLASH
    #define ENABLE_RGB_MATRIX_SOLID_SPLASH
    #define ENABLE_RGB_MATRIX_SOLID_MULTISPLASH
    
    /* Disable unused RGB effects to save space */
    #define DISABLE_RGB_MATRIX_ALPHAS_MODS
    #define DISABLE_RGB_MATRIX_GRADIENT_UP_DOWN
    #define DISABLE_RGB_MATRIX_GRADIENT_LEFT_RIGHT
    #define DISABLE_RGB_MATRIX_BAND_SAT
    #define DISABLE_RGB_MATRIX_BAND_VAL
    #define DISABLE_RGB_MATRIX_BAND_PINWHEEL_SAT
    #define DISABLE_RGB_MATRIX_BAND_PINWHEEL_VAL
    #define DISABLE_RGB_MATRIX_BAND_SPIRAL_SAT
    #define DISABLE_RGB_MATRIX_BAND_SPIRAL_VAL
    #define DISABLE_RGB_MATRIX_CYCLE_LEFT_RIGHT
    #define DISABLE_RGB_MATRIX_CYCLE_UP_DOWN
    #define DISABLE_RGB_MATRIX_RAINBOW_MOVING_CHEVRON
    #define DISABLE_RGB_MATRIX_CYCLE_OUT_IN
    #define DISABLE_RGB_MATRIX_CYCLE_OUT_IN_DUAL
    #define DISABLE_RGB_MATRIX_CYCLE_PINWHEEL
    #define DISABLE_RGB_MATRIX_CYCLE_SPIRAL
    #define DISABLE_RGB_MATRIX_DUAL_BEACON
    #define DISABLE_RGB_MATRIX_RAINBOW_BEACON
    #define DISABLE_RGB_MATRIX_RAINBOW_PINWHEELS
    #define DISABLE_RGB_MATRIX_RAINDROPS
    #define DISABLE_RGB_MATRIX_JELLYBEAN_RAINDROPS
    #define DISABLE_RGB_MATRIX_HUE_BREATHING
    #define DISABLE_RGB_MATRIX_HUE_PENDULUM
    #define DISABLE_RGB_MATRIX_HUE_WAVE
    #define DISABLE_RGB_MATRIX_TYPING_HEATMAP
    #define DISABLE_RGB_MATRIX_DIGITAL_RAIN
    #define DISABLE_RGB_MATRIX_SOLID_REACTIVE_SIMPLE
    #define DISABLE_RGB_MATRIX_SOLID_REACTIVE
    #define DISABLE_RGB_MATRIX_SOLID_REACTIVE_CROSS
    #define DISABLE_RGB_MATRIX_SOLID_REACTIVE_MULTICROSS
    #define DISABLE_RGB_MATRIX_SOLID_REACTIVE_NEXUS
    #define DISABLE_RGB_MATRIX_SOLID_REACTIVE_MULTINEXUS
#endif

/* Tap Dance Configuration */
#define TAPPING_TERM 200

/* Leader Key Configuration */
#define LEADER_TIMEOUT 300
#define LEADER_PER_KEY_TIMING

/* Dynamic Macro Configuration */
#define DYNAMIC_MACRO_SIZE 128

/* EEPROM Configuration for Layout Persistence */
#define EECONFIG_USER_DATA_SIZE 4

/* Layer Configuration */
#define LAYER_STATE_8BIT  // Support up to 8 layers

/* Encoder Configuration */
#define ENCODER_RESOLUTION 4
#define ENCODER_DIRECTION_FLIP

/* Power Saving */
#define USB_SUSPEND_WAKEUP_DELAY 1000

/* Memory Optimization */
#define NO_ACTION_MACRO
#define NO_ACTION_FUNCTION
#define DISABLE_LEADER  // Enable only if using leader key feature

/* Custom Feature Flags */
#define VIM_NAVIGATION_ENABLE
#define FRENCH_ACCENTS_ENABLE
#define LAYOUT_SWITCHER_ENABLE
#define SMART_BRACKETS_ENABLE