#include "dactyl-manuform.h"
#include "action_layer.h"
#include "eeconfig.h"

extern keymap_config_t keymap_config;

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _QWERTY 0
#define _FN1    1

// Fillers to make layering more clear
#define _______ KC_TRNS
#define XXXXXXX KC_NO

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[_QWERTY] = KEYMAP_5x6(
  // left hand
  KC_GRV,    KC_1,    KC_2,    KC_3,   KC_4,   KC_5,
  KC_TAB,    KC_Q,    KC_W,    KC_E,   KC_R,   KC_T,
  KC_LCTRL,  KC_A,    KC_S,    KC_D,   KC_F,   KC_G,
  KC_LSHIFT, KC_Z,    KC_X,    KC_C,   KC_V,   KC_B,
                      _______, _______,
                               KC_RGUI,  MO(_FN1),
                               KC_LALT,  KC_SPC,
                               KC_LGUI,  KC_MHEN,
  // right hand
  KC_6,    KC_7,   KC_8,    KC_9,    KC_0,    KC_BSPC,
  KC_Y,    KC_U,   KC_I,    KC_O,    KC_P,    KC_DEL,
  KC_H,    KC_J,   KC_K,    KC_L,    KC_SCLN, KC_QUOT,
  KC_N,    KC_M,   KC_COMM, KC_DOT,  KC_SLSH, KC_RO,
                   KC_RBRC, KC_NUHS,
           KC_ENTER, KC_ESC,
           LSFT(KC_SPACE), XXXXXXX,
           KC_HENK,  KC_RCTL),


[_FN1] = KEYMAP_5x6(
  // left hand
  RESET,    KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,
  _______,  KC_1,     KC_2,     KC_3,     KC_4,     KC_5,
  _______,  _______,  KC_BTN2,  KC_MS_U,  KC_BTN1,  _______,
  _______,  KC_ACL2,  KC_MS_L,  KC_MS_D,  KC_MS_R,  _______,
                      _______,  _______,
                                _______,  _______,
                                _______,  _______,
                                _______,  _______,
  // right hand
  KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,  KC_JYEN,
  KC_6,     KC_7,     KC_8,     KC_9,     KC_0,    KC_EQL,
  KC_LEFT,  KC_DOWN,  KC_UP,    KC_RIGHT, _______, KC_MINS,
  KC_HOME,  KC_PGDN,  KC_PGUP,  KC_END,   KC_APPLICATION, KC_LBRC,
                      KC_F11,   KC_F12,
            _______,  _______,
            _______,  _______,
            _______,  _______),
};



void persistant_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}
