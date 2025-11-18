#pragma once
#include "Arduino.h"

/*============================ НАСТРОЙКА МАТРИЦ ==============================*/
#define WM 1      // количество матриц по горизонтале
#define HM 2      // количество матриц по вертикале
#define CSM D1    // пин CS
#define DATAM D0  // пин DATA
#define CLKM D2   // пин CLK

/*============================== НАСТРОЙКА КНОПОК ============================*/

#define PIN_OK D6      //  пин кнопки
#define Analog_Pin A0  // пи потенциометра

#define PRESS_TIMER 10   // мс для одиночного клмка
#define HOLD_TIME 400    // мс для перехода в удержание
#define HOLD_REPEAT 500  // мс задержка между повторами удержания
#define DEBOUNCE 20      // мс антидребезг

/*============================= НАСТРОЙКА WiFi ===============================*/

#define WiFi_name ESP8266-Clock

/*========================= НАСТРОЙКА NTP СЕРВЕРА ============================*/

constexpr int8_t GMT = 3;                                 // смещение по GMT
constexpr const char* NTPserverURL = "ntp1.stratum1.ru";  // URL, NTP сервера
#define upmstime 60                                       // синхронизация раз в n-секунд
