/*
*microstriptCalculatorScreencalc.h
*/
#include "microstriptCalculatorScreencalc.h"

static lv_style_t tos_Calculator_NumberBtn_rel;
static lv_style_t tos_Calculator_NumberBtn_pr;
static lv_style_t tos_Calculator_NumberBtn_tgl_rel;
static lv_style_t tos_Calculator_NumberBtn_tgl_pr;
static lv_style_t tos_Calculator_NumberBtn_ina;
static lv_style_t clearButtonStyle_btn_rel;
static lv_style_t clearButtonStyle_btn_pr;



static lv_style_t frekansMCDisplayStyle, dielectricMCDisplayStyle, dielectricHMCDisplayStyle;

static lv_style_t CalculateDownList_SbStyle;
static lv_style_t CalculateDownList_SelStyle;
static lv_style_t CalculateDownList_bgStyle;

static lv_style_t McAL_scrollStyle4, McAL_SbStyle4, McAL_BgStyle4;

lv_obj_t *page4;
lv_obj_t *frekansDisplayLabel, * dielectricDisplayLabel, *dielectricHDisplayLabel;
lv_obj_t *lengthLabelFrameMCDisplay, *lengthLabel;
lv_obj_t *widthLabelFrameMCDisplay, *widthLabel;
lv_obj_t *dielectriclengthLabelFrameMCDisplay, *dielectriclengthLabel;
lv_obj_t *dielectricwidthLabelFrameMCDisplay, *dielectricwidthLabel;
lv_obj_t *frekansMCDisplay, *dielectricMCDisplay, *dielectricHMCDisplay;
char calculatorBuf[32];
double frequencyVariable, dielectricConstVariable, dielectricHVariable;

uint8_t dispSecici = 0;


void CalculateDownListStyle(void);
static void CalculateDropList_event_handler(lv_obj_t * obj, lv_event_t event);
static void tos_calculator_Numbers_event_handler(lv_obj_t * obj, lv_event_t event);
static void clearButton_event_handler(lv_obj_t * obj, lv_event_t event);

void tos_calculatorNumbers(void);
void tos_calculatorNumbersStyle(void);
void CalcPage(void);
void CalcPageStyles(void);
void frekansDisplay(void);
void dielectricConstDisplay(void);
void dielectricHDisplay(void);
void CalculateDropList(void);
void LengthDisplay(void);
void WidthDisplay(void);
void dielectricLengthDisplay(void);
void dielectricWidthDisplay(void);
void clearButton(void);
void clearButtonStyle(void);

void microstriptCalculatorCalcScreen(void) {
	CalcPage();
}

void CalcPage(void)
{
	CalcPageStyles();
	page4 = lv_page_create(lv_scr_act(), NULL);
	lv_obj_set_size(page4, 440, 260);
	lv_obj_align(page4, NULL, LV_ALIGN_CENTER, 0, 0);
	lv_page_set_style(page4, LV_PAGE_STYLE_SCRL, &McAL_scrollStyle4);
	lv_page_set_style(page4, LV_PAGE_STYLE_SB, &McAL_scrollStyle4);
	lv_page_set_style(page4, LV_PAGE_STYLE_BG, &McAL_BgStyle4);

	tos_calculatorNumbers();
	frekansDisplay();
	dielectricConstDisplay();
	dielectricHDisplay();
	CalculateDropList();
	LengthDisplay();
	WidthDisplay();
	dielectricLengthDisplay();
	dielectricWidthDisplay();
	clearButton();
}
void CalcPageDelete(void) {
	lv_obj_clean(page4);
}


void clearButton(void) {
	clearButtonStyle();
	lv_obj_t * applyBtn = lv_btn_create(page4, NULL);
	lv_obj_align(applyBtn, NULL, LV_ALIGN_IN_TOP_LEFT, 160, 15);
	lv_obj_set_size(applyBtn, 42, 25);
	lv_obj_set_event_cb(applyBtn, clearButton_event_handler);

	lv_btn_set_style(applyBtn, LV_BTN_STYLE_REL, &clearButtonStyle_btn_rel);
	lv_btn_set_style(applyBtn, LV_BTN_STYLE_PR, &clearButtonStyle_btn_pr);

	lv_obj_t * applyLabel = lv_label_create(applyBtn, NULL);
	lv_label_set_text(applyLabel, "Clear");
}

