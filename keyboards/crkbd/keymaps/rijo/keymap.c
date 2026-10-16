// rijo's Corne v4.1 keymap
// Layers: LIN/MAC bases (home-row mods, Ctrl<->Cmd swapped), NAV, NUM, SYM, TMUX, FUN.
// OS detection picks the base layer on plug-in; manual override on FUN layer.

#include QMK_KEYBOARD_H
#include "transactions.h"

enum layers {
    _LIN,  // Linux / Windows base
    _MAC,  // macOS base
    _NAV,
    _NUM,
    _SYM,
    _TMUX,
    _FUN,
};

enum tap_dance_codes {
    TD_COLN_ASSIGN, // tap: :   double-tap: :=  (Go short var decl)
    TD_EXL_NEQ,     // tap: !   double-tap: !=
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
    TM_W0,               // C-a 0   window 0
    TM_W1,               // C-a 1   window 1
    TM_W2,               // C-a 2   window 2
    TM_W3,               // C-a 3   window 3
    TM_W4,               // C-a 4   window 4
    TM_W5,               // C-a 5   window 5
    TM_W6,               // C-a 6   window 6
    TM_W7,               // C-a 7   window 7
    TM_W8,               // C-a 8   window 8
    TM_W9,               // C-a 9   window 9
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
#define TH_NAV LT(_NAV, KC_TAB)
#define TH_NUM LT(_NUM, KC_ENT)
#define TH_SYM LT(_SYM, KC_SPC)
#define TH_DEL LT(_FUN, KC_DEL)

#define OSL_TM OSL(_TMUX)
#define OSM_SFT OSM(MOD_LSFT)
#define TD_ASGN TD(TD_COLN_ASSIGN)
#define TD_EXL  TD(TD_EXL_NEQ)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_LIN] = LAYOUT_split_3x6_3_ex2(
  //,--------------------------------------------------------------.  ,--------------------------------------------------------------.
       KC_TAB,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T, CW_TOGG,    KC_MUTE,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P, KC_BSPC,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
      KC_LCTL,     L_A,     L_S,     L_D,     L_F,    KC_G,  OSL_TM,     OSL_TM,    KC_H,     L_J,     L_K,     L_L,  L_SCLN, KC_QUOT,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
      KC_LSFT,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                          KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH, KC_MINS,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                           TH_ESC,  TH_NAV,  TH_NUM,     TH_SYM, KC_BSPC,  TH_DEL
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
                                           TH_ESC,  TH_NAV,  TH_NUM,     TH_SYM, KC_BSPC,  TH_DEL
                                      //`--------------------------'  `--------------------------'
  ),

    [_NAV] = LAYOUT_split_3x6_3_ex2(
  //,--------------------------------------------------------------.  ,--------------------------------------------------------------.
      _______, LALT(KC_1), LALT(KC_2), LALT(KC_3), LALT(KC_4), LALT(KC_5), _______,    _______, LALT(KC_6), LALT(KC_7), LALT(KC_8), LALT(KC_9),  KC_DEL, _______,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
      _______, _______, _______, _______, OSM_SFT, _______, _______,    _______, KC_LEFT, KC_DOWN,   KC_UP, KC_RGHT, XXXXXXX, _______,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
      _______, _______, _______, _______, _______, _______,                       KC_HOME, KC_PGDN, KC_PGUP,  KC_END, XXXXXXX, _______,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          _______, _______, _______,    _______, _______, _______
                                      //`--------------------------'  `--------------------------'
  ),

    // Numpad + operators on the right (held by left thumb); left half stays
    // transparent so home-row mods work. G = Layer Lock for long number runs.
    [_NUM] = LAYOUT_split_3x6_3_ex2(
  //,--------------------------------------------------------------.  ,--------------------------------------------------------------.
      _______, _______, _______, _______, _______, _______, _______,    _______, KC_SLSH,    KC_7,    KC_8,    KC_9, KC_ASTR, _______,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
      _______, _______, _______, _______, _______, QK_LLCK, _______,    _______,    KC_0,    KC_4,    KC_5,    KC_6, KC_MINS, KC_PLUS,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
      _______, _______, _______, _______, _______, _______,                        KC_DOT,    KC_1,    KC_2,    KC_3,  KC_EQL, KC_COMM,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          _______, _______, _______,    _______, _______, _______
                                      //`--------------------------'  `--------------------------'
  ),

    // Symbols on the left hand (held by right thumb), shifted symbols included
    // so Shift is never needed here. Right home row stays transparent (mods);
    // the few extras on the right sit on the base key they shift: : ? "
    [_SYM] = LAYOUT_split_3x6_3_ex2(
  //,--------------------------------------------------------------.  ,--------------------------------------------------------------.
      KC_TILD,  TD_EXL,   KC_AT, KC_HASH,  KC_DLR, KC_PERC, KC_CIRC,    _______, _______, _______, _______, _______, TD_ASGN, _______,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
       KC_GRV,   KC_LT,   KC_GT, KC_LPRN, KC_RPRN,  KC_EQL, KC_AMPR,    _______, _______, _______, _______, _______, _______, KC_DQUO,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
      KC_BSLS, KC_LBRC, KC_RBRC, KC_LCBR, KC_RCBR, KC_PIPE,                       _______, _______, _______, _______, KC_QUES, _______,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_UNDS, KC_ASTR, KC_PLUS,    _______, _______, _______
                                      //`--------------------------'  `--------------------------'
  ),

    [_TMUX] = LAYOUT_split_3x6_3_ex2(
  //,--------------------------------------------------------------.  ,--------------------------------------------------------------.
      XXXXXXX,  TM_W0,   TM_W1,   TM_W2,   TM_W3,   TM_W4, XXXXXXX,    XXXXXXX,   TM_W5,   TM_W6,   TM_W7,   TM_W8,   TM_W9, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
      XXXXXXX,  TM_PFX,  TM_SAV,  TM_DET,  TM_WIN,  TM_RES, XXXXXXX,    XXXXXXX,   TM_MH,   TM_MJ,   TM_MK,   TM_ML, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, XXXXXXX,  TM_NEW, XXXXXXX, XXXXXXX,                       TM_NXT,  TM_PRV, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
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

void td_coln_assign_finished(tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
        tap_code16(KC_COLN);
    } else {
        SEND_STRING(":=");
    }
}

