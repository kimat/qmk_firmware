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
#define _FN 3

#define THUMB_F LT(_SP,KC_SPC)
#define THUMB_K LT(_AG,KC_TAB)
#define MY_Q LCTL_T(BE_Q)
#define MY_S LSFT_T(KC_S)
#define MY_D LALT_T(KC_D)
#define MY_F LT(_SP,KC_F)
#define MY_G LT(_FN,KC_G)

#define MY_J LT(_SP,KC_J)
#define MY_K LALT_T(KC_K)
#define MY_L LSFT_T(KC_L)
#define MY_M LCTL_T(BE_M)

#define THUMB_H LSFT_T(KC_BSPC)
#define THUMB_G LSFT_T(KC_ESC)
#define THUMB_J RCTL_T(KC_ENT)
#define _CAPS LCTL_T(KC_ESC)
#define _LCTL LCTL_T(KC_F12)

#define MODS_SHIFT_MASK (MOD_BIT(KC_LSHIFT)|MOD_BIT(KC_RSHIFT))

/* #define MY_DOT M(0) */
enum custom_keycodes {
  QMKBEST = SAFE_RANGE,
  MY_RCBR,
  MY_LCBR,
  MY_DOT,
  MY_TILD,
  SALT_TAB
};

/* const uint16_t PROGMEM test_combo[] = {BE_Q, KC_S, COMBO_END}; */
/* combo_t key_combos[COMBO_COUNT] = {COMBO(test_combo, KC_ESC)}; */

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[_BA] = LAYOUT ( \
        KC_ESC     , BE_AMP  , BE_EXLM , BE_QUOT , BE_APOS , BE_LPRN , BE_LSBR , BE_RSBR , MY_LCBR , MY_RCBR  , BE_AGRV , BE_MINS    , \
        KC_TAB     , BE_A    , BE_Z    , KC_E    , KC_R    , KC_T    , KC_Y    , KC_U    , KC_I    , KC_O     , KC_P    , BE_CIRC    , \
        _CAPS      , MY_Q    , MY_S    , MY_D    , MY_F    , MY_G    , KC_H    , KC_J    , KC_K    , MY_L     , MY_M    , KC_ENT     , \
        KC_LSFT    , BE_W    , KC_X    , KC_C    , KC_V    , KC_B    , KC_N    , BE_COMM , MY_DOT  , BE_COLN  , BE_EQL  , KC_LSFT    , \
        SALT_TAB      , KC_LGUI , KC_LGUI , KC_LALT , THUMB_F , THUMB_G , THUMB_H , THUMB_J , THUMB_K , KC_K     , KC_L    , KC_CAPS  \
       )           ,
  // space
[_SP] = LAYOUT ( \
        _______    , _______ , _______ , _______ , _______ , _______ , _______ , _______ , BE_LCBR , BE_RCBR  , _______ , _______    ,
        KC_TAB     , BE_AMP  , BE_EXLM , BE_QUOT , BE_APOS , BE_LSBR , BE_RSBR , KC_HOME , BE_LCBR , BE_RCBR  , KC_DEL  , KC_PGUP    , \
        _CAPS      , BE_PIPE , BE_MINS , KC_TAB  , BE_SLSH , BE_PND  , KC_LEFT , KC_DOWN , KC_UP   , KC_RIGHT , KC_END  , KC_PGDN    , \
        KC_LSFT    , BE_LESS , BE_GRTR , KC_C    , KC_V    , KC_B    , KC_BSPC , KC_M    , KC_COMM , KC_DOT   , KC_SLSH , KC_LSFT    , \
        _______    , KC_LGUI , _______ , KC_LALT , _______ , _______ , THUMB_H , THUMB_J , _______ , KC_K     , KC_L    , KC_CAPS  \
        )          ,
// altgr
[_AG] = LAYOUT ( \
        KC_ESC     , BE_PIPE , BE_AT   , BE_HASH , _______ , _______ , _______ , BE_7    , BE_8    , BE_9     , KC_KP_0 , KC_A       , \
        KC_TAB     , BE_PIPE , BE_AT   , BE_HASH , _______ , BE_RPRN , _______ , BE_7    , BE_8    , BE_9     , KC_P    , KC_PGUP    , \
        _CAPS      , BE_PIPE , BE_UNDS , KC_D    , KC_SLSH , KC_G    , _______ , BE_4    , BE_5    , BE_6     , BE_DLR  , BE_GRV     , \
        KC_LSFT    , BE_BSLS , _______ , _______ , _______ , _______ , BE_0    , BE_1    , BE_2    , BE_3     , MY_TILD , KC_LSFT    , \
        _______    , KC_LGUI , _______ , KC_LALT , _______ , _______ , THUMB_H , THUMB_J , _______ , KC_K     , KC_L    , KC_CAPS  \
        )          ,