void tos_calculatorNumbers(void) {

	static const char * number_BtnMap[16] = { "9", "8", "7", "\n",
									   "6", "5", "4", "\n",
									   "3", "2", "1", "\n",
									   "0", ".", "ok", "" };

	lv_obj_t * number_Btns = lv_btnm_create(page4, NULL);
	lv_btnm_set_map(number_Btns, number_BtnMap);

	lv_obj_set_size(number_Btns, 180, 160);
	lv_obj_align(number_Btns, NULL, LV_ALIGN_IN_TOP_LEFT, 10, 55);
	lv_obj_set_event_cb(number_Btns, tos_calculator_Numbers_event_handler);

	tos_calculatorNumbersStyle();
	lv_btnm_set_style(number_Btns, LV_BTNM_STYLE_BTN_REL, &tos_Calculator_NumberBtn_rel);
	lv_btnm_set_style(number_Btns, LV_BTNM_STYLE_BTN_PR, &tos_Calculator_NumberBtn_pr);
	lv_btnm_set_style(number_Btns, LV_BTNM_STYLE_BTN_TGL_REL, &tos_Calculator_NumberBtn_tgl_rel);
	lv_btnm_set_style(number_Btns, LV_BTNM_STYLE_BTN_TGL_PR, &tos_Calculator_NumberBtn_tgl_pr);
	lv_btnm_set_style(number_Btns, LV_BTNM_STYLE_BTN_INA, &tos_Calculator_NumberBtn_ina);

}
void frekansDisplay(void) {
	lv_style_copy(&frekansMCDisplayStyle, &lv_style_plain);
	frekansMCDisplayStyle.body.main_color = lv_color_hex3(0xeee);
	frekansMCDisplayStyle.body.grad_color = lv_color_hex3(0xeee);
	frekansMCDisplayStyle.body.opa = 190;
	frekansMCDisplayStyle.body.radius = 12;
	frekansMCDisplayStyle.text.color = LV_COLOR_BLACK;


	CalcPageStyles();
	lv_obj_t * frekansyaziMCDisplay = lv_label_create(page4, NULL);
	lv_label_set_text(frekansyaziMCDisplay, "freq(Ghz)");
	lv_obj_align(frekansyaziMCDisplay, NULL, LV_ALIGN_IN_TOP_RIGHT, -125,15);
	lv_obj_set_style(frekansyaziMCDisplay, &McAL_BgStyle4);

	frekansMCDisplay = lv_cont_create(page4, NULL);
	lv_obj_set_width(frekansMCDisplay, 100);
	lv_obj_set_height(frekansMCDisplay, 20);
	lv_obj_align(frekansMCDisplay, NULL, LV_ALIGN_IN_TOP_RIGHT, -10, 15);
	lv_obj_set_style(frekansMCDisplay, &frekansMCDisplayStyle);


	frekansDisplayLabel = lv_label_create(frekansMCDisplay, NULL);
	lv_label_set_text(frekansDisplayLabel, "0");
	lv_obj_align(frekansDisplayLabel, NULL, LV_ALIGN_IN_RIGHT_MID, -(LV_DPI / 10), 0);
	
}
void dielectricConstDisplay(void) {

	

	lv_style_copy(&dielectricMCDisplayStyle, &lv_style_plain);
	dielectricMCDisplayStyle.body.main_color = lv_color_hex3(0xeee);
	dielectricMCDisplayStyle.body.grad_color = lv_color_hex3(0xeee);
	dielectricMCDisplayStyle.body.opa = 190;
	dielectricMCDisplayStyle.body.radius = 12;
	dielectricMCDisplayStyle.text.color = LV_COLOR_BLACK;

	CalcPageStyles();
	lv_obj_t * frekansyaziMCDisplay = lv_label_create(page4, NULL);
	lv_label_set_text(frekansyaziMCDisplay, "Dielec. const");
	lv_obj_align(frekansyaziMCDisplay, NULL, LV_ALIGN_IN_TOP_RIGHT, -125, 45);
	lv_obj_set_style(frekansyaziMCDisplay, &McAL_BgStyle4);


	dielectricMCDisplay = lv_cont_create(page4, NULL);
	lv_obj_set_width(dielectricMCDisplay, 100);
	lv_obj_set_height(dielectricMCDisplay, 20);
	lv_obj_align(dielectricMCDisplay, NULL, LV_ALIGN_IN_TOP_RIGHT, -10, 45);
	lv_obj_set_style(dielectricMCDisplay, &dielectricMCDisplayStyle);

	dielectricDisplayLabel = lv_label_create(dielectricMCDisplay, NULL);
	lv_label_set_text(dielectricDisplayLabel, "0");
	lv_obj_align(dielectricDisplayLabel, NULL, LV_ALIGN_IN_RIGHT_MID, -(LV_DPI / 10), 0);
}
void dielectricHDisplay(void) {

	lv_style_copy(&dielectricHMCDisplayStyle, &lv_style_plain);
	dielectricHMCDisplayStyle.body.main_color = lv_color_hex3(0xeee);
	dielectricHMCDisplayStyle.body.grad_color = lv_color_hex3(0xeee);
	dielectricHMCDisplayStyle.body.opa = 190;
	dielectricHMCDisplayStyle.body.radius = 12;
	dielectricHMCDisplayStyle.text.color = LV_COLOR_BLACK;

	CalcPageStyles();
	lv_obj_t * frekansyaziMCDisplay = lv_label_create(page4, NULL);
	lv_label_set_text(frekansyaziMCDisplay, " Dielec. h(mm)");
	lv_obj_align(frekansyaziMCDisplay, NULL, LV_ALIGN_IN_TOP_RIGHT, -125, 75);
	lv_obj_set_style(frekansyaziMCDisplay, &McAL_BgStyle4);

	dielectricHMCDisplay = lv_cont_create(page4, NULL);
	lv_obj_set_width(dielectricHMCDisplay, 100);
	lv_obj_set_height(dielectricHMCDisplay, 20);
	lv_obj_align(dielectricHMCDisplay, NULL, LV_ALIGN_IN_TOP_RIGHT, -10, 75);
	lv_obj_set_style(dielectricHMCDisplay, &dielectricHMCDisplayStyle);

	dielectricHDisplayLabel = lv_label_create(dielectricHMCDisplay, NULL);
	lv_label_set_text(dielectricHDisplayLabel, "0");
	lv_obj_align(dielectricHDisplayLabel, NULL, LV_ALIGN_IN_RIGHT_MID, -(LV_DPI / 10), 0);
}

