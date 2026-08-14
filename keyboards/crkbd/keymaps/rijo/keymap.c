// rijo's Corne v4.1 keymap
// Layers: LIN/MAC bases (home-row mods, Ctrl<->Cmd swapped), NAV, NUM, SYM, TMUX, FUN.
// OS detection picks the base layer on plug-in; manual override on FUN layer.

#include QMK_KEYBOARD_H

enum layers {
    _LIN,  // Linux / Windows base
    _MAC,  // macOS base
    _NAV,
    _NUM,
    _SYM,
    _TMUX,
    _FUN,
};

enum custom_keycodes {
    TM_NEW = SAFE_RANGE, // C-a c   new window
    TM_NXT,              // C-a n   next window
    TM_PRV,              // C-a p   previous window
    TM_WIN,              // C-a w   choose-window tree
    TM_DET,              // C-a d   detach
    TM_SAV,              // C-a C-s resurrect save
    TM_RES,              // C-a C-r resurrect restore
    TM_MH,               // C-a C-h
    TM_MJ,               // C-a C-j
    TM_MK,               // C-a C-k
    TM_ML,               // C-a C-l
    TM_PFX,              // bare C-a prefix, then type anything
    OS_MAC,              // force mac base (persistent)
    OS_LIN,              // force linux base (persistent)
};

// Home-row mods, Linux: GUI / Alt / Ctrl / Shift
#define L_A LGUI_T(KC_A)
#define L_S LALT_T(KC_S)
#define L_D LCTL_T(KC_D)
#define L_F LSFT_T(KC_F)
#define L_J RSFT_T(KC_J)
#define L_K RCTL_T(KC_K)
#define L_L LALT_T(KC_L)
#define L_SCLN RGUI_T(KC_SCLN)

// Home-row mods, macOS: Ctrl / Opt / Cmd / Shift
#define M_A LCTL_T(KC_A)
#define M_S LALT_T(KC_S)
#define M_D LGUI_T(KC_D)
#define M_F LSFT_T(KC_F)
#define M_J RSFT_T(KC_J)
#define M_K RGUI_T(KC_K)
#define M_L LALT_T(KC_L)
#define M_SCLN RCTL_T(KC_SCLN)

// Thumbs
#define TH_ESC LT(_TMUX, KC_ESC)
#define TH_SPC LT(_NAV, KC_SPC)
#define TH_TAB LT(_NUM, KC_TAB)
#define TH_ENT LT(_SYM, KC_ENT)
#define TH_DEL LT(_FUN, KC_DEL)

