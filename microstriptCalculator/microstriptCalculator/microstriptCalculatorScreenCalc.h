/*
*microstriptCalculatorScreencalc.h
*/
#ifndef MICROSTRIPTCALCULATORCALC_H
#define MICROSTRIPTCALCULATORCALC_H
#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

#ifdef LV_CONF_INCLUDE_SIMPLE
#include "lvgl.h"
#else
#include "../../lvgl/lvgl.h"
#endif

#include "stdio.h"
#include "math.h"
#include "string.h"
#include "calculateFunctions.h"

	void microstriptCalculatorCalcScreen(void);
	void CalcPageDelete(void);
#ifdef __cplusplus
}
#endif // __cplusplus

#endif // !MICROSTRIPTCALCULATORCALC_H
