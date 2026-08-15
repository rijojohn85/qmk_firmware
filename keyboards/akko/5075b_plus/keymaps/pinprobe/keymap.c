// Temporary diagnostic keymap: finds which GPIOs the rotary encoder is wired to.
// Probes every pin not used by the key matrix and logs transitions to `qmk console`.

#include QMK_KEYBOARD_H

typedef struct {
    pin_t       pin;
    const char *name;
} probe_t;

static const probe_t probes[] = {
    {A5, "A5"},   {A7, "A7"},   {A8, "A8"},   {A9, "A9"},   {A15, "A15"},
    {B0, "B0"},   {B1, "B1"},   {B2, "B2"},   {B3, "B3"},   {B4, "B4"},
    {B5, "B5"},   {B6, "B6"},   {B7, "B7"},   {B8, "B8"},   {B9, "B9"},
    {B15, "B15"},
    {C4, "C4"},   {C5, "C5"},   {C10, "C10"}, {C11, "C11"}, {C12, "C12"},
    {C14, "C14"}, {C15, "C15"},
};

#define NUM_PROBES (sizeof(probes) / sizeof(probes[0]))

static uint8_t last_state[NUM_PROBES];

void keyboard_post_init_user(void) {
    debug_enable = true;
    for (uint8_t i = 0; i < NUM_PROBES; i++) {
        gpio_set_pin_input_high(probes[i].pin);
    }
    wait_ms(50);
    for (uint8_t i = 0; i < NUM_PROBES; i++) {
        last_state[i] = gpio_read_pin(probes[i].pin) ? 1 : 0;
    }
    uprintf("pinprobe ready: turn the knob\n");
}

void housekeeping_task_user(void) {
    static uint32_t last_scan = 0;
    if (timer_elapsed32(last_scan) < 1) return;
    last_scan = timer_read32();

    for (uint8_t i = 0; i < NUM_PROBES; i++) {
        uint8_t now = gpio_read_pin(probes[i].pin) ? 1 : 0;
        if (now != last_state[i]) {
            last_state[i] = now;
            uprintf("%s -> %u\n", probes[i].name, now);
        }
    }
}

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT(
        KC_ESC,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  QK_BOOT,  KC_MUTE,
        KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC,  KC_HOME,
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS,  KC_PGUP,
        KC_ESC,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,          KC_ENT,   KC_PGDN,
        KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,          KC_RSFT, KC_UP,    KC_END,
        KC_LCTL, KC_LGUI, KC_LALT,                   KC_SPC,                             KC_RALT, KC_RGUI,          KC_RCTL, KC_LEFT,  KC_DOWN, KC_RGHT),
};