void td_exl_neq_finished(tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
        tap_code16(KC_EXLM);
    } else {
        SEND_STRING("!=");
    }
}

tap_dance_action_t tap_dance_actions[] = {
    [TD_COLN_ASSIGN] = ACTION_TAP_DANCE_FN(td_coln_assign_finished),
    [TD_EXL_NEQ]     = ACTION_TAP_DANCE_FN(td_exl_neq_finished),
};

// Base-layer letter combos for bracket pairs and comparison operators, so
// they're reachable without holding SYM. Non-overlapping key pairs (each
// letter used in only one combo) to keep detection unambiguous. Kept off
// J/K/L/; on purpose - those are home-row mod-tap keys, and QMK resolving
// their tap/hold state fights with combo detection, so they never fire.
enum combos {
    CM_BRACE,
    CM_PAREN,
    CM_BRACKET,
    CM_NEQ,
    CM_ASSIGN,
    COMBO_LENGTH
};
uint16_t COMBO_LEN = COMBO_LENGTH;

const uint16_t PROGMEM brace_combo[]   = {KC_Q, KC_W, COMBO_END};
const uint16_t PROGMEM paren_combo[]   = {KC_E, KC_R, COMBO_END};
const uint16_t PROGMEM bracket_combo[] = {KC_U, KC_I, COMBO_END};
const uint16_t PROGMEM neq_combo[]     = {KC_M, KC_COMM, COMBO_END};
const uint16_t PROGMEM assign_combo[]  = {KC_DOT, KC_SLSH, COMBO_END};

combo_t key_combos[] = {
    [CM_BRACE]   = COMBO_ACTION(brace_combo),
    [CM_PAREN]   = COMBO_ACTION(paren_combo),
    [CM_BRACKET] = COMBO_ACTION(bracket_combo),
    [CM_NEQ]     = COMBO_ACTION(neq_combo),
    [CM_ASSIGN]  = COMBO_ACTION(assign_combo),
};

void process_combo_event(uint16_t combo_index, bool pressed) {
    if (!pressed) return;
    switch (combo_index) {
        case CM_BRACE:   SEND_STRING("{}" SS_TAP(X_LEFT)); break;
        case CM_PAREN:   SEND_STRING("()" SS_TAP(X_LEFT)); break;
        case CM_BRACKET: SEND_STRING("[]" SS_TAP(X_LEFT)); break;
        case CM_NEQ:     SEND_STRING("!="); break;
        case CM_ASSIGN:  SEND_STRING(":="); break;
    }
}

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
        case TM_W0:  SEND_STRING(SS_LCTL("a") "0"); return false;
        case TM_W1:  SEND_STRING(SS_LCTL("a") "1"); return false;
        case TM_W2:  SEND_STRING(SS_LCTL("a") "2"); return false;
        case TM_W3:  SEND_STRING(SS_LCTL("a") "3"); return false;
        case TM_W4:  SEND_STRING(SS_LCTL("a") "4"); return false;
        case TM_W5:  SEND_STRING(SS_LCTL("a") "5"); return false;
        case TM_W6:  SEND_STRING(SS_LCTL("a") "6"); return false;
        case TM_W7:  SEND_STRING(SS_LCTL("a") "7"); return false;
        case TM_W8:  SEND_STRING(SS_LCTL("a") "8"); return false;
        case TM_W9:  SEND_STRING(SS_LCTL("a") "9"); return false;
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

