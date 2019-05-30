/* Copyright 2019 kimat
*
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include QMK_KEYBOARD_H
#include "keymap_belgian.h"
#include <sendstring_belgian.h>

#define _BA 0
#define _SP 1
#define _AG 2

#define THUMB_F LT(_SP,KC_SPC)
#define THUMB_K LT(_AG,KC_TAB)

#define THUMB_H LSFT_T(KC_BSPC)
#define THUMB_G LSFT_T(KC_ESC)
#define _LSFT LSFT_T(KC_F12)
#define THUMB_J RCTL_T(KC_ENT)
#define _CAPS LCTL_T(KC_ESC)

enum custom_keycodes {
  QMKBEST = SAFE_RANGE,
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[_BA] = LAYOUT ( \
        KC_ESC     , BE_AMP  , BE_EXLM , BE_QUOT , BE_APOS , BE_LPRN , BE_RPRN , BE_LSBR , BE_RSBR , BE_RCBR  , KC_0    , BE_MINS    , \
        KC_TAB     , BE_A    , BE_Z    , KC_E    , KC_R    , KC_T    , KC_Y    , KC_U    , KC_I    , KC_O     , KC_P    , KC_LBRC    , \
        _CAPS      , BE_Q    , KC_S    , KC_D    , KC_F    , KC_G    , KC_H    , KC_J    , KC_K    , KC_L     , BE_M    , KC_ENT     , \
        _LSFT      , BE_W    , KC_X    , KC_C    , KC_V    , KC_B    , KC_N    , BE_COMM , BE_DOT  , KC_DOT   , KC_SLSH , KC_RSFT    , \
        KC_LCTL    , KC_LGUI , KC_LGUI , KC_LALT , THUMB_F , THUMB_G , THUMB_H , THUMB_J , THUMB_K , KC_K     , KC_L    , KC_CAPS  \
       )           ,
  // space
[_SP] = LAYOUT ( \
        _______    , _______ , _______ , _______ , _______ , _______ , _______ , _______ , BE_LCBR , BE_RCBR  , _______ , _______    ,
        KC_TAB     , KC_1    , KC_2    , KC_3    , KC_4    , KC_5    , KC_6    , KC_HOME , BE_LCBR , BE_RCBR  , KC_DEL  , KC_PGUP    , \
        _CAPS      , BE_PIPE , BE_MINS , KC_TAB  , BE_SLSH , BE_PND  , KC_LEFT , KC_DOWN , KC_UP   , KC_RIGHT , KC_END  , KC_PGDN    , \
        _______    , BE_LESS , BE_GRTR , KC_C    , KC_V    , KC_B    , KC_BSPC , KC_M    , KC_COMM , KC_DOT   , KC_SLSH , KC_RSFT    , \
        KC_LCTL    , KC_LGUI , _______ , KC_LALT , _______ , _______ , THUMB_H , THUMB_J , _______ , KC_K     , KC_L    , KC_CAPS  \
        )          ,
// altgr
[_AG] = LAYOUT ( \
        KC_ESC     , BE_PIPE , BE_AT   , BE_HASH , KC_4    , KC_5    , KC_6    , S(KC_7) , S(KC_8) , S(KC_9)  , KC_KP_0 , KC_A       , \
        KC_TAB     , BE_PIPE , BE_AT   , BE_HASH , KC_R    , KC_T    , KC_Y    , S(KC_7) , S(KC_8) , S(KC_9)  , KC_P    , KC_PGUP    , \
        _CAPS      , BE_PIPE , BE_UNDS , KC_D    , KC_SLSH , KC_G    , KC_BSPC , S(KC_4) , S(KC_5) , S(KC_6)  , KC_SCLN , BE_GRV     , \
        _LSFT      , BE_BSLS , KC_X    , KC_C    , KC_V    , KC_B    , S(KC_0) , S(KC_1) , S(KC_2) , S(KC_3)  , QMKBEST , KC_RSFT    , \
        KC_LCTL    , KC_LGUI , _______ , KC_LALT , _______ , _______ , THUMB_H , THUMB_J , _______ , KC_K     , KC_L    , KC_CAPS  \
        )          ,
  /* [0] = tkl */
  /*   KC_ESC      , KC_F1   , KC_F2   , KC_F3   , KC_F4   , KC_F5   , KC_F6   , KC_F7   , KC_F8   , KC_F9    , KC_F10  , KC_F11     , KC_F12  , KC_PSCR , KC_SLCK , KC_PAUS , */
  /*   KC_GRV      , KC_1    , KC_2    , KC_3    , KC_4    , KC_5    , KC_6    , KC_7    , KC_8    , KC_9     , KC_0    , KC_MINS    , KC_EQL  , KC_BSPC , KC_INS  , KC_HOME , KC_PGUP , */
  /*   KC_TAB      , KC_Q    , KC_W    , KC_E    , KC_R    , KC_T    , KC_Y    , KC_U    , KC_I    , KC_O     , KC_P    , KC_LBRC    , KC_RBRC , KC_DEL  , KC_END  , KC_PGDN , */
  /*   KC_CAPS     , KC_A    , KC_S    , KC_D    , KC_F    , KC_G    , KC_H    , KC_J    , KC_K    , KC_L     , KC_SCLN , KC_QUOT    , KC_NUHS , KC_ENT  , */
  /*   KC_LSFT     , KC_NUBS , KC_Z    , KC_X    , KC_C    , KC_V    , KC_B    , KC_N    , KC_M    , KC_COMM  , KC_DOT  , KC_SLSH    , KC_RSFT , KC_UP   , */
  /*   KC_LCTL     , KC_LGUI , KC_LALT , KC_SPC  , KC_RALT , KC_RGUI , KC_APP  , KC_RCTL , KC_LEFT , KC_DOWN  , KC_RGHT , */
  /* ) \ */

};
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QMKBEST:
      if (record->event.pressed) {
        // when keycode QMKBEST is pressed
        SEND_STRING("~ ");
      } else {
        // when keycode QMKBEST is released
      }
      break;
  }
  return true;
};
