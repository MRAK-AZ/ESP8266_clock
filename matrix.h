#ifndef MATRIX_H
#define MATRIX_H

#include "GyverMAX7219.h"
#include "7x3Font0-9.h"
#include "mainSettings.h"

extern MAX7219< WM, HM, CSM, DATAM, CLKM > mtrx;  // инициализация MAX7219
void initMatrix();
void DisplayTime(uint8_t i, uint8_t y, bool fontF);

#endif
