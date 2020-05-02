/*
*microstriptCalculatorScreenFormula.c
*/
#include "microstriptCalculatorScreenFormula.h"
LV_IMG_DECLARE(msCalFormulla1);
LV_IMG_DECLARE(msCalFormulla2);
LV_IMG_DECLARE(msCalFormulla3);
LV_IMG_DECLARE(msCalFormulla4);
LV_IMG_DECLARE(msCalFormulla5);
/*Functions*/
void formulaPageStyles(void);
void formulaPage(void);
void formula1Image(void);
void formula2Image(void);
void formula3Image(void);
void formula4Image(void);
void formula5Image(void);

static lv_style_t McAL_scrollStyle, McAL_SbStyle, McAL_BgStyle;
lv_obj_t * page;

void microstriptCalculatorFormulaScreen(void) {
	formulaPage();
	
}

void formula1Image(void)
{
	lv_obj_t * img1 = lv_img_create(page, NULL);
	lv_img_set_src(img1, &msCalFormulla1);
	lv_obj_align(img1, NULL, LV_ALIGN_IN_TOP_LEFT, 5, 50);

	formulaPageStyles();

	

	lv_obj_t * label2 = lv_label_create(page, NULL);
	lv_label_set_recolor(label2, true);
	lv_label_set_long_mode(label2, LV_LABEL_LONG_BREAK);
	lv_label_set_text(label2, "#ffffff Step 1: Calculation of the Width(W)#");
	lv_label_set_style(label2, LV_LABEL_STYLE_MAIN, &McAL_BgStyle);
	lv_obj_set_width(label2, 400);
	lv_obj_align(label2, NULL, LV_ALIGN_IN_TOP_LEFT, 5, 25);
	

}
void formula2Image(void)
{
	lv_obj_t * img1 = lv_img_create(page, NULL);
	lv_img_set_src(img1, &msCalFormulla2);
	lv_obj_align(img1, NULL, LV_ALIGN_IN_TOP_LEFT, 5, 240);

	formulaPageStyles();

	lv_obj_t * label3 = lv_label_create(page, NULL);
	lv_label_set_recolor(label3, true);
	lv_label_set_long_mode(label3, LV_LABEL_LONG_BREAK);
	lv_label_set_text(label3, "#ffffff Step 2: Calculation of the Effective Dielectric# \n#ffffff Constant. "
		" This is based on the height, dielectric# \n#ffffff constant  of the dielectric and the calculated # \n#ffffff width  of the patch antenna. #");
	lv_label_set_style(label3, LV_LABEL_STYLE_MAIN, &McAL_BgStyle);
	lv_obj_set_width(label3, 400);
	lv_obj_align(label3, NULL, LV_ALIGN_IN_TOP_LEFT, 5, 150);

}
void formula3Image(void)
{
	lv_obj_t * img1 = lv_img_create(page, NULL);
	lv_img_set_src(img1, &msCalFormulla3);
	lv_obj_align(img1, NULL, LV_ALIGN_IN_TOP_LEFT, 5, 355);

	formulaPageStyles();

	lv_obj_t * label4 = lv_label_create(page, NULL);
	lv_label_set_recolor(label4, true);
	lv_label_set_long_mode(label4, LV_LABEL_LONG_BREAK);
	lv_label_set_text(label4, "#ffffff Step 3: Calculation of the Effective length #");
	lv_label_set_style(label4, LV_LABEL_STYLE_MAIN, &McAL_BgStyle);
	lv_obj_set_width(label4, 400);
	lv_obj_align(label4, NULL, LV_ALIGN_IN_TOP_LEFT, 5, 325);
}
void formula4Image(void)
{
	lv_obj_t * img1 = lv_img_create(page, NULL);
	lv_img_set_src(img1, &msCalFormulla4);
	lv_obj_align(img1, NULL, LV_ALIGN_IN_TOP_LEFT, 5, 450);

	formulaPageStyles();

	lv_obj_t * label4 = lv_label_create(page, NULL);
	lv_label_set_recolor(label4, true);
	lv_label_set_long_mode(label4, LV_LABEL_LONG_BREAK);
	lv_label_set_text(label4, "#ffffff Step 4: Calculation of the length extension delL #");
	lv_label_set_style(label4, LV_LABEL_STYLE_MAIN, &McAL_BgStyle);
	lv_obj_set_width(label4, 400);
	lv_obj_align(label4, NULL, LV_ALIGN_IN_TOP_LEFT, 5, 425);

}
void formula5Image(void)
{
	lv_obj_t * img1 = lv_img_create(page, NULL);
	lv_img_set_src(img1, &msCalFormulla5);
	lv_obj_align(img1, NULL, LV_ALIGN_IN_TOP_LEFT, 5, 580);

	formulaPageStyles();
	
	lv_obj_t * label4 = lv_label_create(page, NULL);
	lv_label_set_recolor(label4, true);
	lv_label_set_long_mode(label4, LV_LABEL_LONG_BREAK);
	lv_label_set_text(label4, "#ffffff Step 5: Calculation of actual length of the patch #");
	lv_label_set_style(label4, LV_LABEL_STYLE_MAIN, &McAL_BgStyle);
	lv_obj_set_width(label4, 400);
	lv_obj_align(label4, NULL, LV_ALIGN_IN_TOP_LEFT, 5, 555);
}

