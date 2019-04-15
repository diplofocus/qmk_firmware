#include QMK_KEYBOARD_H

enum layers {
  _QWERTY,
  _STENO,
  _LOWER,
  _RAISE,
  _FUNCT,
  _MOUSE
};

enum custom_keycodes {
  DYNAMIC_MACRO_RANGE = SAFE_RANGE,
};

#include "dynamic_macro.h"

enum tap_dance {
  TD_Q_MIN,
  TD_S_BSL,
  TD_PL_NX,
  TD_ST_PR,
  TD_LC_CA,
  TD_F4_ALTF4,
  TD_C_SCL,
  TD_D_CL,
};

qk_tap_dance_action_t tap_dance_actions[] = {
  [TD_Q_MIN]    = ACTION_TAP_DANCE_DOUBLE(KC_QUOT, KC_MINS),
  [TD_S_BSL]    = ACTION_TAP_DANCE_DOUBLE(KC_SLASH, KC_BSLASH),
  [TD_PL_NX]    = ACTION_TAP_DANCE_DOUBLE(KC_MPLY, KC_MNXT),
  [TD_ST_PR]    = ACTION_TAP_DANCE_DOUBLE(KC_MSTP, KC_MPRV),
  [TD_LC_CA]    = ACTION_TAP_DANCE_DOUBLE(KC_LCTL, LCTL(KC_A)),
  [TD_C_SCL]    = ACTION_TAP_DANCE_DOUBLE(KC_COMM, KC_SCLN),
  [TD_D_CL]     = ACTION_TAP_DANCE_DOUBLE(KC_DOT, LSFT(KC_SCLN)),
  [TD_F4_ALTF4] = ACTION_TAP_DANCE_DOUBLE(KC_F4, LALT(KC_F4)),
};

#define LOWER    MO(_LOWER)
#define RAISE    MO(_RAISE)
#define FUNCT    MO(_FUNCT)
#define MOUSE    MO(_MOUSE)
#define LOWDEL   LT(_LOWER, KC_DELETE)
#define RAISENT  LT(_RAISE, KC_ENT)
#define MSESC    LT(_MOUSE, KC_ESC)
#define FNTAB    LT(_FUNCT, KC_TAB)
#define SHT_BSP  LSFT_T(KC_BSPC)
#define CMD_BSP  LGUI_T(KC_BSPC)
#define CMD_SPC  LGUI_T(KC_SPC)  // unused atm
#define CMD_LEFT LGUI_T(KC_LEFT)
#define SHT_SPC  LSFT_T(KC_SPC)
#define DIVVY    LALT(LGUI(LSFT(KC_D)))
#define F_CHR    LALT(LSFT(KC_E))
#define F_WIN    LALT(LGUI(LSFT(KC_W)))
#define CTLA     CTL_T(KC_A)
#define CTLO     CTL_T(KC_O)
#define GUIR     GUI_T(KC_R)
#define GUII     GUI_T(KC_I)
#define ALTS     ALT_T(KC_S)
#define ALTE     ALT_T(KC_E)
#define SFTT     SFT_T(KC_T)
#define SFTN     SFT_T(KC_N)

#define TGSTENO  TO(_STENO)

// Petar
#define GUIS GUI_T(KC_S)
#define ALTH ALT_T(KC_H)
#define GUIO GUI_T(KC_O)
#define CTLI CTL_T(KC_I)
#define SFTI SFT_T(KC_I)
#define SFTA SFT_T(KC_A)
#define CTLT CTL_T(KC_T)
#define CTLN CTL_T(KC_N)

#define ALLP ALT_T(KC_LBRC)
#define SFRP SFT_T(KC_RBRC)

#define SF4 SFT_T(KC_4)
#define AL5 ALT_T(KC_5)
#define GUI6 GUI_T(KC_6)
#define CMIN CTL_T(KC_MINUS)
#define CZ LCTL(KC_Z)
#define CX LCTL(KC_X)
#define CC LCTL(KC_C)
#define CV LCTL(KC_V)
#define TDQMIN TD(TD_Q_MIN)
#define TDSLBS TD(TD_S_BSL)
#define TDPLNX TD(TD_PL_NX)
#define TDSTPR TD(TD_ST_PR)
#define TDLCCA TD(TD_LC_CA)
#define TDF4AF4 TD(TD_F4_ALTF4)
#define TDCSCL TD(TD_C_SCL)
#define TDDCL TD(TD_D_CL)

