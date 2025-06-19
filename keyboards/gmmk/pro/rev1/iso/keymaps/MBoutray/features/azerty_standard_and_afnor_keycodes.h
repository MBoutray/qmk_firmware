#include "keymap_french.h"

// Redefining Afnor specific keycodes
#define FR_AF_AT   KC_GRV  // @
#define FR_AF_AGRV KC_1    // à
#define FR_AF_EACU FR_EACU // é
#define FR_AF_EGRV KC_3    // è
#define FR_AF_ECIR KC_4    // ê
#define FR_AF_LPRN FR_LPRN // (
#define FR_AF_RPRN KC_6    // )
#define FR_AF_LSQU KC_7    // ‘
#define FR_AF_RSQU KC_8    // ’
#define FR_AF_LDAQ KC_9    // «
#define FR_AF_RDAQ KC_0    // »
#define FR_AF_QUOT KC_MINS // '
#define FR_AF_CIRC KC_EQL  // ^ (dead)
#define FR_AF_A    FR_A    // A
#define FR_AF_Z    FR_Z    // Z
#define FR_AF_E    FR_E    // E
#define FR_AF_R    FR_R    // R
#define FR_AF_T    FR_T    // T
#define FR_AF_Y    FR_Y    // Y
#define FR_AF_U    FR_U    // U
#define FR_AF_I    FR_I    // I
#define FR_AF_O    FR_O    // O
#define FR_AF_P    FR_P    // P
#define FR_AF_MINS KC_LBRC // -
#define FR_AF_PLUS KC_RBRC // +
#define FR_AF_Q    FR_Q // Q
#define FR_AF_S    FR_S // S
#define FR_AF_D    FR_D // D
#define FR_AF_F    FR_F // F
#define FR_AF_G    FR_G // G
#define FR_AF_H    FR_H // H
#define FR_AF_J    FR_J // J
#define FR_AF_K    FR_K // K
#define FR_AF_L    FR_L // L
#define FR_AF_M    FR_M // M
#define FR_AF_SLSH KC_QUOT // /
#define FR_AF_ASTR FR_ASTR // *
#define FR_AF_LABK FR_LABK // <
#define FR_AF_W    FR_W    // W
#define FR_AF_X    FR_X    // X
#define FR_AF_C    FR_C    // C
#define FR_AF_V    FR_V    // V
#define FR_AF_B    FR_B    // B
#define FR_AF_N    FR_N    // N
#define FR_AF_DOT  KC_M    // .
#define FR_AF_COMM KC_COMM // ,
#define FR_AF_COLN FR_COLN  // :
#define FR_AF_SCLN KC_SLSH // ;
#define FR_AF_HASH S(FR_AF_AT)   // #
#define FR_AF_1    S(FR_AF_AGRV) // 1
#define FR_AF_2    S(FR_AF_EACU) // 2
#define FR_AF_3    S(FR_AF_EGRV) // 3
#define FR_AF_4    S(FR_AF_ECIR) // 4
#define FR_AF_5    S(FR_AF_LPRN) // 5
#define FR_AF_6    S(FR_AF_RPRN) // 6
#define FR_AF_7    S(FR_AF_LSQU) // 7
#define FR_AF_8    S(FR_AF_RSQU) // 8
#define FR_AF_9    S(FR_AF_LDAQ) // 9
#define FR_AF_0    S(FR_AF_RDAQ) // 0
#define FR_AF_DQUO S(FR_AF_QUOT) // "
#define FR_AF_DIAE S(FR_AF_CIRC) // ¨ (dead)
#define FR_AF_NDSH S(FR_AF_MINS) // –
#define FR_AF_PLMN S(FR_AF_PLUS) // ±
#define FR_AF_BSLS S(FR_AF_SLSH) // (backslash)
#define FR_AF_HALF S(FR_AF_ASTR) // ½
#define FR_AF_RABK S(FR_AF_LABK) // >
#define FR_AF_QUES S(FR_AF_DOT)  // ?
#define FR_AF_EXLM S(FR_AF_COMM) // !
#define FR_AF_ELLP S(FR_AF_COLN) // …
#define FR_AF_EQL  S(FR_AF_SCLN) // =
#define FR_AF_BREV ALGR(FR_AF_AT)   // ˘ (dead)
#define FR_AF_SECT ALGR(FR_AF_AGRV) // §
#define FR_AF_ACUT ALGR(FR_AF_EACU) // ´ (dead)
#define FR_AF_GRV  ALGR(FR_AF_EGRV) // ` (dead)
#define FR_AF_AMPR ALGR(FR_AF_ECIR) // &
#define FR_AF_LBRC ALGR(FR_AF_LPRN) // [
#define FR_AF_RBRC ALGR(FR_AF_RPRN) // ]
#define FR_AF_MACR ALGR(FR_AF_LSQU) // ¯ (dead)
#define FR_AF_UNDS ALGR(FR_AF_RSQU) // _
#define FR_AF_LDQU ALGR(FR_AF_LDAQ) // “
#define FR_AF_RDQU ALGR(FR_AF_RDAQ) // ”
#define FR_AF_DEG  ALGR(FR_AF_QUOT) // °
#define FR_AF_CARN ALGR(FR_AF_CIRC) // ˇ (dead)
#define FR_AF_AE   ALGR(FR_AF_A)    // æ
#define FR_AF_PND  ALGR(FR_AF_Z)    // £
#define FR_AF_EURO ALGR(FR_AF_E)    // €
#define FR_AF_REGD ALGR(FR_AF_R)    // ®
#define FR_AF_LCBR ALGR(FR_AF_T)    // {
#define FR_AF_RCBR ALGR(FR_AF_Y)    // }
#define FR_AF_UGRV ALGR(FR_AF_U)    // ù
#define FR_AF_DOTA ALGR(FR_AF_I)    // ˙ (dead)
#define FR_AF_OE   ALGR(FR_AF_O)    // œ
#define FR_AF_PERC ALGR(FR_AF_P)    // %
#define FR_AF_MMNS ALGR(FR_AF_MINS) // −
#define FR_AF_DAGG ALGR(FR_AF_PLUS) // †
#define FR_AF_THET ALGR(FR_AF_Q)    // θ
#define FR_AF_SS   ALGR(FR_AF_S)    // ß
#define FR_AF_DLR  ALGR(FR_AF_D)    // $
#define FR_AF_CURR ALGR(FR_AF_F)    // ¤ (dead monetary key)
#define FR_AF_DGRK ALGR(FR_AF_G)    // µ (dead Greek key)
#define FR_AF_EU   ALGR(FR_AF_H)    // Eu (dead European symbol key)
#define FR_AF_DSLS ALGR(FR_AF_K)    // ∕ (dead)
#define FR_AF_PIPE ALGR(FR_AF_L)    // |
#define FR_AF_INFN ALGR(FR_AF_M)    // ∞
#define FR_AF_DIV  ALGR(FR_AF_SLSH) // ÷
#define FR_AF_MUL  ALGR(FR_AF_ASTR) // ×
#define FR_AF_LEQL ALGR(FR_AF_LABK) // ≤
#define FR_AF_EZH  ALGR(FR_AF_W)    // ʒ
#define FR_AF_COPY ALGR(FR_AF_X)    // ©
#define FR_AF_CCED ALGR(FR_AF_C)    // ç
#define FR_AF_CEDL ALGR(FR_AF_V)    // ¸ (dead)
#define FR_AF_DMNS ALGR(FR_AF_B)    // − (dead)
#define FR_AF_DTIL ALGR(FR_AF_N)    // ~ (dead)
#define FR_AF_IQUE ALGR(FR_AF_DOT)  // ¿
#define FR_AF_IEXL ALGR(FR_AF_COMM) // ¡
#define FR_AF_MDDT ALGR(FR_AF_COLN) // ·
#define FR_AF_AEQL ALGR(FR_AF_SCLN) // ≃
#define FR_AF_IBRV S(ALGR(FR_AF_AT))   // ̑ (dead)
#define FR_AF_DACU S(ALGR(FR_AF_LPRN)) // ˝ (dead)
#define FR_AF_DGRV S(ALGR(FR_AF_RPRN)) // ̏ (dead)
#define FR_AF_MDSH S(ALGR(FR_AF_RSQU)) // —
#define FR_AF_LSAQ S(ALGR(FR_AF_LDAQ)) // ‹
#define FR_AF_RSAQ S(ALGR(FR_AF_RDAQ)) // ›
#define FR_AF_RNGA S(ALGR(FR_AF_QUOT)) // ˚ (dead)
#define FR_AF_TM   S(ALGR(FR_AF_T))    // ™
#define FR_AF_DOTB S(ALGR(FR_AF_I))    // ̣ (dead)
#define FR_AF_PERM S(ALGR(FR_AF_P))    // ‰
#define FR_AF_NBHY S(ALGR(FR_AF_MINS)) // ‑ (non-breaking hyphen)
#define FR_AF_DDAG S(ALGR(FR_AF_PLUS)) // ‡
#define FR_AF_MACB S(ALGR(FR_AF_H))    // ˍ (dead)
#define FR_AF_SQRT S(ALGR(FR_AF_SLSH)) // √
#define FR_AF_QRTR S(ALGR(FR_AF_ASTR)) // ¼
#define FR_AF_GEQL S(ALGR(FR_AF_LABK)) // ≥
#define FR_AF_OGON S(ALGR(FR_AF_V))    // ˛ (dead)
#define FR_AF_DCMM S(ALGR(FR_AF_COMM)) // ̦ (dead)
#define FR_AF_NEQL S(ALGR(FR_AF_SCLN)) // ≠
