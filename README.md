# **ESP8266 & MAX7219 CLOCK** 

![PROJECT_PHOTO](https://github.com/MRAK-AZ/ESP8266_clock/blob/main/ESP8266_clock.jpg)

## Описание
Электронные часы на базе ESP8266 и MAX7219.    
Автоматически синхронизируют время при подключении к WiFi.

#### *Функции:*
- Автоматическая синхронизация времени через NTP-сервер
- Смена стиля отображения времени: *горизонтально / вертикально*
- Изменение стиля шрифта (2 варианта)
- Регулировка яркости
- Хранение в памяти нескольких точек доступа WiFi
- Сброс настроек WiFi при включении и удержании кнопки

#### *Настройка при первом включении*
При первом включении часы создают точку доступа WiFi с названием **ESP8266-Clock**. Подключитесь к ней, затем в веб-интерфейсе подключите часы к вашей сети WiFi.  
Если автоматическое перенаправление не произошло, перейдите по IP: **192.168.1.4**.

#### *Компоненты*
- ESP8266 (Wemos D1 Mini / NodeMCU v3.0)
- 2 матрицы 8×8 на MAX7219
- Потенциометр 10K
- 2 кнопки

#### *Основные настройки в mainSettings.h*
```cpp
/*============================ НАСТРОЙКА МАТРИЦ ==============================*/
#define WM 1      // количество матриц по горизонтали
#define HM 2      // количество матриц по вертикали
#define CSM D1    // пин CS
#define DATAM D0  // пин DATA
#define CLKM D2   // пин CLK

/*============================== НАСТРОЙКА КНОПОК ============================*/
#define PIN_OK D6      // пин кнопки
#define Analog_Pin A0  // пин потенциометра

#define PRESS_TIMER 10   // мс для одиночного клика
#define HOLD_TIME 400    // мс для перехода в режим удержания
#define HOLD_REPEAT 500  // мс задержка между повторами при удержании
#define DEBOUNCE 20      // мс антидребезг

/*============================= НАСТРОЙКА WiFi ===============================*/
#define WiFi_name ESP8266-Clock  // название точки доступа часов

/*========================= НАСТРОЙКА NTP СЕРВЕРА ============================*/
constexpr int8_t GMT = 3;                                 // смещение часового пояса по GMT
constexpr const char* NTPserverURL = "ntp1.stratum1.ru";  // URL NTP-сервера
#define upmstime 60                                       // синхронизация времени раз в n секунд
```
#### *библиотеки использованые в коде*
- [NTPClient](https://github.com/arduino-libraries/NTPClient)
- [GyverMAX7219](https://github.com/GyverLibs/GyverMAX7219)
- [GyverGFX](https://github.com/GyverLibs/GyverGFX)
- [ESPAsyncWiFiManager](https://github.com/alanswx/ESPAsyncWiFiManager)
- [ESPAsyncWebServer](https://github.com/me-no-dev/ESPAsyncWebServer)
- [ESPAsyncTCP](https://github.com/me-no-dev/ESPAsyncTCP)
