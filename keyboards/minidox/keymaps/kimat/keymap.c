// vim: set fdm=marker:
#include "minidox.h"
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
#define _ADJUST 4
#define _FUN 5

enum custom_keycodes {
  AZERTY = SAFE_RANGE,
  MAJ,
  LOWER,
  RAISE,
  ADJUST,
  FUN,
};

// Fillers to make layering more clear
#define _______ KC_TRNS
#define ___ KC_TRNS
#define XXXXXXX KC_NO
#define MAJ_ESC LT(_MAJ, KC_ESC)
#define MAJ_ENT LT(_MAJ, KC_ENT)
#define RAI_SPC LT(_RAISE, KC_SPC)
#define CTL_TAB CTL_T(KC_TAB)
#define CTL_ESC CTL_T(KC_ESC)
#define LOW_F12 LT(_LOWER, KC_F12)
#define ADJ_M LT(_ADJUST, KC_M)


// Defines for task manager and such
#define CALTDEL LCTL(LALT(KC_DEL))
#define TSKMGR LCTL(LSFT(KC_ESC))
// }}}

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

// Azerty {{{
// | a | z | e   | r     | t     | • | y     | u    | i    | o | p |
// | q | s | d   | f     | g     | • | h     | j    | k    | l | m |
// | z | x | c   | v     | b     | • | n     | ,    | .    | : | = |
// |   |   | Alt | SPACE | SHIFT | • | SHIFT | CTRL | NUM  |   |   |
// |   |   |     | Space |       | • | Enter | Tab  | Bspc |   |   |
[_AZERTY] = LAYOUT( \
  KC_A   , KC_Z   , KC_E   , KC_R   , KC_T   , KC_Y   , KC_U   , KC_I  , KC_O   , KC_P  , \
  KC_Q   , KC_S   , KC_D   , KC_F   , KC_G   , KC_H   , KC_J   , KC_K  , KC_L   , ADJ_M , \
  KC_W   , KC_X   , KC_C   , KC_V   , KC_B   , KC_N   , KC_COMM, KC_DOT, KC_COLN, KC_EQL, \
  KC_LALT, RAI_SPC, MAJ_ESC, MAJ_ENT, CTL_TAB, LOW_F12
)        ,
// }}}

// SHIFT {{{
// | A | Z | E | R | T | • | Y | U | I | O | P |
// | Q | S | D | F | G | • | H | J | K | L | M |
// | Z | X | C | V | B | • | N | ? | ; | / | + |
[_MAJ] = LAYOUT( \
  S(KC_A), S(KC_Z), S(KC_E), S(KC_R), S(KC_T), S(KC_Y), S(KC_U), S(KC_I), S(KC_O), S(KC_P), \
  S(KC_Q), S(KC_S), S(KC_D), S(KC_F), S(KC_G), S(KC_H), S(KC_J), S(KC_K), S(KC_L), S(KC_M), \
  (KC_W) , S(KC_X), S(KC_C), S(KC_V), S(KC_B), S(KC_N), KC_QUES, KC_SCLN, KC_SLSH, KC_PLUS, \
    ___  , ___    , ___    , ___    , ___    , ___ \
)        ,
// }}}

// Raise Layer {{{
// | &    | ! | "   | '   | ( | • | ^   | ←   | {   | } | DEL |
// | pipe | - | ⇥   | /   | * | • | ←   | ↓   | ↑   | → | $   |
// | <    | > | F14 | F15 | [ | • | BSP | pDN | pUP | ^  | →   |
[_RAISE] = LAYOUT( \
    KC_AMPR, KC_EXLM, KC_DQT, KC_QUOT, KC_LPRN, KC_CIRC, KC_CIRC, KC_LCBR, KC_RCBR , KC_DEL, \
    KC_PIPE, KC_MINS, KC_TAB, KC_SLSH, KC_ASTR, KC_LEFT, KC_DOWN, KC_UP  , KC_RIGHT, KC_DLR, \
    KC_LT  , KC_GT  , KC_F14, KC_F15 , KC_LBRC, KC_BSPC, KC_PGDN, KC_PGUP, KC_HOME, KC_END, \
    ___    , ___    , ___   , ___    , ___    , ___ \
)          ,
// }}}

// Lower Layer {{{
// | % | @ | # | ( | ) | • | $ | 7 | 8 | 9 | $ |
// | # | _ | = | { | } | • | } | 4 | 5 | 6 | - |
// | 6 | 7 | 8 | [ | ] | • | 0 | 1 | 2 | 3 | 5 |
[_LOWER] = LAYOUT( \
    KC_PERC, KC_AT  , KC_HASH, KC_LPRN, KC_RPRN, KC_DLR, KC_7, KC_8, KC_9, KC_GRV, \
    KC_HASH, KC_UNDS, KC_EQL , KC_LCBR, KC_RCBR, ___   , KC_4, KC_5, KC_6, KC_PERC, \
    KC_BSLS, KC_MINS, KC_GRV , KC_LBRC, KC_RBRC, KC_0  , KC_1, KC_2, KC_3, KC_TILD, \
    ___    , ___    , ___    , ___    , ___    , ___ \
)          ,
// }}}

// Adjust (Lower + Raise)  {{{
[_ADJUST] = LAYOUT( \
  KC_F, RESET, ___, ___, ___, KC_F12, KC_F7, KC_F8, KC_F9, ___, \
  ___ , ___  , ___, ___, ___, KC_F11, KC_F4, KC_F5, KC_F6, ___, \
  ___ , ___  , ___, ___, ___, KC_F10, KC_F1, KC_F2, KC_F3, ___, \
  ___ , ___  , ___, ___, ___, ___ \
)
};
// }}}
