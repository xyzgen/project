#include "../ui.h"

void ui_status_screen_init(void)
{
    ui_status = lv_obj_create(NULL);
    lv_obj_remove_flag(ui_status, LV_OBJ_FLAG_SCROLLABLE);    /// Flags
    lv_obj_set_style_bg_color(ui_status, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_t* label;
    static lv_style_t style_btn;
    lv_style_init(&style_btn);
    /* 设置圆角 */
    lv_style_set_radius(&style_btn,30);

    /* 设置背景颜色和透明度*/
    lv_style_set_bg_color(&style_btn, lv_color_hex(OFFBTN));
    lv_style_set_bg_opa(&style_btn,255);

    /* 设置阴影颜色和透明度*/
    lv_style_set_shadow_opa(&style_btn, 0);

    ui_status_wifiBtn = lv_button_create(ui_status);
    lv_obj_add_flag(ui_status_wifiBtn, LV_OBJ_FLAG_EVENT_BUBBLE);

    label = lv_label_create(ui_status_wifiBtn);
    lv_obj_add_flag(label, LV_OBJ_FLAG_EVENT_BUBBLE);
    lv_label_set_text(label, "");
    lv_obj_set_style_text_font(label, &lv_font_montserrat_32, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_center(label);

    lv_obj_add_style(ui_status_wifiBtn, &style_btn, LV_PART_MAIN );
    lv_obj_set_width(ui_status_wifiBtn, 100);
    lv_obj_set_height(ui_status_wifiBtn, 60);
    lv_obj_set_x(ui_status_wifiBtn, 10);
    lv_obj_set_y(ui_status_wifiBtn, 42);
    lv_obj_set_align(ui_status_wifiBtn, LV_ALIGN_TOP_LEFT);
    lv_obj_add_flag(ui_status_wifiBtn, LV_OBJ_FLAG_CHECKABLE);   /// Flags
    lv_obj_set_style_bg_color(ui_status_wifiBtn, lv_color_hex(LANDE), LV_PART_MAIN |LV_STATE_CHECKED);

    ui_status_blueToothBtn = lv_button_create(ui_status);
    lv_obj_add_flag(ui_status_blueToothBtn, LV_OBJ_FLAG_EVENT_BUBBLE);
    label = lv_label_create(ui_status_blueToothBtn);
    lv_label_set_text(label, "");
    lv_obj_set_style_text_font(label, &lv_font_montserrat_32, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_center(label);
    lv_obj_add_style(ui_status_blueToothBtn, &style_btn, LV_PART_MAIN);
    lv_obj_set_width(ui_status_blueToothBtn, 100);
    lv_obj_set_height(ui_status_blueToothBtn, 60);
    lv_obj_set_x(ui_status_blueToothBtn, 125);
    lv_obj_set_y(ui_status_blueToothBtn, 42);
    lv_obj_set_align(ui_status_blueToothBtn, LV_ALIGN_TOP_LEFT);
    lv_obj_add_flag(ui_status_blueToothBtn, LV_OBJ_FLAG_CHECKABLE);   /// Flags
    lv_obj_set_style_bg_color(ui_status_blueToothBtn, lv_color_hex(LANDE), LV_PART_MAIN | LV_STATE_CHECKED);

    ui_statusSlider = lv_slider_create(ui_status);
    lv_obj_add_flag(ui_statusSlider, LV_OBJ_FLAG_EVENT_BUBBLE);
    lv_obj_set_size(ui_statusSlider, 220, 50);
    lv_obj_align(ui_statusSlider,LV_ALIGN_CENTER,0,0);
    lv_slider_set_value(ui_statusSlider, 127, LV_ANIM_OFF);
    lv_slider_set_range(ui_statusSlider, 0, 255);
    lv_obj_set_style_bg_color(ui_statusSlider, lv_color_hex(0xFFFFFF), LV_PART_MAIN);
    lv_obj_set_style_bg_opa(ui_statusSlider, 80, LV_PART_MAIN);
    lv_obj_set_style_bg_color(ui_statusSlider, lv_color_hex(0xfafafa), LV_PART_INDICATOR);
    lv_obj_set_style_bg_opa(ui_statusSlider, 0, LV_PART_KNOB);
    
    lv_obj_t* ui_sliderImg = lv_image_create(ui_statusSlider);
    lv_obj_add_flag(ui_sliderImg, LV_OBJ_FLAG_EVENT_BUBBLE);
    lv_image_set_src(ui_sliderImg, &ui_img_bright_png);
    lv_obj_align(ui_sliderImg, LV_ALIGN_LEFT_MID,10,0);
    lv_obj_add_flag(ui_sliderImg, LV_OBJ_FLAG_CLICKABLE);   /// Flags
    lv_obj_remove_flag(ui_sliderImg, LV_OBJ_FLAG_SCROLLABLE);    /// Flags
    lv_obj_set_style_image_recolor(ui_sliderImg, lv_color_hex(0xECECEC), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_image_recolor_opa(ui_sliderImg, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_add_event_cb(ui_status, ui_event_status_return, LV_EVENT_ALL, NULL);

}
