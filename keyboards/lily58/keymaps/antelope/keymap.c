#include QMK_KEYBOARD_H

#define DUMMY_LEFT KC_F23
#define DUMMY_RIGHT KC_F24
// Left-hand home row mods layer 0
#define HOME_A LSFT_T(KC_A)
#define HOME_S LALT_T(KC_S)
#define HOME_D LCTL_T(KC_D)
#define HOME_F LGUI_T(KC_F)

// Right-hand home row mods layer 0
#define HOME_J RGUI_T(KC_J)
#define HOME_K RCTL_T(KC_K)
#define HOME_L LALT_T(KC_L)
#define HOME_SCLN RSFT_T(KC_SCLN)

// Left-hand home row mods  layer 1
#define HOME_EXLM LSFT_T(DUMMY_LEFT)
#define HOME_AT LALT_T(DUMMY_LEFT)
#define HOME_HASH LCTL_T(DUMMY_LEFT)
#define HOME_DLR LGUI_T(DUMMY_LEFT)

// Right-hand home row mods layer 1
#define HOME_AMPR RGUI_T(DUMMY_RIGHT)
#define HOME_ASTR RCTL_T(DUMMY_RIGHT)
#define HOME_LPRN LALT_T(DUMMY_RIGHT)
#define HOME_RPRN RSFT_T(DUMMY_RIGHT)

enum layer_number {
  _QWERTY = 0,
  _LOWER,
  _RAISE,
  _ADJUST,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[0] = LAYOUT(KC_ESC, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_GRV, KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_MINS, KC_LCTL, HOME_A, HOME_S, HOME_D, HOME_F, KC_G, KC_H, HOME_J, HOME_K, HOME_L, HOME_SCLN, KC_QUOT, KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_LBRC, KC_RBRC, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_BSLS, KC_LALT, KC_LGUI, MO(1), KC_SPC, KC_ENT, MO(2), KC_BSPC, KC_BSPC),
		
	[1] = LAYOUT(KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, KC_TRNS, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_EQL, KC_TRNS, HOME_EXLM, HOME_AT, HOME_HASH, HOME_DLR, KC_PERC, KC_CIRC, HOME_AMPR, HOME_ASTR, HOME_LPRN, HOME_RPRN, KC_TILD, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_NO, KC_PMNS, KC_PLUS, KC_LCBR, KC_RCBR, KC_PIPE, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, MO(3), KC_DEL, KC_DEL),
	
	[2] = LAYOUT(KC_TRNS, KC_TRNS, KC_TRNS, KC_PSLS, KC_PAST, KC_PMNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_P7, KC_P8, KC_P9, KC_PPLS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_P4, KC_P5, KC_P6, KC_PCMM, KC_LEFT, KC_DOWN, KC_UP, KC_RGHT, KC_RGHT, KC_NO, KC_TRNS, KC_TRNS, KC_P1, KC_P2, KC_P3, KC_PEQL, KC_P0, KC_TRNS, KC_PLUS, KC_MINS, KC_EQL, KC_LBRC, KC_RBRC, KC_BSLS, KC_P0, KC_TRNS, MO(3), KC_TRNS, KC_TRNS, KC_TRNS, KC_DEL, KC_DEL),
	
	[3] = LAYOUT(KC_MUTE, KC_VOLD, KC_VOLU, KC_BRID, KC_BRIU, BL_TOGG, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_TRNS, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_TRNS, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_HOME, KC_PGDN, KC_PGUP, KC_END, KC_NO, KC_NO, KC_TRNS, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS)
};

// Make shift a little more sensitive
uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case HOME_A:
        case HOME_SCLN:
        case HOME_EXLM:
        case HOME_RPRN:
            return TAPPING_TERM - 25;
        default:
            return TAPPING_TERM;
    }
}

// commented this out because I could not get my third layer to work without doing that
//layer_state_t layer_state_set_user(layer_state_t state) {
//  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
//}

//SSD1306 OLED update loop, make sure to enable OLED_ENABLE=yes in rules.mk
#ifdef OLED_ENABLE

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
  if (!is_keyboard_master())
    return OLED_ROTATION_180;  // flips the display 180 degrees if offhand
  return rotation;
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

bool oled_task_user(void) {
  if (is_keyboard_master()) {
    // If you want to change the display of OLED, you need to change here
    oled_write_ln(read_layer_state(), false);
    oled_write_ln(read_keylog(), false);
    oled_write_ln(read_keylogs(), false);
    //oled_write_ln(read_mode_icon(keymap_config.swap_lalt_lgui), false);
    //oled_write_ln(read_host_led_state(), false);
    //oled_write_ln(read_timelog(), false);
  } else {
    oled_write(read_logo(), false);
  }
    return false;
}
#endif // OLED_ENABLE

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
	switch(keycode){
		case HOME_EXLM:
	  		if (record->event.pressed && record->tap.count > 0) {
		  		tap_code16(KC_EXLM);
		  		return false;
	  		}
			break;
		
		case HOME_AT:
	  		if (record->event.pressed && record->tap.count > 0) {
		  		tap_code16(KC_AT);
		  		return false;
	  		}
			break;
		
		case HOME_HASH:
	  		if (record->event.pressed && record->tap.count > 0) {
		  		tap_code16(KC_HASH);
		  		return false;
	  		}
			break;
		
		case HOME_DLR:
	  		if (record->event.pressed && record->tap.count > 0) {
		  		tap_code16(KC_DLR);
		  		return false;
	  		}
			break;
		
		case HOME_AMPR:
	  		if (record->event.pressed && record->tap.count > 0) {
		  		tap_code16(KC_AMPR);
		  		return false;
	  		}
			break;
		
		case HOME_ASTR:
	  		if (record->event.pressed && record->tap.count > 0) {
		  		tap_code16(KC_ASTR);
		  		return false;
	  		}
			break;
		
		case HOME_LPRN:
	  		if (record->event.pressed && record->tap.count > 0) {
		  		tap_code16(KC_LPRN);
		  		return false;
	  		}
			break;
		
		case HOME_RPRN:
	  		if (record->event.pressed && record->tap.count > 0) {
		  		tap_code16(KC_RPRN);
		  		return false;
	  		}
			break;
		
	}

  if (record->event.pressed) {
#ifdef OLED_ENABLE
    set_keylog(keycode, record);
#endif
    // set_timelog();
  }
  return true;
}
