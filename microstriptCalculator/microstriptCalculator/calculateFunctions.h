/*
*calculateFunctions.h
*/
#ifndef CALCULATEFUNCTIONS_H
#define CALCULATEFUNCTIONS_H
#ifdef __cplusplus
extern "C" {
#endif // __cplusplus



#include "math.h"
#include "stdio.h"

	double yamaGenisligi(void);
	double yamaUzunlugu(void);
	double dielektrikMalzemeUzunluk(void);
	double dielektrikMalzemeGenislik(void);
	void variableGets(double *frekansGet, double *dielektrikSabitiGet, double *yamaYukseklikGet);



#ifdef __cplusplus
}
#endif // __cplusplus

#endif // !CALCULATEFUNCTIONS_H
