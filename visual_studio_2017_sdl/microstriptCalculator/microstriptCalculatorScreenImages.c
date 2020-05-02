
/*
*microstriptCalculatorScreenImages.c
*/
#include "microstriptCalculatorScreenImages.h"

LV_IMG_DECLARE(image1);
LV_IMG_DECLARE(image2);
LV_IMG_DECLARE(image3);
void patchImagePageStyles(void);
void patchImagePage(void);

static lv_style_t McAL_scrollStyle1, McAL_SbStyle1, McAL_BgStyle1;
lv_obj_t * page1;


void microstriptCalculatorImageScreen(void) {
	patchImagePage();
}


void patchImage1(void)
{
	lv_obj_t * img1 = lv_img_create(page1, NULL);
	lv_img_set_src(img1, &image1);
	lv_obj_align(img1, NULL, LV_ALIGN_IN_TOP_LEFT, 5, 10);

}

void patchImage2(void)
{
	lv_obj_t * img1 = lv_img_create(page1, NULL);
	lv_img_set_src(img1, &image2);
	lv_obj_align(img1, NULL, LV_ALIGN_IN_TOP_LEFT, 5, 148);

}

void patchImage3(void)
{
	lv_obj_t * img1 = lv_img_create(page1, NULL);
	lv_img_set_src(img1, &image3);
	lv_obj_align(img1, NULL, LV_ALIGN_IN_TOP_LEFT, 5, 349);

}


void patchImagePage(void)
{
	patchImagePageStyles();
	page1 = lv_page_create(lv_scr_act(), NULL);
	lv_obj_set_size(page1, 440, 260);
	lv_obj_align(page1, NULL, LV_ALIGN_CENTER, 0, 0);
	lv_page_set_style(page1, LV_PAGE_STYLE_SCRL, &McAL_scrollStyle1);
	lv_page_set_style(page1, LV_PAGE_STYLE_SB, &McAL_scrollStyle1);
	lv_page_set_style(page1, LV_PAGE_STYLE_BG, &McAL_BgStyle1);

	patchImage1();
	patchImage2();
	patchImage3();
}
void patchImagePageDelete(void) {
	lv_obj_clean(page1);
}


void patchImagePageStyles(void) {

	lv_style_copy(&McAL_scrollStyle1, &lv_style_plain);
	McAL_scrollStyle1.body.main_color = lv_color_hsv_to_rgb(0, 11, 18);
	McAL_scrollStyle1.body.grad_color = lv_color_hsv_to_rgb(0, 11, 18);
	McAL_scrollStyle1.body.border.color = lv_color_hex3(0x333);
	McAL_scrollStyle1.body.border.width = 1;
	McAL_scrollStyle1.body.radius = 10;

	lv_style_copy(&McAL_SbStyle1, &lv_style_plain);
	McAL_SbStyle1.body.main_color = lv_color_make(0, 191, 255);
	McAL_SbStyle1.body.grad_color = lv_color_make(0, 191, 255);
	McAL_SbStyle1.body.border.width = 0;
	McAL_SbStyle1.body.padding.inner = 3;
	McAL_SbStyle1.body.padding.left = 0;
	McAL_SbStyle1.body.padding.right = 0;
	McAL_SbStyle1.body.padding.top = 0;
	McAL_SbStyle1.body.padding.bottom = 0;
	McAL_SbStyle1.body.radius = LV_DPI / 30;
	McAL_SbStyle1.body.opa = LV_OPA_COVER;

	lv_style_copy(&McAL_BgStyle1, &lv_style_plain);
	McAL_BgStyle1.body.opa = LV_OPA_COVER;
	McAL_BgStyle1.glass = 0;
	McAL_BgStyle1.body.radius = 0;
	McAL_BgStyle1.body.padding.left = LV_DPI / 8;
	McAL_BgStyle1.body.padding.right = LV_DPI / 8;
	McAL_BgStyle1.body.padding.top = LV_DPI / 8;
	McAL_BgStyle1.body.padding.bottom = LV_DPI / 8;
	McAL_BgStyle1.body.padding.inner = LV_DPI / 8;
	McAL_BgStyle1.text.letter_space = 1;
	McAL_BgStyle1.text.line_space = 2;
	McAL_BgStyle1.image.color = lv_color_make(255, 248, 220);
	McAL_BgStyle1.image.intense = LV_OPA_TRANSP;
	McAL_BgStyle1.line.color = lv_color_make(255, 248, 220);
	McAL_BgStyle1.line.width = 1;
	McAL_BgStyle1.body.radius = LV_DPI / 10;
	McAL_BgStyle1.body.main_color = lv_color_make(255, 248, 220);
	McAL_BgStyle1.body.grad_color = lv_color_make(255, 248, 220);
	McAL_BgStyle1.body.border.color = lv_color_make(255, 248, 220);
	McAL_BgStyle1.body.border.width = 2;
	McAL_BgStyle1.body.border.opa = LV_OPA_60;
	McAL_BgStyle1.text.color = lv_color_make(255, 255, 255);
	McAL_BgStyle1.line.color = lv_color_make(255, 248, 220);
}