void LengthDisplay(void) {
	static lv_style_t LengthDisplayCDisplayStyle;
	lv_style_copy(&LengthDisplayCDisplayStyle, &lv_style_plain);
	LengthDisplayCDisplayStyle.body.main_color = lv_color_hex3(0xeee);
	LengthDisplayCDisplayStyle.body.grad_color = lv_color_hex3(0xeee);
	LengthDisplayCDisplayStyle.body.opa = 190;
	LengthDisplayCDisplayStyle.body.radius = 12;
	LengthDisplayCDisplayStyle.text.color = LV_COLOR_BLACK;
	LengthDisplayCDisplayStyle.text.font = &lv_font_roboto_12;
	

	CalcPageStyles();
	lv_obj_t * lengthLabelTittleMCDisplay = lv_label_create(page4, NULL);
	lv_label_set_text(lengthLabelTittleMCDisplay, " Patch L(m.m.)");
	lv_obj_align(lengthLabelTittleMCDisplay, NULL, LV_ALIGN_IN_TOP_RIGHT, -125, 105);
	lv_obj_set_style(lengthLabelTittleMCDisplay, &McAL_BgStyle4);

	lengthLabelFrameMCDisplay = lv_cont_create(page4, NULL);
	lv_obj_set_width(lengthLabelFrameMCDisplay, 100);
	lv_obj_set_height(lengthLabelFrameMCDisplay, 20);
	lv_obj_align(lengthLabelFrameMCDisplay, NULL, LV_ALIGN_IN_TOP_RIGHT, -10, 105);
	lv_obj_set_style(lengthLabelFrameMCDisplay, &dielectricHMCDisplayStyle);

	lengthLabel = lv_label_create(lengthLabelFrameMCDisplay, NULL);
	lv_label_set_text(lengthLabel, "");
	lv_obj_align(lengthLabel, NULL, LV_ALIGN_IN_RIGHT_MID, -(LV_DPI / 10), 0);
}

void WidthDisplay(void) {
	static lv_style_t LengthDisplayCDisplayStyle;
	lv_style_copy(&LengthDisplayCDisplayStyle, &lv_style_plain);
	LengthDisplayCDisplayStyle.body.main_color = lv_color_hex3(0xeee);
	LengthDisplayCDisplayStyle.body.grad_color = lv_color_hex3(0xeee);
	LengthDisplayCDisplayStyle.body.opa = 190;
	LengthDisplayCDisplayStyle.body.radius = 12;
	LengthDisplayCDisplayStyle.text.color = LV_COLOR_BLACK;
	LengthDisplayCDisplayStyle.text.font = &lv_font_roboto_12;

	CalcPageStyles();
	lv_obj_t * lengthLabelTittleMCDisplay = lv_label_create(page4, NULL);
	lv_label_set_text(lengthLabelTittleMCDisplay, "Patch w(m.m.)");
	lv_obj_align(lengthLabelTittleMCDisplay, NULL, LV_ALIGN_IN_TOP_RIGHT, -125, 135);
	lv_obj_set_style(lengthLabelTittleMCDisplay, &McAL_BgStyle4);

	widthLabelFrameMCDisplay = lv_cont_create(page4, NULL);
	lv_obj_set_width(widthLabelFrameMCDisplay, 100);
	lv_obj_set_height(widthLabelFrameMCDisplay, 20);
	lv_obj_align(widthLabelFrameMCDisplay, NULL, LV_ALIGN_IN_TOP_RIGHT, -10, 135);
	lv_obj_set_style(widthLabelFrameMCDisplay, &dielectricHMCDisplayStyle);

	widthLabel = lv_label_create(widthLabelFrameMCDisplay, NULL);
	lv_label_set_text(widthLabel, "");
	lv_obj_align(widthLabel, NULL, LV_ALIGN_IN_RIGHT_MID, -(LV_DPI / 10), 0);
}

