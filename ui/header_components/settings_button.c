#include "../lvgl/lvgl.h"
#include "settings_button.h"

static lv_style_t style_button;

lv_obj_t * create_settings_button(lv_obj_t * parent)
{
    lv_obj_t * settings_button = lv_button_create(parent);
    

    /* Label styling */
    lv_obj_t * settings_label = lv_label_create(settings_button);
    lv_label_set_text_fmt(settings_label, LV_SYMBOL_SETTINGS);
    lv_obj_set_style_text_color(settings_label, lv_color_hex(0xff0000), 0);
    lv_obj_center(settings_label);

    /* Button styling */
    lv_style_init(&style_button);
    lv_obj_add_style(settings_button, &style_button, LV_PART_MAIN);

    lv_style_set_border_width(&style_button, 1);
    lv_style_set_border_color(&style_button, lv_color_black());
    lv_style_set_border_opa(&style_button, LV_OPA_50);
    lv_obj_set_style_radius(settings_button, 1, LV_PART_MAIN);
    lv_obj_set_style_bg_color(settings_button, lv_color_hex(0x322D31), LV_PART_MAIN);
    lv_obj_align(settings_button, LV_ALIGN_TOP_RIGHT, 0, 50);

    lv_obj_set_size(settings_button, lv_pct(6), lv_pct(10));

    return settings_button;
}