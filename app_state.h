#ifndef APP_STATE_H
#define APP_STATE_H

#include "lvgl/lvgl.h"

#include <stdbool.h>

typedef struct {
    bool is_paused;
    lv_obj_t * play_button;
} app_state_t;

#endif