#define OSL_TM OSL(_TMUX)
#define OSM_SFT OSM(MOD_LSFT)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_LIN] = LAYOUT_split_3x6_3_ex2(
  //,--------------------------------------------------------------.  ,--------------------------------------------------------------.
       KC_TAB,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T, CW_TOGG,    KC_MUTE,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P, KC_BSPC,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
      KC_LCTL,     L_A,     L_S,     L_D,     L_F,    KC_G,  OSL_TM,     OSL_TM,    KC_H,     L_J,     L_K,     L_L,  L_SCLN, KC_QUOT,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
      KC_LSFT,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                          KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH, KC_MINS,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                           TH_ESC,  TH_SPC,  TH_TAB,     TH_ENT, KC_BSPC,  TH_DEL
                                      //`--------------------------'  `--------------------------'
  ),

    [_MAC] = LAYOUT_split_3x6_3_ex2(
  //,--------------------------------------------------------------.  ,--------------------------------------------------------------.
       KC_TAB,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T, CW_TOGG,    KC_MUTE,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P, KC_BSPC,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
      KC_LCTL,     M_A,     M_S,     M_D,     M_F,    KC_G,  OSL_TM,     OSL_TM,    KC_H,     M_J,     M_K,     M_L,  M_SCLN, KC_QUOT,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
      KC_LSFT,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                          KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH, KC_MINS,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                           TH_ESC,  TH_SPC,  TH_TAB,     TH_ENT, KC_BSPC,  TH_DEL
                                      //`--------------------------'  `--------------------------'
  ),

    [_NAV] = LAYOUT_split_3x6_3_ex2(
  //,--------------------------------------------------------------.  ,--------------------------------------------------------------.
      _______, _______, _______, _______, _______, _______, _______,    _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  KC_DEL, _______,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
      _______, _______, _______, _______, OSM_SFT, _______, _______,    _______, KC_LEFT, KC_DOWN,   KC_UP, KC_RGHT, XXXXXXX, _______,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
      _______, _______, _______, _______, _______, _______,                       KC_HOME, KC_PGDN, KC_PGUP,  KC_END, XXXXXXX, _______,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          _______, _______, _______,    _______, _______, _______
                                      //`--------------------------'  `--------------------------'
  ),

    [_NUM] = LAYOUT_split_3x6_3_ex2(
  //,--------------------------------------------------------------.  ,--------------------------------------------------------------.
      _______, _______, _______, _______, _______, _______, _______,    _______, XXXXXXX,    KC_7,    KC_8,    KC_9, XXXXXXX, _______,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
      _______, _______, _______, _______, _______, _______, _______,    _______,    KC_0,    KC_4,    KC_5,    KC_6, KC_MINS, _______,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
      _______, _______, _______, _______, _______, _______,                        KC_DOT,    KC_1,    KC_2,    KC_3, _______, _______,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          _______, _______, _______,    _______, _______, _______
                                      //`--------------------------'  `--------------------------'
  ),

    [_SYM] = LAYOUT_split_3x6_3_ex2(
  //,--------------------------------------------------------------.  ,--------------------------------------------------------------.
      _______, KC_EXLM,   KC_AT, KC_HASH,  KC_DLR, KC_PERC, _______,    _______, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, _______,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
      _______,  KC_GRV, KC_TILD, KC_MINS, KC_UNDS,  KC_EQL, _______,    _______, KC_LBRC, KC_RBRC, KC_LCBR, KC_RCBR, KC_PIPE, _______,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
      _______, _______, _______, _______, _______, _______,                       KC_PLUS, KC_BSLS, _______, _______, _______, _______,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          _______, _______, _______,    _______, _______, _______
                                      //`--------------------------'  `--------------------------'
  ),

    [_TMUX] = LAYOUT_split_3x6_3_ex2(
  //,--------------------------------------------------------------.  ,--------------------------------------------------------------.
      XXXXXXX, XXXXXXX,  TM_WIN, XXXXXXX,  TM_RES, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  TM_PRV, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
      XXXXXXX,  TM_PFX,  TM_SAV,  TM_DET, XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX,   TM_MH,   TM_MJ,   TM_MK,   TM_ML, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, XXXXXXX,  TM_NEW, XXXXXXX, XXXXXXX,                       TM_NXT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          _______, _______, _______,    _______, _______, _______
                                      //`--------------------------'  `--------------------------'
  ),

    [_FUN] = LAYOUT_split_3x6_3_ex2(
  //,--------------------------------------------------------------.  ,--------------------------------------------------------------.
      XXXXXXX,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5, XXXXXXX,    XXXXXXX, RM_TOGG, RM_NEXT, RM_HUEU, RM_VALU, RM_VALD, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
      XXXXXXX,   KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10, XXXXXXX,    XXXXXXX, KC_MPLY, KC_VOLD, KC_VOLU, KC_MUTE, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
      XXXXXXX,  KC_F11,  KC_F12, XXXXXXX, XXXXXXX, XXXXXXX,                       OS_LIN,  OS_MAC, XXXXXXX, XXXXXXX, QK_BOOT, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          _______, _______, _______,    _______, _______, _______
                                      //`--------------------------'  `--------------------------'
  )
};

// Chordal hold handedness: thumbs are '*' so layer-taps work with same-hand keys;
// home-row mods still require an opposite-hand key to register as a hold.
const char chordal_hold_layout[MATRIX_ROWS][MATRIX_COLS] PROGMEM = LAYOUT_split_3x6_3_ex2(
    'L', 'L', 'L', 'L', 'L', 'L', 'L',    'R', 'R', 'R', 'R', 'R', 'R', 'R',
    'L', 'L', 'L', 'L', 'L', 'L', 'L',    'R', 'R', 'R', 'R', 'R', 'R', 'R',
    'L', 'L', 'L', 'L', 'L', 'L',              'R', 'R', 'R', 'R', 'R', 'R',
                   '*', '*', '*',    '*', '*', '*'
);

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (!record->event.pressed) {
        return true;
    }
    switch (keycode) {
        case TM_NEW: SEND_STRING(SS_LCTL("a") "c"); return false;
        case TM_NXT: SEND_STRING(SS_LCTL("a") "n"); return false;
        case TM_PRV: SEND_STRING(SS_LCTL("a") "p"); return false;
        case TM_WIN: SEND_STRING(SS_LCTL("a") "w"); return false;
        case TM_DET: SEND_STRING(SS_LCTL("a") "d"); return false;
        case TM_SAV: SEND_STRING(SS_LCTL("as")); return false;
        case TM_RES: SEND_STRING(SS_LCTL("ar")); return false;
        case TM_MH:  SEND_STRING(SS_LCTL("ah")); return false;
        case TM_MJ:  SEND_STRING(SS_LCTL("aj")); return false;
        case TM_MK:  SEND_STRING(SS_LCTL("ak")); return false;
        case TM_ML:  SEND_STRING(SS_LCTL("al")); return false;
        case TM_PFX: SEND_STRING(SS_LCTL("a")); return false;
        case OS_MAC: set_single_persistent_default_layer(_MAC); return false;
        case OS_LIN: set_single_persistent_default_layer(_LIN); return false;
    }
    return true;
}

bool process_detected_host_os_user(os_variant_t detected_os) {
    switch (detected_os) {
        case OS_MACOS:
        case OS_IOS:
            default_layer_set((layer_state_t)1 << _MAC);
            break;
        case OS_LINUX:
        case OS_WINDOWS:
            default_layer_set((layer_state_t)1 << _LIN);
            break;
        default:
            break;
    }
    return true;
}
