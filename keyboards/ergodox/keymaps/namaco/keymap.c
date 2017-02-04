#include "ergodox.h"
#include "debug.h"
#include "action_layer.h"
#include "version.h"

#define MAC     0  // default layer (for Mac)
#define WINDOWS 1  // default layer (for Windows)
#define MACFN   2  // mac functions
#define WINFN   3  // win functions
#define MOUSE   4  // mouse mode

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Keymap 0: MAC layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * | Esc    |   1  |   2  |   3  |   4  |   5  |  =   |           | `~   |   6  |   7  |   8  |   9  |   0  |   -    |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * | Tab    |   Q  |   W  |   E  |   R  |   T  |   [  |           |  ]   |   Y  |   U  |   I  |   O  |   P  |   \    |
 * |--------+------+------+------+------+------|   {  |           |  }   |------+------+------+------+------+--------|
 * | LGui   |   A  |   S  |   D  |   F  |   G  |------|           |------|   H  |   J  |   K  |   L  |   ;  |   '"   |
 * |--------+------+------+------+------+------| LGui+|           | LFn  |------+------+------+------+------+--------|
 * | LShift |   Z  |   X  |   C  |   V  |   B  | Space|           |      |   N  |   M  |   ,  |   .  |   /  | RShift |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |  cut | copy | paste| Left | Right|                                       |  Up  | Down |   [  |   ]  | LWin  |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        | CTRL | LAlt |       | Alt  |LMouse |
 *                                 ,------|------|------|       |------+-------+------.
 *                                 |      |      | Home |       | PgUp |       |      |
 *                                 |Space |Backsp|------|       |------| Delete| Enter|
 *                                 |      |ace   | End  |       | PgDn |       |      |
 *                                 `--------------------'       `---------------------'
 */
// If it accepts an argument (i.e, is a function), it doesn't need KC_.
// Otherwise, it needs KC_*
[MAC] = KEYMAP(  // layer 0 : default
        // left hand
        KC_ESC,         KC_1,         KC_2,        KC_3,      KC_4,   KC_5,   KC_EQL,
        KC_TAB,         KC_Q,         KC_W,        KC_E,      KC_R,   KC_T,   KC_LBRC,
        KC_LGUI,        KC_A,         KC_S,        KC_D,      KC_F,   KC_G,
        KC_LSFT,        KC_Z,         KC_X,        KC_C,      KC_V,   KC_B,   LGUI(KC_SPC),
        LGUI(KC_X),     LGUI(KC_C),   LGUI(KC_V),  KC_LEFT,   KC_RGHT,
                                                                      KC_LCTL,KC_LALT,
                                                                              KC_HOME,
                                                              KC_SPC, KC_BSPC,KC_END,
        // right hand
        KC_GRV,      KC_6,   KC_7,   KC_8,   KC_9,   KC_0,             KC_MINS,
        KC_LBRC,     KC_Y,   KC_U,   KC_I,   KC_O,   KC_P,             KC_BSLS,
                     KC_H,   KC_J,   KC_K,   KC_L,   KC_SCLN,          KC_QUOT,
        MO(MACFN),   KC_N,   KC_M,   KC_COMM,KC_DOT, KC_SLSH,          KC_RSFT,
                             KC_UP,  KC_DOWN,KC_LBRC,KC_RBRC,          TO(WINDOWS,1),
        KC_LALT,     TO(MOUSE,1),
        KC_PGUP,
        KC_PGDN,     KC_DELT,KC_ENT
    ),

/* Keymap 1: Windows layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * | Esc    |   1  |   2  |   3  |   4  |   5  |   =  |           |  `~  |   6  |   7  |   8  |   9  |   0  |   -    |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * | Tab    |   Q  |   W  |   E  |   R  |   T  |   [  |           |   ]  |   Y  |   U  |   I  |   O  |   P  |   \    |
 * |--------+------+------+------+------+------|   {  |           |   }  |------+------+------+------+------+--------|
 * | CTRL   |   A  |   S  |   D  |   F  |   G  |------|           |------|   H  |   J  |   K  |   L  |   ;  |   '"   |
 * |--------+------+------+------+------+------| LGui+|           | LFn  |------+------+------+------+------+--------|
 * | LShift |   Z  |   X  |   C  |   V  |   B  | Space|           |      |   N  |   M  |   ,  |   .  |   /  | RShift |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |  cut | copy | paste| Left | Right|                                       |  Up  | Down |   [  |   ]  | LMac |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        | LGui | LAlt |       | Alt  |LMouse |
 *                                 ,------|------|------|       |------+-------+------.
 *                                 |      |      | Home |       | PgUp |       |      |
 *                                 |Space |Backsp|------|       |------| Delete| Enter|
 *                                 |      |ace   | End  |       | PgDn |       |      |
 *                                 `--------------------'       `---------------------'
 */
