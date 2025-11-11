#include QMK_KEYBOARD_H
#include <stdio.h>

enum
{
  TD_Q_ESC,
  TD_C_COPY,
  TD_V_PSTE,
  TD_X_CUT,
  TD_Z_UNDO,
  TD_SPC_TAB,
  TD_LBRC_RBRC,
  TD_LCBR_RCBR,
  TD_LPRN_RPRN,
  TD_LABK_RABK,
  TD_MINS_UNDS,
  TD_EQL_PLUS,
  TD_QUOT_DQUO,
  TD_BSLS_PIPE,
  TD_GRV_TILD
};

qk_tap_dance_action_t tap_dance_actions[] = {
    // Layer 0
    [TD_Q_ESC] = ACTION_TAP_DANCE_DOUBLE(KC_Q, KC_ESC),
    //[TD_C_COPY]    = ACTION_TAP_DANCE_DOUBLE(KC_C, KC_COPY),
    //[TD_V_PSTE]    = ACTION_TAP_DANCE_DOUBLE(KC_V, KC_PSTE),
    //[TD_X_CUT]     = ACTION_TAP_DANCE_DOUBLE(KC_X, KC_CUT),
    //[TD_Z_UNDO]    = ACTION_TAP_DANCE_DOUBLE(KC_Z, KC_UNDO),

    // Layer 1
    [TD_LBRC_RBRC] = ACTION_TAP_DANCE_DOUBLE(KC_LBRC, KC_RBRC),
    [TD_LCBR_RCBR] = ACTION_TAP_DANCE_DOUBLE(KC_LCBR, KC_RCBR),
    [TD_LPRN_RPRN] = ACTION_TAP_DANCE_DOUBLE(KC_LPRN, KC_RPRN),
    [TD_LABK_RABK] = ACTION_TAP_DANCE_DOUBLE(KC_LABK, KC_RABK),
    [TD_MINS_UNDS] = ACTION_TAP_DANCE_DOUBLE(KC_MINS, KC_UNDS),
    [TD_EQL_PLUS] = ACTION_TAP_DANCE_DOUBLE(KC_EQL, KC_PLUS),
    [TD_QUOT_DQUO] = ACTION_TAP_DANCE_DOUBLE(KC_QUOT, KC_DQUO),
    [TD_BSLS_PIPE] = ACTION_TAP_DANCE_DOUBLE(KC_BSLS, KC_PIPE),
    [TD_GRV_TILD] = ACTION_TAP_DANCE_DOUBLE(KC_GRV, KC_TILD)};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /*
     * ┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┐
     * │ Q │ W │ E │ R │ T │ Y │ U │ I │ O │ P │
     * ├───┼───┼───┼───┼───┼───┼───┼───┼───┼───┤
     * │ A │ S │ D │ F │ G │ H │ J │ K │ L │ ; │
     * ├───┼───┼───┼───┼───┼───┼───┼───┼───┼───┤
     * │ Z │ X │ C │ V │ B │ N │ M │ , │ . │ / │
     * └───┴───┴───┼───┼───┼───┼───┼───┴───┴───┘
     *             │Spc│MO1│MO2│Ent│
     *             └───┴───┴───┴───┘
     */
    [0] = LAYOUT_ortho_3x10_4(
        TD(TD_Q_ESC), KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P,
        LGUI_T(KC_A), LALT_T(KC_S), LCTL_T(KC_D), LSFT_T(KC_F), KC_G, KC_H, RSFT_T(KC_J), RCTL_T(KC_K), RALT_T(KC_L), RGUI_T(KC_SCLN),
        KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH,
        XXXXXXX, XXXXXXX, XXXXXXX, KC_SPC, MO(1), MO(2), KC_ENT, XXXXXXX, XXXXXXX, XXXXXXX),

    [1] = LAYOUT_ortho_3x10_4(
        KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0,
        KC_TAB, TD(TD_LBRC_RBRC), TD(TD_LCBR_RCBR), TD(TD_LPRN_RPRN), TD(TD_LABK_RABK), TD(TD_MINS_UNDS), TD(TD_EQL_PLUS), TD(TD_QUOT_DQUO), TD(TD_BSLS_PIPE), TD(TD_GRV_TILD),
        KC_ESC, KC_AT, KC_HASH, KC_DLR, KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_EXLM, KC_QUES,
        XXXXXXX, XXXXXXX, XXXXXXX, KC_SPC, _______, MO(2), KC_BSPC, XXXXXXX, XXXXXXX, XXXXXXX),

    [2] = LAYOUT_ortho_3x10_4(
        KC_MPLY, KC_VOLU, KC_PGUP, KC_HOME, CW_TOGG, KC_CAPS, KC_INS, TG(3), QK_RBT, KC_PSCR,
        KC_MUTE, KC_VOLD, KC_PGDN, KC_END, KC_F11, KC_F12, KC_LEFT, KC_DOWN, KC_UP, KC_RGHT,
        KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10,
        XXXXXXX, XXXXXXX, XXXXXXX, KC_DEL, MO(1), _______, KC_ENT, XXXXXXX, XXXXXXX, XXXXXXX),

    [3] = LAYOUT_ortho_3x10_4(
        KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O,
        KC_LSFT, KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L,
        KC_LCTL, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_P, KC_SLSH,
        XXXXXXX, XXXXXXX, XXXXXXX, KC_ESC, KC_SPC, MO(4), KC_ENT, XXXXXXX, XXXXXXX, XXXXXXX),

    [4] = LAYOUT_ortho_3x10_4(
        KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0,
        _______, _______, _______, _______, _______, KC_LGUI, KC_LEFT, KC_DOWN, KC_UP, KC_RGHT,
        _______, _______, _______, _______, _______, KC_MINS, KC_EQL, KC_COMM, KC_DOT, TG(3),
        XXXXXXX, XXXXXXX, XXXXXXX, KC_LALT, _______, _______, KC_BSPC, XXXXXXX, XXXXXXX, XXXXXXX)};

