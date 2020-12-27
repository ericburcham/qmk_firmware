#include QMK_KEYBOARD_H

#ifdef PROTOCOL_LUFA
  #include "lufa.h"
  #include "split_util.h"
#endif
#ifdef SSD1306OLED
  #include "ssd1306.h"
#endif

extern uint8_t is_master;

enum layer_number {
  _QWERTY = 0,
  _LOWER,
  _RAISE,
  _ADJUST,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
   // LAYER TEMPLATE
   // [_NAME] = LAYOUT(
   // .-----------------------------------------------------.                      .-----------------------------------------------------.
   // |        |        |        |        |        |        |                      |        |        |        |        |        |        |
   //   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
   // |--------+--------+--------+--------+--------+--------|                      |--------+--------+--------+--------+--------+--------|
   // |        |        |        |        |        |        |                      |        |        |        |        |        |        |
   //   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
   // |--------+--------+--------+--------+--------+--------|                      |--------+--------+--------+--------+--------+--------|
   // |        |        |        |        |        |        |                      |        |        |        |        |        |        |
   //   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,/*------.    .-------*/ XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
   // |--------+--------+--------+--------+--------+--------|        |    |        |--------+--------+--------+--------+--------+--------|
   // |        |        |        |        |        |        |        |    |        |        |        |        |        |        |        |
   //   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
   // .-----------------------------------------------------/        /    \        \-----------------------------------------------------.
   //                         |        |        |        | /        /      \        \ |        |        |        |
   //                           XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX,          XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX
   //                         '-----------------------------------'          '-----------------------------------'
   // ),



   // QWERTY
   [_QWERTY] = LAYOUT(
   // .-----------------------------------------------------.                      .-----------------------------------------------------.
   // |       `|       1|       2|       3|       4|       5|                      |       6|       7|       8|       9|       0|       -|
         KC_GRV,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                           KC_6,    KC_7,    KC_8,    KC_9,    KC_0, KC_MINS,
   // |--------+--------+--------+--------+--------+--------|                      |--------+--------+--------+--------+--------+--------|
   // |     Tab|       Q|       W|       E|       R|       T|                      |       Y|       U|       I|       O|       P|    Bspc|
         KC_TAB,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                           KC_Y,    KC_U,    KC_I,    KC_O,    KC_P, KC_BSPC,
   // |--------+--------+--------+--------+--------+--------|                      |--------+--------+--------+--------+--------+--------|
   // |    Caps|       A|       S|       D|       F|       G|                      |       H|       J|       K|       L|       ;|       '|
        KC_CAPS,    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,/*------.    .-------*/    KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN, KC_QUOT,
   // |--------+--------+--------+--------+--------+--------|        |    |        |--------+--------+--------+--------+--------+--------|
   // |  LShift|       Z|       X|       C|       V|       B|    LGUI|    |    Menu|       N|       M|       ,|       .|       /|  RShift|
        KC_LSFT,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B, KC_LGUI,       KC_APP,    KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH, KC_RSFT,
   // .-----------------------------------------------------/        /    \        \-----------------------------------------------------.
   //                         |    LCtr|    LAlt|  Layer1| /   Space/      \   Enter\ |  Layer2|    RAlt|    RCtl|
                               KC_LCTRL, KC_LALT,   MO(1),   KC_SPC,            KC_ENT,   MO(2), KC_RALT,KC_RCTRL
   //                         '-----------------------------------'          '-----------------------------------'
   ),



   // LOWER
   [_LOWER] = LAYOUT(
   // .-----------------------------------------------------.                      .-----------------------------------------------------.
   // |        |        |        |        |        |        |                      |        |     Ins|    Home|    PgUp|        |        |
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                        XXXXXXX,  KC_INS, KC_HOME, KC_PGUP, XXXXXXX, XXXXXXX,
   // |--------+--------+--------+--------+--------+--------|                      |--------+--------+--------+--------+--------+--------|
   // |     Tab|        |        |        |        |        |                      |    Redo|     Del|     End|  PgDown|        |     Del|
        _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                        C(KC_Y),  KC_DEL,  KC_END, KC_PGDN, XXXXXXX,  KC_DEL,
   // |--------+--------+--------+--------+--------+--------|                      |--------+--------+--------+--------+--------+--------|
   // |    Caps|        |        |        |        |        |                      |        |    Left|    Down|      Up|   Right|        |
        _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,/*------.    .-------*/ XXXXXXX, KC_LEFT, KC_DOWN,   KC_UP, KC_RGHT, XXXXXXX,
   // |--------+--------+--------+--------+--------+--------|        |    |        |--------+--------+--------+--------+--------+--------|
   // |  LShift|    Undo|     Cut|    Copy|   Paste|     Esc|    LGUI|    |    Menu|        |        |        |        |        |  RShift|
        _______, C(KC_Z), C(KC_X), C(KC_C), C(KC_V),  KC_ESC, _______,      _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,
   // .-----------------------------------------------------/        /    \        \-----------------------------------------------------.
   //                         |    LCtr|    LAlt|  Layer1| /   Space/      \   Enter\ |  Layer3|    RAlt|    RCtl|
                                _______, _______, _______,  _______,           _______,   MO(3), _______, _______
   //                         '-----------------------------------'          '-----------------------------------'
   ),



