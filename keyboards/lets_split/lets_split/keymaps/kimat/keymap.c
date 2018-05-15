// vim: set fdm=marker:
#include "lets_split.h"
#include "action_layer.h"
#include "eeconfig.h"

// Defines {{{
//------------
extern keymap_config_t keymap_config;

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _AZERTY 0
#define _MAJ 1
#define _LOWER 2
#define _RAISE 3
#define _ADJUST 16

enum custom_keycodes {
  AZERTY = SAFE_RANGE,
  MAJ,
  LOWER,
  RAISE,
  ADJUST,
};

// Fillers to make layering more clear
#define _______ KC_TRNS
#define XXXXXXX KC_NO
#define MAJ_ESC LT(_MAJ, KC_ESC)
#define MAJ_ENT LT(_MAJ, KC_ENT)
#define RAI_SPC LT(_RAISE, KC_SPC)
#define CTL_TAB CTL_T(KC_TAB)
#define CTL_ESC CTL_T(KC_ESC)
#define LOW_F12 LT(_LOWER, KC_F12)

// }}}

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

// Azerty {{{
//-----------
// | Tab    | a    | z   | e   | r     | t     | • | y     | u     | i    | o    | p  | Backspace |
// | Esc    | q    | s   | d   | f     | g     | • | h     | j     | k    | l    | ;  | "         |
// | Lshift | w    | x   | c   | v     | b     | • | n     | ,     | .    | :    | =  | Rshift    |
// | Adjust | Ctrl | Alt | GUI | Lower | Space | • | Space | Raise | Left | Down | Up | Right     |
[_AZERTY] = LAYOUT(
   KC_TAB , KC_A   , KC_Z , KC_E   , KC_R   , KC_T   , KC_Y   , KC_U   , KC_I   , KC_O   , KC_P  , KC_BSPC   , \
   CTL_ESC, KC_Q   , KC_S , KC_D   , KC_F   , KC_G   , KC_H   , KC_J   , KC_K   , KC_L   , KC_M  , KC_ENT    , \
   KC_LSFT, KC_W   , KC_X , KC_C   , KC_V   , KC_B   , KC_N   , KC_COMM, KC_DOT , KC_COLN, KC_EQL, KC_RSFT   , \
   ADJUST , KC_LCTL, RAISE, KC_LALT, RAI_SPC, MAJ_ESC, MAJ_ENT, CTL_TAB, LOW_F12, KC_DOWN, KC_UP , KC_RGHT  \
),
// }}}

// Maj {{{
//--------
// | Tab    | A    | Z   | E   | R     | T     | • | Y     | U     | I    | O    | P  | Backspace |
// | Esc    | Q    | S   | D   | F     | G     | • | H     | J     | K    | L    | ;  | "         |
// | Lshift | W    | X   | C   | V     | B     | • | N     | ?     | ;    | /    | +  | Rshift    |
// | Adjust | Ctrl | Alt | GUI | Lower | Space | • | Space | Raise | Left | Down | Up | Right     |
[_MAJ] = LAYOUT( \
  _______, S(KC_A), S(KC_Z), S(KC_E), S(KC_R), S(KC_T), S(KC_Y), S(KC_U), S(KC_I), S(KC_O), S(KC_P), S(KC_BSPC), \
  _______, S(KC_Q), S(KC_S), S(KC_D), S(KC_F), S(KC_G), S(KC_H), S(KC_J), S(KC_K), S(KC_L), S(KC_M), KC_SLSH   , \
  _______, S(KC_W) , S(KC_X), S(KC_C), S(KC_V), S(KC_B), S(KC_N), KC_QUES, KC_SCLN, KC_SLSH, KC_PLUS, _______   , \
  _______, _______, _______, _______, _______, _______, _______, _______, KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY \
),
// }}}

