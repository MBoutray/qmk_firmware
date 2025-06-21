/* Copyright 2024 MBoutray
 * Vim-style navigation implementation with modifier support
 */

#include "vim_navigation.h"

/* Navigation state tracking */
static bool vim_nav_active = false;
static uint16_t vim_g_timer = 0;
static bool vim_g_pressed = false;

/* Process vim navigation keys with modifier support */
bool process_vim_navigation(uint16_t keycode, keyrecord_t *record) {
    // Get current modifiers
    uint8_t mods = get_mods();
    bool shift_held = mods & MOD_MASK_SHIFT;
    bool ctrl_held = mods & MOD_MASK_CTRL;
    bool alt_held = mods & MOD_MASK_ALT;
    // bool gui_held = mods & MOD_MASK_GUI;

    switch (keycode) {
        /* Basic movement */
        case VIM_H:
            if (record->event.pressed) {
                if (ctrl_held && shift_held) {
                    // Ctrl+Shift+H: Select to beginning of line
                    tap_code16(S(KC_HOME));
                } else if (ctrl_held) {
                    // Ctrl+H: Beginning of line
                    tap_code(KC_HOME);
                } else if (shift_held) {
                    // Shift+H: Select left
                    tap_code16(S(KC_LEFT));
                } else if (alt_held) {
                    // Alt+H: Word left
                    tap_code16(A(KC_LEFT));
                } else {
                    // H: Left
                    tap_code(KC_LEFT);
                }
            }
            return false;

        case VIM_J:
            if (record->event.pressed) {
                if (ctrl_held && shift_held) {
                    // Ctrl+Shift+J: Select page down
                    tap_code16(S(KC_PGDN));
                } else if (ctrl_held) {
                    // Ctrl+J: Page down
                    tap_code(KC_PGDN);
                } else if (shift_held) {
                    // Shift+J: Select down
                    tap_code16(S(KC_DOWN));
                } else if (alt_held) {
                    // Alt+J: Move line down (VS Code style)
                    tap_code16(A(KC_DOWN));
                } else {
                    // J: Down
                    tap_code(KC_DOWN);
                }
            }
            return false;

        case VIM_K:
            if (record->event.pressed) {
                if (ctrl_held && shift_held) {
                    // Ctrl+Shift+K: Select page up
                    tap_code16(S(KC_PGUP));
                } else if (ctrl_held) {
                    // Ctrl+K: Page up
                    tap_code(KC_PGUP);
                } else if (shift_held) {
                    // Shift+K: Select up
                    tap_code16(S(KC_UP));
                } else if (alt_held) {
                    // Alt+K: Move line up (VS Code style)
                    tap_code16(A(KC_UP));
                } else {
                    // K: Up
                    tap_code(KC_UP);
                }
            }
            return false;

        case VIM_L:
            if (record->event.pressed) {
                if (ctrl_held && shift_held) {
                    // Ctrl+Shift+L: Select to end of line
                    tap_code16(S(KC_END));
                } else if (ctrl_held) {
                    // Ctrl+L: End of line
                    tap_code(KC_END);
                } else if (shift_held) {
                    // Shift+L: Select right
                    tap_code16(S(KC_RIGHT));
                } else if (alt_held) {
                    // Alt+L: Word right
                    tap_code16(A(KC_RIGHT));
                } else {
                    // L: Right
                    tap_code(KC_RIGHT);
                }
            }
            return false;

        /* Word movement */
        case VIM_W:
            if (record->event.pressed) {
                if (shift_held) {
                    // Shift+W: Select word forward
                    tap_code16(S(C(KC_RIGHT)));
                } else {
                    // W: Word forward
                    tap_code16(C(KC_RIGHT));
                }
            }
            return false;

        case VIM_B:
            if (record->event.pressed) {
                if (shift_held) {
                    // Shift+B: Select word backward
                    tap_code16(S(C(KC_LEFT)));
                } else {
                    // B: Word backward
                    tap_code16(C(KC_LEFT));
                }
            }
            return false;

        case VIM_E:
            if (record->event.pressed) {
                if (shift_held) {
                    // Shift+E: Select to end of word
                    tap_code16(S(C(KC_RIGHT)));
                    tap_code16(S(KC_LEFT));
                } else {
                    // E: End of word
                    tap_code16(C(KC_RIGHT));
                    tap_code(KC_LEFT);
                }
            }
            return false;

        /* Line movement */
        case VIM_0:
            if (record->event.pressed) {
                if (shift_held) {
                    // Shift+0: Select to beginning of line
                    tap_code16(S(KC_HOME));
                } else {
                    // 0: Beginning of line
                    tap_code(KC_HOME);
                }
            }
            return false;

        case VIM_DLR:
            if (record->event.pressed) {
                if (shift_held) {
                    // Shift+$: Select to end of line
                    tap_code16(S(KC_END));
                } else {
                    // $: End of line
                    tap_code(KC_END);
                }
            }
            return false;

        /* Document movement */
        case VIM_GG:
            if (record->event.pressed) {
                if (shift_held) {
                    // Shift+gg: Select to beginning of document
                    tap_code16(S(C(KC_HOME)));
                } else {
                    // gg: Beginning of document
                    tap_code16(C(KC_HOME));
                }
            }
            return false;

        case VIM_G:
            if (record->event.pressed) {
                if (vim_g_pressed && timer_elapsed(vim_g_timer) < TAPPING_TERM) {
                    // Double G: Go to beginning (gg)
                    if (shift_held) {
                        tap_code16(S(C(KC_HOME)));
                    } else {
                        tap_code16(C(KC_HOME));
                    }
                    vim_g_pressed = false;
                } else {
                    // Single G: Go to end
                    if (shift_held) {
                        tap_code16(S(C(KC_END)));
                    } else {
                        tap_code16(C(KC_END));
                    }
                    vim_g_pressed = true;
                    vim_g_timer = timer_read();
                }
            }
            return false;
    }

    return true;
}

/* Helper function to check if we're in vim navigation mode */
bool is_vim_nav_active(void) {
    return vim_nav_active;
}

/* Toggle vim navigation mode */
void toggle_vim_nav(void) {
    vim_nav_active = !vim_nav_active;

    // Visual feedback via RGB
    #ifdef RGB_MATRIX_ENABLE
    if (vim_nav_active) {
        rgb_matrix_sethsv_noeeprom(85, 255, 255);  // Green for vim mode
    } else {
        rgb_matrix_sethsv_noeeprom(0, 0, 255);     // White for normal mode
    }
    #endif
}

/* Reset vim navigation state */
void reset_vim_nav(void) {
    vim_nav_active = false;
    vim_g_pressed = false;
    vim_g_timer = 0;
}
