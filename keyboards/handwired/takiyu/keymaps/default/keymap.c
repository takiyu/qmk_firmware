#include QMK_KEYBOARD_H

#include "keymap_japanese.h"

enum custom_layer {
    _HOM,
    _1FN,
    _2VI,
    _3DE,
};

// TODO: Mouse key (Joystick)
// TODO: Dynamic macros

#define ___NG___ XXXXXXX
#define TK_SPC_1 LT(_1FN, KC_SPC)
#define TK_SPC_2 LT(_2VI, KC_SPC)
#define TK_TAB3  LCTL(KC_TAB)
#define TK_TAB2  LSFT(LCTL(KC_TAB))

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    // Home Layer
    [_HOM] = LAYOUT_5x8(
        KC_ESC,   JP_ZKHK, KC_1   , KC_2   , KC_3   , KC_4   , KC_5   , KC_6   ,    KC_7   , KC_8   , KC_9   , KC_0   , JP_MINS, JP_CIRC, JP_YEN , KC_BSPC,
        TO(_HOM), KC_TAB , KC_Q   , KC_W   , KC_E   , KC_R   , KC_T   ,___NG___,    KC_Y   , KC_U   , KC_I   , KC_O   , KC_P   , JP_AT  , JP_LBRC, KC_ENT ,
        TO(_1FN), KC_LCTL, KC_A   , KC_S   , KC_D   , KC_F   , KC_G   ,___NG___,    KC_H   , KC_J   , KC_K   , KC_L   , JP_SCLN, JP_COLN, JP_RBRC,___NG___,
        TO(_2VI), KC_LSFT, KC_LSFT, KC_Z   , KC_X   , KC_C   , KC_V   , KC_B   ,    KC_B   , KC_N   , KC_M   , JP_COMM, JP_DOT , JP_SLSH, JP_BSLS, KC_RSFT,
        TO(_3DE), KC_LCTL, KC_CAPS, KC_LWIN, KC_LALT, KC_RALT,TK_SPC_1,___NG___,   TK_SPC_1, KC_ESC , KC_RALT, KC_MENU, KC_RCTL, KC_WBAK, KC_WFWD, KC_PSCR
    ),

    // Function Layer
    [_1FN] = LAYOUT_5x8(
        KC_ESC,   JP_ZKHK, KC_F1  , KC_F2  , KC_F3  , KC_F4  , KC_F5  , KC_F6  ,    KC_F7  , KC_F8  , KC_F9  , KC_F10 , KC_F11 , KC_F12 , XXXXXXX, KC_DEL ,
        TO(_HOM), KC_TAB , KC_Q   , KC_W   , KC_E   , KC_R   , KC_T   ,___NG___,    KC_Y   , KC_U   , KC_INS , KC_O   , KC_P   , JP_AT  , KC_PGUP, KC_ENT ,
        TO(_1FN), KC_LCTL, KC_A   , KC_S   , KC_D   , KC_F   , KC_G   ,___NG___,    KC_LEFT, KC_DOWN, KC_UP  ,KC_RIGHT, JP_SCLN, JP_COLN, KC_PGDN,___NG___,
        TO(_2VI),MO(_1FN), KC_LSFT, KC_Z   , KC_DEL , KC_C   , KC_V   , KC_B   ,    KC_B   , KC_N   , KC_M   , JP_COMM, JP_DOT , JP_SLSH, JP_BSLS, KC_RSFT,
        TO(_3DE), KC_LCTL, KC_CAPS, KC_LWIN, KC_LALT, KC_RALT,TK_SPC_2,___NG___,   TK_SPC_2, KC_ESC , KC_RALT, KC_MENU, KC_RCTL, KC_WBAK, KC_WFWD, KC_PSCR
    ),

    // Vim-like Layer
    [_2VI] = LAYOUT_5x8(
        KC_ESC,   JP_ZKHK, KC_1   , TK_TAB2, TK_TAB3, KC_4   , KC_5   , KC_6   ,    KC_7   , KC_8   , KC_HOME, KC_END , JP_MINS, JP_CIRC, JP_YEN , KC_BSPC,
        TO(_HOM), KC_TAB , KC_Q   , KC_W   , KC_E   , KC_R   , KC_T   ,___NG___,    KC_Y   , KC_PGUP, KC_INS , KC_O   , KC_P   , JP_AT  , KC_PGUP, KC_ENT ,
        TO(_1FN), KC_LCTL, KC_A   , KC_S   , KC_PGDN, KC_F   , KC_G   ,___NG___,    KC_LEFT, KC_DOWN, KC_UP  ,KC_RIGHT, XXXXXXX, XXXXXXX, KC_PGDN,___NG___,
        TO(_2VI),MO(_1FN), KC_LSFT, XXXXXXX, KC_DEL , KC_C   , KC_V   , KC_B   ,    KC_B   , KC_N   , KC_M   , JP_COMM, JP_DOT , JP_SLSH, JP_BSLS, KC_RSFT,
        TO(_3DE), KC_LCTL, KC_CAPS, KC_LWIN, KC_LALT, KC_RALT,TK_SPC_1,___NG___,   TK_SPC_1, KC_ESC , KC_RALT, KC_MENU, KC_RCTL, KC_WBAK, KC_WFWD, KC_PSCR
    ),

    // Debug Layer
    [_3DE] = LAYOUT_5x8(
        KC_ESC,   JP_ZKHK, KC_1   , KC_2   , KC_3   , KC_4   , KC_5   , KC_6   ,    KC_7   , KC_8   , KC_9   , KC_0   , JP_MINS, JP_CIRC, JP_YEN , KC_BSPC,
        TO(_HOM), KC_TAB , QK_BOOT, KC_W   , KC_E   , KC_R   , KC_T   ,___NG___,    KC_Y   , KC_U   , KC_I   , KC_O   , QK_BOOT, JP_AT  , JP_LBRC, KC_ENT ,
        TO(_1FN), KC_LCTL, KC_A   , KC_S   , KC_D   , KC_F   , KC_G   ,___NG___,    KC_H   , KC_J   , KC_K   , KC_L   , JP_SCLN, JP_COLN, JP_RBRC,___NG___,
        TO(_2VI),MO(_1FN), KC_LSFT, KC_Z   , KC_X   , KC_C   , KC_V   , KC_B   ,    KC_B   , KC_N   , KC_M   , JP_COMM, JP_DOT , JP_SLSH, JP_BSLS, KC_RSFT,
        TO(_3DE), KC_LCTL, KC_CAPS, KC_LWIN, KC_LALT, KC_RALT,TK_SPC_1,___NG___,   TK_SPC_1, KC_ESC , KC_RALT, KC_MENU, KC_RCTL, KC_WBAK, KC_WFWD, KC_PSCR
    )
};
