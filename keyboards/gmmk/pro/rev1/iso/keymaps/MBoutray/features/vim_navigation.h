/* Copyright 2024 MBoutray
 * Vim-style navigation header file
 */

#pragma once

#include "quantum.h"
#include <stdbool.h>
#include "custom_keycodes.h"

/* Function declarations */
bool process_vim_navigation(uint16_t keycode, keyrecord_t *record);
bool is_vim_nav_active(void);
void toggle_vim_nav(void);
void reset_vim_nav(void);
