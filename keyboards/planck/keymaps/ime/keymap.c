#include "planck.h"

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
enum {
    QWERTY = 0,
    NUM = 1
    SYM = 2
    NAV = 3
};


/* MIT Layout (Blank)
 *
 * ,-----------------------------------------------------------------------.
 * |     |     |     |     |     |     |     |     |     |     |     |     |
 * |-----------------------------------------------------------------------|
 * |     |     |     |     |     |     |     |     |     |     |     |     |
 * |-----------------------------------------------------------------------|
 * |     |     |     |     |     |     |     |     |     |     |     |     |
 * |-----------------------------------------------------------------------|
 * |     |     |     |     |     |     |     |     |     |     |     |     |
 * `-----------------------------------------------------------------------'
 */
[BLANK] = {
  {KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO},
  {KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO},
  {KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO},
  {KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO}
},

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* MIT Layout (QWERTY layer)
 *
 * ,-----------------------------------------------------------------------.
 * |  `  |  q  |  w  |  e  |  r  |  t  |  y  |  u  |  i  |  o  |  p  | bksp|
 * |-----------------------------------------------------------------------|
 * |tbSYM|  a  |  s  |  d  |  f  |  g  |  h  |  j  |  k  |  l  |  ;  |  '  |
 * |-----------------------------------------------------------------------|
 * | shft|  z  |  x  |  c  |  v  |  b  |  n  |  m  |  ,  |  .  |  /  |shft |
 * |-----------------------------------------------------------------------|
 * | NUM |     | NAV |     | bksp| mta | ctl | spc | ent | NAV | SYM |     |
 * `-----------------------------------------------------------------------'
 */
[QWERTY] = {
  {KC_TILD,           KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC},
  {LT(SYMS, KC_TAB),  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT},
  {KC_LSFT,           KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT},
  {KC_NO,             KC_NO,   KC_LCTL, KC_LALT, KC_BSPC, KC_DEL,  KC_ENT,  KC_SPC,  KC_RALT, KC_RCTL, KC_NO,   KC_NO}
},
/* MIT Layout (Numpad)
 *
 * ,-----------------------------------------------------------------------.
 * |  1  |  2  |  3  |  4  |  5  |  6  |  7  |  8  |  9  |  0  |     |     |
 * |-----------------------------------------------------------------------|
 * |     |     |     |     |     |     |  4  |  5  |  6  |     |     |     |
 * |-----------------------------------------------------------------------|
 * |     |     |     |     |     |     |  1  |  2  |  3  |     |     |     |
 * |-----------------------------------------------------------------------|
 * |     |     |     |     |     |     |  0  |  0  |  .  | entr|     |     |
 * `-----------------------------------------------------------------------'
 */
[NUM] = {
  {KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_7,  KC_8,  KC_9,   KC_NO,  KC_NO, KC_NO},
  {KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_4,  KC_5,  KC_6,   KC_NO,  KC_NO, KC_NO},
  {KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_1,  KC_2,  KC_3,   KC_NO,  KC_NO, KC_NO},
  {KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_0,  KC_0,  KC_DOT, KC_ENT, KC_NO, KC_NO}
},
/* MIT Layout (Symbols)
 *
 * ,-----------------------------------------------------------------------.
 * |  ~  |  !  |  @  |  #  |  $  |  %  |  ^  |  &  |  *  |  (  |  )  |     |
 * |-----------------------------------------------------------------------|
 * |     | F1  | F2  | F3  | F4  | F5  | F6  |  _  |  =  |  {  |  }  |  \  |
 * |-----------------------------------------------------------------------|
 * |     | F7  | F8  | F9  | F10 | F11 | F12 |     |     |     |     |     |
 * |-----------------------------------------------------------------------|
 * |     |     |     |     |     |           |     |     |     |     |     |
 * `-----------------------------------------------------------------------'
 */
[SYM] = {
  {KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_BSPC},
  {KC_TRNS, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_UNDS, KC_EQL,  KC_LCBR, KC_RCBR, KC_BSLS},
  {KC_TRNS, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS},
  {KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS}
},
/* MIT Layout (Navigation)
 *
 * ,-----------------------------------------------------------------------.
 * |     |     |     |     |     |     |     |     |     |     |     | del |
 * |-----------------------------------------------------------------------|
 * |     |     |     |     |     |     |     |     |     |     |     |     |
 * |-----------------------------------------------------------------------|
 * |     |     |     |     |     |     |     |     |     |     |     |     |
 * |-----------------------------------------------------------------------|
 * |     |     |     |     |     |           |     |home |pgdn |pgup | end |
 * `-----------------------------------------------------------------------'
 */
[NAV] = {
  {KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_DELT},
  {KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS},
  {KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS},
  {KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_HOME, KC_PGDN, KC_PGUP, KC_END}
}
};

const uint16_t PROGMEM fn_actions[] = {

};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
  // MACRODOWN only works in this function
      switch(id) {
        case 0:
          if (record->event.pressed) {
            register_code(KC_RSFT);
            backlight_step();
          } else {
            unregister_code(KC_RSFT);
          }
        break;
      }
    return MACRO_NONE;
};
