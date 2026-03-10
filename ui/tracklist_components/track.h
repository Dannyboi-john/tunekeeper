#ifndef TRACK_H
#define TRACK_H
#include <unistd.h>

#include "lvgl/lvgl.h"

lv_obj_t* create_track(lv_obj_t *parent, const char *name);

#endif