#define MAC_PL1 DYN_MACRO_PLAY1
#define MAC_PL2 DYN_MACRO_PLAY2
#define MAC_RC1 DYN_REC_START1
#define MAC_RC2 DYN_REC_START2
#define MAC_STP DYN_REC_STOP

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (!process_record_dynamic_macro(keycode, record)) {
    return false;
  }
  return true;
}

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QWERTY] = LAYOUT_ortho_4x12(
    KC_Q,    KC_D,    KC_R,   KC_W,    KC_B,    TDSTPR,  TDPLNX,  KC_J,    KC_F,    KC_U,    KC_P,    TDQMIN,
    SFTA,    GUIS,    ALTH,   CTLT,    KC_G,    KC_BRID, KC_BRIU, KC_Y,    CTLN,    ALTE,    GUIO,    SFTI,
    KC_Z,    KC_X,    KC_M,   KC_C,    KC_V,    KC_VOLD, KC_VOLU, KC_K,    KC_L,    TDCSCL,  TDDCL,   TDSLBS,
    MAC_PL1, MAC_PL2, MSESC,  LOWDEL,  SHT_BSP, TGSTENO, MAC_STP, KC_SPC,  RAISENT, FNTAB,   MAC_RC1, MAC_RC2
  ),

  [_STENO] = LAYOUT_ortho_4x12(
    KC_Q,    KC_W,    KC_E,   KC_R,    KC_T,    _______, _______, KC_Y,    KC_I,    KC_O,    KC_P,    TDQMIN,
    SFTA,    GUIS,    KC_D,   KC_F,    KC_G,    _______, _______, KC_H,    KC_J,    KC_K,    KC_L,    TDCSCL,
    KC_Z,    KC_X,    KC_C,   KC_V,    KC_B,    _______, _______, KC_N,    KC_M,    TDCSCL,  TDDCL,   TDSLBS,
    MAC_PL1, MAC_PL2, MSESC,  LOWDEL,  SHT_BSP, _______, _______, KC_SPC,  RAISENT, FNTAB,   MAC_RC1, MAC_RC2
  ),

  [_LOWER] = LAYOUT_ortho_4x12(
    KC_GRV,  _______, KC_LPRN, KC_RPRN, _______, _______, _______, _______, KC_7,   KC_8,    KC_9,    KC_EQL,
    TDLCCA,  KC_LWIN, KC_LBRC, KC_RBRC, KC_TAB,  _______, _______, _______, KC_4,   KC_5,    KC_6,    CMIN,
    CZ,      CX,      CC,      KC_PSCR, CV,      _______, _______, _______, KC_1,   KC_2,    KC_3,    KC_SLSH,
    _______, _______, _______, _______, _______, _______, _______, _______, KC_0,   KC_DOT,  _______, _______
  ),

  [_RAISE] = LAYOUT_ortho_4x12(
    DIVVY,   F_CHR,   F_WIN,   _______, _______, _______, _______, KC_PGUP, KC_HOME, KC_UP,   KC_END,  _______,
    KC_LCTL, KC_LWIN, KC_LALT, KC_LSFT, _______, _______, _______, KC_PGDN, KC_LEFT, KC_DOWN, KC_RGHT, KC_INS,
    _______, KC_X,    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
  ),

  [_FUNCT] = LAYOUT_ortho_4x12(
    _______, _______, _______, _______, _______, _______, _______, _______, KC_F7,   KC_F8,   KC_F9,   KC_F10,
    KC_LCTL, KC_LWIN, KC_LALT, KC_LSFT, _______, _______, _______, _______, TDF4AF4, KC_F5,   KC_F6,   KC_F11,
    _______, _______, _______, _______, _______, _______, _______, _______, KC_F1,   KC_F2,   KC_F3,   KC_F12,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
  ),

  [_MOUSE] = LAYOUT_ortho_4x12(
    _______, _______, _______, _______, _______, RGB_HUI, RGB_HUD, KC_WH_U, KC_WH_L, KC_MS_U, KC_WH_R, _______,
    KC_LCTL, KC_LWIN, KC_LALT, KC_LSFT, _______, RGB_SAI, RGB_SAD, KC_WH_D, KC_MS_L, KC_MS_D, KC_MS_R, KC_LCTL,
    _______, _______, _______, _______, _______, RGB_VAI, RGB_VAD, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, RGB_TOG, RGB_MOD, RGB_RMOD,KC_BTN1, KC_BTN2, _______, _______, _______
  )
};
