#include "../ui.h"

typedef struct mmod {
    uint8_t flag;
    uint8_t interFace;
    char name[10];
    void* img;

}mmod_t;

static mmod_t mmod[5] =
{
    {ui_strat_mode_heat,0,"加热棒", &ui_img_heater_png},
    {ui_strat_mode_sanit,0,"杀菌灯", &ui_img_uv_png },
    {ui_strat_mode_aroma,0,"香薰", &ui_img_aroma_png},
    {ui_strat_mode_feed,0,"喂食器", &ui_img_feed_png },
    {ui_strat_mode_isola,0,"蛋分器", &ui_img_decom_png }
};

static void ui_setting_cb(lv_event_t* e);
static void select_interface_event_cb(lv_event_t* e);
static void ui_choose_cb(lv_event_t* code);
static void interface_picker_cancel_event_cb(lv_event_t* e);
static void interface_picker_confirm_event_cb(lv_event_t* e);
static lv_obj_t* interface_picker_dialog = NULL;
static lv_obj_t* setting_dialog = NULL;
static lv_obj_t* settingLab = NULL;
static lv_obj_t* settingBtnLab = NULL;


void ui_more_screen_init(void)
{
    ui_more = lv_obj_create(NULL);
    lv_obj_remove_flag(ui_more, LV_OBJ_FLAG_SCROLLABLE);    /// Flags
    lv_obj_set_style_bg_color(ui_more, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_t* ui_listLab = lv_label_create(ui_more);
    lv_obj_align(ui_listLab, LV_ALIGN_TOP_LEFT,16,16);
    lv_label_set_text(ui_listLab, "更多组件");
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
        lv_obj_t* ui_listBtn = lv_button_create(ui_moreList);
        lv_obj_set_align(ui_listBtn, LV_ALIGN_CENTER);
        lv_obj_set_size(ui_listBtn, lv_pct(100), lv_pct(20));
        lv_obj_add_flag(ui_listBtn, LV_OBJ_FLAG_SCROLL_ON_FOCUS);   /// Flags
        lv_obj_remove_flag(ui_listBtn, LV_OBJ_FLAG_SCROLLABLE);    /// Flags
        lv_obj_set_style_bg_color(ui_listBtn, lv_color_hex(0x909090), LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_bg_opa(ui_listBtn, 127, LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_shadow_opa(ui_listBtn, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_add_event_cb(ui_listBtn, ui_setting_cb, LV_EVENT_PRESSED, &mmod[i]);

        lv_obj_t* ui_listLab = lv_label_create(ui_listBtn);
        lv_obj_set_align(ui_listLab, LV_ALIGN_CENTER);
        lv_label_set_text_fmt(ui_listLab, "%s", mmod[i].name);
        lv_obj_set_style_text_color(ui_listLab, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_text_font(ui_listLab, &ui_font_Chinese16B, LV_PART_MAIN | LV_STATE_DEFAULT);

        lv_obj_t* ui_listImg = lv_image_create(ui_listBtn);
        lv_image_set_src(ui_listImg, mmod[i].img);
        lv_obj_set_align(ui_listImg, LV_ALIGN_LEFT_MID);
        lv_obj_add_flag(ui_listImg, LV_OBJ_FLAG_CLICKABLE);   /// Flags
        lv_obj_remove_flag(ui_listImg, LV_OBJ_FLAG_SCROLLABLE);    /// Flags
        lv_obj_set_style_image_recolor(ui_listImg, lv_color_hex(LANDE), LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_image_recolor_opa(ui_listImg, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

        lv_obj_t* ui_listBtnSwitch = lv_switch_create(ui_listBtn);
        lv_obj_set_style_bg_color(ui_listBtnSwitch, lv_color_hex(LANDE), LV_PART_INDICATOR|LV_STATE_CHECKED);
        lv_obj_add_event_cb(ui_listBtnSwitch, ui_choose_cb, LV_EVENT_VALUE_CHANGED, &mmod[i]);
        lv_obj_align(ui_listBtnSwitch, LV_ALIGN_RIGHT_MID, -16, 0);
        
    }
    lv_obj_add_event_cb(ui_more, ui_event_more, LV_EVENT_ALL, NULL);
}

static void ui_event_setting(lv_event_t* e) {
    static lv_point_t press_p, release_p;

    lv_event_code_t event_code = lv_event_get_code(e);

    if (event_code == LV_EVENT_PRESSED)
    {
        lv_indev_get_point(lv_event_get_indev(e), &press_p);
    }
    if (event_code == LV_EVENT_RELEASED)
    {
        lv_indev_get_point(lv_event_get_indev(e), &release_p);
        if (press_p.x - release_p.x > 20 || release_p.x - press_p.x > 20)
        {
            _ui_screen_change(&ui_more, LV_SCR_LOAD_ANIM_FADE_ON, 500, 0, NULL);
            lv_obj_del(setting_dialog);
            setting_dialog = NULL;
        }
    }
}

static void ui_setting_cb(lv_event_t* e)
{
    mmod_t* pos = lv_event_get_user_data(e);

    if (setting_dialog == NULL) {

        // 创建接口选择对话框
        setting_dialog = lv_obj_create(ui_more);
        lv_obj_set_size(setting_dialog, 240, 296);
        lv_obj_align(setting_dialog, LV_ALIGN_CENTER, 0, 0);
        lv_obj_set_style_bg_color(setting_dialog, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_bg_opa(setting_dialog, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_add_event_cb(setting_dialog, ui_event_setting, LV_EVENT_ALL, NULL);

        lv_obj_t* label = lv_label_create(setting_dialog);
        lv_obj_align(label, LV_ALIGN_TOP_LEFT, 0, 0);
        lv_label_set_text(label, pos->name);
        lv_obj_set_style_text_color(label, lv_color_hex(LANDE), LV_PART_MAIN);
        lv_obj_set_style_text_font(label, &ui_font_Chinese24B, LV_PART_MAIN);

        settingLab = lv_label_create(setting_dialog);
        lv_obj_align(settingLab, LV_ALIGN_CENTER, 0, 0);

        lv_obj_t* btn = lv_button_create(setting_dialog);

        lv_obj_set_size(btn, 80, 24);
        lv_obj_align(btn, LV_ALIGN_BOTTOM_MID, 0, -16);
        lv_obj_add_event_cb(btn, select_interface_event_cb, LV_EVENT_PRESSED, pos);

        settingBtnLab = lv_label_create(btn);
        lv_obj_center(settingBtnLab);
        lv_obj_set_style_text_color(settingBtnLab, lv_color_hex(0xFFFFFF), LV_PART_MAIN);
        lv_obj_set_style_text_font(settingBtnLab, &ui_font_Chinese16B, LV_PART_MAIN);

        if(pos->interFace)
        {
            lv_label_set_text_fmt(settingLab, "当前接口 %d",pos->interFace);
            lv_label_set_text(settingBtnLab, "更改接口");
        }
        else
        {
            lv_label_set_text(settingLab, "当前接口 -");
            lv_label_set_text(settingBtnLab, "点击去设置");
        }
        lv_obj_set_style_text_color(settingLab, lv_color_hex(0xFFFFFF), LV_PART_MAIN);
        lv_obj_set_style_text_font(settingLab, &ui_font_Chinese16B, LV_PART_MAIN);
    }
}

static void ui_event_picker(lv_event_t* e) {
    static lv_point_t press_p, release_p;

    lv_event_code_t event_code = lv_event_get_code(e);

    if (event_code == LV_EVENT_PRESSED)
    {
        lv_indev_get_point(lv_event_get_indev(e), &press_p);
    }
    if (event_code == LV_EVENT_RELEASED)
    {
        lv_indev_get_point(lv_event_get_indev(e), &release_p);
        if (press_p.x - release_p.x > 20 || release_p.x - press_p.x > 20)
        {
            _ui_screen_change(&setting_dialog, LV_SCR_LOAD_ANIM_FADE_ON, 500, 0, NULL);
            lv_obj_del(interface_picker_dialog);
            interface_picker_dialog = NULL;
        }


    }
}

static void select_interface_event_cb(lv_event_t* e)
{
    mmod_t* pos = lv_event_get_user_data(e);
    if (interface_picker_dialog == NULL) {

        // 创建接口选择对话框
        interface_picker_dialog = lv_obj_create(setting_dialog);
        lv_obj_set_size(interface_picker_dialog, 240, 296);
        lv_obj_align(interface_picker_dialog, LV_ALIGN_CENTER, 0, 0);
        lv_obj_set_style_bg_color(interface_picker_dialog, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_bg_opa(interface_picker_dialog, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_add_event_cb(interface_picker_dialog, ui_event_picker, LV_EVENT_ALL, NULL);

        lv_obj_t* label = lv_label_create(interface_picker_dialog);
        lv_obj_align(label, LV_ALIGN_TOP_LEFT, 16, 16);
        lv_label_set_text(label, "设定接口");
        lv_obj_set_style_text_color(label, lv_color_hex(LANDE), LV_PART_MAIN);
        lv_obj_set_style_text_font(label, &ui_font_Chinese24B, LV_PART_MAIN);

        label = lv_label_create(interface_picker_dialog);
        lv_obj_align(label, LV_ALIGN_CENTER, 0, 32);
        lv_label_set_text(label, "备注:鱼缸接口\n从上到下为1~7");
        lv_obj_set_style_text_color(label, lv_color_hex(LANDE), LV_PART_MAIN);
        lv_obj_set_style_text_font(label, &ui_font_Chinese16B, LV_PART_MAIN);

        // 选择器
        static lv_style_t style;
        lv_style_init(&style);
        lv_style_set_size(&style, 90, 24);
        lv_style_set_bg_color(&style, lv_color_black());
        lv_style_set_text_color(&style, lv_color_white());
        lv_style_set_text_font(&style, &ui_font_Chinese16B);
        lv_style_set_border_width(&style, 0);
        lv_style_set_radius(&style, 0);

        ui_interfaceRoller = lv_roller_create(interface_picker_dialog);
        lv_obj_add_style(ui_interfaceRoller, &style, 0);
        lv_obj_set_style_bg_opa(ui_interfaceRoller, LV_OPA_50, LV_PART_SELECTED);

        lv_roller_set_options(ui_interfaceRoller,
            "1\n"
            "2\n"
            "3\n"
            "4\n"
            "5\n"
            "6\n"
            "7",
            LV_ROLLER_MODE_NORMAL);

        lv_obj_align(ui_interfaceRoller, LV_ALIGN_CENTER, 0, -32);
        lv_roller_set_visible_row_count(ui_interfaceRoller, 3);

        // 创建“确定”和“取消”按钮
        lv_obj_t* btn_confirm = lv_btn_create(interface_picker_dialog);
        lv_obj_align(btn_confirm, LV_ALIGN_BOTTOM_MID, 60, -10);
        lv_obj_set_style_size(btn_confirm, 40, 40, LV_PART_MAIN);
        lv_obj_set_style_radius(btn_confirm, LV_RADIUS_CIRCLE, LV_PART_MAIN);
        lv_obj_set_style_bg_color(btn_confirm, lv_palette_main(LV_PALETTE_GREEN), LV_PART_MAIN);
        lv_obj_t* label_confirm = lv_label_create(btn_confirm);
        lv_obj_center(label_confirm);
        lv_label_set_text(label_confirm, LV_SYMBOL_OK);
        lv_obj_set_style_text_font(label_confirm, &lv_font_montserrat_32, LV_PART_MAIN);

        lv_obj_add_event_cb(btn_confirm, interface_picker_confirm_event_cb, LV_EVENT_CLICKED, pos);

        lv_obj_t* btn_cancel = lv_btn_create(interface_picker_dialog);
        lv_obj_align(btn_cancel, LV_ALIGN_BOTTOM_MID, -60, -10);
        lv_obj_set_style_size(btn_cancel, 40, 40, LV_PART_MAIN);
        lv_obj_set_style_radius(btn_cancel, LV_RADIUS_CIRCLE, LV_PART_MAIN);
        lv_obj_set_style_bg_color(btn_cancel, lv_palette_main(LV_PALETTE_RED), LV_PART_MAIN);
        lv_obj_t* label_cancel = lv_label_create(btn_cancel);
        lv_obj_center(label_cancel);
        lv_label_set_text(label_cancel, LV_SYMBOL_CLOSE);
        lv_obj_set_style_text_font(label_cancel, &lv_font_montserrat_32, LV_PART_MAIN);

        lv_obj_add_event_cb(btn_cancel, interface_picker_cancel_event_cb, LV_EVENT_CLICKED, NULL);
    }
}

static void ui_choose_cb(lv_event_t* e)
{
    mmod_t* pos = lv_event_get_user_data(e);
    lv_obj_t* obj = lv_event_get_target(e);
    LV_UNUSED(obj);
    if (lv_obj_has_state(obj, LV_STATE_CHECKED))
    {
        ui_strat_mode_enable_mask |= pos->flag;
    }
    else
    {
        ui_strat_mode_enable_mask &= ~(pos->flag);
    }
}

// 接口选择确定回调
static void interface_picker_confirm_event_cb(lv_event_t* e) {
    mmod_t* pos = lv_event_get_user_data(e);
    pos->interFace = lv_roller_get_selected(ui_interfaceRoller)+1;

    lv_label_set_text_fmt(settingLab, "当前接口 %d", pos->interFace);
    lv_label_set_text(settingBtnLab, "更改接口");

    lv_obj_del(interface_picker_dialog);  // 关闭对话框
    interface_picker_dialog = NULL;       // 清除对话框
}

// 接口选择取消回调
static void interface_picker_cancel_event_cb(lv_event_t* e) {
    lv_obj_del(interface_picker_dialog);  // 关闭对话框
    interface_picker_dialog = NULL;       // 清除对话框
}
