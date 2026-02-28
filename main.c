#include "lvgl/lvgl.h"
#include <unistd.h>
#include <stdio.h>
#include <stdbool.h>

/* Declaration of the label + bool */
static lv_obj_t * my_label1;
static bool isPlaying = true;


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


int main(void)
{
    /* Initialize LVGL */
    lv_init();
    fflush(stdout);

    /* Initialize SDL display */
    lv_display_t * disp = lv_sdl_window_create(800, 480);

    /* Screen color setting */
    lv_obj_set_style_bg_color(lv_screen_active(), lv_color_hex(0x4D4C5C), LV_PART_MAIN);

    
    /* Initialize mouse and keyboard */
    lv_sdl_mouse_create();
    lv_sdl_keyboard_create();

    /* Creating a button */
    lv_obj_t * my_button1 = lv_button_create(lv_screen_active());
    /* Set parent-sized witdth, and content-sized height */
    lv_obj_set_size(my_button1, LV_SIZE_CONTENT, lv_pct(10));
    /* Align to the center */
    lv_obj_align(my_button1, LV_ALIGN_TOP_LEFT, 0, 0);
    /* Attaching the callback function inside main() */
    lv_obj_add_event_cb(my_button1, btn_event_cb, LV_EVENT_CLICKED, NULL);
    /* Button background color */
    lv_obj_set_style_bg_color(my_button1, lv_color_hex(0x322D31), LV_PART_MAIN);

    /* Create a label for the button */
    my_label1 = lv_label_create(my_button1);
    lv_label_set_text_fmt(my_label1, LV_SYMBOL_PLAY);
    lv_obj_set_style_text_color(my_label1, lv_color_hex(0xff0000), 0);

    while(1) {
        lv_timer_handler();
        usleep(5000);
    }

    return 0;
}