void dielectricLengthDisplay(void) {
	static lv_style_t LengthDisplayCDisplayStyle;
	lv_style_copy(&LengthDisplayCDisplayStyle, &lv_style_plain);
	LengthDisplayCDisplayStyle.body.main_color = lv_color_hex3(0xeee);
	LengthDisplayCDisplayStyle.body.grad_color = lv_color_hex3(0xeee);
	LengthDisplayCDisplayStyle.body.opa = 190;
	LengthDisplayCDisplayStyle.body.radius = 12;
	LengthDisplayCDisplayStyle.text.color = LV_COLOR_BLACK;
	LengthDisplayCDisplayStyle.text.font = &lv_font_roboto_12;

	CalcPageStyles();
	lv_obj_t * lengthLabelTittleMCDisplay = lv_label_create(page4, NULL);
	lv_label_set_text(lengthLabelTittleMCDisplay, "Dielec. L(mm)");
	lv_obj_align(lengthLabelTittleMCDisplay, NULL, LV_ALIGN_IN_TOP_RIGHT, -125, 165);
	lv_obj_set_style(lengthLabelTittleMCDisplay, &McAL_BgStyle4);

	dielectriclengthLabelFrameMCDisplay = lv_cont_create(page4, NULL);
	lv_obj_set_width(dielectriclengthLabelFrameMCDisplay, 100);
	lv_obj_set_height(dielectriclengthLabelFrameMCDisplay, 20);
	lv_obj_align(dielectriclengthLabelFrameMCDisplay, NULL, LV_ALIGN_IN_TOP_RIGHT, -10, 165);
	lv_obj_set_style(dielectriclengthLabelFrameMCDisplay, &dielectricHMCDisplayStyle);

	dielectriclengthLabel = lv_label_create(dielectriclengthLabelFrameMCDisplay, NULL);
	lv_label_set_text(dielectriclengthLabel, "");
	lv_obj_align(dielectriclengthLabel, NULL, LV_ALIGN_IN_RIGHT_MID, -(LV_DPI / 10), 0);
}

void dielectricWidthDisplay(void) {
	static lv_style_t LengthDisplayCDisplayStyle;
	lv_style_copy(&LengthDisplayCDisplayStyle, &lv_style_plain);
	LengthDisplayCDisplayStyle.body.main_color = lv_color_hex3(0xeee);
	LengthDisplayCDisplayStyle.body.grad_color = lv_color_hex3(0xeee);
	LengthDisplayCDisplayStyle.body.opa = 190;
	LengthDisplayCDisplayStyle.body.radius = 12;
	LengthDisplayCDisplayStyle.text.color = LV_COLOR_BLACK;
	LengthDisplayCDisplayStyle.text.font = &lv_font_roboto_12;

	CalcPageStyles();
	lv_obj_t * lengthLabelTittleMCDisplay = lv_label_create(page4, NULL);
	lv_label_set_text(lengthLabelTittleMCDisplay, " Dielec. w(mm)");
	lv_obj_align(lengthLabelTittleMCDisplay, NULL, LV_ALIGN_IN_TOP_RIGHT, -125, 195);
	lv_obj_set_style(lengthLabelTittleMCDisplay, &McAL_BgStyle4);

	dielectricwidthLabelFrameMCDisplay = lv_cont_create(page4, NULL);
	lv_obj_set_width(dielectricwidthLabelFrameMCDisplay, 100);
	lv_obj_set_height(dielectricwidthLabelFrameMCDisplay, 20);
	lv_obj_align(dielectricwidthLabelFrameMCDisplay, NULL, LV_ALIGN_IN_TOP_RIGHT, -10, 195);
	lv_obj_set_style(dielectricwidthLabelFrameMCDisplay, &dielectricHMCDisplayStyle);

	dielectricwidthLabel = lv_label_create(dielectricwidthLabelFrameMCDisplay, NULL);
	lv_label_set_text(dielectricwidthLabel, "");
	lv_obj_align(dielectricwidthLabel, NULL, LV_ALIGN_IN_RIGHT_MID, -(LV_DPI / 10), 0);
}

void CalculateDropList(void) {
	CalculateDownListStyle();
	lv_obj_t * ddlist = lv_ddlist_create(page4, NULL);
	lv_ddlist_set_options(ddlist, "Frequency\n"
		"Dielectric Const\n"
		"Dielectric h");
	lv_ddlist_set_draw_arrow(ddlist, true);
	lv_ddlist_set_style(ddlist, LV_DDLIST_STYLE_SB, &CalculateDownList_SbStyle);
	lv_ddlist_set_style(ddlist, LV_DDLIST_STYLE_BG, &CalculateDownList_bgStyle);
	lv_ddlist_set_style(ddlist, LV_DDLIST_STYLE_SEL, &CalculateDownList_SelStyle);
	lv_obj_set_size(ddlist, 180, 25);
	lv_obj_align(ddlist, NULL, LV_ALIGN_IN_TOP_LEFT, 15, 15);
	lv_obj_set_event_cb(ddlist, CalculateDropList_event_handler);
}


