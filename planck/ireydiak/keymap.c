/* Copyright 2015-2023 Jack Humbert
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

enum planck_layers {
    _QWERTY,
    _LOWER,
    _RAISE,
    _ADJUST
};

enum planck_keycodes { QWERTY = SAFE_RANGE, BACKLIT, EXT_PLV, OS_SWAP };


// ┌─────────────────────────────────────────────────┐
// │ d e f i n e   m a c r o n a m e s               │
// └─────────────────────────────────────────────────┘
// LEFT HAND HOME ROW MODS ├──────────────────┐
#define GUI_A LGUI_T(KC_A)
#define ALT_S LALT_T(KC_S)
#define CTL_D LCTL_T(KC_D)
#define SHT_F LSFT_T(KC_F)

// RIGHT HAND HOME ROW MODS ├─────────────────┐
#define SHT_J RSFT_T(KC_J)
#define CTL_K LCTL_T(KC_K)
#define ALT_L LALT_T(KC_L)
#define GUI_SCLN LGUI_T(KC_SCLN)

// RIGHT HAND MOVEMENT MODS ├─────────────────┐
#define CLEFT LCTL_T(KC_LEFT)
#define CDOWN LCTL_T(KC_DOWN)
#define CUP LCTL_T(KC_UP)
#define CRIGHT LCTL_T(KC_RIGHT)

#define ADJUST MO(_ADJUST)
#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)

/* clang-format off */
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 * ,-----------------------------------------------------------------------------------.
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Esc  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  '   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl | GUI  |  Alt | Esc  |Lower |    Space    | Raise| Del  | CAPS |   |  |  `   |
 * `-----------------------------------------------------------------------------------'
 */
[_QWERTY] = LAYOUT_planck_grid(
    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,     KC_BSPC,
    KC_ESC,  GUI_A,   ALT_S,   CTL_D,   SHT_F,   KC_G,    KC_H,    SHT_J,   CTL_K,   ALT_L,   GUI_SCLN, KC_QUOT,
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,  KC_ENT,
    KC_LCTL, KC_LGUI, KC_LALT, KC_ESC,  LOWER,   KC_SPC,  KC_SPC,  RAISE,   KC_DEL,  KC_CAPS, KC_PIPE,  KC_GRV
),


/* Lower
 * ,-----------------------------------------------------------------------------------.
 * |   ~  |   !  |   @  |   #  |   $  |   %  |   ^  |   &  |   *  |   (  |   )  | Del  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |   +  │  _   │   -  │   =  |   ~  │   (  │      |   {  |  }   |   :  |  "   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |   \  |  |   |   <  |   >  |   ?  |   <  |   >  |   [  |  ]   |      |  ?   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |  |   |  ~   |
 * `-----------------------------------------------------------------------------------'
 */
[_LOWER] = LAYOUT_planck_grid(
    _______, KC_EXLM, KC_AT,   KC_HASH,       KC_DLR,        KC_PERC,       KC_CIRC,      KC_AMPR,       KC_ASTR, KC_LPRN,      KC_RPRN,       KC_BSPC,
    _______, KC_PPLS, KC_UNDS, KC_PMNS,       KC_EQL,        LSFT(KC_GRV),  _______,      _______,       KC_LCBR, KC_RCBR,      LSFT(KC_SCLN), LSFT(KC_QUOT),
    _______, KC_BSLS, KC_PIPE, LSFT(KC_COMM), LSFT(KC_DOT),  LSFT(KC_SLSH), LSFT(KC_COMM),LSFT(KC_DOT),  KC_LBRC, KC_RBRC,      LSFT(KC_SLSH), _______,
    _______, _______, _______, _______,        _______,      _______,       _______,       _______,      _______, _______,      _______,       LSFT(KC_GRV)
),

/* Raise
 * ,-----------------------------------------------------------------------------------.
 * |      |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Del  |   +  │   _  │  -   │   =  |  {   |  ←  │  ↓  │  ↑  │  →  |   }  |  |   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |ISO # |ISO / |Pg Up |Pg Dn |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      | Next | Vol- | Vol+ | Play |
 * `-----------------------------------------------------------------------------------'
 */
[_RAISE] = LAYOUT_planck_grid(
    KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,     KC_0,    KC_BSPC,
    KC_DEL,  KC_PPLS, KC_UNDS, KC_PMNS, KC_EQL,  KC_LBRC, KC_LEFT, KC_DOWN, KC_UP,   KC_RIGHT, KC_RBRC, KC_BSLS,
    _______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_NUHS, KC_COMM, KC_DOT,   KC_SLSH, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, KC_MNXT, KC_VOLD,  KC_VOLU, KC_MPLY
),

/* Adjust (Lower + Raise)
 *                      v------------------------RGB CONTROL--------------------v
 * ,-----------------------------------------------------------------------------------.
 * |      | Reset|Debug | RGB  |RGBMOD| HUE+ | HUE- | SAT+ | SAT- |BRGTH+|BRGTH-|  Del |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |MUSmod|Aud on|Audoff|AGnorm|AGswap|Qwerty|Colemk|Dvorak|Plover|      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |Voice-|Voice+|Mus on|Musoff|MIDIon|MIDIof|      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             | Prev | Next | Vol- | Vol+ | Play |
 * `-----------------------------------------------------------------------------------'
 */
[_ADJUST] = LAYOUT_planck_grid(
    _______, QK_BOOT, DB_TOGG, RGB_TOG, RGB_MOD, RGB_HUI, RGB_HUD, RGB_SAI, RGB_SAD, RGB_VAI, RGB_VAD, OS_SWAP,
    _______, OS_SWAP, MU_NEXT, AU_ON,   AU_OFF,  AG_NORM, AG_SWAP, _______,  _______, _______,  _______,  _______,
    _______, AU_PREV, AU_NEXT, MU_ON,   MU_OFF,  MI_ON,   MI_OFF,  _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, KC_MPRV, KC_MNXT, KC_VOLD,  KC_VOLU, KC_MPLY
),

};


