#include "dht_sensor.h"

unsigned long lastMillis;

void setupDHT() {
  dht.begin();
  lastMillis = millis();
}

void retrieveDHTData() {
  if ((unsigned long)(millis() - lastMillis) > 5000) {
    float h = dht.readHumidity();
    float t = dht.readTemperature();
    StaticJsonDocument<100> doc;
    doc["h"] = h;
    doc["t"] = t;
    String json = "";
    serializeJson(doc, json);
    mqttClient.publish("/data/dht", json.c_str());
    lastMillis = millis();
  }
}