// If it accepts an argument (i.e, is a function), it doesn't need KC_.
// Otherwise, it needs KC_*
[WINDOWS] = KEYMAP(  // layer 0 : default
        // left hand
        KC_ESC,         KC_1,         KC_2,         KC_3,       KC_4,   KC_5,   KC_EQL,
        KC_TAB,         KC_Q,         KC_W,         KC_E,       KC_R,   KC_T,   KC_LBRC,
        KC_LCTL,        KC_A,         KC_S,         KC_D,       KC_F,   KC_G,
        KC_LSFT,        KC_Z,         KC_X,         KC_C,       KC_V,   KC_B,   LALT(KC_GRV),
        LCTL(KC_X),     LCTL(KC_C),   LCTL(KC_V),   KC_LEFT,    KC_RGHT,
                                                                        KC_LGUI,    KC_LALT,
                                                                                    KC_HOME,
                                                                KC_SPC, KC_BSPC,    KC_END,
        // right hand
        KC_GRV,     KC_6,       KC_7,   KC_8,   KC_9,   KC_0,             KC_MINS,
        KC_RBRC,    KC_Y,       KC_U,   KC_I,   KC_O,   KC_P,             KC_BSLS,
                    KC_H,       KC_J,   KC_K,   KC_L,   KC_SCLN,          KC_QUOT,
        MO(WINFN),  KC_N,       KC_M,   KC_COMM,KC_DOT, KC_SLSH,          KC_RSFT,
                                KC_UP,  KC_DOWN,KC_LBRC,KC_RBRC,          TO(MAC,1),
        KC_LALT,    TO(MOUSE,1),
        KC_PGUP,
        KC_PGDN,    KC_DELT,    KC_ENT
    ),

/* Keymap 2: Mac function Layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |  F1  |  F2  |  F3  |  F4  |  F5  | F6   |           | F7   |  F8  |  F9  | F10  |  F11 |  F12 |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |      |      |      |      |S+⌘+3 |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        | ⌘+A  | ⌘+S  |      | ⌘+F  | ⌘+G  |------|           |------|      |      |      |      |      |        |
 * |--------+------+------+------+------+------|S+⌘+4 |           |      |------+------+------+------+------+--------|
 * |        | ⌘+Z  | ⌘+X  | ⌘+C  | ⌘+V  |      |      |           |      |      |      |      |      |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |      |      |      |      |LMouse|
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      | Mute |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |⌘+S+A |A+Ent |------|       |------| Vol- | Vol+ |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
/*
 * This layer contains IntelliJ shortcuts.
 */
// Fnctions
[MACFN] = KEYMAP(
       // left hand
       KC_TRNS,       KC_F1,      KC_F2,       KC_F3,       KC_F4,      KC_F5,   KC_F6,
       KC_TRNS,     KC_TRNS,      KC_TRNS,     KC_TRNS,     KC_TRNS,    KC_TRNS, LGUI(LSFT(KC_３)),
       KC_TRNS,     LGUI(KC_A),   LGUI(KC_S),  KC_TRNS,     LGUI(KC_F), LGUI(KC_G),
       KC_TRNS,     LGUI(KC_Z),   LGUI(KC_X),  LGUI(KC_C),  LGUI(KC_V), KC_TRNS, LGUI(LSFT(KC_４)),
       KC_TRNS,     KC_TRNS,      KC_TRNS,     KC_TRNS,     KC_TRNS,
                                                                        KC_TRNS, KC_TRNS,
                                                                                 KC_TRNS,
                                                  LGUI(LSFT(KC_A)), LALT(KC_ENT),KC_TRNS,
       // right hand
       KC_F7,     KC_F8,   KC_F9,  KC_F10,  KC_F11,  KC_F12,  KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS,
                KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS,
                KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  TO(MOUSE,1),
       KC_TRNS, KC_MUTE,
       KC_TRNS,
       KC_TRNS, KC_VOLD, KC_VOLU
    ),

/* Keymap 3: Function Layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |  F1  |  F2  |  F3  |  F4  |  F5  | F6   |           | F7   |  F8  |  F9  | F10  |  F11 |  F12 |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |      |W+C+←|W+C+→|      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+------| PRSC |           |      |------+------+------+------+------+--------|
 * |  LGui  |      |      | W+d  |      |      |------|           |------|      |      |      |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |W+PRSC|A+PRSC|           |      |      |      |      |      |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      | W+← | W+↓ | W+↑ | W+→ |                                       |      |      |      |      |LMouse|
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      | Mute |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |⌘+S+A |A+Ent |------|       |------| Vol- | Vol+ |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
/*
 * This layer contains IntelliJ shortcuts.
 */
