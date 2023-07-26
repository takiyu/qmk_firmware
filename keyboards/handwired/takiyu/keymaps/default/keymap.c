#include QMK_KEYBOARD_H

#include "keymap_japanese.h"
#include "os_detection.h"

enum custom_layer {
    _HOM = 0,
    _1FN = 1,
    _2MO = 2,
    _3DE = 3,
};

#define ___NG___ XXXXXXX
#define VOL_UP KC_VOLU
#define VOL_DN KC_VOLD

#define TK_SPC1  LT(_1FN, KC_SPC)
#define TK_SPC2  LT(_2MO, KC_SPC)
#define TK_TAB3  LCTL(KC_TAB)
#define TK_TAB2  LSFT(LCTL(KC_TAB))
#define TK_PSCR  LALT(KC_PSCR)
#define TK_CUT   LCTL(KC_X)
#define TK_COPY  LCTL(KC_C)
#define TK_PAST  LCTL(KC_V)
#define TK_ALL   LCTL(KC_A)
#define TK_ALTF4 LALT(KC_F4)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    // Home Layer
    [_HOM] = LAYOUT_5x8(
        KC_ESC,   JP_ZKHK, KC_1   , KC_2   , KC_3   , KC_4   , KC_5   , KC_6   ,    KC_7   , KC_8   , KC_9   , KC_0   , JP_MINS, JP_CIRC, JP_YEN , KC_BSPC,
        TO(_HOM), KC_TAB , KC_Q   , KC_W   , KC_E   , KC_R   , KC_T   ,___NG___,    KC_Y   , KC_U   , KC_I   , KC_O   , KC_P   , JP_AT  , JP_LBRC, KC_ENT ,
        TO(_1FN), KC_LCTL, KC_A   , KC_S   , KC_D   , KC_F   , KC_G   ,___NG___,    KC_H   , KC_J   , KC_K   , KC_L   , JP_SCLN, JP_COLN, JP_RBRC,___NG___,
        TO(_2MO), KC_LSFT, KC_LSFT, KC_Z   , KC_X   , KC_C   , KC_V   , KC_B   ,    KC_B   , KC_N   , KC_M   , JP_COMM, JP_DOT , JP_SLSH, JP_BSLS, KC_RSFT,
        TO(_3DE), KC_LCTL, KC_CAPS, KC_LWIN, KC_LALT, KC_RALT, TK_SPC1,___NG___,    TK_SPC2, KC_ESC , KC_RALT, KC_APP , KC_RCTL, KC_LEFT,KC_RIGHT, KC_PSCR
    ),

    // Function Layer
    [_1FN] = LAYOUT_5x8(
        KC_ESC,   _______, KC_F1  , KC_F2  , KC_F3  , KC_F4  , KC_F5  , KC_F6  ,    KC_F7  , KC_F8  , KC_F9  , KC_F10 , KC_F11 , KC_F12 , XXXXXXX, KC_DEL ,
        TO(_HOM), _______, _______, _______, _______, KC_LWIN, _______,___NG___,    TK_COPY, _______, _______, _______, TK_PAST, _______, KC_PGUP, _______,
        TO(_1FN), _______, TK_ALL , _______, _______, _______, _______,___NG___,    KC_LEFT, KC_DOWN, KC_UP  ,KC_RIGHT, _______, _______, KC_PGDN,___NG___,
        TO(_2MO), _______, _______, _______, KC_DEL ,TK_ALTF4, _______, _______,    _______, _______, _______, _______, _______, _______, _______, _______,
        TO(_3DE), _______, KC_SCRL, _______, _______, _______, TK_SPC1,___NG___,   DF(_1FN),DF(_HOM), _______, _______, _______,  VOL_DN,  VOL_UP, TK_PSCR
    ),

    // Mouse Layer
    [_2MO] = LAYOUT_5x8(
        KC_ESC,   _______, KC_F1  , TK_TAB2, TK_TAB3, KC_F4  , KC_F5  , KC_F6  ,    KC_F7  , KC_F8  , KC_HOME, KC_END ,  KC_F11,  KC_F12, XXXXXXX, KC_DEL ,
        TO(_HOM), _______, DM_REC1, _______, _______, KC_WFWD, _______,___NG___,    TK_COPY, KC_WBAK, _______, _______, TK_PAST, DM_PLY1, KC_WH_U, _______,
        TO(_1FN), _______, DM_RSTP, KC_BTN2, KC_BTN3, KC_BTN1, _______,___NG___,    KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, _______, _______, KC_WH_D,___NG___,
        TO(_2MO), _______, _______, _______, KC_DEL , _______, _______, _______,    _______, _______, _______, _______, _______, _______, _______, _______,
        TO(_3DE), _______, KC_SCRL, _______, _______, _______,DF(_2MO),___NG___,    TK_SPC2,DF(_HOM), _______, _______, _______,  VOL_DN,  VOL_UP, TK_PSCR
    ),

    // Debug Layer
    [_3DE] = LAYOUT_5x8(
        KC_ESC,   _______, _______, _______, _______, _______, _______, _______,    _______, _______, _______, _______, _______, _______, _______, _______,
        TO(_HOM), _______, QK_BOOT, _______, _______, _______, _______,___NG___,    _______, _______,  KC_INS, _______, QK_BOOT, _______, _______, _______,
        TO(_1FN), KC_CAPS, _______, _______, _______, _______, _______,___NG___,    _______, _______, _______, _______, _______, _______, _______,___NG___,
        TO(_2MO), _______, _______, _______, _______, _______, _______, _______,    _______, _______, _______, _______, _______, _______, _______, _______,
        TO(_3DE), _______, KC_SCRL, _______, _______, _______, TK_SPC1,___NG___,    TK_SPC2,DF(_HOM), _______, _______, _______, _______, _______, _______
    )
};


