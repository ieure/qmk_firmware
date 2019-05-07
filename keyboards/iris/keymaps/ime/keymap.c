#include QMK_KEYBOARD_H

extern keymap_config_t keymap_config;

#define _QWERTY 0
#define _SYMS 1

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  SYMS
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Blank template
 *
 * ,-----------------------------------------.                   ,-----------------------------------------.
 * |      |      |      |      |      |      |                   |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                   |------+------+------+------+------+------|
 * |      |      |      |      |      |      |                   |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                   |------+------+------+------+------+------|
 * |      |      |      |      |      |      |                   |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                   |------+------+------+------+------+------|
 * |      |      |      |      |      |      | ,------. ,------. |      |      |      |      |      |      |
 * `-----------------------------------------' |      | |      | `-----------------------------------------'
 *                          ,-------------.    |------| |------|    ,-------------.
 *                          |      |      |    |      | |      |    |      |      |
 *                          `-------------'    `------' `------'    `-------------'
 */

/*
 * Layer 0: QWERTY
 *
 * ,-----------------------------------------.                   ,-----------------------------------------.
 * |   `  |      |      | LGUI | LALT | LCTRL|                   | RCTRL| RALT | RGUI |      |   -  |   =  |
 * |------+------+------+------+------+------|                   |------+------+------+------+------+------|
 * |  TAB |   Q  |   W  |   E  |   R  |  T   |                   |   Y  |   U  |   I  |   O  |   P  |      |
 * |------+------+------+------+------+------|                   |------+------+------+------+------+------|
 * |      |   A  |   S  |   D  |   F  |  G   |                   |   H  |   J  |   K  |   L  |   ;  |  '   |
 * |------+------+------+------+------+------|                   |------+------+------+------+------+------|
 * | SHIFT|   Z  |   X  |   C  |   V  |  B   | ,------. ,------. |   N  |   M  |   ,  |   .  |   /  |SHIFT |
 * `-----------------------------------------' |      | | ESC  | `-----------------------------------------'
 *                          ,-------------.    |------| |------|    ,-------------.
 *                          | Lyr1 | BkSp |    |  Del | |Enter |    | Space| Lyr1 |
 *                          `-------------'    `------' `------'    `-------------'
 */
  [_QWERTY] = LAYOUT(
     KC_GRV,  KC_NO,   KC_NO,   KC_LGUI, KC_LALT, KC_LCTL,                            KC_RCTL, KC_RALT, KC_RGUI, KC_NO,   KC_MINS, KC_EQL,
     KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                               KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_NO,
     KC_NO,   KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                               KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
     KC_LALT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_NO,             KC_ESC, KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RALT,
//   KC_LSFT, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_LALT, KC_NO,             KC_ESC, KC_LALT, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_RSFT,
                                 MO(_SYMS), KC_BSPC,   KC_DEL,                    KC_ENT,  KC_SPC,   MO(_SYMS)
                     ),


/*  Layer 1: Symbols & Numpad
 *
 * ,-----------------------------------------.                   ,-----------------------------------------.
 * |   `  |   (  |   !  |   $  |  *   |   \  |                   |   7  |   8  |   9  |   -  |   =  |      |
 * |------+------+------+------+------+------|                   |------+------+------+------+------+------|
 * |   '  |   [  |   @  |   %  |  &   |      |                   |   4  |   5  |   6  |   [  |   ]  |   \  |
 * |------+------+------+------+------+------|                   |------+------+------+------+------+------|
 * |   "  |   {  |   #  |   -  |   +  |      |                   |   1  |   2  |   3  |   '  |   "  |      |
 * |------+------+------+------+------+------|                   |------+------+------+------+------+------|
 * | SHIFT|   <  |   ^  |      |      |      | ,------. ,------. |   .  |   0  |      |      |      |SHIFT |
 * `-----------------------------------------' |      | |      | `-----------------------------------------'
 *                          ,-------------.    |------| |------|    ,-------------.
 *                          |      |      |    |      | |      |    |      |      |
 *                          `-------------'    `------' `------'    `-------------'
 */
 [_SYMS] = LAYOUT(
    KC_GRV,     S(KC_9),        S(KC_1), S(KC_4), S(KC_8),    KC_BSLASH,                          KC_7,    KC_8,    KC_9,    KC_MINS,     KC_EQL,      KC_NO,
    KC_QUOT,    KC_LBRACKET,    S(KC_2), S(KC_5), S(KC_7),    KC_NO,                              KC_4,    KC_5,    KC_6,    KC_LBRACKET, KC_RBRACKET, KC_BSLASH,
    S(KC_QUOT), S(KC_LBRACKET), S(KC_3), KC_MINS, S(KC_MINS), KC_NO,                              KC_1,    KC_2,    KC_3,    KC_QUOT,     S(KC_QUOT),  KC_NO,
    KC_LSFT,    S(KC_COMM),     S(KC_6), KC_NO,   KC_NO,      KC_NO,  KC_NO,              KC_NO,  KC_DOT,  KC_0,    KC_NO,   KC_NO,       KC_NO,       KC_RSFT,
                                      KC_NO,  KC_NO, KC_NO,                       KC_ENT,  KC_SPC,   KC_NO
 )
};