#pragma once

#undef MANUFACTURER
#undef PRODUCT

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
#define TAPPING_FORCE_HOLD

/* Unicode input configuration */
#define UNICODE_KEY_WINC KC_RIGHT_ALT

/* Dynamic Macro Configuration */
#define DYNAMIC_MACRO_SIZE 128

/* EEPROM Configuration for Layout Persistence */
#define EECONFIG_USER_DATA_SIZE 4

/* Layer Configuration */
#define LAYER_STATE_16BIT  // Support up to 16 layers

/* Encoder Configuration */
#define ENCODER_RESOLUTION 4

/* Power Saving */
#define USB_SUSPEND_WAKEUP_DELAY 1000

/* Memory Optimization */
#define NO_ACTION_MACRO
#define NO_ACTION_FUNCTION
#define DISABLE_LEADER  // Enable only if using leader key feature

/* Custom Feature Flags */
#define VIM_NAVIGATION_ENABLE
#define AZERTY_AFNOR_ENABLE
#define QWERTY_ENABLE
#define BEPO_ENABLE
#define SMART_BRACKETS_ENABLE

/* RGB Matrix Configuration */
#ifdef RGB_MATRIX_ENABLE
    #define RGB_MATRIX_KEYPRESSES
    // #define RGB_MATRIX_KEYRELEASES                                       // reactive effects respond to keyreleases (instead of keypresses)
    #define RGB_MATRIX_TIMEOUT 1200000 // 20 minutes                     // number of milliseconds to wait until rgb automatically turns off
    #define RGB_MATRIX_SLEEP                                             // turn off effects when suspended
    #define RGB_MATRIX_LED_PROCESS_LIMIT (RGB_MATRIX_LED_COUNT + 4) / 5  // limits the number of LEDs to process in an animation per task run (increases keyboard responsiveness)
    #define RGB_MATRIX_LED_FLUSH_LIMIT 16                                // limits in milliseconds how frequently an animation will update the LEDs. 16 (16ms) is equivalent to limiting to 60fps (increases keyboard responsiveness)
    #define RGB_MATRIX_MAXIMUM_BRIGHTNESS 150                            // limits maximum brightness of LEDs to 200 out of 255. If not defined maximum brightness is set to 255
    #define RGB_MATRIX_DEFAULT_ON true                                   // Sets the default enabled state, if none has been set
    #define RGB_MATRIX_DEFAULT_MODE RGB_MATRIX_CYCLE_LEFT_RIGHT          // Sets the default mode, if none has been set
    #define RGB_MATRIX_DEFAULT_HUE 0                                     // Sets the default hue value, if none has been set
    #define RGB_MATRIX_DEFAULT_SAT 255                                   // Sets the default saturation value, if none has been set
    #define RGB_MATRIX_DEFAULT_VAL RGB_MATRIX_MAXIMUM_BRIGHTNESS         // Sets the default brightness value, if none has been set
    #define RGB_MATRIX_DEFAULT_SPD 127                                   // Sets the default animation speed, if none has been set
    #define RGB_MATRIX_HUE_STEP 8                                        // The value by which to increment the hue per adjustment action
    #define RGB_MATRIX_SAT_STEP 16                                       // The value by which to increment the saturation per adjustment action
    #define RGB_MATRIX_VAL_STEP 16                                       // The value by which to increment the brightness per adjustment action
    #define RGB_MATRIX_SPD_STEP 16                                       // The value by which to increment the animation speed per adjustment action
    #define RGB_MATRIX_DEFAULT_FLAGS LED_FLAG_ALL                        // Sets the default LED flags, if none has been set
    #define RGB_TRIGGER_ON_KEYDOWN                                       // Triggers RGB keypress events on key down. This makes RGB control feel more responsive. This may cause RGB to not function properly on some boards

    /* Enable/Disable specific RGB effects */
    #define ENABLE_RGB_MATRIX_ALPHAS_MODS
    #define ENABLE_RGB_MATRIX_GRADIENT_UP_DOWN
    #define ENABLE_RGB_MATRIX_GRADIENT_LEFT_RIGHT
    #define ENABLE_RGB_MATRIX_BREATHING
    #define ENABLE_RGB_MATRIX_BAND_SAT
    #define ENABLE_RGB_MATRIX_BAND_VAL
    #define ENABLE_RGB_MATRIX_BAND_PINWHEEL_SAT
    #define ENABLE_RGB_MATRIX_BAND_PINWHEEL_VAL
    #define ENABLE_RGB_MATRIX_BAND_SPIRAL_SAT
    #define ENABLE_RGB_MATRIX_BAND_SPIRAL_VAL
    #define ENABLE_RGB_MATRIX_CYCLE_ALL
    #define ENABLE_RGB_MATRIX_CYCLE_LEFT_RIGHT
    #define ENABLE_RGB_MATRIX_CYCLE_UP_DOWN
    #define ENABLE_RGB_MATRIX_RAINBOW_MOVING_CHEVRON
    #define ENABLE_RGB_MATRIX_CYCLE_OUT_IN
    #define ENABLE_RGB_MATRIX_CYCLE_OUT_IN_DUAL
    #define ENABLE_RGB_MATRIX_CYCLE_PINWHEEL
    #define ENABLE_RGB_MATRIX_CYCLE_SPIRAL
    #define ENABLE_RGB_MATRIX_DUAL_BEACON
    #define ENABLE_RGB_MATRIX_RAINBOW_BEACON
    #define ENABLE_RGB_MATRIX_RAINBOW_PINWHEELS
    #define ENABLE_RGB_MATRIX_RAINDROPS
    #define ENABLE_RGB_MATRIX_JELLYBEAN_RAINDROPS
    #define ENABLE_RGB_MATRIX_HUE_BREATHING
    #define ENABLE_RGB_MATRIX_HUE_PENDULUM
    #define ENABLE_RGB_MATRIX_HUE_WAVE
    #define ENABLE_RGB_MATRIX_PIXEL_FRACTAL
    #define ENABLE_RGB_MATRIX_PIXEL_FLOW
    #define ENABLE_RGB_MATRIX_PIXEL_RAIN
    // Framebuffer defines (additional logic can increase firmware size)
    #define ENABLE_RGB_MATRIX_TYPING_HEATMAP
    #define ENABLE_RGB_MATRIX_DIGITAL_RAIN
    // Reactive defines (additional logic can increase firmware size)
    #define ENABLE_RGB_MATRIX_SOLID_REACTIVE_SIMPLE
    #define ENABLE_RGB_MATRIX_SOLID_REACTIVE
    #define ENABLE_RGB_MATRIX_SOLID_REACTIVE_WIDE
    #define ENABLE_RGB_MATRIX_SOLID_REACTIVE_MULTIWIDE
    #define ENABLE_RGB_MATRIX_SOLID_REACTIVE_CROSS
    #define ENABLE_RGB_MATRIX_SOLID_REACTIVE_MULTICROSS
    #define ENABLE_RGB_MATRIX_SOLID_REACTIVE_NEXUS
    #define ENABLE_RGB_MATRIX_SOLID_REACTIVE_MULTINEXUS
    #define ENABLE_RGB_MATRIX_SPLASH
    #define ENABLE_RGB_MATRIX_MULTISPLASH
    #define ENABLE_RGB_MATRIX_SOLID_SPLASH
    #define ENABLE_RGB_MATRIX_SOLID_MULTISPLASH
#endif
