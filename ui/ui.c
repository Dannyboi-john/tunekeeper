#include "lvgl/lvgl.h"
#include "ui.h"
#include <stdio.h>
#include <stdbool.h>
#include <unistd.h>
#include "ui/images/icons.h"
#include "components/play_button.h"
#include "components/stop_button.h"
#include "components/bpm_dd.h"
#include "components/record_button.h"
#include "components/settings_button.h"
#include "app_state.h"

LV_IMAGE_DECLARE(record);


lv_obj_t *create_track_list(lv_obj_t * parent)
{
    lv_obj_t *track_list_area = lv_obj_create(lv_screen_active());
    lv_obj_set_size(track_list_area, LV_PCT(100), LV_PCT(80));
    lv_obj_set_flex_flow(track_list_area, LV_FLEX_FLOW_COLUMN);
    lv_obj_set_flex_align(track_list_area, LV_FLEX_ALIGN_START, LV_FLEX_ALIGN_START, LV_FLEX_ALIGN_START);
    lv_obj_align(track_list_area, LV_ALIGN_BOTTOM_MID, 0, 0);

    return track_list_area;
}


lv_obj_t* create_track(lv_obj_t *parent, const char *name) {
    lv_obj_t *track = lv_obj_create(parent);
    lv_obj_set_size(track, LV_PCT(100), 60);
    lv_obj_set_flex_flow(track, LV_FLEX_FLOW_ROW);
    lv_obj_set_flex_align(track, LV_FLEX_ALIGN_START, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER);

    /* Arm button */
    lv_obj_t *arm_button = lv_button_create(track);
    lv_obj_set_size(arm_button, 40, 40);
    lv_obj_t *arm_label = lv_label_create(arm_button);
    lv_label_set_text(arm_label, LV_SYMBOL_AUDIO);
    lv_obj_center(arm_label);

    /* Track name button */
    lv_obj_t *name_button = lv_button_create(track);
    lv_obj_set_size(name_button, 120, 40);
    lv_obj_t *name_label = lv_label_create(name_button);
    lv_label_set_text(name_label, "Track 1");
    lv_obj_center(name_label);

    /* Volume slider */
    lv_obj_t *slider = lv_slider_create(track);
    lv_obj_set_size(slider, 150, 10);
    lv_slider_set_range(slider, 0, 100);
    lv_slider_set_value(slider, 80, LV_ANIM_OFF);

    /* Delete button */
    lv_obj_t *delete_button = lv_button_create(track);
    lv_obj_set_size(delete_button, 40, 40);
    lv_obj_t *delete_label = lv_label_create(delete_button);
    lv_label_set_text(delete_label, LV_SYMBOL_TRASH);
    lv_obj_center(delete_label);

    return track;
}


void ui_init(void)
{
    lv_obj_t * screen = lv_screen_active();
    /* Screen color setting */
    lv_obj_set_style_bg_color(lv_screen_active(), lv_color_hex(0x4D4C5C), LV_PART_MAIN);

    /* Initialize mouse and keyboard while building - touch events later */
    lv_sdl_mouse_create();
    lv_sdl_keyboard_create();

    // Centralizing state management / redraws
    static app_state_t app_state = {
        .is_paused = true,
        .play_button = NULL
    };

    app_state.play_button = create_play_button(screen, &app_state);

    // lv_obj_t * play_button = create_play_button(screen, &app_state);
    lv_obj_t * stop_button = create_stop_button(screen, &app_state);
    lv_obj_t * bpm_dd = create_bpm_dropdown(screen);
    lv_obj_t * record_button = create_record_button(screen);
    lv_obj_t * settings_button = create_settings_button(screen);
    create_track_list(screen);
}