static void tos_calculator_Numbers_event_handler(lv_obj_t * obj, lv_event_t event)
{
	if (event == LV_EVENT_VALUE_CHANGED) {

		if (dispSecici == 0) {
			
			static const char * number_BtnMapValues[10] = { "9", "8", "7",
															"6", "5", "4",
															"3", "2", "1",
															"0" };

			for (uint8_t sayac = 0; sayac < 10; sayac++) {
				if (0 == strcmp(number_BtnMapValues[sayac], lv_btnm_get_active_btn_text(obj))) {
					if (lv_obj_get_screen(frekansDisplayLabel) == lv_scr_act()) {
						if (0 == strcmp("0", lv_label_get_text(frekansDisplayLabel))) {
							snprintf(calculatorBuf, 32, "%s", lv_btnm_get_active_btn_text(obj));
						}
						else {
							snprintf(calculatorBuf, 32, "%s%s",
								lv_label_get_text(frekansDisplayLabel), lv_btnm_get_active_btn_text(obj));
						}

						lv_label_set_text(frekansDisplayLabel, calculatorBuf);
						lv_obj_align(frekansDisplayLabel, NULL, LV_ALIGN_IN_RIGHT_MID, -(LV_DPI / 10) + 3, 0);
					}


				}

			}
			if (0 == strcmp(".", lv_btnm_get_active_btn_text(obj))) {
				if (0 == strstr(lv_label_get_text(frekansDisplayLabel), ".")) {
					snprintf(calculatorBuf, 32, "%s%s",
						lv_label_get_text(frekansDisplayLabel), lv_btnm_get_active_btn_text(obj));
					lv_label_set_text(frekansDisplayLabel, calculatorBuf);


					lv_obj_align(frekansDisplayLabel, NULL, LV_ALIGN_IN_RIGHT_MID, -(LV_DPI / 10) + 3, 0);
				}
			}
			frequencyVariable = atof(lv_label_get_text(frekansDisplayLabel));
		}
		else if (dispSecici == 1) {
		
			
			static const char * number_BtnMapValues[10] = { "9", "8", "7",
															"6", "5", "4",
															"3", "2", "1",
															"0" };


			for (uint8_t sayac = 0; sayac < 10; sayac++) {
				if (0 == strcmp(number_BtnMapValues[sayac], lv_btnm_get_active_btn_text(obj))) {
					if (lv_obj_get_screen(dielectricDisplayLabel) == lv_scr_act()) {
						if (0 == strcmp("0", lv_label_get_text(dielectricDisplayLabel))) {
							snprintf(calculatorBuf, 32, "%s", lv_btnm_get_active_btn_text(obj));
						}
						else {
							snprintf(calculatorBuf, 32, "%s%s",
								lv_label_get_text(dielectricDisplayLabel), lv_btnm_get_active_btn_text(obj));
						}

						lv_label_set_text(dielectricDisplayLabel, calculatorBuf);
						lv_obj_align(dielectricDisplayLabel, NULL, LV_ALIGN_IN_RIGHT_MID, -(LV_DPI / 10) + 3, 0);
					}


				}

			}
			if (0 == strcmp(".", lv_btnm_get_active_btn_text(obj))) {
				if (0 == strstr(lv_label_get_text(dielectricDisplayLabel), ".")) {
					snprintf(calculatorBuf, 32, "%s%s",
						lv_label_get_text(dielectricDisplayLabel), lv_btnm_get_active_btn_text(obj));
					lv_label_set_text(dielectricDisplayLabel, calculatorBuf);
					lv_obj_align(dielectricDisplayLabel, NULL, LV_ALIGN_IN_RIGHT_MID, -(LV_DPI / 10) + 3, 0);
				}
			}
			dielectricConstVariable = atof(lv_label_get_text(dielectricDisplayLabel));
		}
		else if (dispSecici == 2) {
			
			static const char * number_BtnMapValues[10] = { "9", "8", "7",
															"6", "5", "4",
															"3", "2", "1",
															"0" };


			for (uint8_t sayac = 0; sayac < 10; sayac++) {
				if (0 == strcmp(number_BtnMapValues[sayac], lv_btnm_get_active_btn_text(obj))) {
					if (lv_obj_get_screen(dielectricHDisplayLabel) == lv_scr_act()) {
						if (0 == strcmp("0", lv_label_get_text(dielectricHDisplayLabel))) {
							snprintf(calculatorBuf, 32, "%s", lv_btnm_get_active_btn_text(obj));
						}
						else {
							snprintf(calculatorBuf, 32, "%s%s",
								lv_label_get_text(dielectricHDisplayLabel), lv_btnm_get_active_btn_text(obj));
						}

						lv_label_set_text(dielectricHDisplayLabel, calculatorBuf);
						lv_obj_align(dielectricHDisplayLabel, NULL, LV_ALIGN_IN_RIGHT_MID, -(LV_DPI / 10) + 3, 0);
					}


				}

			}
			if (0 == strcmp(".", lv_btnm_get_active_btn_text(obj))) {
				if (0 == strstr(lv_label_get_text(dielectricDisplayLabel), ".")) {
					snprintf(calculatorBuf, 32, "%s%s",
						lv_label_get_text(dielectricDisplayLabel), lv_btnm_get_active_btn_text(obj));
					lv_label_set_text(dielectricDisplayLabel, calculatorBuf);
					lv_obj_align(dielectricDisplayLabel, NULL, LV_ALIGN_IN_RIGHT_MID, -(LV_DPI / 10) + 3, 0);
				}
			}
			dielectricHVariable = atof(lv_label_get_text(dielectricHDisplayLabel));
		}

		
		 if (0 == strcmp("ok", lv_btnm_get_active_btn_text(obj))) {	

				variableGets(&frequencyVariable, &dielectricConstVariable, &dielectricHVariable);

				snprintf(calculatorBuf, 32, "%lf", yamaGenisligi());
				lv_label_set_text(widthLabel, calculatorBuf);
				lv_obj_align(widthLabel, NULL, LV_ALIGN_IN_RIGHT_MID, -(LV_DPI / 10) + 3, 0);

				snprintf(calculatorBuf, 32, "%lf", yamaUzunlugu());
				lv_label_set_text(lengthLabel, calculatorBuf);
				lv_obj_align(lengthLabel, NULL, LV_ALIGN_IN_RIGHT_MID, -(LV_DPI / 10) + 3, 0);

				snprintf(calculatorBuf, 32, "%lf", dielektrikMalzemeUzunluk());
				lv_label_set_text(dielectriclengthLabel, calculatorBuf);
				lv_obj_align(dielectriclengthLabel, NULL, LV_ALIGN_IN_RIGHT_MID, -(LV_DPI / 10) + 3, 0);


				snprintf(calculatorBuf, 32, "%lf", dielektrikMalzemeGenislik());
				lv_label_set_text(dielectricwidthLabel, calculatorBuf);
				lv_obj_align(dielectricwidthLabel, NULL, LV_ALIGN_IN_RIGHT_MID, -(LV_DPI / 10) + 3, 0);

		}
	}
}
static void CalculateDropList_event_handler(lv_obj_t * obj, lv_event_t event)
{
	if (event == LV_EVENT_VALUE_CHANGED) {
		char buf[20];
		lv_ddlist_get_selected_str(obj, buf, sizeof(buf));
		if (0 == strcmp("Frequency", buf)) {
			dispSecici = 0;
		}
		else if (0 == strcmp("Dielectric Const", buf)) {
			dispSecici = 1;
		}
		else if (0 == strcmp("Dielectric h", buf)) {
			
			dispSecici = 2;
		}
	}
}

