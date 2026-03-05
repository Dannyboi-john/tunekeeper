#include "../lvgl/lvgl.h"
#include "stop_button.h"
#include <stdio.h>
#include <string.h>
#include "../components/play_button.h"
#include "../app_state.h"

static lv_style_t style_button;

static void stop_button_event_cb(lv_event_t * e)
{
    app_state_t * state = lv_event_get_user_data(e);

    if (lv_event_get_code(e) == LV_EVENT_CLICKED && !state->is_paused) {
        state->is_paused = true;

        // Refresh the play button label
        if (state->play_button) {
            play_button_update(state->play_button, state);
        }
    }
}

lv_obj_t * create_stop_button(lv_obj_t * parent, app_state_t * state)
{
   /* Create the button */
    lv_obj_t * stop_button = lv_button_create(parent);
    lv_style_init(&style_button);

    /* Label styling */
    lv_obj_t * stop_label = lv_label_create(stop_button);
    lv_label_set_text_fmt(stop_label, LV_SYMBOL_STOP);

    /* Adding event callbalck */
    lv_obj_add_event_cb(stop_button, stop_button_event_cb, LV_EVENT_CLICKED, state);
    lv_obj_set_style_text_color(stop_label, lv_color_hex(0xff0000), 0);
    lv_obj_center(stop_label);

    /* Adding the style to the button */
    lv_obj_add_style(stop_button, &style_button, LV_PART_MAIN);

    /* Button styling */
    lv_obj_set_size(stop_button, lv_pct(6), lv_pct(10));
    lv_obj_set_style_bg_color(stop_button, lv_color_hex(0x322D31), LV_PART_MAIN);
    lv_obj_set_pos(stop_button, lv_pct(12), 0);
    lv_obj_set_style_radius(stop_button, 1, LV_PART_MAIN);
    lv_style_set_border_width(&style_button, 1);
    lv_style_set_border_color(&style_button, lv_color_black());
    
    return stop_button;
}