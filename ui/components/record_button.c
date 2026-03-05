#include "../lvgl/lvgl.h"
#include "record_button.h"
#include "ui/images/icons.h"

static lv_style_t style_button;

LV_IMAGE_DECLARE(record);

lv_obj_t * create_record_button(lv_obj_t * parent)
{
    /* Create the button */
    lv_obj_t * record_button = lv_button_create(parent);

    lv_style_init(&style_button);

    /* Adding the style to the button */
    lv_obj_add_style(record_button, &style_button, LV_PART_MAIN);

    lv_style_set_border_width(&style_button, 1);
    lv_style_set_border_color(&style_button, lv_color_black());
    lv_style_set_border_opa(&style_button, LV_OPA_50);
    lv_obj_set_style_radius(record_button, 1, LV_PART_MAIN);
    lv_obj_set_style_bg_color(record_button, lv_color_hex(0x322D31), LV_PART_MAIN);
    lv_obj_set_pos(record_button, 0, 0);

    lv_obj_set_size(record_button, lv_pct(6), lv_pct(10));
    lv_obj_t * record_icon = lv_image_create(record_button);

    /* Setting icon to button */
    lv_image_set_src(record_icon, &record);
    lv_obj_center(record_icon);

    /* Scaling the img down a little bit */
    lv_image_set_scale(record_icon, 128);

    return record_button;
}