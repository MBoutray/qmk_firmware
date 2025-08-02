# MCU name
MCU = STM32F303

# Bootloader selection
BOOTLOADER = stm32-dfu

# Build Options
#   change yes to no to disable
#
BOOTMAGIC_ENABLE = yes        # Enable Bootmagic Lite
MOUSEKEY_ENABLE = yes         # Mouse keys
EXTRAKEY_ENABLE = yes         # Audio control and System control
CONSOLE_ENABLE = no           # Console for debug
COMMAND_ENABLE = no           # Commands for debug and configuration
NKRO_ENABLE = yes             # Enable N-Key Rollover
BACKLIGHT_ENABLE = no         # Enable keyboard backlight functionality
RGBLIGHT_ENABLE = no          # Enable keyboard RGB underglow
RGB_MATRIX_ENABLE = yes       # Enable RGB Matrix
RGB_MATRIX_DRIVER = aw20216s  # RGB Matrix driver
AUDIO_ENABLE = no             # Audio output
ENCODER_ENABLE = yes          # Enable rotary encoder

# Feature Options
USER_CONFIG_ENABLE = yes
TAP_DANCE_ENABLE = no         # Enable tap dance functionality
LEADER_ENABLE = no            # Enable leader key functionality
AUTO_SHIFT_ENABLE = no        # Enable auto shift
DYNAMIC_MACRO_ENABLE = no     # Enable dynamic macros
UNICODE_COMMON = no           # Enable common unicode characters
UNICODEMAP_ENABLE = yes       # Enable unicode support
KEY_OVERRIDE_ENABLE = no      # Enable key overrides
COMBO_ENABLE = no             # Disable combos to save space

# Size optimization
LTO_ENABLE = yes              # Link Time Optimization
SPACE_CADET_ENABLE = no       # Disable space cadet to save space

# Custom source files
SRC += features/custom_keycodes.c
SRC += features/rgb_matrix.c
SRC += features/unicode.c
SRC += features/vim_navigation.c
SRC += layout/azerty_afnor.c
SRC += layout/bepo.c
SRC += layout/qwerty.c

# Include paths
VPATH += keyboards/gmmk/pro/rev1/iso/keymaps/mboutray/features
VPATH += keyboards/gmmk/pro/rev1/iso/keymaps/mboutray/layout
