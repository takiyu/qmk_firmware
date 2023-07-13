#include QMK_KEYBOARD_H

#include "keymap_japanese.h"

enum custom_layer {
    _HOM,
    _1FN,
    _2MO,
    _3DE,
};

// TODO: Menu,Caps

#define ___NG___ XXXXXXX
#define TK_SPC1  LT(_1FN, KC_SPC)
#define TK_SPC2  LT(_2MO, KC_SPC)
#define TK_TAB3  LCTL(KC_TAB)
#define TK_TAB2  LSFT(LCTL(KC_TAB))
#define TK_PSCR  LALT(KC_PSCR)
#define TK_CUT   LCTL(KC_X)
#define TK_COPY  LCTL(KC_C)
#define TK_PAST  LCTL(KC_V)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    // Home Layer
    [_HOM] = LAYOUT_5x8(
        KC_ESC,   JP_ZKHK, KC_1   , KC_2   , KC_3   , KC_4   , KC_5   , KC_6   ,    KC_7   , KC_8   , KC_9   , KC_0   , JP_MINS, JP_CIRC, JP_YEN , KC_BSPC,
        TO(_HOM), KC_TAB , KC_Q   , KC_W   , KC_E   , KC_R   , KC_T   ,___NG___,    KC_Y   , KC_U   , KC_I   , KC_O   , KC_P   , JP_AT  , JP_LBRC, KC_ENT ,
        TO(_1FN), KC_LCTL, KC_A   , KC_S   , KC_D   , KC_F   , KC_G   ,___NG___,    KC_H   , KC_J   , KC_K   , KC_L   , JP_SCLN, JP_COLN, JP_RBRC,___NG___,
        TO(_2MO), KC_LSFT, KC_LSFT, KC_Z   , KC_X   , KC_C   , KC_V   , KC_B   ,    KC_B   , KC_N   , KC_M   , JP_COMM, JP_DOT , JP_SLSH, JP_BSLS, KC_RSFT,
        TO(_3DE), KC_LCTL, KC_CAPS, KC_LWIN, KC_LALT, KC_RALT, TK_SPC1,___NG___,    TK_SPC1, KC_ESC , KC_RALT, KC_MENU, KC_RCTL, KC_LEFT,KC_RIGHT, KC_PSCR
    ),

    // Function Layer
    [_1FN] = LAYOUT_5x8(
        KC_ESC,   _______, KC_F1  , KC_F2  , KC_F3  , KC_F4  , KC_F5  , KC_F6  ,    KC_F7  , KC_F8  , KC_F9  , KC_F10 , KC_F11 , KC_F12 , XXXXXXX, KC_DEL ,
        TO(_HOM), _______, DM_REC1, _______, _______, KC_F5,   _______,___NG___,    _______, _______, KC_INS , _______, _______, DM_PLY1, KC_PGUP, _______,
        TO(_1FN), _______, DM_RSTP, _______, _______, _______, _______,___NG___,    KC_LEFT, KC_DOWN, KC_UP  ,KC_RIGHT, _______, _______, KC_PGDN,___NG___,
        TO(_2MO), _______, _______, _______, KC_DEL , _______, _______, _______,    _______, _______, _______, _______, _______, _______, _______, _______,
        TO(_3DE), _______, _______, _______, _______, _______, TK_SPC2,___NG___,    TK_SPC2, _______, _______, _______, _______, KC_WBAK, KC_WFWD, TK_PSCR
    ),

    // Mouse Layer
    [_2MO] = LAYOUT_5x8(
        KC_ESC,   _______, _______, TK_TAB2, TK_TAB3, _______, _______, _______,    _______, _______, KC_HOME, KC_END , _______, _______, _______, _______,
        TO(_HOM), _______, _______, _______, _______, KC_WFWD, _______,___NG___,    TK_COPY, KC_WBAK, _______, _______, TK_PAST, _______, _______, _______,
        TO(_1FN), _______, _______, KC_BTN3, KC_BTN2, KC_BTN1, _______,___NG___,    KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, _______, _______, _______,___NG___,
        TO(_2MO), _______, _______, _______,  TK_CUT, _______, _______, _______,    _______, _______, _______, _______, _______, _______, _______, _______,
        TO(_3DE), _______, _______, _______, _______, _______, TK_SPC2,___NG___,    TK_SPC2, _______, _______, _______, _______, _______, _______, _______
    ),

    // Debug Layer
    [_3DE] = LAYOUT_5x8(
        KC_ESC,   _______, _______, _______, _______, _______, _______, _______,    _______, _______, _______, _______, _______, _______, _______, _______,
        TO(_HOM), _______, QK_BOOT, _______, _______, _______, _______,___NG___,    _______, _______, _______, _______, QK_BOOT, _______, _______, _______,
        TO(_1FN), _______, _______, _______, _______, _______, _______,___NG___,    _______, _______, _______, _______, _______, _______, _______,___NG___,
        TO(_2MO), KC_CAPS, _______, _______, _______, _______, _______, _______,    _______, _______, _______, _______, _______, _______, _______, _______,
        TO(_3DE), _______, _______, _______, _______, _______, TK_SPC2,___NG___,    TK_SPC2, _______, _______, _______, _______, _______, _______, _______
    )
};


// ------------------------------- Key overrides -------------------------------
// Mod + BS -> Delete keys
const key_override_t override_ctrl_bs = ko_make_basic(MOD_MASK_CTRL, KC_BSPC, KC_DEL);
const key_override_t override_shif_bs = ko_make_basic(MOD_MASK_SHIFT, KC_BSPC, KC_DEL);

// Mod + arrows -> Up/Down/Home/End  (Disabled)
// const key_override_t override_ctrl_h = ko_make_basic(MOD_MASK_CTRL, KC_LEFT, KC_HOME);
// const key_override_t override_ctrl_j = ko_make_basic(MOD_MASK_CTRL, KC_DOWN, KC_PGDN);
// const key_override_t override_ctrl_k = ko_make_basic(MOD_MASK_CTRL, KC_UP, KC_PGUP);
// const key_override_t override_ctrl_l = ko_make_basic(MOD_MASK_CTRL, KC_RIGHT, KC_END);
// const key_override_t override_shif_h = ko_make_basic(MOD_MASK_SHIFT, KC_LEFT, KC_HOME);
// const key_override_t override_shif_j = ko_make_basic(MOD_MASK_SHIFT, KC_DOWN, KC_PGDN);
// const key_override_t override_shif_k = ko_make_basic(MOD_MASK_SHIFT, KC_UP, KC_PGUP);
// const key_override_t override_shif_l = ko_make_basic(MOD_MASK_SHIFT, KC_RIGHT, KC_END);

// Shift + Space -> PageUp
const key_override_t override_shif_space = ko_make_basic(MOD_MASK_SHIFT, KC_SPC, KC_PGUP);

// Alt + Space/Esc for Windows
const key_override_t override_alt_space = ko_make_basic(MOD_MASK_ALT, KC_SPC, KC_LWIN);
const key_override_t override_alt_esc = ko_make_basic(MOD_MASK_ALT, KC_ESC, LALT(KC_TAB));

const key_override_t **key_overrides = (const key_override_t *[]){
    &override_ctrl_bs, &override_shif_bs,
    // &override_ctrl_h, &override_ctrl_l, &override_ctrl_j, &override_ctrl_k,
    // &override_shif_h, &override_shif_l, &override_shif_j, &override_shif_k,
    &override_shif_space,
    &override_alt_space, &override_alt_esc,
    NULL // End of array
};
