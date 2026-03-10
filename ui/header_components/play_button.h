#ifndef PLAY_BUTTON_H
#define PLAY_BUTTON_H

#include "lvgl/lvgl.h"
#include "../app_state.h"

lv_obj_t * create_play_button(lv_obj_t * parent, app_state_t * state);

// Allowing other files to update state of play icon
void play_button_update(lv_obj_t * play_button, app_state_t * state);

#endif