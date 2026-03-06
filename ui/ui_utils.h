#ifndef UI_UTILS_H
#define UI_UTILS_H
#include "../lvgl/lvgl.h"

static inline void remove_padding(lv_obj_t *obj)
{
    lv_obj_set_style_pad_all(obj, 0, LV_PART_MAIN);
    lv_obj_set_style_pad_row(obj, 0, LV_PART_MAIN);
    lv_obj_set_style_pad_column(obj, 0, LV_PART_MAIN);
    lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN);
}

#endif