static void clearButton_event_handler(lv_obj_t * obj, lv_event_t event) {
	if (event == LV_EVENT_CLICKED) {
		if (0 == strcmp("Clear", lv_list_get_btn_text(obj))) {

			snprintf(calculatorBuf, 32, "0");
			lv_label_set_text(frekansDisplayLabel, calculatorBuf);
			lv_obj_align(frekansDisplayLabel, NULL, LV_ALIGN_IN_RIGHT_MID, -(LV_DPI / 10) + 3, 0);

			snprintf(calculatorBuf, 32, "0");
			lv_label_set_text(dielectricDisplayLabel, calculatorBuf);
			lv_obj_align(dielectricDisplayLabel, NULL, LV_ALIGN_IN_RIGHT_MID, -(LV_DPI / 10) + 3, 0);

			snprintf(calculatorBuf, 32, "0");
			lv_label_set_text(dielectricHDisplayLabel, calculatorBuf);
			lv_obj_align(dielectricHDisplayLabel, NULL, LV_ALIGN_IN_RIGHT_MID, -(LV_DPI / 10) + 3, 0);

			snprintf(calculatorBuf, 32, "");
			lv_label_set_text(widthLabel, calculatorBuf);
			lv_obj_align(widthLabel, NULL, LV_ALIGN_IN_RIGHT_MID, -(LV_DPI / 10) + 3, 0);

			snprintf(calculatorBuf, 32, "");
			lv_label_set_text(lengthLabel, calculatorBuf);
			lv_obj_align(lengthLabel, NULL, LV_ALIGN_IN_RIGHT_MID, -(LV_DPI / 10) + 3, 0);

			snprintf(calculatorBuf, 32, "");
			lv_label_set_text(dielectriclengthLabel, calculatorBuf);
			lv_obj_align(dielectriclengthLabel, NULL, LV_ALIGN_IN_RIGHT_MID, -(LV_DPI / 10) + 3, 0);


			snprintf(calculatorBuf, 32, "");
			lv_label_set_text(dielectricwidthLabel, calculatorBuf);
			lv_obj_align(dielectricwidthLabel, NULL, LV_ALIGN_IN_RIGHT_MID, -(LV_DPI / 10) + 3, 0);


			frequencyVariable = 0;
			dielectricConstVariable = 0;
			dielectricHVariable = 0;
			dispSecici = 0;
		}
	}
}

