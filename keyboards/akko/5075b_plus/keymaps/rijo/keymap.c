// Copyright 2026 rijojohn
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H
// clang-format off

enum __layers {
    WIN_B,
    WIN_FN,
    MAC_B,
    MAC_FN,
    TMUX,
    SYM
};

enum tap_dance_codes {
    TD_EQL_EQEQ,    // tap: =   double-tap: ==
    TD_EXL_NEQ,     // tap: !   double-tap: !=
    TD_COLN_ASSIGN, // tap: :   double-tap: := (Go short var decl)
};

// DF() only moves the default layer in RAM, so the OS choice is lost on replug.
// These write it to EEPROM instead.
enum custom_keycodes {
    DF_WIN = SAFE_RANGE,
    DF_MAC
};

// tmux leader. Every key on the TMUX layer sends this first, then itself.
#define TMUX_PFX LCTL(KC_A)

// Home row mods. Windows: GACS (GUI/Alt/Ctrl/Shift), Mac: AGCS with Cmd on D/K.
#define W_A LGUI_T(KC_A)
#define W_S LALT_T(KC_S)
#define W_D LCTL_T(KC_D)
#define W_F LSFT_T(KC_F)
#define W_J RSFT_T(KC_J)
#define W_K RCTL_T(KC_K)
#define W_L RALT_T(KC_L)
#define W_SC RGUI_T(KC_SCLN)

#define M_A LALT_T(KC_A)
#define M_S LCTL_T(KC_S)
#define M_D LGUI_T(KC_D)
#define M_F LSFT_T(KC_F)
#define M_J RSFT_T(KC_J)
#define M_K RGUI_T(KC_K)
#define M_L RCTL_T(KC_L)
#define M_SC RALT_T(KC_SCLN)

#define CTL_ESC LCTL_T(KC_ESC)

