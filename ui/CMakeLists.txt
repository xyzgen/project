SET(SOURCES screens/ui_main.c
    screens/ui_light.c
    screens/ui_light1.c
    screens/ui_pump.c
    screens/ui_pump1.c
    ui_theme_manager.c
    ui_themes.c
    ui.c
    components/ui_comp_hook.c
    ui_helpers.c
    images/ui_img_setup_png.c
    images/ui_img_light_png.c
    images/ui_img_heater_png.c
    images/ui_img_pump_png.c
    images/ui_img_feed_png.c
    images/ui_img_level_png.c
    images/ui_img_aroma_png.c
    images/ui_img_cloud_png.c
    images/ui_img_qr_code_png.c
    images/ui_img_off_png.c
    fonts/ui_font_Chinese10.c
    fonts/ui_font_Chinese12.c
    fonts/ui_font_Chinese14.c
    fonts/ui_font_Chinese16.c
    fonts/ui_font_Chinese16B.c
    fonts/ui_font_Chinese8.c)

add_library(ui ${SOURCES})