void CalcPageStyles(void) {

	lv_style_copy(&McAL_scrollStyle4, &lv_style_plain);
	McAL_scrollStyle4.body.main_color = lv_color_hsv_to_rgb(0, 11, 18);
	McAL_scrollStyle4.body.grad_color = lv_color_hsv_to_rgb(0, 11, 18);
	McAL_scrollStyle4.body.border.color = lv_color_hex3(0x333);
	McAL_scrollStyle4.body.border.width = 1;
	McAL_scrollStyle4.body.radius = 10;

	lv_style_copy(&McAL_SbStyle4, &lv_style_plain);
	McAL_SbStyle4.body.main_color = lv_color_make(0, 191, 255);
	McAL_SbStyle4.body.grad_color = lv_color_make(0, 191, 255);
	McAL_SbStyle4.body.border.width = 0;
	McAL_SbStyle4.body.padding.inner = 3;
	McAL_SbStyle4.body.padding.left = 0;
	McAL_SbStyle4.body.padding.right = 0;
	McAL_SbStyle4.body.padding.top = 0;
	McAL_SbStyle4.body.padding.bottom = 0;
	McAL_SbStyle4.body.radius = LV_DPI / 30;
	McAL_SbStyle4.body.opa = LV_OPA_COVER;

	lv_style_copy(&McAL_BgStyle4, &lv_style_plain);
	McAL_BgStyle4.body.opa = LV_OPA_COVER;
	McAL_BgStyle4.glass = 0;
	McAL_BgStyle4.body.radius = 0;
	McAL_BgStyle4.body.padding.left = LV_DPI / 8;
	McAL_BgStyle4.body.padding.right = LV_DPI / 8;
	McAL_BgStyle4.body.padding.top = LV_DPI / 8;
	McAL_BgStyle4.body.padding.bottom = LV_DPI / 8;
	McAL_BgStyle4.body.padding.inner = LV_DPI / 8;
	McAL_BgStyle4.text.letter_space = 1;
	McAL_BgStyle4.text.line_space = 2;
	McAL_BgStyle4.image.color = lv_color_make(255, 248, 220);
	McAL_BgStyle4.image.intense = LV_OPA_TRANSP;
	McAL_BgStyle4.line.color = lv_color_make(255, 248, 220);
	McAL_BgStyle4.line.width = 1;
	McAL_BgStyle4.body.radius = LV_DPI / 10;
	McAL_BgStyle4.body.main_color = lv_color_make(255, 248, 220);
	McAL_BgStyle4.body.grad_color = lv_color_make(255, 248, 220);
	McAL_BgStyle4.body.border.color = lv_color_make(255, 248, 220);
	McAL_BgStyle4.body.border.width = 2;
	McAL_BgStyle4.body.border.opa = LV_OPA_60;
	McAL_BgStyle4.text.color = lv_color_make(255, 255, 255);
	McAL_BgStyle4.line.color = lv_color_make(255, 248, 220);
}

void tos_calculatorNumbersStyle(void) {



							lv_style_copy(&tos_Calculator_NumberBtn_rel, &lv_style_plain);
							tos_Calculator_NumberBtn_rel.body.main_color = lv_color_hsv_to_rgb(0, 10, 40);
							tos_Calculator_NumberBtn_rel.body.grad_color = lv_color_hsv_to_rgb(0, 10, 20);
							tos_Calculator_NumberBtn_rel.body.border.color = lv_color_hex3(0x111);
							tos_Calculator_NumberBtn_rel.body.border.width = 1;
							tos_Calculator_NumberBtn_rel.body.border.opa = LV_OPA_70;
							tos_Calculator_NumberBtn_rel.body.padding.left = LV_DPI / 4;
							tos_Calculator_NumberBtn_rel.body.padding.right = LV_DPI / 4;
							tos_Calculator_NumberBtn_rel.body.padding.top = LV_DPI / 8;
							tos_Calculator_NumberBtn_rel.body.padding.bottom = LV_DPI / 8;
							tos_Calculator_NumberBtn_rel.body.shadow.type = LV_SHADOW_BOTTOM;
							tos_Calculator_NumberBtn_rel.body.shadow.color = lv_color_hex3(0x111);
							tos_Calculator_NumberBtn_rel.body.shadow.width = LV_DPI / 30;
							tos_Calculator_NumberBtn_rel.text.color = lv_color_hex3(0xeee);
							tos_Calculator_NumberBtn_rel.image.color = lv_color_hex3(0xeee);

							lv_style_copy(&tos_Calculator_NumberBtn_pr, &tos_Calculator_NumberBtn_rel);
							tos_Calculator_NumberBtn_pr.body.main_color = lv_color_hsv_to_rgb(0, 10, 30);
							tos_Calculator_NumberBtn_pr.body.grad_color = lv_color_hsv_to_rgb(0, 10, 10);

							lv_style_copy(&tos_Calculator_NumberBtn_tgl_rel, &tos_Calculator_NumberBtn_rel);
							tos_Calculator_NumberBtn_tgl_rel.body.main_color = lv_color_hsv_to_rgb(0, 10, 20);
							tos_Calculator_NumberBtn_tgl_rel.body.grad_color = lv_color_hsv_to_rgb(0, 10, 40);
							tos_Calculator_NumberBtn_tgl_rel.body.shadow.width = LV_DPI / 40;
							tos_Calculator_NumberBtn_tgl_rel.text.color = lv_color_hex3(0xddd);
							tos_Calculator_NumberBtn_tgl_rel.image.color = lv_color_hex3(0xddd);

							lv_style_copy(&tos_Calculator_NumberBtn_tgl_pr, &tos_Calculator_NumberBtn_rel);
							tos_Calculator_NumberBtn_tgl_pr.body.main_color = lv_color_hsv_to_rgb(0, 10, 10);
							tos_Calculator_NumberBtn_tgl_pr.body.grad_color = lv_color_hsv_to_rgb(0, 10, 30);
							tos_Calculator_NumberBtn_tgl_pr.body.shadow.width = LV_DPI / 30;
							tos_Calculator_NumberBtn_tgl_pr.text.color = lv_color_hex3(0xddd);
							tos_Calculator_NumberBtn_tgl_pr.image.color = lv_color_hex3(0xddd);

							lv_style_copy(&tos_Calculator_NumberBtn_ina, &tos_Calculator_NumberBtn_rel);
							tos_Calculator_NumberBtn_ina.body.main_color = lv_color_hsv_to_rgb(0, 10, 20);
							tos_Calculator_NumberBtn_ina.body.grad_color = lv_color_hsv_to_rgb(0, 10, 20);
							tos_Calculator_NumberBtn_ina.body.shadow.width = 0;
							tos_Calculator_NumberBtn_ina.text.color = lv_color_hex3(0xaaa);
							tos_Calculator_NumberBtn_ina.image.color = lv_color_hex3(0xaaa);


						}