[_FN] = LAYOUT ( \
        KC_ESC     , _______ , _______ , _______ , _______ , _______ , _______ , KC_F7   , KC_F8   , KC_F9    , _______ , _______    , \
        _______    , _______ , _______ , _______ , _______ , _______ , _______ , KC_F7   , KC_F8   , KC_F9    , _______ , _______    , \
        _______    , _______ , MY_S    , MY_D    , _______ , _______ , KC_F11  , KC_F4   , KC_F5   , KC_F6    , _______ , _______    , \
        KC_LSFT    , _______ , _______ , _______ , _______ , _______ , KC_F10  , KC_F1   , KC_F2   , KC_F3    , _______ , _______    , \
        _______    , _______ , _______ , _______ , _______ , _______ , _______ , KC_F11  , KC_F12  , KC_F13   , _______ , _______  \
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

bool is_alt_tab_active = false;    // ADD this near the begining of keymap.c
uint16_t alt_tab_timer = 0;        // we will be using them soon.

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    /* case MY_DOT: */
    /*   if (record->event.pressed) { */
    /*     if (get_mods() & MODS_SHIFT_MASK){ */
    /*       /1* SEND_STRING(SS_TAP(X_LESS)); *1/ */
    /*       SEND_STRING(SS_UP(X_LSHIFT)";"SS_DOWN(X_LSHIFT)); */
    /*       /1* prev_mods= get_mods(); *1/ */
    /*       /1* clear_keyboard(); *1/ */
    /*       /1* tap_code16(BE_SCLN); *1/ */
    /*       /1* /2* register_code(BE_SCLN); *2/ *1/ */
    /*       /1* set_mods(prev_mods); *1/ */
    /*       /1* prev_mods= get_mods(); *1/ */
    /*       /1* clear_keyboard(); *1/ */
    /*       /1* /2* tap_code16(BE_SCLN); *2/ *1/ */
    /*       /1* SEND_STRING(";"); *1/ */
    /*     } */
    /*     else */
    /*       tap_code16(BE_DOT); */
    /*   } */
    /*   /1* return false; *1/ */
    /*   break; */
    /* case MY_RCBR: */
    /*   if (record->event.pressed) */
    /*     (keyboard_report->mods & MODS_SHIFT_MASK) ?  tap_code16(BE_8) : SEND_STRING("}"); */
    /*   break; */
    /* case MY_LCBR: */
    /*   if (record->event.pressed) */
    /*     (get_mods() & MODS_SHIFT_MASK) ?  tap_code16(BE_7) : SEND_STRING("{"); */
    /*   break; */
    /* case MY_TILD: */
    /*   if (record->event.pressed) */
    /*     SEND_STRING("{"); */
    // I swapped some keys from their default position so this configures how they should be shifted:
    case MY_DOT:
      if (record->event.pressed)
        (get_mods() & MODS_SHIFT_MASK) ? SEND_STRING(SS_UP(X_LSHIFT)";"SS_DOWN(X_LSHIFT)) : SEND_STRING(".");
      break;
    case MY_RCBR:
      if (record->event.pressed)
        (get_mods() & MODS_SHIFT_MASK) ?  SEND_STRING(SS_UP(X_LSHIFT)"8"SS_DOWN(X_LSHIFT)) : SEND_STRING("}");
      break;
    case MY_LCBR:
        (get_mods() & MODS_SHIFT_MASK) ?  SEND_STRING(SS_UP(X_LSHIFT)"7"SS_DOWN(X_LSHIFT)) : SEND_STRING("{");
      break;
    case MY_TILD: // I don't use this as a dead key
      if (record->event.pressed) SEND_STRING("~ ");
      break;
    case SALT_TAB:
      if (record->event.pressed) {
        if (!is_alt_tab_active) {
          is_alt_tab_active = true;
          register_code(KC_LALT);
        }
        alt_tab_timer = timer_read();
        register_code(KC_TAB);
      }
      else
        unregister_code(KC_TAB);
      break;
  }
  return true;
};

void matrix_scan_user(void) {     // The very important timer.
  if (is_alt_tab_active) {
    if (timer_elapsed(alt_tab_timer) > 300) {
      unregister_code(KC_LALT);
      is_alt_tab_active = false;
    }
  }
}