// Fnctions
[WINFN] = KEYMAP(
       // left hand
       KC_TRNS,       KC_F1,         KC_F2,       KC_F3,               KC_F4,                KC_F5,         KC_F6,
       KC_TRNS,       KC_TRNS,       KC_TRNS,     LGUI(LCTL(KC_LEFT)), LGUI(LCTL(KC_RIGHT)), KC_TRNS,       KC_PSCR,
       KC_LGUI,       KC_TRNS,       KC_TRNS,     LGUI(KC_D),          KC_TRNS,              KC_TRNS,
       KC_TRNS,       KC_TRNS,       KC_TRNS,     KC_TRNS,             KC_TRNS,              LGUI(KC_PSCR), LALT(KC_PSCR),
       KC_TRNS,       KC_TRNS,       KC_TRNS,     KC_TRNS,             KC_TRNS,
                                                                                             KC_TRNS,       KC_TRNS,
                                                                                                            KC_TRNS,
                                                                       LCTL(LSFT(KC_A)),     LALT(KC_ENT),  KC_TRNS,
       // right hand
       KC_F7,     KC_F8,   KC_F9,  KC_F10,  KC_F11,  KC_F12,  KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS,
                KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS,
                KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  TO(MOUSE,1),
       KC_TRNS, KC_MUTE,
       KC_TRNS,
       KC_TRNS, KC_VOLD, KC_VOLU
    ),

/* Keymap 4: Mouse Layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |  RESET |  F1  |  F2  |  F3  |  F4  |  F5  | F6   |           | F7   |  F8  |  F9  | F10  |  F11 |  F12 |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      | M-Up |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|      |           | LMac |------+------+------+------+------+--------|
 * |        |  M-L | M-Dn | M-R  |      |      |------|           |------|      |      |      |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           | LWin |      |      |      |      |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      | WH-L | WH-R |                                       | Sp+2 | Sp+1 | Sp+0 |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       | M2   |MClick|
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       | PgUp |      |      |
 *                                 |Space |Enter |------|       |------|RClick|LClick|
 *                                 |      |      |      |       | PgDn |      |      |
 *                                 `--------------------'       `--------------------'
 */
// Mouse
[MOUSE] = KEYMAP(
       // left hand
       RESET,       KC_F1,      KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,
       KC_TRNS,     KC_TRNS,    KC_MS_U, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS,     KC_MS_L,    KC_MS_D, KC_MS_R, KC_TRNS, KC_TRNS,
       KC_TRNS,     KC_TRNS,    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS,     KC_TRNS,    KC_TRNS, KC_WH_L, KC_WH_R,
                                                            KC_TRNS, KC_TRNS,
                                                                     KC_TRNS,
                                                     KC_SPC, KC_ENT, KC_TRNS,
       // right hand
       KC_F7,           KC_F8,   KC_F9,  KC_F10,  KC_F11,  KC_F12,  KC_TRNS,
       TO(MAC,1),     KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS,
                      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS,
       TO(WINDOWS,1), KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS,
                      KC_ACL2, KC_ACL1, KC_ACL0, KC_TRNS,  KC_TRNS,
       KC_BTN4, KC_BTN3,
       KC_PGUP,
       KC_PGDN, KC_BTN1, KC_BTN2
    ),
};

const uint16_t PROGMEM fn_actions[] = {
    [1] = ACTION_LAYER_TAP_TOGGLE(MACFN),
    [2] = ACTION_LAYER_TAP_TOGGLE(WINFN)    // FN1,2 - Momentary Layer 1,2 (functions)
};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
    // MACRODOWN only works in this function
    switch(id) {
        case 0:
            if (record->event.pressed) {
                register_code(KC_RSFT);
            } else {
                unregister_code(KC_RSFT);
            }
            break;
    }
    return MACRO_NONE;
};

// Runs just one time when the keyboard initializes.
void matrix_init_user(void) {
    ergodox_board_led_off();
    ergodox_right_led_1_on();
    ergodox_right_led_2_on();
    ergodox_right_led_3_on();
    ergodox_board_led_off();
    ergodox_right_led_1_on();
    ergodox_right_led_2_on();
    ergodox_right_led_3_on();
    ergodox_board_led_off();
};

// Runs constantly in the background, in a loop.
void matrix_scan_user(void) {

    uint8_t layer = biton32(layer_state);

    ergodox_board_led_off();
    ergodox_right_led_1_off();
    ergodox_right_led_2_off();
    ergodox_right_led_3_off();
    switch (layer) {
      // TODO: Make this relevant to the ErgoDox EZ.
        case MAC:
            ergodox_right_led_1_on();
            break;
        case WINDOWS:
            ergodox_right_led_2_on();
            break;
        case MACFN:
            ergodox_right_led_1_on();
            ergodox_right_led_2_off();
            ergodox_right_led_3_on();
            break;
        case WINFN:
            ergodox_right_led_1_off();
            ergodox_right_led_2_on();
            ergodox_right_led_3_on();
            break;
        case MOUSE:
            ergodox_led_all_on();
            break;
        default:
            // none
            break;
    }

};
