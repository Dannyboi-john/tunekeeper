#include "../lvgl/lvgl.h"
#include "next_button.h"

static lv_style_t style_button;

lv_obj_t * create_next_button(lv_obj_t * parent)
{
    /* Create the button */
    lv_obj_t * next_button = lv_button_create(parent);

    lv_style_init(&style_button);

    /* Adding the style to the button */
    lv_obj_add_style(next_button, &style_button, LV_PART_MAIN);

    lv_style_set_border_width(&style_button, 1);
    lv_style_set_border_color(&style_button, lv_color_black());
    lv_style_set_border_opa(&style_button, LV_OPA_50);
    lv_obj_set_style_radius(next_button, 1, LV_PART_MAIN);
    lv_obj_set_style_bg_color(next_button, lv_color_hex(0x322D31), LV_PART_MAIN);
    lv_obj_set_pos(next_button, lv_pct(24), 50);
    lv_obj_set_size(next_button, lv_pct(6), lv_pct(10));

    /* Label styling */
    lv_obj_t * next_label = lv_label_create(next_button);
    lv_label_set_text_fmt(next_label, LV_SYMBOL_NEXT);
    lv_obj_set_style_text_color(next_label, lv_color_hex(0xff0000), 0);
    lv_obj_center(next_label);

    return next_button;
}