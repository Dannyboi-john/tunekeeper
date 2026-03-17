#include "lvgl/lvgl.h"
#include "select.h"

static lv_style_t style_dd;

void select_dropdown_event_cb(lv_event_t * e)
{
    lv_obj_t * select_dropdown = lv_event_get_target_obj(e);
    char buf[64];
    lv_dropdown_get_selected_str(select_dropdown, buf, sizeof(buf));
    LV_LOG_USER("'%s' is selected", buf);
}

lv_obj_t * create_select_dropdown(lv_obj_t * parent)
{
    // Creating the select dropdown menu.
    lv_obj_t * select_dropdown = lv_dropdown_create(lv_screen_active());
    lv_obj_t * dropdown_list = lv_dropdown_get_list(select_dropdown);
    lv_obj_align(select_dropdown, LV_ALIGN_TOP_LEFT, lv_pct(32), 0);
    lv_dropdown_set_options(select_dropdown, "All\n"
                                        "None\n"
                                        "Tracks\n"
                                        "Region"
                                    );

    // Setting the fixed dropdown text
    lv_dropdown_set_text(select_dropdown, "Select");

    lv_dropdown_set_selected_highlight(select_dropdown, false);

    lv_obj_add_event_cb(select_dropdown, select_dropdown_event_cb, LV_EVENT_VALUE_CHANGED, NULL);

    // Styling the dropdown menu
    lv_obj_add_style(select_dropdown, &style_dd, LV_PART_MAIN);
    lv_obj_set_style_radius(select_dropdown, 1, LV_PART_MAIN);
    lv_obj_set_style_bg_color(select_dropdown, lv_color_hex(0x322D31), LV_PART_MAIN);
    lv_obj_set_style_border_width(select_dropdown, 0, LV_PART_MAIN);
    lv_obj_set_style_text_color(select_dropdown, lv_color_hex(0xD6CFC7), LV_PART_MAIN);

    //Styling the dropdown list
    lv_obj_add_style(dropdown_list, &style_dd, LV_PART_MAIN);
    lv_obj_set_style_radius(dropdown_list, 1, LV_PART_MAIN);
    lv_obj_set_style_bg_color(dropdown_list, lv_color_hex(0x322D31), LV_PART_MAIN);
    lv_obj_set_style_border_width(dropdown_list, 1, LV_PART_MAIN);
    lv_obj_set_style_text_color(dropdown_list, lv_color_hex(0xD6CFC7), LV_PART_MAIN);
}