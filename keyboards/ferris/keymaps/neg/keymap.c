#include QMK_KEYBOARD_H
#if __has_include("keymap.h")
#    include "keymap.h"
#endif
#include "sm_td/sm_td.h"

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (!process_smtd(keycode, record)) {
        return false;
    }
    // your code here
    return true;
}

smtd_resolution on_smtd_action(uint16_t keycode, smtd_action action, uint8_t tap_count) {
    switch (keycode) {
        SMTD_MT(KC_A, KC_LEFT_CTRL)
        SMTD_MT(KC_D, KC_LEFT_GUI)
        SMTD_MT(KC_F, KC_LEFT_ALT)
        SMTD_MT(KC_Z, KC_LSFT)
    }
    return SMTD_RESOLUTION_UNHANDLED;
}

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT_split_3x5_2(
        // ┌─────┬─────┬─────┬─────┬─────┐               ┌─────┬─────┬─────┬─────┬─────┐
           KC_Q , KC_W , KC_E , KC_R , KC_T ,             KC_Y , KC_U , KC_I , KC_O , KC_P ,
        // ├─────┼─────┼─────┼─────┼─────┤               ├─────┼─────┼─────┼─────┼─────┤
           KC_A , KC_S , KC_D , KC_F , KC_G ,             KC_H , KC_J , KC_K , KC_L , KC_SCLN ,
        // ├─────┼─────┼─────┼─────┼─────┤               ├─────┼─────┼─────┼─────┼─────┤
           KC_Z , KC_X , KC_C , KC_V , KC_B ,             KC_N , KC_M , KC_COMM,KC_DOT, KC_SLSH,
        // └─────┴─────┴─────┴─────┴─────┘               └─────┴─────┴─────┴─────┴─────┘
                          KC_LGUI, KC_SPC ,              KC_ENT, KC_TAB
        //                  └─────┴─────┘               └─────┴─────┘
    )
};

#ifdef OTHER_KEYMAP_C
#    include OTHER_KEYMAP_C
#endif // OTHER_KEYMAP_C