void CalculateDownListStyle(void) {



	lv_style_copy(&CalculateDownList_SbStyle, &lv_style_plain);
	lv_style_copy(&CalculateDownList_SelStyle, &lv_style_plain);
	lv_style_copy(&CalculateDownList_bgStyle, &lv_style_plain);


	CalculateDownList_SbStyle.body.main_color = lv_color_make(0, 191, 255);
	CalculateDownList_SbStyle.body.grad_color = lv_color_make(0, 191, 255);
	CalculateDownList_SbStyle.body.border.width = 0;
	CalculateDownList_SbStyle.body.padding.inner = 3;
	CalculateDownList_SbStyle.body.padding.left = 0;
	CalculateDownList_SbStyle.body.padding.right = 0;
	CalculateDownList_SbStyle.body.padding.top = 0;
	CalculateDownList_SbStyle.body.padding.bottom = 0;
	CalculateDownList_SbStyle.body.radius = 3;
	CalculateDownList_SbStyle.body.opa = LV_OPA_COVER;

	CalculateDownList_bgStyle.text.line_space = 3;
	CalculateDownList_bgStyle.body.padding.top = LV_DPI / 8;
	CalculateDownList_bgStyle.body.padding.bottom = LV_DPI / 8;
	CalculateDownList_bgStyle.body.padding.left = LV_DPI / 8;
	CalculateDownList_bgStyle.body.padding.right = LV_DPI / 8;
	CalculateDownList_bgStyle.body.radius = 3;

	CalculateDownList_SelStyle.body.main_color = lv_color_make(0, 191, 255);
	CalculateDownList_SelStyle.body.grad_color = lv_color_make(0, 191, 255);
	CalculateDownList_SelStyle.body.radius = 0;


}

void clearButtonStyle(void) {

	lv_style_copy(&clearButtonStyle_btn_rel, &lv_style_plain);
	clearButtonStyle_btn_rel.body.border.color = lv_color_hex3(0x00bfff);
	clearButtonStyle_btn_rel.body.border.width = 1;
	clearButtonStyle_btn_rel.body.main_color = lv_color_make(255, 248, 220);
	clearButtonStyle_btn_rel.body.grad_color = lv_color_make(255, 248, 220);
	clearButtonStyle_btn_rel.body.shadow.width = 4;
	clearButtonStyle_btn_rel.body.shadow.type = LV_SHADOW_BOTTOM;
	clearButtonStyle_btn_rel.body.radius = LV_RADIUS_CIRCLE;
	clearButtonStyle_btn_rel.text.font = &lv_font_roboto_16;
	clearButtonStyle_btn_rel.text.color = lv_color_hsv_to_rgb(0, 11, 18);


	lv_style_copy(&clearButtonStyle_btn_pr, &clearButtonStyle_btn_rel);
	clearButtonStyle_btn_pr.body.border.color = lv_color_hex3(0x00bfff);
	clearButtonStyle_btn_pr.body.main_color = lv_color_hsv_to_rgb(0, 11, 18);
	clearButtonStyle_btn_pr.body.grad_color = lv_color_hsv_to_rgb(0, 11, 18);
	clearButtonStyle_btn_pr.body.shadow.width = 2;
	clearButtonStyle_btn_pr.text.font = &lv_font_roboto_16;
	clearButtonStyle_btn_pr.text.color = lv_color_make(255, 248, 220);
}