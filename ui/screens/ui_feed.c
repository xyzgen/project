﻿// This file was generated by SquareLine Studio
// SquareLine Studio version: SquareLine Studio 1.5.0
// LVGL version: 9.1.0
// Project name: SquareLine_Project

#include "../ui.h"

void ui_feed_screen_init(void)
{
ui_feed = lv_obj_create(NULL);
lv_obj_remove_flag( ui_feed, LV_OBJ_FLAG_SCROLLABLE );    /// Flags

ui_feedPer = lv_arc_create(ui_feed);
lv_obj_set_width( ui_feedPer, 100);
lv_obj_set_height( ui_feedPer, 100);
lv_obj_set_x( ui_feedPer, -4 );
lv_obj_set_y( ui_feedPer, -72 );
lv_obj_set_align( ui_feedPer, LV_ALIGN_CENTER );
lv_arc_set_range(ui_feedPer, 0,20);
lv_arc_set_value(ui_feedPer, 5);
lv_arc_set_bg_angles(ui_feedPer,0,360);
lv_arc_set_rotation(ui_feedPer,120);
lv_obj_set_style_arc_width(ui_feedPer, 5, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_arc_rounded(ui_feedPer, false, LV_PART_MAIN| LV_STATE_DEFAULT);

lv_obj_set_style_arc_color(ui_feedPer, lv_color_hex(0x007AFF), LV_PART_INDICATOR | LV_STATE_DEFAULT );
lv_obj_set_style_arc_opa(ui_feedPer, 255, LV_PART_INDICATOR| LV_STATE_DEFAULT);
lv_obj_set_style_arc_width(ui_feedPer, 5, LV_PART_INDICATOR| LV_STATE_DEFAULT);
lv_obj_set_style_arc_rounded(ui_feedPer, false, LV_PART_INDICATOR| LV_STATE_DEFAULT);

lv_obj_set_style_bg_color(ui_feedPer, lv_color_hex(0xFFFFFF), LV_PART_KNOB | LV_STATE_DEFAULT );
lv_obj_set_style_bg_opa(ui_feedPer, 0, LV_PART_KNOB| LV_STATE_DEFAULT);

ui_curfeedPerLab = lv_label_create(ui_feedPer);
lv_obj_set_width( ui_curfeedPerLab, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_curfeedPerLab, LV_SIZE_CONTENT);   /// 1
lv_obj_set_align( ui_curfeedPerLab, LV_ALIGN_CENTER );
lv_label_set_text(ui_curfeedPerLab,"0.5");
lv_obj_set_style_text_font(ui_curfeedPerLab, &ui_font_Chinese16B, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_setfeedPerLab = lv_label_create(ui_feedPer);
lv_obj_set_width( ui_setfeedPerLab, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_setfeedPerLab, LV_SIZE_CONTENT);   /// 1
lv_obj_set_x( ui_setfeedPerLab, 0 );
lv_obj_set_y( ui_setfeedPerLab, 30 );
lv_obj_set_align( ui_setfeedPerLab, LV_ALIGN_TOP_MID );
lv_label_set_text(ui_setfeedPerLab,"设置档位");
lv_obj_set_style_text_color(ui_setfeedPerLab, lv_color_hex(0x919191), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_text_opa(ui_setfeedPerLab, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_font(ui_setfeedPerLab, &ui_font_Chinese16B, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_addfeedPer = lv_button_create(ui_feed);
lv_obj_set_width( ui_addfeedPer, 32);
lv_obj_set_height( ui_addfeedPer, 32);
lv_obj_set_x( ui_addfeedPer, 79 );
lv_obj_set_y( ui_addfeedPer, -40 );
lv_obj_set_align( ui_addfeedPer, LV_ALIGN_CENTER );
lv_obj_add_flag( ui_addfeedPer, LV_OBJ_FLAG_SCROLL_ON_FOCUS );   /// Flags
lv_obj_remove_flag( ui_addfeedPer, LV_OBJ_FLAG_SCROLLABLE );    /// Flags
lv_obj_set_style_radius(ui_addfeedPer, 16, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_bg_color(ui_addfeedPer, lv_color_hex(0xE2E1E1), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_bg_opa(ui_addfeedPer, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_shadow_color(ui_addfeedPer, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_shadow_opa(ui_addfeedPer, 0, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_addfeedPerLab = lv_label_create(ui_addfeedPer);
lv_obj_set_width( ui_addfeedPerLab, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_addfeedPerLab, LV_SIZE_CONTENT);   /// 1
lv_obj_set_x( ui_addfeedPerLab, 0 );
lv_obj_set_y( ui_addfeedPerLab, -1 );
lv_obj_set_align( ui_addfeedPerLab, LV_ALIGN_CENTER );
lv_label_set_text(ui_addfeedPerLab,"+");
lv_obj_set_style_text_color(ui_addfeedPerLab, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_text_opa(ui_addfeedPerLab, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_font(ui_addfeedPerLab, &ui_font_Chinese16B, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_diffeedPer = lv_button_create(ui_feed);
lv_obj_set_width( ui_diffeedPer, 32);
lv_obj_set_height( ui_diffeedPer, 32);
lv_obj_set_x( ui_diffeedPer, -80 );
lv_obj_set_y( ui_diffeedPer, -40 );
lv_obj_set_align( ui_diffeedPer, LV_ALIGN_CENTER );
lv_obj_add_flag( ui_diffeedPer, LV_OBJ_FLAG_SCROLL_ON_FOCUS );   /// Flags
lv_obj_remove_flag( ui_diffeedPer, LV_OBJ_FLAG_SCROLLABLE );    /// Flags
lv_obj_set_style_radius(ui_diffeedPer, 16, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_bg_color(ui_diffeedPer, lv_color_hex(0xE2E1E1), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_bg_opa(ui_diffeedPer, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_shadow_color(ui_diffeedPer, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_shadow_opa(ui_diffeedPer, 0, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_diffeedPerLab = lv_label_create(ui_diffeedPer);
lv_obj_set_width( ui_diffeedPerLab, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_diffeedPerLab, LV_SIZE_CONTENT);   /// 1
lv_obj_set_x( ui_diffeedPerLab, 0 );
lv_obj_set_y( ui_diffeedPerLab, -1 );
lv_obj_set_align( ui_diffeedPerLab, LV_ALIGN_CENTER );
lv_label_set_text(ui_diffeedPerLab,"-");
lv_obj_set_style_text_color(ui_diffeedPerLab, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_text_opa(ui_diffeedPerLab, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_font(ui_diffeedPerLab, &ui_font_Chinese16B, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_feedStatus = lv_obj_create(ui_feed);
lv_obj_set_width( ui_feedStatus, 199);
lv_obj_set_height( ui_feedStatus, 38);
lv_obj_set_x( ui_feedStatus, 0 );
lv_obj_set_y( ui_feedStatus, 15 );
lv_obj_set_align( ui_feedStatus, LV_ALIGN_CENTER );
lv_obj_remove_flag( ui_feedStatus, LV_OBJ_FLAG_SCROLLABLE );    /// Flags
lv_obj_set_style_radius(ui_feedStatus, 3, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_border_color(ui_feedStatus, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_border_opa(ui_feedStatus, 255, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_feedStatusLab = lv_label_create(ui_feedStatus);
lv_obj_set_width( ui_feedStatusLab, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_feedStatusLab, LV_SIZE_CONTENT);   /// 1
lv_obj_set_align( ui_feedStatusLab, LV_ALIGN_BOTTOM_LEFT );
lv_label_set_text(ui_feedStatusLab,"喂食中");
lv_obj_set_style_text_color(ui_feedStatusLab, lv_color_hex(0x919191), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_text_opa(ui_feedStatusLab, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_font(ui_feedStatusLab, &ui_font_Chinese16B, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_feedStatusBtn = lv_button_create(ui_feedStatus);
lv_obj_set_width( ui_feedStatusBtn, 32);
lv_obj_set_height( ui_feedStatusBtn, 32);
lv_obj_set_x( ui_feedStatusBtn, 76 );
lv_obj_set_y( ui_feedStatusBtn, 1 );
lv_obj_set_align( ui_feedStatusBtn, LV_ALIGN_CENTER );
lv_obj_add_flag( ui_feedStatusBtn, LV_OBJ_FLAG_SCROLL_ON_FOCUS );   /// Flags
lv_obj_remove_flag( ui_feedStatusBtn, LV_OBJ_FLAG_SCROLLABLE );    /// Flags
lv_obj_set_style_radius(ui_feedStatusBtn, 16, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_bg_color(ui_feedStatusBtn, lv_color_hex(0x007AFF), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_bg_opa(ui_feedStatusBtn, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_shadow_color(ui_feedStatusBtn, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_shadow_opa(ui_feedStatusBtn, 0, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_feedStatusImg = lv_image_create(ui_feedStatusBtn);
lv_image_set_src(ui_feedStatusImg, &ui_img_off_png);
lv_obj_set_width( ui_feedStatusImg, LV_SIZE_CONTENT);  /// 16
lv_obj_set_height( ui_feedStatusImg, LV_SIZE_CONTENT);   /// 16
lv_obj_set_align( ui_feedStatusImg, LV_ALIGN_CENTER );
lv_obj_add_flag( ui_feedStatusImg, LV_OBJ_FLAG_CLICKABLE );   /// Flags
lv_obj_remove_flag( ui_feedStatusImg, LV_OBJ_FLAG_SCROLLABLE );    /// Flags
lv_obj_set_style_image_recolor(ui_feedStatusImg, lv_color_hex(0xFFFFFF), LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_image_recolor_opa(ui_feedStatusImg, 255, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_feedAmount = lv_obj_create(ui_feed);
lv_obj_set_width( ui_feedAmount, 199);
lv_obj_set_height( ui_feedAmount, 57);
lv_obj_set_x( ui_feedAmount, -1 );
lv_obj_set_y( ui_feedAmount, 67 );
lv_obj_set_align( ui_feedAmount, LV_ALIGN_CENTER );
lv_obj_remove_flag( ui_feedAmount, LV_OBJ_FLAG_SCROLLABLE );    /// Flags
lv_obj_set_style_radius(ui_feedAmount, 3, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_border_color(ui_feedAmount, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_border_opa(ui_feedAmount, 255, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_feedAmountLab = lv_label_create(ui_feedAmount);
lv_obj_set_width( ui_feedAmountLab, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_feedAmountLab, LV_SIZE_CONTENT);   /// 1
lv_obj_set_x( ui_feedAmountLab, 0 );
lv_obj_set_y( ui_feedAmountLab, -20 );
lv_obj_set_align( ui_feedAmountLab, LV_ALIGN_BOTTOM_LEFT );
lv_label_set_text(ui_feedAmountLab,"喂食量");
lv_obj_set_style_text_color(ui_feedAmountLab, lv_color_hex(0x101010), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_text_opa(ui_feedAmountLab, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_font(ui_feedAmountLab, &ui_font_Chinese16B, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_feedAmountSlider = lv_slider_create(ui_feedAmount);
lv_slider_set_range(ui_feedAmountSlider, 1,120);
lv_slider_set_value( ui_feedAmountSlider, 1, LV_ANIM_OFF);
if (lv_slider_get_mode(ui_feedAmountSlider)==LV_SLIDER_MODE_RANGE ) lv_slider_set_left_value( ui_feedAmountSlider, 1, LV_ANIM_OFF);
lv_obj_set_width( ui_feedAmountSlider, 162);
lv_obj_set_height( ui_feedAmountSlider, 2);
lv_obj_set_x( ui_feedAmountSlider, -3 );
lv_obj_set_y( ui_feedAmountSlider, 2 );
lv_obj_set_align( ui_feedAmountSlider, LV_ALIGN_CENTER );
lv_obj_set_style_bg_color(ui_feedAmountSlider, lv_color_hex(0xEDEDED), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_bg_opa(ui_feedAmountSlider, 255, LV_PART_MAIN| LV_STATE_DEFAULT);


//Compensating for LVGL9.1 draw crash with bar/slider max value when top-padding is nonzero and right-padding is 0
if (lv_obj_get_style_pad_top(ui_feedAmountSlider,LV_PART_MAIN) > 0) lv_obj_set_style_pad_right( ui_feedAmountSlider, lv_obj_get_style_pad_right(ui_feedAmountSlider,LV_PART_MAIN) + 1, LV_PART_MAIN );
ui_feedAmountSliderLab = lv_label_create(ui_feedAmount);
lv_obj_set_width( ui_feedAmountSliderLab, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_feedAmountSliderLab, LV_SIZE_CONTENT);   /// 1
lv_obj_set_x( ui_feedAmountSliderLab, 2 );
lv_obj_set_y( ui_feedAmountSliderLab, 8 );
lv_obj_set_align( ui_feedAmountSliderLab, LV_ALIGN_BOTTOM_MID );
lv_label_set_text(ui_feedAmountSliderLab,"1	        20	        40	       60	        80	      100	     自动");
lv_obj_set_style_text_color(ui_feedAmountSliderLab, lv_color_hex(0x919191), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_text_opa(ui_feedAmountSliderLab, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_font(ui_feedAmountSliderLab, &ui_font_Chinese16B, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_feedFreq = lv_obj_create(ui_feed);
lv_obj_set_width( ui_feedFreq, 199);
lv_obj_set_height( ui_feedFreq, 53);
lv_obj_set_x( ui_feedFreq, -1 );
lv_obj_set_y( ui_feedFreq, 127 );
lv_obj_set_align( ui_feedFreq, LV_ALIGN_CENTER );
lv_obj_remove_flag( ui_feedFreq, LV_OBJ_FLAG_SCROLLABLE );    /// Flags
lv_obj_set_style_radius(ui_feedFreq, 3, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_border_color(ui_feedFreq, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_border_opa(ui_feedFreq, 255, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_feedFreqLab = lv_label_create(ui_feedFreq);
lv_obj_set_width( ui_feedFreqLab, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_feedFreqLab, LV_SIZE_CONTENT);   /// 1
lv_obj_set_x( ui_feedFreqLab, 0 );
lv_obj_set_y( ui_feedFreqLab, -20 );
lv_obj_set_align( ui_feedFreqLab, LV_ALIGN_BOTTOM_LEFT );
lv_label_set_text(ui_feedFreqLab,"喂食频率");
lv_obj_set_style_text_color(ui_feedFreqLab, lv_color_hex(0x101010), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_text_opa(ui_feedFreqLab, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_font(ui_feedFreqLab, &ui_font_Chinese16B, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_feedFreqBtn = lv_obj_create(ui_feedFreq);
lv_obj_remove_style_all(ui_feedFreqBtn);
lv_obj_set_width( ui_feedFreqBtn, 194);
lv_obj_set_height( ui_feedFreqBtn, 50);
lv_obj_set_align( ui_feedFreqBtn, LV_ALIGN_CENTER );
lv_obj_remove_flag( ui_feedFreqBtn, LV_OBJ_FLAG_CLICKABLE | LV_OBJ_FLAG_SCROLLABLE );    /// Flags

ui_oneADayBtn = lv_button_create(ui_feedFreqBtn);
lv_obj_set_width( ui_oneADayBtn, 30);
lv_obj_set_height( ui_oneADayBtn, 20);
lv_obj_set_x( ui_oneADayBtn, -72 );
lv_obj_set_y( ui_oneADayBtn, 10 );
lv_obj_set_align( ui_oneADayBtn, LV_ALIGN_CENTER );
lv_obj_add_flag( ui_oneADayBtn, LV_OBJ_FLAG_SCROLL_ON_FOCUS );   /// Flags
lv_obj_remove_flag( ui_oneADayBtn, LV_OBJ_FLAG_SCROLLABLE );    /// Flags
lv_obj_set_style_radius(ui_oneADayBtn, 10, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_bg_color(ui_oneADayBtn, lv_color_hex(0xF7F7F7), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_bg_opa(ui_oneADayBtn, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_shadow_color(ui_oneADayBtn, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_shadow_opa(ui_oneADayBtn, 0, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_oneADayBtnLab = lv_label_create(ui_oneADayBtn);
lv_obj_set_width( ui_oneADayBtnLab, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_oneADayBtnLab, LV_SIZE_CONTENT);   /// 1
lv_obj_set_align( ui_oneADayBtnLab, LV_ALIGN_CENTER );
lv_label_set_text(ui_oneADayBtnLab,"1次/天");
lv_obj_set_style_text_color(ui_oneADayBtnLab, lv_color_hex(0x939393), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_text_opa(ui_oneADayBtnLab, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_font(ui_oneADayBtnLab, &ui_font_Chinese16B, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_twoADayBtn = lv_button_create(ui_feedFreqBtn);
lv_obj_set_width( ui_twoADayBtn, 30);
lv_obj_set_height( ui_twoADayBtn, 20);
lv_obj_set_x( ui_twoADayBtn, -36 );
lv_obj_set_y( ui_twoADayBtn, 10 );
lv_obj_set_align( ui_twoADayBtn, LV_ALIGN_CENTER );
lv_obj_add_flag( ui_twoADayBtn, LV_OBJ_FLAG_SCROLL_ON_FOCUS );   /// Flags
lv_obj_remove_flag( ui_twoADayBtn, LV_OBJ_FLAG_SCROLLABLE );    /// Flags
lv_obj_set_style_radius(ui_twoADayBtn, 10, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_bg_color(ui_twoADayBtn, lv_color_hex(0xF7F7F7), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_bg_opa(ui_twoADayBtn, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_shadow_color(ui_twoADayBtn, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_shadow_opa(ui_twoADayBtn, 0, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_twoADayBtnLab = lv_label_create(ui_twoADayBtn);
lv_obj_set_width( ui_twoADayBtnLab, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_twoADayBtnLab, LV_SIZE_CONTENT);   /// 1
lv_obj_set_align( ui_twoADayBtnLab, LV_ALIGN_CENTER );
lv_label_set_text(ui_twoADayBtnLab,"2次/天");
lv_obj_set_style_text_color(ui_twoADayBtnLab, lv_color_hex(0x939393), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_text_opa(ui_twoADayBtnLab, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_font(ui_twoADayBtnLab, &ui_font_Chinese16B, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_threeADayBtn = lv_button_create(ui_feedFreqBtn);
lv_obj_set_width( ui_threeADayBtn, 30);
lv_obj_set_height( ui_threeADayBtn, 20);
lv_obj_set_x( ui_threeADayBtn, 0 );
lv_obj_set_y( ui_threeADayBtn, 10 );
lv_obj_set_align( ui_threeADayBtn, LV_ALIGN_CENTER );
lv_obj_add_flag( ui_threeADayBtn, LV_OBJ_FLAG_SCROLL_ON_FOCUS );   /// Flags
lv_obj_remove_flag( ui_threeADayBtn, LV_OBJ_FLAG_SCROLLABLE );    /// Flags
lv_obj_set_style_radius(ui_threeADayBtn, 10, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_bg_color(ui_threeADayBtn, lv_color_hex(0xF7F7F7), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_bg_opa(ui_threeADayBtn, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_shadow_color(ui_threeADayBtn, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_shadow_opa(ui_threeADayBtn, 0, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_threeADayBtnLab = lv_label_create(ui_threeADayBtn);
lv_obj_set_width( ui_threeADayBtnLab, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_threeADayBtnLab, LV_SIZE_CONTENT);   /// 1
lv_obj_set_align( ui_threeADayBtnLab, LV_ALIGN_CENTER );
lv_label_set_text(ui_threeADayBtnLab,"3次/天");
lv_obj_set_style_text_color(ui_threeADayBtnLab, lv_color_hex(0x939393), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_text_opa(ui_threeADayBtnLab, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_font(ui_threeADayBtnLab, &ui_font_Chinese16B, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_fiveAWeekBtn = lv_button_create(ui_feedFreqBtn);
lv_obj_set_width( ui_fiveAWeekBtn, 30);
lv_obj_set_height( ui_fiveAWeekBtn, 20);
lv_obj_set_x( ui_fiveAWeekBtn, 36 );
lv_obj_set_y( ui_fiveAWeekBtn, 10 );
lv_obj_set_align( ui_fiveAWeekBtn, LV_ALIGN_CENTER );
lv_obj_add_flag( ui_fiveAWeekBtn, LV_OBJ_FLAG_SCROLL_ON_FOCUS );   /// Flags
lv_obj_remove_flag( ui_fiveAWeekBtn, LV_OBJ_FLAG_SCROLLABLE );    /// Flags
lv_obj_set_style_radius(ui_fiveAWeekBtn, 10, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_bg_color(ui_fiveAWeekBtn, lv_color_hex(0xF7F7F7), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_bg_opa(ui_fiveAWeekBtn, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_shadow_color(ui_fiveAWeekBtn, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_shadow_opa(ui_fiveAWeekBtn, 0, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_fiveAWeekBtnLab = lv_label_create(ui_fiveAWeekBtn);
lv_obj_set_width( ui_fiveAWeekBtnLab, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_fiveAWeekBtnLab, LV_SIZE_CONTENT);   /// 1
lv_obj_set_align( ui_fiveAWeekBtnLab, LV_ALIGN_CENTER );
lv_label_set_text(ui_fiveAWeekBtnLab,"5次/周");
lv_obj_set_style_text_color(ui_fiveAWeekBtnLab, lv_color_hex(0x939393), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_text_opa(ui_fiveAWeekBtnLab, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_font(ui_fiveAWeekBtnLab, &ui_font_Chinese16B, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_sevenAWeekBtn = lv_button_create(ui_feedFreqBtn);
lv_obj_set_width( ui_sevenAWeekBtn, 30);
lv_obj_set_height( ui_sevenAWeekBtn, 20);
lv_obj_set_x( ui_sevenAWeekBtn, 72 );
lv_obj_set_y( ui_sevenAWeekBtn, 10 );
lv_obj_set_align( ui_sevenAWeekBtn, LV_ALIGN_CENTER );
lv_obj_add_flag( ui_sevenAWeekBtn, LV_OBJ_FLAG_SCROLL_ON_FOCUS );   /// Flags
lv_obj_remove_flag( ui_sevenAWeekBtn, LV_OBJ_FLAG_SCROLLABLE );    /// Flags
lv_obj_set_style_radius(ui_sevenAWeekBtn, 10, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_bg_color(ui_sevenAWeekBtn, lv_color_hex(0xF7F7F7), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_bg_opa(ui_sevenAWeekBtn, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_shadow_color(ui_sevenAWeekBtn, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_shadow_opa(ui_sevenAWeekBtn, 0, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_sevenAWeekBtnLab = lv_label_create(ui_sevenAWeekBtn);
lv_obj_set_width( ui_sevenAWeekBtnLab, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_sevenAWeekBtnLab, LV_SIZE_CONTENT);   /// 1
lv_obj_set_align( ui_sevenAWeekBtnLab, LV_ALIGN_CENTER );
lv_label_set_text(ui_sevenAWeekBtnLab,"7次/周");
lv_obj_set_style_text_color(ui_sevenAWeekBtnLab, lv_color_hex(0x939393), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_text_opa(ui_sevenAWeekBtnLab, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_font(ui_sevenAWeekBtnLab, &ui_font_Chinese16B, LV_PART_MAIN| LV_STATE_DEFAULT);

lv_obj_add_event_cb(ui_feedPer, ui_event_feedPer, LV_EVENT_ALL, NULL);
lv_obj_add_event_cb(ui_addfeedPer, ui_event_addfeedPer, LV_EVENT_ALL, NULL);
lv_obj_add_event_cb(ui_diffeedPer, ui_event_diffeedPer, LV_EVENT_ALL, NULL);
lv_obj_add_event_cb(ui_feed, ui_event_feed, LV_EVENT_ALL, NULL);

}