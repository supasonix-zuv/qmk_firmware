#include QMK_KEYBOARD_H
#include "version.h"

#define BASE 0 // default layer
#define SYMB 1 // symbols
#define MDIA 2 // media keys
#define GAME 3 // Gaming layer

enum custom_keycodes {
  VRSN = SAFE_RANGE,
  RGB_SLD
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Keymap 0: Basic layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |   =    |   1  |   2  |   3  |   4  |   5  |GUI+[ |           | GUI+[|   6  |   7  |   8  |   9  |   0  |   -    |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * | Del    |   Q  |   D  |   R  |   W  |   B  |TG(1) |           | TG(1)|   J  |   F  |   U  |   P  |   ;  |   \    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * | BkSp   |   A  |   S  |   H  |   T  |   G  |------|           |------|   Y  |   N  |   E  |   O  |I / L2|' / Cmd |
 * |--------+------+------+------+------+------|TG(2) |           |TG(2) |------+------+------+------+------+--------|
 * | LShift |Z/Ctrl|   X  |   M  |   C  |   ,  |      |           |      |   .  |   V  |   K  |   L  |//Ctrl| RShift |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |Grv/L1|  '"  |AltShf|  [   |  ]   |                                       | Left | Down |  Up  | Right | ~L1  |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        | Home | End  |       | Play  |Ctrl/Esc|
 *                                 ,------|------|------|       |------+--------+------.
 *                                 |      |      | LAlt |       | Inst |        |      |
 *                                 | Space|Backsp|------|       |------|  Tab   |Enter |
 *                                 |      |ace   | GUI  |       | PtSc |        |      |
 *                                 `--------------------'       `----------------------'
 */
// If it accepts an argument (i.e, is a function), it doesn't need KC_.
// Otherwise, it needs KC_*
[BASE] = LAYOUT_ergodox(  // layer 0 : default
        // left hand
        KC_EQL,         KC_1,         KC_2,   KC_3,   KC_4,   KC_5,   LGUI(KC_LBRC),
        KC_DEL,         KC_Q,         KC_D,   KC_R,   KC_W,   KC_B,   TG(SYMB),
        KC_BSPC,        KC_A,         KC_S,   KC_H,   KC_T,   KC_G,
        KC_LSFT,        CTL_T(KC_Z),  KC_X,   KC_M,   KC_C,   KC_COMM,   TG(MDIA),
        LT(SYMB,KC_GRV),KC_QUOT,      LALT(KC_LSFT),  KC_LBRC,KC_RBRC,
                                              KC_HOME,  KC_END,
                                                              KC_LALT,
                                               KC_SPC,KC_BSPC,KC_LGUI,
        // right hand
             LGUI(KC_RBRC),  KC_6,   KC_7,  KC_8,   KC_9,   KC_0,             KC_MINS,
             TG(SYMB),    KC_J,   KC_F,  KC_U,   KC_P,   KC_SCLN,             KC_BSLS,
                          KC_Y,   KC_N,  KC_E,   KC_O,   LT(MDIA, KC_I),GUI_T(KC_QUOT),
             TG(MDIA),KC_DOT,   KC_V,  KC_K,KC_L, CTL_T(KC_SLSH),   KC_RSFT,
                                  KC_LEFT, KC_DOWN,KC_UP,KC_RIGHT,          MO(SYMB),
             KC_MPLY,        CTL_T(KC_ESC),
             KC_INS,
             KC_PSCR,KC_TAB,KC_ENT
    ),
/* Keymap 1: Symbol Layer
 *
 * ,---------------------------------------------------.           ,--------------------------------------------------.
 * |  RESET  |  F1  |  F2  |  F3  |  F4  |  F5  |      |           |      |  F6  |  F7  |  F8  |  F9  |  F10 |   F11  |
 * |---------+------+------+------+------+------+------|           |------+------+------+------+------+------+--------|
 * |         |   !  |   @  |   {  |   }  |   |  |      |           |      |   Up |   7  |   8  |   9  |   *  |   F12  |
 * |---------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |         |   #  |   $  |   (  |   )  |   `  |------|           |------| Down |   4  |   5  |   6  |   +  |        |
 * |---------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |         |   %  |   ^  |   [  |   ]  |   ~  |      |           |      |   &  |   1  |   2  |   3  |   \  |        |
 * `---------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 * | EEP_RST  |      |      |      |      |                                       |      |    . |   0  |   =  |TG(3)|
 *   `-----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 | Vol  | Vol  |      |       |      |Prev  |Next  |
 *                                 | -    | +    |------|       |------|Track |Track |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
// SYMBOLS
[SYMB] = LAYOUT_ergodox(
       // left hand
       RESET,   KC_F1,  KC_F2,  KC_F3,  KC_F4,  KC_F5,  KC_TRNS,
       KC_TRNS,KC_EXLM,KC_AT,  KC_LCBR,KC_RCBR,KC_PIPE,KC_TRNS,
       KC_TRNS,KC_HASH,KC_DLR, KC_LPRN,KC_RPRN,KC_GRV,
       KC_TRNS,KC_PERC,KC_CIRC,KC_LBRC,KC_RBRC,KC_TILD,KC_TRNS,
       EEP_RST,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
                                       KC_TRNS,KC_TRNS,
                                               KC_TRNS,
                               KC_VOLD,KC_VOLU,KC_TRNS,
       // right hand
       KC_TRNS, KC_F6,   KC_F7,  KC_F8,   KC_F9,   KC_F10,  KC_F11,
       KC_TRNS, KC_UP,   KC_7,   KC_8,    KC_9,    KC_ASTR, KC_F12,
                KC_DOWN, KC_4,   KC_5,    KC_6,    KC_PLUS, KC_TRNS,
       KC_TRNS, KC_AMPR, KC_1,   KC_2,    KC_3,    KC_BSLS, KC_TRNS,
                         KC_TRNS,KC_DOT,  KC_0,    KC_EQL,  TG(GAME),
       KC_TRNS, KC_TRNS,
       KC_TRNS,
       KC_TRNS, KC_MRWD, KC_MFFD
),
/* Keymap 2: Media and mouse keys
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |      | MsUp |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |MsLeft|MsDown|MsRght|      |------|           |------|      | MsU  |      |      |      |  Play  |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      | MsD  | Prev | Next |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      | Lclk | Rclk |                                       |VolUp |VolDn | Mute |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |Lclk  |Rclk  |      |       |      |Brwser|Brwser|
 *                                 |      |      |------|       |------|Back  |Fwd   |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
// MEDIA AND MOUSE
[MDIA] = LAYOUT_ergodox(
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_MS_U, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_MS_L, KC_MS_D, KC_MS_R, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_BTN1, KC_BTN2,
                                           KC_TRNS, KC_TRNS,
                                                    KC_TRNS,
                                  KC_BTN1, KC_BTN2, KC_TRNS,
    // right hand
       KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                 KC_TRNS, KC_WH_U, KC_TRNS, KC_TRNS, KC_TRNS, KC_MPLY,
       KC_TRNS,  KC_TRNS, KC_WH_D, KC_MPRV, KC_MNXT, KC_TRNS, KC_TRNS,
                          KC_VOLU, KC_VOLD, KC_MUTE, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS,
       KC_TRNS,
       KC_TRNS, KC_WBAK, KC_WFWD
),
/* Keymap 3: Gaming Layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |  F12   |  1   | 2    | 3    | 4    | 5    | 6    |           | LEFT |  6   |  7   |  8   | 9    | 0    |  -     |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * | TAB    | Q    | W    | E    | R    | T    | 7    |           |      |  Y   |      |  UP  |      | P    |  +     |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * | ~      | A    | S    | D    | F    | G    |------|           |------|      | LEFT |  DOWN| RIGHT| '    |  \     |
 * |--------+------+------+------+------+------| 8    |           |      |------+------+------+------+------+--------|
 * |  SHIFT | Z    | X    | C    | V    | B    |      |           |      |  N   | M    | ,    | .    | /    | RSHIFT |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   | LCTRL   |      |      |   | LALT |                                    | RALT |   | MO(SYMB) |TO(BASE) | TG(GAME)|
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        | ESC  | GUI  |       | F9   | Back |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |SPC   |      | INS  |       | Play |      |      |
 *                                 |      |      |------|       |------|      |Enter |
 *                                 |      |      | LALT |       | F5   |      |      |
 *                                 `--------------------'       `--------------------'
 */
// MEDIA AND MOUSE
[GAME] = LAYOUT_ergodox(
       KC_F12, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6,
       KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_7,
       KC_GRV, KC_A, KC_S, KC_D, KC_F, KC_G,
       KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_8,
       KC_LCTL, KC_NO, KC_NO, KC_NO, KC_LALT,
                                           KC_ESC, KC_LGUI,
                                                    KC_INS,
                                  KC_SPC, KC_NO, KC_LALT,
    // right hand
       KC_LEFT,  KC_6, KC_7, KC_8, KC_9, KC_0, KC_MINS,
       KC_NO,  KC_Y, KC_NO, KC_UP, KC_NO, KC_P, KC_EQL,
                 KC_NO, KC_LEFT, KC_DOWN, KC_RIGHT, KC_QUOT, KC_BSLS,
       KC_NO,  KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_RSFT,
                          KC_F1, KC_F2, KC_F3, TO(BASE), TG(GAME),
       KC_F9, KC_BSPC,
       KC_MPLY,
       KC_F5, KC_NO, KC_ENT
),
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    // dynamically generate these.
    case VRSN:
      if (record->event.pressed) {
        SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
      }
      return false;
      break;
    case RGB_SLD:
      if (record->event.pressed) {
        #ifdef RGBLIGHT_ENABLE
          rgblight_mode(1);
        #endif
      }
      return false;
      break;
  }
  return true;
}

// Runs constantly in the background, in a loop.
void matrix_scan_user(void) {

    uint8_t layer = biton32(layer_state);

    ergodox_right_led_1_off();
    ergodox_right_led_2_off();
    ergodox_right_led_3_off();
    switch (layer) {
      // TODO: Make this relevant to the ErgoDox EZ.
        case 1:
            ergodox_right_led_1_on();
            break;
        case 2:
            ergodox_right_led_2_on();
            break;
        default:
            // none
            break;
    }
};