// Lower {{{
//----------
// |  | % | @ | # | ( | ) | • | $ | 7 | 8 | 9 | $ |  |
// |  | | | _ | = | { | } | • | h | 4 | 5 | 6 | ` |  |
// |  | \ | - | ` | [ | ] | • | 0 | 1 | 2 | 3 | ~ |  |
// |  |   |   |   |   |   | • |   |   |   |   |   |  |
[_LOWER] = LAYOUT( \
   _______, KC_PERC, KC_AT  , KC_HASH, KC_LPRN, KC_RPRN, KC_DLR , KC_7   , KC_8   , KC_9   , KC_DLR , _______  , \
   _______, KC_PIPE, KC_UNDS, KC_EQL , KC_LCBR, KC_RCBR, _______, KC_4   , KC_5   , KC_6   , KC_GRV, _______  , \
   _______, KC_BSLS, KC_MINS, KC_GRV , KC_LBRC, KC_RBRC, KC_0   , KC_1   , KC_2   , KC_3   , KC_TILD, _______  , \
  _______ , _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______ \
),
//   }}}

// Raise {{{
//----------
// | Tab    | a    | z   | e   | r     | t     | • | y     | u     | i    | o    | p  | Backspace |
// | Esc    | q    | s   | d   | f     | g     | • | h     | j     | k    | l    | ;  | "         |
// | Lshift | w    | x   | c   | v     | b     | • | n     | ,     | .    | :    | =  | Rshift    |
// | Adjust | Ctrl | Alt | GUI | Lower | Space | • | Space | Raise | Left | Down | Up | Right     |

// |  | & | ! | " | ' | ( |   | • | ^   | ←   | {   | } | DEL |  |
// |  |   |   | - | ⇥ | / | * | • | ←   | ↓   | ↑   | → | $   |  |
// |  | < | > | 8 | 9 |   |   | • | BSP | pDN | pUP |   | →   |  |
// |  |   |   |   |   |   |   | • |     |     |     |   |     |  |
[_RAISE] = LAYOUT( \
  _______, KC_AMPR, KC_EXLM, KC_DQT , KC_QUOT, KC_LPRN, KC_CIRC, KC_HOME, KC_LCBR, KC_RCBR , KC_DEL , _______  , \
  _______, KC_UNDS, KC_MINS, KC_TAB , KC_SLSH, KC_ASTR, KC_LEFT, KC_DOWN, KC_UP  , KC_RIGHT, KC_DLR , _______  , \
  _______, KC_LT  , KC_GT  , KC_8   , KC_9   , KC_LBRC, KC_BSPC, KC_PGDN, KC_PGUP, KC_END  , KC_END , _______  , \
  _______, _______, _______, _______, _______, _______, _______, _______, KC_MNXT, KC_VOLD , KC_VOLU, KC_MPLY \
),
//   }}}

// Adjust (Lower + Raise) {{{
// |      | Reset|      |      |      |      |      |      |      |      |      |  Del |
// |      |      |      |Aud on|Audoff|AGnorm|AGswap|Azerty|Colemk|Dvorak|      |      |
[_ADJUST] =  LAYOUT( \
  _______, RESET  , _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_DEL   , \
  _______, _______, _______, AU_ON  , AU_OFF , AG_NORM, AG_SWAP, AZERTY , MAJ    , _______, _______, _______  , \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______  , \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______ \
)
//  }}}

};

// Tri Layer & Audio {{{
//----------------------
#ifdef AUDIO_ENABLE
float tone_azerty[][2]     = SONG(QWERTY_SOUND);
float tone_maj[][2]     = SONG(DVORAK_SOUND);
#endif

void persistent_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case AZERTY:
      if (record->event.pressed) {
        #ifdef AUDIO_ENABLE
          PLAY_SONG(tone_azerty);
        #endif
        persistent_default_layer_set(1UL<<_AZERTY);
      }
      return false;
      break;
    case MAJ:
      if (record->event.pressed) {
        #ifdef AUDIO_ENABLE
          PLAY_SONG(tone_colemak);
        #endif
        persistent_default_layer_set(1UL<<_MAJ);
      }
      return false;
      break;
    case LOWER:
      if (record->event.pressed) {
        layer_on(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case RAISE:
      if (record->event.pressed) {
        layer_on(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case ADJUST:
      if (record->event.pressed) {
        layer_on(_ADJUST);
      } else {
        layer_off(_ADJUST);
      }
      return false;
      break;
  }
  return true;
}
// }}}
