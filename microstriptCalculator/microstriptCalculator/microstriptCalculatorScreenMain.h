/*
*microstriptCalculatorScreenMain.h
*/
#ifndef MICROSTRIPTCALCULATOR_H
#define MICROSTRIPTCALCULATOR_H
#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

#ifdef LV_CONF_INCLUDE_SIMPLE
#include "lvgl.h"
#else
#include "../../lvgl/lvgl.h"
#endif
#include "microstriptCalculatorScreenCalc.h"
#include "microstriptCalculatorScreenDeveloper.h"
#include "microstriptCalculatorScreenFormula.h"
#include "microstriptCalculatorScreenImages.h"

	void microstriptCalculatorMainScreen(void);

#ifdef __cplusplus
}
#endif // __cplusplus

#endif // !MICROSTRIPTCALCULATOR_H
