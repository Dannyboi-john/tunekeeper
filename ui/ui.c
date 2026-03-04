#include "lvgl/lvgl.h"
#include "ui.h"
#include <stdio.h>
#include <stdbool.h>
#include <unistd.h>
#include "ui/images/icons.h"
#include "components/play_button.h"
#include "components/stop_button.h"
#include "components/bpm_dd.h"
#include "app_state.h"


/* Button styling */
static lv_style_t style_button;

/* Record image import */
LV_IMAGE_DECLARE(record);

static lv_obj_t * create_record_button(lv_obj_t * parent)
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


