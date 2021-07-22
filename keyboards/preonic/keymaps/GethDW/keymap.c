#include QMK_KEYBOARD_H
#include <keymap_uk.h>
#include "config.h"

#define NOP XXXXXXX
#define LAYOUT_BOTTOM(k1,k2,k3,k4,k5,k6,k7,k8,k9,k10,k11,k12) \
    { k1, k2, k3, k10, k11, k12 }, \
    { k7, k8, k9, k4,  k5,  k6 }
#define LAYOUT_gethdw( \
    k00, k01, k02, k03, k04, k05, k06, k07, k08, k09, k0a, k0b, \
    k10, k11, k12, k13, k14, k15, k16, k17, k18, k19, k1a, k1b, \
    k20, k21, k22, k23, k24, k25, k26, k27, k28, k29, k2a, k2b, \
    k30, k31, k32, k33, k34, k35, k36, k37, k38, k39, k3a, k3b  ) { \
    { k00, k01, k02, k03, k04, k05 },{ k10, k11, k12, k13, k14, k15 }, \
    { k20, k21, k22, k23, k24, k25 },{ k30, k31, k32, k33, k34, k35 }, \
    { k06, k07, k08, k09, k0a, k0b },{ k16, k17, k18, k19, k1a, k1b }, \
    { k26, k27, k28, k29, k2a, k2b },{ k36, k37, k38, k39, k3a, k3b }, \
    DEFAULT_BOTTOM }

enum preonic_layers {
  _QWERTY,
  _REST,
  _FUNC,
};

enum preonic_keycodes {
  CKC_REST = SAFE_RANGE,
  CKC_FUNC,
};

const uint32_t PROGMEM unicode_map[] = {
    [0] = 0x203D,  // ‽
};

/* Bottom Row
 * ,-----------------------------------------------------------------------------------.
 * | Ctrl | Win  | Alt  | Func | Rest | Space| Space| Shift|      | Alt  | Win  | Ctrl |
 * `-----------------------------------------------------------------------------------' */
#define DEFAULT_BOTTOM LAYOUT_BOTTOM( KC_LCTL, KC_LGUI, KC_LALT, CKC_FUNC, CKC_REST, KC_SPC, KC_SPC, KC_RSFT, NOP, KC_RALT, KC_RGUI, KC_RCTL )

const uint16_t PROGMEM keymaps[3][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 * ,-----------------------------------------------------------------------------------.
 * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Del  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Esc  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |   '  |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  | Enter|
 * `-----------------------------------------------------------------------------------' */
[_QWERTY] = LAYOUT_gethdw(
  UK_GRV,  UK_1, UK_2, UK_3, UK_4, UK_5, UK_6, UK_7, UK_8,    UK_9,   UK_0,    KC_DEL,
  KC_TAB,  UK_Q, UK_W, UK_E, UK_R, UK_T, UK_Y, UK_U, UK_I,    UK_O,   UK_P,    KC_BSPC,
  KC_ESC,  UK_A, UK_S, UK_D, UK_F, UK_G, UK_H, UK_J, UK_K,    UK_L,   UK_SCLN, KC_QUOT,
  KC_LSFT, UK_Z, UK_X, UK_C, UK_V, UK_B, UK_N, UK_M, KC_COMM, KC_DOT, KC_SLSH, KC_ENT
),

/* Rest
 * ,-----------------------------------------------------------------------------------.
 * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Del  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   -  |   =  |   [  |   ]  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Esc  |   !  |   "  |   £  |   $  |   %  |   ^  |   &  |   *  |   (  |   )  |   #  |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   \  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  | Enter|
 * `-----------------------------------------------------------------------------------' */
[_REST] = LAYOUT_gethdw(
  UK_GRV,  UK_1,    UK_2,    UK_3,    UK_4,    UK_5,    UK_6,    UK_7,    UK_8,    UK_9,    UK_0,    KC_DEL,
  KC_TAB,  UK_Q,    UK_W,    UK_E,    UK_R,    UK_T,    UK_Y,    UK_MINS, UK_EQL,  UK_LBRC, UK_RBRC, KC_BSPC,
  KC_ESC,  S(UK_1), S(UK_2), S(UK_3), S(UK_4), S(UK_5), S(UK_6), S(UK_7), S(UK_8), S(UK_9), S(UK_0), UK_HASH,
  KC_LSFT, UK_BSLS, UK_X,    UK_C,    UK_V,    UK_B,    UK_N,    UK_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_ENT
),

/* Func
 * ,-----------------------------------------------------------------------------------.
 * | F1   | F2   | F3   | F4   | F5   | F6   | F7   | F8   | F9   | F10  | F12  | F12  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Caps |   A  |   S  |   D  |   F  |   G  |  <-  |  \/  |  /\  |  ->  |   ;  |   '  |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  | Enter|
 * `-----------------------------------------------------------------------------------' */
[_FUNC] = LAYOUT_gethdw(
  KC_F1,   KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7,   KC_F8,   KC_F9,   KC_F10,   KC_F11,  KC_F12,
  KC_TAB,  UK_Q,  UK_W,  UK_E,  UK_R,  UK_T,  UK_Y,    UK_U,    UK_I,    UK_O,     UK_P,    KC_BSPC,
  KC_CAPS, UK_A,  UK_S,  UK_D,  UK_F,  UK_G,  KC_LEFT, KC_DOWN, KC_UP,   KC_RIGHT, UK_SCLN, UK_QUOT,
  KC_LSFT, UK_Z,  UK_X,  UK_C,  UK_V,  UK_B,  UK_N,    UK_M,    KC_COMM, KC_DOT,   KC_SLSH, KC_ENT
),
};

#ifdef RGBLIGHT_ENABLE
    #define SETCOL(c) rgblight_sethsv(c)
    #define CLEARCOL rgblight_sethsv(COLOR_QWERTY)
    #define COLOR_QWERTY HSV_PINK
    #define COLOR_REST HSV_CYAN
    #define COLOR_FUNC HSV_RED
#else
    #define SETCOL(c)
    #define CLEARCOL
    #define COLOR_QWERTY
    #define COLOR_REST
    #define COLOR_FUNC
#endif

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case CKC_REST:
            if (record->event.pressed) {
                layer_on(_REST);
                SETCOL(COLOR_REST);
            } else {
                layer_off(_REST);
                CLEARCOL;
            }
            return false;
            break;
        case CKC_FUNC:
            if (record->event.pressed) {
                layer_on(_FUNC);
                SETCOL(COLOR_FUNC);
            } else {
                layer_off(_FUNC);
                CLEARCOL;
            }
            return false;
            break;
    }
    return true;
};


void keyboard_post_init_user(void) {
#ifdef RGBLIGHT_ENABLE
    rgblight_enable();
    rgblight_mode(RGBLIGHT_MODE_STATIC_LIGHT);
    rgblight_sethsv(COLOR_QWERTY);
#endif
}