// Flow Tap forces fast mod-taps to tap, which eats capitals typed mid-flow
// ("the Corne" -> "the fcorne") and turns quick SYM holds into spaces.
// Exempt the home-row shifts (same keycodes on LIN and MAC) and the SYM thumb.
uint16_t get_flow_tap_term(uint16_t keycode, keyrecord_t *record, uint16_t prev_keycode) {
    switch (keycode) {
        case L_F:
        case L_J:
        case TH_SYM:
            return 0;
    }
    if (is_flow_tap_key(keycode) && is_flow_tap_key(prev_keycode)) {
        return FLOW_TAP_TERM;
    }
    return 0;
}

// RGB indicators: Caps Word lights the alpha keys, a locked NUM layer lights
// the NUM layer's keys. The master owns both states, so it syncs them to the
// other half over a custom split transaction.
enum indicator_flags {
    IND_CAPS_WORD = 1 << 0,
    IND_NUM_LOCK  = 1 << 1,
};
static uint8_t indicator_state = 0;

static void sync_indicators_slave(uint8_t in_len, const void *in_data, uint8_t out_len, void *out_data) {
    if (in_len == sizeof(indicator_state)) {
        indicator_state = *(const uint8_t *)in_data;
    }
}

void keyboard_post_init_user(void) {
    transaction_register_rpc(USER_SYNC_INDICATORS, sync_indicators_slave);
}

void housekeeping_task_user(void) {
    if (!is_keyboard_master()) {
        return;
    }
    indicator_state = (is_caps_word_on() ? IND_CAPS_WORD : 0) | (is_layer_locked(_NUM) ? IND_NUM_LOCK : 0);

    // Send on change, plus a periodic resend in case the slave missed one.
    static uint8_t  last_sent = 0xFF;
    static uint32_t last_sync = 0;
    if (indicator_state != last_sent || timer_elapsed32(last_sync) > 500) {
        if (transaction_rpc_send(USER_SYNC_INDICATORS, sizeof(indicator_state), &indicator_state)) {
            last_sent = indicator_state;
            last_sync = timer_read32();
        }
    }
}

static uint16_t tap_keycode(uint16_t keycode) {
    if (IS_QK_MOD_TAP(keycode)) return QK_MOD_TAP_GET_TAP_KEYCODE(keycode);
    if (IS_QK_LAYER_TAP(keycode)) return QK_LAYER_TAP_GET_TAP_KEYCODE(keycode);
    return keycode;
}

static void set_indicator(uint8_t led, uint8_t hue) {
    rgb_t rgb = hsv_to_rgb((hsv_t){hue, 255, rgb_matrix_get_val()});
    rgb_matrix_set_color(led, rgb.r, rgb.g, rgb.b);
}

bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
    if (!indicator_state) {
        return false;
    }
    for (uint8_t row = 0; row < MATRIX_ROWS; ++row) {
        for (uint8_t col = 0; col < MATRIX_COLS; ++col) {
            uint8_t led = g_led_config.matrix_co[row][col];
            if (led == NO_LED || led < led_min || led >= led_max) {
                continue;
            }
            keypos_t pos = {.row = row, .col = col};
            if (indicator_state & IND_NUM_LOCK) {
                // NUM-only keys: numpad, operators and the lock key itself
                uint16_t kc = keymap_key_to_keycode(_NUM, pos);
                if (kc != KC_TRNS && kc != KC_NO) {
                    set_indicator(led, 170); // blue
                    continue;
                }
            }
            if (indicator_state & IND_CAPS_WORD) {
                // LIN and MAC share alpha positions, so _LIN works on both
                uint16_t kc = tap_keycode(keymap_key_to_keycode(_LIN, pos));
                if (kc >= KC_A && kc <= KC_Z) {
                    set_indicator(led, 21);  // orange
                }
            }
        }
    }
    return false;
}
