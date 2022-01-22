#include "dht_sensor.h"

DHT dht(DHT_PIN, DHT_TYPE);

const char* dht_mqtt_topic = "/data/dht";
unsigned long lastMillis;

void setupDHT() {
  dht.begin();
  lastMillis = millis();
}

void sendDHTData() {
  if ((unsigned long)(millis() - lastMillis) > 5000) {
    float temp = dht.readTemperature();
    float humi = dht.readHumidity();

    if (isnan(temp) || isnan(humi)) {
      Serial.println("[DHT Sensor] Failed to read data");
      return;
    }

    StaticJsonDocument<100> doc;
    doc["temp"] = temp;
    doc["humi"] = humi;
    String jsonStr = "";
    serializeJson(doc, jsonStr);
    mqttPublishData(dht_mqtt_topic, jsonStr.c_str());
    lastMillis = millis();
  }
}