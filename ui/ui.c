#include "lvgl/lvgl.h"
#include "ui.h"
#include <stdio.h>
#include <stdbool.h>
#include <unistd.h>
#include "ui/images/icons.h"
#include "menu_bar_components/file.h"
#include "menu_bar_components/edit.h"
#include "menu_bar_components/select.h"
#include "header_components/play_button.h"
#include "header_components/stop_button.h"
#include "header_components/bpm_dd.h"
#include "header_components/record_button.h"
#include "header_components/settings_button.h"
#include "header_components/prev_button.h"
#include "header_components/next_button.h"
#include "tracklist_components/tl_area.h"
#include "tracklist_components/track.h"
#include "ui_utils.h"
#include "app_state.h"


// Imports the record icon / image
LV_IMAGE_DECLARE(record);


// Main function that creates the UI
void ui_init(void)
{
    lv_obj_t * screen = lv_screen_active();

    // Screen color setting
    lv_obj_set_style_bg_color(lv_screen_active(), lv_color_hex(0x48494B), LV_PART_MAIN);

    // Initialize mouse and keyboard while building - touch events later
    lv_sdl_mouse_create();
    lv_sdl_keyboard_create();

    // Centralizing state management / redraws
    static app_state_t app_state = {
        .is_paused = true,
        .play_button = NULL
    };


    // State management for the play button
    app_state.play_button = create_play_button(screen, &app_state);


    // Menu bar components
    lv_obj_t * file_dropdown = create_file_dropdown(screen);
    lv_obj_t * edit_dropdown = create_edit_dropdown(screen);
    lv_obj_t * select_dropdown = create_select_dropdown(screen);

    // Header components
    lv_obj_t * stop_button = create_stop_button(screen, &app_state);
    lv_obj_t * bpm_dd = create_bpm_dropdown(screen);
    lv_obj_t * record_button = create_record_button(screen);
    lv_obj_t * settings_button = create_settings_button(screen);
    lv_obj_t * prev_button = create_prev_button(screen);
    lv_obj_t * next_button = create_next_button(screen);

    // Track list segment
    lv_obj_t *track_list = create_track_list(screen);
}