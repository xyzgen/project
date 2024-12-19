#include "../ui.h"

typedef struct mmod {
    uint8_t flag;
    char name[10];
    void* img;
}mmod_t;

static mmod_t mmod[5] =
{
    {ui_strat_mode_heat,"加热棒", &ui_img_heater_png},
    {ui_strat_mode_sanit,"杀菌灯", &ui_img_uv_png },
    {ui_strat_mode_aroma,"香薰", &ui_img_aroma_png},
    {ui_strat_mode_feed,"喂食器", &ui_img_feed_png },
    {ui_strat_mode_isola,"蛋分器", &ui_img_decom_png }
};

static void ui_choose_cb(lv_event_t* code);

void ui_more_screen_init(void)
{
    ui_more = lv_obj_create(NULL);
    lv_obj_remove_flag(ui_more, LV_OBJ_FLAG_SCROLLABLE);    /// Flags
    lv_obj_set_style_bg_color(ui_more, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_t* ui_listLab = lv_label_create(ui_more);
    lv_obj_align(ui_listLab, LV_ALIGN_TOP_LEFT,16,16);
    lv_label_set_text(ui_listLab, "可选组件");
    lv_obj_set_style_text_color(ui_listLab, lv_color_hex(LANDE), LV_PART_MAIN);
    lv_obj_set_style_text_font(ui_listLab, &ui_font_Chinese16B,LV_PART_MAIN);

    ui_moreList = lv_list_create(ui_more);
    lv_obj_set_size(ui_moreList, lv_pct(100), lv_pct(85));
    lv_obj_set_style_pad_row(ui_moreList, 5, 0);
    lv_obj_set_align(ui_moreList, LV_ALIGN_BOTTOM_MID);
    lv_obj_set_flex_flow(ui_moreList, LV_FLEX_FLOW_ROW_WRAP);
    lv_obj_set_flex_align(ui_moreList, LV_FLEX_ALIGN_START, LV_FLEX_ALIGN_START, LV_FLEX_ALIGN_START);
    lv_obj_set_style_bg_color(ui_moreList, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_moreList, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_moreList, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui_moreList, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui_moreList, 0, LV_PART_SCROLLBAR | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui_moreList, 0, LV_PART_SCROLLBAR | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui_moreList, 0, LV_PART_SCROLLBAR | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui_moreList, 0, LV_PART_SCROLLBAR | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_row(ui_moreList, 0, LV_PART_SCROLLBAR | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_column(ui_moreList, 0, LV_PART_SCROLLBAR | LV_STATE_DEFAULT);

    for (int i = 0; i < sizeof(mmod) / sizeof(mmod_t); i++) {
        lv_obj_t* ui_listLab = lv_label_create(ui_moreList);
        lv_obj_set_align(ui_listLab, LV_ALIGN_CENTER);
        lv_obj_set_size(ui_listLab, lv_pct(100), lv_pct(20));
        lv_obj_add_flag(ui_listLab, LV_OBJ_FLAG_SCROLL_ON_FOCUS);   /// Flags
        lv_obj_remove_flag(ui_listLab, LV_OBJ_FLAG_SCROLLABLE);    /// Flags
        lv_obj_set_style_bg_color(ui_listLab, lv_color_hex(0x909090), LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_bg_opa(ui_listLab, 127, LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_shadow_opa(ui_listLab, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

        lv_label_set_text_fmt(ui_listLab, "\n              %s", mmod[i].name);
        lv_obj_set_style_text_color(ui_listLab, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_text_font(ui_listLab, &ui_font_Chinese16B, LV_PART_MAIN | LV_STATE_DEFAULT);

        lv_obj_t* ui_listImg = lv_image_create(ui_listLab);
        lv_image_set_src(ui_listImg, mmod[i].img);
        lv_obj_set_align(ui_listImg, LV_ALIGN_LEFT_MID);
        lv_obj_add_flag(ui_listImg, LV_OBJ_FLAG_CLICKABLE);   /// Flags
        lv_obj_remove_flag(ui_listImg, LV_OBJ_FLAG_SCROLLABLE);    /// Flags
        lv_obj_set_style_image_recolor(ui_listImg, lv_color_hex(LANDE), LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_image_recolor_opa(ui_listImg, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

        lv_obj_t* ui_listLabSwitch = lv_switch_create(ui_listLab);
        lv_obj_set_style_bg_color(ui_listLabSwitch, lv_color_hex(LANDE), LV_PART_INDICATOR|LV_STATE_CHECKED);
        lv_obj_add_event_cb(ui_listLabSwitch, ui_choose_cb, LV_EVENT_VALUE_CHANGED, &mmod[i]);
        lv_obj_align(ui_listLabSwitch, LV_ALIGN_RIGHT_MID, -16, 0);
        
    }
    lv_obj_add_event_cb(ui_more, ui_event_more, LV_EVENT_ALL, NULL);
}

static void ui_choose_cb(lv_event_t* e)
{
    mmod_t* pos = lv_event_get_user_data(e);
    lv_obj_t* obj = lv_event_get_target(e);
    LV_UNUSED(obj);
    if (lv_obj_has_state(obj, LV_STATE_CHECKED))
        ui_strat_mode_enable_mask |= pos->flag;
    else
        ui_strat_mode_enable_mask &= ~(pos->flag);
}
