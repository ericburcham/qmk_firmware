#include QMK_KEYBOARD_H

enum sofle_layers {
    /* _M_XYZ = Mac Os, _W_XYZ = Win/Linux */
    _QWERTY,
    _LOWER,
    _RAISE,
    _ADJUST,
};

enum custom_keycodes {
    KC_QWERTY = SAFE_RANGE,
    KC_LOWER,
    KC_RAISE,
    KC_ADJUST,
    KC_PRVWD,
    KC_NXTWD,
    KC_LSTRT,
    KC_LEND,
    KC_DLINE
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
   //                |        |        |        |        | /        /      \        \ |        |        |        |        |
   //                  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX,          XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
   //                '--------------------------------------------'          '--------------------------------------------'
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
   // |  LShift|       Z|       X|       C|       V|       B|    Mute|    | RGB Tog|       N|       M|       ,|       .|       /|  RShift|
        KC_LSFT,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B, KC_MUTE,      RGB_TOG,    KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH, KC_RSFT,
   // .-----------------------------------------------------/        /    \        \-----------------------------------------------------.
   //                |    LCtr|    LGUI|    LAlt|   LOWER| /   Space/      \   Enter\ |   RAISE|    RAlt|    Menu|    RCtl|
                      KC_LCTRL, KC_LGUI, KC_LALT,KC_LOWER,   KC_SPC,           KC_ENT, KC_RAISE, KC_RALT,  KC_APP,KC_RCTRL
   //                '--------------------------------------------'          '--------------------------------------------'
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
   // |    Caps| SlctAll|    Save|        |    Find|        |                      | Replace|    Left|    Down|      Up|   Right|        |
        _______, C(KC_A), C(KC_S), XXXXXXX, C(KC_F), XXXXXXX,/*------.    .-------*/ C(KC_H), KC_LEFT, KC_DOWN,   KC_UP, KC_RGHT, XXXXXXX,
   // |--------+--------+--------+--------+--------+--------|        |    |        |--------+--------+--------+--------+--------+--------|
   // |  LShift|    Undo|     Cut|    Copy|   Paste|     Esc|    Mute|    | RGB Tog|        |        |        |        |       \|  RShift|
        _______, C(KC_Z), C(KC_X), C(KC_C), C(KC_V),  KC_ESC, _______,      _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_BSLS, _______,
   // .-----------------------------------------------------/        /    \        \-----------------------------------------------------.
   //                |    LCtr|    LGUI|    LAlt|   LOWER| /   Space/      \   Enter\ |   RAISE|    RAlt|    Menu|    RCtl|
                       _______, _______, _______, _______,  _______,          _______,  _______, _______, _______, _______
   //                '--------------------------------------------'          '--------------------------------------------'
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
   // |    Caps| SlctAll|    Save|PrntScrn|  ScrLck|   Pause|                      |       -|       =|       ||       [|       ]|        |
        _______, _______, _______, KC_PSCR, KC_SLCK, KC_PAUS,/*------.    .-------*/ KC_MINS,  KC_EQL, KC_PIPE, KC_LBRC, KC_RBRC, XXXXXXX,
   // |--------+--------+--------+--------+--------+--------|        |    |        |--------+--------+--------+--------+--------+--------|
   // |  LShift|    Undo|     Cut|    Copy|   Paste|     Esc|    Mute|    | RGB Tog|       _|       +|       ~|       {|       }|  RShift|
        _______, _______, _______, _______, _______,  KC_ESC, _______,      _______, KC_UNDS, KC_PLUS, KC_TILD, KC_LCBR, KC_RCBR, _______,
   // .-----------------------------------------------------/        /    \        \-----------------------------------------------------.
   //                |    LCtr|    LGUI|    LAlt|   LOWER| /   Space/      \   Enter\ |   RAISE|    RAlt|    Menu|    RCtl|
                       _______, _______, _______, _______,  _______,          _______,  _______, _______, _______, _______
   //                '--------------------------------------------'          '--------------------------------------------'
   ),



   // ADJUST
   [_ADJUST] = LAYOUT(
   // .-----------------------------------------------------.                      .-----------------------------------------------------.
   // | Effect-| Effect+|    Hue-|    Hue+|    Sat-|    Sat+|                      | Bright-| Bright+|        |        |        | RGB Tog|
        RGB_SPD, RGB_SPI, RGB_HUD, RGB_HUI, RGB_SAD, RGB_SAI,                        RGB_VAD, RGB_VAI, XXXXXXX, XXXXXXX, XXXXXXX, RGB_TOG,
   // |--------+--------+--------+--------+--------+--------|                      |--------+--------+--------+--------+--------+--------|
   // |        |        |        |        |        |        |                      |        |        |        |        |        |        |
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
   // |--------+--------+--------+--------+--------+--------|                      |--------+--------+--------+--------+--------+--------|
   // |        |        |        |        |        |        |                      |        |    Mute|    Vol-|    Vol+|        |        |
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,/*------.    .-------*/ XXXXXXX, KC_MUTE, KC_VOLD, KC_VOLU, XXXXXXX, XXXXXXX,
   // |--------+--------+--------+--------+--------+--------|        |    |        |--------+--------+--------+--------+--------+--------|
   // |   Reset|        |        |        |        |     Esc|    Mute|    | RGB Tog|        | PrvTrck|    Play| NxtTrck|        |  RShift|
          RESET, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, _______,      _______, XXXXXXX, KC_MPRV, KC_MPLY, KC_MNXT, XXXXXXX, _______,
   // .-----------------------------------------------------/        /    \        \-----------------------------------------------------.
   //                |    LCtr|    LGUI|    LAlt|   LOWER| /   Space/      \   Enter\ |   RAISE|    RAlt|    Menu|    RCtl|
                       _______, _______, _______, _______,  _______,          _______,  _______, _______, _______, _______
   //                '--------------------------------------------'          '--------------------------------------------'
   )
};

