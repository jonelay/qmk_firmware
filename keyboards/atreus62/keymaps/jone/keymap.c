// this is the style you want to emulate.
// This is the canonical layout file for the Quantum project. If you want to add another keyboard,

#include QMK_KEYBOARD_H

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _BASE  0
#define _DN_R  1
#define _DN_L  2
#define _DN_B  3
#define _DN_SB 4
#define _UP_R  5
#define _UP_L  6
#define _UP_B  7
#define _UP_SB 8
#define _EXTR  9
#define _EXTL  10

// Fillers to make layering more clear

#define _______ KC_TRNS
#define XXXXXXX KC_NO
#define THUMB_L LT(_UP_L, KC_BSPC)
#define THUMB_R LT(_UP_R, KC_DEL)
#define THUMB_B MO(_UP_B)
#define THUMB_SB MO(_UP_SB)
#define HOME_L LT(_DN_L, KC_SPACE)
#define HOME_R LT(_DN_R, KC_ENTER)
#define HOME_B MO(_DN_B)
#define HOME_SB MO(_DN_SB)
#define CTL_TAB LCTL_T(KC_TAB)
#define CTL_QUO RCTL_T(KC_QUOT)
#define GUI_QUO RGUI_T(KC_QUOT)
#define GUI_ENT RGUI_T(KC_ENT)
#define ALT_TIL LALT_T(KC_GRAVE)
#define ALT_DEL RALT_T(KC_DELETE)
#define SFT_TAB LSFT_T(KC_TAB)
#define H_ALT_A LALT_T(KC_A)
#define H_GUI_E LGUI_T(KC_E)
#define H_SFT_S LSFT_T(KC_S)
#define H_CTL_T LCTL_T(KC_T)
#define H_HYP_G ALL_T(KC_G)
#define EXT_L MO(_EXTL)
#define EXT_R MO(_EXTR)

#define STAR 0x2605 // ★

// #define LT_BASE LT(_BASE, TG(_BASE))
// #define LT_NUM LT(_NUM, TG(_NUM))
// #define LT_NAV LT(_NAV, TG(_NAV))

// #define TO_BASE TO(_BASE)
// #define TO_NAV TO(_NAV)
// #define TO_DEV TO(_DEV)

