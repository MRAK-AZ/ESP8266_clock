#include "matrix.h"

MAX7219< WM, HM, CSM, DATAM, CLKM > mtrx;  // инициализация MAX7219

void initMatrix() {
  mtrx.begin();
  mtrx.setType(GM_SERIES);
}


void DisplayTime(uint8_t i, uint8_t y, bool fontF) {
  mtrx.drawBitmap(0, y, fontF ? x7x3Font[i] : x7x3Fontv2[i], 8, 4, 0, 1);
}


