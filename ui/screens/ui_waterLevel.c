#include "../ui.h"

#define HIGHT 10

static int get_water_level(void);
static void water_level_anim_cb(void* var, int32_t v);
static void hidden_cb(void* arg);
static void timer_cb(lv_timer_t* timer);
static int hight[7] = { HIGHT * 2,HIGHT,HIGHT,HIGHT*2,HIGHT*3,HIGHT * 4,HIGHT * 3};

static lv_obj_t* ui_waterLevelPanel[16];

void ui_waterLevel_screen_init(void)
{
    ui_waterLevel = lv_obj_create(NULL);
    lv_obj_remove_flag(ui_waterLevel, LV_OBJ_FLAG_SCROLLABLE);    /// Flags
    lv_obj_set_style_bg_color(ui_waterLevel, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_t* ui_lab = lv_label_create(ui_waterLevel);
    lv_obj_align(ui_lab, LV_ALIGN_TOP_LEFT, 16, 16);
    lv_label_set_text(ui_lab, "水位");
    lv_obj_set_style_text_color(ui_lab, lv_color_hex(LANDE), LV_PART_MAIN);
    lv_obj_set_style_text_font(ui_lab, &ui_font_Chinese32B, LV_PART_MAIN);

    ui_waterLevelLab = lv_label_create(ui_waterLevel);
    lv_obj_align(ui_waterLevelLab, LV_ALIGN_BOTTOM_MID, 0, -32);
    lv_label_set_text(ui_waterLevelLab, "水位 -");
    lv_obj_set_style_text_color(ui_waterLevelLab, lv_color_hex(LANDE), LV_PART_MAIN);
    lv_obj_set_style_text_font(ui_waterLevelLab, &ui_font_Chinese32B, LV_PART_MAIN);

    lv_obj_add_event_cb(ui_waterLevel, ui_event_main, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_waterLevel, ui_event_waterPump, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_waterLevel, ui_event_status, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_waterLevel, timer_cb, LV_EVENT_SCREEN_LOADED, NULL);
    lv_obj_add_event_cb(ui_waterLevel, hidden_cb, LV_EVENT_SCREEN_UNLOADED, NULL);

    lv_timer_t* timer = lv_timer_create(timer_cb, 60000, NULL);
}

static int get_water_level(void) {
    return lv_rand(0, 99); // 假设水位在0到100之间
}

static void timer_cb(lv_timer_t* timer) {

    int wl = get_water_level();

    for(int i =0 ;i< 16;i++)
    {
        if (ui_waterLevelPanel[i] == NULL)
        {
            ui_waterLevelPanel[i] = lv_obj_create(ui_waterLevel);
        }
        lv_obj_remove_flag(ui_waterLevelPanel[i], LV_OBJ_FLAG_HIDDEN);
        lv_obj_set_width(ui_waterLevelPanel[i],5);
        lv_obj_set_style_border_width(ui_waterLevelPanel[i], 0,LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_x(ui_waterLevelPanel[i], (i-8)*12);
        lv_anim_t a;
        lv_anim_init(&a);
        lv_anim_set_var(&a, ui_waterLevelPanel[i]); // 设置动画关联的对象
        lv_anim_set_time(&a, 500); // 设置动画时间（毫秒）
        if (wl > 50)
        {
            lv_label_set_text(ui_waterLevelLab, "正常");
            lv_anim_set_values(&a, 0, -(i % 16 == 0 ? HIGHT : i % 16 == 1 ? HIGHT / 2 : i % 16 == 2 ? -(HIGHT / 2) : i % 16 == 3 ? -HIGHT : i % 16 == 4 ? -(HIGHT * 3 / 2) : i % 16 == 5 ? -(HIGHT * 4 / 2) : i % 16 == 6 ? -(HIGHT * 3 / 2) : i % 16 == 7 ? -HIGHT : i % 16 == 8 ? -(HIGHT / 2) : i % 16 == 9 ? HIGHT / 2 : i % 16 == 10 ? HIGHT : i % 16 == 11 ? HIGHT * 3 / 2 : i % 16 == 12 ? HIGHT * 4 / 2 : i % 16 == 13 ? HIGHT * 3 / 2 : i % 16 == 14 ? HIGHT : HIGHT / 2));
        }
        else
        {
            lv_label_set_text(ui_waterLevelLab, "缺水");
            lv_anim_set_values(&a, 0, (i % 16 == 0 ? HIGHT : i % 16 == 1 ? HIGHT / 2 : i % 16 == 2 ? -(HIGHT / 2) : i % 16 == 3 ? -HIGHT : i % 16 == 4 ? -(HIGHT * 3 / 2) : i % 16 == 5 ? -(HIGHT * 4 / 2) : i % 16 == 6 ? -(HIGHT * 3 / 2) : i % 16 == 7 ? -HIGHT : i % 16 == 8 ? -(HIGHT / 2) : i % 16 == 9 ? HIGHT / 2 : i % 16 == 10 ? HIGHT : i % 16 == 11 ? HIGHT * 3 / 2 : i % 16 == 12 ? HIGHT * 4 / 2 : i % 16 == 13 ? HIGHT * 3 / 2 : i % 16 == 14 ? HIGHT : HIGHT / 2));
        }
        if (i > 8)
            if (wl > 50)
                lv_obj_set_style_bg_color(ui_waterLevelPanel[i], lv_color_hex(LANDE), LV_PART_MAIN | LV_STATE_DEFAULT);
            else
                lv_obj_set_style_bg_color(ui_waterLevelPanel[i], lv_palette_main(LV_PALETTE_RED), LV_PART_MAIN | LV_STATE_DEFAULT);
        else
            lv_obj_set_style_bg_color(ui_waterLevelPanel[i], lv_color_hex(0x909090), LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_anim_set_exec_cb(&a, water_level_anim_cb); // 设置动画步骤回调函数
        lv_anim_start(&a); // 启动动画
        lv_obj_set_align(ui_waterLevelPanel[i], LV_ALIGN_CENTER);
    }
}

static void water_level_anim_cb(void * var, int32_t v)
{
    // 获取当前动画的关联对象（这里假设是面板）
    lv_obj_t* panel = var;

    // 设置面板的高度（v 是动画的当前值，范围从 0 到目标高度）
    lv_obj_set_height(panel, (v>0?v:-v)*2);
    lv_obj_set_y(panel,v);
}

static void hidden_cb(void *arg)
{
    for (int i = 0;i < 16;i++)
    {
        lv_obj_add_flag(ui_waterLevelPanel[i], LV_OBJ_FLAG_HIDDEN);
    }
}