///┌─────────────────────────────────────────────────┐
// │ c o m b o s                                     │
// └─────────────────────────────────────────────────┘
enum combos {
    WQ_VIM_SAVE_EXIT,
    JK_ARROW_FN,
};

const uint16_t PROGMEM vim_save_exit_combo[] = {KC_W, KC_Q, COMBO_END};
const uint16_t PROGMEM arrow_fn_combo[] = {KC_J, KC_K, COMBO_END};

combo_t key_combos[] = {
    [WQ_VIM_SAVE_EXIT]    = COMBO_ACTION(vim_save_exit_combo),
    [JK_ARROW_FN]         = COMBO_ACTION(arrow_fn_combo),
};


void process_combo_event(uint16_t combo_index, bool pressed) {
    switch(combo_index) {
        case WQ_VIM_SAVE_EXIT:
            if (pressed) {
                tap_code16(KC_ESC);
                tap_code16(KC_COLON);
                tap_code16(KC_W);
                tap_code16(KC_Q);
            }
            break;
        case JK_ARROW_FN:
            if (pressed) {
                // send character sequence ()
                tap_code16(KC_LSFT);
                tap_code16(KC_9);
                tap_code16(KC_0);
                tap_code16(KC_LSFT);
                // send empty space
                tap_code16(KC_SPC);
                // send character sequence {}
                tap_code16(KC_LSFT);
                tap_code16(KC_LBRC);
                tap_code16(KC_RBRC);
                tap_code16(KC_LSFT);
                // move cursor between parantheses
                tap_code16(KC_LEFT);
                tap_code16(KC_LEFT);
                tap_code16(KC_LEFT);
            }
    }
}
/* clang-format on */

#ifdef AUDIO_ENABLE
float plover_song[][2]    = SONG(PLOVER_SOUND);
float plover_gb_song[][2] = SONG(PLOVER_GOODBYE_SOUND);
#endif

layer_state_t layer_state_set_user(layer_state_t state) {
    return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case OS_SWAP:
            if (record->event.pressed) {
                if (!keymap_config.swap_lctl_lgui) {
                  keymap_config.swap_lctl_lgui = true;  // ─── MAC
                }
                else {
                  keymap_config.swap_lctl_lgui = false; // ─── WIN
                }
                eeconfig_update_keymap(keymap_config.raw);
                clear_keyboard();  // ──── clear to prevent stuck keys
                return false;
            }
        case BACKLIT:
            if (record->event.pressed) {
                register_code(KC_RSFT);
            } else {
                unregister_code(KC_RSFT);
            }
            return false;
            break;
    }
    return true;
}

/* clang-format off */
float melody[8][2][2] = {
    {{440.0f, 8}, {440.0f, 24}},
    {{440.0f, 8}, {440.0f, 24}},
    {{440.0f, 8}, {440.0f, 24}},
    {{440.0f, 8}, {440.0f, 24}},
    {{440.0f, 8}, {440.0f, 24}},
    {{440.0f, 8}, {440.0f, 24}},
    {{440.0f, 8}, {440.0f, 24}},
    {{440.0f, 8}, {440.0f, 24}},
};
/* clang-format on */

#define JUST_MINOR_THIRD 1.2
#define JUST_MAJOR_THIRD 1.25
#define JUST_PERFECT_FOURTH 1.33333333
#define JUST_TRITONE 1.42222222
#define JUST_PERFECT_FIFTH 1.33333333

#define ET12_MINOR_SECOND 1.059463
#define ET12_MAJOR_SECOND 1.122462
#define ET12_MINOR_THIRD 1.189207
#define ET12_MAJOR_THIRD 1.259921
#define ET12_PERFECT_FOURTH 1.33484
#define ET12_TRITONE 1.414214
#define ET12_PERFECT_FIFTH 1.498307

deferred_token tokens[8];

uint32_t reset_note(uint32_t trigger_time, void *note) {
    *(float*)note = 440.0f;
    return 0;
}

bool encoder_update_user(uint8_t index, bool clockwise) {
    cancel_deferred_exec(tokens[index]);
    if (clockwise) {
        melody[index][1][0] = melody[index][1][0] * ET12_MINOR_SECOND;
        melody[index][0][0] = melody[index][1][0] / ET12_PERFECT_FIFTH;
        audio_play_melody(&melody[index], 2, false);
    } else {
        melody[index][1][0] = melody[index][1][0] / ET12_MINOR_SECOND;
        melody[index][0][0] = melody[index][1][0] * ET12_TRITONE;
        audio_play_melody(&melody[index], 2, false);
    }
    tokens[index] = defer_exec(1000, reset_note, &melody[index][1][0]);
    return false;
}

bool dip_switch_update_user(uint8_t index, bool active) {
    switch (index) {
        case 0: {
#ifdef AUDIO_ENABLE
            static bool play_sound = false;
#endif
            if (active) {
#ifdef AUDIO_ENABLE
                if (play_sound) {
                    PLAY_SONG(plover_song);
                }
#endif
                layer_on(_ADJUST);
            } else {
#ifdef AUDIO_ENABLE
                if (play_sound) {
                    PLAY_SONG(plover_gb_song);
                }
#endif
                layer_off(_ADJUST);
            }
#ifdef AUDIO_ENABLE
            play_sound = true;
#endif
            break;
        }
    }
    return true;
}
