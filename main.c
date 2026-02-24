#include "lvgl/lvgl.h"
#include <unistd.h>

int main(void)
{
    /* Initialize LVGL */
    lv_init();

    /* Initialize SDL display */
    lv_display_t * disp = lv_sdl_window_create(800, 480);

    /* Create a label */
    lv_obj_t * label = lv_label_create(lv_screen_active());
    lv_label_set_text(label, "HELLO LVGL v9 + SDL!@!!");
    lv_obj_center(label);

    while(1) {
        lv_timer_handler();
        usleep(5000);
    }

    return 0;
}