   // RAISE
   [_RAISE] = LAYOUT(
   // .-----------------------------------------------------.                      .-----------------------------------------------------.
   // |        |      F1|      F2|      F3|      F4|      F5|                      |      F6|      F7|      F8|      F9|     F10|     F11|
        XXXXXXX,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                          KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10,  KC_F11,
   // |--------+--------+--------+--------+--------+--------|                      |--------+--------+--------+--------+--------+--------|
   // |     Tab|       !|       @|       #|       $|       %|                      |       ^|       &|       *|       (|       )|     F12|
        _______, KC_EXLM,   KC_AT, KC_HASH,  KC_DLR, KC_PERC,                        KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN,  KC_F12,
   // |--------+--------+--------+--------+--------+--------|                      |--------+--------+--------+--------+--------+--------|
   // |    Caps|        |PrntScrn|  ScrLck|   Pause|        |                      |       -|       =|       ||       [|       ]|        |
        _______, XXXXXXX, KC_PSCR, KC_SLCK, KC_PAUS, XXXXXXX,/*------.    .-------*/ KC_MINS,  KC_EQL, KC_PIPE, KC_LBRC, KC_RBRC, XXXXXXX,
   // |--------+--------+--------+--------+--------+--------|        |    |        |--------+--------+--------+--------+--------+--------|
   // |  LShift|    Undo|     Cut|    Copy|   Paste|     Esc|    LGUI|    |    Menu|       _|       +|       ~|       {|       }|  RShift|
        _______, C(KC_Z), C(KC_X), C(KC_C), C(KC_V),  KC_ESC, _______,      _______, KC_UNDS, KC_PLUS, KC_TILD, KC_LCBR, KC_RCBR, _______,
   // .-----------------------------------------------------/        /    \        \-----------------------------------------------------.
   //                         |    LCtr|    LAlt|  Layer3| /   Space/      \   Enter\ |  Layer3|    RAlt|    RCtl|
                                _______, _______,   MO(3),  _______,           _______, _______, _______, _______
   //                         '-----------------------------------'          '-----------------------------------'
   ),



   // ADJUST
   [_ADJUST] = LAYOUT(
   // .-----------------------------------------------------.                      .-----------------------------------------------------.
   // |        |        |        |        |        |        |                      |        |        |        |        |        |        |
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
   // |--------+--------+--------+--------+--------+--------|                      |--------+--------+--------+--------+--------+--------|
   // |        |        |        |        |        |        |                      |        |        |        |        |        |        |
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
   // |--------+--------+--------+--------+--------+--------|                      |--------+--------+--------+--------+--------+--------|
   // |        |        |        |        |        |        |                      |        |    Mute|    Vol-|    Vol+|        |        |
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,/*------.    .-------*/ XXXXXXX, KC_MUTE, KC_VOLD, KC_VOLU, XXXXXXX, XXXXXXX,
   // |--------+--------+--------+--------+--------+--------|        |    |        |--------+--------+--------+--------+--------+--------|
   // |   Reset|        |        |        |        |     Esc|    LGUI|    |    Menu|        | PrvTrck|    Play| NxtTrck|        |  RShift|
          RESET, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, _______,      _______, XXXXXXX, KC_MPRV, KC_MPLY, KC_MNXT, XXXXXXX, _______,
   // .-----------------------------------------------------/        /    \        \-----------------------------------------------------.
   //                         |    LCtr|    LAlt|  Layer3| /   Space/      \   Enter\ |  Layer3|    RAlt|    RCtl|
                                _______, _______, _______,  _______,          _______,  _______, _______, _______
   //                         '-----------------------------------'          '-----------------------------------'
   )
};

// Setting ADJUST layer RGB back to default
void update_tri_layer_RGB(uint8_t layer1, uint8_t layer2, uint8_t layer3) {
  if (IS_LAYER_ON(layer1) && IS_LAYER_ON(layer2)) {
    layer_on(layer3);
  } else {
    layer_off(layer3);
  }
}

//SSD1306 OLED update loop, make sure to enable OLED_DRIVER_ENABLE=yes in rules.mk
#ifdef OLED_DRIVER_ENABLE

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
  if (!is_keyboard_master())
    return OLED_ROTATION_180;  // flips the display 180 degrees if offhand
  return rotation;
}


#define L_BASE 0
#define L_LOWER 2
#define L_RAISE 4
#define L_ADJUST 8

void oled_render_layer_state(void) {
    oled_write_P(PSTR("Layer: "), false);
    switch (layer_state) {
        case L_BASE:
            oled_write_ln_P(PSTR("Default"), false);
            break;
        case L_LOWER:
            oled_write_ln_P(PSTR("Lower"), false);
            break;
        case L_RAISE:
            oled_write_ln_P(PSTR("Raise"), false);
            break;
        case L_ADJUST:
        case L_ADJUST|L_LOWER:
        case L_ADJUST|L_RAISE:
        case L_ADJUST|L_LOWER|L_RAISE:
            oled_write_ln_P(PSTR("Adjust"), false);
            break;
    }
}

// When you add source files to SRC in rules.mk, you can use functions.
const char *read_layer_state(void);
const char *read_logo(void);
void set_keylog(uint16_t keycode, keyrecord_t *record);
const char *read_keylog(void);
const char *read_keylogs(void);

// const char *read_mode_icon(bool swap);
// const char *read_host_led_state(void);
// void set_timelog(void);
// const char *read_timelog(void);

void oled_task_user(void) {
  if (is_keyboard_master()) {
    // If you want to change the display of OLED, you need to change here
    oled_render_layer_state();
    oled_write_ln(read_keylog(), false);
    oled_write_ln(read_keylogs(), false);
    //oled_write_ln(read_mode_icon(keymap_config.swap_lalt_lgui), false);
    //oled_write_ln(read_host_led_state(), false);
    //oled_write_ln(read_timelog(), false);
  } else {
    oled_write(read_logo(), false);
  }
}
#endif // OLED_DRIVER_ENABLE

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
#ifdef OLED_DRIVER_ENABLE
    set_keylog(keycode, record);
#endif
    // set_timelog();
  }
  return true;
}
