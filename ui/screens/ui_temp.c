#include "../ui.h"

static int get_temp();
static void timer_cb(lv_timer_t* timer);
static void create_dashed_line(lv_obj_t* scr, int x, int y);

void ui_temp_screen_init(void)
{
    ui_temp = lv_obj_create(NULL);
    lv_obj_remove_flag(ui_temp, LV_OBJ_FLAG_SCROLLABLE);    /// Flags
    lv_obj_set_style_bg_color(ui_temp, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_t* ui_lab = lv_label_create(ui_temp);
    lv_obj_add_flag(ui_lab, LV_OBJ_FLAG_EVENT_BUBBLE);
    lv_obj_align(ui_lab, LV_ALIGN_TOP_LEFT, 16, 16);
    lv_label_set_text(ui_lab, "温度");
    lv_obj_set_style_text_color(ui_lab, lv_color_hex(LANDE), LV_PART_MAIN);
    lv_obj_set_style_text_font(ui_lab, &ui_font_Chinese24B, LV_PART_MAIN);

    lv_obj_t* ui_tempImg = lv_image_create(ui_temp);
    lv_obj_add_flag(ui_tempImg, LV_OBJ_FLAG_EVENT_BUBBLE);
    lv_image_set_src(ui_tempImg, &ui_img_temp_png);
    lv_obj_align(ui_tempImg, LV_ALIGN_BOTTOM_MID,-16,-9);
    lv_image_set_scale(ui_tempImg, 192);
    lv_obj_set_style_image_recolor(ui_tempImg, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_image_recolor_opa(ui_tempImg, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_tempLab = lv_label_create(ui_temp);
    lv_obj_add_flag(ui_tempLab, LV_OBJ_FLAG_EVENT_BUBBLE);
    lv_obj_align(ui_tempLab, LV_ALIGN_BOTTOM_MID, 16, -16);
    lv_obj_set_style_text_color(ui_tempLab, lv_color_hex(0xFFFFFF), LV_PART_MAIN);
    lv_obj_set_style_text_font(ui_tempLab, &ui_font_Chinese16B, LV_PART_MAIN);

    lv_obj_t* line_obj = lv_line_create(ui_temp);

    static lv_point_t line_points[] = { {0, 0}, {200, 0} };
    lv_line_set_points(line_obj, line_points, 2);

    // 设置虚线样式
    lv_obj_set_style_line_width(line_obj, 1, LV_PART_MAIN);
    lv_obj_set_style_line_color(line_obj, lv_color_hex(0x606060), LV_PART_MAIN);

    // 设置线条位置（可选）
    lv_obj_align(line_obj, LV_ALIGN_CENTER, 0, 0); // 或者使用 lv_obj_set_pos 来设置具体位置

    create_dashed_line(ui_temp,-100,0);
    create_dashed_line(ui_temp, -50, 0);
    create_dashed_line(ui_temp, 0, 0);
    create_dashed_line(ui_temp, 50, 0);
    create_dashed_line(ui_temp, 100, 0);

    ui_tempChart = lv_chart_create(ui_temp);
    lv_obj_add_flag(ui_tempChart, LV_OBJ_FLAG_EVENT_BUBBLE);
    lv_obj_set_size(ui_tempChart, 200, 150);
    lv_obj_center(ui_tempChart);
    lv_chart_set_type(ui_tempChart, LV_CHART_TYPE_LINE);   /*Show lines and points too*/
    lv_obj_set_style_bg_opa(ui_tempChart, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui_tempChart, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_line_opa(ui_tempChart, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_line_width(ui_tempChart, 2, LV_PART_ITEMS);
    lv_obj_set_style_size(ui_tempChart, 0, 0, LV_PART_INDICATOR);
    lv_chart_set_range(ui_tempChart, LV_CHART_AXIS_PRIMARY_Y, 10,40);

    lv_chart_set_point_count(ui_tempChart, 24);

    ui_tempSeries = lv_chart_add_series(ui_tempChart, lv_palette_main(LV_PALETTE_RED), LV_CHART_AXIS_PRIMARY_Y);
    //lv_obj_add_flag(ui_tempSeries, LV_OBJ_FLAG_EVENT_BUBBLE);


    lv_obj_add_event_cb(ui_temp, ui_event_main, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_temp, ui_event_waterLevel, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_temp, ui_event_status, LV_EVENT_ALL, ui_temp);
    lv_timer_t* timer = lv_timer_create(timer_cb, 1000, NULL);


    //lv_obj_t* ui_avelab = lv_label_create(ui_temp);
    //lv_obj_add_flag(ui_avelab, LV_OBJ_FLAG_EVENT_BUBBLE);

    //lv_obj_align(ui_avelab, LV_ALIGN_BOTTOM_MID, -32, -16);
    //lv_label_set_text(ui_avelab, "当前温度");
    //lv_obj_set_style_text_color(ui_avelab, lv_color_hex(0xFFFFFF), LV_PART_MAIN);
    //lv_obj_set_style_text_font(ui_avelab, &ui_font_Chinese16B, LV_PART_MAIN);

    //ui_temp_ave_Lab = lv_label_create(ui_temp);
    //lv_obj_align(ui_temp_ave_Lab, LV_ALIGN_BOTTOM_RIGHT, -16, -16);
    //lv_obj_set_style_text_color(ui_temp_ave_Lab, lv_color_hex(0xFFFFFF), LV_PART_MAIN);
    //lv_obj_set_style_text_font(ui_temp_ave_Lab, &ui_font_Chinese16B, LV_PART_MAIN);

}

static int get_temp() {
    return lv_rand(10, 40);
}

//每天更新图表
static void timer_cb(lv_timer_t* timer) {

    static int data[12],index=0;
    int temp = get_temp(),sum = 0,i;
    index %= 12;
    data[index] = temp;
    lv_label_set_text_fmt(ui_tempLab, "%d ℃", temp);

    lv_chart_set_next_value(ui_tempChart, ui_tempSeries, temp);
    //for (i = 0;data[i] != 0&&i<12;i++)
    //{
    //    sum += data[i];
    //}
    //lv_label_set_text_fmt(ui_temp_ave_Lab, "%d", sum/i);

    uint16_t p = lv_chart_get_point_count(ui_tempChart);
    uint16_t s = lv_chart_get_x_start_point(ui_tempChart, ui_tempSeries);
    int32_t* a = lv_chart_get_y_array(ui_tempChart, ui_tempSeries);

    a[(s + 1) % p] = LV_CHART_POINT_NONE;
    a[(s + 2) % p] = LV_CHART_POINT_NONE;
    a[(s + 2) % p] = LV_CHART_POINT_NONE;

    lv_chart_refresh(ui_tempChart);
    index++;
}

static void create_dashed_line(lv_obj_t* scr,int x,int y) {
    // 创建线条对象
    lv_obj_t* line_obj = lv_line_create(scr);

    // 设置点数组
    static lv_point_t line_points[] = { {0, 0}, {0, 150} };
    lv_line_set_points(line_obj, line_points, 2);

    // 设置虚线样式
    lv_obj_set_style_line_width(line_obj, 1, LV_PART_MAIN);
    lv_obj_set_style_line_dash_width(line_obj, 1, LV_PART_MAIN);
    lv_obj_set_style_line_dash_gap(line_obj, 1, LV_PART_MAIN);
    lv_obj_set_style_line_color(line_obj, lv_color_hex(0x606060),LV_PART_MAIN);

    // 设置线条位置（可选）
    lv_obj_align(line_obj,LV_ALIGN_CENTER,x,y); // 或者使用 lv_obj_set_pos 来设置具体位置
}
