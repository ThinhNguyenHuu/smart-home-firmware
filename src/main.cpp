#include <Arduino.h>
#include <string.h>
#include "arduino_wifi.h"
#include "mqtt.h"
#include "ble.h"
#include "dht_sensor.h"

void setup() {  
  Serial.begin(115200);
  while (!Serial) {}

  setupWiFi();
  setupMQTT();
  setupBLE();
  setupDHT();
  setupActions();
}

void loop() {
  mqttLoop();
  bleLoop();
  retrieveDHTData();
}