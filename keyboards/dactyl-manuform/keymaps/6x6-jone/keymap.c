#include "dactyl-manuform.h"
#include "action_layer.h"
#include "eeconfig.h"
#include "quantum.h"
#include QMK_KEYBOARD_H

extern keymap_config_t keymap_config;

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _BASE  0
#define _UP_L  1
#define _UP_R  2
#define _UPSR  3
#define _UPSL  4
#define _DN_L  5
#define _DN_R  6
#define _DNSL  7
#define _DNSR  8
#define _EX_L  9
#define _EX_R  10
#define _SM_L  11
#define _SM_R  12
#define _SMSL  13
#define _SMSR  14
#define _SMML  15
#define _SMMR  16

// Fillers to make layering more clear
#define __ KC_TRNS
#define _______ KC_TRNS
#define XXXXXXX KC_NO
#define THMB_UL LT(_UP_L, KC_ENTER)
#define THMB_UR LT(_UP_R, KC_ENTER)
#define THMB_DL LT(_DN_L, KC_SPACE)
#define THMB_DR LT(_DN_R, KC_SPACE)
#define CTL_TAB LCTL_T(KC_TAB)
#define CTL_RHT RCTL_T(KC_RGHT)
#define CTL_QUO RCTL_T(KC_QUOT)
#define GUI_ENT RGUI_T(KC_ENT)
#define GUI_DEL RGUI_T(KC_DELETE)
#define GUI_UP RGUI_T(KC_UP)
#define GUI_TAB RGUI_T(KC_TAB)
#define ALT_TIL LALT_T(KC_GRAVE)
#define ALT_DWN RALT_T(KC_DOWN)
#define ALT_DEL RALT_T(KC_DELETE)
#define ALT_BSP RALT_T(KC_BSPC)
#define SFT_TAB LSFT_T(KC_TAB)
#define SYM_DEL LT(_SM_R, KC_DELETE)
#define SYM_BSP LT(_SM_L, KC_BSPC)
#define H_ALT_A LALT_T(KC_A)
#define H_GUI_E LGUI_T(KC_E)
#define H_SFT_S LSFT_T(KC_S)
#define H_CTL_T LCTL_T(KC_T)
#define H_HYP_G ALL_T(KC_G)
#define EXT_L LT(_EX_L, KC_TAB)
#define EXT_R LT(_EX_R, KC_TAB)
#define ALT_LED ALT_T(KC_LEAD)
#define AGR_LED ALGR_T(KC_LEAD)

#define STAR 0x2605 // ★

enum custom_keycodes {
  COLEMAK = SAFE_RANGE,
  LOWER,
  RAISE,
};



const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[_BASE] = KEYMAP_6x6(
  // left hand
//   KC_F1,           KC_F2,   KC_F3,   KC_F4,  KC_F5,  KC_F6,
   RESET,  _______,  _______,  _______,  _______,  _______,
   KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,
   ALT_TIL, KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,
   KC_RCTL, KC_A,    KC_R,    KC_S,    KC_T,    KC_G,
   KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_D,    KC_V,
                             KC_BSPC, KC_DEL,
                                 KC_ENTER, KC_SPC,
                                   TT(_NAVIGATION), TT(_NUMBERS),
                                   KC_LALT, KC_LGUI,
  // right hand
//    KC_F7,   KC_F8,  KC_F9,   KC_F10,  KC_F11,  KC_F12,
    _______,  _______,  _______,  _______,  _______,  RESET,
    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,
    KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN, ALT_DEL,
    KC_M,    KC_N,    KC_E,    KC_I,    KC_O,    KC_QUOT,
    KC_K,    KC_H,    KC_COMM, KC_DOT,  KC_SLSH, KC_LSFT,
                       KC_BSPC, KC_DEL,
                KC_SPC, KC_ENTER,
        TT(_NUMBERS), TT(_NAVIGATION),
        KC_RGUI, KC_RALT),
[_UP_L] = KEYMAP_6x6(
  // left hand
    _______,   _______, _______, _______, _______, _______,
    _______,   KC_PAST, KC_7,    KC_8,    KC_9,    KC_LCBR,
    _______,   KC_EQL,  KC_4,    KC_5,    KC_6,    KC_LBRC,
    _______,   KC_MINS, KC_1,    KC_2,    KC_3,    KC_LPRN,
    MO(_UPSL), KC_BSLS, KC_0,    KC_COMM, KC_DOT,  KC_LABK,
                        _______,  _______,
                              _______, _______,
                                   _______, _______,
                                   _______, _______,
  // right hand
    _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______,
                        _______,     _______,
                  _______, _______,
        _______, _______,
        _______, _______),