void formulaPage(void)
{
	formulaPageStyles();
	page = lv_page_create(lv_scr_act(), NULL);
	lv_obj_set_size(page, 440, 260);
	lv_obj_align(page, NULL, LV_ALIGN_CENTER, 0, 0);
	lv_page_set_style(page, LV_PAGE_STYLE_SCRL, &McAL_scrollStyle);          
	lv_page_set_style(page, LV_PAGE_STYLE_SB, &McAL_scrollStyle);          
	lv_page_set_style(page, LV_PAGE_STYLE_BG, &McAL_BgStyle);           


	lv_obj_t * label1 = lv_label_create(page, NULL);
	lv_label_set_recolor(label1, true);
	lv_label_set_long_mode(label1, LV_LABEL_LONG_BREAK);
	lv_label_set_text(label1, "#ff0000 Microstrip Patch Antenna Calculation Process #");
	lv_label_set_style(label1, LV_LABEL_STYLE_MAIN, &McAL_BgStyle);
	lv_obj_set_width(label1, 400);
	
	
	
	formula1Image();
	formula2Image();
	formula3Image();
	formula4Image();
	formula5Image();

	lv_obj_t * label4 = lv_label_create(page, NULL);
	lv_label_set_recolor(label4, true);
	lv_label_set_long_mode(label4, LV_LABEL_LONG_BREAK);
	lv_label_set_text(label4, "#ff0000 Where the following parameters are used; #"
	"\n#00ff00 f0 #is the #ff0000 Resonance Frequency, #"
	"\n#00ff00 W #is the #ff0000 Width of the Patch, #"
	"\n#00ff00 L #is the #ff0000 Length of the Patch, #"
	"\n#00ff00 h #is the #ff0000 the thickness, #"
	"\n#00ff00 Er #is the #ff0000  relative Permittivity of the dielectric # \n#ff0000 substrate, #"
	"\n#00ff00 c #is the #ff0000 Speed of light: 3 x 10^8. #"
	);
	lv_label_set_style(label4, LV_LABEL_STYLE_MAIN, &McAL_BgStyle);
	lv_obj_set_width(label4, 400);
	lv_obj_align(label4, NULL, LV_ALIGN_IN_TOP_LEFT, 5, 620);

}
void formulaPageDelete(void) {
	lv_obj_clean(page);
}
void formulaPageStyles(void) {

	lv_style_copy(&McAL_scrollStyle, &lv_style_plain);
	McAL_scrollStyle.body.main_color = lv_color_hsv_to_rgb(0, 11, 18);
	McAL_scrollStyle.body.grad_color = lv_color_hsv_to_rgb(0, 11, 18);
	McAL_scrollStyle.body.border.color = lv_color_hex3(0x333);
	McAL_scrollStyle.body.border.width = 1;
	McAL_scrollStyle.body.radius = 10;

	lv_style_copy(&McAL_SbStyle, &lv_style_plain);
	McAL_SbStyle.body.main_color = lv_color_make(0, 191, 255);
	McAL_SbStyle.body.grad_color = lv_color_make(0, 191, 255);
	McAL_SbStyle.body.border.width = 0;
	McAL_SbStyle.body.padding.inner = 3;
	McAL_SbStyle.body.padding.left = 0;
	McAL_SbStyle.body.padding.right = 0;
	McAL_SbStyle.body.padding.top = 0;
	McAL_SbStyle.body.padding.bottom = 0;
	McAL_SbStyle.body.radius = LV_DPI / 30;
	McAL_SbStyle.body.opa = LV_OPA_COVER;

	lv_style_copy(&McAL_BgStyle, &lv_style_plain);
	McAL_BgStyle.body.opa = LV_OPA_COVER;
	McAL_BgStyle.glass = 0;
	McAL_BgStyle.body.radius = 0;
	McAL_BgStyle.body.padding.left = LV_DPI / 8;
	McAL_BgStyle.body.padding.right = LV_DPI / 8;
	McAL_BgStyle.body.padding.top = LV_DPI / 8;
	McAL_BgStyle.body.padding.bottom = LV_DPI / 8;
	McAL_BgStyle.body.padding.inner = LV_DPI / 8;
	McAL_BgStyle.text.letter_space = 1;
	McAL_BgStyle.text.line_space = 2;
	McAL_BgStyle.image.color = lv_color_make(255, 248, 220);
	McAL_BgStyle.image.intense = LV_OPA_TRANSP;
	McAL_BgStyle.line.color = lv_color_make(255, 248, 220);
	McAL_BgStyle.line.width = 1;
	McAL_BgStyle.body.radius = LV_DPI / 10;
	McAL_BgStyle.body.main_color = lv_color_make(255, 248, 220);
	McAL_BgStyle.body.grad_color = lv_color_make(255, 248, 220);
	McAL_BgStyle.body.border.color = lv_color_make(255, 248, 220);
	McAL_BgStyle.body.border.width = 2;
	McAL_BgStyle.body.border.opa = LV_OPA_60;
	McAL_BgStyle.text.color = lv_color_make(255, 255,255);
	McAL_BgStyle.line.color = lv_color_make(255, 248, 220);
}