// this is the style you want to emulate.
// This is the canonical layout file for the Quantum project. If you want to add another keyboard,

#include QMK_KEYBOARD_H

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _BASE 0
#define _NUM 1
#define _SYM 2
#define _NAV 3
#define _DEV 4

// Fillers to make layering more clear
#define _______ KC_TRNS
#define XXXXXXX KC_NO
#define LT_BASE LT(_BASE, TG(_BASE))
#define LT_NUM LT(_NUM, TG(_NUM))
#define LT_NAV LT(_NAV, TG(_NAV))
#define MO_DEV MO(_DEV)
#define MO_NAV MO(_NAV)
#define TO_BASE TO(_BASE)
#define TO_NAV TO(_NAV)
#define TO_DEV TO(_DEV)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BASE] = LAYOUT( /* Colemak= */
    KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                        KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,
    KC_TAB,  KC_Q,    KC_W,    KC_F,    KC_P,    KC_G,                        KC_J,    KC_L,    KC_U,    KC_Y,    KC_BSLS, KC_DELT,
    KC_LSFT, KC_A,    KC_R,    KC_S,    KC_T,    KC_D,                        KC_H,    KC_N,    KC_E,    KC_I,    KC_O,    KC_QUOT,
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                        KC_K,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_LBRC,
    KC_LCTL, KC_LGUI, KC_LALT, MO_DEV,  LT_NAV,  KC_SPC,  TG(_NAV),   TG(_NAV),   KC_ENT,  LT_NAV,  MO_DEV,  KC_RALT, KC_RGUI, KC_RCTL
  ),

  [_NAV] = LAYOUT(
    _______, _______, _______, _______, _______, _______,                     _______, _______, _______, _______, _______, _______,
    KC_BTN2, KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, KC_BTN1,                     KC_F12,  KC_4,    KC_5,    KC_6,    _______, TO_DEV,
    TO_BASE, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, _______,                     _______, KC_1,    KC_2,    KC_3,    _______, _______,
    _______, KC_HOME, KC_PGDN, KC_PGUP, KC_END,  _______,                     _______, KC_0,    _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______,  _______,  _______, _______, _______, _______, _______, _______
  ),

  [_DEV] = LAYOUT(
    KC_F12,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                       KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, RESET
  )

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