[_UP_R] = KEYMAP_6x6(
  // left hand
    _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______,
                        _______,  _______,
                             KC_BTN1, KC_BTN2,
                                  _______, _______,
                                  _______, _______,
  // right hand
    _______, _______, _______, _______, _______, _______,
    KC_RCBR, KC_7,    KC_8,    KC_9,    KC_PAST, _______,
    KC_RBRC, KC_4,    KC_5,    KC_6,    KC_EQL,  _______,
    KC_RPRN, KC_1,    KC_2,    KC_3,    KC_MINS, CTL_QUO,
    KC_RABK, KC_0,    _______, _______, KC_BSLS, MO(_UPSR),
                        _______,  _______,
                  KC_BTN1, KC_BTN2,
        _______, _______,
        _______, _______),
[_UPSL] = KEYMAP_6x6(
  // left hand
    _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, KC_PSCR, _______,
    _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______,
                        _______,  _______,
                             KC_BTN1, KC_BTN2,
                                  _______, _______,
                                  _______, _______,
  // right hand
    _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______,
                       _______,  _______,
                  KC_BTN1, KC_BTN2,
        _______, _______,
        _______, _______)
[_UPSR] = KEYMAP_6x6(
  // left hand
    _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______,
                        _______,  _______,
                             KC_BTN1, KC_BTN2,
                                  _______, _______,
                                  _______, _______,
  // right hand
    _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, CTL_QUO,
    _______, _______, _______, _______, _______, MO(_UPSR),
                       _______,  _______,
                  KC_BTN1, KC_BTN2,
        _______, _______,
        _______, _______)
[_DN_L] = KEYMAP_6x6(
  // left hand
    _______, _______, _______, _______, _______, _______,
    KC_F12,  KC_F1,   KC_F2,   KC_F3,    KC_F4,  KC_F5,
    _______, LCTL(KC_Q), KC_PGUP, KC_UP, KC_PGDN, KC_HOME,
    _______, LCTL(KC_A), KC_LEFT, KC_DOWN, KC_RGHT, KC_END,
    MO(_DNSL), LCTL(KC_Z), LCTL(KC_X), LCTL(KC_C), LCTL(KC_D),
                        _______,  _______,
                             KC_BTN1, KC_BTN2,
                                  _______, _______,
                                  _______, _______,
  // right hand
    _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______,
                  KC_BTN1, KC_BTN2,
        _______, _______,
        _______, _______)
[_DN_R] = KEYMAP_6x6(
  // left hand
    _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______,
                        _______,  _______,
                             KC_BTN1, KC_BTN2,
                                  _______, _______,
                                  _______, _______,
  // right hand
    _______, _______, _______, _______, _______, _______,
    KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10,   KC_F11,
    KC_HOME, KC_PGUP, KC_UP, KC_PGDN, _______, _______,
    KC_END, KC_LEFT, KC_DOWN, KC_RGHT,   _______, CTL_QUO,
    _______, _______, _______, _______, _______, MO(_DNSR),
                  KC_BTN1, KC_BTN2,
        _______, _______,
        _______, _______)
[_DNSL] = KEYMAP_6x6(
  // left hand
    _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______,
    _______, _______, KC_WH_U, KC_MS_U, KC_WH_D, KC_BTN2,
    _______, _______, KC_MS_L, KC_MS_D, KC_MS_R, KC_BTN1,
    MO(_DNSL), _______, _______, _______, _______, _______,
                        _______,  _______,
                             KC_BTN1, KC_BTN2,
                                  _______, _______,
                                  _______, _______,
  // right hand
    _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______,
                  KC_BTN1, KC_BTN2,
        _______, _______,
        _______, _______)
[_DNSR] = KEYMAP_6x6(
  // left hand
    _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______,
                        _______,  _______,
                             KC_BTN1, KC_BTN2,
                                  _______, _______,
                                  _______, _______,
  // right hand
    _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______,
    KC_BTN2, KC_WH_U, KC_MS_U, KC_WH_D, _______, _______,
    KC_BTN1, KC_MS_L, KC_MS_D, KC_MS_R, _______, CTL_QUO,
    KC_BTN3, _______, _______, _______, _______, MO(_DNSR),
                  KC_BTN1, KC_BTN2,
        _______, _______,
        _______, _______)
