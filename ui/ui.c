#include "lvgl/lvgl.h"
#include "ui.h"
#include <stdio.h>
#include <stdbool.h>
#include <unistd.h>


/* Declaration of the label + bool */
static lv_obj_t * my_label1;
static bool isPlaying = true;
static lv_obj_t * my_label2;



/* Callback function that handles play / pause click events */
static void btn_event_cb(lv_event_t * e)
{
    lv_event_code_t code = lv_event_get_code(e);

    if(code == LV_EVENT_CLICKED) {

        if (isPlaying) {
            fprintf(stderr, "Event Fired\n");
            lv_label_set_text_fmt(my_label1, LV_SYMBOL_PAUSE);
            isPlaying = !isPlaying;

        } else {
            fprintf(stderr, "Event Fired\n");
            lv_label_set_text_fmt(my_label1, LV_SYMBOL_PLAY);
            isPlaying = !isPlaying;
        }

    }
}


/* Creating separate function for play/pause */
static lv_obj_t * create_play_button(lv_obj_t * parent)
{
    /* Create the button */
    lv_obj_t * play_button = lv_button_create(parent);

    /* Attach the callback */
    lv_obj_add_event_cb(play_button, btn_event_cb, LV_EVENT_CLICKED, NULL);

    /* Label styling */
    my_label1 = lv_label_create(play_button);
    lv_label_set_text_fmt(my_label1, LV_SYMBOL_PLAY);
    lv_obj_set_style_text_color(my_label1, lv_color_hex(0xff0000), 0);

    /* Button styling */
    lv_obj_set_size(play_button, lv_pct(6), lv_pct(10));
    /* Align to the top left */
    lv_obj_set_pos(play_button, 0, 0);
    lv_obj_set_style_bg_color(play_button, lv_color_hex(0x322D31), LV_PART_MAIN);
    
    return play_button;
}


static lv_obj_t * create_stop_button(lv_obj_t * parent)
{
   /* Create the button */
    lv_obj_t * stop_button = lv_button_create(parent);

    /* Label styling */
    my_label2 = lv_label_create(stop_button);
    lv_label_set_text_fmt(my_label2, LV_SYMBOL_STOP);
    lv_obj_set_style_text_color(my_label2, lv_color_hex(0xff0000), 0);

    /* Button styling */
    lv_obj_set_size(stop_button, LV_SIZE_CONTENT, lv_pct(10));
    lv_obj_set_style_bg_color(stop_button, lv_color_hex(0x322D31), LV_PART_MAIN);
    
    return stop_button;
}


static lv_obj_t * create_bpm_dropdown(lv_obj_t * parent)
{
    lv_obj_t * bpm_dd = lv_dropdown_create(parent);
    lv_dropdown_clear_options(bpm_dd);
    lv_obj_align(bpm_dd, LV_ALIGN_TOP_MID, 0, 0);

    for (int i = 20; i <= 200; i++) {
        char buffer[16];
        snprintf(buffer, sizeof(buffer), "%d", i);
        lv_dropdown_add_option(bpm_dd, buffer, LV_DROPDOWN_POS_LAST);
    }

    lv_dropdown_set_selected(bpm_dd, 120 - 20);

    return bpm_dd;
}


void ui_init(void)
{

    lv_obj_t * screen = lv_screen_active();
    /* Screen color setting */
    lv_obj_set_style_bg_color(lv_screen_active(), lv_color_hex(0x4D4C5C), LV_PART_MAIN);

    /* Initialize mouse and keyboard while building - touch events later */
    lv_sdl_mouse_create();
    lv_sdl_keyboard_create();

    lv_obj_t * play_button = create_play_button(screen);
    lv_obj_t * stop_button = create_stop_button(screen);
    lv_obj_t * bpm_dd = create_bpm_dropdown(screen);

    lv_obj_align_to(stop_button, play_button, LV_ALIGN_RIGHT_MID, 80, 0);

}


