// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later
//
// TODO:
// - OS detection
//  - danish letters on alt ;oa (like macos)

#include <stdint.h>
#include "keycodes.h"
#include "quantum.h"
#include QMK_KEYBOARD_H

// Userspace
#include "features/achordion.h"
#include "features/custom_shift_keys.h"

#include "keys.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    // BASE
    [0] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      KC_GRV,   KC_V,    KC_W,    KC_M,    KC_G,    KC_Z,                        KC_MINS,  KC_U,    KC_O,    KC_Y,   DK_OE,   DK_AA,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
       KC_Q,    HM_C,    HM_S,    HM_N,    HM_T,    KC_B,                         KC_X,    HM_A,    HM_E,    HM_I,    HM_H,  KC_QUOTE,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_PIPE,  KC_P,    HM_F,    KC_L,    KC_D,    KC_J,                        KC_EQL,   KC_K,   KC_COMM, HM_DOT,  KC_SLSH, DK_AE,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          LT_TAB,  LT_R,  LT_ESC,       LT_BSPC, LT_SPC,  KC_ENT
                                      //`--------------------------'  `--------------------------'

  ),
    // NAV
    [1] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      XXXXXXX,  GUIV,    GUIW,    GUIM,    GUIG,    GUIZ,                        KC_HOME, KC_PGDN, KC_PGUP, KC_END,  XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
       GUIQ,   _______, _______, _______, _______,  GUIB,                        KC_LEFT, KC_DOWN, KC_UP,  KC_RIGHT, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX,  GUIP,   HM_F,     GUIL,    GUID,    GUIJ,                        VI_HOME, VI_DOWN, VI_UP,   VI_END,  XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          XXXXXXX, _______, XXXXXXX,    VI_OUT,  VI_JMP,  VI_IN
                                      //`--------------------------'  `--------------------------'
  ),
    // SYMBOLS
    [2] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      _______, _______, _______, _______, _______, _______,                      _______, KC_LCBR, KC_RCBR, KC_PERC, KC_HASH, _______,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, _______, _______, _______, _______, _______,                      KC_LT,   KC_LPRN, KC_RPRN, KC_GT,    KC_AT,  KC_BSLS,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, _______, _______, _______, _______, _______,                      _______, KC_LBRC, KC_RBRC, KC_ASTR, _______, _______,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          XXXXXXX, XXXXXXX, _______,    KC_CIRC, KC_UNDS, KC_DLR
                                      //`--------------------------'  `--------------------------'
  ),
    // NUMBERS
    [3] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      _______, _______, _______, _______, _______, _______,                      KC_CIRC,  KC_7,    KC_8,    KC_9,   KC_HASH, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, _______, _______, _______, _______, _______,                      KC_PERC,  KC_4,    KC_5,    KC_6,   KC_ASTR, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, _______, _______, _______, _______, _______,                      KC_EQL,   KC_1,    KC_2,    KC_3,   KC_SLSH, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          _______, XXXXXXX, XXXXXXX,    KC_MINS,  KC_0,  KC_PLUS
                                      //`--------------------------'  `--------------------------'
  ),
    // FN
    [4] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      XXXXXXX, KC_F9,   KC_F10,  KC_F11,  KC_F12,  XXXXXXX,                      KC_HOME, KC_PGDN, KC_PGUP, KC_END,  _______, _______,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_CAPS, KC_F5,   KC_F6,   KC_F7,   KC_F8,   XXXXXXX,                      KC_LEFT, HM_DOWN, HM_UP,  HM_RIGHT, _______, MO(6),
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, KC_F1,   KC_F2,   KC_F3,   KC_F4,   XXXXXXX,                      VI_HOME, VI_DOWN, VI_UP,   VI_END,  _______, _______,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          XXXXXXX, CW_TOGG, XXXXXXX,    XXXXXXX, _______, XXXXXXX
                                      //`--------------------------'  `--------------------------'
  ),
    // MISC + MEDIA
    [5] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      XXXXXXX, XXXXXXX, XXXXXXX, KC_VOLU, XXXXXXX, XXXXXXX,                       _______, _______, _______, _______, _______, _______,
  //|--------|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, KC_MPRV, KC_VOLD, KC_MNXT, XXXXXXX,                       KC_MPRV, KC_VOLD, KC_VOLU, KC_MNXT, _______, _______,
  //|--------|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                       _______, KC_MUTE, KC_MPLY, _______, _______, _______,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_MUTE, KC_MPLY, KC_MSTP,    _______, XXXXXXX, XXXXXXX
                                      //`--------------------------'  `--------------------------'
  ),
    // QMK
    [6] = LAYOUT_split_3x6_3(
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
  // process entire left handof layer 1 to cmd-modded keys
  if (IS_LAYER_ON(1) && record->event.pressed && record->tap.count) {
    switch (keycode) {
      case HM_C:
        tap_code16(LGUI(KC_C));
        return false;
      case HM_S:
        tap_code16(LGUI(KC_S));
        return false;
      case HM_N:
        tap_code16(LGUI(KC_N));
        return false;
      case HM_T:
        tap_code16(LGUI(KC_T));
        return false;
      case HM_F:
        tap_code16(LGUI(KC_F));
        return false;
    }
    // if (record->event.key.row % (MATRIX_ROWS / 2) <= 2 && record->event.key.col < 6) {
    //   tap_code16(LGUI(keycode));
    //   return false;
    // }
  }

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
        case LT_SPC:
        case LT_BSPC:
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
  switch (tap_hold_keycode) {
    // Allow same hand mods layer for thumbs
    case LT_SPC:
    case LT_R:
    case LT_ESC:
    case LT_BSPC:
    case LT_TAB:
      return true;
    case HM_N:
      switch (other_keycode) {
        case KC_GRV:
          return true;
      }
  }

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
  {LT_BSPC, KC_DEL }, // Shift backspace is del
  {HM_DOT , KC_COLN}, // Shift . is : (sym \)
  {KC_COMM, KC_SCLN}, // Shift , is ;
  // {KC_SLSH, KC_ASTR}, // Shift / is * (sym ~)
  {KC_MINS, KC_PLUS}, // Shift - is +
  // {KC_AT  , KC_AMPR}, // Shift @ is & (sym #)
  // {KC_EXLM, KC_QUES}, // Shift ? is ! (sym =)
  {LT_SPC , KC_UNDS}, // Shift space is _
  // {HM_DOT , KC_COLN}, // Shift . is :
  // {KC_COMM, KC_SCLN}, // Shift , is ;
  // {KC_ASTR, KC_BSLS}, /* Shift * is \ */
  // {KC_MINS, KC_PLUS}, // Shift - is + (sym =)
  {KC_EQL , KC_EXLM}, // Shift = is !
  {KC_AT  , KC_HASH}, // Shift @ is #
  {KC_PIPE, KC_AMPR}, // Shift | is &
  // {KC_CIRC, KC_PERC}, // Shift ^ is %
};
uint8_t NUM_CUSTOM_SHIFT_KEYS =
    sizeof(custom_shift_keys) / sizeof(custom_shift_key_t);
