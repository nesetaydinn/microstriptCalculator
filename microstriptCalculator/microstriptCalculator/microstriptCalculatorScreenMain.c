/*
*microstriptCalculatorScreenMain.c
*/
#include "microstriptCalculatorScreenMain.h"

static lv_style_t	MainDownList_SbStyle;
static lv_style_t	MainDownList_SelStyle;
static lv_style_t	MainDownList_bgStyle;
lv_obj_t * mCMainScreen;

void MainDropList(void);
static void MainDropList_event_handler(lv_obj_t * obj, lv_event_t event);
void MainDownListStyle(void);

uint8_t PageController=0;

void microstriptCalculatorMainScreen(void) {

	lv_theme_set_current(lv_theme_mono_init(0,0));
	mCMainScreen =lv_obj_create(0,0);
	lv_disp_load_scr(mCMainScreen);

	//microstriptCalculatorFormulaScreen();
	//microstriptCalculatorImageScreen();
	//microstriptCalculatorDeveloperScreen();
	microstriptCalculatorCalcScreen();
	MainDropList();

}

void MainDropList(void) {
	MainDownListStyle();
	lv_obj_t * ddlist = lv_ddlist_create(lv_scr_act(), NULL);
	lv_ddlist_set_options(ddlist,	"Calculator\n"
									"Formula\n"
									"Images\n"
									"Developer");
	lv_ddlist_set_draw_arrow(ddlist, true);
	lv_ddlist_set_style(ddlist, LV_DDLIST_STYLE_SB, &MainDownList_SbStyle);
	lv_ddlist_set_style(ddlist, LV_DDLIST_STYLE_BG, &MainDownList_bgStyle);
	lv_ddlist_set_style(ddlist, LV_DDLIST_STYLE_SEL, &MainDownList_SelStyle);
	lv_obj_set_size(ddlist,120, 25);
	lv_obj_align(ddlist, NULL, LV_ALIGN_IN_TOP_LEFT, 25, 5);
	lv_obj_set_event_cb(ddlist, MainDropList_event_handler);
}
static void MainDropList_event_handler(lv_obj_t * obj, lv_event_t event)
{
	if (event == LV_EVENT_VALUE_CHANGED) {
		char buf[20];
		lv_ddlist_get_selected_str(obj, buf, sizeof(buf));

		switch (PageController)
		{
		case 0: CalcPageDelete();
			break;
		case 1: formulaPageDelete();
			break;
		case 2: patchImagePageDelete();
			break;
		case 3: DeveloperPageDelete();
			break;
		default:
			break;
		}
		
		if (0 == strcmp("Calculator", buf)) {

			microstriptCalculatorCalcScreen();
			PageController = 0;
			lv_disp_load_scr(mCMainScreen);
		}
		else if (0 == strcmp("Formula", buf)) {
			microstriptCalculatorFormulaScreen();
			PageController = 1;
			lv_disp_load_scr(mCMainScreen);
		}
		else if (0 == strcmp("Images", buf)) {
	
			microstriptCalculatorImageScreen();
			PageController = 2;
			lv_disp_load_scr(mCMainScreen);
		}
		else if (0 == strcmp("Developer", buf)) {

			microstriptCalculatorDeveloperScreen();
			PageController = 3;
			lv_disp_load_scr(mCMainScreen);
			
		}
		MainDropList();
		
	}
}void MainDownListStyle(void) {



	lv_style_copy(&MainDownList_SbStyle, &lv_style_plain);
	lv_style_copy(&MainDownList_SelStyle, &lv_style_plain);
	lv_style_copy(&MainDownList_bgStyle, &lv_style_plain);


	MainDownList_SbStyle.body.main_color = lv_color_make(0, 191, 255);
	MainDownList_SbStyle.body.grad_color = lv_color_make(0, 191, 255);
	MainDownList_SbStyle.body.border.width = 0;
	MainDownList_SbStyle.body.padding.inner = 3;
	MainDownList_SbStyle.body.padding.left = 0;
	MainDownList_SbStyle.body.padding.right = 0;
	MainDownList_SbStyle.body.padding.top = 0;
	MainDownList_SbStyle.body.padding.bottom = 0;
	MainDownList_SbStyle.body.radius = 3;
	MainDownList_SbStyle.body.opa = LV_OPA_COVER;


	MainDownList_bgStyle.text.line_space = 3;
	MainDownList_bgStyle.body.padding.top = LV_DPI /8;
	MainDownList_bgStyle.body.padding.bottom = LV_DPI / 8;
	MainDownList_bgStyle.body.padding.left = LV_DPI /4;
	MainDownList_bgStyle.body.padding.right = LV_DPI / 4;
	MainDownList_bgStyle.body.radius = 5;



	MainDownList_SelStyle.body.main_color = lv_color_make(0, 191, 255);
	MainDownList_SelStyle.body.grad_color = lv_color_make(0, 191, 255);
	MainDownList_SelStyle.body.radius = 0;
	




}