[_EX_L] = KEYMAP_6x6(
  // left hand
    _______, _______, _______, _______, _______, _______,
    LGUI(S(KC_Q)), _______,    LGUI(KC_7), LGUI(KC_8), LGUI(KC_9), _______,
    LGUI(KC_GRV), KC_MNXT, LGUI(KC_4), LGUI(KC_5), LGUI(KC_6), KC_VOLU,
    _______, KC_MPLY, LGUI(KC_1), LGUI(KC_2), LGUI(KC_3), KC_MUTE,
    _______, LCTL(KC_Z), LGUI(KC_X), LGUI(KC_C), LGUI(KC_D), KC_VOLD,
                        _______,  _______,
                             KC_BTN1, KC_BTN2,
                                  _______, _______,
                                  _______, _______,
  // right hand
    _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______,
                  KC_BTN1, KC_BTN2,
        _______, _______,
        _______, _______)
[_EX_R] = KEYMAP_6x6(
  // left hand
    _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______,
                        _______,  _______,
                             KC_BTN1, KC_BTN2,
                                  _______, _______,
                                  _______, _______,
  // right hand
    _______, _______, _______, _______, _______, _______,
    _______, RGUI(KC_7), RGUI(KC_8), RGUI(KC_9), KC_PAST, RGUI(S(KC_Q)),
    KC_VOLU, RGUI(KC_4), RGUI(KC_5), RGUI(KC_6), KC_MNXT, _______,
    KC_MUTE, RGUI(KC_1), RGUI(KC_2), RGUI(KC_3), KC_MPLY, _______,
    KC_VOLD, RGUI(KC_0), RGUI(KC_C), RGUI(KC_D), KC_MPRV, _______,
                  KC_BTN1, KC_BTN2,
        _______, _______,
        _______, _______)
[_SM_L] = KEYMAP_6x6(
  // left hand
    _______, _______, _______, _______, _______, _______,
    RESET, UC(8543), UC(189), UC(8531), UC(188), UC(8533),
    _______, UC(952), UC(969), UC(966), UC(960), UC(946),
    _______, UC(945), UC(961), UC(963), UC(964), UC(947),
    MO(_SMSL), UC(950), UC(967), UC(162), UC(948), UC(8711),
                        _______,  _______,
                             KC_BTN1, KC_BTN2,
                                  _______, _______,
                                  _______, _______,
  // right hand
    _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______,
                  KC_BTN1, KC_BTN2,
        _______, _______,
        _______, _______)
[_SM_R] = KEYMAP_6x6(
  // left hand
    _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______,
                        _______,  _______,
                             KC_BTN1, KC_BTN2,
                                  _______, _______,
                                  _______, _______,
  // right hand
    _______, _______, _______, _______, _______, _______,
    UC(8537), UC(8528), UC(8539), UC(8529), UC(8530), RESET,
    UC(958), UC(955), UC(965), UC(968), UC(177), _______,
    UC(956), UC(8470), UC(949), UC(8734), _______, _______,
    UC(922), UC(951), UC(8804), UC(8805), UC(247), MO(_SMSR),
                  KC_BTN1, KC_BTN2,
        _______, _______,
        _______, _______)
};


// void persistant_default_layer_set(uint16_t default_layer) {
//   eeconfig_update_default_layer(default_layer);
//   default_layer_set(default_layer);
// }

// bool process_record_user(uint16_t keycode, keyrecord_t *record) {
//   switch (keycode) {
//         case COLEMAK:
//           if (record->event.pressed) {
//             #ifdef AUDIO_ENABLE
//               PLAY_NOTE_ARRAY(tone_colemak, false, 0);
//             #endif
//             persistant_default_layer_set(1UL<<_COLEMAK);
//           }
//           return false;
//           break;
//         case LOWER:
//           if (record->event.pressed) {
//             layer_on(_LOWER);
//             update_tri_layer(_LOWER, _RAISE, _ADJUST);
//           } else {
//             layer_off(_LOWER);
//             update_tri_layer(_LOWER, _RAISE, _ADJUST);
//           }
//           return false;
//           break;
//         case RAISE:
//           if (record->event.pressed) {
//             layer_on(_RAISE);
//             update_tri_layer(_LOWER, _RAISE, _ADJUST);
//           } else {
//             layer_off(_RAISE);
//             update_tri_layer(_LOWER, _RAISE, _ADJUST);
//           }
//           return false;
//           break;
//       }
//     return true;
// };
