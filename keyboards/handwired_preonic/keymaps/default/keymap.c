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

#define THUMB_G LSFT_T(KC_ESC)
#define THUMB_F LSFT_T(KC_SPC)
#define THUMB_H LSFT_T(KC_BSPC)
#define THUMB_J RCTL_T(KC_ENT)
#define THUMB_K RALT_T(KC_TAB)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT ( \
        KC_ESC  , KC_1    , KC_2 , KC_3    , KC_4    , KC_5    , KC_6    , KC_7    , KC_8    , KC_9   , KC_0    , KC_MINS    , \
        KC_TAB  , KC_Q    , KC_W , KC_E    , KC_R    , KC_T    , KC_Y    , KC_U    , KC_I    , KC_O   , KC_P    , KC_LBRC    , \
        KC_LCTL , KC_A    , KC_S , KC_D    , KC_F    , KC_G    , KC_H    , KC_J    , KC_K    , KC_L   , KC_SCLN , KC_QUOT    , \
        KC_LSFT , KC_Z    , KC_X , KC_C    , KC_V    , KC_B    , KC_N    , KC_M    , KC_COMM , KC_DOT , KC_SLSH , KC_RSFT    , \
        KC_LCTL , KC_LGUI , KC_D , KC_LALT , THUMB_F , THUMB_G , THUMB_H , THUMB_J , THUMB_K , KC_K   , KC_L    , KC_CAPS  \
  )                ,
};
