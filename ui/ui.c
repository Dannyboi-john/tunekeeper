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
#include "app_state.h"


/* Button styling */
static lv_style_t style_button;


void ui_init(void)
{

    lv_obj_t * screen = lv_screen_active();
    /* Screen color setting */
    lv_obj_set_style_bg_color(lv_screen_active(), lv_color_hex(0x4D4C5C), LV_PART_MAIN);

    /* Initialize mouse and keyboard while building - touch events later */
    lv_sdl_mouse_create();
    lv_sdl_keyboard_create();

    static app_state_t app_state = {
        .is_paused = true,
        .play_button = NULL
    };

    app_state.play_button = create_play_button(screen, &app_state);

    // lv_obj_t * play_button = create_play_button(screen, &app_state);
    lv_obj_t * stop_button = create_stop_button(screen, &app_state);
    lv_obj_t * bpm_dd = create_bpm_dropdown(screen);
    lv_obj_t * record_button = create_record_button(screen);
}


