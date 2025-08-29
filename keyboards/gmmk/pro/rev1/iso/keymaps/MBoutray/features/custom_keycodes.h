#pragma once

#include "quantum.h"

/* Per-key tapping term */
uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record);

/* Custom Keycodes */
enum custom_keycodes {
    // AZERTY Afnor specific keycodes
    AF_AT = SAFE_RANGE,
    AF_AGRV,
    AF_EACU,
    AF_EGRV,
    AF_ECIR,
    AF_LPRN,
    AF_RPRN,
    AF_LSQU,
    AF_RSQU,
    AF_LDAQ,
    AF_RDAQ,
    AF_QUOT,
    AF_CIRC,
    AF_A,
    AF_Z,
    AF_E,
    AF_R,
    AF_T,
    AF_Y,
    AF_U,
    AF_I,
    AF_O,
    AF_P,
    AF_MINS,
    AF_PLUS,
    AF_Q,
    AF_S,
    AF_D,
    AF_F,
    AF_G,
    AF_H,
    AF_J,
    AF_K,
    AF_L,
    AF_M,
    AF_SLSH,
    AF_ASTR,
    AF_LABK,
    AF_W,
    AF_X,
    AF_C,
    AF_V,
    AF_B,
    AF_N,
    AF_DOT,
    AF_COMM,
    AF_COLN,
    AF_SCLN,

    // RGB Matrix
    RM_NONE,
    RM_ALPHAS_MODS,
    RM_GRAD_UP_DOWN,
    RM_GRAD_LEFT_RIGHT,
    RM_BREATHING,
    RM_BAND_SAT,
    RM_BAND_VAL,
    RM_BAND_PINWHEEL_SAT,
    RM_BAND_PINWHEEL_VAL,
    RM_BAND_SPIRAL_SAT,
    RM_BAND_SPIRAL_VAL,
    RM_CYC_ALL,
    RM_CYC_LEFT_RIGHT,
    RM_CYC_UP_DOWN,
    RM_RAINBOW_MOVING_CHEVRON,
    RM_CYC_OUT_IN,
    RM_CYC_OUT_IN_DUAL,
    RM_CYC_PINWHEEL,
    RM_CYC_SPIRAL,
    RM_DUAL_BEACON,
    RM_RAINBOW_BEACON,
    RM_RAINBOW_PINWHEELS,
    RM_RAINDROPS,
    RM_JELLYBEAN_RAINDROPS,
    RM_HUE_BREATHING,
    RM_HUE_PENDULUM,
    RM_HUE_WAVE,
    RM_PIX_FRACTAL,
    RM_PIX_FLOW,
    RM_PIX_RAIN,
    // Framebuffer defines (additional logic can increase firmware size)
    RM_TYPING_HEATMAP,
    RM_DIGITAL_RAIN,
    // Reactive defines (additional logic can increase firmware size)
    RM_SOLID_REACT_SIMPLE,
    RM_SOLID_REACT,
    RM_SOLID_REACT_WIDE,
    RM_SOLID_REACT_MULTIWIDE,
    RM_SOLID_REACT_CROSS,
    RM_SOLID_REACT_MULTICROSS,
    RM_SOLID_REACT_NEXUS,
    RM_SOLID_REACT_MULTINEXUS,
    RM_SPLASH,
    RM_MULTISPLASH,
    RM_SOLID_SPLASH,
    RM_SOLID_MULTISPLASH,

    // Custom safe range for user
    NEW_SAFE_RANGE
};

/* Layer definitions */
enum layers {
    BASE = 0,           // Base layer
    FUNC,                   // Function layer
    NUMP,                   // Numpad layer
    SYST,                   // System administration layer
    RGB_MAT,                // RGB control layer
};

/* Momentary layer shortcuts */
#define MO_FUNC MO(FUNC)
#define MO_SYST MO(SYST)
#define MO_RGB  MO(RGB_MAT)

/* Layer toggle shortcuts */
#define TG_NUMP TG(NUMP)
#define TG_SYST TG(SYST)
#define TG_RGB  TG(RGB_MAT)

/* Turn on a layer, turn off the rest (except base) */
#define TO_NUMP TO(NUMP)
#define TO_SYST TO(SYST)
