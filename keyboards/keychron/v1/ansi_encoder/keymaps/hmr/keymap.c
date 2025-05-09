/* Copyright 2021 @ Keychron (https://www.keychron.com)
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

#include "keycodes.h"
#include "keymap_us.h"
#include QMK_KEYBOARD_H

// Userspace
#include "features/achordion.h"
#include "features/custom_shift_keys.h"

#include "keys.h"

// clang-format off

enum layers{
    MAC_BASE,
    WIN_BASE,
    FN,
    SYM,
    QMK,
};

#define KC_TASK LGUI(KC_TAB)
#define KC_FLXP LGUI(KC_E)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [MAC_BASE] = LAYOUT_ansi_82(
    // |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
         KC_ESC,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_DEL,           KC_MUTE,
    // |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
         KC_GRV,  KC_1,     KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,   KC_MINS, KC_EQL,  KC_BSPC,          KC_PGUP,
    // |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
         KC_TAB,  KC_Q,     KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,   KC_LBRC, KC_RBRC, KC_BSLS,          KC_PGDN,
    // |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
         LT_ESC,  HM_A,     HM_S,    HM_D,    HM_F,    KC_G,    KC_H,    HM_J,    HM_K,    HM_L,   HM_SCLN, KC_QUOT,          KC_ENT,           KC_HOME,
    // |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------------------------+--------|
        KC_LSFT,  KC_Z,     HM_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,   KC_COMM, HM_DOT,  KC_SLSH,          KC_RSFT,          KC_UP,
    // |-----------------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------------------------+--------+--------|
        KC_LCTL, KC_LOPT,  KC_LCMD,                            LT_SPC,                             KC_RCMD, KC_RALT, KC_RCTL, KC_LEFT, KC_DOWN, KC_RGHT
    // |--------+--------+--------+--------------------------------------------------------------+--------+--------+--------+--------+--------+--------|
    ),

    [WIN_BASE] = LAYOUT_ansi_82(
    // |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
         KC_ESC,  KC_F1,    KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10,  KC_F11,  KC_F12,  KC_DEL,           KC_MUTE,
    // |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
         KC_GRV,  KC_1,     KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,   KC_MINS, KC_EQL,  KC_BSPC,          KC_PGUP,
    // |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
         KC_TAB,  KC_Q,     KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,   KC_LBRC, KC_RBRC, KC_BSLS,          KC_PGDN,
    // |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
         LT_ESC,  HM_A,     HM_S,    HM_D,    HM_F,    KC_G,    KC_H,    HM_J,    HM_K,    HM_L,   HM_SCLN, KC_QUOT,          KC_ENT,           KC_HOME,
    // |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------------------------+--------|
        KC_LSFT,  KC_Z,     KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,   KC_COMM, HM_DOT,  KC_SLSH,          KC_RSFT,          KC_UP,
    // |-----------------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------------------------+--------+--------|
        KC_LCTL, KC_LWIN,  KC_LCTL,                            LT_SPC,                             KC_RALT, KC_RWIN, KC_RCTL, KC_LEFT, KC_DOWN, KC_RGHT
    // |--------+--------+--------+--------------------------------------------------------------+--------+--------+--------+--------+--------+--------|
    ),

    [FN] = LAYOUT_ansi_82(
    // |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
        _______,  KC_BRID, KC_BRIU,  KC_NO,   KC_NO,  RM_VALD, RM_VALU, KC_MPRV, KC_MPLY, KC_MNXT, KC_MUTE, KC_VOLD, KC_VOLU, _______,          RM_NEXT,
    // |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
        _______,  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
    // |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
        _______,  _______, _______, _______, _______, _______, KC_HOME, KC_PGDN, KC_PGUP, KC_END,  _______, _______, _______, _______,          _______,
    // |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
        _______,  _______, _______, _______, _______, _______, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, _______, _______,          KC_MPLY,          MO(QMK),
    // |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------------------------+--------|
        CW_TOGG,  _______, _______, _______, _______, _______, KC_CIRC, VI_DOWN, VI_UP,   KC_DLR,  _______,          CW_TOGG,          KC_VOLU,
    // |-----------------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------------------------+--------+--------|
        _______, _______,  _______,                            _______,                            _______, _______, _______, KC_MPRV, KC_VOLD, KC_MNXT
    // |--------+--------+--------+--------------------------------------------------------------+--------+--------+--------+--------+--------+--------|
    ),

    [SYM] = LAYOUT_ansi_82(
    // |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
        _______,  RM_SATD, RM_SATU,  KC_NO,   KC_NO,  RM_VALD, RM_VALU, RM_PREV, KC_MPLY, RM_NEXT, KC_MUTE, RM_SPDD, RM_SPDU, _______,          RM_PREV,
    // |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
        _______,  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
    // |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
        _______,  _______, _______, _______, _______, _______, KC_MINS, KC_LCBR, KC_RCBR, KC_DLR,  _______, _______, _______, _______,          _______,
    // |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
        _______,  _______, _______, _______, _______, _______, KC_LT,   KC_LPRN, KC_RPRN, KC_GT,   KC_PIPE, KC_AMPR,          _______,          _______,
    // |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------------------------+--------|
        _______,  _______, _______, _______, _______,  _______, KC_EQL,  KC_LBRC, KC_RBRC, KC_ASTR, KC_SLSH,          KC_TILD,          RM_VALU,
    // |-----------------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------------------------+--------+--------|
        _______, _______,  _______,                            _______,                            _______, _______, _______, RM_SPDD, RM_VALD, RM_SPDU
    // |--------+--------+--------+--------------------------------------------------------------+--------+--------+--------+--------+--------+--------|
    ),

    [QMK] = LAYOUT_ansi_82(
    // |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
        QK_BOOT,  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
    // |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
        _______,  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
    // |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
        _______,  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
    // |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
        _______,  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,          _______,
    // |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------------------------+--------|
        _______,  _______, _______, _______, _______, _______, NK_TOGG, _______, _______, _______, _______,          _______,          _______,
    // |-----------------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------------------------+--------+--------|
         QK_RBT, _______,  _______,                            _______,                            _______, _______, _______, _______, _______, _______
    // |--------+--------+--------+--------------------------------------------------------------+--------+--------+--------+--------+--------+--------|
    )
};

#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [MAC_BASE] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU)},
    [WIN_BASE] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU)},
    [FN]   = { ENCODER_CCW_CW(RM_SATD, RM_SATU)},
    [SYM]   = { ENCODER_CCW_CW(RM_HUED, RM_HUEU)},
    [QMK]   = { ENCODER_CCW_CW(RM_VALD, RM_VALU)},
};
#endif // ENCODER_MAP_ENABLE

// Handle DIP switches similarly to v2, i.e. switch between layer 0/1
bool dip_switch_update_user(uint8_t index, bool active) {
    if (index == 0) {
        default_layer_set(1UL << (active ? 1 : 0));
        return false; // Prevent keyboard-level function from processing this switch
    }

    // Return true for other switches to allow keyboard-level function to process them
    return true;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  // Achordion
  if (!process_achordion(keycode, record)) { return false; }
  // custom shift keys
  if (!process_custom_shift_keys(keycode, record)) { return false; }

  return true;
}

void matrix_scan_user(void) {
  achordion_task();
}

uint16_t get_quick_tap_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case LT_SPC: // TODO: maybe 0 here as well?
            return QUICK_TAP_TERM;
        default:
            return 0;
    }
}

// Achordion
// https://getreuer.info/posts/keyboards/achordion/index.html
bool achordion_chord(uint16_t tap_hold_keycode,
                     keyrecord_t* tap_hold_record,
                     uint16_t other_keycode,
                     keyrecord_t* other_record) {

  // Allow all holds for spc, tab, esc and grave. Also include "b" as it's in the center.
  switch (other_keycode) {
    case LT_SPC:
    case KC_B:
    case KC_TAB:
    case KC_GRV:
    case LT_ESC:
        return true;
  }

  // For certain key combinations, we'll also allow holds.
  switch (tap_hold_keycode) {
    // Allow same hand mods layer for thumbs
    case LT_SPC:
    case LT_ESC:
    case LT_LCMD:
    case LT_LALT:
      return true;
    // Allow common combinations for left hand
    // case HM_F: // lmet
    // case HM_S: // lctl
    //   if (other_record->event.key.row > 1) { // i.e. all alpha letters
    //     return true;
    //   }
    //   break;
  }

  // Check that both keys on the same hand. This is what happens in achordion, but the keyboard is not as symmetric as assumed by the library.
  return (tap_hold_record->event.key.col < 6) != (other_record->event.key.col < 6);
}

bool achordion_eager_mod(uint8_t mod) {
  switch (mod) {
    case MOD_LSFT:
    case MOD_RSFT:
    case MOD_LCTL:
    case MOD_RCTL:
    case MOD_LALT:
    case MOD_RALT:
    case MOD_LGUI:
    case MOD_RGUI:
      return true;  // Eagerly apply Shift, Alt, and Ctrl mods.

    default:
      return false;
  }
}

// custom shift keys
// https://getreuer.info/posts/keyboards/custom-shift-keys/index.html
const custom_shift_key_t custom_shift_keys[] = {
  {KC_BSPC, KC_DEL }, // Shift backspace is del
  {KC_MINS, KC_PLUS}, // Shift - is +
  {LT_SPC , KC_UNDS}, // Shift space is _
  {KC_EQL , KC_EXLM}, // Shift = is !
};
uint8_t NUM_CUSTOM_SHIFT_KEYS =
    sizeof(custom_shift_keys) / sizeof(custom_shift_key_t);
