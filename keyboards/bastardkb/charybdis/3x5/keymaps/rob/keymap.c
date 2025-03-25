/**
 * Copyright 2021 Charly Delay <charly@codesink.dev> (@0xcharly)
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

enum charybdis_keymap_layers {
    LAYER_BASE = 0,
    LAYER_LOWER,
    LAYER_RAISE,
};

#define LOWER MO(LAYER_LOWER)
#define RAISE MO(LAYER_RAISE)
// #define PT_Z LT(LAYER_POINTER, KC_Z)
// #define PT_SLSH LT(LAYER_POINTER, KC_SLSH)

#define HT_HOME_END LT(0, KC_HOME)
#define LOW_ENT LT(LAYER_LOWER, KC_ENT)

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [LAYER_BASE] = LAYOUT(
  // ╭──────────────────────────────────────────────────────────────────╮ ╭───────────────────────────────────────────────────────────────────╮
       KC_Q,         KC_W,         KC_E,         KC_R,    KC_T,           KC_Y,    KC_U,          KC_I,         KC_O,         KC_P,
  // ├──────────────────────────────────────────────────────────────────┤ ├───────────────────────────────────────────────────────────────────┤
       LGUI_T(KC_A), LALT_T(KC_S), LCTL_T(KC_D), LSFT_T(KC_F), KC_G,      KC_H,    RSFT_T(KC_J),  RCTL_T(KC_K), LALT_T(KC_L), RGUI_T(KC_SCLN),
  // ├──────────────────────────────────────────────────────────────────┤ ├───────────────────────────────────────────────────────────────────┤
       KC_Z,         KC_X,         KC_C,          KC_V,    KC_B,          KC_N,    KC_M,          KC_COMM,      KC_DOT,       KC_SLSH,
  // ╰──────────────────────────────────────────────────────────────────┤ ├───────────────────────────────────────────────────────────────────╯
                             KC_TAB, KC_SPC, LT(LAYER_RAISE, KC_ESC),     LOW_ENT, KC_BSPC
  //                               ╰────────────────────────────────────╯ ╰──────────────────╯
  ),

  [LAYER_LOWER] = LAYOUT(
  // ╭───────────────────────────────────────────────╮ ╭──────────────────────────────────────────╮
       HT_HOME_END, KC_7,    KC_8,    KC_9, KC_NO,     KC_TILD, KC_DQUO, KC_QUOT, KC_GRV,  KC_DEL,
  // ├───────────────────────────────────────────────┤ ├──────────────────────────────────────────┤
          KC_NO,    KC_4,    KC_5,    KC_6, KC_NO,     KC_LEFT, KC_DOWN,   KC_UP, KC_RIGHT, KC_NO,
  // ├───────────────────────────────────────────────┤ ├──────────────────────────────────────────┤
          KC_0,     KC_1,    KC_2,    KC_3, KC_PSCR,   KC_TRNS,  EE_CLR, KC_TRNS, KC_TRNS, KC_NO,
  // ╰───────────────────────────────────────────────┤ ├──────────────────────────────────────────╯
                           KC_TRNS, KC_TRNS, KC_TRNS,    KC_NO, QK_BOOT
  //                     ╰───────────────────────────╯ ╰──────────────────╯
  ),

  [LAYER_RAISE] = LAYOUT(
  // ╭──────────────────────────────────────────────╮ ╭─────────────────────────────────────────────╮
       KC_EXLM,   KC_AT, KC_HASH,  KC_DLR, KC_PERC,    KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN,
  // ├──────────────────────────────────────────────┤ ├─────────────────────────────────────────────┤
         KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,    KC_MINS,  KC_EQL, KC_LBRC, KC_RBRC, KC_BSLS,
  // ├──────────────────────────────────────────────┤ ├─────────────────────────────────────────────┤
         KC_F8,   KC_F9,  KC_F10,  KC_F11,  KC_F12,    KC_UNDS,  KC_PLUS, KC_LCBR, KC_RCBR, KC_PIPE,
  // ╰──────────────────────────────────────────────┤ ├─────────────────────────────────────────────╯
                          QK_BOOT, KC_TRNS,   KC_NO,    KC_TRNS, KC_TRNS
  //                    ╰───────────────────────────╯ ╰──────────────────╯
  ),

  // [LAYER_POINTER] = LAYOUT(
  // // ╭───────────────────────────────────────────────╮ ╭──────────────────────────────────────────────╮
  //      KC_NO,   KC_NO,   KC_NO,   DPI_MOD, S_D_MOD,      S_D_MOD,  DPI_MOD, KC_NO,   KC_NO,   KC_NO,
  // // ├───────────────────────────────────────────────┤ ├──────────────────────────────────────────────┤
  //      KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, KC_NO,        KC_NO,    KC_RSFT, KC_RCTL, KC_RALT, KC_RGUI,
  // // ├───────────────────────────────────────────────┤ ├──────────────────────────────────────────────┤
  //      KC_TRNS, DRGSCRL, KC_COPY, KC_PSTE, QK_BOOT,      QK_BOOT,  EE_CLR,  SNIPING, DRGSCRL, KC_TRNS,
  // // ╰───────────────────────────────────────────────┤ ├──────────────────────────────────────────────╯
  //                          KC_BTN2, KC_BTN1, KC_BTN3,    KC_BTN3, KC_BTN1
  // //                     ╰───────────────────────────╯ ╰──────────────────╯
  // ),
};
// clang-format on

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case LT(0, KC_HOME):
            if (!record->tap.count && record->event.pressed) {
                tap_code(KC_END); // Intercept hold function to send Ctrl-X
                return false;
            }
            return true; // Return true for normal processing of tap keycode
    }
    return true;
}

bool caps_word_press_user(uint16_t keycode) {
    uprintf("Keycode %u\n", keycode);
    switch (keycode) {
        // Keycodes that continue Caps Word, with shift applied.
        case KC_A ... KC_Z:
            add_weak_mods(MOD_BIT(KC_LSFT));
            return true;

        // Keycodes that continue Caps Word, without shifting.
        case KC_MINS:
            /* Note this differs from the default config which applies shift when KC_MINS is
             * pressed. This turn - to _ which I find annoying as there is a dedicated KC_UNDS */
        case KC_1 ... KC_0:
        case KC_BSPC:
        case KC_DEL:
        case KC_UNDS:
            return true;

        default:
            return false; // Deactivate Caps Word.
    }
}

