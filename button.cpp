#include "button.h"
#include "mainSettings.h"

/*====================== ЛОГИКА ОТРАБОТКИ НАЖАТИЙ ============================*/

void updateButton(Button &btn, int pin) {
  bool reading = !digitalRead(pin);

  // сброс одноразовых флагов
  btn.P = false;
  btn.H = false;

  // новое нажатие
  if (reading && !btn.F && millis() - btn.timer > DEBOUNCE) {
    btn.F = true;
    btn.HO = false;  // сброс "HO" только при новом нажатии
    btn.timer = millis();
    btn.repeat = millis();
  }

  // hold
  if (btn.F && millis() - btn.timer > HOLD_TIME) {
    if (!btn.HO) {
      btn.HO = true;  // первый вход в удержание
      btn.H = true;
      btn.repeat = millis();
    } else if (millis() - btn.repeat > HOLD_REPEAT) {
      btn.H = true;  // повтор удержания
      btn.repeat = millis();
    }
  }
  if (!reading && btn.F) {
    if (!btn.HO) {
      btn.R = true;
      btn.press = millis();
    }
    btn.F = false;
    btn.timer = millis();
  }

  // одиночный клик
  if (btn.R && millis() - btn.press > PRESS_TIMER) {
    btn.R = false;
    btn.P = true;
  }

  // после полного отпускания — сброс HO
  if (!reading && !btn.F) {
    btn.HO = false;
  }
}
