
/*
*microstriptCalculatorScreenDeveloper.c
*/
#include "microstriptCalculatorScreenDeveloper.h"

static lv_style_t McAL_scrollStyle2, McAL_SbStyle2, McAL_BgStyle2;
lv_obj_t * page2;
void DeveloperPage(void);
void DeveloperPageStyles(void);

void microstriptCalculatorDeveloperScreen(void) {
	DeveloperPage();

}
void DeveloperPage(void)
{
	DeveloperPageStyles();
	page2 = lv_page_create(lv_scr_act(), NULL);
	lv_obj_set_size(page2, 440, 260);
	lv_obj_align(page2, NULL, LV_ALIGN_CENTER, 0, 0);
	lv_page_set_style(page2, LV_PAGE_STYLE_SCRL, &McAL_scrollStyle2);
	lv_page_set_style(page2, LV_PAGE_STYLE_SB, &McAL_scrollStyle2);
	lv_page_set_style(page2, LV_PAGE_STYLE_BG, &McAL_BgStyle2);


	lv_obj_t * labelDev = lv_label_create(page2, NULL);
	lv_label_set_recolor(labelDev, true);
	lv_label_set_long_mode(labelDev, LV_LABEL_LONG_BREAK);
	lv_label_set_text(labelDev, "This application is using calculate lenght and weidth for Microstrip Path Antena. "
	"\n Developer by #ff0000  Neset Aydin #");
	lv_label_set_style(labelDev, LV_LABEL_STYLE_MAIN, &McAL_BgStyle2);
	lv_obj_set_width(labelDev, 400);
	lv_obj_align(labelDev, NULL, LV_ALIGN_IN_TOP_LEFT, 5, 25);
}
void DeveloperPageDelete(void) {
	lv_obj_clean(page2);
}

void DeveloperPageStyles(void) {

	lv_style_copy(&McAL_scrollStyle2, &lv_style_plain);
	McAL_scrollStyle2.body.main_color = lv_color_hsv_to_rgb(0, 11, 18);
	McAL_scrollStyle2.body.grad_color = lv_color_hsv_to_rgb(0, 11, 18);
	McAL_scrollStyle2.body.border.color = lv_color_hex3(0x333);
	McAL_scrollStyle2.body.border.width = 1;
	McAL_scrollStyle2.body.radius = 10;

	lv_style_copy(&McAL_SbStyle2, &lv_style_plain);
	McAL_SbStyle2.body.main_color = lv_color_make(0, 191, 255);
	McAL_SbStyle2.body.grad_color = lv_color_make(0, 191, 255);
	McAL_SbStyle2.body.border.width = 0;
	McAL_SbStyle2.body.padding.inner = 3;
	McAL_SbStyle2.body.padding.left = 0;
	McAL_SbStyle2.body.padding.right = 0;
	McAL_SbStyle2.body.padding.top = 0;
	McAL_SbStyle2.body.padding.bottom = 0;
	McAL_SbStyle2.body.radius = LV_DPI / 30;
	McAL_SbStyle2.body.opa = LV_OPA_COVER;

	lv_style_copy(&McAL_BgStyle2, &lv_style_plain);
	McAL_BgStyle2.body.opa = LV_OPA_COVER;
	McAL_BgStyle2.glass = 0;
	McAL_BgStyle2.body.radius = 0;
	McAL_BgStyle2.body.padding.left = LV_DPI / 8;
	McAL_BgStyle2.body.padding.right = LV_DPI / 8;
	McAL_BgStyle2.body.padding.top = LV_DPI / 8;
	McAL_BgStyle2.body.padding.bottom = LV_DPI / 8;
	McAL_BgStyle2.body.padding.inner = LV_DPI / 8;
	McAL_BgStyle2.text.letter_space = 1;
	McAL_BgStyle2.text.line_space = 2;
	McAL_BgStyle2.image.color = lv_color_make(255, 248, 220);
	McAL_BgStyle2.image.intense = LV_OPA_TRANSP;
	McAL_BgStyle2.line.color = lv_color_make(255, 248, 220);
	McAL_BgStyle2.line.width = 1;
	McAL_BgStyle2.body.radius = LV_DPI / 10;
	McAL_BgStyle2.body.main_color = lv_color_make(255, 248, 220);
	McAL_BgStyle2.body.grad_color = lv_color_make(255, 248, 220);
	McAL_BgStyle2.body.border.color = lv_color_make(255, 248, 220);
	McAL_BgStyle2.body.border.width = 2;
	McAL_BgStyle2.body.border.opa = LV_OPA_60;
	McAL_BgStyle2.text.color = lv_color_make(255, 255, 255);
	McAL_BgStyle2.line.color = lv_color_make(255, 248, 220);
}