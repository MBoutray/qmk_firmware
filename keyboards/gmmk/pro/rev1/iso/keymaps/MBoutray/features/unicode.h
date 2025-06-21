#pragma once

#include "quantum.h"
// #include <stdint.h>

enum unicode_names {
    UNICODE_AT, // @ (arrobase)
    UNICODE_AGRV, // à (a grave)
    UNICODE_EACU, // é (e acute)
    UNICODE_EGRV, // è (e grave)
    UNICODE_ECIR, // ê (e circumflex)
    UNICODE_LPRN, // ( (left parenthesis)
    UNICODE_RPRN, // ) (right parenthesis)
    UNICODE_LSQU, // ‘ (left single quotation)
    UNICODE_RSQU, // ’ (right single quotation)
    UNICODE_LDAQ, // « (left double angle quotation)
    UNICODE_RDAQ, // » (right double angle quotation)
    UNICODE_QUOT, // ' (quotation mark)
    UNICODE_CIRC, // ^ (circumflex, dead key)
    UNICODE_A, // A
    UNICODE_Z, // Z
    UNICODE_E, // E
    UNICODE_R, // R
    UNICODE_T, // T
    UNICODE_Y, // Y
    UNICODE_U, // U
    UNICODE_I, // I
    UNICODE_O, // O
    UNICODE_P, // P
    UNICODE_MINS, // - (left bracket)
    UNICODE_PLUS, // + (plus)
    UNICODE_Q, // Q
    UNICODE_S, // S
    UNICODE_D, // D
    UNICODE_F, // F
    UNICODE_G, // G
    UNICODE_H, // H
    UNICODE_J, // J
    UNICODE_K, // K
    UNICODE_L, // L
    UNICODE_M, // M
    UNICODE_SLSH, // / (slash)
    UNICODE_ASTR, // * (asterisk)
    UNICODE_LABK, // < (left angle bracket)
    UNICODE_W, // W
    UNICODE_X, // X
    UNICODE_C, // C
    UNICODE_V, // V
    UNICODE_B, // B
    UNICODE_N, // N
    UNICODE_DOT, // . (dot)
    UNICODE_COMM, // , (comma)
    UNICODE_COLN, // : (colon)
    UNICODE_SCLN, // ; (semicolon)
    UNICODE_HASH, // # (hash)
    UNICODE_1, // 1
    UNICODE_2, // 2
    UNICODE_3, // 3
    UNICODE_4, // 4
    UNICODE_5, // 5
    UNICODE_6, // 6
    UNICODE_7, // 7
    UNICODE_8, // 8
    UNICODE_9, // 9
    UNICODE_0, // 0
    UNICODE_DQUO, // " (double quotation mark)
    UNICODE_DIAE, // ¨ (diaeresis, dead key)
    UNICODE_NDSH, // – (en dash)
    UNICODE_PLMN, // ∓ (plus-minus)
    UNICODE_BSLS, // \ (backslash)
    UNICODE_HALF, // ½ (one-half)
    UNICODE_RABK, // » (right angle bracket)
    UNICODE_QUES, // ¿ (inverted question mark)
    UNICODE_EXLM, // ¡ (inverted exclamation mark)
    UNICODE_ELLP, // … (ellipsis)
    UNICODE_EQL, // = (equals)
    UNICODE_BREV, // ˆ (breve)
    UNICODE_SECT, // § (section)
    UNICODE_ACUT, // ´ (acute)
    UNICODE_GRV, // ` (grave)
    UNICODE_AMPR, // & (ampersand)
    UNICODE_LBRC, // [ (left bracket)
    UNICODE_RBRC, // ] (right bracket)
    UNICODE_MACR, // ¯ (macron)
    UNICODE_UNDS, // _ (underscore)
    UNICODE_LDQU, // “ (left double quotation)
    UNICODE_RDQU, // ” (right double quotation)
    UNICODE_DEG, // ° (degree)
    UNICODE_CARN, // ˜ (caron)
    UNICODE_AE, // æ (ash)
    UNICODE_PND, // ∓ (plus-minus)
    UNICODE_EURO, // € (euro)
    UNICODE_REGD, // ® (registered)
    UNICODE_LCBR, // { (left curly bracket)
    UNICODE_RCBR, // } (right curly bracket)
    UNICODE_UGRV, // ù (u grave)
    UNICODE_DOTA, // ∘ (dot operator)
    UNICODE_OE, // œ (oe)
    UNICODE_PERC, // % (percent)
    UNICODE_MMNS, // ∓ (minus-plus)
    UNICODE_DAGG, // ∇ (nabla)
    UNICODE_THET, // θ (theta)
    UNICODE_SS, // ß (sharp s)
    UNICODE_DLR, // $ (dollar)
    UNICODE_CURR, // ¢ (cent)
    UNICODE_DGRK, // δ (delta)
    UNICODE_EU, // ∈ (element of)
    UNICODE_DSLS, // ∖ (set minus)
    UNICODE_PIPE, // | (pipe)
    UNICODE_INFN, // ∞ (infinity)
    UNICODE_DIV, // ÷ (division)
    UNICODE_MUL, // × (multiplication)
    UNICODE_LEQL, // ≤ (less than or equal to)
    UNICODE_EZH, // ɘ (ezh)
    UNICODE_COPY, // © (copyright)
    UNICODE_CCED, // ç (cedilla)
    UNICODE_CEDL, // ̦ (cedilla)
    UNICODE_DMNS, // ∖ (set minus)
    UNICODE_DTIL, // ̃ (tilde)
    UNICODE_IQUE, // ¿ (inverted question mark)
    UNICODE_IEXL, // ¡ (inverted exclamation mark)
    UNICODE_MDDT, // … (ellipsis)
    UNICODE_AEQL, // = (equals)
    UNICODE_IBRV, // ˆ (breve)
    UNICODE_AGRV_CAPS, // À (A grave)
    UNICODE_EACU_CAPS, // É (E acute)
    UNICODE_EGRV_CAPS, // È (E grave)
    UNICODE_ECIR_CAPS, // Ê (E circumflex)
    UNICODE_DACU, // ̄ (macron)
    UNICODE_DGRV, // ̋ (double grave)
    UNICODE_MDSH, // — (em dash)
    UNICODE_LSAQ, // ‘ (left single quotation)
    UNICODE_RSAQ, // ’ (right single quotation)
    UNICODE_RNGA, // ˜ (tilde)
    UNICODE_AE_CAPS, // Æ (AE)
    UNICODE_TM, // ™ (trade mark)
    UNICODE_UGRV_CAPS, // Ù (U grave)
    UNICODE_DOTB, // ∘ (dot operator)
    UNICODE_OE_CAPS, // Œ (OE)
    UNICODE_PERM, // ℗ (phonorecord)
    UNICODE_NBHY, // ‾ (non-breaking hyphen)
    UNICODE_DDAG, // ∇ (nabla)
    UNICODE_SS_CAPS, // ß (sharp s)
    UNICODE_MACB, // ̄ (macron)
    UNICODE_SQRT, // √ (square root)
    UNICODE_QRTR, // ⊠ (square)
    UNICODE_GEQL, // ≥ (greater than or equal to)
    UNICODE_EZH_CAPS, // ɘ (ezh)
    UNICODE_CCED_CAPS, // Ç (C cedilla)
    UNICODE_OGON, // ̨ (ogonek)
    UNICODE_DCMM, // ̄ (macron)
    UNICODE_NEQL, // ≠ (not equal)
};

const uint32_t PROGMEM unicode_map[146];
