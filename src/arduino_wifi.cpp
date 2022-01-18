#include "arduino_wifi.h"

const char* ssid = "thu lan 999";
const char* password = "Thulan@8888";

void setupWiFi() {
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.print("\n[WiFi] Connected with IP Address: ");
  Serial.println(WiFi.localIP());
}
