#include QMK_KEYBOARD_H

#define LBASE1 0
#define LBASE2 1
#define LNUM 2
#define EMOJI 3
#define LFN 4
#define LBSEL 5

#define TABNUM LT(LNUM, KC_TAB)
#define ENTNAV LT(EMOJI, KC_ENT)
#define BSNAV LT(EMOJI, KC_BSPC)
#define NAV MO(EMOJI)
#define BSSFT MT(MOD_RSFT,KC_BSPC)
#define FN MO(LFN)
#define BASE1 DF(LBASE1)
#define BASE2 DF(LBASE2)
#define BSEL MO(LBSEL)



enum emoji_map {
  UNAM, // unamused 😒
  HEYE, // smiling face with heart shaped eyes 😍
  OK, // ok hand sign 👌
  SMIR, // smirk 😏
  PRAY, // pray 🙏
  CELE, // celebration 🙌
  COOL, // smile with sunglasses 😎
  EYES, // eyes
  THNK, // BIG THONK
  NAIL, // Nailcare 💅
};

const uint32_t unicode_map[] PROGMEM = {
  [UNAM] = 0x1F612,
  [HEYE] = 0x1f60d,
  [OK]   = 0x1F44C,
  [SMIR] = 0x1F60F,
  [PRAY] = 0x1F64F,
  [CELE] = 0x1F64C,
  [COOL] = 0x1F60E,
  [EYES] = 0x1F440,
  [THNK] = 0x1F914,
  [NAIL] = 0x1F485,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[LBASE1] = LAYOUT_split_4x6_3(
_______,    KC_1,       KC_2,       KC_3,       KC_4,       KC_5,                              KC_6,       KC_7,       KC_8,       KC_9,       KC_0,       _______,
KC_ESC,     KC_Q,       KC_W,       KC_E,       KC_R,       KC_T,                              KC_Y,       KC_U,       KC_I,       KC_O,       KC_P,       KC_DEL,
KC_LALT,    KC_A,       KC_S,       KC_D,       KC_F,       KC_G,                              KC_H,       KC_J,       KC_K,       KC_L,       KC_SCLN,    KC_QUOT,
KC_LSFT,    KC_Z,       KC_X,       KC_C,       KC_V,       KC_B,                              KC_N,       KC_M,       KC_COMM,    KC_DOT,     KC_SLSH,    KC_RGUI,
                                                KC_LCTL,    TABNUM,     KC_SPC,    BSSFT,      ENTNAV,     FN
),

[LBASE2] = LAYOUT_split_4x6_3(
_______,    KC_1,       KC_2,       KC_3,       KC_4,       KC_5,                              KC_6,       KC_7,       KC_8,       KC_9,       KC_0,       _______,
KC_ESC,     KC_Q,       KC_W,       KC_E,       KC_R,       KC_T,                              KC_Y,       KC_U,       KC_I,       KC_O,       KC_P,       KC_DEL,
KC_TAB,     KC_A,       KC_S,       KC_D,       KC_F,       KC_G,                              KC_H,       KC_J,       KC_K,       KC_L,       KC_SCLN,    KC_QUOT,
KC_LSFT,    KC_Z,       KC_X,       KC_C,       KC_V,       KC_B,                              KC_N,       KC_M,       KC_COMM,    KC_DOT,     KC_SLSH,    KC_RGUI,
                                                KC_LALT,    KC_LCTL,    KC_SPC,    BSSFT,      ENTNAV,     FN
),

[LNUM] = LAYOUT_split_4x6_3(
_______,    KC_F1,      KC_F2,      KC_F3,      KC_F4,      KC_F5,                              KC_F6,      KC_F7,      KC_F8,      KC_F9,      KC_F10,     _______,
_______,    KC_EXLM,    KC_AT,      KC_HASH,    KC_DLR,     KC_TILD,                            _______,    KC_7,       KC_8,       KC_9,       _______,    KC_BSPC,
_______,    KC_PERC,    KC_CIRC,    KC_AMPR,    KC_ASTR,    KC_GRV,                             KC_MINS,    KC_4,       KC_5,       KC_6,       KC_PIPE,    _______,
_______,    _______,    _______,    _______,    _______,    _______,                            _______,    KC_1,       KC_2,       KC_3,       KC_BSLS,    _______,
                                                _______,    _______,    _______,    _______,    KC_0,       KC_DOT
),

  [EMOJI] = LAYOUT_split_4x6_3(

_______,    UM(CELE),  UM(PRAY),    _______,    _______,    _______,                            _______,    _______,    _______,    _______,    _______,    _______,
_______,    _______,    _______,    _______,    _______,    _______,                            _______,    _______,    _______,    _______,    _______,    _______,
_______,    _______,    _______,    _______,    _______,    _______,                            _______,    _______,    _______,    _______,    _______,    _______,
_______,    _______,    _______,    _______,    _______,    _______,                            _______,    _______,    _______,    _______,    _______,    _______,
                                                _______,    _______,    _______,    _______,    _______,    _______
    /* TO(0)   , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , QK_BOOT, */
    /* _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______, */
    /* _______ , UM(CELE), UM(PRAY), UM(NAIL), UM(OK)  , UM(THNK), _______ , _______ , _______ , UM(UNAM), UM(HEYE), UM(COOL), UM(EYES), UM(SMIR), _______, */
    /* _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______, */
    /* _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ */
  ),


[LFN] = LAYOUT_split_4x6_3(
_______,    KC_F1,      KC_F2,      KC_F3,      KC_F4,      KC_F5,                              KC_F6,      KC_F7,      KC_F8,      KC_F9,      KC_F10,     _______,
_______,    KC_F1,      KC_F2,      KC_F3,      KC_F4,      _______,                            _______,    _______,    _______,    _______,    KC_PSCR,    _______,
_______,    KC_F5,      KC_F6,      KC_F7,      KC_F8,      _______,                            _______,    _______,    _______,    _______,    _______,    _______,
_______,    KC_F9,      KC_F10,     KC_F11,     KC_F12,     BSEL,                               _______,    _______,    _______,    _______,    _______,    _______,
                                                _______,    _______,    _______,    _______,    _______,    _______
),

[LBSEL] = LAYOUT_split_4x6_3(
_______,    BASE1,      BASE2,      _______,    _______,    _______,                            _______,    _______,    _______,    _______,    _______,    _______,
_______,    _______,    _______,    _______,    _______,    _______,                            _______,    _______,    _______,    _______,    _______,    _______,
_______,    _______,    _______,    _______,    _______,    _______,                            _______,    _______,    _______,    _______,    _______,    _______,
_______,    _______,    _______,    _______,    _______,    _______,                            _______,    _______,    _______,    _______,    _______,    _______,
                                                _______,    _______,    _______,    _______,    _______,    _______
),

};