#define TD_EQL  TD(TD_EQL_EQEQ)
#define TD_EXL  TD(TD_EXL_NEQ)
#define TD_ASGN TD(TD_COLN_ASSIGN)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [WIN_B] = LAYOUT(
        KC_ESC,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_DEL,   KC_MUTE,
        KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC,  KC_HOME,
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS,  KC_PGUP,
        CTL_ESC, W_A,     W_S,     W_D,     W_F,     KC_G,    KC_H,    W_J,     W_K,     W_L,     W_SC,    KC_QUOT,          KC_ENT,   KC_PGDN,
        KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,          KC_RSFT, KC_UP,    KC_END,
        KC_LCTL, KC_LGUI, KC_LALT,                   LT(SYM, KC_SPC),                   OSL(TMUX), MO(WIN_FN),     KC_RCTL, KC_LEFT,  KC_DOWN, KC_RGHT),

    [WIN_FN] = LAYOUT(
        _______, KC_MYCM, KC_MAIL, KC_WSCH, KC_WHOM, KC_MSEL, KC_MPLY, KC_MPRV, KC_MNXT, _______, _______, _______, _______, QK_BOOT,  _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______,
        _______, RM_NEXT, RM_PREV, RM_HUEU, RM_SATU, RM_VALU, RM_SPDU, RM_TOGG, KC_INS,  EE_CLR,  KC_PSCR, _______, _______, _______,  _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,  _______,
        _______, _______, _______, KC_CALC, _______, _______, _______, DF_MAC,  KC_MUTE, KC_VOLD, KC_VOLU,          _______, _______,  _______,
        _______, _______, _______,                   _______,                            _______, _______,          _______, _______,  _______, _______),

    [MAC_B] = LAYOUT(
        KC_ESC,  KC_BRID, KC_BRIU, KC_MCTL, KC_LPAD, KC_F5,   KC_F6,   KC_MPRV, KC_MPLY, KC_MNXT, KC_MUTE, KC_VOLD, KC_VOLU, KC_DEL,   KC_MUTE,
        KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC,  KC_HOME,
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS,  KC_PGUP,
        CTL_ESC, M_A,     M_S,     M_D,     M_F,     KC_G,    KC_H,    M_J,     M_K,     M_L,     M_SC,    KC_QUOT,          KC_ENT,   KC_PGDN,
        KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,          KC_RSFT, KC_UP,    KC_END,
        KC_LCTL, KC_LALT, KC_LGUI,                   LT(SYM, KC_SPC),                   OSL(TMUX), MO(MAC_FN),     KC_RCTL, KC_LEFT,  KC_DOWN, KC_RGHT),

    [MAC_FN] = LAYOUT(
        _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  QK_BOOT,  _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______,
        _______, RM_NEXT, RM_PREV, RM_HUEU, RM_SATU, RM_VALU, RM_SPDU, RM_TOGG, KC_INS,  EE_CLR,  KC_PSCR, _______, _______, _______,  _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,  _______,
        _______, _______, _______, KC_CALC, _______, _______, _______, DF_WIN,  KC_MUTE, KC_VOLD, KC_VOLU,          _______, _______,  _______,
        _______, _______, _______,                   _______,                            _______, _______,          _______, _______,  _______, _______),

    // Hold right alt. Mnemonic where it can be: (C)reate, (N)ext, (P)rev, (Z)oom,
    // (X) kill, (D)etach, (S)essions, (W)indows, (R)ename, (V)ertical / (H)orizontal
    // split, (O)ther pane, (L)ast window. Number row selects a window, arrows move
    // between panes. Anything unmapped is dead, so a mistyped key does nothing.
    //
    // V and H send "-" and "|" (not the tmux defaults "\"" and "%"), since
    // ~/.tmux.conf rebinds split-window onto those two keys instead.
    // ; and ' send Ctrl-s / Ctrl-r for tmux-resurrect's save/restore, which sit
    // on top of (not instead of) plain prefix+s (session tree) and prefix+, (rename).
    [TMUX] = LAYOUT(
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX,
        XXXXXXX, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX,
        XXXXXXX, XXXXXXX, KC_W,    XXXXXXX, KC_COMM, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_O,    KC_P,    KC_LBRC, KC_RBRC, XXXXXXX,  XXXXXXX,
        XXXXXXX, XXXXXXX, KC_S,    KC_D,    XXXXXXX, XXXXXXX, S(KC_BSLS), XXXXXXX, XXXXXXX, KC_L, LCTL(KC_S), LCTL(KC_R),    XXXXXXX,  XXXXXXX,
        XXXXXXX, KC_Z,    KC_X,    KC_C,    KC_MINS, XXXXXXX, KC_N,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,          XXXXXXX, KC_UP,    XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX,                   KC_SPC,                             XXXXXXX, XXXXXXX,          XXXXXXX, KC_LEFT,  KC_DOWN, KC_RGHT),

    // Held from the base layers via LT(SYM, KC_SPC): tap space for space, hold for
    // this. Left-hand-only symbols for Neovim/LazyVim, laid out per finger column:
    // Q/W = ~ ` , E/R = ( ) , T = % , A/S = & = , D/F = ^ $ , G = - ,
    // Z/X = @ _ , C/V = + ! , B = *. {} and [] dropped - already one shift away
    // on the base layer. Right hand is a number pad on YUIOP/HJKL;:
    // Y U I O P = 0 1 2 3 4, H J K L ; = 5 6 7 8 9.
    // S, V and the quote slot are tap-dances: single tap sends the symbol shown
    // above (=, !, :); double-tap sends ==, != or := instead.
    [SYM] = LAYOUT(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______,
        _______, KC_TILD, KC_GRV,  KC_LPRN, KC_RPRN, KC_PERC, KC_0,    KC_1,    KC_2,    KC_3,    KC_4,    _______, _______, _______,  _______,
        _______, KC_AMPR, TD_EQL,  KC_CIRC, KC_DLR,  KC_MINS, KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    TD_ASGN,          _______,  _______,
        _______, KC_AT,   KC_UNDS, KC_PLUS, TD_EXL,  KC_ASTR, _______, _______, _______, _______, _______,          _______, _______,  _______,
        _______, _______, _______,                   _______,                            _______, _______,          _______, _______,  _______, _______),
};

void td_eql_eqeq_finished(tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
        tap_code16(KC_EQL);
    } else {
        SEND_STRING("==");
    }
}

void td_exl_neq_finished(tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
        tap_code16(KC_EXLM);
    } else {
        SEND_STRING("!=");
    }
}

void td_coln_assign_finished(tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
        tap_code16(KC_COLN);
    } else {
        SEND_STRING(":=");
    }
}

tap_dance_action_t tap_dance_actions[] = {
    [TD_EQL_EQEQ]    = ACTION_TAP_DANCE_FN(td_eql_eqeq_finished),
    [TD_EXL_NEQ]     = ACTION_TAP_DANCE_FN(td_exl_neq_finished),
    [TD_COLN_ASSIGN] = ACTION_TAP_DANCE_FN(td_coln_assign_finished),
};

// The TMUX layer holds bare tmux command keys; the leader is injected here rather
// than baked into each one, so adding a binding is a one-key edit to the layer above.
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed && IS_LAYER_ON(TMUX) && keycode != KC_NO && keycode != OSL(TMUX)) {
        tap_code16(TMUX_PFX);
    }

    switch (keycode) {
        case DF_WIN:
            if (record->event.pressed) set_single_persistent_default_layer(WIN_B);
            return false;
        case DF_MAC:
            if (record->event.pressed) set_single_persistent_default_layer(MAC_B);
            return false;
    }

    return true;
}

#if defined(ENCODER_ENABLE)
bool encoder_update_user(uint8_t index, bool clockwise) {
    tap_code(clockwise ? KC_VOLU : KC_VOLD);
    return false;
}
#endif