void matrix_init_user(void) {
    set_unicode_input_mode(UC_LNX); // REPLACE UC_XXXX with the Unicode Input Mode for your OS. See table below.
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BASE] = LAYOUT( /* Colemak= */
    KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                      KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,
    RESET,   KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,                      KC_J,    KC_L,    KC_U,    KC_Y,    KC_BSLS, ALT_DEL,
    CTL_TAB, KC_A,    KC_R,    KC_S,    KC_T,    KC_G,                      KC_M,    KC_N,    KC_E,    KC_I,    KC_O,    GUI_QUO,
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_D,    KC_V,                      KC_K,    KC_H,    KC_COMM, KC_DOT,  KC_SLSH, KC_LSFT,
    KC_LCTL, KC_LGUI, KC_LALT, EXT_L,   SFT_TAB, HOME_L,  THUMB_L, THUMB_R, HOME_R,  SFT_TAB, EXT_R,  KC_RALT,  KC_RGUI, KC_RCTL
  ),

  [_UP_R] = LAYOUT(
    _______, _______, _______, _______, _______, _______,                   KC_BTN3, KC_WH_L, KC_WH_D, KC_WH_U, KC_WH_R, _______,
    _______, _______, _______, _______, _______, _______,                   KC_BTN1, KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, _______,
    _______, _______, _______, _______, _______, _______,                   KC_BTN2, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, GUI_ENT,
    _______, _______, _______, _______, _______, _______,                   _______, KC_HOME, KC_PGDN, KC_PGUP, KC_END,  _______,
    _______, _______, _______, _______, _______, _______, THUMB_B, _______, _______, _______, _______, _______, _______, _______
  ),

  [_UP_L] = LAYOUT(
    _______, KC_WH_L, KC_WH_D, KC_WH_U, KC_WH_R, KC_BTN3,                   _______, _______, _______, _______, _______, _______,
    _______, KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, KC_BTN1,                   _______, _______, _______, _______, _______, _______,
    _______, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_BTN2,                   _______, _______, _______, _______, _______, _______,
    _______, KC_HOME, KC_PGDN, KC_PGUP, KC_END,  _______,                   _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, THUMB_B, _______, _______, _______, _______, _______, _______
  ),

  [_UP_B] = LAYOUT(
    _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                     KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_MUTE,
    _______, _______, _______, UC(9785), KC_PSCR, UC(8226),                   KC_PAUS, KC_MUTE, KC_VOLD, KC_VOLU, _______, RESET,
    _______, _______, UC(174), UC(9786), UC(8482), _______,                   KC_MPLY, KC_MPRV, _______, _______, KC_MNXT, _______,
    THUMB_SB, _______, _______, UC(169), UC(176), _______,                   KC_MSTP, _______, _______, _______, UC(8260), THUMB_SB,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
  ),

  [_UP_SB] = LAYOUT(
    _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                     KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_MUTE,
    _______, _______, _______, _______, _______, UC(9702),                   _______, _______, _______, _______, _______, RESET,
    _______, _______, _______, KC_SLCK, _______, _______,                   _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, UC(166), _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
  ),


  [_DN_R] = LAYOUT(
    _______, _______, _______, _______, _______, _______,                   KC_RCBR, KC_7,    KC_8,    KC_9,    KC_PAST, _______,
    _______, _______, _______, _______, _______, _______,                   KC_RBRC, KC_4,    KC_5,    KC_6,    KC_EQL,  RESET,
    _______, _______, _______, _______, _______, _______,                   KC_RPRN, KC_1,    KC_2,    KC_3,    KC_MINS, GUI_ENT,
    _______, _______, _______, _______, _______, _______,                   KC_RABK, KC_0,    _______, _______, _______, _______,
    _______, _______, _______, _______, _______, HOME_B,  _______, _______, _______, _______, _______, _______, _______, _______
  ),

  [_DN_L] = LAYOUT(
    _______, KC_PAST, KC_9,    KC_8,    KC_7,    KC_LCBR,                   _______, _______, _______, _______, _______, _______,
    _______, KC_EQL,  KC_6,    KC_5,    KC_4,    KC_LBRC,                   _______, _______, _______, _______, _______, RESET,
    _______, KC_MINS, KC_3,    KC_2,    KC_1,    KC_LPRN,                   _______, _______, _______, _______, _______, _______,
    _______, KC_SLSH, KC_DOT,  KC_COMM, KC_0,    KC_LABK,                   _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, HOME_B,  _______, _______, _______, _______, _______
  ),

  [_DN_B] = LAYOUT(
    _______, UC(8543), UC(189), UC(8531), UC(188), UC(8533),                   UC(8537), UC(8528), UC(8539), UC(8529), UC(8530), _______,
    _______, UC(952), UC(969), UC(966), UC(960), UC(946),                   UC(958), UC(955), _______, UC(968), UC(177), RESET,
    _______, UC(945), UC(961), UC(963), UC(964), UC(947),                   UC(956), _______, UC(949), UC(8734), _______, _______,
    HOME_SB, UC(950), UC(967), UC(162), UC(948), UC(8711),                   UC(922), UC(951), UC(8804), UC(8805), UC(247), HOME_SB,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
  ),

  [_DN_SB] = LAYOUT(
    _______, UC(8265), UC(178), UC(179), UC(163), UC(8733),                   UC(8743), _______, _______, UC(11816), UC(11817), _______,
    UC(65103), UC(920), UC(937), UC(934), UC(928), UC(914),                   UC(926), UC(923), _______, UC(936), UC(8757), RESET,
    _______, UC(913), UC(929), UC(931), UC(932), UC(915),                   UC(13186), UC(8470), UC(1013), UC(8747), _______, _______,
    _______, UC(918), UC(935), UC(8364), UC(916), UC(8730),                   UC(954), UC(13185), UC(8810), UC(8811), UC(8756), _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
  ),

  [_EXTR] = LAYOUT(
    _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, RESET,
    _______, _______, _______, _______, _______, _______,                   KC_HYPR, KC_RCTL, KC_RSFT, KC_RGUI, KC_RALT, GUI_ENT,
    _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
  ),

  [_EXTL] = LAYOUT(
    _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, RESET,
    _______, KC_LALT, KC_LGUI, KC_LSFT, KC_LCTL, KC_HYPR,                   _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
  ),


  /*
  [_TRNS] = LAYOUT(
    _______,  _______, _______, _______, _______, _______,                     _______, _______, _______, _______, _______, _______ ,
    _______,  _______, _______, _______, _______, _______,                     _______, _______, _______, _______, _______, _______ ,
    _______,  _______, _______, _______, _______, _______,                     _______, _______, _______, _______, _______, _______ ,
    _______,  _______, _______, _______, _______, _______,                     _______, _______, _______, _______, _______, _______ ,
    _______,  _______, _______, _______, _______, _______, _______,  _______,  _______, _______, _______, _______, _______, _______
  ),
  */
};



const uint16_t PROGMEM fn_actions[] = {

};


const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt) {
  // MACRODOWN only works in this function
  switch (id) {
  case 0:
    if (record->event.pressed) {
      register_code(KC_RSFT);
    }
    else {
      unregister_code(KC_RSFT);
    }
    break;
  }
  return MACRO_NONE;
};