// ------------------------------- Key overrides -------------------------------
// Shift + Space -> PageUp (TODO)
const key_override_t override_shif_space = ko_make_basic(MOD_MASK_SHIFT, KC_SPC, KC_PGUP);

// Alt + 1/2/.../6 -> Shift + 1/2/.../6
const key_override_t override_alt_1 = ko_make_basic(MOD_MASK_ALT, KC_1, JP_EXLM);
const key_override_t override_alt_2 = ko_make_basic(MOD_MASK_ALT, KC_2, JP_DQUO);
const key_override_t override_alt_3 = ko_make_basic(MOD_MASK_ALT, KC_3, JP_HASH);
const key_override_t override_alt_4 = ko_make_basic(MOD_MASK_ALT, KC_4, JP_DLR);
const key_override_t override_alt_5 = ko_make_basic(MOD_MASK_ALT, KC_5, JP_PERC);
const key_override_t override_alt_6 = ko_make_basic(MOD_MASK_ALT, KC_6, JP_AMPR);
const key_override_t override_alt_bs = ko_make_basic(MOD_MASK_ALT, KC_BSPC, KC_DEL);

// Register overrides
const key_override_t **key_overrides = (const key_override_t *[]){
    &override_shif_space,
    &override_alt_1, &override_alt_2, &override_alt_3, &override_alt_4,
    &override_alt_5, &override_alt_6,
    &override_alt_bs,
    NULL // End of array
};

// --------------------------------- User Hook ---------------------------------
bool g_takiyu_is_alt_tab = false;
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    const os_variant_t os_type = detected_host_os();
    const bool is_win = (os_type == OS_WINDOWS || os_type == OS_UNSURE);
    const bool is_pressed = record->event.pressed;

    if (is_win) {
        // 1FN/RALT + Tab/S: Start
        const bool is_r_alt = (get_mods() & MOD_BIT(KC_RALT));
        const bool is_fn_on = IS_LAYER_ON(_1FN);
        if ((is_fn_on || is_r_alt) &&
            (keycode == KC_TAB || keycode == KC_S) && is_pressed) {
            g_takiyu_is_alt_tab = true;
            register_code(KC_RALT);  // Alt: Push
            tap_code(KC_TAB);        // Alt+Tab
            tap_code(KC_LEFT);       // Left
            layer_on(_1FN);          // 1FN: ON
            return false;  // Skip all further processing of this key
        }
        // 1FN/RALT + Tab/S: End
        if (g_takiyu_is_alt_tab) {
            if (!(keycode == KC_TAB || keycode == KC_S ||
                  keycode == KC_UP || keycode == KC_DOWN ||
                  keycode == KC_LEFT || keycode == KC_RIGHT)) {
                g_takiyu_is_alt_tab = false;
                unregister_code(KC_RALT);  // Alt: Release
                layer_clear();             // Clear status
                clear_keyboard();
                if (keycode == KC_LWIN) {
                    tap_code(KC_LWIN);  // Win
                }
                return false;  // Skip all further processing of this key
            }
        }
    }

    return true;
}
