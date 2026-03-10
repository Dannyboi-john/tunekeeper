#include "../lvgl/lvgl.h"
#include <stdio.h>
#include <string.h>
#include "../app_state.h"



lv_obj_t * create_bpm_dropdown(lv_obj_t * parent)
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

    /* Creating the label */
    lv_obj_t * bpm_label = lv_label_create(parent);
    lv_label_set_text(bpm_label, "BPM:");
    lv_obj_align_to(bpm_label, bpm_dd, LV_ALIGN_OUT_LEFT_MID, -10, 0);

    return bpm_dd;
}