# GMMK Pro ISO Multi-Layout Configuration

A professional QMK configuration for the GMMK Pro ISO keyboard featuring multiple layouts (AZERTY, QWERTY, BÉPO), vim-style navigation, and extensive customization options.

## Features

### Multiple Layouts
- **AZERTY** (French standard) - Red RGB indicator
- **QWERTY** (International) - Green RGB indicator  
- **BÉPO** (Optimized French) - Blue RGB indicator
- Layout persistence across power cycles via EEPROM

### Navigation System
- **Vim-style navigation** on dedicated layer (HJKL movement)
- **Word navigation** with W/B/E keys
- **Line navigation** with 0/$ keys
- **Document navigation** with gg/G commands
- Full modifier support (Shift for selection, Ctrl for larger movements)

### Programming Enhancements
- **Smart brackets**: Auto-closing with cursor positioning
- **French accents**: Direct access to é, è, à, ù, ç and uppercase variants
- **Leader sequences**: Quick access to code snippets and git commands
- **Dynamic macros**: Record and replay complex key sequences

### Layer Structure
1. **Base Layer** (_BASE): Main typing layer (layout-dependent)
2. **Function Layer** (FUNC): Media controls and F13-F17
3. **System Layer** (SYST): RGB control, layout switching, bootloader
4. **Navigation Layer** (NAVI): Vim-style cursor movement
5. **Symbol
