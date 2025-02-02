﻿// This file was generated by SquareLine Studio
// SquareLine Studio version: SquareLine Studio 1.5.0
// LVGL version: 9.1.0
// Project name: SquareLine_Project

#define CENTER_X 182
#define CENTER_Y 58

#include "../ui.h"
static const char* weekday_cn[] = { "周日", "周一", "周二", "周三", "周四", "周五", "周六" };

lv_point_t hour_points[2] = { {CENTER_X, CENTER_Y}, {CENTER_X, CENTER_Y} }, minute_points[2] = { {CENTER_X, CENTER_Y}, {CENTER_X, CENTER_Y} }, second_points[2] = { {CENTER_X, CENTER_Y}, {CENTER_X, CENTER_Y} };

static void update_clock_hands(void);

void ui_main_screen_init(void)
{
    ui_main = lv_obj_create(NULL);
    lv_obj_remove_flag(ui_main, LV_OBJ_FLAG_SCROLLABLE);    /// Flags
    lv_obj_set_style_bg_color(ui_main, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_main, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_dateLab = lv_label_create(ui_main);
    lv_obj_add_flag(ui_dateLab, LV_OBJ_FLAG_EVENT_BUBBLE);
    lv_obj_set_width(ui_dateLab, 128);  /// 1
    lv_obj_set_height(ui_dateLab, 16);   /// 1
    lv_obj_align(ui_dateLab, LV_ALIGN_BOTTOM_LEFT, 16, -60);
    lv_obj_set_style_text_font(ui_dateLab, &ui_font_Chinese16B, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui_dateLab, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_dateLab, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_timeLab = lv_label_create(ui_main);
    lv_obj_add_flag(ui_timeLab, LV_OBJ_FLAG_EVENT_BUBBLE);
    lv_obj_set_width(ui_timeLab, 128);  /// 1
    lv_obj_set_height(ui_timeLab, 180);   /// 1
    lv_obj_align(ui_timeLab, LV_ALIGN_TOP_LEFT, 16, 20);
    lv_obj_set_style_text_line_space(ui_timeLab, 30, LV_PART_MAIN);
    lv_obj_set_style_text_font(ui_timeLab, &ui_font_Chinese96, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui_timeLab, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_timeLab, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    // 创建表盘（这里使用一个简单的圆形作为示例）
    lv_obj_t* dial = lv_arc_create(ui_main);
    lv_obj_add_flag(dial, LV_OBJ_FLAG_EVENT_BUBBLE);
    lv_obj_set_size(dial, 76, 76);
    lv_obj_align(dial, LV_ALIGN_TOP_RIGHT, -20, 20);
    lv_arc_set_bg_angles(dial, 0, 360);
    lv_arc_set_end_angle(dial, 360);
    lv_obj_set_style_arc_color(dial, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_arc_width(dial, 3, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_arc_rounded(dial, false, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_arc_color(dial, lv_color_hex(0xFFFFFF), LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_arc_width(dial, 3, LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_arc_rounded(dial, false, LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(dial, 0, LV_PART_KNOB | LV_STATE_DEFAULT);

    // 创建指针（使用线条作为示例）
    hour_hand = lv_line_create(ui_main);
    lv_obj_add_flag(hour_hand, LV_OBJ_FLAG_EVENT_BUBBLE);
    lv_line_set_points(hour_hand, hour_points, 1);
    lv_obj_set_style_line_width(hour_hand, 3, 0);
    lv_obj_set_style_line_color(hour_hand, lv_color_hex(0xFFFFFF), 0);

    minute_hand = lv_line_create(ui_main);
    lv_obj_add_flag(minute_hand, LV_OBJ_FLAG_EVENT_BUBBLE);
    lv_line_set_points(minute_hand, minute_points, 1);
    lv_obj_set_style_line_width(minute_hand, 3, 0);
    lv_obj_set_style_line_color(minute_hand, lv_color_hex(0xFFFFFF), 0);

    second_hand = lv_line_create(ui_main);
    lv_obj_add_flag(second_hand, LV_OBJ_FLAG_EVENT_BUBBLE);
    lv_line_set_points(second_hand, second_points, 1);
    lv_obj_set_style_line_width(second_hand, 2, 0);
    lv_obj_set_style_line_color(second_hand, lv_palette_main(LV_PALETTE_RED), 0);

    // 设置定时器来更新时间
    lv_timer_create(update_clock_hands, 1000, NULL); // 每秒调用一次update_clock_hands函数


    //温度条
    static lv_style_t style_temp;

    lv_style_init(&style_temp);
    lv_style_set_bg_color(&style_temp, lv_color_hex(0xF0CF14));

    ui_tempBar = lv_bar_create(ui_main);
    lv_obj_add_flag(ui_tempBar, LV_OBJ_FLAG_EVENT_BUBBLE);
    lv_obj_add_style(ui_tempBar, &style_temp, LV_PART_INDICATOR);
    lv_obj_set_size(ui_tempBar, 8, 90);
    lv_obj_align(ui_tempBar, LV_ALIGN_CENTER, 45, 15);
    lv_bar_set_range(ui_tempBar, 0, 60);
    lv_bar_set_value(ui_tempBar, 30, LV_ANIM_ON);
    lv_obj_set_style_bg_color(ui_tempBar, lv_color_hex(0xF0CF14), LV_PART_MAIN);
    lv_obj_set_style_bg_opa(ui_tempBar, 127, LV_PART_MAIN);

    lv_obj_t* tempimg = lv_image_create(ui_main);
    lv_obj_add_flag(tempimg, LV_OBJ_FLAG_EVENT_BUBBLE);
    lv_image_set_src(tempimg, &ui_img_temp_png);
    lv_obj_set_width(tempimg, LV_SIZE_CONTENT);  /// 16
    lv_obj_set_height(tempimg, LV_SIZE_CONTENT);   /// 16
    lv_obj_align(tempimg, LV_ALIGN_CENTER, 46, 80);
    lv_obj_set_style_image_recolor(tempimg, lv_color_hex(0xF0CF14), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_image_recolor_opa(tempimg, 255, LV_PART_MAIN | LV_STATE_DEFAULT);



    static lv_style_t style_level;

    lv_style_init(&style_level);
    lv_style_set_bg_color(&style_level, lv_color_hex(LANDE));

    ui_waterLevelBar = lv_bar_create(ui_main);
    lv_obj_add_flag(ui_waterLevelBar, LV_OBJ_FLAG_EVENT_BUBBLE);
    lv_obj_add_style(ui_waterLevelBar, &style_level, LV_PART_INDICATOR);
    lv_obj_set_size(ui_waterLevelBar, 8, 90);
    lv_obj_align(ui_waterLevelBar, LV_ALIGN_CENTER, 75, 15);
    lv_bar_set_range(ui_waterLevelBar, 0, 2);
    lv_bar_set_value(ui_waterLevelBar, 2, LV_ANIM_ON);
    lv_obj_set_style_bg_color(ui_waterLevelBar, lv_color_hex(LANDE), LV_PART_MAIN);
    lv_obj_set_style_bg_opa(ui_waterLevelBar, 127, LV_PART_MAIN);

    lv_obj_t* levelimg = lv_image_create(ui_main);
    lv_obj_add_flag(levelimg, LV_OBJ_FLAG_EVENT_BUBBLE);
    lv_image_set_src(levelimg, &ui_img_level_png);
    lv_obj_set_width(levelimg, LV_SIZE_CONTENT);  /// 16
    lv_obj_set_height(levelimg, LV_SIZE_CONTENT);   /// 16
    lv_obj_align(levelimg, LV_ALIGN_CENTER, 76, 80);
    lv_obj_set_style_image_recolor(levelimg, lv_color_hex(LANDE), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_image_recolor_opa(levelimg, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_mainInfo = lv_image_create(ui_main);
    lv_obj_add_flag(ui_mainInfo, LV_OBJ_FLAG_EVENT_BUBBLE);
    lv_obj_set_width(ui_mainInfo, 212);
    lv_obj_set_height(ui_mainInfo, 24);
    lv_obj_set_style_radius(ui_mainInfo, 12, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_align(ui_mainInfo, LV_ALIGN_BOTTOM_MID, 0, -24);
    lv_obj_set_style_bg_color(ui_mainInfo, lv_color_hex(0x909090), LV_PART_MAIN);
    lv_obj_set_style_bg_opa(ui_mainInfo, LV_OPA_80, LV_PART_MAIN);
    ui_mainInfoLab = lv_label_create(ui_mainInfo);
    lv_obj_add_flag(ui_mainInfoLab, LV_OBJ_FLAG_EVENT_BUBBLE);
    lv_obj_set_width(ui_mainInfoLab, 160);  /// 1
    lv_obj_set_height(ui_mainInfoLab, 16);   /// 1
    lv_obj_set_align(ui_mainInfoLab, LV_ALIGN_CENTER);
    lv_obj_set_style_text_font(ui_mainInfoLab, &ui_font_Chinese16B, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui_mainInfoLab, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_mainInfoLab, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_label_set_text_fmt(ui_mainInfoLab, "水泵 %d 档   灯光 %s", 7, "氛围");

    lv_obj_add_event_cb(ui_main, ui_event_status, LV_EVENT_ALL, ui_main);
    lv_obj_add_event_cb(ui_main, ui_event_control, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_main, ui_event_temp, LV_EVENT_ALL, ui_main);
}

static void update_clock_hands(void) {
    time_t now = time(NULL);
    struct tm* t = localtime(&now);

    static time_t last_time_update = 0;
    static time_t last_date_update = 0;
    char date_str[32];
    snprintf(date_str, sizeof(date_str), "%02d/%d       %s", t->tm_mon + 1, t->tm_mday, weekday_cn[t->tm_wday]);
    lv_label_set_text(ui_dateLab, date_str);

    strftime(date_str, sizeof(date_str), "%H%M", t);
    lv_label_set_text(ui_timeLab, date_str);

    // 计算每个指针的角度（每小时30度，每分钟6度，每秒6度*60=360度/分钟）
    int hour_angle = (t->tm_hour % 12 + t->tm_min / 60.0) * 30.0 - 90.0; // 调整为12小时制，并居中
    int minute_angle = t->tm_min * 6.0 - 90.0;
    int second_angle = t->tm_sec * 6.0 - 90.0;

    // 将角度转换为弧度
    float hour_rad = hour_angle * (2 * 3.1415 / 360.0);
    float minute_rad = minute_angle * (2 * 3.1415 / 360.0);
    float second_rad = second_angle * (2 * 3.1415 / 360.0);


    int16_t hour_x = CENTER_X + 20 * cos(hour_rad);
    int16_t hour_y = CENTER_Y + 20 * sin(hour_rad);
    int16_t minute_x = CENTER_X + 24 * cos(minute_rad);
    int16_t minute_y = CENTER_Y + 24 * sin(minute_rad);
    int16_t second_x = CENTER_X + 28 * cos(second_rad);
    int16_t second_y = CENTER_Y + 28 * sin(second_rad);

    // 更新指针位置
    hour_points[1].x = hour_x;
    hour_points[1].y = hour_y;
    lv_line_set_points(hour_hand, hour_points, 2);

    minute_points[1].x = minute_x;
    minute_points[1].y = minute_y;
    lv_line_set_points(minute_hand, minute_points, 2);

    second_points[1].x = second_x;
    second_points[1].y = second_y;
    lv_line_set_points(second_hand, second_points, 2);

}