#ifdef OLED_DRIVER_ENABLE

static void render_logo(void) {
    static const char PROGMEM Logo_CP2077 [] = {
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x80, 0x80, 0x80, 0xc0, 0xc0, 0xe0, 0x60, 0x70, 0x30, 0x38, 0x18, 0x0c, 0x0c, 0x1e, 0x0c,
0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xc0, 0xe0, 0xf0, 0x38, 0x1c, 0x0e,
0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x80, 0x80, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x00, 0x00, 0x80, 0x40, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x80, 0x80, 0x00, 0x00, 0x00, 0x00, 0x80,
0x80, 0xc0, 0xc0, 0x60, 0x60, 0x30, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x10, 0x30, 0x30, 0x70, 0x78, 0x78, 0x7c, 0x7c, 0x7e, 0x3e, 0x3f,
0x3f, 0x3b, 0x3b, 0x39, 0x39, 0x38, 0x38, 0x38, 0x38, 0x38, 0x38, 0x38, 0x3c, 0x38, 0x18, 0x8f,
0xdf, 0xf8, 0x7c, 0xbe, 0xdf, 0xf7, 0xfb, 0xfd, 0xfe, 0xef, 0x73, 0x3b, 0x1b, 0x1f, 0xef, 0xf7,
0xff, 0x7e, 0x6f, 0x6f, 0x6f, 0x6f, 0x6d, 0xbd, 0xe1, 0xf9, 0x3f, 0x3f, 0x39, 0x79, 0x79, 0x7d,
0xed, 0xed, 0xcd, 0xc7, 0xc7, 0x87, 0xc7, 0xe3, 0xe0, 0xf8, 0x7e, 0x3f, 0x37, 0x33, 0x3b, 0x1b,
0x19, 0x19, 0x0d, 0xed, 0xff, 0xbf, 0xc7, 0xe7, 0xe3, 0xf0, 0x7c, 0xde, 0xe7, 0xfb, 0x3e, 0x3f,
0xfc, 0xe0, 0xf8, 0x3e, 0xcf, 0xf3, 0xfc, 0x3f, 0x1f, 0x1f, 0x3c, 0x7e, 0x76, 0xf3, 0xe3, 0x81,
0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x20, 0x30, 0x18, 0x1e, 0x0f, 0x03,
0x01, 0x00, 0x00, 0x00, 0x01, 0x03, 0x03, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x01, 0xe1, 0x79, 0x3e, 0x1f, 0x07, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x01, 0x01, 0x01, 0x00, 0x00, 0x01, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01,
0x01, 0x03, 0x02, 0x06, 0x04, 0x08, 0x18, 0x10, 0x30, 0x20, 0x60, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};


    oled_write_raw_P(Logo_CP2077, sizeof(Logo_CP2077));
}

static void print_status_narrow(void) {
    // Print current mode
    oled_write_P(PSTR("\n\n"), false);
    oled_write_ln_P(PSTR("MODE"), false);
    oled_write_ln_P(PSTR(""), false);
    if (keymap_config.swap_lctl_lgui) {
        oled_write_ln_P(PSTR("MAC"), false);
    } else {
        oled_write_ln_P(PSTR("WIN"), false);
    }

    switch (get_highest_layer(default_layer_state)) {
        case _QWERTY:
            oled_write_ln_P(PSTR("Qwrt"), false);
            break;
        default:
            oled_write_P(PSTR("Undef"), false);
    }
    oled_write_P(PSTR("\n\n"), false);
    // Print current layer
    oled_write_ln_P(PSTR("LAYER"), false);
    switch (get_highest_layer(layer_state)) {
        case _QWERTY:
            oled_write_P(PSTR("Base\n"), false);
            break;
        case _RAISE:
            oled_write_P(PSTR("Raise"), false);
            break;
        case _LOWER:
            oled_write_P(PSTR("Lower"), false);
            break;
        case _ADJUST:
            oled_write_P(PSTR("Adj\n"), false);
            break;
        default:
            oled_write_ln_P(PSTR("Undef"), false);
    }
    oled_write_P(PSTR("\n\n"), false);
    led_t led_usb_state = host_keyboard_led_state();
    oled_write_ln_P(PSTR("CPSLK"), led_usb_state.caps_lock);
}

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    if (is_keyboard_master()) {
        return OLED_ROTATION_270;
    }
    return rotation;
}

