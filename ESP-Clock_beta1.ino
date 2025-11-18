#include "NTPClient.h"
#include "WiFiUdp.h"
#include "WIFIManagerESP.h"
#include "matrix.h"
#include "button.h"
#include "mainSettings.h"

/*================================ Flug's ====================================*/
bool rotation;
bool fontF;
bool updateF;extern AsyncWebServer server;
extern DNSServer dns;

Button btnOK;
/*=================================== NTP  ===================================*/
WiFiUDP udp;
NTPClient timeClient(udp, NTPserverURL, 3600 * GMT, 1000 * upmstime);
/*============================================================================*/

void setup() {
  Serial.begin(115200);  // открываем порт для отладки

  pinMode(Analog_Pin, INPUT);
  pinMode(PIN_OK, INPUT_PULLUP);


  connectWIFI();       //  подключение к WiFi
  initMatrix();        // инициализация матриц
  timeClient.begin();  //  инициализация NTP-client
}

void loop() {
  updateButton(btnOK, PIN_OK);

  if (btnOK.P) {
    rotation = !rotation;  // изменение ориентации отображания
    mtrx.setRotation(rotation);
    updateF = 1;
  }

  if (btnOK.H) {
    fontF = !fontF;  // изменение стиля шрифта
    updateF = 1;
  }

  /*=========================== УПРАВЛЕНИЕ ЯРКОСТЬЮ ==========================*/

  static uint8_t oldBright;
  Serial.println(analogRead(Analog_Pin));
  uint16_t Bright = map(analogRead(Analog_Pin), 140, 1023, 1, 15);
  Bright = constrain(Bright, 1, 15);

  if (oldBright != Bright) {
    mtrx.setBright(Bright);
    oldBright = Bright;
  }


  timeClient.update();
  uint8_t Hours = timeClient.getHours();
  uint8_t Minutes = timeClient.getMinutes();
  static uint8_t oldMinutes;
  uint8_t y;

  if (Minutes != oldMinutes) updateF = 1;

  /*=========================== ОБНОВЛЕНИЕ ДИСПЛЕЯ ===========================*/

  if (updateF) {
    mtrx.clear();
    DisplayTime(Hours / 10, 8, fontF);
    DisplayTime(Hours % 10, 12, fontF);
    DisplayTime(Minutes / 10, rotation ? 1 : 0, fontF);
    DisplayTime(Minutes % 10, rotation ? 5 : 4, fontF);
    mtrx.update();

    oldMinutes = Minutes;
    updateF = 0;
  }
}
