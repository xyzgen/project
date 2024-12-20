﻿// This file was generated by SquareLine Studio
// SquareLine Studio version: SquareLine Studio 1.5.0
// LVGL version: 9.1.0
// Project name: SquareLine_Project

#include "../ui.h"

void ui_aroma_screen_init(void)
{
ui_aroma = lv_obj_create(NULL);
lv_obj_remove_flag( ui_aroma, LV_OBJ_FLAG_SCROLLABLE );    /// Flags

ui_aromaPer = lv_arc_create(ui_aroma);
lv_obj_set_width( ui_aromaPer, 150);
lv_obj_set_height( ui_aromaPer, 150);
lv_obj_set_x( ui_aromaPer, 0 );
lv_obj_set_y( ui_aromaPer, -49 );
lv_obj_set_align( ui_aromaPer, LV_ALIGN_CENTER );
lv_arc_set_range(ui_aromaPer, 0,20);
lv_arc_set_value(ui_aromaPer, 10);
lv_arc_set_bg_angles(ui_aromaPer,0,360);
lv_arc_set_rotation(ui_aromaPer,120);
lv_obj_set_style_arc_rounded(ui_aromaPer, false, LV_PART_MAIN| LV_STATE_DEFAULT);

lv_obj_set_style_arc_color(ui_aromaPer, lv_color_hex(0xF4CE98), LV_PART_INDICATOR | LV_STATE_DEFAULT );
lv_obj_set_style_arc_opa(ui_aromaPer, 255, LV_PART_INDICATOR| LV_STATE_DEFAULT);
lv_obj_set_style_arc_width(ui_aromaPer, 12, LV_PART_INDICATOR| LV_STATE_DEFAULT);
lv_obj_set_style_arc_rounded(ui_aromaPer, false, LV_PART_INDICATOR| LV_STATE_DEFAULT);

lv_obj_set_style_bg_color(ui_aromaPer, lv_color_hex(0xFFFFFF), LV_PART_KNOB | LV_STATE_DEFAULT );
lv_obj_set_style_bg_opa(ui_aromaPer, 0, LV_PART_KNOB| LV_STATE_DEFAULT);

ui_curaromaPerLab = lv_label_create(ui_aromaPer);
lv_obj_set_width( ui_curaromaPerLab, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_curaromaPerLab, LV_SIZE_CONTENT);   /// 1
lv_obj_set_align( ui_curaromaPerLab, LV_ALIGN_CENTER );
lv_label_set_text(ui_curaromaPerLab,"10");
lv_obj_set_style_text_font(ui_curaromaPerLab, &ui_font_Chinese32B, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_setaromaPerLab = lv_label_create(ui_aromaPer);
lv_obj_set_width( ui_setaromaPerLab, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_setaromaPerLab, LV_SIZE_CONTENT);   /// 1
lv_obj_set_x( ui_setaromaPerLab, 0 );
lv_obj_set_y( ui_setaromaPerLab, 30 );
lv_obj_set_align( ui_setaromaPerLab, LV_ALIGN_TOP_MID );
lv_label_set_text(ui_setaromaPerLab,"设置强度");
lv_obj_set_style_text_color(ui_setaromaPerLab, lv_color_hex(0x919191), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_text_opa(ui_setaromaPerLab, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_font(ui_setaromaPerLab, &ui_font_Chinese16B, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_addaromaPer = lv_button_create(ui_aroma);
lv_obj_set_width( ui_addaromaPer, 32);
lv_obj_set_height( ui_addaromaPer, 32);
lv_obj_set_x( ui_addaromaPer, 80 );
lv_obj_set_y( ui_addaromaPer, 20 );
lv_obj_set_align( ui_addaromaPer, LV_ALIGN_CENTER );
lv_obj_add_flag( ui_addaromaPer, LV_OBJ_FLAG_SCROLL_ON_FOCUS );   /// Flags
lv_obj_remove_flag( ui_addaromaPer, LV_OBJ_FLAG_SCROLLABLE );    /// Flags
lv_obj_set_style_radius(ui_addaromaPer, 16, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_bg_color(ui_addaromaPer, lv_color_hex(0xE2E1E1), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_bg_opa(ui_addaromaPer, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_shadow_color(ui_addaromaPer, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_shadow_opa(ui_addaromaPer, 0, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_addaromaPerLab = lv_label_create(ui_addaromaPer);
lv_obj_set_width( ui_addaromaPerLab, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_addaromaPerLab, LV_SIZE_CONTENT);   /// 1
lv_obj_set_x( ui_addaromaPerLab, 0 );
lv_obj_set_y( ui_addaromaPerLab, -1 );
lv_obj_set_align( ui_addaromaPerLab, LV_ALIGN_CENTER );
lv_label_set_text(ui_addaromaPerLab,"+");
lv_obj_set_style_text_color(ui_addaromaPerLab, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_text_opa(ui_addaromaPerLab, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_font(ui_addaromaPerLab, &ui_font_Chinese16B, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_difaromaPer = lv_button_create(ui_aroma);
lv_obj_set_width( ui_difaromaPer, 32);
lv_obj_set_height( ui_difaromaPer, 32);
lv_obj_set_x( ui_difaromaPer, -85 );
lv_obj_set_y( ui_difaromaPer, 20 );
lv_obj_set_align( ui_difaromaPer, LV_ALIGN_CENTER );
lv_obj_add_flag( ui_difaromaPer, LV_OBJ_FLAG_SCROLL_ON_FOCUS );   /// Flags
lv_obj_remove_flag( ui_difaromaPer, LV_OBJ_FLAG_SCROLLABLE );    /// Flags
lv_obj_set_style_radius(ui_difaromaPer, 16, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_bg_color(ui_difaromaPer, lv_color_hex(0xE2E1E1), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_bg_opa(ui_difaromaPer, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_shadow_color(ui_difaromaPer, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_shadow_opa(ui_difaromaPer, 0, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_difaromaPerLab = lv_label_create(ui_difaromaPer);
lv_obj_set_width( ui_difaromaPerLab, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_difaromaPerLab, LV_SIZE_CONTENT);   /// 1
lv_obj_set_x( ui_difaromaPerLab, 0 );
lv_obj_set_y( ui_difaromaPerLab, -1 );
lv_obj_set_align( ui_difaromaPerLab, LV_ALIGN_CENTER );
lv_label_set_text(ui_difaromaPerLab,"-");
lv_obj_set_style_text_color(ui_difaromaPerLab, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_text_opa(ui_difaromaPerLab, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_font(ui_difaromaPerLab, &ui_font_Chinese16B, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_aromaStatus = lv_obj_create(ui_aroma);
lv_obj_set_width( ui_aromaStatus, 199);
lv_obj_set_height( ui_aromaStatus, 50);
lv_obj_set_x( ui_aromaStatus, 0 );
lv_obj_set_y( ui_aromaStatus, 72 );
lv_obj_set_align( ui_aromaStatus, LV_ALIGN_CENTER );
lv_obj_remove_flag( ui_aromaStatus, LV_OBJ_FLAG_SCROLLABLE );    /// Flags
lv_obj_set_style_radius(ui_aromaStatus, 3, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_border_color(ui_aromaStatus, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_border_opa(ui_aromaStatus, 255, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_aromaStatusLab = lv_label_create(ui_aromaStatus);
lv_obj_set_width( ui_aromaStatusLab, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_aromaStatusLab, LV_SIZE_CONTENT);   /// 1
lv_obj_set_align( ui_aromaStatusLab, LV_ALIGN_BOTTOM_LEFT );
lv_label_set_text(ui_aromaStatusLab,"运行中 ");
lv_obj_set_style_text_color(ui_aromaStatusLab, lv_color_hex(0x919191), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_text_opa(ui_aromaStatusLab, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_font(ui_aromaStatusLab, &ui_font_Chinese16B, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_aromaStatusBtn = lv_button_create(ui_aromaStatus);
lv_obj_set_width( ui_aromaStatusBtn, 32);
lv_obj_set_height( ui_aromaStatusBtn, 32);
lv_obj_set_x( ui_aromaStatusBtn, 76 );
lv_obj_set_y( ui_aromaStatusBtn, 1 );
lv_obj_set_align( ui_aromaStatusBtn, LV_ALIGN_CENTER );
lv_obj_add_flag( ui_aromaStatusBtn, LV_OBJ_FLAG_SCROLL_ON_FOCUS );   /// Flags
lv_obj_remove_flag( ui_aromaStatusBtn, LV_OBJ_FLAG_SCROLLABLE );    /// Flags
lv_obj_set_style_radius(ui_aromaStatusBtn, 16, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_bg_color(ui_aromaStatusBtn, lv_color_hex(0xF4CE98), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_bg_opa(ui_aromaStatusBtn, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_shadow_color(ui_aromaStatusBtn, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_shadow_opa(ui_aromaStatusBtn, 0, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_aromaStatusImg = lv_image_create(ui_aromaStatusBtn);
lv_image_set_src(ui_aromaStatusImg, &ui_img_off_png);
lv_obj_set_width( ui_aromaStatusImg, LV_SIZE_CONTENT);  /// 16
lv_obj_set_height( ui_aromaStatusImg, LV_SIZE_CONTENT);   /// 16
lv_obj_set_align( ui_aromaStatusImg, LV_ALIGN_CENTER );
lv_obj_add_flag( ui_aromaStatusImg, LV_OBJ_FLAG_CLICKABLE );   /// Flags
lv_obj_remove_flag( ui_aromaStatusImg, LV_OBJ_FLAG_SCROLLABLE );    /// Flags
lv_obj_set_style_image_recolor(ui_aromaStatusImg, lv_color_hex(0xFFFFFF), LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_image_recolor_opa(ui_aromaStatusImg, 255, LV_PART_MAIN| LV_STATE_DEFAULT);

lv_obj_add_event_cb(ui_aromaPer, ui_event_aromaPer, LV_EVENT_ALL, NULL);
lv_obj_add_event_cb(ui_addaromaPer, ui_event_addaromaPer, LV_EVENT_ALL, NULL);
lv_obj_add_event_cb(ui_difaromaPer, ui_event_difaromaPer, LV_EVENT_ALL, NULL);
lv_obj_add_event_cb(ui_aroma, ui_event_aroma, LV_EVENT_ALL, NULL);

}
