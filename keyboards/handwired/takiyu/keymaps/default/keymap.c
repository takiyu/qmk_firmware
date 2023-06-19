#include QMK_KEYBOARD_H

#include "keymap_japanese.h"

enum custom_layer {
    _HOM,
    _FUN,
    _1LA,
    _2LA,
    _3LA,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_HOM] = LAYOUT_5x8(
        TO(_HOM), JP_ZKHK , KC_1    , KC_2   , KC_3   , KC_4   , KC_5   , KC_6   ,        KC_7  , KC_8   , KC_9   , KC_0  , JP_MINS, JP_CIRC, JP_YEN , KC_BSPC,
        TO(_FUN), KC_TAB  , KC_Q    , KC_W   , KC_E   , KC_R   , KC_T   , _______,        KC_Y  , KC_U   , KC_I   , KC_O  , KC_P   , JP_AT  , JP_LBRC, KC_ENT ,
        TO(_1LA), KC_LCTL , KC_A    , KC_S   , KC_D   , KC_F   , KC_G   , _______,        KC_H  , KC_J   , KC_K   , KC_L  , JP_SCLN, JP_COLN, JP_RBRC, _______,
        TO(_2LA), MO(_FUN), KC_LSFT , KC_Z   , KC_X   , KC_C   , KC_V   , KC_B   ,        KC_B  , KC_N   , KC_M   ,JP_COMM, JP_DOT , JP_SLSH, JP_BSLS, KC_LSFT,
        TO(_3LA), KC_LCTL , KC_CAPS , KC_LWIN, KC_LALT, KC_F13 , KC_SPC , _______,        KC_SPC, KC_ESC , KC_F13, KC_MENU, KC_RCTL, KC_WBAK, KC_WFWD, KC_PSCR
    ),

    [_FUN] = LAYOUT_5x8(
        TO(_HOM), KC_ESC , KC_F1   , KC_F2  , KC_F3 , KC_F4 , KC_F5 , KC_F6 ,        KC_F7 , KC_F8  , KC_F9  , KC_F10, KC_F11, KC_F12   , _______, KC_ESC ,
        TO(_FUN), _______, KC_GRV  , KC_1   , KC_2  , KC_3  , KC_4  , KC_5  ,        KC_6  , KC_7   , KC_8   , KC_9  , KC_0  , KC_LBRC  , KC_RBRC, _______,
        TO(_1LA), _______, KC_TAB  , KC_Q   , KC_W  , KC_E  , KC_R  , KC_T  ,        KC_Y  , KC_U   , KC_I   , KC_O  , KC_P  , KC_QUOT  , KC_BSLS, _______,
        TO(_2LA), _______, KC_LSFT , KC_A   , KC_S  , KC_D  , KC_F  , KC_G  ,        KC_H  , KC_J   , KC_K   , KC_L  ,KC_SCLN, KC_LSFT  , _______, _______,
        TO(_3LA), _______, KC_LCTL , KC_Z   , KC_X  , KC_C  , KC_V  , KC_B  ,        KC_N  , KC_M   , KC_COMM, KC_DOT,KC_SLSH, KC_LCTL  , _______, _______
    ),

    [_1LA] = LAYOUT_5x8(
        KC_ESC , KC_ESC , KC_F1   , KC_F2  , KC_F3 , KC_F4 , KC_F5 , KC_F6 ,        KC_F7 , KC_F8  , KC_F9  , KC_F10, KC_F11, KC_F12   , _______, KC_ESC ,
        _______, _______, KC_GRV  , KC_1   , KC_2  , KC_3  , KC_4  , KC_5  ,        KC_6  , KC_7   , KC_8   , KC_9  , KC_0  , KC_LBRC  , KC_RBRC, _______,
        _______, _______, KC_TAB  , KC_Q   , KC_W  , KC_E  , KC_R  , KC_T  ,        KC_Y  , KC_U   , KC_I   , KC_O  , KC_P  , KC_QUOT  , KC_BSLS, _______,
        _______, _______, KC_LSFT , KC_A   , KC_S  , KC_D  , KC_F  , KC_G  ,        KC_H  , KC_J   , KC_K   , KC_L  ,KC_SCLN, KC_LSFT  , _______, _______,
        _______, _______, KC_LCTL , KC_Z   , KC_X  , KC_C  , KC_V  , KC_B  ,        KC_N  , KC_M   , KC_COMM, KC_DOT,KC_SLSH, KC_LCTL  , _______, _______
    ),

    [_2LA] = LAYOUT_5x8(
        KC_ESC , KC_ESC , KC_F1   , KC_F2  , KC_F3 , KC_F4 , KC_F5 , KC_F6 ,        KC_F7 , KC_F8  , KC_F9  , KC_F10, KC_F11, KC_F12   , _______, KC_ESC ,
        _______, _______, KC_GRV  , KC_1   , KC_2  , KC_3  , KC_4  , KC_5  ,        KC_6  , KC_7   , KC_8   , KC_9  , KC_0  , KC_LBRC  , KC_RBRC, _______,
        _______, _______, KC_TAB  , KC_Q   , KC_W  , KC_E  , KC_R  , KC_T  ,        KC_Y  , KC_U   , KC_I   , KC_O  , KC_P  , KC_QUOT  , KC_BSLS, _______,
        _______, _______, KC_LSFT , KC_A   , KC_S  , KC_D  , KC_F  , KC_G  ,        KC_H  , KC_J   , KC_K   , KC_L  ,KC_SCLN, KC_LSFT  , _______, _______,
        _______, _______, KC_LCTL , KC_Z   , KC_X  , KC_C  , KC_V  , KC_B  ,        KC_N  , KC_M   , KC_COMM, KC_DOT,KC_SLSH, KC_LCTL  , _______, _______
    ),

    [_3LA] = LAYOUT_5x8(
        KC_ESC , KC_ESC , KC_F1   , KC_F2  , KC_F3 , KC_F4 , KC_F5 , KC_F6 ,        KC_F7 , KC_F8  , KC_F9  , KC_F10, KC_F11, KC_F12   , _______, KC_ESC ,
        _______, _______, KC_GRV  , KC_1   , KC_2  , KC_3  , KC_4  , KC_5  ,        KC_6  , KC_7   , KC_8   , KC_9  , KC_0  , KC_LBRC  , KC_RBRC, _______,
        _______, _______, KC_TAB  , KC_Q   , KC_W  , KC_E  , KC_R  , KC_T  ,        KC_Y  , KC_U   , KC_I   , KC_O  , KC_P  , KC_QUOT  , KC_BSLS, _______,
        _______, _______, KC_LSFT , KC_A   , KC_S  , KC_D  , KC_F  , KC_G  ,        KC_H  , KC_J   , KC_K   , KC_L  ,KC_SCLN, KC_LSFT  , _______, _______,
        _______, _______, KC_LCTL , KC_Z   , KC_X  , KC_C  , KC_V  , KC_B  ,        KC_N  , KC_M   , KC_COMM, KC_DOT,KC_SLSH, KC_LCTL  , _______, _______
    )
};
