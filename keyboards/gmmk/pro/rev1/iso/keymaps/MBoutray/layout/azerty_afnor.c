
#include "azerty_afnor.h"

bool process_afnor_keycodes(uint16_t keycode, keyrecord_t *record) {
    if (!record->event.pressed) return true;

    bool shift = get_mods() & MOD_MASK_SHIFT;
    bool altgr = get_mods() & MOD_BIT(KC_RALT);

    if (shift && altgr) {
        for (int i = 0; i < ARRAY_SIZE(afnor_mappings); i++) {
            if (keycode == afnor_mappings[i].base) {
                tap_code16(afnor_mappings[i].shift_altgr);
                return false;
            }
        }
        return true;
    } else if (shift) {
        for (int i = 0; i < ARRAY_SIZE(afnor_mappings); i++) {
            if (keycode == afnor_mappings[i].base) {
                tap_code16(afnor_mappings[i].shift);
                return false;
            }
        }
        return true;
    } else if (altgr) {
        for (int i = 0; i < ARRAY_SIZE(afnor_mappings); i++) {
            if (keycode == afnor_mappings[i].base) {
                tap_code16(afnor_mappings[i].altgr);
                return false;
            }
        }
        return true;
    } else {
        return true;
    }
}

static const afnor_keycode_mapping_t PROGMEM afnor_mappings[48] = {
    { AF_AT,   FR_AF_HASH, FR_AF_BREV, FR_AF_IBRV },
    { AF_AGRV, FR_AF_1,    FR_AF_SECT, FR_AF_AGRV_CAPS },
    { AF_EACU, FR_AF_2,    FR_AF_ACUT, FR_AF_EACU_CAPS },
    { AF_EGRV, FR_AF_3,    FR_AF_GRV,  FR_AF_EGRV_CAPS },
    { AF_ECIR, FR_AF_4,    FR_AF_AMPR, FR_AF_ECIR_CAPS },
    { AF_LPRN, FR_AF_5,    FR_AF_LBRC, FR_AF_DACU },
    { AF_RPRN, FR_AF_6,    FR_AF_RBRC, FR_AF_DGRV },
    { AF_LSQU, FR_AF_7,    FR_AF_MACR, XXXXXXX },
    { AF_RSQU, FR_AF_8,    FR_AF_UNDS, FR_AF_MDSH },
    { AF_LDAQ, FR_AF_9,    FR_AF_LDQU, FR_AF_LSAQ },
    { AF_RDAQ, FR_AF_0,    FR_AF_RDQU, FR_AF_RSAQ },
    { AF_QUOT, FR_AF_DQUO, FR_AF_DEG,  FR_AF_RNGA },
    { AF_CIRC, FR_AF_DIAE, FR_AF_CARN, XXXXXXX },
    { AF_A,    FR_AF_A,    FR_AF_AE,   FR_AF_AE_CAPS },
    { AF_Z,    FR_AF_Z,    FR_AF_PND,  XXXXXXX },
    { AF_E,    FR_AF_E,    FR_AF_EURO, XXXXXXX },
    { AF_R,    FR_AF_R,    FR_AF_REGD, XXXXXXX },
    { AF_T,    FR_AF_T,    FR_AF_LCBR, FR_AF_TM   },
    { AF_Y,    FR_AF_Y,    FR_AF_RCBR, XXXXXXX },
    { AF_U,    FR_AF_U,    FR_AF_UGRV, FR_AF_UGRV_CAPS },
    { AF_I,    FR_AF_I,    FR_AF_DOTA, FR_AF_DOTB },
    { AF_O,    FR_AF_O,    FR_AF_OE,   FR_AF_OE_CAPS },
    { AF_P,    FR_AF_P,    FR_AF_PERC, FR_AF_PERM },
    { AF_MINS, FR_AF_NDSH, FR_AF_MMNS, FR_AF_NBHY },
    { AF_PLUS, FR_AF_PLMN, FR_AF_DAGG, FR_AF_DDAG },
    { AF_Q,    FR_AF_Q,    FR_AF_THET, XXXXXXX },
    { AF_S,    FR_AF_S,    FR_AF_SS,   FR_AF_SS_CAPS },
    { AF_D,    FR_AF_D,    FR_AF_DLR,  XXXXXXX },
    { AF_F,    FR_AF_F,    FR_AF_CURR, XXXXXXX },
    { AF_G,    FR_AF_G,    FR_AF_DGRK, XXXXXXX },
    { AF_H,    FR_AF_H,    FR_AF_EU,   FR_AF_MACB },
    { AF_J,    FR_AF_J,    XXXXXXX,    XXXXXXX },
    { AF_K,    FR_AF_K,    FR_AF_DSLS, XXXXXXX },
    { AF_L,    FR_AF_L,    FR_AF_PIPE, XXXXXXX },
    { AF_M,    FR_AF_M,    FR_AF_INFN, XXXXXXX },
    { AF_SLSH, FR_AF_BSLS, FR_AF_DIV,  FR_AF_SQRT },
    { AF_ASTR, FR_AF_HALF, FR_AF_MUL,  FR_AF_QRTR },
    { AF_LABK, FR_AF_RABK, FR_AF_LEQL, FR_AF_GEQL },
    { AF_W,    FR_AF_W,    FR_AF_EZH,  FR_AF_EZH_CAPS },
    { AF_X,    FR_AF_X,    FR_AF_COPY, XXXXXXX },
    { AF_C,    FR_AF_C,    FR_AF_CCED, FR_AF_CCED_CAPS },
    { AF_V,    FR_AF_V,    FR_AF_CEDL, FR_AF_OGON },
    { AF_B,    FR_AF_B,    FR_AF_DMNS, XXXXXXX },
    { AF_N,    FR_AF_N,    FR_AF_DTIL, XXXXXXX },
    { AF_DOT,  FR_AF_QUES, FR_AF_IQUE, XXXXXXX },
    { AF_COMM, FR_AF_EXLM, FR_AF_IEXL, FR_AF_DCMM },
    { AF_COLN, FR_AF_ELLP, FR_AF_MDDT, XXXXXXX },
    { AF_SCLN, FR_AF_EQL,  FR_AF_AEQL, FR_AF_NEQL }
};
