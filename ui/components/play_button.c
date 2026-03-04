#include "play_button.h"
#include "../lvgl/lvgl.h"
#include <stdio.h>
#include <string.h>

static lv_style_t style_button;

static void play_button_event_cb(lv_event_t * e)
{
    lv_obj_t * label = lv_event_get_user_data(e);

    if (lv_event_get_code(e) == LV_EVENT_CLICKED ) {

        const char * current = lv_label_get_text(label);

        if (strcmp(lv_label_get_text(label), LV_SYMBOL_PLAY) == 0) {
            lv_label_set_text(label, LV_SYMBOL_PAUSE);
        } else {
            lv_label_set_text(label, LV_SYMBOL_PLAY);
        }

    }
}

/* Creating separate function for play/pause */
lv_obj_t * create_play_button(lv_obj_t * parent)
{
    /* Create the button */
    lv_obj_t * play_button = lv_button_create(parent);
    lv_obj_t * play_label = lv_label_create(play_button);

    /* Attach the callback */
    lv_obj_add_event_cb(play_button, play_button_event_cb, LV_EVENT_CLICKED, play_label);
    lv_style_init(&style_button);

    /* Adding the style to the button */
    lv_obj_add_style(play_button, &style_button, LV_PART_MAIN);

    /* Label styling */
    lv_label_set_text_fmt(play_label, LV_SYMBOL_PLAY);
    lv_obj_set_style_text_color(play_label, lv_color_hex(0xff0000), 0);

    /* Button styling */
    lv_obj_set_style_radius(play_button, 1, LV_PART_MAIN);
    lv_obj_set_style_bg_color(play_button, lv_color_hex(0x322D31), LV_PART_MAIN);
    lv_obj_set_size(play_button, lv_pct(6), lv_pct(10));
    lv_obj_center(play_label);
    lv_style_set_border_width(&style_button, 1);
    lv_style_set_border_color(&style_button, lv_color_black());

    /* Align to the top left */
    lv_obj_set_pos(play_button, lv_pct(6), 0);
    
    return play_button;
}