#include "WIFIManagerESP.h"

AsyncWebServer server(80);
DNSServer dns;
AsyncWiFiManager wifiManager(&server, &dns);

void connectWIFI() {

  if (digitalRead(PIN_OK)) wifiManager.resetSettings();  
  
  wifiManager.autoConnect("WiFi_name");

  Serial.println("Conected to WiFi!");
  Serial.print("IP's adress: ");
  Serial.println(WiFi.localIP());
}
