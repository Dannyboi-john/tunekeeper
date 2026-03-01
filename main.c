#include "lvgl/lvgl.h"
#include <unistd.h>
#include "ui/ui.h"
#include <stdio.h>


int main(void)
{
    /* Initialize LVGL */
    lv_init();
    fflush(stdout);

    /* Initialize SDL display */
    lv_display_t * disp = lv_sdl_window_create(800, 480);
    ui_init();

    while(1) {
        lv_timer_handler();
        usleep(5000);
    }

    return 0;
}