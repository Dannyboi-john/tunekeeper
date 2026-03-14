#include "lvgl/lvgl.h"
#include "track.h"
#include <unistd.h>

lv_obj_t* create_track(lv_obj_t *parent, const char *name) {

    // Instantiates & styles the track
    lv_obj_t *track = lv_obj_create(parent);
    lv_obj_set_size(track, LV_PCT(30), 120);
    lv_obj_set_flex_flow(track, LV_FLEX_FLOW_COLUMN);
    lv_obj_set_flex_align(track, LV_FLEX_ALIGN_START, LV_FLEX_ALIGN_START, LV_FLEX_ALIGN_START);
    lv_obj_set_style_pad_all(track, 0, LV_PART_MAIN);
    lv_obj_set_style_radius(track, 1, LV_PART_MAIN);
    lv_obj_set_style_bg_color(track, lv_color_hex(0x3E424B), LV_PART_MAIN);
    lv_obj_set_style_border_width(track, 0, LV_PART_MAIN);


    // Row 1 buttons
    lv_obj_t *button_row = lv_obj_create(track);
    lv_obj_set_size(button_row, LV_PCT(100), 50);
    lv_obj_set_flex_flow(button_row, LV_FLEX_FLOW_ROW);
    lv_obj_set_flex_align(button_row, LV_FLEX_ALIGN_START, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER);
    lv_obj_set_style_pad_all(button_row, 0, LV_PART_MAIN);
    lv_obj_set_style_bg_color(button_row, lv_color_hex(0x3E424B), LV_PART_MAIN);
    lv_obj_set_style_border_width(button_row, 0, LV_PART_MAIN);

    // Arm button
    lv_obj_t *arm_button = lv_button_create(button_row);
    lv_obj_set_size(arm_button, 40, 40);
    lv_obj_t *arm_label = lv_label_create(arm_button);
    lv_label_set_text(arm_label, LV_SYMBOL_AUDIO);
    lv_obj_center(arm_label);
    lv_obj_set_style_radius(arm_button, 1, LV_PART_MAIN);

    // Track name button
    lv_obj_t *name_button = lv_button_create(button_row);
    lv_obj_set_size(name_button, 120, 40);
    lv_obj_t *name_label = lv_label_create(name_button);
    lv_label_set_text(name_label, "Track 1");
    lv_obj_center(name_label);
    lv_obj_set_style_radius(name_button, 1, LV_PART_MAIN);

    // Delete button
    lv_obj_t *delete_button = lv_button_create(button_row);
    lv_obj_set_size(delete_button, 40, 40);
    lv_obj_t *delete_label = lv_label_create(delete_button);
    lv_label_set_text(delete_label, LV_SYMBOL_TRASH);
    lv_obj_center(delete_label);
    lv_obj_set_style_radius(delete_button, 1, LV_PART_MAIN);

    // Row 2: volume slider
    lv_obj_t *slider_row = lv_obj_create(track);
    lv_obj_set_size(slider_row, LV_PCT(100), 40);
    lv_obj_set_flex_flow(slider_row, LV_FLEX_FLOW_ROW);
    lv_obj_set_flex_align(slider_row, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER);

    // Volume slider
    lv_obj_t *slider = lv_slider_create(slider_row);
    lv_obj_set_size(slider, lv_pct(90), 10);
    lv_slider_set_range(slider, 0, 100);
    lv_slider_set_value(slider, 80, LV_ANIM_OFF);
    lv_obj_set_style_pad_all(slider_row, 0, LV_PART_MAIN);
    lv_obj_set_style_bg_color(slider_row, lv_color_hex(0x3E424B), LV_PART_MAIN);
    lv_obj_set_style_border_width(slider_row, 0, LV_PART_MAIN);
    return track;
}