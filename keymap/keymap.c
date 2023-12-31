#include QMK_KEYBOARD_H
#include <stdint.h>
#include "annepro2.h"
#include "qmk_ap2_led.h"

#define ________ KC_TRNS

// force space cadet training by disabling normal shifted keys
#undef SPACE_CADET_TRAINING

enum anne_pro_layers {
  _BASE_LAYER,
  _FN1_LAYER,
  _FN2_LAYER,
};

// macros
enum custom_keycodes {
  SS_ARROW = SAFE_RANGE,
  SS_FAT_ARROW
};

// tapdance keycodes
enum td_keycodes {
  TD_ESC_CAPS
};


qk_tap_dance_action_t tap_dance_actions[] = {
  [TD_ESC_CAPS] = ACTION_TAP_DANCE_DOUBLE(KC_ESC, KC_CAPS)
};

/*
* Layer _BASE_LAYER
* ,-----------------------------------------------------------------------------------------.
* |  `~ |  1  |  2  |  3  |  4  |  5  |  6  |  7  |  8  |  9  |  0  |  -  |  =  |    Bksp   |
* |-----------------------------------------------------------------------------------------+
* | Tab    |  q  |  w  |  e  |  r  |  t  |  y  |  u  |  i  |  o  |  p  |  [  |  ]  |   \    |
* |-----------------------------------------------------------------------------------------+
* | Esc     |  a  |  s  |  d  |  f  |  g  |  h  |  j  |  k  |  l  |  ;  |  '  |    Enter    |
* |-----------------------------------------------------------------------------------------+
* | Shift      |  z  |  x  |  c  |  v  |  b  |  n  |  m  |  ,  |  .  |  /  |    Shift       |
* |-----------------------------------------------------------------------------------------+
* | Ctrl  |  L1   |  Alt  |               space             |  Alt  |  FN1  |  FN2  | Ctrl  |
* \-----------------------------------------------------------------------------------------/
* Layer TAP in _BASE_LAYER
* ,-----------------------------------------------------------------------------------------.
* |     |     |     |     |     |     |     |     |     |     |     |     |     |           |
* |-----------------------------------------------------------------------------------------+
* |        |     |     |     |     |     |     |     |     |     |     |     |     |        |
* |-----------------------------------------------------------------------------------------+
* |         |     |     |     |     |     |     |     |     |     |     |     |             |
* |-----------------------------------------------------------------------------------------+
* |            |     |     |     |     |     |     |     |     |     |     |       UP       |
* |-----------------------------------------------------------------------------------------+
* |       |       |       |                                 |       |  LEFT | DOWN  | RIGHT |
* \-----------------------------------------------------------------------------------------/
*/
 const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
 [_BASE_LAYER] = KEYMAP( /* Base */
    LT(_FN2_LAYER, KC_GRV), KC_1   , KC_2         , KC_3  , KC_4         , KC_5         , KC_6    , KC_7         , KC_8    , KC_9           , KC_0   , KC_MINS      , KC_EQL  , KC_BSPC,
    LT(_FN1_LAYER, KC_TAB), KC_Q   , KC_W         , KC_E  , KC_R         , KC_T         , KC_Y    , KC_U         , KC_I    , KC_O           , KC_P   ,
#ifdef SPACE_CADET_TRAINING
    ________     , ________,
#else
    KC_LBRC, KC_RBRC,
#endif
    KC_BSLS,
    TD(TD_ESC_CAPS)       , KC_A   , KC_S         , KC_D  , KC_F         , KC_G         , KC_H    , KC_J         , KC_K    , KC_L           , KC_SCLN, KC_QUOT      , KC_ENT  ,
    KC_LSPO               , KC_Z   , KC_X         , KC_C  , KC_V         , KC_B         , KC_N    , KC_M         , KC_COMM , KC_DOT         , KC_SLSH, KC_RSPC      ,
    KC_LCPO               , KC_LGUI, KC_LAPO      , KC_SPC, KC_RAPC      , LT(_FN1_LAYER, KC_LEFT), LT(_FN2_LAYER, KC_DOWN), KC_RCPC
),
  /*
  * Layer _FN1_LAYER
  * ,-----------------------------------------------------------------------------------------.
  * |  `  |  F1 |  F2 |  F3 |  F4 |  F5 |  F6 |  F7 |  F8 |  F9 | F10 | F11 | F12 |  DELETE   |
  * |-----------------------------------------------------------------------------------------+
  * | Tab    |  q  | UP  |  e  |  r  |  t  |  y  |  u  |  i  |  o  | PS | HOME | END |   \    |
  * |-----------------------------------------------------------------------------------------+
  * | Esc     |LEFT |DOWN |RIGHT|  f  |  g  |  h  |  j  |  k  |  l  | PGUP|PGDN |    Enter    |
  * |-----------------------------------------------------------------------------------------+
  * | Shift      |V-UP |V-DWN|MUTE |  v  |  b  |  n  |  m  |  ,  |INSRT| DEL |    Shift       |
  * |-----------------------------------------------------------------------------------------+
  * | Ctrl  |  L1   |  Alt  |               space             |  Alt  |  FN1  |  FN2  | Ctrl  |
  * \-----------------------------------------------------------------------------------------/
  *
  */
 [_FN1_LAYER] = KEYMAP( /* Base */
    KC_GRV  , KC_F1   , KC_F2   , KC_F3   , KC_F4   , KC_F5   , KC_F6         , KC_F7   , KC_F8   , KC_F9   , KC_F10 , KC_F11  , KC_F12  , KC_DEL  ,
    ________, ________, KC_UP   , ________, ________, ________, ________      , ________, ________, ________, KC_PSCR, KC_HOME , KC_END  , ________,
    ________, KC_LEFT , KC_DOWN , KC_RGHT , ________, ________, KC_LEFT       , KC_DOWN , KC_UP   , KC_RIGHT, KC_PGUP, KC_PGDN , ________,
    ________, KC_VOLU , KC_VOLD , KC_MUTE , ________, ________, ________      , ________, ________, KC_INS  , KC_DEL , ________,
    ________, ________, ________, ________, ________, ________, MO(_FN2_LAYER), ________
),
  /*
  * Layer _FN2_LAYER
  * ,-----------------------------------------------------------------------------------------.
  * |  ~  | BT1 | BT2 | BT3 | BT4 |  F5 |  F6 |  F7 |LEDOF|LEDON| F10 | F11 | F12 |    Bksp   |
  * |-----------------------------------------------------------------------------------------+
  * | Tab    |  q  | UP  |  e  |  r  |  t  |  y  |  u  |  i  |  o  | PS | HOME | END |   \    |
  * |-----------------------------------------------------------------------------------------+
  * | Esc     |LEFT |DOWN |RIGHT|  f  |  g  |  h  |  j  |  k  |  l  | PGUP|PGDN |    Enter    |
  * |-----------------------------------------------------------------------------------------+
  * | Shift      |  z  |  x  |  c  |  v  |  b  |  n  |  m  |  ,  |INSRT| DEL |    Shift       |
  * |-----------------------------------------------------------------------------------------+
  * | Ctrl  |  L1   |  Alt  |               space             |  Alt  |  FN1  |  FN2  | Ctrl  |
  * \-----------------------------------------------------------------------------------------/
  *
  */
 [_FN2_LAYER] = KEYMAP( /* Base */
    ________      , KC_AP2_BT1, KC_AP2_BT2, KC_AP2_BT3, KC_AP2_BT4, ________      , ________      , ________, KC_AP_LED_OFF, KC_AP_LED_ON, ________, SS_ARROW, SS_FAT_ARROW, ________,
    MO(_FN2_LAYER), ________  , KC_UP     , ________  , ________  , ________      , ________      , ________, ________     , ________    , KC_PSCR , KC__VOLDOWN, KC__VOLUP, KC__MUTE,
    ________      , KC_LEFT   , KC_DOWN   , KC_RGHT   , ________  , ________      , ________      , ________, ________     , ________    , KC_PGUP , KC_PGDN    , KC_MPLY  ,
    ________      , ________  , ________  , ________  , ________  , ________      , ________      , ________, ________     , KC_INS      , KC_DEL  , ________   ,
    ________      , ________  , ________  , ________  , ________  , MO(_FN1_LAYER), MO(_FN2_LAYER), ________
 ),
};

//const uint16_t keymaps_size = sizeof(keymaps);


void matrix_init_user(void) {

}

void matrix_scan_user(void) {
}

layer_state_t layer_state_set_user(layer_state_t layer) {
  return layer;
}

bool _keypress_is_shifted(keyrecord_t *record) {
  if (record->event.pressed) {
    if (get_mods() & MOD_MASK_SHIFT)
      return true;
    else
      return false;
  }

  // key not pressed
  return false;
}

// keypress handler, handle macros
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    #ifdef SPACE_CADET_TRAINING
    // disable normal parens to force adjustment to space cadet shift
    case KC_9:
      return ! _keypress_is_shifted(record);

    case KC_0:
      return ! _keypress_is_shifted(record);
    #endif

    // these are not currently working
    case SS_ARROW:
      if (record->event.pressed)
        SEND_STRING("->");
      break;
    case SS_FAT_ARROW:
      if (record->event.pressed)
        SEND_STRING("=>");
      break;
  }

  return true;
}
