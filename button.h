#pragma once
#include <Arduino.h>
#include "mainSettings.h"

// ---------------- СТРУКТУРА ----------------
struct Button {
  bool S;   // state (состояние кнопки)
  bool F;   // flag (кнопка зажата)
  bool R;   // release (флаг отпускания)
  bool P;   // press (короткое нажатие)
  bool H;   // hold (удержание)
  bool HO;  // hold once (первый вход в удержание)

  unsigned long timer;   // антидребезг + отсчёт удержания
  unsigned long press;   // задержка для одиночного клика
  unsigned long repeat;  // повтор удержания
};

void updateButton(Button &btn, int pin);
