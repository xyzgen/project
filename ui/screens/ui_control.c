﻿#include "../ui.h"

typedef struct mod {
    char name[10];
    void* img;
    void (*event)(void *e);

}mod_t;

static mod_t mod[8] =
{
    {"温度", &ui_img_temp_png, ui_event_tempBtn},
    {"水位", &ui_img_level_png, ui_event_waterLevelBtn},
    {"水泵", &ui_img_pump_png, ui_event_waterPumpBtn},
    {"灯光", &ui_img_light_png, ui_event_lighterBtn},
    {"更多", &ui_img_more_png, ui_event_lighterBtn},
    {"加热棒", &ui_img_heater_png, ui_event_heaterBtn},
    {"杀菌灯", &ui_img_light_png, ui_event_lighterBtn},
    {"香薰", &ui_img_aroma_png, ui_event_AromatherapyBtn},
};

typedef struct module
{
    mod_t *mod;
    struct module* next;
}module_t;

static module_t* module;

static void module_add_node(mod_t *new_mod)
{
    module_t* pos;
    module_t* new_module = malloc(sizeof(module_t));
    new_module->mod = new_mod;
    for (pos = module;pos->next != module;pos = pos->next) { ; }
    new_module->next = pos->next;
    pos->next = new_module;
}

static void module_init(void)
{
    module = malloc(sizeof(module_t));
    module->next = module;
    for (size_t i = 0; i < 5; i++)
    {
        module_add_node(&mod[i]);
    }
}

void ui_control_screen_init(void)
{
    module_init();
    ui_control = lv_obj_create(NULL);
    lv_obj_remove_flag(ui_control, LV_OBJ_FLAG_SCROLLABLE);    /// Flags
    lv_obj_set_style_bg_color(ui_control, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_t* ui_listLab = lv_label_create(ui_control);
    lv_obj_align(ui_listLab, LV_ALIGN_TOP_LEFT,16,16);
    lv_label_set_text(ui_listLab, "控制");
    lv_obj_set_style_text_color(ui_listLab, lv_color_hex(LANDE), LV_PART_MAIN);
    lv_obj_set_style_text_font(ui_listLab, &ui_font_Chinese16B,LV_PART_MAIN);

    ui_controlList = lv_list_create(ui_control);
    lv_obj_set_size(ui_controlList, lv_pct(100), lv_pct(85));
    lv_obj_set_style_pad_row(ui_controlList, 5, 0);
    lv_obj_set_align( ui_controlList, LV_ALIGN_BOTTOM_MID);
    lv_obj_set_flex_flow(ui_controlList,LV_FLEX_FLOW_ROW_WRAP);
    lv_obj_set_flex_align(ui_controlList, LV_FLEX_ALIGN_START, LV_FLEX_ALIGN_START, LV_FLEX_ALIGN_START);
    lv_obj_set_style_bg_color(ui_controlList, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT );
    lv_obj_set_style_bg_opa(ui_controlList, 0, LV_PART_MAIN| LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_controlList, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT );
    lv_obj_set_style_border_opa(ui_controlList, 0, LV_PART_MAIN| LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui_controlList, 0, LV_PART_SCROLLBAR| LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui_controlList, 0, LV_PART_SCROLLBAR| LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui_controlList, 0, LV_PART_SCROLLBAR| LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui_controlList, 0, LV_PART_SCROLLBAR| LV_STATE_DEFAULT);
    lv_obj_set_style_pad_row(ui_controlList, 0, LV_PART_SCROLLBAR| LV_STATE_DEFAULT);
    lv_obj_set_style_pad_column(ui_controlList, 0, LV_PART_SCROLLBAR| LV_STATE_DEFAULT);

    for (module_t* pos = module->next;pos != module;pos = pos->next) {
        lv_obj_t* ui_listBtn = lv_button_create(ui_controlList);
        lv_obj_set_align(ui_listBtn, LV_ALIGN_CENTER);
        lv_obj_set_size(ui_listBtn, lv_pct(100),lv_pct(20));
        lv_obj_add_flag(ui_listBtn, LV_OBJ_FLAG_SCROLL_ON_FOCUS);   /// Flags
        lv_obj_remove_flag(ui_listBtn, LV_OBJ_FLAG_SCROLLABLE);    /// Flags
        lv_obj_set_style_bg_color(ui_listBtn, lv_color_hex(0x909090), LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_bg_opa(ui_listBtn, 127, LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_shadow_opa(ui_listBtn, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

        lv_obj_t* ui_listBtnLab = lv_label_create(ui_listBtn);
        lv_obj_align(ui_listBtnLab, LV_ALIGN_LEFT_MID,32,0);
        lv_label_set_text_fmt(ui_listBtnLab, "%s", pos->mod->name);
        lv_obj_set_style_text_font(ui_listBtnLab, &ui_font_Chinese16B, LV_PART_MAIN | LV_STATE_DEFAULT);

        lv_obj_t* ui_listImg = lv_image_create(ui_listBtn);
        lv_image_set_src(ui_listImg, pos->mod->img);
        lv_obj_set_align(ui_listImg, LV_ALIGN_LEFT_MID);
        lv_obj_add_flag(ui_listImg, LV_OBJ_FLAG_CLICKABLE);   /// Flags
        lv_obj_remove_flag(ui_listImg, LV_OBJ_FLAG_SCROLLABLE);    /// Flags
        //lv_obj_set_style_radius(ui_listImg, 16, LV_PART_MAIN | LV_STATE_DEFAULT);
        //lv_obj_set_style_bg_color(ui_listImg, lv_color_hex(0x1D469E), LV_PART_MAIN | LV_STATE_DEFAULT);
        //lv_obj_set_style_bg_opa(ui_listImg, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_image_recolor(ui_listImg, lv_color_hex(LANDE), LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_image_recolor_opa(ui_listImg, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_add_event_cb(ui_listBtn, pos->mod->event, LV_EVENT_ALL, NULL);
    }
    lv_obj_add_event_cb(ui_control, ui_event_status, LV_EVENT_ALL, NULL);
}