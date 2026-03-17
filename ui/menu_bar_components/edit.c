#include "lvgl/lvgl.h"
#include "edit.h"

static lv_style_t style_dd;

void edit_dropdown_event_cb(lv_event_t * e)
{
    lv_obj_t * edit_dropdown = lv_event_get_target_obj(e);
    char buf[64];
    lv_dropdown_get_selected_str(edit_dropdown, buf, sizeof(buf));
    LV_LOG_USER("'%s' is selected", buf);
}

lv_obj_t * create_edit_dropdown(lv_obj_t * parent)
{
    // Creating the edit dropdown menu.
    lv_obj_t * edit_dropdown = lv_dropdown_create(lv_screen_active());
    lv_obj_t * dropdown_list = lv_dropdown_get_list(edit_dropdown);
    lv_obj_align(edit_dropdown, LV_ALIGN_TOP_LEFT, lv_pct(17), 0);
    lv_dropdown_set_options(edit_dropdown, "Undo\n"
                                        "Redo\n"
                                        "Cut\n"
                                        "Delete\n"
                                        "Copy\n"
                                        "Paste"
                                    );

    // Setting the fixed dropdown text
    lv_dropdown_set_text(edit_dropdown, "Edit");

    lv_dropdown_set_selected_highlight(edit_dropdown, false);

    lv_obj_add_event_cb(edit_dropdown, edit_dropdown_event_cb, LV_EVENT_VALUE_CHANGED, NULL);

    // Styling the dropdown menu
    lv_obj_add_style(edit_dropdown, &style_dd, LV_PART_MAIN);
    lv_obj_set_style_radius(edit_dropdown, 1, LV_PART_MAIN);
    lv_obj_set_style_bg_color(edit_dropdown, lv_color_hex(0x322D31), LV_PART_MAIN);
    lv_obj_set_style_border_width(edit_dropdown, 0, LV_PART_MAIN);
    lv_obj_set_style_text_color(edit_dropdown, lv_color_hex(0xD6CFC7), LV_PART_MAIN);

    //Styling the dropdown list
    lv_obj_add_style(dropdown_list, &style_dd, LV_PART_MAIN);
    lv_obj_set_style_radius(dropdown_list, 1, LV_PART_MAIN);
    lv_obj_set_style_bg_color(dropdown_list, lv_color_hex(0x322D31), LV_PART_MAIN);
    lv_obj_set_style_border_width(dropdown_list, 1, LV_PART_MAIN);
    lv_obj_set_style_text_color(dropdown_list, lv_color_hex(0xD6CFC7), LV_PART_MAIN);
}