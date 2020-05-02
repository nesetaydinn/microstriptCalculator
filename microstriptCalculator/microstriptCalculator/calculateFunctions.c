/*
*calculateFunctions.c
*/
#include "calculateFunctions.h"

double frekans =0;
double dielektrikSabiti =0;
double yamaYukseklik =0;

double yamaGenisligi(void) {
	const double isikHizi = 3 * pow(10, 8);
	const double giga = pow(10, 9);
	return isikHizi / (2 * frekans*giga)*pow((dielektrikSabiti + 1) / 2, -0.5)*pow(10, 3);
}
double efektifDielektrikSabiti(void) {
	const double isikHizi = 3 * pow(10, 8);
	const double giga = pow(10, 9);
	return ((dielektrikSabiti + 1) / 2) + ((dielektrikSabiti - 1) / 2)*pow(1 + (12 * yamaYukseklik / yamaGenisligi()), -0.5);
}
double uzatmaUzunlugu(void) {
	const double isikHizi = 3 * pow(10, 8);
	const double giga = pow(10, 9);
	return  yamaYukseklik * 0.412*((efektifDielektrikSabiti() + 0.3)*((yamaGenisligi() / yamaYukseklik) + 0.264)) / ((efektifDielektrikSabiti() - 0.258)*((yamaGenisligi() / yamaYukseklik) + 0.8));
}
double efektifUzunluk(void) {
	const double isikHizi = 3 * pow(10, 8);
	const double giga = pow(10, 9);
	return isikHizi / (2 * frekans*giga*sqrt(efektifDielektrikSabiti()))*pow(10, 3);
}

double yamaUzunlugu(void) {
	const double isikHizi = 3 * pow(10, 8);
	const double giga = pow(10, 9);
	return efektifUzunluk() - (2 * uzatmaUzunlugu());
}
double dielektrikMalzemeUzunluk(void) {
	return 6 * yamaYukseklik + yamaUzunlugu();
}
double dielektrikMalzemeGenislik(void) {
	return 6 * yamaYukseklik + yamaGenisligi();
}

void variableGets(double *frekansGet, double *dielektrikSabitiGet, double *yamaYukseklikGet ) {
	frekans= *frekansGet;
	dielektrikSabiti= *dielektrikSabitiGet;
	yamaYukseklik= *yamaYukseklikGet;
	
}