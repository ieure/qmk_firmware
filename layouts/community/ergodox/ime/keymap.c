#include QMK_KEYBOARD_H
#include "debug.h"
#include "action_layer.h"
#include "version.h"

enum {
    BASE = 0,                   // Default layer
    NUMPAD = 1,                 // Numpad etc
    SYMS = 2                    // Symbols
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/*
 * Layer 0: QWERTY
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |   `    |   1  |   2  |   3  |   4  |   5  |  ||> |           |  ESC |   6  |   7  |   8  |   9  |   0  |   -    |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |  Tab   |   Q  |   W  |   E  |   R  |   T  | LCTL |           | RCTL |   Y  |   U  |   I  |   O  |   P  |   "    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |\, syms |   A  |   S  |   D  |   F  |   G  |------|           |------|   H  |   J  |   K  |   L  |   ;  | ',syms |
 * |--------+------+------+------+------+------| LALT |           | RALT |------+------+------+------+------+--------|
 * | LShift |   Z  |   X  |   C  |   V  |   B  |      |           |      |   N  |   M  |   ,  |   .  |  /   | RShift |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   | Lyr1 |      |      | SysRq| LGUI |                                       | Left | Down |  Up  | Rght | Lyr1 |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |  =   |      |       |   [  |   ]  |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |  Vol-|       | Vol+ |      |      |
 *                                 | BkSp |  Del |------|       |------| Enter| Space|
 *                                 |      |      | LHYP |       | RHYP |      |      |
 *                                 `--------------------'       `--------------------'
 */
[BASE] = KEYMAP(
           // left hand
           KC_GRV,                  KC_1,     KC_2,    KC_3,    KC_4,   KC_5, KC_MPLY,
           KC_TAB,                  KC_Q,     KC_W,    KC_E,    KC_R,   KC_T, KC_LCTL,
           LT(SYMS, KC_BSLASH),     KC_A,     KC_S,    KC_D,    KC_F,   KC_G,
           OSM(MOD_LSFT),           KC_Z,     KC_X,    KC_C,    KC_V,   KC_B, KC_LALT,
           MO(NUMPAD),              KC_TRNS,  KC_TRNS, KC_SYSREQ, KC_LGUI,

           KC_EQL, KC_TRNS,
           KC_VOLD,
           KC_BSPC, KC_DEL, KC_WWW_BACK,

           // right hand
           KC_ESC,    KC_6,    KC_7,    KC_8,     KC_9,   KC_0,     KC_MINS,
           KC_RCTRL,  KC_Y,    KC_U,    KC_I,     KC_O,   KC_P,     S(KC_QUOT),
                      KC_H,    KC_J,    KC_K,     KC_L,   KC_SCLN,  LT(SYMS, KC_QUOT),
           KC_RALT,   KC_N,    KC_M,    KC_COMM,  KC_DOT, KC_SLSH,  OSM(MOD_RSFT),
                               KC_LEFT, KC_DOWN,  KC_UP,  KC_RIGHT, MO(NUMPAD),

           KC_LBRACKET, KC_RBRACKET,
           KC_VOLU,
           KC_WWW_FORWARD,     KC_ENT,      KC_SPC
                ),


/*
 * Keymap: Layer 1 -- numpad / paging
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |  F1  |  F2  |  F3  |  F4  |  F5  |      |           |      |  F6  | F7   |  F8  |  F9  | F10  |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |   7  |   8  |   9  |   +  |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |------|           |------|   4  |   5  |   6  |   -  |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |   0  |   1  |   2  |   3  |   *  |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       | Home | PgDn | PgUp | End  |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      | BL-  |       |  BL+ |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |  <<  |       |  >>  |      |      |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 *
 */
[NUMPAD] = KEYMAP(
           // left hand
           KC_TRNS, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_TRNS,
           KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
           KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
           KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
           KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,

           BL_DEC, KC_TRNS,
           KC_MPRV,
           KC_TRNS, KC_TRNS, KC_TRNS,

           // right hand
           KC_TRNS, KC_F6,   KC_F7,   KC_F8,     KC_F9,          KC_F10,  KC_TRNS,
           KC_TRNS, KC_7,    KC_8,    KC_9,      KC_KP_PLUS,     KC_TRNS, KC_TRNS,
                    KC_4,    KC_5,    KC_6,      KC_KP_MINUS,    KC_TRNS, KC_TRNS,
           KC_0,    KC_1,    KC_2,    KC_3,      KC_KP_ASTERISK, KC_TRNS, KC_TRNS,
                             KC_HOME, KC_PGDN,   KC_PGUP,        KC_END,  KC_TRNS,

           BL_INC, KC_TRNS,
           KC_MNXT,
           KC_TRNS, KC_TRNS, KC_TRNS
                  ),


/*
 * Keymap: Layer 2 -- Symbols
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |      | M-"  | M-'  |      |      |           |   *  |   !  |   @  |   #  |   $  |  %   |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        | M-[  | M-(  |      |      |      |------|           |------|   [  |   (  |   {  |   <  |  ^   |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |   _  |   ]  |   )  |   }  |   >  |  &   |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |      |      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 *
 */

[SYMS] = KEYMAP(
           // left hand
           KC_TRNS, KC_TRNS,           KC_TRNS,    KC_TRNS,       KC_TRNS,       KC_TRNS, KC_TRNS,
           KC_TRNS, KC_TRNS,           KC_TRNS,    SCMD(KC_QUOT), LGUI(KC_QUOT), KC_TRNS, KC_TRNS,
           KC_TRNS, LGUI(KC_LBRACKET), SCMD(KC_9), KC_TRNS,       KC_TRNS,       KC_TRNS,
           KC_TRNS, KC_TRNS,           KC_TRNS,    KC_TRNS,       KC_TRNS,       KC_TRNS, KC_TRNS,
           KC_TRNS, KC_TRNS,           KC_TRNS,    KC_TRNS,       KC_TRNS,

           KC_TRNS, KC_TRNS,
           KC_TRNS,
           KC_TRNS, KC_TRNS, KC_TRNS,

           // right hand
           KC_TRNS,       KC_TRNS,     KC_TRNS,    KC_TRNS,           KC_TRNS,        KC_TRNS,    KC_TRNS,
           LSFT(KC_8),    LSFT(KC_1),  LSFT(KC_2), LSFT(KC_3),        LSFT(KC_4),     LSFT(KC_5), KC_TRNS,
                          KC_LBRACKET, LSFT(KC_9), LSFT(KC_LBRACKET), LSFT(KC_COMMA), LSFT(KC_6), KC_TRNS,
           LSFT(KC_MINS), KC_RBRACKET, LSFT(KC_0), LSFT(KC_RBRACKET), LSFT(KC_DOT),   LSFT(KC_7), KC_TRNS,
                          KC_TRNS,     KC_TRNS,    KC_TRNS,           KC_TRNS,        KC_TRNS,

           KC_TRNS, KC_TRNS,
           KC_TRNS,
           KC_TRNS, KC_TRNS, KC_TRNS
                )
};
