// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later
//
// TODO:
// - OS detection
//  - danish letters on alt ;oa (like macos)

#include QMK_KEYBOARD_H

// Userspace
#include "features/achordion.h"
#include "features/custom_shift_keys.h"

#include "keys.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    // BASE
    [0] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      KC_CIRC,  KC_V,    KC_W,    KC_M,    KC_G,    KC_X,                       KC_PIPE,   KC_U,    KC_O,    KC_Y,    KC_B,   KC_AT,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      HM_Q,     HM_C,    HM_S,    HM_N,    HM_T,    HM_K,                       HM_MINS,   HM_A,    HM_E,    HM_I,    HM_H,    HM_Z,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
     KC_GRAVE,  KC_P,    HM_F,    KC_L,    HM_D,    KC_J,                        KC_EQL, HM_COMM, KC_QUOTE, HM_DOT,  KC_SLSH, KC_ASTR,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          LT_TAB,  LT_ESC,  LT_R,       LT_SPC,  KC_BSPC, KC_ENT
                                      //`--------------------------'  `--------------------------'

  ),
    // NAV
    [1] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, KC_HOME,  KC_UP,  KC_END,  XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_HYPR, KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, KC_MEH,                       KC_PGUP, KC_LEFT, KC_DOWN,KC_RIGHT, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, KC_RALT, XXXXXXX, KC_LCAG, XXXXXXX,                      KC_PGDN, KC_CIRC, XXXXXXX, KC_DLR,  XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          XXXXXXX, XXXXXXX, _______,    KC_MPLY, KC_MUTE, KC_MSTP
                                      //`--------------------------'  `--------------------------'
  ),
    // SYMBOLS
    [2] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      _______, _______, _______, _______, _______, _______,                      _______, KC_LBRC, KC_RBRC, _______, _______, _______,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, _______, _______, _______, _______, _______,                      _______, KC_LPRN, KC_RPRN, KC_RABK, KC_DLR,  _______,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, _______, _______, _______, _______, _______,                      _______, KC_LBRC, KC_RBRC, KC_LABK, _______, _______,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          XXXXXXX, _______, XXXXXXX,    KC_SPC,  _______, _______
                                      //`--------------------------'  `--------------------------'
  ),
    // NUMBERS
    [3] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      _______, _______, _______, _______, _______, _______,                      KC_PEQL,  KC_7,    KC_8,    KC_9,   KC_PSLS, KC_PAST,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, _______, _______, _______, _______, _______,                      KC_PPLS,  KC_4,    KC_5,    KC_6,    KC_0,   XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, _______, _______, _______, _______, _______,                      KC_PMNS,  KC_1,    KC_2,    KC_3,   KC_COMM, KC_DOT,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          _______, XXXXXXX, XXXXXXX,    KC_SPC,  _______, _______
                                      //`--------------------------'  `--------------------------'
  ),
    // FN
    [4] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      XXXXXXX, KC_F9,   KC_F10,  KC_F11,  KC_F12,  XXXXXXX,                      _______, _______, _______, _______, _______, _______,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, KC_F5,   KC_F6,   KC_F7,   KC_F8,   XXXXXXX,                      _______, _______, _______, _______, _______, MO(5),
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, KC_F1,   KC_F2,   KC_F3,   KC_F4,   XXXXXXX,                      _______, _______, _______, _______, _______, _______,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_CAPS, XXXXXXX, CW_TOGG,    _______, XXXXXXX, XXXXXXX
                                      //`--------------------------'  `--------------------------'
  ),
    // QMK
    [5] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      QK_BOOT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      QK_RBT,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX
                                      //`--------------------------'  `--------------------------'
  )
};

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

// Achordion
// https://getreuer.info/posts/keyboards/achordion/index.html
bool achordion_chord(uint16_t tap_hold_keycode,
                     keyrecord_t* tap_hold_record,
                     uint16_t other_keycode,
                     keyrecord_t* other_record) {
  // Also allow same-hand holds when the other key is in the rows below the
  // alphas. I need the `% (MATRIX_ROWS / 2)` because my keyboard is split.
  if (other_record->event.key.row % (MATRIX_ROWS / 2) >= 3) { return true; }
  // Otherwise, follow the opposite hands rule.
  return achordion_opposite_hands(tap_hold_record, other_record);
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
  {HM_DOT , KC_COLN}, // Shift . is :
  {KC_COMM, KC_SCLN}, // Shift , is ;
  {KC_ASTR, KC_BSLS}, /* Shift * is \ */
  {KC_MINS, KC_PLUS}, // Shift - is +
  {KC_EQL , KC_EXLM}, // Shift = is !
  {KC_AT  , KC_HASH}, // Shift @ is #
  {KC_PIPE, KC_AMPR}, // Shift | is &
  {KC_CIRC, KC_PERC}, // Shift ^ is %
  {LT_SPC , KC_UNDS}, // Shift space is _
};
uint8_t NUM_CUSTOM_SHIFT_KEYS =
    sizeof(custom_shift_keys) / sizeof(custom_shift_key_t);
