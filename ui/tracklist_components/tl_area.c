#include "../lvgl/lvgl.h"
#include "tl_area.h"
#include "track.h"
#include <stdio.h>


// Logic for "Create track" button
void create_track_button_cb(lv_event_t * e)
{
    lv_obj_t *btn = lv_event_get_target(e);
    lv_obj_t *parent = (lv_obj_t *)lv_event_get_user_data(e);
    char track_label[32];
    snprintf(track_label, sizeof(track_label), "Track %d", lv_obj_get_index(btn) + 1);

    const int index = lv_obj_get_index(btn);
    printf("%d\n", index);
    create_track(parent, track_label);

    lv_obj_move_to_index(btn, -1);

}


// Track list area component
lv_obj_t *create_track_list(lv_obj_t * parent)
{
    lv_obj_t *track_list_area = lv_obj_create(lv_screen_active());
    lv_obj_set_size(track_list_area, LV_PCT(100), LV_PCT(80));
    lv_obj_set_flex_flow(track_list_area, LV_FLEX_FLOW_COLUMN);
    lv_obj_set_flex_align(track_list_area, LV_FLEX_ALIGN_START, LV_FLEX_ALIGN_START, LV_FLEX_ALIGN_START);
    lv_obj_align(track_list_area, LV_ALIGN_BOTTOM_MID, 0, 0);
    lv_obj_set_style_bg_color(track_list_area, lv_color_hex(0x373642), LV_PART_MAIN);
    lv_obj_set_style_pad_all(track_list_area, 0, LV_PART_MAIN);
    lv_obj_set_style_border_width(track_list_area, 0, LV_PART_MAIN);

    // Create & style create track button
    lv_obj_t *create_track_button = lv_button_create(track_list_area);
    lv_obj_set_size(create_track_button, LV_PCT(30), 100);
    lv_obj_set_style_radius(create_track_button, 1, LV_PART_MAIN);
    lv_obj_set_style_bg_color(create_track_button, lv_color_hex(0x322D31), LV_PART_MAIN);

    // Create & style label for create track button
    lv_obj_t *create_track_button_label = lv_label_create(create_track_button);
    lv_label_set_text(create_track_button_label, LV_SYMBOL_PLUS);
    lv_obj_set_style_text_color(create_track_button_label, lv_color_hex(0xff0000), 0);
    lv_obj_center(create_track_button_label);
    lv_obj_add_event_cb(create_track_button, create_track_button_cb, LV_EVENT_CLICKED, track_list_area);

    return track_list_area;
}