void oled_task_user(void) {
    if (is_keyboard_master()) {
        print_status_narrow();
    } else {
        render_logo();
    }
}

#endif

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case KC_QWERTY:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_QWERTY);
            }
            return false;
        case KC_LOWER:
            if (record->event.pressed) {
                layer_on(_LOWER);
                update_tri_layer(_LOWER, _RAISE, _ADJUST);
            } else {
                layer_off(_LOWER);
                update_tri_layer(_LOWER, _RAISE, _ADJUST);
            }
            return false;
        case KC_RAISE:
            if (record->event.pressed) {
                layer_on(_RAISE);
                update_tri_layer(_LOWER, _RAISE, _ADJUST);
            } else {
                layer_off(_RAISE);
                update_tri_layer(_LOWER, _RAISE, _ADJUST);
            }
            return false;
        case KC_ADJUST:
            if (record->event.pressed) {
                layer_on(_ADJUST);
            } else {
                layer_off(_ADJUST);
            }
            return false;
        case KC_PRVWD:
            if (record->event.pressed) {
                if (keymap_config.swap_lctl_lgui) {
                    register_mods(mod_config(MOD_LALT));
                    register_code(KC_LEFT);
                } else {
                    register_mods(mod_config(MOD_LCTL));
                    register_code(KC_LEFT);
                }
            } else {
                if (keymap_config.swap_lctl_lgui) {
                    unregister_mods(mod_config(MOD_LALT));
                    unregister_code(KC_LEFT);
                } else {
                    unregister_mods(mod_config(MOD_LCTL));
                    unregister_code(KC_LEFT);
                }
            }
            break;
        case KC_NXTWD:
             if (record->event.pressed) {
                if (keymap_config.swap_lctl_lgui) {
                    register_mods(mod_config(MOD_LALT));
                    register_code(KC_RIGHT);
                } else {
                    register_mods(mod_config(MOD_LCTL));
                    register_code(KC_RIGHT);
                }
            } else {
                if (keymap_config.swap_lctl_lgui) {
                    unregister_mods(mod_config(MOD_LALT));
                    unregister_code(KC_RIGHT);
                } else {
                    unregister_mods(mod_config(MOD_LCTL));
                    unregister_code(KC_RIGHT);
                }
            }
            break;
        case KC_LSTRT:
            if (record->event.pressed) {
                if (keymap_config.swap_lctl_lgui) {
                     //CMD-arrow on Mac, but we have CTL and GUI swapped
                    register_mods(mod_config(MOD_LCTL));
                    register_code(KC_LEFT);
                } else {
                    register_code(KC_HOME);
                }
            } else {
                if (keymap_config.swap_lctl_lgui) {
                    unregister_mods(mod_config(MOD_LCTL));
                    unregister_code(KC_LEFT);
                } else {
                    unregister_code(KC_HOME);
                }
            }
            break;
        case KC_LEND:
            if (record->event.pressed) {
                if (keymap_config.swap_lctl_lgui) {
                    //CMD-arrow on Mac, but we have CTL and GUI swapped
                    register_mods(mod_config(MOD_LCTL));
                    register_code(KC_RIGHT);
                } else {
                    register_code(KC_END);
                }
            } else {
                if (keymap_config.swap_lctl_lgui) {
                    unregister_mods(mod_config(MOD_LCTL));
                    unregister_code(KC_RIGHT);
                } else {
                    unregister_code(KC_END);
                }
            }
            break;
        case KC_DLINE:
            if (record->event.pressed) {
                register_mods(mod_config(MOD_LCTL));
                register_code(KC_BSPC);
            } else {
                unregister_mods(mod_config(MOD_LCTL));
                unregister_code(KC_BSPC);
            }
            break;
        case KC_COPY:
            if (record->event.pressed) {
                register_mods(mod_config(MOD_LCTL));
                register_code(KC_C);
            } else {
                unregister_mods(mod_config(MOD_LCTL));
                unregister_code(KC_C);
            }
            return false;
        case KC_PASTE:
            if (record->event.pressed) {
                register_mods(mod_config(MOD_LCTL));
                register_code(KC_V);
            } else {
                unregister_mods(mod_config(MOD_LCTL));
                unregister_code(KC_V);
            }
            return false;
        case KC_CUT:
            if (record->event.pressed) {
                register_mods(mod_config(MOD_LCTL));
                register_code(KC_X);
            } else {
                unregister_mods(mod_config(MOD_LCTL));
                unregister_code(KC_X);
            }
            return false;
            break;
        case KC_UNDO:
            if (record->event.pressed) {
                register_mods(mod_config(MOD_LCTL));
                register_code(KC_Z);
            } else {
                unregister_mods(mod_config(MOD_LCTL));
                unregister_code(KC_Z);
            }
            return false;
    }
    return true;
}

#ifdef ENCODER_ENABLE

void encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) {
        if (clockwise) {
            tap_code(KC_VOLU);
        } else {
            tap_code(KC_VOLD);
        }
    } else if (index == 1) {
        if (clockwise) {
            tap_code(KC_WH_U);
        } else {
            tap_code(KC_WH_D);
        }
    }
}

#endif
